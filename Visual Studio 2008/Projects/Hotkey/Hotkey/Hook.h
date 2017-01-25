#ifndef _HOOK_
#define _HOOK_

#pragma once

#include "files.h"

class cHook{
public:
		cHook( void )
		{
			Do_Once = false;
		}

		void OnResetDevice( void )
		{
			pSprite->OnResetDevice( );
			pFont->OnResetDevice( );
		}

		void OnLostDevice( void )
		{
			pSprite->OnLostDevice( );
			pFont->OnLostDevice( );
		}

		void Release( void )
		{
			pSprite->Release( );
			pFont->Release( );
		}

		bool OverCheckPointers( void )
		{
			if( pDevice && m_pDevice == pDevice && pFont && pSprite )
				return true;

			return false;
		}

		void Create( void )
		{
			if( pDevice == NULL )
				return;

			this->m_pDevice = this->pDevice;

			HRESULT FontSpriteRes	= D3DXCreateSprite( this->m_pDevice, &this->pSprite );
			HRESULT FontRes			= D3DXCreateFont( this->m_pDevice, 12, 0, FW_NORMAL, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &this->pFont );

			if( FontRes == S_OK && FontSpriteRes == S_OK  )
				add_log( Log_File, "Font Created Successfully..." );
			else
				add_log( Log_File, "Font Creation Failed..." );
		}

		void DrawText( int x, int y, DWORD Color, const char* szString )
		{
			if( this->pDevice == NULL )
				return;

			RECT FontRect = { x, y, x + 120, y + 16 };

			pSprite->Begin( D3DXSPRITE_ALPHABLEND );
			pFont->DrawText( pSprite, szString, - 1, &FontRect, DT_NOCLIP, Color );
			pSprite->End( );
		}

		void __cdecl add_log( char *file,  const char *fmt, ... )
		{
			ofile.open( file, ios::app );

			va_list va_alist;
			char logbuf[256] = {0};

			va_start (va_alist, fmt);
			vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), fmt, va_alist);
			va_end (va_alist);

			ofile << logbuf << endl;

			ofile.close();
		}

		void *DetourCreate(BYTE *src, const BYTE *dst, const int len)	
		{
			BYTE *jmp = (BYTE*)malloc(len+5);
			DWORD dwBack;

			VirtualProtect( src, len, PAGE_EXECUTE_READWRITE, &dwBack );
			memcpy( jmp, src, len );

			jmp += len;
			jmp[0] = 0xE9;
			*(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;
			src[0] = 0xE9;
			*(DWORD*)(src+1) = (DWORD)(dst - src) - 5;
			for( int i=5; i<len; i++ ) 
				src[i]=0x90;

			VirtualProtect( src, len, dwBack, &dwBack );
			FlushInstructionCache( GetCurrentProcess(), src, 0x10 );

			return (jmp-len);
		}
public:
		void RenderEx( void );
		LPDIRECT3DDEVICE9 pDevice, m_pDevice;

private:
	bool Do_Once;
	ofstream ofile;
	LPD3DXFONT pFont;
	LPD3DXSPRITE pSprite;

	void Render( void );
};

extern cHook* hook;

#endif