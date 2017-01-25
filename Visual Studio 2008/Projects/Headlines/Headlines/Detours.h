// ========================================================================
#ifndef __DETOURS_H__
#define __DETOURS_H__
// ========================================================================
#pragma once
// ========================================================================
#include "ADE32.h"
// ========================================================================
//#define RESET					16
//#define PRESENT					17
//#define LEN_SIZE				5
//#define LEN_DRAW_SIZE			12
//#define DETOUR_LEN_AUTO			0 // Finds the Detour Length Automatically
//#define DETOUR_MAX_SRCH_OPLEN	64
// ========================================================================
//#define Detour_Type_0xE9		1
//#define Detour_Type_0xB8		2
//#define Detour_Type_0x68		3
// ========================================================================
class cDetour {
public:
	BOOL DataCompare( BYTE* pData, BYTE* bMask, char * szMask );
	void* Memoria( void* pvAddress, const void* pvBuffer, size_t stLen );
	DWORD FindPattern( DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask );
	DWORD CreateDetour( DWORD dwAdress, DWORD dwThread, DWORD dwType,DWORD dwSize );
	void UnlinkModule( HINSTANCE hDll );
	void EraseHeaders( HINSTANCE hModule );
	DWORD GetCodeSize( const char* szModuleName );
};
// ========================================================================
extern class cDetour detour;
// ========================================================================
#endif
// ========================================================================