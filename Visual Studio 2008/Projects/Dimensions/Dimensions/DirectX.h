//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef _DIRECTX_H
#define _DIRECTX_H
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#pragma once
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Includes.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
struct sVertex
{
	float x, y, z, RHW;
	DWORD color;

	enum FVF
	{
		FVF_Flags = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
	};
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cDirectX
{
public:
	LPD3DXFONT pFont;
	ID3DXLine *pLine;
	LPDIRECT3DDEVICE9 pDevice;
	void PrintText( float x, float y, DWORD color, const char *fmt, ...);
	void DrawCrosshair( LPDIRECT3DDEVICE9 pDevice, int size, int strong,  D3DCOLOR xcolor );
	void DrawCircle( float X, float Y, int radius, int numSides, DWORD Color );
	void DrawRGB( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, DWORD color );
	void DrawBorder( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, DWORD color1, DWORD color2 );
	void DrawBox( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, D3DCOLOR BoxColor, D3DCOLOR BorderColor1, D3DCOLOR BorderColor2 ) ;
	//void SliderBase( LPDIRECT3DDEVICE9 pDevice, float x, float y, float BaseWidth, float BaseHeight );
	void DrawRAMBox( LPDIRECT3DDEVICE9 pDevice, float x, float y );
	void DrawFileText( LPDIRECT3DDEVICE9 pDevice, float x, float y );
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
extern class cDirectX* directx;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++