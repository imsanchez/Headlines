/*
 * Copyright (C) 2011 Digital Hacking.
 *
 * This file is part of the Headlines Public Hack.
 * 
 * Headlines Public Hack is licensed under a Creative Commons 
 * Attribution-NonCommercial 3.0 Unported License. 
 * <http://creativecommons.org/licenses/by-nc/3.0/>
 *
 * DO NOT REMOVE COPYRIGHT OR CREDITS
 *
 * CREDITS, PROPS, FRIENDS, and THANKS ARE FOUND IN FILES.H
 *
 * base.cpp - 
 * 
 */

#include "base.h"

void cBase::Hook( void )
{
	DWORD theD3D9, Address, *vtbl;
	theD3D9 = 0;

	do {
		theD3D9 = ( DWORD )GetModuleHandleW( L"d3d9.dll" );
		Sleep( 10 );
	} while( !theD3D9 );
	
	Address = tool.FindPattern( theD3D9, 0x128000, (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx" );
	
	if( Address ) { 
		memcpy( &vtbl, ( void * )( Address+2 ), 4 );
		pReset   = ( oReset   )tool.DetourCreate( ( PBYTE ) vtbl[Reset],   ( PBYTE ) &TheReset  , ( VOID** )5 );
		pPresent = ( oPresent )tool.DetourCreate( ( PBYTE ) vtbl[Present], ( PBYTE ) &ThePresent, ( VOID** )5 );
	}
}

DWORD WINAPI dhMainThread( LPVOID lpArg )
{
	while( !hook->IsGameReady() )
		Sleep( 100 );

	base = new cBase();
	hook = new cHook();

	if( base && hook ) {
//#ifdef _DEBUG_
//		tools.add_log( STRING_LOGFILE, STRING_CLASSFAILURE_dwMain );
//#endif
		base->Hook();
	}
	return EXIT_SUCCESS;
}