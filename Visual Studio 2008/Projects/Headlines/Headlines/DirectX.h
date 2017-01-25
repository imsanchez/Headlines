// ========================================================================
#ifndef __DIRECTX_H__
#define __DIRECTX_H__
// ========================================================================
#pragma once
// ========================================================================
struct sVertex {
	float x, y, z, RHW;
	DWORD color;

	enum FVF
	{
		FVF_Flags = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
	};
};
// ========================================================================
class cDirectX {
public:
	LPD3DXFONT pFont;
	//ID3DXFont *iFont;
	ID3DXLine *pLine;
	void PrintText( float x, float y, D3DCOLOR font, const char *fmt, ... );
	void PrintShadowedText( float x, float y, D3DCOLOR font, D3DCOLOR shadow, const char *fmt, ... );
	void DrawCrosshair( LPDIRECT3DDEVICE9 pDevice, int size, int strong,  D3DCOLOR xcolor );
	void DrawCircle( float X, float Y, float radius, float numSides, DWORD Color );
	void DrawRGB( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, DWORD color );
	void DrawBorder( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, DWORD color1, DWORD color2 );
	void DrawBox( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, D3DCOLOR BoxColor, D3DCOLOR BorderColor1, D3DCOLOR BorderColor2 ) ;
	//void SliderBase( LPDIRECT3DDEVICE9 pDevice, float x, float y, float BaseWidth, float BaseHeight );
	//void DrawGradient( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, D3DCOLOR Color1, D3DCOLOR Color2 );
	void DrawRAMBox( LPDIRECT3DDEVICE9 pDevice, float x, float y, D3DCOLOR font, D3DCOLOR shadow, D3DCOLOR bg, D3DCOLOR border1, D3DCOLOR border2  );
	void PrintFileText( LPDIRECT3DDEVICE9 pDevice, const char* file, float x, float y, D3DCOLOR font );
};
extern class cDirectX directx;
// ========================================================================
#endif
// ========================================================================