#include "Menu.h"
#include "Hacks.h"

cMenu* menu = NULL;
cHacks* hacks = NULL;
cGroup group;
cHair xhair;

bool mShow = false;

void cMenu::Render( LPDIRECT3DDEVICE9 pDevice )
{
	CreateGUI(pDevice);
}
																						
bool cMenu::MouseIsOver( int x, int y, int w, int h )
{ 
    bool bover; 
    if(Cur.x >= x && Cur.x <= x + w && Cur.y >= y && Cur.y <= y + h)
	{ 
		bover = true; 
	}else{ 
		bover = false; 
	} 
    return bover;
}

void cMenu::InitializeMenu() //Initializes all the variables for the menu
{
	X=100;//X Start of the Menu
	Y=150;//Y Start of the Menu
	Width=180;//Dont change this
	I_OFS=15;//Item space from X
	G_OFS=5;//Group space from X
	S_OFS=(Width/2)+70;//State space from X
	I_SPC=16;//Size of each Menuitem
}

void cMenu::CreateGUI( LPDIRECT3DDEVICE9 pDevice )
{
	GetCursorPos( &Cur );//X and Y of the curser
	ScreenToClient( GetForegroundWindow(), &Cur );
	InitializeMenu();

	if(GetAsyncKeyState(VK_INSERT)&1) mShow=(!mShow); // Checks when Insert is pressed..If pressed menu will show
	if(mShow){

		NO=0;
		Group("Hacks",			"|",			&group.Visual					); //This is the group
			Item("Crosshair",	"Off|Red|Blue", &xhair.cross,  group.Visual, 1	);
			Item("Test",		"Off|On",		&xhair.test1,  group.Visual, 1	);


		Group("Testing","|",&group.Weapon);//same
			Item("test",		"Off|On",		&xhair.test2,	group.Weapon, 1 );
			Item("Test",		"Off|On",		&xhair.test3,	group.Weapon, 1 );
		
		//Render the Menu
		for(int no=0; no<NO; no++)
		{	
			RECT rec1 = { X+G_OFS, MC_ITEMY(no)+2, 0, 0};
			RECT rec2 = { X+I_OFS, MC_ITEMY(no)+2, 0, 0};
			RECT rec3 = { X+S_OFS, MC_ITEMY(no)+2, 0, 0};
			D3DCOLOR text;
			D3DCOLOR text2;
			text=(*(items[no].val)>0)?C_ON:C_OFF;
			text2=(*(items[no].val)>0)?C_ON2:C_OFF2;

			if(items[no].type==T_CAT)
			{
				text=C_CAT;
			}
			if(Cur.x>X && Cur.x<(X+Width) && Cur.y>MC_ITEMY(no) && Cur.y<MC_ITEMY(no)+I_SPC)
			{
				directx->DrawBorder( pDevice, X + 1, MC_ITEMY( no ) + 2, Width + 10, 14, Black, Black );
			}
			if(items[no].type==T_CAT)
			{
				directx->pFont->DrawTextA(NULL,items[no].title,-1,&rec1,DT_NOCLIP,text);
			}else{
				directx->pFont->DrawTextA(NULL,items[no].title,-1,&rec2,DT_NOCLIP,text);
			}

			directx->pFont->DrawTextA(NULL,items[no].state,-1,&rec3,DT_LEFT|DT_NOCLIP,text2);

		}

		int mno=999;

		if(MouseIsOver(X, Y, Width, MC_ITEMY(NO)))
		{
			mno = ((Cur.y-T_SPC)>Y)?((Cur.y - Y - T_SPC - (T_SPC/2)) / I_SPC):(999);
		}

		//If Right Mousebutton is klicked once..
		if(mno!=999 && GetAsyncKeyState(VK_RBUTTON)&1 && (*items[mno].val)>0)
		{
			(*items[mno].val)-=1;
		}else{mousefix_R}

		//if Left Mousebutton is klicked once..
		if(mno!=999 && GetAsyncKeyState(VK_LBUTTON)&1 && (*items[mno].val)<(items[mno].max-1))
		{
			(*items[mno].val)+=1;
		}else{mousefix_L}

		if(Current>NO)Current=NO-1;
	}
}

void cMenu::additem(char *title, char *states,int type, int *var, int show, int when)
{
	if(show==when)
	{
		strcpy(items[NO].title,title);
		getfield(states,items[NO].state,*var+1);
		items[NO].type=type;
		items[NO].max=nofields(states);
		items[NO].val=var;
		NO++;
	}

}

void cMenu::Group(char *title, char *states, int *var)
{
	additem(title,states,T_CAT,var,0,0);
}

void cMenu::Item(char *title, char *states,int *var,int show,int when)
{
	additem(title,states,T_ITEM,var,show,when);
}

int cMenu::nofields(char *str)
{
	char *ptr;
	int  no;
	for(no=1; (ptr=strchr(str,(char)'|'))!=NULL; no++)str=ptr+1;
	return no;
}

void cMenu::getfield(char *str,char *dst,int no)
{
	char *ptr;		
	int  i;
	for(i=1; (ptr=strchr(str,(char)'|'))!=NULL ; i++) 
	{
		if(i==no) break;
		str=ptr+1;
	}
	if(ptr)
	{
		i=(int)(ptr-str);
		strncpy(dst,str,i);
		dst[i]=0;
	}
	else
		strcpy(dst,str);
}

void cHacks::RenderHacks( LPDIRECT3DDEVICE9 pDevice )
{
	switch( xhair.cross )
	{
	case 1:
		directx->DrawCrosshair( pDevice, 25, 1, Red );
		break;
	case 2:
		directx->DrawCrosshair( pDevice, 25, 1, Red );
		break;
	}
}