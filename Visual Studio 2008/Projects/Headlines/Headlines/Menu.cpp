//======================================================================
#include "Menu.h"
//======================================================================
cMenu menu;
POINT cPos;
//======================================================================
bool isDragging[6], isVisible;
int OffSetX[6], OffSetY[6];
int WinX[6] = { 5, 160, 320, 480, 640 }; 
int WinY[6] = { 50, 50, 50, 50, 50 };
/*======================================================================
//The Actual Menu
void cMenu::RenderMenu( void ) {
//======================================================================
	AddItem( "  .: Visual :."		, Opt_Folder	, &cHacks::FolderHolder	, 2		, MENUFOLDER ); //1
		if( visual ) {
			AddItem( "NX. Chams"		, Opt_on_off	, &cHacks::SatChams		, 2		, MENUITEM ); //1
			//AddItem( "Color Chams"	, Opt_Colors	, &cHacks::ColorChams	, 5		, MENUITEM ); //2
			//AddItem( "Special Chams"	, Opt_Chams		, &visual3				, 4		, MENUITEM);//3
			AddItem( "Cross-Hair"		, Opt_Colors	, &cHacks::Crosshair	, 5		, MENUITEM ); //4
			AddItem( "Skeletons"		, Opt_on_off	, &cHacks::Skeletons	, 2		, MENUITEM ); //5
			AddItem( "Tracers"			, Opt_on_off	, &cHacks::Tracers		, 2		, MENUITEM ) ; //6
			AddItem( "Prediction"		, Opt_on_off	, &cHacks::Prediction	, 2		, MENUITEM ); //7
			AddItem( "Virtual Jump"		, Opt_VJump		, &cHacks::vJump		, 3		, MENUITEM ); //8
			//AddItem( "Blood Modifier"	, Opt_Blood		, &visual9				, 2		, MENUITEM);//9
			AddItem( "Model Modifier"	, Opt_Model		, &cHacks::ModelMod		, 3		, MENUITEM ); //10
			AddItem( "Wall Modifier"	, Opt_Wall		, &cHacks::Walls		, 5		, MENUITEM ); //11
			AddItem( "Ghost Mode"		, Opt_Val		, &cHacks::GhostMode	, 18	, MENUITEM ); //12
		}
//======================================================================
	AddItem( "  .:Player:."				, Opt_Folder	, &cHacks::FolderHolder	, 2		, MENUFOLDER);//2
		if( player ) {
			AddItem( "Pick Up"			, Opt_on_off	, &cHacks::Activation	, 2		, MENUITEM);//1
			//AddItem( "Fly Hack"		, Opt_on_off	, &player2				, 2		, MENUITEM);//2
			AddItem( "Super Jump"		, Opt_on_off	, &cHacks::SuperJump	, 2		, MENUITEM);//3
			AddItem( "Hover"			, Opt_on_off	, &cHacks::Hover		, 2		, MENUITEM);//4
			AddItem( "Player Speed"		, Opt_Speed		, &cHacks::SpeedHack	, 4		, MENUITEM);//5
			//AddItem( "Fire Speed"		, Opt_on_off	, &player6				, 2		, MENUITEM);//6
			//AddItem( "OPK"			, Opt_Val		, &player7				, 18	, MENUITEM);//7
			//AddItem( "Telekill"		, Opt_on_off	, &player8				, 2		, MENUITEM);//8
			//AddItem( "Teleport"		, Opt_on_off	, &player9				, 2		, MENUITEM);//9
			//AddItem( "Super Bullets"	, Opt_on_off	, &cHacks::SuperBullets	, 2		, MENUITEM);//10
			//AddItem( "Glitcher"		, Opt_ghost		, &cHacks::Glitcher		, 6		, MENUITEM);//11
			//AddItem( "Glitcher"		, Opt_on_off	, &player12				, 2		, MENUITEM);//12
		}
//======================================================================
	AddItem( "  .:Removers:."			, Opt_Folder	, &cHacks::FolderHolder	, 2		, MENUFOLDER);//3
		if( remover ) {
			AddItem( "Anti-SS"			, Opt_on_off	, &cHacks::AntiSS		, 2		, MENUITEM);//1
			AddItem( "No Effect/Lag"	, Opt_on_off	, &cHacks::Unlagged		, 2		, MENUITEM);//2
			AddItem( "No Fog"			, Opt_on_off	, &cHacks::NoFog		, 2		, MENUITEM);//3
			AddItem( "No KB"			, Opt_on_off	, &cHacks::NoKnockBack	, 2		, MENUITEM);//4
			//AddItem( "No Recoil"		, Opt_on_off	, &cHacks::NoRecoil		, 2		, MENUITEM);//5
			//AddItem( "No Reload"		, Opt_on_off	, &cHacks::NoReload		, 2		, MENUITEM);//6
			AddItem( "No Smoke"			, Opt_on_off	, &cHacks::NoSmoke		, 2		, MENUITEM);//7
			AddItem( "No Spread"		, Opt_on_off	, &cHacks::NoSpread		, 2		, MENUITEM);//8
			AddItem( "No Cam. Sway"		, Opt_on_off	, &cHacks::NoWeapSway	, 2		, MENUITEM);//9
			//AddItem( "No Wep. Sway"	, Opt_on_off	, &cHacks::NoWeapSway	, 2		, MENUITEM);//10
			AddItem( "No Weapons"		, Opt_on_off	, &cHacks::NoWeap		, 2		, MENUITEM);//11
		}
//======================================================================
	AddItem( "  .:Misc:."				, Opt_Folder	, &cHacks::FolderHolder	, 2		, MENUFOLDER);//3
		if( misc ) {
			AddItem( "Refresh"			, Opt_on_off	, &cHacks::Refresh		, 2		, MENUITEM);//1
			AddItem( "Suicide"			, Opt_on_off	, &cHacks::Suicide		, 2		, MENUITEM);//2
			AddItem( "Show FPS"			, Opt_on_off	, &cHacks::ShowFPS		, 2		, MENUITEM);//3
			//AddItem( "Unlock Cursor"	, Opt_on_off	, &cHacks::Cursor		, 2		, MENUITEM);//4
			AddItem( "Scores"			, Opt_on_off	, &cHacks::Scores		, 2		, MENUITEM);//5
			AddItem( "Windowed"			, Opt_on_off	, &cHacks::Windowed		, 2		, MENUITEM);//6
			//AddItem( "Anti-Detect"	, Opt_on_off	, &cHacks::AntiDetect	, 2		, MENUITEM);//7
			AddItem( "Crash CA"			, Opt_on_off	, &cHacks::CrashCA		, 2		, MENUITEM);//8
		}
}
//======================================================================
//Set Hotkeys
void cMenu::Hotkey( void ) {
	while( true ) {
		if( FreezeMenu ) {
			Sleep(500);
			int KeyPressed = keys.NextKeyPress(10000);
			if( KeyPressed != keys.KeyEvents.None )	{
				Hotkeys[MENU[Mpos].maxvalue] = KeyPressed;
				HotkeyNames[MENU[Mpos].maxvalue] = keys.KeyName(KeyPressed);
			}
			MENU[Mpos].var = 0;
			FreezeMenu = false;
		}
		Sleep(100);
	}
}*/
//======================================================================
bool cMenu::MouseIsOver( int x, int y, int w, int h ) {
	GetCursorPos(&cPos);
    if( cPos.x >= x && cPos.x <= x + w && cPos.y >= y && cPos.y <= y + h ) { 
		return true; 
	} else { 
		return false; 
	} 
    return false;
}
//======================================================================
bool cMenu::MouseIsActive( int x, int y, int w, int h ) { 
    if( menu.MouseIsOver( x, y, w, h ) ) { 
		if( GetAsyncKeyState( VK_LBUTTON ) < 0 ) {
			return true; 
		} else {
			return false; 
		}
	} else { 
		return false; 
	} 
    return false;
}
//======================================================================
void cMenu::Render( LPDIRECT3DDEVICE9 pDevice, D3DCOLOR font, D3DCOLOR shadow, D3DCOLOR box ) {
	float SystemX = ( float )GetSystemMetrics( 0 );
	float SystemY = ( float )GetSystemMetrics( 1 );
	if( menu.MenuSt.isVisible ) {
		directx.DrawBox( pDevice, 0, 0, SystemX, 40, box, Black, Black ); // Top Bar
		directx.PrintShadowedText( SystemX - ( SystemX / 3 ), 13, font, shadow, "Welcome to the first release of Headlines!" );
		directx.DrawRAMBox( pDevice, SystemX - 110, 39, font, shadow, box, Black, Black );
		directx.PrintText( 5, 45, font, "Close Headline." );
		if( menu.MouseIsActive( 5, 45, 50, 15 ) ) {
			menu.MenuSt.isVisible = !menu.MenuSt.isVisible;
		}
	}
	menu.MenuSt.tabNumber = 0;
	menu.MenuSt.itemNumber = 1;
	menu.AddTab( pDevice, STRING_MENU_TAB_VISUALS,	PADDING						, 15, 5, 75, 30, font, shadow, D3DCOLOR_ARGB ( 230, 212, 208, 200 ) ); // 7 CHARS = 15 (V takes 1)
	menu.AddTab( pDevice, STRING_MENU_TAB_PLAYERS,	( PADDING * 2 ) + 75		, 14, 5, 75, 30, font, shadow, D3DCOLOR_ARGB ( 230, 212, 208, 200 ) ); // 7 CHARS = 14
	menu.AddTab( pDevice, STRING_MENU_TAB_REMOVALS, ( PADDING * 3 ) + (75 * 2)	, 7	, 5, 75, 30, font, shadow, D3DCOLOR_ARGB ( 230, 212, 208, 200 ) ); // 8 CHARS = 7
	menu.AddTab( pDevice, STRING_MENU_TAB_SETTINGS, ( PADDING * 4 ) + (75 * 3)	, 11, 5, 75, 30, font, shadow, D3DCOLOR_ARGB ( 230, 212, 208, 200 ) ); // 8 CHARS = 11

	menu.AddCheck( pDevice, STRING_MENU_CBOX_NOFOG		, 0, &cHacks::NoFog, font, shadow, box );
	menu.AddCheck( pDevice, STRING_MENU_CBOX_NOKNOCKBACK, 0, &cHacks::NoFog, font, shadow, box );
	menu.AddCheck( pDevice, STRING_MENU_CBOX_NORELOAD	, 0, &cHacks::NoFog, font, shadow, box );
	menu.AddCheck( pDevice, STRING_MENU_CBOX_NOSMOKE	, 0, &cHacks::NoFog, font, shadow, box );
	menu.AddCheck( pDevice, STRING_MENU_CBOX_NOSPREAD	, 0, &cHacks::NoFog, font, shadow, box );
	menu.AddCheck( pDevice, STRING_MENU_CBOX_NOSWAY		, 0, &cHacks::NoFog, font, shadow, box );
}
//======================================================================
void cMenu::AddCheck( LPDIRECT3DDEVICE9 pDevice, char* name, int tab, void (__thiscall cHacks::*var)(int), D3DCOLOR font, D3DCOLOR shadow, D3DCOLOR box ) {
	int iNum = menu.MenuSt.itemNumber;
	int w = 15, h = 15;
	int x = WinX[ tab ] + PADDING;
	int y = WinY[ tab ] + 25 + ( ( iNum - 1 ) * 20 );
	//menu.CheckBoxSt[ iNum ].name = name;
	if( menu.TabSt[ tab ][ 0 ].state ) {
		if( menu.MouseIsActive( x, y, w, h ) ) {
			menu.TabSt[ tab ][ iNum ].state = !menu.TabSt[ tab ][ iNum ].state ;
			if( menu.TabSt[ tab ][ iNum ].state ) { ((hacks).*(var))(1); } else { ((hacks).*(var))(0); }
			Sleep( 150 );
		}
		if( menu.TabSt[ tab ][ iNum ].state ) {
			//menu.CheckBoxSt[ iNum ].isActive = true;
			directx.DrawBox( pDevice, x, y, w, h, LimeGreen, WIN2KBORDER, White );
		} else {
			//menu.CheckBoxSt[ iNum ].isActive = false;
			directx.DrawBox( pDevice, x, y, w, h, DarkOrange, White, WIN2KBORDER );
		}
		directx.PrintShadowedText( x + w + 5, y, font, shadow, name );
	}
	menu.MenuSt.itemNumber++;
}
//======================================================================
void cMenu::AddTab( LPDIRECT3DDEVICE9 pDevice, char* name, int x, int padding, int y, int w, int h, D3DCOLOR font, D3DCOLOR shadow, D3DCOLOR box ) {
	int tNum = menu.MenuSt.tabNumber;
	if( menu.MouseIsActive( x, y, w, h ) ) {
		menu.TabSt[ tNum ][ 0 ].state = !menu.TabSt[ tNum ][ 0 ].state;
		Sleep( 150 );
	}
	if( menu.TabSt[ tNum ][ 0 ].state ) {
		if( GetAsyncKeyState( VK_LBUTTON ) < 0 ) {
			GetCursorPos(&cPos);
			if( cPos.x > WinX[ tNum ] - 10 && cPos.x < WinX[ tNum ] + 150 && cPos.y > WinY[ tNum ] - 10 && cPos.y < WinY[ tNum ] + 20 ) {
				if( !isDragging[ tNum ] ) {
					OffSetX[ tNum ] = cPos.x - WinX[ tNum ];
					OffSetY[ tNum ] = cPos.y - WinY[ tNum ];
					isDragging[ tNum ] = true;
				}
			}
		} else {
			isDragging[ tNum ] = false;
		}
		if( isDragging[ tNum ] ) {
			 WinX[ tNum ] = cPos.x - OffSetX[ tNum ];
			 WinY[ tNum ] = cPos.y - OffSetY[ tNum ];
		}
		directx.DrawBox( pDevice, x, y, w, h, box, WIN2KBORDER, White );
		directx.DrawRGB( pDevice, WinX[ tNum ], WinY[ tNum ], 150, 20, WIN2KBLUE );
		directx.PrintText( WinX[ tNum ] + PADDING, WinY[ tNum ] + 2, White, name );
		directx.DrawBox( pDevice, WinX[ tNum ], WinY[ tNum ] + 20, 150, 200, box, White, White );
	} else {
		directx.DrawBox( pDevice, x, y, w, h, box, White, WIN2KBORDER );
	}
	directx.PrintShadowedText( x + padding, y + ( h / 4 ), font, shadow, name );
	menu.MenuSt.tabNumber++;
}

/*======================================================================
void cMenu::AddItem( char *txt, char **opt, void (__thiscall cHacks::*var)(int *), int maxvalue, int typ ) {
	MENU[Mmax].typ=typ;
	MENU[Mmax].txt=txt;
	MENU[Mmax].opt=opt;
	MENU[Mmax].var=var;
	MENU[Mmax].maxvalue=maxvalue;
	Mmax++;
	Mheight = (Mmax*FONTSIZE);
}
//======================================================================
int cMenu::GetMax( int vars ) {
	return MENU[vars].maxvalue;
}
//======================================================================
void cMenu::MenuShow( int x, int y, LPDIRECT3DDEVICE9 pDevice ) {
	directx.DrawBox( pDevice, x - 5, y - 32, 195, 23, D3DCOLOR_ARGB ( 205, 0, 0, 0 ), White, Grey );
	directx.PrintText( x + 6, y - 28, GreenYellow, "Headlines v1.0 Beta" );

	int i, val;
	DWORD Color;
	if( !Mvisible ) return;
	if( Mtitle[0] ) {
		directx.PrintText( x + Mxofs / 2, y, MCOLOR_TITLE, Mtitle );
		y += FONTSIZE;
	}
	for ( i = 0; i  <Mmax; i++ ) {
		//val=(MENU[i].var)?(*MENU[i].var):0;
		val = ( Vars[i] );
		if ( i == Mpos ) {
			Color = Red;
		} else if( MENU[i].typ == MENUFOLDER ) {
			Color = DarkOrange;
		} else if( MENU[i].typ == MENUTEXT || MENU[i].typ == MENUHOTKEY ) {
			Color = Snow;
		} else {
			Color = ( val ) ? Green : MCOLOR_INACTIVE;
		}
		directx.PrintText( x + 10, y, Color, MENU[i].txt );
		if ( MENU[i].opt ) {
			char Text[100];
			if ( MENU[i].typ == MENUTEXT ) {
				sprintf( Text, "%s", ( char * )MENU[i].opt );
			} else {
				sprintf( Text, "%s",( char * )MENU[i].opt[val] );
			}
			directx.PrintText( x + Mxofs + 10 + 1, y, Color, Text );
		}
		y += FONTSIZE;
	}
}
//======================================================================
//Menu Navigation Function
void cMenu::MenuNav( void ) {
	if( FreezeMenu )
		return;
	if( GetAsyncKeyState( VK_INSERT ) )	{
		Mvisible = ( !Mvisible );
		Sleep( 140 );
	}
	if ( GetAsyncKeyState( VK_HOME ) ) {
		//POINT cursor;
		//GetCursorPos(&cursor);
		//menux = cursor.x;
		//menuy = cursor.y;
	}
	if ( !Mvisible ) {
		return;
	}
	if( GetAsyncKeyState( VK_UP ) ) {
		do {
			Mpos--;
			if( Mpos < 0 )  Mpos = Mmax - 1;
		} while( MENU[Mpos].typ == MENUTEXT );		// skip textitems
		Sleep( 140 );
	} else if( GetAsyncKeyState( VK_DOWN ) ) {
		do {
			Mpos++;
		    if( Mpos == Mmax ) Mpos = 0;
		} while( MENU[Mpos].typ == MENUTEXT );		// skip textitems
		Sleep( 140 );
	} else if( Vars[Mpos] ) {
		int dir = 0;
		if( GetAsyncKeyState( VK_LEFT ) && Vars[Mpos] > 0 ) {
			dir = -1;
		}
		if( GetAsyncKeyState( VK_RIGHT ) && Vars[Mpos] < (MENU[Mpos].maxvalue-1 ) ) {
			dir = 1;
		}
		if( dir ) {
			Vars[Mpos] += dir;
			if ( MENU[Mpos].typ == MENUFOLDER) Mmax=0;  // change on menufolder, force a rebuild
			//else firstRun = true;
		}
		Sleep( 100 );
	}
}
//======================================================================*/