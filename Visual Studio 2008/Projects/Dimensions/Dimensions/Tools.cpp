//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								INCLUDES							  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Tools.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
cTools* tools = NULL;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void __cdecl cTools::RunConsoleCommand( const char* cCommand )
{
	//(*(int (*)(const char *)) (*((int *) ADDR_LTCLIENT) + 0x208))(cCommand);
	void* address = ( void* ) ADDR_CONSOLEUNWRAPPED;

	__asm
	{
		Push cCommand
		call address
		add esp, 0x4
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cTools::Memoria( void* pvAddress, void* pvBuffer, size_t len )
{
	if( *(BYTE*)pvAddress == *(BYTE*)pvBuffer )
		return;

	memcpy( ( void* )pvAddress, ( void* )pvBuffer, len );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							DETOUR FUNCTION							  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Thank You Azorbix
//DWORD cTools::DetourCreate( DWORD SrcVA, DWORD DstVA, DWORD Size )
//{
//    DWORD DetourVA, dwProtect, i;
//
//	#define SIZEOF_JMP_REL  5
//
//    if ( SrcVA && DstVA && Size >= SIZEOF_JMP_REL )
//    {
//        DetourVA = (DWORD) VirtualAlloc( 
//            NULL, Size + SIZEOF_JMP_REL, 
//            MEM_COMMIT, PAGE_EXECUTE_READWRITE );
//
//        if ( DetourVA && VirtualProtect( (VOID*)SrcVA, Size, PAGE_EXECUTE_READWRITE, &dwProtect ) )
//        {
//            for ( i=0; i < Size; i++ ) {
//                *(BYTE*)( DetourVA + i ) = *(BYTE*)( SrcVA + i );
//            }
//            
//            *(BYTE*)( DetourVA + Size + 0 ) = 0xE9;
//            *(DWORD*)( DetourVA + Size + 1 ) = ( SrcVA - DetourVA - SIZEOF_JMP_REL );
//
//                    *(BYTE*)( SrcVA + 0 ) = 0xE9;
//            *(DWORD*)( SrcVA + 1 ) = ( DstVA - SrcVA - SIZEOF_JMP_REL );
//
//            VirtualProtect( (VOID*)SrcVA, Size, dwProtect, &dwProtect );
//
//            VirtualProtect( (VOID*)DetourVA, Size + 
//                SIZEOF_JMP_REL, PAGE_EXECUTE_READ, &dwProtect );
//
//            return DetourVA;
//        }
//    }
//    return (0);
//}
void *cTools::DetourCreate( BYTE *src, const BYTE *dst, const int len )
{
	BYTE *jmp = ( BYTE* )malloc( len+5 );
	DWORD dwback;
	VirtualProtect( src, len, PAGE_READWRITE, &dwback );
	memcpy( jmp, src, len ); jmp += len;
	jmp[0] = 0xE9;
	*( DWORD* )( jmp+1 ) = ( DWORD )( src+len - jmp ) - 5;
	src[0] = 0xE9;
	*( DWORD* )( src+1 ) = ( DWORD )( dst - src ) - 5;
	VirtualProtect( src, len, dwback, &dwback );
	return ( jmp-len );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++