/*
    Name: Detoursz
    Description: Detoursz is a library for function detouring
    Version: 1.0
    Author: Sinner & Zaki96
	Website: www.gamedefeat.com & www.cheatersutopia.com
    Credits: z0mbie (ADE32), LanceVorgin's CDetour (some ideas)
*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#include "Includes.h"
#include "ADE32.h"
//#pragma comment lib, "detourxs")

#pragma warning(disable: 4311)
#pragma warning(disable: 4312)
#pragma warning(disable: 4244)
#pragma warning(disable: 4102)
#pragma warning(disable: 4996)

#define DETOUR_LEN_AUTO 0 // Finds the detour length automatically

#define DETOUR_MAX_SRCH_OPLEN 64

#define JaMu32_SZ 5
#define SI32_SZ 4

// jmp32 si
//-------bagian penting--------//
#define SI_SSZ 3//ini yg ak edit
#define SI_OOP_0 0xCC//ini yg aku edit
#define SI_OOP_1 0x90//ini juga
#define SI_OOP_2 0xC3//ini jg

enum
{
        DETOUR_TYPE_JMP, // min detour len: 5
        DETOUR_TYPE_PUSH_RET, // min detour len: 6
        DETOUR_TYPE_NOP_JMP, // min detour len: 6
        DETOUR_TYPE_NOP_NOP_JMP, // min detour len: 7
        DETOUR_TYPE_STC_JC, // min detour len: 7
        DETOUR_TYPE_CLC_JNC, // min detour len: 7
};

static DWORD dwOldProt;

class cDetour{
public:
	void* memcpy_s( void* pvAddress, const void* pvBuffer, size_t stLen );
	LPVOID Create( LPVOID lpFuncOrig, LPVOID lpFuncDetour, int patchType, int detourLen=DETOUR_LEN_AUTO );
	LPVOID Create( LPCSTR lpModuleName, LPCSTR lpProcName, LPVOID lpFuncDetour, int patchType, int detourLen=DETOUR_LEN_AUTO );
	BOOL Remove( LPVOID lpDetourCreatePtr );
	int GetDetourLen(int patchType);
	int GetDetourLenAuto(PBYTE &pbFuncOrig, int minDetLen);
	bool bDataCompare( const BYTE* pData, const BYTE* bMask, const char* szMask );
	DWORD FindPattern( DWORD dwAddress, DWORD dwLen,BYTE *bMask, char * szMask );
};

extern class cDetour detour;