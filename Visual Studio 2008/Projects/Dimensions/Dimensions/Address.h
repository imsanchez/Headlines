//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#pragma once

#define Reset 16
#define Present 17
#define Len_Size 5
#define Len_Draw_Size 12
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//SFX ID's								
#define SFX_NADE				0x13
#define SFX_PICKUP				0x17
#define SFX_CHARACTER			0x18
#define SFX_MAX					0x3B
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//CShell.dll								
#define ADDR_LTBASE				0x377A0180 //0x3778CF40
#define ADDR_LOCALPTR			0x37152B60 //0x37152250
#define ADDR_RANDOMPTR			//0x377CF9F8
#define ADDR_LTCLIENT_DLL		0x377A0198 //0x3778CF58
#define ADDR_DRAWPRIM			0x8068F8 //0x00804454 //0x800054 //0x8024F8
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_PLAYER_BY_INDEX	0x37151CE0
#define	ADDR_GAME_CLIENT_SHELL	0x377E28A0
//Anti-Kick |V|
//On: \x0C\x05\x45\xF1
//Off: \xFF\x32\x22\XF1
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_UNLAMMO			//0x373F7DF0
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_RAPIDFIRE			0x373FFC8E //0x373F7555
//#define ADDR_RAPIDFIRE2			0x373F751E
//#define ADDR_RAPIDFIRE3			0x373F33D7
//#define ADDR_RAPIDFIRE4			0x373F7525
//#define ADDR_RAPIDFIRE5			0x373F7358
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_TELEPORT			//0x373F7555
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_NORELOAD			0x373FEF94 //0x3747EC07
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_NORECOIL1			0x3738B890 //0x37383E60
#define ADDR_NORECOIL2			0x374AAE09 //0x3749C949
#define ADDR_NORECOIL3			0x3738B8A4 //0x37383E74
#define ADDR_NORECOIL4			0x3738B8A7 //0x37383E80
#define ADDR_NORECOIL5			0x3738B8B0 //0x37383E80
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_PLAYERBYINDEX		//0x37151450
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_SUPERBULLETS		0x373F9C36 //0x373F14F6
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_GAMECLIENTSHELL	//0x377CF310
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_CLIENTINFO			//0x3778BC4C
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_NAMETAGS1			0x372E38AA //0x372DF3E0
#define ADDR_NAMETAGS2			0x372E392D //0x372DF45D
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_RANGE1				0x373FF219 //0x373F6AD9
#define ADDR_RANGE2				0x373FF599 //0x373FF469 //0x373F6E59
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_STATUS				0x377B11B0 //0x3779DF64
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_WEAPON_MGR			0x377DF21C //0x377CBC8C
#define	ADDR_PLAYER_MGR			0x377E0B14 //0x377CD584
#define ADDR_CLIENT_INFO_MGR	0x3779EE8C
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_REMOTEKILL1		0x373FF341 //0x374B5861
#define ADDR_REMOTEKILL2		0x373FF342 //0x374B5862 
#define ADDR_REMOTEKILL3		0x373FF6C1 //0x374B5AB1
#define ADDR_REMOTEKILL4		0x373FF6C2 //0x374B5AB2
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ADDR_BUILDFONT			//0x37537B10
#define ADDR_FILLFONT			//0x375387A0
#define ADDR_FONTECX			//0x377E29BC
#define ADDR_FONTHAND			//0x3744F780
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//FPS
//#define ADDR_FORCEFPS			0x3780CC20 //0x3780AC00 //0x377F49C0
//#define OFF_FPS					0xDA00
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Engine.exe
#define ADDR_D3D                0x00910368 //0x90BF60
//#define ADDR_W2S              0x4913C0 
//#define ADDR_CURSORCENTER		0x7E943C
#define ADDR_CONSOLEUNWRAPPED	0x00485FA0 //0x00485F90
//#define ADRR_INTERSECT		0x470AE0
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//ClientFx.fxd
#define ADDR_CLIENTFX           //0x66F34
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//HackShield Bypass
#define ZwOpenProcess			//0x10095D6F //68 F8 1B 0F 10
#define ZwReadVirtualMemory		//0x10095DAB //68 E4 1B 0F 10
#define ZwWriteVirtualMemory	//0x10095DE7 //68 CC 1B 0F 10
#define ZwSuspendThread			//0x10095E23 //68 BC 1B 0F 10
#define ZwTerminateThread		//0x10095E57 //68 A8 1B 0F 10
#define ZwSetContextThread		//0x10095E8B //68 94 1B 0F 10
#define ZwGetContextThread		//0x10095EBF //68 80 1B 0F 10
#define ZwQueryPerformance		//0x10095EFB //68 64 1B 0F 10
#define ZwDeviceIoControl		//0x10095F2F //68 08 1C 0F 10
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++