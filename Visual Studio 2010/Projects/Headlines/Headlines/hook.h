/*******************************************************/
/* Solify's -> CA Base D3D Menu Selection
/* WE11ington -> Disponibilizou Para Combat Arms Brasil
/* Elinson/Turbulence -> Pequenos ajustes d/c etc na V3
/*******************************************************/
#include "files.h"

BOOL Pointer = 0xE9;
typedef HRESULT(WINAPI *tReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS *a);
tReset oReset;

typedef HRESULT(WINAPI *tPresent)(LPDIRECT3DDEVICE9 pDevice, CONST RECT *a, CONST RECT *b, HWND c, CONST RGNDATA *d);
tPresent oPresent;

VOID CreateDevice(DWORD *dwVTable)
{
	LPDIRECT3D9 pD3d9;
	LPDIRECT3DDEVICE9 pD3DDevice;
	pD3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	if(pD3d9 == NULL)
		return;
	D3DPRESENT_PARAMETERS pPresentParms;
	ZeroMemory(&pPresentParms, sizeof(pPresentParms));
	pPresentParms.Windowed = TRUE;
	pPresentParms.BackBufferFormat = D3DFMT_UNKNOWN;
	pPresentParms.SwapEffect = D3DSWAPEFFECT_DISCARD;
	if(FAILED(pD3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GetDesktopWindow(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pPresentParms, &pD3DDevice)))
		return;
	DWORD *dwTable = (DWORD *)pD3DDevice;
	dwTable = (DWORD *) dwTable[0];
	dwVTable[0] = dwTable[16];
	dwVTable[1] = dwTable[17];
}

VOID *DetourCreate(BYTE *src, CONST BYTE *dst, CONST INT len)
{
	BYTE *jmp = (BYTE *)malloc(len + 5);
	DWORD dwback;
	VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len);
	jmp += len;
	jmp[0] = Pointer;
	*(DWORD *)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	src[0] = Pointer;
	*(DWORD *)(src + 1) = (DWORD)(dst - src) - 5;
	for(INT i = 5; i < len; i++) src[i] = 0x90;
	VirtualProtect(src, len, dwback, &dwback);

	return(jmp - len);
}