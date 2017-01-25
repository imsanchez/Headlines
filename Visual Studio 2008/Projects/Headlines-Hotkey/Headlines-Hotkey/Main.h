//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef MAIN_H
#define MAIN_H
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#pragma once
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <windows.h>
#include <Winuser.h>
#include <stdio.h>
#include <fstream>
#include <stdio.h>
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define MaxHax  51 //Don't change...
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++			
//Addresses
#define ADDR_LTBASE				0x377A0180
#define ADDR_LOCALPTR			0x37152B60
#define ADDR_LTCLIENT_DLL		0x377A0198
#define ADDR_DRAWPRIM			0x8068F8
#define ADDR_PLAYER_BY_INDEX	0x37151CE0
#define	ADDR_GAME_CLIENT_SHELL	0x377E28A0
#define ADDR_RAPIDFIRE			0x373FFC8E
#define ADDR_NORELOAD			0x373FEF94
#define ADDR_NORECOIL1			0x3738B890
#define ADDR_NORECOIL2			0x374AAE09
#define ADDR_NORECOIL3			0x3738B8A4
#define ADDR_NORECOIL4			0x3738B8A7
#define ADDR_NORECOIL5			0x3738B8B0
#define ADDR_SUPERBULLETS		0x373F9C36
#define ADDR_NAMETAGS1			0x372E38AA
#define ADDR_NAMETAGS2			0x372E392D
#define ADDR_RANGE1				0x373FF219
#define ADDR_RANGE2				0x373FF599
#define ADDR_STATUS				0x377B11B0
#define ADDR_WEAPON_MGR			0x377DF21C
#define	ADDR_PLAYER_MGR			0x377E0B14
#define ADDR_CLIENT_INFO_MGR	0x3779EE8C
#define ADDR_REMOTEKILL1		0x373FF341
#define ADDR_REMOTEKILL2		0x373FF342
#define ADDR_REMOTEKILL3		0x373FF6C1
#define ADDR_REMOTEKILL4		0x373FF6C2
#define ADDR_CONSOLEUNWRAPPED	0x00485FA0
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cMain
{
public:
	bool IsGameReadyForHook();
	bool IsInGame();
	void AddHackItem( int i, int Key );
	void __cdecl RunConsoleCommand( const char* szCommand );
	void Memoria( void* pvAddress, void* pvBuffer, size_t len );
	void HackCall( void );
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
extern class cMain main; //Lower case prevents confusion
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++