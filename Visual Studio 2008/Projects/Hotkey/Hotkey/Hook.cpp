//////////////////////////////////////////////////////////////////////////
//	    Combat Arms: Mid-function Engine ( "Engine.exe" ) D3D Hook		//
//					 Created By: Gellin									//
//																		//
//		Released On: www.uc-forum.com && www.delta-h.net Only			//
//																		//
//			Credits: www.uc-forum.com && www.delta-h.net				//
//				   Ghoster - Pro - The Starship commander				//
//				   : raiders - help with font & he pro to				//
//				   : All Uc-Forum & Delta-h members i forgot			//
//																		//
//			Shouts:	www.delta-h.net										//
//					- Micro												//
//					- CD												//
//					- Cobra												//
//																		//
//////////////////////////////////////////////////////////////////////////

#include "hook.h"

cHook* hook = NULL;

DWORD dwRES_HOOK = 0x570E6E;
DWORD dwRES_RESTORE = dwRES_HOOK+0x7; 

DWORD dwPRES_HOOK = 0x65B336;
DWORD dwPRES_RESTORE = dwPRES_HOOK+0x5;

//////////////////////////////////////////////////////////////////////////
//								Render									//
//////////////////////////////////////////////////////////////////////////

void cHook::Render( void )
{
	hook->DrawText( 20, 10, 0xFFFF0000, "CA UNK_V1_BASE By: Gellin" );
}

//////////////////////////////////////////////////////////////////////////
//								RenderEx								//
//////////////////////////////////////////////////////////////////////////

void cHook::RenderEx( void )
{
	pDevice = ( **( LPDIRECT3DDEVICE9** )ADDR_DEVICE );

	if( !this->Do_Once )
	{
		this->add_log( Log_File, "Initializing..." );
		this->Create();
		this->Do_Once = true;
	}

	if( pDevice != m_pDevice )
	{
		this->add_log( Log_File, "Device / Object Device Mismatch..." );

		this->Release();
		this->Create();

		this->add_log( Log_File, "Re-Created Objects" );
	}
	
	if( this->OverCheckPointers() )			//Prolly Not needed but ill chunk it here, for sanity
		this->Render();						
}

//////////////////////////////////////////////////////////////////////////
//						  PRESENT HOOK								    //																								
//////////////////////////////////////////////////////////////////////////

__declspec( naked ) void Present_Hook( )
{
	//Fix the asm our 5 byte Detour patched over and push all registers
	_asm
	{
		MOV ECX, DWORD PTR DS:[EAX]
		MOV EDX, DWORD PTR DS:[ECX+0x44]	// 0x44 = DECI 68;   68 / 4 = 17; 17 = Present V-Table Offset
		//CALL EDX							// Call to D3D9 Present From Engine.exe, left for reference only
		PUSHAD								
	}

	hook->RenderEx();						// Call our Backend Render function;

	_asm
	{
		POPAD								
		JMP[ dwPRES_RESTORE ]				// Jump back to the code in Engine.exe After - MOV EDX, DWORD PTR DS:[ECX+0x44]
	}
}

//////////////////////////////////////////////////////////////////////////
//							RESET HOOK									//
//////////////////////////////////////////////////////////////////////////

_declspec( naked ) void Reset_Hook( )
{
	//Fix the asm our 5 byte Detour patched over and push all registers
	_asm
	{
		MOV ECX, DWORD PTR DS:[EAX]
		MOV EDX, DWORD PTR DS:[ECX+0x40]	// 0x40 = DECI 64;   64 / 4 = 16; 16 = Reset V-Table Offset
		PUSHAD
	}

	hook->OnLostDevice();					// Call Our onlostdev right before the game calls Reset

	_asm 
	{
		POPAD 
		CALL EDX							// Call to D3D9 Reset From Engine.exe
		PUSHAD
	}

	hook->OnResetDevice();					// Call Our onresetdev right after the game calls Reset

	_asm
	{
		POPAD
		JMP[ dwRES_RESTORE ]				// Jump back to the code in Engine.exe After - CALL EDX
	}
}

DWORD WINAPI dwMain( LPVOID )
{
	bool bSleep = true;

	while( bSleep )
	{
		if( GetAsyncKeyState( VK_NUMPAD1 ) &1 )
			bSleep = false;

		Sleep( 20 );
	}

	hook = new cHook();

	if( hook )
	{
		hook->DetourCreate( (PBYTE)dwRES_HOOK, (PBYTE)Reset_Hook, 5 );
		hook->DetourCreate( (PBYTE)dwPRES_HOOK, (PBYTE)Present_Hook, 5 );
	}

	return 0;
}

BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	switch( dwReason )
	{
		case DLL_PROCESS_ATTACH:
			DeleteFile( Log_File );
			CreateThread( NULL, NULL, dwMain, NULL, NULL, NULL );
			break;

		case DLL_PROCESS_DETACH:
			delete hook;
			break;
	}

	return TRUE;
}