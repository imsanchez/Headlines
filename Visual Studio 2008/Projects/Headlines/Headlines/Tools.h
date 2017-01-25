// ========================================================================
#ifndef __TOOLS_H__
#define __TOOLS_H__
// ========================================================================
#pragma once
// ========================================================================
template <int XORSTART, int BUFLEN, int XREFKILLER>

class XorStr
{
private: 
	XorStr();
public: 
	char s[ BUFLEN ];

	XorStr( const char * xs );

	~XorStr()
	{
		for ( int i = 0; i < BUFLEN; i++ ) s[ i ]=0; 
	}
};

template <int XORSTART, int BUFLEN, int XREFKILLER>
XorStr<XORSTART,BUFLEN,XREFKILLER>::XorStr( const char * xs )
{
	int xvalue = XORSTART;
	int i = 0;

	for ( ; i < ( BUFLEN - 1 ); i++ ) 
	{
		s[ i ] = xs[ i - XREFKILLER ] ^ xvalue;
		xvalue += 1;
		xvalue %= 256;
	}

	s[ BUFLEN - 1 ] = 0;
}
// ========================================================================
class cTools{
	public:
		void __cdecl WriteLog( char *file,  const char *fmt );
		void __cdecl WriteLogX( char *file,  const char *fmt, ... );
		void __cdecl ClearLog( char *file, ... );
	private:
		ofstream ofile;
};
// ========================================================================
extern class cTools tools;
// ========================================================================
#endif
// ========================================================================