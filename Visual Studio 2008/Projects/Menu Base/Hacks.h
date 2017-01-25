#ifndef _Hack
#define _Hack

#pragma once

#include "Files.h"

struct Flags
{
	bool Flag[15];
};

class cHack
{
public:
	Flags Flag;
	void hCommands(void);
	void __cdecl pRun_Command(const char* szCommand); 
	void PatchCommand(bool MenuVal ,char *commandOn, char *commandOff, bool& zsFlag);
};

extern class cHack Hack;

#endif