// ========================================================================
#ifndef __KEYS_H__
#define __KEYS_H__
// ========================================================================
#pragma once
// ========================================================================
#define KEY_LEFTMOUSE		"Left Mouse"
#define KEY_RIGHTMOUSE		"Right Mouse"
#define KEY_BREAK			"Break"
#define KEY_MIDDLEMOUSE		"Middle Mouse"
#define KEY_BACKSPACE		"Backspace"
#define KEY_TAB				"Tab"
#define KEY_CLEAR			"Clear"
#define KEY_ENTER			"Enter"
#define KEY_SHIFT			"Shift"
#define KEY_CTRL			"Ctrl"
#define KEY_ALT				"Alt"
#define KEY_PAUSE			"Pause"
#define KEY_CAPSLOCK		"Caps"
#define KEY_ESC				"Esc"
#define KEY_SPACE			"Space"
#define KEY_PAGEUP			"Page Up"
#define KEY_PAGEDOWN		"Page Down"
#define KEY_END				"End"
#define KEY_HOME			"Home"
#define KEY_LEFT			"Left"
#define KEY_UP				"Up"
#define KEY_RIGHT			"Right"
#define KEY_DOWN			"Down"
#define KEY_SELECT			"Select"
#define KEY_PRINT			"Print"
#define KEY_EXEC			"Execute"
#define KEY_PRINTSCREEN		"PrntScrn"
#define KEY_INSERT			"Insert"
#define KEY_DELETE			"Delete"
#define KEY_HELP			"Help"
#define KEY_ZERO			"0"
#define KEY_ONE				"1"
#define KEY_TWO				"2"
#define KEY_THREE			"3"
#define KEY_FOUR			"4"
#define KEY_FIVE			"5"
#define KEY_SIX				"6"
#define KEY_SEVEN			"7"
#define KEY_EIGHT			"8"
#define KEY_NINE			"9"
#define KEY_A				"A"
#define KEY_B				"B"
#define KEY_C				"C"
#define KEY_D				"D"
#define KEY_E				"E"
#define KEY_F				"F"
#define KEY_G				"G"
#define KEY_H				"H"
#define KEY_I				"I"
#define KEY_J				"J"
#define KEY_K				"K"
#define KEY_L				"L"
#define KEY_M				"M"
#define KEY_N				"N"
#define KEY_O				"O"
#define KEY_P				"P"
#define KEY_Q				"Q"
#define KEY_R				"R"
#define KEY_S				"S"
#define KEY_T				"T"
#define KEY_U				"U"
#define KEY_V				"V"
#define KEY_W				"W"
#define KEY_X				"X"
#define KEY_Y				"Y"
#define KEY_Z				"Z"
#define KEY_NUMPAD0			"Numpad 0"
#define KEY_NUMPAD1			"Numpad 1"
#define KEY_NUMPAD2			"Numpad 2"
#define KEY_NUMPAD3			"Numpad 3"
#define KEY_NUMPAD4			"Numpad 4"
#define KEY_NUMPAD5			"Numpad 5"
#define KEY_NUMPAD6			"Numpad 6"
#define KEY_NUMPAD7			"Numpad 7"
#define KEY_NUMPAD8			"Numpad 8"
#define KEY_NUMPAD9			"Numpad 9"
#define KEY_MULTIPLY		"Numpad *"
#define KEY_ADD				"Numpad +"
#define KEY_SEPARATOR		"Numpad Enter"
#define KEY_SUBTRACT		"Numpad -"
#define KEY_DECIMAL			"Numpad ."
#define KEY_DIVIDE			"Numpad /"
#define KEY_F1				"F1"
#define KEY_F2				"F2"
#define KEY_F3				"F3"
#define KEY_F4				"F4"
#define KEY_F5				"F5"
#define KEY_F6				"F6"
#define KEY_F7				"F7"
#define KEY_F8				"F8"
#define KEY_F9				"F9"
#define KEY_F10				"F10"
#define KEY_F11				"F11"
#define KEY_F12				"F12"
#define KEY_F13				"F13"
#define KEY_F14				"F14"
#define KEY_F15				"F15"
#define KEY_F16				"F16"
#define KEY_F17				"F17"
#define KEY_F18				"F18"
#define KEY_F19				"F19"
#define KEY_F20				"F20"
#define KEY_F21				"F21"
#define KEY_F22				"F22"
#define KEY_F23				"F23"
#define KEY_F24				"F24"
#define KEY_NUMLOCK			"Num Lock"
#define KEY_SCROLLLOCK		"Scroll Lock"
#define KEY_LEFTSHIFT		"Left Shift"
#define KEY_RIGHTSHIFT		"Right Shift"
#define KEY_LEFTCONTROL		"Left Ctrl"
#define KEY_RIGHTCONTROL	"Right Ctrl"
#define KEY_LEFTALT			"Left Alt"
#define KEY_RIGHTALT		"Right Alt"
#define KEY_PLAY			"Play"
#define KEY_ZOOM			"Zoom"
#define KEY_SEMICOLON		";"
#define KEY_COMMA			","
#define KEY_EQUALS			"="
#define KEY_MINUS			"-"
#define KEY_PERIOD			"."
#define KEY_FORWARDSLASH	"/"
#define KEY_TILDE			"~"
#define KEY_OPENBRACKET		"["
#define KEY_BACKSLASH		"\\"
#define KEY_CLOSEBRACKET	"]"
#define KEY_QUOTE			"\""
// ========================================================================
class cKeys {
public:
	struct KeyEvents_t {
		static const int LeftMouse		= VK_LBUTTON;
		static const int RightMouse		= VK_RBUTTON;
		static const int Break			= VK_CANCEL;
		static const int MiddleMouse	= VK_MBUTTON;
		static const int Backspace		= VK_BACK;
		static const int Tab			= VK_TAB;
		static const int Clear			= VK_CLEAR;
		static const int Enter			= VK_RETURN;
		static const int Shift			= VK_SHIFT;
		static const int Ctrl			= VK_CONTROL;
		static const int Alt			= VK_MENU;
		static const int Pause			= VK_PAUSE;
		static const int CapsLock		= VK_CAPITAL;
		static const int Esc			= VK_ESCAPE;
		static const int Space			= VK_SPACE;
		static const int PageUp			= VK_PRIOR;
		static const int PageDown		= VK_NEXT;
		static const int End			= VK_END;
		static const int Home			= VK_HOME;
		static const int Left			= VK_LEFT;
		static const int Up				= VK_UP;
		static const int Right			= VK_RIGHT;
		static const int Down			= VK_DOWN;
		static const int Select			= VK_SELECT;
		static const int Print			= VK_PRINT;
		static const int Execute		= VK_EXECUTE;
		static const int PrintScreen	= VK_SNAPSHOT;
		static const int Insert			= VK_INSERT;
		static const int Delete			= VK_DELETE;
		static const int Help			= VK_HELP;
		static const int Zero			= 0x30;
		static const int One			= 0x31;
		static const int Two			= 0x32;
		static const int Three			= 0x33;
		static const int Four			= 0x34;
		static const int Five			= 0x35;
		static const int Six			= 0x36;
		static const int Seven			= 0x37;
		static const int Eight			= 0x38;
		static const int Nine			= 0x39;
		static const int A				= 0x41;
		static const int B				= 0x42;
		static const int C				= 0x43;
		static const int D				= 0x44;
		static const int E				= 0x45;
		static const int F				= 0x46;
		static const int G				= 0x47;
		static const int H				= 0x48;
		static const int I				= 0x49;
		static const int J				= 0x4A;
		static const int K				= 0x4B;
		static const int L				= 0x4C;
		static const int M				= 0x4D;
		static const int N				= 0x4E;
		static const int O				= 0x4F;
		static const int P				= 0x50;
		static const int Q				= 0x51;
		static const int R				= 0x52;
		static const int S				= 0x53;
		static const int T				= 0x54;
		static const int U				= 0x55;
		static const int V				= 0x56;
		static const int W				= 0x57;
		static const int X				= 0x58;
		static const int Y				= 0x59;
		static const int Z				= 0x5A;
		static const int Numpad0		= VK_NUMPAD0;
		static const int Numpad1		= VK_NUMPAD1;
		static const int Numpad2		= VK_NUMPAD2;
		static const int Numpad3		= VK_NUMPAD3;
		static const int Numpad4		= VK_NUMPAD4;
		static const int Numpad5		= VK_NUMPAD5;
		static const int Numpad6		= VK_NUMPAD6;
		static const int Numpad7		= VK_NUMPAD7;
		static const int Numpad8		= VK_NUMPAD8;
		static const int Numpad9		= VK_NUMPAD9;
		static const int Multiply		= VK_MULTIPLY;
		static const int Add			= VK_ADD;
		static const int Separator		= VK_SEPARATOR;
		static const int Subtract		= VK_SUBTRACT;
		static const int Decimal		= VK_DECIMAL;
		static const int Divide			= VK_DIVIDE;
		static const int F1				= VK_F1;
		static const int F2				= VK_F2;
		static const int F3				= VK_F3;
		static const int F4				= VK_F4;
		static const int F5				= VK_F5;
		static const int F6				= VK_F6;
		static const int F7				= VK_F7;
		static const int F8				= VK_F8;
		static const int F9				= VK_F9;
		static const int F10			= VK_F10;
		static const int F11			= VK_F11;
		static const int F12			= VK_F12;
		static const int F13			= VK_F13;
		static const int F14			= VK_F14;
		static const int F15			= VK_F15;
		static const int F16			= VK_F16;
		static const int F17			= VK_F17;
		static const int F18			= VK_F18;
		static const int F19			= VK_F19;
		static const int F20			= VK_F20;
		static const int F21			= VK_F21;
		static const int F22			= VK_F22;
		static const int F23			= VK_F23;
		static const int F24			= VK_F24;
		static const int NumLock		= VK_NUMLOCK;
		static const int ScrollLock		= VK_SCROLL;
		static const int LeftShift		= VK_LSHIFT;
		static const int RightShift		= VK_RSHIFT;
		static const int LeftControl	= VK_LCONTROL;
		static const int RightControl	= VK_RCONTROL;
		static const int LeftAlt		= VK_LMENU;
		static const int RightAlt		= VK_RMENU;
		static const int Play			= VK_PLAY;
		static const int Zoom			= VK_ZOOM;
		static const int SemiColon		= VK_OEM_1;
		static const int Comma			= VK_OEM_COMMA;
		static const int Equals			= VK_OEM_PLUS;
		static const int Minus			= VK_OEM_MINUS;
		static const int Period			= VK_OEM_PERIOD;
		static const int ForwardSlash	= VK_OEM_2;
		static const int Tilde			= VK_OEM_3;
		static const int OpenBracket	= VK_OEM_4;
		static const int BackSlash		= VK_OEM_5;
		static const int CloseBracket	= VK_OEM_6;
		static const int Quote			= VK_OEM_7;
		static const int None			= NULL;
	} KeyEvents;

	bool KeyPressed(int Key);
	char* KeyName(int Key);
	int NextKeyPress(int waitTime);
	int SecToMil(int Sec);
	bool isLetter(int Key);
private:
	//
};
// ========================================================================
extern cKeys keys;
// ========================================================================
#endif
// ========================================================================