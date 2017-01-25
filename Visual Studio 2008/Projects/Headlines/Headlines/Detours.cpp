// ========================================================================
#include "Detours.h"
// ========================================================================
cDetour detour;
// ========================================================================
//NOP Function
void* cDetour::Memoria( void* pvAddress, const void* pvBuffer, size_t stLen ) { 
	MEMORY_BASIC_INFORMATION mbi;
	VirtualQuery( ( void* )pvAddress, &mbi, sizeof( mbi ) );
	VirtualProtect( mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &mbi.Protect );
	void* pvRetn = memcpy( ( void* )pvAddress, ( void* )pvBuffer, stLen );
	VirtualProtect( mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &mbi.Protect );
	FlushInstructionCache( GetCurrentProcess( ), ( void* )pvAddress, stLen );
	return pvRetn;
}
// ========================================================================
// FindPattern & DataCompare by dom1n1k
BOOL cDetour::DataCompare( BYTE* pData, BYTE* bMask, char * szMask ) {
    for( ; *szMask; ++szMask, ++pData, ++bMask )
        if( *szMask == 'x' && *pData != *bMask )
            return FALSE;
    return ( *szMask == NULL );
}
DWORD cDetour::FindPattern( DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask ) {
    for( DWORD i = 0; i < dwLen; i++ )
        if( detour.DataCompare( (BYTE*)( dwAddress + i ), bMask, szMask ) )
            return (DWORD)( dwAddress + i );
    return 0;
}
// ========================================================================
extern "C" int  __cdecl  mlde32( void *codeptr );
// ========================================================================
DWORD cDetour::CreateDetour( DWORD dwAdress, DWORD dwThread, DWORD dwType,DWORD dwSize ) {
	DWORD dwDetour,dwProtect,i;
	if( dwAdress && dwThread&&dwSize >= dwSize ) {
		dwDetour = ( DWORD )VirtualAlloc( 0, dwSize + dwSize, 0x1000, 0x40 );
		if( dwDetour&&VirtualProtect( ( VOID* )dwAdress, dwSize, 0x40, &dwProtect ) ) {
			for( i = 0; i < dwSize; i++ ) {
				*( BYTE* )( dwDetour + i ) = *( BYTE* )( dwAdress + i );
			}
			switch( dwType ) {
			    case 1: {
				    *( BYTE* )( dwDetour + dwSize + 0 ) = 0xE9;
				    *( DWORD* )( dwDetour + dwSize + 1 ) = ( dwAdress - dwDetour - dwSize );
						*(BYTE*)(dwAdress+0)=0xE9;
				    *( DWORD* )( dwAdress + 1 ) = ( dwThread - dwAdress - dwSize );
				}
				break;
				case 2: {
				    *( BYTE* )( dwDetour + dwSize + 0 ) = 0xB8;
				    *( DWORD* )( dwDetour + dwSize + 1 ) = ( dwAdress + dwSize );
				    *( WORD* )( dwDetour + dwSize + 5 ) = 0xE0FF; 
				    *( BYTE* )( dwAdress + 0 ) = 0xB8;            
				    *( DWORD* )( dwAdress + 1 ) = ( dwThread );
				    *( WORD* )( dwAdress + 5 ) = 0xE0FF; 
				}
				break;
				case 3: {
				    *( BYTE* )( dwDetour + dwSize + 0 ) = 0x68;
				    *( DWORD* )( dwDetour + dwSize + 1 ) =( dwAdress + dwSize );
				    *( WORD* )( dwDetour + dwSize + 5 ) = 0xC3; 
				    *( BYTE* )( dwAdress + 0 ) = 0x68;            
				    *( DWORD* )( dwAdress + 1 ) = ( dwThread );
				    *( WORD* )( dwAdress + 5 ) = 0xC3; 
				}
				break;
			}
			VirtualProtect( ( VOID* )dwAdress, dwSize,dwProtect, &dwProtect );
			VirtualProtect( ( VOID* )dwDetour, dwSize + dwSize, 0x20, &dwProtect );
			return dwDetour;
		}
	}
	Sleep(10);
	return(0);
}
// ========================================================================
void cDetour::UnlinkModule( HINSTANCE hDll ) {
	DWORD dwPEB_LDR_DATA = 0;
	_asm {
	  pushad;
	  pushfd;
	  mov eax, fs:[30h]             
	  mov eax, [eax+0Ch]               
	  mov dwPEB_LDR_DATA, eax 

	  InLoadOrderModuleList:
	   mov esi, [eax+0Ch]      
	   mov edx, [eax+10h]      

	  LoopInLoadOrderModuleList: 
		  lodsd           
	   mov esi, eax 
	   mov ecx, [eax+18h]  
	   cmp ecx, hDll 
	   jne SkipA   
		  mov ebx, [eax]   
		  mov ecx, [eax+4]  
		  mov [ecx], ebx    
		  mov [ebx+4], ecx   
	   jmp InMemoryOrderModuleList 

	  SkipA:
	   cmp edx, esi     
	   jne LoopInLoadOrderModuleList

	  InMemoryOrderModuleList:
	   mov eax, dwPEB_LDR_DATA
	   mov esi, [eax+14h]
	   mov edx, [eax+18h]

	  LoopInMemoryOrderModuleList: 
	   lodsd
	   mov esi, eax
	   mov ecx, [eax+10h]
	   cmp ecx, hDll
	   jne SkipB
	   mov ebx, [eax] 
	   mov ecx, [eax+4]
	   mov [ecx], ebx
	   mov [ebx+4], ecx
	   jmp InInitializationOrderModuleList

	  SkipB:
	   cmp edx, esi
	   jne LoopInMemoryOrderModuleList

	  InInitializationOrderModuleList:
	   mov eax, dwPEB_LDR_DATA
	   mov esi, [eax+1Ch]   
	   mov edx, [eax+20h]   

	  LoopInInitializationOrderModuleList: 
	   lodsd
	   mov esi, eax  
	   mov ecx, [eax+08h]
	   cmp ecx, hDll  
	   jne SkipC
	   mov ebx, [eax] 
	   mov ecx, [eax+4]
	   mov [ecx], ebx
	   mov [ebx+4], ecx
	   jmp Finished

	  SkipC:
	   cmp edx, esi
	   jne LoopInInitializationOrderModuleList

	  Finished:
	   popfd;
	   popad;
	}
}
// ========================================================================
void cDetour::EraseHeaders( HINSTANCE hModule ) {
	PIMAGE_DOS_HEADER pDoH; 
	PIMAGE_NT_HEADERS pNtH;
	DWORD i, ersize, protect;
	if( !hModule ) return;
	pDoH = (PIMAGE_DOS_HEADER)( hModule);
	pNtH = ( PIMAGE_NT_HEADERS )( ( LONG )hModule + ( ( PIMAGE_DOS_HEADER )hModule )->e_lfanew );
	ersize = sizeof( IMAGE_DOS_HEADER );
	if( VirtualProtect( pDoH, ersize, PAGE_READWRITE, &protect ) ) {
		for( i = 0; i < ersize; i++ )
			*(BYTE*)((BYTE*)pDoH + i) = 0;
	}
	ersize = sizeof(IMAGE_NT_HEADERS);
	if( pNtH && VirtualProtect( pNtH, ersize, PAGE_READWRITE, &protect ) ) {
		for( i=0; i < ersize; i++ )
			*(BYTE*)((BYTE*)pNtH + i) = 0;
	}
	return;
}
// ========================================================================
DWORD cDetour::GetCodeSize( const char* szModuleName ) {
	HMODULE hModule = GetModuleHandle( szModuleName );

	if ( !hModule )
		 return NULL;

	PIMAGE_DOS_HEADER pDosHeader = PIMAGE_DOS_HEADER( hModule );

	if( !pDosHeader )
		return NULL;

	PIMAGE_NT_HEADERS pNTHeader = PIMAGE_NT_HEADERS( (LONG)hModule + pDosHeader->e_lfanew );

	if( !pNTHeader )
		return NULL;

	PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pNTHeader->OptionalHeader;

	if( !pOptionalHeader )
		return NULL;

	return pOptionalHeader->SizeOfCode;
}