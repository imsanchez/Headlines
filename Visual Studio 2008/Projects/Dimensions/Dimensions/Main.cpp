//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Main.h"
#include "Menu.h"
#include "Detoursz.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
cMain* main = NULL;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef HRESULT ( WINAPI* oPresent ) ( LPDIRECT3DDEVICE9 pDevice, CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion);
typedef HRESULT ( WINAPI* oReset )( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters );
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
oPresent pPresent;
oReset pReset;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
LPDIRECT3DDEVICE9 g_pDevice = 0;

HRESULT cMain::CreateFont( LPDIRECT3DDEVICE9 pDevice, const char* Font )
{
	HRESULT hr;
	hr = D3DXCreateFontA( pDevice, 15, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, Font, &directx->pFont );
	if ( FAILED( hr ) )
	{
		MessageBoxA( GetDesktopWindow(), "Call to D3DXCreateFont failed!", "ERROR", MB_OK|MB_ICONEXCLAMATION );
		directx->pFont = NULL;
	}
	if ( directx->pFont == 0 ){
		D3DXCreateFontA( pDevice, 15, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, Font, &directx->pFont );
	}else{
		if ( g_pDevice != pDevice )
		{
			g_pDevice = pDevice;
			try
			{ 
				if ( directx->pFont != NULL )
					directx->pFont->Release();
			} catch (...) {}
			directx->pFont = NULL;
			D3DXCreateFontA( pDevice, 15, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, Font, &directx->pFont );
		}
	}
	return hr;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//						THE RENDER FUNCTION						  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cMain::RenderFrame( LPDIRECT3DDEVICE9 pDevice )
{
	OSVERSIONINFO os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	if ( os.dwMajorVersion == 6 )
	{
		if ( os.dwMinorVersion == 0 )
			OSVer = Vista;
		else
			OSVer = Win7;
	}else if ( os.dwMajorVersion == 5 && os.dwMinorVersion == 1 ){
		OSVer = XP;
	}
	if (OSVer != XP )
	{
		main->CreateFont( pDevice, "Verdana"); //"Segoe UI" );
	}else{
		main->CreateFont( pDevice, "Verdana" );
	}
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//							RENDER TIME								  //
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	if ( directx->pFont != NULL )
	{
		directx->PrintText( 5, 5, White, "Welcome to Headlines" );
		//menu->Render( pDevice );
		//hacks->RenderHacks( pDevice );
	}
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

/*
HRESULT WINAPI TheDrawIndexedPrimitive( LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount )
{
	CHAM STUFF?
	return pDrawIndexedPrimitive( pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount );
}
*/
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//						THE PRESENT FUNCTION						  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
HRESULT WINAPI PresentThunk( LPDIRECT3DDEVICE9 pDevice, const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion )
{
	main->RenderFrame( pDevice );
	return pPresent( pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//						  THE RESET FUNCTION						  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
HRESULT WINAPI TheReset( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters )
{
	directx->pFont->OnLostDevice();
	HRESULT hRet = pReset( pDevice, pPresentationParameters );
	directx->pFont->OnResetDevice();
	if(hRet == D3D_OK){
	}
	return hRet;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//			AUTOMATIC D3D9 POINTER & CALL RESET / PRESENT			  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
DWORD WINAPI InstallHook( LPVOID )
{
    DWORD GetD3D9Module, Addie, *vLmao, sz_dwPresent, sz_dwReset;
	GetD3D9Module = 0;
	do {
		GetD3D9Module = (DWORD)GetModuleHandleA("d3d9.dll");
		Sleep( 10 );
	} while ( !GetD3D9Module );
	Addie = detour->FindPattern( GetD3D9Module, 0x128000, ( PBYTE )"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx" );
	if( Addie )
	{
		memcpy( &vLmao, ( void * )( Addie + 2 ),4);
		sz_dwPresent = vLmao[Present];
		sz_dwReset = vLmao[Reset];
		pReset = ( oReset )detour->Create( ( BYTE* )sz_dwReset, ( BYTE* )Reset, DETOUR_LEN_AUTO ); 
		pPresent = ( oPresent )detour->Create((  BYTE* )sz_dwPresent, ( BYTE* )PresentThunk, DETOUR_LEN_AUTO );
		//pPresent = ( oPresent )tools->DetourCreate( ( BYTE* )dwPresent, ( BYTE* )&PresentThunk, Len_Size );
		//pReset = ( oReset )tools->DetourCreate( ( BYTE* )dwReset, ( BYTE* )TheReset, Len_Size );
		//while(true)
		//{
		//	DWORD dwDrawIndexedPrimitive = vLmao[82];
		//	if(  memcmp( ( void * )vLmao[82], ( void * )"\x8B\xFF", 2 ) == 0 )
		//	{
		//		pDrawIndexedPrimitive	 = ( oDrawIndexedPrimitive )tools->DetourCreate( ( PBYTE )TheDrawIndexedPrimitive, ( PBYTE )myDrawIndexedPrimitive, Len_Draw_Size );
		//	}
		//}
		Sleep( 10 );
	}
	free( ( void * )vLmao );
	return TRUE;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							GET THE GAME READY						  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool cMain::ReadyForHook()
{
	if ( GetModuleHandleA( "CShell.dll"	  )	!= NULL &&
		 GetModuleHandleA( "d3d9.dll"	  ) != NULL &&
		 GetModuleHandleA( "ClientFX.fxd" ) != NULL		)
		return true;
	return false;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//						CREATE SECOND THREAD (D3D9)					  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
DWORD WINAPI dwD3D9Thread( LPVOID )
{
	while( !main->ReadyForHook() )
		Sleep( 100 );
	
	main		= new cMain();
	menu		= new cMenu();
	detour		= new cDetour();
	hacks		= new cHacks();
	directx		= new cDirectX();
	tools		= new cTools();

	if ( main && menu && detour && hacks && directx && tools )
	{
		CreateThread( NULL, NULL, InstallHook, NULL, NULL, NULL );
	}

	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							CREATE FIRST THREAD						  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	DisableThreadLibraryCalls( hDll );

	if ( dwReason == DLL_PROCESS_ATTACH )
	{
		CreateThread( NULL, NULL, dwD3D9Thread, NULL, NULL, NULL );
	}

	return TRUE;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++