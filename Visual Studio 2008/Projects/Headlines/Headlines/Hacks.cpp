// ========================================================================
#include "Hacks.h"
#include "Detours.h"
// ========================================================================
cHacks hacks;
// ========================================================================
//int refresh = 0;
//DWORD ltclientexe;
// ========================================================================
void cHacks::Render( LPDIRECT3DDEVICE9 pDevice ) {
	//DWORD dwEngineEntryPoint = ( DWORD )GetModuleHandleA( STRING_ENGINEDOTEXE );
	//DWORD dwCShellEntryPoint = ( DWORD )GetModuleHandleA( STRING_CSHELLDOTDLL );
	//DWORD dwEngineCodeSize = detour.GetCodeSize( STRING_ENGINEDOTEXE );

	//DWORD dwLTClientEXE = detour.FindPattern( dwEngineEntryPoint, dwEngineCodeSize, ( BYTE* )"\xC7\x5\x00\x00\x00\x00\x00\x00\x00\x00\xC7\x5\x00\x00\x00\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x00\x68\x00\x00\x00\x00\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x59\xC3\xCC\xCC\xCC\xCC\x8B\x44\x24\x00", "xx????????xx????????x????xx?x????x????x????xxxxxxxxxxxxx????x????xxxxxxxxx" );
	//ltclientexe = ( DWORD )dwLTClientEXE + 0x47;
	//tools.WriteLogX( STRING_LOG_PATH, "ConsoleUnWrapped or LTClientEXE: [ 0x%x ]", ltclientexe );
}

void __stdcall cHacks::RunConsoleCommand( const char* cCommand ) {
	//static DWORD LTCLIENTEXE;
	//DWORD dwEngineEntryPoint = ( DWORD )GetModuleHandleA( STRING_ENGINEDOTEXE );
	//DWORD dwCShellEntryPoint = ( DWORD )GetModuleHandleA( STRING_CSHELLDOTDLL );
	//DWORD dwEngineCodeSize = detour.GetCodeSize( STRING_ENGINEDOTEXE );

	//DWORD dwLTClientEXE = detour.FindPattern( dwEngineEntryPoint, dwEngineCodeSize, ( BYTE* )"\xC7\x5\x00\x00\x00\x00\x00\x00\x00\x00\xC7\x5\x00\x00\x00\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x00\x68\x00\x00\x00\x00\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x59\xC3\xCC\xCC\xCC\xCC\x8B\x44\x24\x00", "xx????????xx????????x????xx?x????x????x????xxxxxxxxxxxxx????x????xxxxxxxxx" );
	//LTCLIENTEXE = ( DWORD )dwLTClientEXE + 0x47;

	//typedef void( __cdecl*RunConsoleCommandFn )( const char*, int& );
	//RunConsoleCommandFn RunConsoleCmd = ( RunConsoleCommandFn )LTCLIENTEXE;
	//int v4;
	//RunConsoleCmd( cCommand, v4 );
	//if( *( BYTE* )GCS == 1 ) {
		//__asm {
		//	pushad;
		//	push cCommand
		//	call ltclientexe
		//	add esp, 0x4
		//	popad;
		//}
	//}
}
//
//void cHacks::Crosshair( int type )
//{
//	//if( type == 1 ) //Cross-Hair (RED)
//	//	DirectX.DrawCrosshair( DirectX.pDevice, 25, 1, Red );
//
//	//if( type == 2 ) //Cross-Hair (BLUE)
//	//	DirectX.DrawCrosshair( DirectX.pDevice, 25, 1, Blue );
//
//	//if( type == 3 ) //Cross-Hair (GREEN)
//	//	DirectX.DrawCrosshair( DirectX.pDevice, 25, 1, Green );
//
//	//if( type == 4 ) //Cross-Hair (YELLOW)
//	//	DirectX.DrawCrosshair( DirectX.pDevice, 25, 1, Yellow );
//}
//
//void cHacks::SatChams( int active )
//{
//	if( active == 1 ) //Sat. Chams
//		hacks.RunConsoleCommand("+SkelModelStencil -1.0" );
//	else
//		hacks.RunConsoleCommand("+SkelModelStencil 0.0" );
//}
//
//void cHacks::Skeletons( int active )
//{
//	if( active == 1 ) //Skeletons
//		hacks.RunConsoleCommand("+ModelDebug_DrawSkeleton 1.0" );
//	else
//		hacks.RunConsoleCommand("+ModelDebug_DrawSkeleton 0.0" );
//}
//
//void cHacks::Tracers( int active )
//{
//	if( active == 1 ) //Tracers
//		hacks.RunConsoleCommand("+ShowFirePath 1" );
//	else
//		hacks.RunConsoleCommand("+ShowFirePath 0" );
//}
//
//void cHacks::Prediction( int active )
//{
//	if( active == 1 ) //Prediction
//		hacks.RunConsoleCommand("+Prediction 1" );
//	else
//		hacks.RunConsoleCommand("+Prediction 0" );
//}
//
//void cHacks::vJump( int setting )
//{
//	if( setting == 1 ) //Virtual Jump (UP)
//	{
//		hacks.RunConsoleCommand("+CamMaxPosYOffset 200.000000");
//		hacks.RunConsoleCommand("+DuckDownCamOffSet 1000.000000");
//	}
//	else if( setting == 2 ) //Virtual Jump (DOWN)
//	{
//		hacks.RunConsoleCommand("+CamMaxPosYOffset -1000.000000");
//		hacks.RunConsoleCommand("+DuckDownCamOffSet -13.000000");
//	}
//	else //No Virtual Jump
//	{
//		hacks.RunConsoleCommand("+CamMaxPosYOffset 200.000000");
//		hacks.RunConsoleCommand("+DuckDownCamOffSet -13.000000");
//	}
//}
//
//void cHacks::ModelMod( int setting )
//{
//	if( setting == 1 ) //Model Modifier (GLOW)
//		hacks.RunConsoleCommand("+ScreenGlowEnable 1" );
//	else
//		hacks.RunConsoleCommand("+ScreenGlowEnable 0" );
//
//	if( setting == 2 ) //Model Modifier (WIREFRAME)
//		hacks.RunConsoleCommand("+WireframeModels 1" );
//	else
//		hacks.RunConsoleCommand("+WireframeModels 0" );
//}
//
//void cHacks::Walls( int setting )
//{
//	//if( setting == 1 ) //Wall Modifier (BRIGHT)
//	//	hacks.RunConsoleCommand("+FullBright 1" );
//	//else
//	//	hacks.RunConsoleCommand("+FullBright 0" );
//
//	//if( setting == 2 ) //Wall Modifier (GLASS)
//	//	tool.Memoria((LPVOID)WALLS, "\x6A\x00", 2);
//	//else
//	//	tool.Memoria((LPVOID)WALLS, "\x6A\x01", 2);
//
//	//if( setting == 3 ) //Wall Modifier (WHITE)
//	//	hacks.RunConsoleCommand("+DrawFlat 1" );
//	//else
//	//	hacks.RunConsoleCommand("+DrawFlat 0" );
//
//	//if( setting == 4 ) //Wall Modifier (WIREFRAME)
//	//	hacks.RunConsoleCommand("+Wireframe 1" );
//	//else
//	//	hacks.RunConsoleCommand("+Wireframe 0" );
//}
//
//void cHacks::GhostMode( int active )
//{
//	if( active == 1 )
//		(*(long*)0x378228C4) = 4;
//	else
//		(*(long*)0x378228C4) = 1;
//}
//
//void cHacks::Activation( int active )
//{
//	if( active == 1 ) //Pick Up
//		hacks.RunConsoleCommand("+ActivationDistance 999999" );
//	else
//		hacks.RunConsoleCommand("+ActivationDistance 100" );
//}
//
//void cHacks::Fly( int active )
//{
//	if( active == 1 ) //Fly Hack
//		if(keys.KeyPressed(keys.KeyEvents.Space))
//			hacks.RunConsoleCommand("+PlayerGravity 800");
//		else
//			hacks.RunConsoleCommand("+PlayerGravity -800");
//}
//
//void cHacks::SuperJump( int active )
//{
//	if( active == 1 ) //Super Jump
//		hacks.RunConsoleCommand("+JumpVel 660.000000" );
//	else
//		hacks.RunConsoleCommand("+JumpVel 330.000000" );
//}
//
//void cHacks::Hover( int active )
//{
//	if( active == 1 ) //Hover (ON)
//	{
//		hacks.RunConsoleCommand("+Gravity 0");
//		hacks.RunConsoleCommand("+PlayerGravity 0");
//		hacks.RunConsoleCommand("+GravityOverrride 0");
//		hacks.RunConsoleCommand("+FallVelocity 0");
//	}
//	else
//	{
//		hacks.RunConsoleCommand("+Gravity -800");
//		hacks.RunConsoleCommand("+PlayerGravity -800");
//		hacks.RunConsoleCommand("+GravityOverrride 1");
//	}
//}
//
//void cHacks::SpeedHack( int speed )
//{
//	if( speed == 0 ) //Player Speed (NORMAL)
//	{
//		hacks.RunConsoleCommand("+BaseMoveAccel 3000.000000");
//		hacks.RunConsoleCommand("+StartAccel 500.000000");
//		hacks.RunConsoleCommand("+MaxAccel 3000.000000");
//		hacks.RunConsoleCommand("+AccelInc 6000.000000");
//		hacks.RunConsoleCommand("+WalkVel 70.000000");
//		hacks.RunConsoleCommand("+FRunVel 285.000000");
//		hacks.RunConsoleCommand("+BRunVel 285.000000");
//		hacks.RunConsoleCommand("+SRunVel 285.000000");
//		hacks.RunConsoleCommand("+DuckVel 50.000000");
//	}
//	
//	if( speed == 1 ) //Player Speed (FAST)
//	{
//		hacks.RunConsoleCommand("+BaseMoveAccel 2000.000000");
//		hacks.RunConsoleCommand("+StartAccel 2000.000000");
//		hacks.RunConsoleCommand("+MaxAccel 2000.000000");
//		hacks.RunConsoleCommand("+AccelInc 2000.000000");
//		hacks.RunConsoleCommand("+WalkVel 2000.000000");
//		hacks.RunConsoleCommand("+FRunVel 2000.000000");
//		hacks.RunConsoleCommand("+BRunVel 2000.000000");
//		hacks.RunConsoleCommand("+SRunVel 2000.000000");
//		hacks.RunConsoleCommand("+DuckVel 2000.000000");
//	}
//
//	if( speed == 2 ) //Player Speed (FASTER)
//	{
//		hacks.RunConsoleCommand("+BaseMoveAccel 4000.000000");
//		hacks.RunConsoleCommand("+StartAccel 4000.000000");
//		hacks.RunConsoleCommand("+MaxAccel 4000.000000");
//		hacks.RunConsoleCommand("+AccelInc 4000.000000");
//		hacks.RunConsoleCommand("+WalkVel 4000.000000");
//		hacks.RunConsoleCommand("+FRunVel 4000.000000");
//		hacks.RunConsoleCommand("+BRunVel 4000.000000");
//		hacks.RunConsoleCommand("+SRunVel 4000.000000");
//		hacks.RunConsoleCommand("+DuckVel 4000.000000");
//	}
//
//	if( speed == 3 ) //Player Speed (GLITCHER)
//	{
//		hacks.RunConsoleCommand("+BaseMoveAccel 90000.000000");
//		hacks.RunConsoleCommand("+StartAccel 90000.000000");
//		hacks.RunConsoleCommand("+MaxAccel 90000.000000");
//		hacks.RunConsoleCommand("+AccelInc 90000.000000");
//		hacks.RunConsoleCommand("+WalkVel 90000.000000");
//		hacks.RunConsoleCommand("+FRunVel 90000.000000");
//		hacks.RunConsoleCommand("+BRunVel 90000.000000");
//		hacks.RunConsoleCommand("+SRunVel 90000.000000");
//		hacks.RunConsoleCommand("+JumpVel 90000.000000");
//		hacks.RunConsoleCommand("+DuckVel 90000.000000");
//	}
//}
//
////void cHacks::SuperBullets( int active ) {
//	//if( active == 1 )
//		//tool.Memoria((LPVOID)SUPERBULLETS, "\x90\x90\x90", 3);
//	//else
//		//tool.Memoria((LPVOID)SUPERBULLETS, "\x0F\x94\xC0", 3);
////}
//
//void cHacks::AntiSS( int active )
//{
//	if( active == 1 ) //Anti-SS
//		hacks.RunConsoleCommand("+FlareBlindCamAngle 243" );
//	else
//		hacks.RunConsoleCommand("+FlareBlindCamAngle 0" );
//}
//
//void cHacks::Unlagged( int active )
//{
//	if( active == 1 ) //No Effect/Lag
//	{
//		hacks.RunConsoleCommand("+DynamicLight 0");
//		hacks.RunConsoleCommand("+EnableWeatherFX 0");
//		hacks.RunConsoleCommand("+MuzzleLight 0");
//		hacks.RunConsoleCommand("+CamDamage 0");
//		hacks.RunConsoleCommand("+SnowEnable 0");
//		hacks.RunConsoleCommand("+ModelApplySun 0");
//		hacks.RunConsoleCommand("+ClientFXDetailLevel 0");
//		hacks.RunConsoleCommand("+ModelShadow_Proj_Enable 0");
//		hacks.RunConsoleCommand("+DebrisFXLevel 0");
//		hacks.RunConsoleCommand("+ScatterEnable 0");
//		hacks.RunConsoleCommand("+modelshadow_proj_blurenable 0");
//		hacks.RunConsoleCommand("+DrawAllModelShadows 0");
//		hacks.RunConsoleCommand("+ModelShadow_Proj_MinColorComponent 0");
//		hacks.RunConsoleCommand("+ModelShadow_Proj_MaxProjDist 0");
//	}
//	else
//	{
//		hacks.RunConsoleCommand("+DynamicLight 1");
//		hacks.RunConsoleCommand("+EnableWeatherFX 1");
//		hacks.RunConsoleCommand("+MuzzleLight 1");
//		hacks.RunConsoleCommand("+CamDamage 1");
//		hacks.RunConsoleCommand("+SnowEnable 1");
//		hacks.RunConsoleCommand("+ModelApplySun 1");
//		hacks.RunConsoleCommand("+ClientFXDetailLevel 1");
//		hacks.RunConsoleCommand("+ModelShadow_Proj_Enable 1");
//		hacks.RunConsoleCommand("+DebrisFXLevel 1");
//		hacks.RunConsoleCommand("+ScatterEnable 1");
//		hacks.RunConsoleCommand("+modelshadow_proj_blurenable 1");
//		hacks.RunConsoleCommand("+DrawAllModelShadows 1");
//		hacks.RunConsoleCommand("+ModelShadow_Proj_MinColorComponent 1");
//		hacks.RunConsoleCommand("+ModelShadow_Proj_MaxProjDist 1");
//	}
//}

void cHacks::NoFog( int active ) {
	if( active == 1 ) {
		//tools.WriteLog( STRING_LOG_PATH, "No Fog Enabled.");
		hacks.RunConsoleCommand( STRING_NOFOG_ON );
	} else {
		//tools.WriteLog( STRING_LOG_PATH, "No Fog Disabled.");
		hacks.RunConsoleCommand( STRING_NOFOG_OFF );
	}
}
//
//void cHacks::NoKnockBack( int active )
//{
//	if( active == 1 ) //No KB
//		hacks.RunConsoleCommand("+KnockBack 0");
//	else
//		hacks.RunConsoleCommand("+KnockBack 1");
//}
//
//void cHacks::NoReloadd( int active )
//{
//	if( active == 1 ) //No KB
//		hacks.RunConsoleCommand("+KnockBack 0");
//	else
//		hacks.RunConsoleCommand("+KnockBack 1");
//}
//
//void cHacks::NoSmoke( int active )
//{
//	if( active == 1 ) //No Smoke
//		hacks.RunConsoleCommand("+DrawParticles 0");
//	else
//		hacks.RunConsoleCommand("+DrawParticles 1");
//}
//
//void cHacks::NoSpread( int active )
//{
//	if( active == 1 ) //No Spread
//	{
//		hacks.RunConsoleCommand("+PerturbRotationEffect  0.000000" ); 
//		hacks.RunConsoleCommand("+PerturbIncreaseSpeed 0.000000" ); 
//		hacks.RunConsoleCommand("+PerturbWalkPercent 0.000000" ); 
//		hacks.RunConsoleCommand("+PerturbFiringIncreaseSpeed 0.000000" );
//		hacks.RunConsoleCommand("+PerturbRecoil 0.000000" );
//		hacks.RunConsoleCommand("+FireMovePerturb 0.000000" );
//		hacks.RunConsoleCommand("+ZoomedFireMoveDuckPerturb 0.000000" );
//		hacks.RunConsoleCommand("+ZoomedFireMovePerturb 0.000000" );
//		hacks.RunConsoleCommand("+ZoomedFireDuckPerturb 0.000000" );
//	}
//	else
//	{
//		hacks.RunConsoleCommand("+PerturbRotationEffect 3.000000" );
//		hacks.RunConsoleCommand("+PerturbIncreaseSpeed 3.000000" );
//		hacks.RunConsoleCommand("+PerturbDecreaseSpeed 9.000000" );
//		hacks.RunConsoleCommand("+PerturbWalkPercent 0.500000" );
//		hacks.RunConsoleCommand("+PerturbRecoil 9.000000" );
//		hacks.RunConsoleCommand("+FireMovePerturb 9.000000" );
//		hacks.RunConsoleCommand("+ZoomedFireMoveDuckPerturb 9.000000" );
//		hacks.RunConsoleCommand("+ZoomedFireMovePerturb 9.000000" );
//		hacks.RunConsoleCommand("+ZoomedFireDuckPerturb 9.000000" );
//	}
//}
//
//void cHacks::NoWeapSway( int active )
//{
//	if( active == 1 ) //No Wep. Sway
//		hacks.RunConsoleCommand("+WeaponSway 0.000000");
//	else
//		hacks.RunConsoleCommand("+WeaponSway 1.000000");
//}
//
//void cHacks::NoWeap( int active )
//{
//	if( active == 1 )//No Weapons
//		hacks.RunConsoleCommand( "drawguns 0" );
//	else
//		hacks.RunConsoleCommand( "drawguns 1" );
//}
//
//void cHacks::Suicide( int active )
//{
//	if( active == 1 ) //Suicide
//		hacks.RunConsoleCommand("+FragSelf 1" );
//}
//
//void cHacks::ShowFPS( int active )
//{
//	if( active == 1 )
//		hacks.RunConsoleCommand( "ShowFps 1");
//	else
//		hacks.RunConsoleCommand( "ShowFps 0");
//}
//
//	//UNLOCK CURSOR GOES HERE
//
//void cHacks::Scores( int active )
//{
//	if( active == 1 )
//		hacks.RunConsoleCommand("+ShowPerformanceStatistics 1");
//	else
//		hacks.RunConsoleCommand("+ShowPerformanceStatistics 0");
//}
//
//void cHacks::Windowed( int active )
//{
//	if( active == 1 )
//		hacks.RunConsoleCommand("+Windowed 1");
//	else
//		hacks.RunConsoleCommand("+Windowed 0");
//}
//
//void cHacks::NoCameraSway( int active )
//{
//	if( active == 1 ) //No Cam. Sway
//	{
//		hacks.RunConsoleCommand("+CameraSwayXFreq 0.000000");
//		hacks.RunConsoleCommand("+CameraSwayYFreq 0.000000");
//	}
//	else
//	{
//		hacks.RunConsoleCommand("+CameraSwayXFreq 1.000000");
//		hacks.RunConsoleCommand("+CameraSwayYFreq 1.000000");
//	}
//}
//
////void cHacks::NoRecoil( int active ) {
//	//if( active == 1 ) {
//		//tool.Memoria((LPVOID) RECOIL1, "\x90\x90\x90", 3);
//		//tool.Memoria((LPVOID) RECOIL2, "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90",11);
//		//tool.Memoria((LPVOID) RECOIL3, "\x90\x90\x90\x90\x90\x90", 6);
//		//tool.Memoria((LPVOID) RECOIL4, "\x90\x90\x90", 3);
//	//} else {
//		//tool.Memoria((LPVOID) RECOIL1, "\xD8\x66\x54", 3);
//		//tool.Memoria((LPVOID) RECOIL2, "\xC7\x84\x24\x94\x00\x00\x00\x0F\x00\x00\x00",11);
//		//tool.Memoria((LPVOID) RECOIL3, "\xD9\x5E\x54\xD9\x46\x48", 6);
//		//tool.Memoria((LPVOID) RECOIL4, "\xD9\x5E\x48", 3);
//	//}
////}
//
//void cHacks::Refresh( int active )
//{
//	//refresh = 1;
//	//*active = 0;
//}
//
//void cHacks::CrashCA( int active )
//{
//	if( active ) {
//		FILE *fhandle = fopen("C:\\addys.txt", "w");
//		fprintf(fhandle, "[Librarys]\nEngine.exe:		0x%x\nClientFX.fxd:	0x%x\nCShell.dll:		0x%x\nEHSvc.dll:		0x%x\nd3d9.dll:		0x%x\n\n[Addresses]\n",
//			(DWORD)GetModuleHandleA("Engine.exe"),
//			(DWORD)GetModuleHandleA("ClientFX.fxd"),
//			(DWORD)GetModuleHandleA("CShell.dll"),
//			(DWORD)GetModuleHandleA("EHSvc.dll"),
//			(DWORD)GetModuleHandleA("d3d9.dll")
//			);
//		DWORD CShell = (DWORD)GetModuleHandleA("CShell.dll");
//		fprintf(fhandle, "D3D Device: %X\n", FindPattern((DWORD)GetModuleHandleA("d3d9.dll"), 0x128000, (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx"));
//		fprintf(fhandle, "Player Index: %X\n", FindPattern(CShell, 0x128000, (PBYTE)"\x8B\x41\x04\x85\xC0\x74\x18\x8B\x54\x24\x04\xEB\x03\x8D\x49\x00\x39\x50\x04\x74\x1A\x8B\x80", "xxxxxxxxxxxxxxxxxxxxxxx"));
//		fprintf(fhandle, "Super Bullets: %X\n", FindPattern(CShell, 0x128000, (PBYTE)"\x0F\x94\xC0\x5E", "xxxx"));
//		fclose(fhandle);
//		TerminateProcess(GetCurrentProcess(),0);
//		*active = 0;
//	}
//}
//
//void cHacks::FolderHolder(int menu)
//{
//	//Folder Holder for menus ;)
//}