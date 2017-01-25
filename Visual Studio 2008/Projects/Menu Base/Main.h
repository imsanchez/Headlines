#ifndef _Main
#define _Main

#pragma once

#include "Files.h"

typedef HRESULT (WINAPI* oPresent)(LPDIRECT3DDEVICE9 pDevice,CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion);
typedef HRESULT (WINAPI* oReset)(LPDIRECT3DDEVICE9 pDevice,D3DPRESENT_PARAMETERS* Parametri);

#define D3D9_Name L"d3d9.dll"
#define Font_Name "Verdana"
#define Hack_Name "Haxo v[0.0.0]"
#define Menu_Title "CheckBox Base"

#define Reset     16
#define Present   17

#define Len_size  5

class cMain
{
public:
	LPD3DXFONT pFont;            // 
	LPDIRECT3DDEVICE9 pDevice;   //

	static void *DetourCreate(BYTE *src, const BYTE *dst, const int len); // 
	bool bDataCompare(const BYTE* pData, const BYTE* bMask, const char* szMask); // 
	DWORD FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask); //
	bool HookReady();//
	void DrawString(int x, int y, DWORD color, LPD3DXFONT g_pFont, const char *fmt, ...);//
	
	void Render(LPDIRECT3DDEVICE9 pDevice);//
	void Hook();                 //
};

extern class cMain Main;

#endif