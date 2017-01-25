// ========================================================================
// MAIN.CPP
// ========================================================================
//CREATE FONT
	/*HRESULT hr;
	hr = D3DXCreateFontA( pDevice, 15, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font, &directx.pFont );
	if( FAILED( hr ) ) {
		MessageBoxA( GetDesktopWindow(), "Call to D3DXCreateFont failed!", "ERROR", MB_OK|MB_ICONEXCLAMATION );
		directx.pFont = NULL;
	}
	if( directx.pFont == 0 ) {
		D3DXCreateFontA( pDevice, 15, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, Font, &directx.pFont );
	} else {
		if( g_pDevice != pDevice ) {
			g_pDevice = pDevice;
			try { 
				if( directx.pFont != NULL )
					directx.pFont->Release();
			} catch (...) {}
			directx.pFont = NULL;
			D3DXCreateFontA( pDevice, 15, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, Font, &directx.pFont );
		}
	}
	return hr;*/

// AUTOMATIC D3D9 POINTER & CALL RESET / PRESENT
/*bool InstallHook( void ) {
	DWORD GetD3D9Module = 0;
	
	do {
		GetD3D9Module = ( DWORD )GetModuleHandle("d3d9.dll");
		Sleep( 10 );
	} while( !GetD3D9Module );

	//DWORD Address = detour.FindPattern( GetD3D9Module, 0x128000, ( PBYTE )"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx");

	//detour.Memoria( &VTBLS, ( void* )( Address + 2 ), 4 );
	
	DWORD VTBLS[1] = {0};
	detour.CreateDevice( VTBLS );

	//DWORD *zz_hlReset = VTBLS[Reset];
	//DWORD *zz_hlPresent = VTBLS[Present];
	sReset	 = ( tReset )	detour.Create(VTBLS[0], ( DWORD )&hlReset, Detour_Type_0xE9, 5 ); 
	sPresent = ( tPresent )	detour.Create(VTBLS[1], ( DWORD )&hlPresent, Detour_Type_0xE9, 5 );
	//sReset   = ( tReset )  detour.Salta( ( PBYTE )dwTable[0], ( PBYTE )&hlReset, 5 );
	//sPresent = ( tPresent )detour.Salta( ( PBYTE )dwTable[1], ( PBYTE )&hlPresent, 5 );
	free( ( void* )VTBLS );
	Sleep( 10 );
	return 0;

    DWORD GetD3D9Module, Addie, *vLmao, sz_dwPresent, sz_dwReset;
	
	if( detour.FindPattern( GetD3D9Module, 0x128000, ( PBYTE )"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx" ) )
	{
		memcpy( &vLmao, ( void * )( Addie + 2 ),4);
		sz_dwPresent = vLmao[Present];
		sz_dwReset = vLmao[Reset];
		sReset = ( tReset )detour.Create( ( BYTE* )sz_dwReset, ( BYTE* )hlReset, DETOUR_LEN_AUTO ); 
		sPresent = ( tPresent )detour.Create((  BYTE* )sz_dwPresent, ( BYTE* )hlPresent, DETOUR_LEN_AUTO );
		//pPresent = ( oPresent )tools->DetourCreate( ( BYTE* )dwPresent, ( BYTE* )&PresentThunk, Len_Size );
		//pReset = ( oReset )tools->DetourCreate( ( BYTE* )dwReset, ( BYTE* )TheReset, Len_Size );
		//while(true)
		//{
		//	DWORD dwDrawIndexedPrimitive = vLmao[82];
		//	if(  memcmp( ( void * )vLmao[82], ( void * )"\x8B\xFF", 2 ) == 0 )
		//	{
		//		pDrawIndexedPrimitive	 = ( oDrawIndexedPrimitive )tools->DetourCreate( ( PBYTE )TheDrawIndexedPrimitive, ( PBYTE )myDrawIndexedPrimitive, Len_Draw_Size );
		//	}
		//}
		Sleep( 10 );
	}
	free( ( void * )vLmao );
	return TRUE;
}*/
// ========================================================================
// DIRECTX.H
// ========================================================================
class cFont {
	public:
		virtual void Function0();
		virtual void Function1();
		virtual void SetSomthing( int a, int b, int c, int d );
		virtual void Function3();
		virtual void Render();
		virtual void Function5();
		virtual void Function6();
		virtual int GetX();
		virtual void SetPos( int x, int y );
		virtual void GetPos( int* x, int* y );
		virtual void Function10();
		virtual void Function11();
		virtual void Function12();
		virtual float GetScaleX();
		virtual float GetScaleY();
		virtual void Function15();
		virtual void Function16();
		virtual void Function17();
		virtual void Function18();
		virtual void Function19();
		virtual void Function20();
		virtual void Function21();
		virtual void Function22();
		virtual void Function23();
		virtual void Function24();
		virtual void Function25();
		virtual void Function26();
		virtual void Function27();
		virtual void Function28();
		virtual void Function29();
		virtual void Function30();
		virtual void Function31();
		virtual void Function32();
		virtual void Function33();
		virtual void Function34();
		virtual void Function35();
		virtual void Function36();
		virtual void Function37();
		virtual void Function38();
		virtual void Function39();
		virtual void Function40();
		virtual void Function41();
		virtual void Function42();
		virtual void Function43();
		virtual void SetColor( int c, int c_, int c__, int const_num );
		virtual void Function45();
		virtual void Function46();
		virtual void Function47();
		virtual void Function48();
		virtual void Function49();
		virtual void Function50();
		virtual void Function51();
		virtual void Function52();
		virtual void Function53();
		virtual void Function54();
		virtual void Function55();
		virtual void Function56();
		virtual void Function57();
		virtual void Function58();
		virtual void Function59();
		virtual void Function60();
		virtual void Function61();
		virtual void Function62();
		virtual void Function63();
		virtual void Function64();
		virtual void Function65();
		virtual void Function66();
		virtual void Function67();
		virtual void Function68();
		virtual void Function69();
		virtual void Function70();
		virtual void Function71();
		virtual void Function72();
		virtual void Function73();
		virtual void Function74();
		virtual void Function75();
		virtual void Function76();
		virtual void Function77();
		virtual void Function78();
		virtual void Function79();
		virtual void Function80();
		virtual void Function81();
		virtual void Function82();
		virtual void Function83();
		virtual void SetText( unsigned short* text, int cont_num ); 
};
extern cFont* pSmallFont;
extern cFont* pESPFont;
extern cFont* pWarningFont;
extern DWORD dwGetFontHandle, dwFontECX, dwBuildFont, dwFillFont;
// ========================================================================
void RenderString2( cFont* renderer, int x, int y, const char *text, DWORD color );
// ========================================================================
		int FontHandle( int index );
		DWORD BuildFontByFontIndex( int index, int FontSize );
		void InitFonts( void );
		void RenderString( cFont* renderer, int x, int y, const char *text, DWORD color );
// ========================================================================
// DIRECTX.CPP
// ========================================================================
cFont* pSmallFont;
cFont* pESPFont;
cFont* pWarningFont;
DWORD dwGetFontHandle, dwFontECX, dwBuildFont, dwFillFont;
// ========================================================================
int cDirectX::FontHandle( int index ) {
	void* vGetFontHandle = (void*)dwGetFontHandle;
	DWORD dwECX			 = *(DWORD*)dwFontECX;

	__asm
	{
		push 0
		push index
		mov ecx, dwECX
		call [vGetFontHandle]
	}
}
// ========================================================================
DWORD cDirectX::BuildFontByFontIndex( int index, int FontSize ) {
	void* vBuildFont    = (void*)dwBuildFont;
	void* dwFill	    = (void*)dwFillFont;
	int FontHandle      = directx.FontHandle( index );
	DWORD dwFontAddr	= 0;
	BYTE* FontBuffer	= new BYTE[0x228];

	__asm
	{	
		mov ecx, FontBuffer
		call [dwFill]
		mov dwFontAddr, eax	
		mov ecx, eax
		push	0
		push	0
		push	0 
		push	0
		push	FontSize
		push	FontHandle
		push	0
		push	0
		push	0
		call	[vBuildFont]
	}
	return dwFontAddr;
}
// ========================================================================
void cDirectX::InitFonts( void ) {
	pSmallFont		= (cFont*)BuildFontByFontIndex( 30, 11 );
	pESPFont        = (cFont*)BuildFontByFontIndex( 17, 13 );
	pWarningFont	= (cFont*)BuildFontByFontIndex( 15, 25 );
}
// ========================================================================
void RenderString2( cFont* renderer, int x, int y, const char *text, DWORD color ) {
	if( renderer ) {
		renderer->SetText( ( unsigned short* )text, 1 );
		renderer->SetPos( x, y );
		renderer->SetColor( color, color, color, ( int )-1 );
		renderer->Render();
	}
}
// ========================================================================
void cDirectX::RenderString( cFont* renderer, int x, int y, const char *text, DWORD color ) {
	RenderString2( renderer, x - 1, y, text, Black );
	RenderString2( renderer, x, y - 1, text, Black );
	RenderString2( renderer, x + 1, y, text, Black );
	RenderString2( renderer, x, y + 1, text, Black );
	RenderString2( renderer, x, y, text, color );
}
// ========================================================================