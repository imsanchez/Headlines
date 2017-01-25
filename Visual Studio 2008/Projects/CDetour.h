#pragma once

//#pragma comment(lib, "detourxs")
#include <windows.h>
#define DETOUR_LEN_AUTO 0 // Finds the detour length automatically

typedef enum detour_types_s
{
	DETOUR_TYPE_NOT_SET = -1,
	DETOUR_TYPE_OBS_RAND,
	DETOUR_TYPE_JMP,
	DETOUR_TYPE_PUSH_RET,
	DETOUR_TYPE_NOP_JMP,
	DETOUR_TYPE_NOP_NOP_JMP,
	DETOUR_TYPE_STC_JC,
	DETOUR_TYPE_CLC_JNC,
	DETOUR_TYPE_OBS_ADD,
	DETOUR_TYPE_OBS_XOR,
	DETOUR_TYPE_OBS_STACKADD,
	DETOUR_TYPE_OBS_ROR,
	DETOUR_TYPE_OBS_ADDNOT,

};

#define DetourRandTypeLow		DETOUR_TYPE_OBS_ADD
#define DetourRandTypeHigh		DETOUR_TYPE_OBS_ADDNOT

LPVOID DetourCreate(LPVOID lpFuncOrig, LPVOID lpFuncDetour, int patchType, int detourLen=DETOUR_LEN_AUTO);
LPVOID DetourCreate(LPCSTR lpModuleName, LPCSTR lpProcName, LPVOID lpFuncDetour, int patchType, int detourLen=DETOUR_LEN_AUTO);
BOOL DetourRemove(LPVOID lpDetourCreatePtr);