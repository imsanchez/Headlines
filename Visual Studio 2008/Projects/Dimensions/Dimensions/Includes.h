//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	-Dimensions- does it again! Everything is nice and neat.
//	Project		: Combined Base v3 Undetected (PRIVATE)
//	Author		: -Dimensions-
//	Date		: 26th of July, 2011
//
//	Credits		: 
//		Qwerty01, Gellin, Hans211, DeadLinez, Alessandro10, and whit
//		FindPattern	 : d0m1n1k
//		DetourCreate : Azorbix
//		This amazing Description Outline? C00lGuy(s)?
//	
//	Tools Used	:
//		Microsoft Visual Studio 2008 Express Edition
//		DirectX9 SDK Update (June 2010)
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef INCLUDES_HEADER
#define INCLUDES_HEADER
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#pragma once
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//						LET US IGNORE SOME STUFF					  // Just in Case
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#pragma warning ( disable: 4996 )
#pragma warning ( disable: 4311 )
#pragma warning ( disable: 4312 )
#pragma warning ( disable: 4244 )
#pragma warning ( disable: 4088 )
#pragma warning ( disable: 4006 )
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								LIBRARIES							  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#pragma comment ( lib, "d3d9.lib" )
#pragma comment ( lib, "d3dx9.lib" )
#pragma comment ( lib, "winmm.lib" )
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							EXTERNAL INCLUDES						  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9core.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h> 
#include <string>
//#include <time.h> //No Purpose
#include <windows.h>
#include <Winuser.h>
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//						INTERNAL HEADER INCLUDES					  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Address.h"
#include "Colors.h"
#include "DirectX.h"
//#include "Hacks.h"
#include "Tools.h"
#include "XorStr.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++