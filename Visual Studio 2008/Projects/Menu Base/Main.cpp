#include "Main.h"

cMain Main;


oPresent pPresent;
oReset pReset;

LPDIRECT3DDEVICE9 g_pDevice = 0;


void cMain::Render(LPDIRECT3DDEVICE9 pDevice)
{	
	if(Main.pFont != NULL)
	{
		Main.DrawString(0 , 0, 0xFFFF0000, Main.pFont, Hack_Name); // Hack Title..

		Menu.Render (pDevice);//Menu Render
		Hack.hCommands();
		//etc...
	}else if (g_pDevice != pDevice)
	{
		g_pDevice = pDevice;
		try
		{ 
			if (Main.pFont != 0)
				Main.pFont->Release();
		} catch (...) {}
		Main.pFont = 0;
		D3DXCreateFontA(pDevice, 13, 0, FW_NORMAL, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, 
			DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, Font_Name, &Main.pFont);
	}
}

void cMenu::StyleRender(LPDIRECT3DDEVICE9 pDevice)
{
	Menu.DrawBox(Menu.MenuSt.x  - 5 , Menu.MenuSt.y  - 20, 300 , 150 ,5,0xFFD4D7D4,0xFF787878,0xFF787878,pDevice);
	Main.DrawString(Menu.MenuSt.x + 30 , Menu.MenuSt.y - 15 , 0xFF000000, Main.pFont, Menu_Title); // Menu Title..
}

HRESULT WINAPI MyPresent(LPDIRECT3DDEVICE9 pDevice, CONST RECT *pSourceRect, 
						   CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion)
{
	_asm pushad;

	pDevice->SetTexture( NULL, NULL );
	pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, D3DZB_TRUE );
	pDevice->SetFVF( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 );
	pDevice->SetRenderState( D3DRS_FOGENABLE, false );
	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );

	Main.Render(pDevice);

	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_TRUE );
    pDevice->SetTexture(0, NULL); 

	_asm popad;
	return pPresent(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT WINAPI MyReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters )
{
	_asm pushad;

	Main.pFont->OnLostDevice();

	HRESULT hRet = pReset(pDevice, pPresentationParameters);

	if(SUCCEEDED(hRet))
		Main.pFont->OnResetDevice();

	_asm popad;

	return pReset(pDevice, pPresentationParameters);
}


void cMain::Hook() 
{
	//Creetiz : Hans && Gordon
	DWORD	dwD3D9, Address, *vtbl;
	dwD3D9 = 0;
	do {
		dwD3D9 = (DWORD)GetModuleHandle(D3D9_Name);
		Sleep(10);
	} while(!dwD3D9);

	Address = Main.FindPattern(dwD3D9, 0x128000, (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx");
	
	if ( Address ) 
	{
		memcpy(&vtbl,(void *)(Address+2),4);
		pReset   = ( oReset   )cMain::DetourCreate(( PBYTE ) vtbl[Reset],   ( PBYTE ) &MyReset   ,Len_size );
		pPresent = ( oPresent )cMain::DetourCreate(( PBYTE ) vtbl[Present], ( PBYTE ) &MyPresent ,Len_size );
	}
}

DWORD WINAPI dwHookThread(LPVOID)
{
	while(!Main.HookReady())
		Sleep(25);

	Main.Hook();
	return EXIT_SUCCESS;
}

BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	DisableThreadLibraryCalls(hDll);
	if ( dwReason == 1 )
		CreateThread(NULL, NULL,dwHookThread, NULL, NULL, NULL);

	return TRUE;
}

void cMain::DrawString(int x, int y, DWORD color, LPD3DXFONT g_pFont, const char *fmt, ...) 
{
	if(!g_pFont)
		return;

	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	g_pFont->DrawTextA(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

bool cMain::bDataCompare(const BYTE* pData, const BYTE* bMask, const char* szMask) 
{ 
    for(;*szMask;++szMask,++pData,++bMask) 
        if(*szMask=='x' && *pData!=*bMask )  
            return false; 
    return (*szMask) == NULL; 
} 


DWORD cMain::FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask) 
{ 
    for(DWORD i=0; i < dwLen; i++) 
		if(Main.bDataCompare( (BYTE*)( dwAddress+i ),bMask,szMask) ) 
            return (DWORD)(dwAddress+i); 
     
    return 0; 
}

void *cMain::DetourCreate(BYTE *src, const BYTE *dst, const int len)
{
	BYTE *jmp = (BYTE*)malloc(len+5);
	DWORD dwback;
	VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len); jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src+1) = (DWORD)(dst - src) - 5;
	VirtualProtect(src, len, dwback, &dwback);
	return (jmp-len);
}

bool cMain::HookReady()
{
	if( GetModuleHandle( L"d3d9.dll" ) != NULL  )
	   return true;
	return false;
}