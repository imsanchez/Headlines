//======================================================================
#ifndef __MENU_H__
#define __MENU_H__
//======================================================================
#pragma once
//======================================================================
#define tabCount		5
#define checkBoxCount	255

#define FONTSIZE 15
#define PADDING 5

#define WIN2KBORDER D3DCOLOR_ARGB ( 255, 65, 65, 60 )
#define WIN2KBLUE D3DCOLOR_ARGB( 255, 9, 36, 107 )
//======================================================================
struct iMenuSt_t {
	bool isVisible;
	int itemNumber, tabNumber;
};
//======================================================================
struct iTabSt_t {
	bool state;
};
//======================================================================
struct iChkBoxSt_t {
	char* name;
	bool isActive;
	//void (__thiscall cHacks::*var)(int *);
};
//======================================================================
class cMenu {
public:
	iMenuSt_t MenuSt;
	iTabSt_t TabSt[ tabCount ][ checkBoxCount ];
	iChkBoxSt_t CheckBoxSt[ checkBoxCount ];
	bool MouseIsOver( int x, int y, int w, int h );
	bool MouseIsActive( int x, int y, int w, int h );
	void Render( LPDIRECT3DDEVICE9 pDevice, D3DCOLOR font, D3DCOLOR shadow, D3DCOLOR box );
	void AddCheck( LPDIRECT3DDEVICE9 pDevice, char* name, int tab, void (__thiscall cHacks::*var)(int), D3DCOLOR font, D3DCOLOR shadow, D3DCOLOR box );
	void AddTab( LPDIRECT3DDEVICE9 pDevice, char* name, int x, int padding, int y, int w, int h, D3DCOLOR font, D3DCOLOR shadow, D3DCOLOR box );
    //void RenderMenu( void );
	//void MenuNav( void );
    //void MenuShow( int x, int y, LPDIRECT3DDEVICE9 pDevice );
	//void Hotkey( void );
	//int GetMax( int vars );
private:
	//void AddCheck( LPDIRECT3DDEVICE9 pDevice, char* txt, int x, int y, int w, int h, int tab );
	//void AddItem( char *txt, char **opt, void (__thiscall cHacks::*var)(int *), int maxvalue, int typ );
};
//======================================================================
extern class cMenu menu;
//======================================================================
#endif
//======================================================================