// ========================================================================
#include "Main.h"
#include "Detours.h"
// ========================================================================
cMain main;
// ========================================================================
LPDIRECT3DDEVICE9 hl_pDevice = 0;
// ========================================================================
void cMain::RenderFont( LPDIRECT3DDEVICE9 pDevice ) {
	const char* font;
	OSVERSIONINFO os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	if( os.dwMajorVersion == 6 ) {
		OSVer = ( os.dwMinorVersion == 0 ) ? Vista : Win7;
	} else if( os.dwMajorVersion == 5 && os.dwMinorVersion == 1 ) {
		OSVer = XP;
	}
	if( OSVer != XP ) {
		font = STRING_FONT_VERDANA; //"Segoe UI Light";
	} else {
		font = STRING_FONT_VERDANA;
	}
	if( hl_pDevice != pDevice ) {
		hl_pDevice = pDevice;
		try { 
			if( directx.pFont != NULL ) {
				directx.pFont->Release();
				tools.WriteLog( STRING_LOG_PATH, "Old Font Released." );
				directx.pFont = NULL;
			}
		} catch (...) {}
		D3DXCreateFontA( pDevice, 15, 0, FW_NORMAL, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font, &directx.pFont );
		tools.WriteLog( STRING_LOG_PATH, "New Font Created." );
	}
}
// ========================================================================
bool rendered = false;
void cMain::RenderFrame( LPDIRECT3DDEVICE9 pDevice ) {
	main.RenderFont( pDevice );
	if( directx.pFont != NULL ) {
		if( !rendered ) {
			menu.MenuSt.isVisible = true;
			rendered = true;
		}
		hacks.Render( pDevice );
		menu.Render( pDevice, Black, Grey, D3DCOLOR_ARGB ( 205, 212, 208, 200 ) );
	} else {
		main.RenderFont( pDevice );
	}
}
// ========================================================================
LPDIRECT3DDEVICE9 pDevice;

typedef void (__cdecl * tRender)( LPDIRECT3DDEVICE9 pDevice, CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion );
tRender sRender;
__declspec( naked ) void hlRender( LPDIRECT3DDEVICE9 pDevice, const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion ) {
	__asm PUSHAD;
		main.RenderFont( pDevice );
		main.RenderFrame( pDevice );
	__asm POPAD;
	__asm JMP[sRender];
};
// ========================================================================
typedef HRESULT ( WINAPI* tReset )( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters );
tReset sReset;
HRESULT WINAPI hlReset( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters ) {
	directx.pFont->OnLostDevice();
	directx.pFont->OnResetDevice();
	directx.pLine->OnLostDevice();
	directx.pLine->OnResetDevice();
	return sReset(pDevice, pPresentationParameters);
}
// ========================================================================
typedef HRESULT(WINAPI *tPresent)(LPDIRECT3DDEVICE9 pDevice, CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion );
tPresent sPresent;
HRESULT WINAPI hlPresent( LPDIRECT3DDEVICE9 pDevice, const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion ) {
	__asm PUSHAD;
	main.RenderFrame( pDevice );
	__asm POPAD;
	return sPresent( pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion );
}
// ========================================================================
void cMain::Init( void ) {
	while( 1 ) {
		DWORD GetD3D9Module = 0;
		do {
			GetD3D9Module = ( DWORD )GetModuleHandle( STRING_D3D9DOTDLL );
			Sleep( 10 );
		} while( !GetD3D9Module );
		DWORD D3D9Addie = detour.FindPattern( GetD3D9Module, 0x128000, ( BYTE* )"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx" );
		if( D3D9Addie ) {
			DWORD* VTBL;
			tools.WriteLogX( STRING_LOG_PATH, "D3D9 Address Found... [ 0x%x ]", D3D9Addie );
			if ( memcpy( &VTBL, ( void * )( D3D9Addie + 2 ), 4 ) ) {
				tools.WriteLog( STRING_LOG_PATH, "D3D9 Address Copied to vTable Successfully. Proceeding with Detouring..." );
				sReset	 = ( tReset )detour.CreateDetour( ( DWORD )VTBL[16], ( DWORD )hlReset, 1, 5 );
				tools.WriteLogX( STRING_LOG_PATH, "RESET[ 0x%x ]", VTBL[16] );
				sPresent = ( tPresent )detour.CreateDetour( ( DWORD )VTBL[17], ( DWORD )hlPresent, 1, 5 ); //( PBYTE )hlPresent
				tools.WriteLogX( STRING_LOG_PATH, "PRESENT[ 0x%x ]", VTBL[17] );
				tools.WriteLog( STRING_LOG_PATH, "Reset and Present Detours Created Successfully." );
				ExitThread(0);
			} else {
				tools.WriteLog( STRING_LOG_PATH, ".:ERROR:FAILED TO COPY D3D9 ADDRESS TO VTABLE:." );
			}
			Sleep( 100 );
		} else {
			tools.WriteLog( STRING_LOG_PATH, ".:ERROR:FAILED TO FIND D3D9 ADDRESS:." );
		}
	}
}
// ========================================================================
//							CHECK IF GAME READY							 //
// ========================================================================
bool cMain::ReadyForHook() {
	return ( (	//GetModuleHandle( STRING_KERNEL		) != NULL &&
				GetModuleHandle( STRING_D3D9DOTDLL		) != NULL &&
				GetModuleHandle( STRING_ENGINEDOTEXE	) != NULL &&
				GetModuleHandle( STRING_CSHELLDOTDLL	) != NULL &&
				GetModuleHandle( STRING_CLIENTFXDOTFXD	) != NULL	) ? true : false );
				//GetModuleHandle( STRING_EHSVCDOTDLL	) != NULL	) ? true : false;
}
// ========================================================================
//						CREATE FIRST THREAD (D3D9)						 //
// ========================================================================
DWORD __stdcall threadStarter( LPVOID lpParam  ) {
	while( !main.ReadyForHook() )
		Sleep( 100 );

	tools.ClearLog( STRING_LOG_PATH );
	tools.WriteLog( STRING_LOG_PATH, 
		"================================================================	\n"
		" _    _ ______          _____  _      _____ _   _ ______  _____	\n"
		"| |  | |  ____|   /\\   |  __ \\| |    |_   _| \\ | |  ____|/ ____|\n"
		"| |__| | |__     /  \\  | |  | | |      | | |  \\| | |__  | (___	\n"
		"|  __  |  __|   / /\\ \\ | |  | | |      | | |     |  __|  \\___ \\\n"
		"| |  | | |____ / ____ \\| |__| | |____ _| |_| |\\  | |____ ____) |	\n"
		"|_|  |_|______/_/    \\_\\_____/|______|_____|_| \\_|______|_____/	\n"
		"																	\n"
		"================================================================	\n"
		"VERSION: 0.01 PRE-ALPHA (PRIVATE)									\n"
		"AUTHOR : -Dimensions-												\n"
		"DATE	: 20th of July, 2013										\n"
		"================================================================	\n"
		"							CREDITS									\n"
		"================================================================	\n"
		"-Dimensions-														\n"
		"Qwerty01															\n"
		"Gelli																\n"
		"Hans211															\n"
		"Sinner																\n"
		"Zaki96																\n"
		"z0mbie (ADE32)														\n"
		"LanceVorgin														\n"
		"d0m1n1c															\n"
		"Azorbix															\n"
		"USSR																\n"
		"Shadow																\n"
		"NeoIII																\n"
		"Ch40z-C0d3r														\n"
		"BlackLegend														\n"
		"NOOB																\n"
		"We11ingtow															\n"
		"Sollyf																\n"
		"srDIEGO															\n"
		"experthack															\n"
		"luizimloko															\n"
		"mattypatty															\n"
		"TokolocoSK															\n"
		"arun823															\n"
		"_Debug_ 															\n"
		"HackerFail															\n"
		"Luizimloko															\n"
		"WE11ngton															\n"
		"Zerocool															\n"
		"Shad0w_															\n"
		"xCyniu																\n"
		"TokolocoSK															\n"
		"kssiobr															\n"
		"and others ...														\n"
		"================================================================	\n"
		"							   LOG									\n"
		"================================================================	\n"
		"DLL Attached Successfully and D3D9 Init Function has begun.		");
	main.Init();

	return NULL;
}
// ========================================================================
//							CREATE FIRST THREAD							 //
// ========================================================================
bool __stdcall DllMain( HMODULE hlModule, DWORD hlReason, LPVOID lpReserved ) {
	DisableThreadLibraryCalls( hlModule );
	if( hlReason == DLL_PROCESS_ATTACH ) {
		CreateThread( 0, 0, ( LPTHREAD_START_ROUTINE )threadStarter, 0, 0, 0 );
		return true;
	} else if( hlReason == DLL_PROCESS_DETACH ) {
		detour.UnlinkModule( hlModule );
		detour.EraseHeaders( hlModule );
		return true;
	}
	/*
	
	DWORD threadID = 0;
	switch ( dwReason ) {
		case DLL_PROCESS_ATTACH:
			CreateThread( NULL, NULL, ( LPTHREAD_START_ROUTINE )getD3D9Thread, NULL, NULL, &threadID );
			break;
		case DLL_THREAD_ATTACH:
			//
			break;
		case DLL_THREAD_DETACH:
			//
			break;
		case DLL_PROCESS_DETACH:
			//
			break;
	}
	*/
	return false;
}
// ========================================================================