#pragma once

#include "Includes.h"

#define MC_ITEMY(index)	 (Y+(index*I_SPC)+T_SPC+5)
#define MC_ITEMY1(index) (Y+(index*I_SPC)+T_SPC+(FS_SPC*1)+10)
#define MC_ITEMY2(index) (Y+(index*I_SPC)+T_SPC+(FS_SPC*2)+15)
#define MC_ITEMY3(index) (Y+(index*I_SPC)+T_SPC+(FS_SPC*3)+20)

#define mousefix_L  if(GetAsyncKeyState(VK_LBUTTON)){GetAsyncKeyState(VK_RBUTTON);}
#define mousefix_R  if(GetAsyncKeyState(VK_RBUTTON)){GetAsyncKeyState(VK_LBUTTON);}

#define C_OFF	 D3DCOLOR_ARGB( 255, 200, 200, 200 )
#define C_OFF2	 D3DCOLOR_ARGB( 255, 255,   0,   0 )
#define C_ON	 D3DCOLOR_ARGB( 255, 255, 255, 255 )
#define C_ON2	 D3DCOLOR_ARGB( 255,   0, 255,   0 )
#define C_CAT	 D3DCOLOR_ARGB( 250, 255,   0,  40 )
#define C_CURBOX D3DCOLOR_ARGB( 140, 120,  60,  55 )
#define C_TITLE	 D3DCOLOR_ARGB( 250, 255,   0,  40 )
#define C_Menu	 D3DCOLOR_ARGB(  90,   0,   0,   0 )
#define C_Border D3DCOLOR_ARGB( 190,  60,   0,   0 )

struct cGroup{
	int Visual, Weapon, Other;
};

struct cHair{
	int cross, test1, test2, test3;
};

class cMenu{
public:
	POINT Cur;
	void Render( LPDIRECT3DDEVICE9 pDevice );
	bool MouseIsOver( int x, int y, int w, int h );
	void CreateGUI( LPDIRECT3DDEVICE9 pDevice );
private:
	int
		NO,
		X,Y,
		Current,
		Width,
		I_OFS,S_OFS,G_OFS,
		I_SPC,T_SPC
	;

	struct sitem
	{
		char title[50];
		char state[50];
		int	 type;
		int  max;
		int  no;
		int	 *val;
	}
	items[50];

	enum I_TYPES
	{
		T_TEXT = 0,
		T_ITEM = 1,
		T_CAT  = 2
	};

	void  InitializeMenu();
	void  additem(char *title, char *states,int type, int *var, int show, int when);
	void  Group(char *title, char *states,int *var);
	void  Item(char *title, char *states,int *var,int show,int when);
	int   nofields(char *str);
	void  getfield(char *str,char *dst,int no);
};

extern class cMenu* menu;

class cHacks{
public:
	void RenderHacks(LPDIRECT3DDEVICE9 Device);
};

extern class cHacks* hacks;