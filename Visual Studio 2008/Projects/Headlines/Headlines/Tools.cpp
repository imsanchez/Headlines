// ========================================================================
#include "Tools.h"
// ========================================================================
cTools tools;
// ========================================================================
void __cdecl cTools::WriteLog( char *file,  const char *fmt ) {
 	tools.ofile.open( file , ios::app);
 	tools.ofile << fmt << endl;
 	tools.ofile.close();
 	return;
}
// ========================================================================
void __cdecl cTools::WriteLogX( char *file,  const char *fmt, ... ) {
 	tools.ofile.open( file , ios::app);
 	va_list va_alist;
 	char logbuf[256] = {0};
 	va_start( va_alist, fmt );
 	vsnprintf( logbuf + strlen( logbuf ), sizeof( logbuf ) - strlen( logbuf ), fmt, va_alist );
 	va_end( va_alist );
 	tools.ofile << logbuf << endl;
 	tools.ofile.close();
 	return;
}
// ========================================================================
void __cdecl cTools::ClearLog( char *file, ... ) {
	tools.ofile.open( file , ios::out | ios::trunc);
 	tools.ofile.close();
 	return;
}