#include "Main.h"

cMain main;

struct {
	int OnOff;
}HackItem[MaxHax];

bool cMain::IsInGame()
{
	switch(*(int*)ADDR_STATUS)
	{ 
	case 1:
		return true;
	}
	return false;
}

void cMain::AddHackItem( int i, int Key )
{
	//if ( main.IsInGame() )
	//{
		if( GetAsyncKeyState( Key ) )
		{
			//Credits to Qwerty01
			HackItem[i].OnOff = HackItem[i].OnOff == 1?0:1; //You can't mess with this Sh!t
			//So noob protected right here ^
			Sleep( 100 ); //Prevent from Flickering
		}
	//}
}

//Credits to Gellin (originally came from his leeched VIP)
void __cdecl cMain::RunConsoleCommand( const char* szCommand ) 
{
	void* address = ( void* ) ADDR_CONSOLEUNWRAPPED;

	__asm
	{
		Push szCommand
		call address
		add esp, 0x4
	}
}

//Found this somewhere...
void cMain::Memoria( void* pvAddress, void* pvBuffer, size_t len )
{
	if( *(BYTE*)pvAddress == *(BYTE*)pvBuffer )
		return;

	memcpy( ( void* )pvAddress, ( void* )pvBuffer, len );
}

//Add the Hack Items and PTC Functions... You can change this...
void cMain::HackCall( void )
{
	main.AddHackItem( 1, VK_NUMPAD1 );

	if ( HackItem[1].OnOff == 1 ) //On
	{
		main.RunConsoleCommand( "ShowFps 1" );
	}
	if ( HackItem[1].OnOff == 0 ) //Off
	{
		main.RunConsoleCommand( "ShowFps 0" );
		HackItem[1].OnOff = 2; //Do nothing once its off...
	}
}

bool cMain::IsGameReadyForHook()
{
	if( GetModuleHandleA( "CShell.dll"		) != NULL &&
		GetModuleHandleA( "Engine.exe"		) != NULL )
		return true;

	return false;
}
DWORD WINAPI dwHackThread( LPVOID )
{
	while( !main.IsGameReadyForHook() )
		Sleep( 25 );

	main.HackCall();

	return EXIT_SUCCESS;
}

BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	DisableThreadLibraryCalls( hDll );
	if ( dwReason == DLL_PROCESS_ATTACH )
	{
			CreateThread( NULL, NULL, dwHackThread, NULL, NULL, NULL );	
	}
	return TRUE;
}