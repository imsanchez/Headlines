/*******************************************************/
/* Solify's -> CA Base D3D Menu Selection
/* WE11ington -> Disponibilizou Para Combat Arms Brasil
/* Elinson/Turbulence -> Pequenos ajustes d/c etc na V3
/*******************************************************/
#include "stdafx.h"

LPD3DXFONT Directx_Font;

CONST D3DCOLOR Red      = D3DCOLOR_ARGB(255, 255, 000, 000);
CONST D3DCOLOR Green    = D3DCOLOR_ARGB(255, 127, 255, 000);
CONST D3DCOLOR Orange   = D3DCOLOR_ARGB(255, 255, 140, 000);
CONST D3DCOLOR Blue     = D3DCOLOR_ARGB(255, 000, 000, 255);
CONST D3DCOLOR Yellow   = D3DCOLOR_ARGB(255, 255, 255,  51);
CONST D3DCOLOR Black    = D3DCOLOR_ARGB(255, 000, 000, 000);
CONST D3DCOLOR Grey     = D3DCOLOR_ARGB(255, 112, 112, 112);
CONST D3DCOLOR Gold     = D3DCOLOR_ARGB(255, 255, 215, 000);
CONST D3DCOLOR Pink     = D3DCOLOR_ARGB(255, 255, 192, 203);
CONST D3DCOLOR Purple   = D3DCOLOR_ARGB(255, 128, 000, 128);
CONST D3DCOLOR White    = D3DCOLOR_ARGB(255, 255, 255, 249);
CONST D3DCOLOR Cyan     = D3DCOLOR_ARGB(255, 000, 255, 255);
CONST D3DCOLOR Magenta  = D3DCOLOR_ARGB(255, 255, 000, 255);

VOID DrawText(LPDIRECT3DDEVICE9 pDevice, INT x, INT y, DWORD color, CHAR *text)
{
	RECT rect;
	SetRect(&rect, x, y, x, y);
	Directx_Font->DrawText(NULL, text, -1, &rect, DT_LEFT | DT_NOCLIP, color);
}

VOID DrawRect(LPDIRECT3DDEVICE9 pDevice, INT x, INT y, INT h, INT w, DWORD Color)
{
	D3DRECT rec;
	rec.x1 = x;
	rec.x2 = x + w;
	rec.y1 = y;
	rec.y2 = y + h;
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
}

VOID DrawBox(LPDIRECT3DDEVICE9 pDevice, INT x, INT y, INT h, INT w, D3DCOLOR Border, D3DCOLOR Fill)
{
	DrawRect(pDevice, x, y, h , w, Fill);
	DrawRect(pDevice, x, y, h, 1, Border);
	DrawRect(pDevice, x + w, y, h, 1, Border);
	DrawRect(pDevice, x, y, 1, w, Border);
	DrawRect(pDevice, x, y + h, 1, w + 1, Border);
	DrawRect(pDevice, x + 2, y + 2, h - 4, 2, Border);
	DrawRect(pDevice, x + 2, y + 2, 2, w - 4, Border);
	DrawRect(pDevice, x + w - 4, y + 2, h - 4, 2, Border);
	DrawRect(pDevice, x + 2, y + h - 4, 2, w - 4, Border);
}

VOID CurrentOption(LPDIRECT3DDEVICE9 pDevice, INT x, INT y, INT h, INT w, D3DCOLOR Border)
{
	DrawRect(pDevice, x, y, h, 2, Border);
	DrawRect(pDevice, x + w, y, h, 2, Border);
	DrawRect(pDevice, x, y, 2, w, Border);
	DrawRect(pDevice, x, y + h, 2, w + 2, Border);
}

VOID CrossHair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color)
{
	D3DVIEWPORT9 Viewport;
	pDevice->GetViewport(&Viewport);
	DWORD ScreenX = Viewport.Width / 2;
	DWORD ScreenY = Viewport.Height / 2;
	D3DRECT rec1 = { ScreenX - 15, ScreenY, ScreenX + 15, ScreenY + 2 };
	D3DRECT rec2 = { ScreenX, ScreenY - 15, ScreenX + 2, ScreenY + 15 };
	pDevice->Clear(1, &rec1, D3DCLEAR_TARGET, Color, 0, 0);
	pDevice->Clear(1, &rec2, D3DCLEAR_TARGET, Color, 0, 0);
}
