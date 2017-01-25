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
 * main.cpp - 
 *
 */

#include "Files.h"

BOOL WINAPI DllMain( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	DisableThreadLibraryCalls( hDll );
	if( dwReason == DLL_PROCESS_ATTACH ) {
//#ifdef _DEBUG_
		//DeleteFile( STRING_LOGFILE );
//#endif
		CreateThread( NULL, NULL, dhMainThread, NULL, NULL, NULL );
	}
	return TRUE;
}
