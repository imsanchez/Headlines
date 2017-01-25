//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								INCLUDES							  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "DirectX.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
cDirectX* directx = NULL;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
using namespace std;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cDirectX::DrawCrosshair( LPDIRECT3DDEVICE9 pDevice, int size, int strong,  D3DCOLOR xcolor )
{
	if ( !pDevice )
		return;

	int iCenterX = 512; //GetSystemMetrics( 0 ) / 2;
	int iCenterY = 384; //GetSystemMetrics( 1 ) / 2;
	if ( iCenterX < 20 && iCenterY < 20 )
	{
		iCenterX = ( GetSystemMetrics( 0 ) / 2 );
		iCenterY = ( GetSystemMetrics( 1 ) / 2 );
	}
	D3DRECT rec2 = { iCenterX- size, iCenterY, iCenterX+ size, iCenterY+ strong};
	D3DRECT rec3 = { iCenterX, iCenterY- size, iCenterX+ strong, iCenterY+ size};
	pDevice->Clear(1, &rec2, D3DCLEAR_TARGET, xcolor, 1000, 0);
	pDevice->Clear(1, &rec3, D3DCLEAR_TARGET, xcolor, 100, 0);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cDirectX::DrawCircle( float X, float Y, int radius, int numSides, DWORD Color )
{
    D3DXVECTOR2 Line[128];
    float Step = 3.14 * 2.0 / numSides;
    int Count = 0;
    for ( float a = 0; a < 3.14 * 2.0; a += Step )
    {
        float X1 = radius * cos( a ) + X;
        float Y1 = radius * sin( a ) + Y;
        float X2 = radius * cos( a + Step ) + X;
        float Y2 = radius * sin( a + Step ) + Y;
        Line[Count].x = X1;
        Line[Count].y = Y1;
        Line[Count+1].x = X2;
        Line[Count+1].y = Y2;
        Count += 2;
    }
    directx->pLine->Begin();
    directx->pLine->Draw(Line, Count, Color);
    directx->pLine->End();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cDirectX::PrintText(float x, float y, DWORD color, const char *fmt, ...) 
{
	if ( !directx->pFont )
		return;

	RECT FontPos = { (long)x, (long)y, (long)x + 120, (long)y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start( va_alist, fmt );
	vsprintf_s( buf, fmt, va_alist );
	va_end( va_alist );

	directx->pFont->DrawTextA( NULL, buf, -1, &FontPos, DT_NOCLIP, color );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cDirectX::DrawRGB( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, DWORD color )
{
	if ( !pDevice )
		return;

	sVertex Veri[4] =
	{
		{(float)x		,(float)y		, 0.0f, 0.0f, color},
		{(float)(x+w)	,(float)y		, 0.0f, 0.0f, color},
		{(float)x		,(float)(y+h)	, 0.0f, 0.0f, color},
		{(float)(x+w)	,(float)(y+h)	, 0.0f, 0.0f, color},		
	};

	pDevice->SetTexture( 0, NULL );

	pDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	pDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );
	pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	pDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
	pDevice->SetRenderState( D3DRS_FOGENABLE, false );

    pDevice->SetFVF( sVertex::FVF_Flags  );
	pDevice->DrawPrimitiveUP( D3DPT_TRIANGLESTRIP,2,Veri,sizeof( sVertex ) );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cDirectX::DrawBorder( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, DWORD color1, DWORD color2 )
{ 
	if ( !pDevice )
		return;

	sVertex vertices[6] =
	{
		{float(x+w)	,float(y)		, 0.0f, 1.0f, color2},
		{float(x+w)	,float(y+h)		, 0.0f, 1.0f, color2},
		{float(x)	,float(y+h)		, 0.0f, 1.0f, color2},

		{float(x)	, float(y+h)	, 0.0f, 1.0f, color1},
		{float(x)	, float(y)		, 0.0f, 1.0f, color1},
		{float(x+w)	, float(y)		, 0.0f, 1.0f, color1},
	};
	pDevice->DrawPrimitiveUP( D3DPT_LINESTRIP, 5, vertices, sizeof( sVertex ) );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cDirectX::DrawBox( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, D3DCOLOR BoxColor, D3DCOLOR BorderColor1, D3DCOLOR BorderColor2 ) 
{ 
	if ( !pDevice )
		return;

    directx->DrawRGB( pDevice, x, y, w, h, BoxColor ); 
    directx->DrawBorder( pDevice, x, y, w, h, BorderColor1, BorderColor2 ); 
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//void cDirectX::SliderBase( LPDIRECT3DDEVICE9 pDevice, float x, float y, float BaseWidth, float BaseHeight )
//{
//	if ( !pDevice )
//		return;
//
//	directx.BarX = x;
//	if ( Focused )
//	{
//		if ( directx.BarX < x - 4 - 10 )
//		{
//			if ( GetAsyncKeyState( VK_RIGHT ) < 0 )
//				directx.BarX++;
//		}
//		if ( directx.BarX > !x )
//		{
//			if ( GetAsyncKeyState( VK_LEFT ) < 0 )
//				directx.BarX--;
//		}
//	}
//
//	directx.PrintText( 0, 0, Black, "Test" );
//
//	if ( GetAsyncKeyState( VK_NUMPAD1 ) & 1 )
//	{
//		Sleep(100);
//		Focused = !Focused;
//		directx.DrawBox( pDevice, directx.BarX + 100 + 2, y + 2, 10, BaseHeight - 4, D3DCOLOR_ARGB ( 205, 212, 208, 200 ), D3DCOLOR_ARGB ( 0, 0, 0, 0 ), D3DCOLOR_ARGB ( 0, 0, 0, 0 ) );
//		directx.DrawBox( pDevice, x, y, BaseWidth, BaseHeight, D3DCOLOR_ARGB ( 205, 212, 208, 200 ), D3DCOLOR_ARGB ( 0, 0, 0, 0 ), D3DCOLOR_ARGB ( 0, 0, 0, 0 ) );
//	}
//}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cDirectX::DrawRAMBox( LPDIRECT3DDEVICE9 pDevice, float x, float y )
{
	//if ( !pDevice )
	//	return;

	//MEMORYSTATUSEX RamInfo;
	//RamInfo.dwLength = sizeof ( RamInfo );
	//GlobalMemoryStatusEx( &RamInfo );
	//directx->DrawBox( pDevice, x, y, 110, 55, D3DCOLOR_ARGB ( 205, 212, 208, 200 ), Black, Black );
	//directx->PrintText( x + 5, y + 5 , Black, "Memory Status" );
	//directx->PrintText( x + 5, y + 17, Black, "%i MB Used", (((RamInfo.ullTotalPhys)/(1024*1024)) - ((RamInfo.ullAvailPhys)/(1024*1024))) );
	//directx->PrintText( x + 5, y + 29, Black, "%i MB Total", RamInfo.ullTotalPhys/(1024*1024) );
	//directx->PrintText( x + 5, y + 41, Black, "%i Percent", RamInfo.dwMemoryLoad );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cDirectX::DrawFileText( LPDIRECT3DDEVICE9 pDevice, float x, float y )
{
	//if ( !pDevice )
	//	return;

	//char txt[255];
	//std::ifstream inFile( "C:\\Nexon\\Headline.txt" );
 //   while ( !inFile )
 //   {
	//	directx->PrintText( x, y, Black, "While opening a file an error was encountered!" );
	//}
	//inFile.getline( txt, 255 );
	//std::cout<<txt;
	//directx->PrintText( x, y, Black, txt );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++