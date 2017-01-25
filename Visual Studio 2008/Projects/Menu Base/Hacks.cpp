#include "Hacks.h"

cHack Hack;

void __cdecl cHack::pRun_Command(const char* szCommand)
{
	__asm 
	{
		PUSH szCommand
		MOV EAX, 0x485f60
		CALL EAX
		ADD ESP, 0x4
	}
}

void cHack::PatchCommand(bool MenuVal,char *commandOn,char *commandOff,bool& zsFlag)
{
	if(MenuVal)
	{
		if(zsFlag == true)
		{
			Hack.pRun_Command(commandOn);
			zsFlag = false;
		}
	}else{
		if(zsFlag == false)
		{
			Hack.pRun_Command(commandOff);
			zsFlag = true;
		}
	}
}

void cHack::hCommands(void)
{
	int i = 0;
	Hack.PatchCommand( Menu.CheckBox[0][1].State , "SkelModelStencil 1",	"SkelModelStencil 0"		, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][2].State , "FullBright 1",			"FullBright 0"				, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][3].State , "FogEnable 0",			"FogEnable 1"				, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][4].State , "WireFrame 1",			"WireFrame 0"				, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][5].State , "WireframeModels 1",		"WireframeModels 0"			, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][6].State , "DrawVolumeEffects 0",	"DrawVolumeEffects 1"		, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][7].State , "ScreenGlowEnable 1",	"ScreenGlowEnable 0"		, Hack.Flag.Flag[i++]);

	Hack.PatchCommand( Menu.CheckBox[1][1].State , "PerturbRotationEffect 0",		"PerturbRotationEffect 3"       , Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[1][1].State , "PerturbIncreaseSpeed 0",		"PerturbIncreaseSpeed 0"        , Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[1][1].State , "PerturbWalkPercent 0",			"PerturbWalkPercent 0"			, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[1][1].State , "PerturbFiringIncreaseSpeed 0",	"PerturbFiringIncreaseSpeed 0"  , Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[1][2].State, "ActivationDistance 9999",		"ActivationDistance 100"		, Hack.Flag.Flag[i++]);
	
	Hack.PatchCommand( Menu.CheckBox[2][1].State , "JumpVel 600",		"JumpVel 330"				, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[2][2].State , "ShowFPS 1",			"ShowFPS 0"					, Hack.Flag.Flag[i++]);
}