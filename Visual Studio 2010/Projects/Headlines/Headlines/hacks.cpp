/*******************************************************/
/* Solify's -> CA Base D3D Menu Selection
/* WE11ington -> Disponibilizou Para Combat Arms Brasil
/* Elinson/Turbulence -> Pequenos ajustes d/c etc na V3
/*******************************************************/

#include "files.h"
#include "Menu.h"
#include "Hook.h"

//////////////////////////////////
#define DeviceGame      0x0090BF60 //
#define LTClientEXE     0x00485F60 //
#define LTClientDLL     0x3777BCB0 // 
#define GameStatus      0x3778CC48 //
#define EspName1        0x372DB790 //Não está sendo usado
#define EspName2        0x372DB80D //Não está sendo usado
#define NoRecoil        0x3737F5FC //Não está sendo usado
//////////////////////////////////

//Menu
CHAR MenuTitle[25] = { "Menu Selection V3" }; // Titulo do hack aqui, Menu Title.
CHAR Timestruct[25] = { "hh':'mm':'ss tt" }; // Estrutura Relogio.
CHAR TimeString[25];
INT MenuSelection;
BOOL Menu = TRUE;
BOOL bFont;

//Hack Variables
INT FPS;
INT Cross;

INT bFPS;

INT quantdehacks = 2; // Quantidade de hacks que tem na base, deve mudar sempre o valor ao adicionar ou retirar alguma função.

void ComandoPush(const char* cmd)
{
	_asm
	{
	PUSH cmd
	MOV EAX, LTClientEXE
	CALL EAX
	ADD ESP, 0x4
	}
}

HRESULT WINAPI hkReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS *a)
{
	Directx_Font->OnLostDevice();

	HRESULT hTorna = oReset(pDevice, a);

	if(SUCCEEDED(hTorna))
		Directx_Font->OnResetDevice();

	return hTorna;
}

HRESULT WINAPI hkPresent(LPDIRECT3DDEVICE9 pDevice, CONST RECT *a, CONST RECT *b, HWND c, CONST RGNDATA *d)
{
	if(Directx_Font) {
		Directx_Font->Release();
		Directx_Font = NULL;
		bFont = FALSE;
	}

	if(!bFont) {
		D3DXCreateFont(pDevice, 14, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &Directx_Font);
		bFont = TRUE;
	}

	if(GetAsyncKeyState(VK_INSERT)&1) Menu = !Menu;	

	if(Menu && Directx_Font) {
		pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
		GetTimeFormat(NULL, NULL, NULL, NULL, Timestruct, 15);

		DrawBox(pDevice, 20, 25, 35, 162, Green, Black);//Draw box do titulo.		
		DrawText(pDevice, 30, 35, Yellow, MenuTitle);// Titulo do hack. MenuTitle declaração, então deve mudar la em cima.
		sprintf_s(TimeString, "%s", Timestruct);// Relogio.
		DrawText(pDevice, 130, 35, Yellow, TimeString);// Texto do Relogio.	
		DrawBox(pDevice, 20, 70, 50, 162, Green, Black);//Draw Box Principal //Cada vez que for adicionar uma nova função aumente o INT h (50) em 20 em 20 por exemplo, 50 + 20 = 70, 70 + 20 = 90, Espero que intenda.

		DrawText(pDevice, 30, 80, White, "Show FPS");
		if(FPS == 1) DrawText(pDevice, 150, 80, Green, "ON");
		if(FPS == 0) DrawText(pDevice, 150, 80,   Red, "OFF");

		DrawText(pDevice, 30, 100, White, "CrossHair");
		if(Cross == 1) DrawText(pDevice, 150, 100, Green, "ON");
		if(Cross == 0) DrawText(pDevice, 150, 100,   Red, "OFF");

		//DrawText(pDevice, 30, 60, White, "Nome da Função");
		//if(VariaveldaFunção == 1) DrawText(pDevice, 150, INT Y (Valor de cima +20)120, Green, "[On]");
		//if(VariaveldaFunção == 0) DrawText(pDevice, 150, INT Y (Valor de cima +20)120,   Red, "[Off]");
		//Cada função que for adicionar Sempre aumente a INT Y de cada uma em 20 para ficar ajustado. Espero que intenda.
		
		if(GetAsyncKeyState(VK_UP)&1) {
			MenuSelection--;
			if(MenuSelection < 0) MenuSelection = quantdehacks - 1;
		}

		if(GetAsyncKeyState(VK_DOWN)&1) {
			MenuSelection++;
			if(MenuSelection > quantdehacks - 1) MenuSelection = 0;
		}

		if(GetAsyncKeyState(VK_RIGHT)&1) {
			switch(MenuSelection) {
				case 0:
					FPS++; if(FPS > 1) FPS = 1; break;// case do FPS.
				case 1:
					Cross++; if(Cross > 1) Cross =1; break;// case do CrossHair.
				//case 2:
					//Variavel++; if(Variavel > 1) Variavel =1; break;// Sempre adicionar um novo a cada nova função adicionada.
				default:
					break;
			}
		}

		if(GetAsyncKeyState(VK_LEFT)&1) {
			switch(MenuSelection) {
				case 0:
					FPS--; if(FPS < 0) FPS = 0; break;
				case 1:
					Cross--; if(Cross <0) Cross = 0; break;
				//case 2:
					//Variavel--; if(Variavel > 0) Variavel =0; break;// Sempre adicionar um novo a cada nova função adicionada.
				default:
					break;
			}
		}

		for(INT x = 0; x < quantdehacks + 1; x++) {
			if(MenuSelection == x) 
				CurrentOption(pDevice, 25, 80 + 20 * x, 15, 150, Cyan);// Opção de seleção/Current Option.
		}
	}

	if(Cross) CrossHair(pDevice, Red);

	if(FPS && !bFPS) {
		ComandoPush("ShowFPS 1");
		bFPS = 1;
	} else if(!FPS && bFPS) {
		ComandoPush("ShowFPS 0");
		bFPS = 0;
	}

	return oPresent(pDevice, a, b, c, d);
}

DWORD WINAPI Hook(LPVOID lpArgs)
{
	DWORD dwD3D9 = 0;

	while(!dwD3D9) {
		Sleep(100);
		dwD3D9 = (DWORD)GetModuleHandle("d3d9.dll");
	}

	DWORD dwVTable[1] = {0};
	CreateDevice(dwVTable);

	oReset   = (tReset)  DetourCreate((PBYTE) dwVTable[0], (PBYTE) &hkReset, 5);
	oPresent = (tPresent)DetourCreate((PBYTE) dwVTable[1], (PBYTE) &hkPresent, 5);
	
	return FALSE;
}
