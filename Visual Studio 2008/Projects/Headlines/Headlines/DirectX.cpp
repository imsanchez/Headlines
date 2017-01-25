// ========================================================================
#include "DirectX.h"
// ========================================================================
cDirectX directx;
// ========================================================================
void cDirectX::PrintText( float x, float y, D3DCOLOR font, const char *fmt, ... ) {
	if ( !directx.pFont )
		return;

	RECT fontpos = { (long)x, (long)y, (long)x + 120, (long)y + 16 };

	char buf[256] = {'0'};
	va_list va_alist;
	va_start( va_alist, fmt );
	vsprintf_s( buf, fmt, va_alist );
	va_end( va_alist );

	directx.pFont->DrawTextA( NULL, buf, -1, &fontpos, DT_NOCLIP, font );
}
// ========================================================================
void cDirectX::PrintShadowedText( float x, float y, D3DCOLOR font, D3DCOLOR shadow, const char *fmt, ... ) {
	if ( !directx.pFont )
		return;

	char buf[256] = {'0'};
	va_list va_alist;
	va_start( va_alist, fmt );
	vsprintf_s( buf, fmt, va_alist );
	va_end( va_alist );

	directx.PrintText(x + 1, y + 1, shadow, buf);
	directx.PrintText(x, y, font, buf);
}
// ========================================================================
void cDirectX::DrawCrosshair( LPDIRECT3DDEVICE9 pDevice, int size, int strong,  D3DCOLOR xcolor ) {
	if ( !pDevice )
		return;

	int iCenterX = ( GetSystemMetrics( 0 ) / 2 );
	int iCenterY = ( GetSystemMetrics( 1 ) / 2 );
	D3DRECT rec2 = { iCenterX - size, iCenterY, iCenterX + size, iCenterY + strong};
	D3DRECT rec3 = { iCenterX, iCenterY - size, iCenterX + strong, iCenterY + size};
	pDevice->Clear(1, &rec2, D3DCLEAR_TARGET, xcolor, 1000, 0);
	pDevice->Clear(1, &rec3, D3DCLEAR_TARGET, xcolor, 100, 0);
}
// ========================================================================
void cDirectX::DrawCircle( float x, float y, float radius, float numSides, D3DCOLOR color ) {
    D3DXVECTOR2 line[128];
    float step = ( float )3.14 * ( float )2.0 / numSides;
    int count = 0;
    for( float a = 0; a < 3.14 * 2.0; a += step ) {
        float x1 = radius * cos( a ) + x;
        float y1 = radius * sin( a ) + y;
        float x2 = radius * cos( a + step ) + x;
        float y2 = radius * sin( a + step ) + y;
        line[count].x = x1;
        line[count].y = y1;
        line[count + 1].x = x2;
        line[count + 1].y = y2;
        count += 2;
    }
    directx.pLine->Begin();
    directx.pLine->Draw( line, count, color );
    directx.pLine->End();
}
// ========================================================================
void cDirectX::DrawRGB( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, DWORD color ) {
	if ( !pDevice )
		return;

	sVertex Veri[4] = {
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
// ========================================================================
void cDirectX::DrawBorder( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, DWORD Color1, DWORD Color2 ) { 
	if ( !pDevice )
		return;

	sVertex vertices[6] = {
		{float(x+w)	,float(y)	, 0.0f, 1.0f, Color2},
		{float(x+w)	,float(y+h)	, 0.0f, 1.0f, Color2},
		{float(x)	,float(y+h)	, 0.0f, 1.0f, Color2},
		{float(x)	,float(y+h)	, 0.0f, 1.0f, Color1},
		{float(x)	,float(y)	, 0.0f, 1.0f, Color1},
		{float(x+w)	,float(y)	, 0.0f, 1.0f, Color1},
	};
	pDevice->DrawPrimitiveUP( D3DPT_LINESTRIP, 5, vertices, sizeof( sVertex ) );
}
// ========================================================================
void cDirectX::DrawBox( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, D3DCOLOR BoxColor, D3DCOLOR BorderColor1, D3DCOLOR BorderColor2 ) { 
	if ( !pDevice )
		return;

    directx.DrawRGB( pDevice, x + 1, y + 1, w - 2, h - 2, BoxColor ); 
    directx.DrawBorder( pDevice, x, y, w - 1, h - 1, BorderColor1, BorderColor2 ); 
}
// ========================================================================
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
// ========================================================================
/*void cDirectX::DrawGradient( LPDIRECT3DDEVICE9 pDevice, float x, float y, float w, float h, D3DCOLOR Color1, D3DCOLOR Color2 ) {
	DWORD a1 = (Color1 >> 24)& 0xFF;
	DWORD r1 = (Color1 >> 16)& 0xFF;
	DWORD g1 = (Color1 >> 8) & 0xFF;
	DWORD b1 = (Color1 >> 32)& 0xFF;
	DWORD a2 = (Color2 >> 24)& 0xFF;
	DWORD r2 = (Color2 >> 16)& 0xFF;
	DWORD g2 = (Color2 >> 8) & 0xFF;
	DWORD b2 = (Color2 >> 32)& 0xFF;
	float aDif, rDif, gDif, bDif;
	aDif = ( ( float )a2 - ( float )a1 ) / h;
	rDif = ( ( float )r2 - ( float )r1 ) / h;
	gDif = ( ( float )g2 - ( int )g1 ) / h;
	bDif = ( ( float )b2 - ( float )b1 ) / h;
	D3DCOLOR Gradient;
	for( int i = 0; i < h; i++ ) {
		Gradient = ( a1 + ( int )( aDif * i ) << 24 ) | ( r1 + ( int )( rDif * i ) << 16 ) | ( g1+  ( int )( gDif * i ) << 8 ) | ( b1 + ( int )( bDif * i ) );
		directx.DrawRGB(pDevice, x, y + i, w, 1, Gradient);
	}
}*/
// ========================================================================
void cDirectX::DrawRAMBox( LPDIRECT3DDEVICE9 pDevice, float x, float y, D3DCOLOR font, D3DCOLOR shadow, D3DCOLOR bg, D3DCOLOR border1, D3DCOLOR border2  ) {
	if ( !pDevice )
		return;

	MEMORYSTATUSEX RamInfo;
	RamInfo.dwLength = sizeof ( RamInfo );
	GlobalMemoryStatusEx( &RamInfo );
	directx.DrawBox( pDevice, x, y, 110, 55, bg, border1, border2 );
	directx.PrintShadowedText( x + 5, y + 2 , font, shadow, "Memory Status" );
	directx.PrintShadowedText( x + 5, y + 14, font, shadow, "%i MB Used", (((RamInfo.ullTotalPhys)/(1024*1024)) - ((RamInfo.ullAvailPhys)/(1024*1024))) );
	directx.PrintShadowedText( x + 5, y + 26, font, shadow, "%i MB Total", RamInfo.ullTotalPhys/(1024*1024) );
	directx.PrintShadowedText( x + 5, y + 38, font, shadow, "%i Percent", RamInfo.dwMemoryLoad );
}
// ========================================================================
void cDirectX::PrintFileText( LPDIRECT3DDEVICE9 pDevice, const char* file, float x, float y, D3DCOLOR font ) {
	if ( !pDevice )
		return;

	char txt[255];
	std::ifstream inFile( file );
    while( !inFile ) {
		directx.PrintText( x, y, font, "An Error was Encountered while Opening Configuration!" );
	}
	inFile.getline( txt, 255 );
	std::cout << txt;
	directx.PrintText( x, y, font, txt );
}
// ========================================================================