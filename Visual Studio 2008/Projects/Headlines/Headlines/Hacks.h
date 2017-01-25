#ifndef __HACKS_H__
#define __HACKS_H__

#pragma once

#include "Includes.h"

class cHacks {
public:
	bool ValidPointer( void* p ) { 
		return !IsBadReadPtr( p, 4 ) && p;
	}

	D3DXVECTOR3 GetObjectMaxPos( int* obj ) {
		return *(D3DXVECTOR3*)( obj + 0x4 );
	}

	D3DXVECTOR3 GetObjectMinPos( int* obj ) {
		return *(D3DXVECTOR3*)( obj + 0x10 );
	}

	D3DXVECTOR3 GetObjectRootPos( int* obj ) {
		return *(D3DXVECTOR3*)( obj + 0xC8 );
	}

	DWORD GetObjectColorRGBA( int* obj ) {
		return *(DWORD*)( obj + 0x94 );
	}

	DWORD SetObjectColorRGBA( int* obj, DWORD dwColorRGBA ) {
		*(DWORD*)( obj + 0x94 ) = dwColorRGBA;
	}

	void __stdcall RunConsoleCommand( const char* cCommand );
	void Render( LPDIRECT3DDEVICE9 pDevice );
	void Crosshair( int type );
	void SatChams( int active );
	void Skeletons( int active );
	void Tracers( int active );
	void Prediction( int active );
	void vJump( int setting );
	void ModelMod( int setting );
	void Walls( int setting );
	void GhostMode( int active );
	void Activation( int active );
	void Fly( int active );
	void SuperJump( int active );
	void Hover( int active );
	void SpeedHack( int speed );
//	void SuperBullets( int active );
	void AntiSS( int active );
	void Unlagged( int active );
	void NoFog( int active );
	void NoKnockBack( int active );
	void NoReloadd( int active );
//	void NoRecoil( int active );
	void NoSmoke( int active );
	void NoSpread( int active );
	void NoWeapSway( int active );
	void NoWeap( int active );
	void Suicide( int active );
	void ShowFPS( int active );
	//UNLOCK CURSOR GOES HERE
	void Scores( int active );
	void Windowed( int active );
	void NoCameraSway( int active );
	void CrashCA( int active );
	void FolderHolder( int menu );
	void Refresh( int active );
};

extern class cHacks hacks;
extern int refresh;

#endif
