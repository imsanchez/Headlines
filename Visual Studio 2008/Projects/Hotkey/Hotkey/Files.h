//////////////////////////////////////////////////////////////////////////
//	    Combat Arms: Mid-function Engine ( "Engine.exe" ) D3D Hook		//
//					 Created By: Gellin									//
//																		//
//		Released On: www.uc-forum.com && www.delta-h.net Only			//
//																		//
//			Credits: www.uc-forum.com && www.delta-h.net				//
//				   : Ghoster - Pro - The Starship commander 			//
//				   : raiders - help with font & he pro to				//
//				   : micro   - Menu base he pro afk lul					//
//				   : All Uc-Forum & Delta-h members i forgot			//
//																		//
//			Shouts:	www.delta-h.net										//
//					- CD												//
//					- Cobra												//
//																		//
//////////////////////////////////////////////////////////////////////////

#ifndef _FILES_
#define _FILES_

#pragma once

#define WIN32_LEAN_AND_MEAN
#define VC_EXTRA_LEAN

//Core Includes

#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

#include <iostream>
#include <fstream>

//Global Definitions
using namespace std;

#define ADDR_DEVICE 0x90AF20 //0x909EF8
#define Log_File "C:\\UC_D3D_Log.txt"

#endif