/*
    Name: Detoursz
    Description: Detoursz is a library for function detouring
    Version: 1.0
    Author: Sinner & Zaki96
    Website: www.gamedefeat.com & www.cheatersutopia.com
    Credits: z0mbie (ADE32), LanceVorgin's CDetour (some ideas)
*/

#include "Detoursz.h"

cDetour* detour = NULL;

void* cDetour::memcpy_s( void* pvAddress, const void* pvBuffer, size_t stLen )
{
	MEMORY_BASIC_INFORMATION mbi;
	VirtualQuery( ( void* )pvAddress, &mbi, sizeof( mbi ) );
	VirtualProtect( mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &mbi.Protect );
	void* pvRetn = memcpy( ( void* )pvAddress, ( void* )pvBuffer, stLen );
	VirtualProtect( mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &mbi.Protect );
	FlushInstructionCache( GetCurrentProcess( ), ( void* )pvAddress, stLen );
	return pvRetn;
}


LPVOID cDetour::Create( LPVOID lpFuncOrig, LPVOID lpFuncDetour, int patchType, int detourLen )
{
    LPVOID lpMallocPtr = NULL;
    DWORD dwProt = NULL;
    PBYTE pbMallocPutr = NULL;
    PBYTE pbFuncOrig = (PBYTE)lpFuncOrig;
    PBYTE pbFuncDetour = (PBYTE)lpFuncDetour;
    PBYTE pbPatchBuf = NULL;
    int minDetLen = 0;
    int detLen = 0;

    // Get detour length
    if((minDetLen = GetDetourLen(patchType)) == 0)
            return NULL;

    else if((detLen = GetDetourLenAuto(pbFuncOrig, minDetLen)) < minDetLen)
            return NULL;

    // Alloc mem for the overwritten bytes
    if((lpMallocPtr = (LPVOID)malloc(detLen+JaMu32_SZ+SI_SSZ)) == NULL)
            return NULL;

    pbMallocPutr = (PBYTE)lpMallocPtr;

    // Enable writing to original
    VirtualProtect(lpFuncOrig, detLen, PAGE_READWRITE, &dwProt);
	

    // Write overwritten bytes to the malloc
    memcpy(lpMallocPtr, lpFuncOrig, detLen);
    pbMallocPutr += detLen;
    pbMallocPutr[0] = 0xE9;
    *(DWORD*)(pbMallocPutr+1) = (DWORD)((pbFuncOrig+detLen)-pbMallocPutr)-JaMu32_SZ;
    pbMallocPutr += JaMu32_SZ;
    pbMallocPutr[0] = SI_OOP_0;
    pbMallocPutr[1] = SI_OOP_1;
    pbMallocPutr[2] = SI_OOP_2;

    // Create a buffer to prepare the detour bytes
    pbPatchBuf = new BYTE[detLen];
    memset(pbPatchBuf, 0x90, detLen);

    switch(patchType)
    {
        case DETOUR_TYPE_CLC_JNC:
                pbPatchBuf[0] = 0xF8;
                pbPatchBuf[1] = 0x0F;
                pbPatchBuf[2] = 0x83;
                *(DWORD*)&pbPatchBuf[3] = (DWORD)(pbFuncDetour - pbFuncOrig) - 7;
                break;
        
        default:
                return NULL;
    }

    // Write the detour
    for(int i=0; i<detLen; i++)
            pbFuncOrig[i] = pbPatchBuf[i];

    delete [] pbPatchBuf;

    // Reset original mem flags
    VirtualProtect( lpFuncOrig, detLen, dwProt, &dwOldProt );

    return lpMallocPtr;
}

BOOL cDetour::Remove( LPVOID lpDetourCreatePtr )
{
    PBYTE pbMallocPutr = NULL;
    DWORD dwFuncOrig = NULL;
    DWORD dwProt = NULL;
    int i=0;

    if((pbMallocPutr = (PBYTE)lpDetourCreatePtr) == NULL)
            return FALSE;

	// Find the orig jmp32 opcode sig
    for(i=0; i<=DETOUR_MAX_SRCH_OPLEN; i++)
    {
        if(pbMallocPutr[i] == SI_OOP_0 //ini juga
                && pbMallocPutr[i+1] == SI_OOP_1//<-------- liat ini jg
                && pbMallocPutr[i+2] == SI_OOP_2)///ini juga
                break;

        if(i == DETOUR_MAX_SRCH_OPLEN)
                return FALSE;
    }

    // Write the overwritten bytes back to the original
   
    memcpy((LPVOID)dwFuncOrig, lpDetourCreatePtr, (i-JaMu32_SZ));
    VirtualProtect((LPVOID)dwFuncOrig, (i-JaMu32_SZ), dwProt, &dwOldProt);

    // Memory cleanup
    free(lpDetourCreatePtr);

    return TRUE;
}

int cDetour::GetDetourLen( int patchType )
{
    switch(patchType)
    {
        case DETOUR_TYPE_CLC_JNC:
                return 7;
        default:
                return 0;
    }
}

int cDetour::GetDetourLenAuto( PBYTE &pbFuncOrig, int minDetLen )
{
    int len = 0;
    PBYTE pbCurOp = pbFuncOrig;

    while(len < minDetLen)
    {
        int i = oplen(pbCurOp);
        
        if(i == 0 || i == -1)
                return 0;

        if(len > DETOUR_MAX_SRCH_OPLEN)
                return 0;

        len += i;
        pbCurOp += i;
    }

    return len;
}

bool cDetour::bDataCompare( const BYTE* pData, const BYTE* bMask, const char* szMask ) 
{ 
    for( ;*szMask;++szMask,++pData,++bMask ) 
        if( *szMask=='x' && *pData!=*bMask )  
            return false; 
    return ( *szMask ) == NULL; 
} 

// Thank You d0m1n1k
DWORD cDetour::FindPattern( DWORD dwAddress, DWORD dwLen,BYTE *bMask, char * szMask ) 
{ 
    for( DWORD i=0; i < dwLen; i++ ) 
		if( detour->bDataCompare( ( BYTE* )( dwAddress + i ), bMask, szMask) ) 
            return ( DWORD )( dwAddress+i ); 
     
    return 0; 
}