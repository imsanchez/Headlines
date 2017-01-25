// ========================================================================
#ifndef __MAIN_H__
#define __MAIN_H__
// ========================================================================
#pragma once
// ========================================================================
static HRESULT WINAPI hlReset( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters );
static HRESULT WINAPI hlPresent( LPDIRECT3DDEVICE9 pDevice, const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion );
// ========================================================================
int InstallHook( void );
int dwD3D9Thread( void );
// ========================================================================
class cMain{
public:
	void RenderFont( LPDIRECT3DDEVICE9 pDevice );
	void RenderFrame( LPDIRECT3DDEVICE9 pDevice );
	void Init();
	bool ReadyForHook();
private:
	enum _OSVer
	{
		Vista = 0,
		Win7 = 1,
		XP = 2,
	};
	_OSVer OSVer;
};
// ========================================================================
extern class cMain main;
// ========================================================================
#endif
// ========================================================================