// ========================================================================
#include "Keys.h"
// ========================================================================
cKeys keys;
// ========================================================================
bool cKeys::KeyPressed( int Key ) {
	if( GetAsyncKeyState( ( int )Key ) )
		return true;
	return false;
}
// ========================================================================
bool cKeys::isLetter( int Key ) {
	if( Key == keys.KeyEvents.A )
		return true;
	if( Key == keys.KeyEvents.B )
		return true;
	if( Key == keys.KeyEvents.C )
		return true;
	if( Key == keys.KeyEvents.D )
		return true;
	if( Key == keys.KeyEvents.E )
		return true;
	if( Key == keys.KeyEvents.F )
		return true;
	if( Key == keys.KeyEvents.G )
		return true;
	if( Key == keys.KeyEvents.H )
		return true;
	if( Key == keys.KeyEvents.I )
		return true;
	if( Key == keys.KeyEvents.J )
		return true;
	if( Key == keys.KeyEvents.K )
		return true;
	if( Key == keys.KeyEvents.L )
		return true;
	if( Key == keys.KeyEvents.M )
		return true;
	if( Key == keys.KeyEvents.N )
		return true;
	if( Key == keys.KeyEvents.O )
		return true;
	if( Key == keys.KeyEvents.P )
		return true;
	if( Key == keys.KeyEvents.Q )
		return true;
	if( Key == keys.KeyEvents.R )
		return true;
	if( Key == keys.KeyEvents.S )
		return true;
	if( Key == keys.KeyEvents.T )
		return true;
	if( Key == keys.KeyEvents.U )
		return true;
	if( Key == keys.KeyEvents.V )
		return true;
	if( Key == keys.KeyEvents.W )
		return true;
	if( Key == keys.KeyEvents.X )
		return true;
	if( Key == keys.KeyEvents.Y )
		return true;
	if( Key == keys.KeyEvents.Z )
		return true;
	return false;
}
// ========================================================================
char* cKeys::KeyName( int Key ) {
	if( Key == keys.KeyEvents.A )
		return KEY_A;
	if( Key == keys.KeyEvents.Add )
		return KEY_ADD;
	if( Key == keys.KeyEvents.Alt )
		return KEY_ALT;
	if( Key == keys.KeyEvents.B )
		return KEY_B;
	if( Key == keys.KeyEvents.BackSlash )
		return KEY_BACKSLASH;
	if( Key == keys.KeyEvents.Backspace )
		return KEY_BACKSPACE;
	if( Key == keys.KeyEvents.Break )
		return KEY_BREAK;
	if( Key == keys.KeyEvents.C )
		return KEY_C;
	if( Key == keys.KeyEvents.CapsLock )
		return KEY_CAPSLOCK;
	if( Key == keys.KeyEvents.Clear )
		return KEY_CLEAR;
	if( Key == keys.KeyEvents.CloseBracket )
		return KEY_CLOSEBRACKET;
	if( Key == keys.KeyEvents.Comma )
		return KEY_COMMA;
	if( Key == keys.KeyEvents.Ctrl )
		return KEY_CTRL;
	if( Key == keys.KeyEvents.D )
		return KEY_D;
	if( Key == keys.KeyEvents.Decimal )
		return KEY_DECIMAL;
	if( Key == keys.KeyEvents.Delete )
		return KEY_DELETE;
	if( Key == keys.KeyEvents.Divide )
		return KEY_DIVIDE;
	if( Key == keys.KeyEvents.Down )
		return KEY_DOWN;
	if( Key == keys.KeyEvents.E )
		return KEY_E;
	if( Key == keys.KeyEvents.Eight )
		return KEY_EIGHT;
	if( Key == keys.KeyEvents.End )
		return KEY_END;
	if( Key == keys.KeyEvents.Enter )
		return KEY_ENTER;
	if( Key == keys.KeyEvents.Equals )
		return KEY_EQUALS;
	if( Key == keys.KeyEvents.Esc )
		return KEY_ESC;
	if( Key == keys.KeyEvents.Execute )
		return KEY_EXEC;
	if( Key == keys.KeyEvents.F )
		return KEY_F;
	if( Key == keys.KeyEvents.F1 )
		return KEY_F1;
	if( Key == keys.KeyEvents.F10 )
		return KEY_F10;
	if( Key == keys.KeyEvents.F11 )
		return KEY_F11;
	if( Key == keys.KeyEvents.F12 )
		return KEY_F12;
	if( Key == keys.KeyEvents.F13 )
		return KEY_F13;
	if( Key == keys.KeyEvents.F14 )
		return KEY_F14;
	if( Key == keys.KeyEvents.F15 )
		return KEY_F15;
	if( Key == keys.KeyEvents.F16 )
		return KEY_F16;
	if( Key == keys.KeyEvents.F17 )
		return KEY_F17;
	if( Key == keys.KeyEvents.F18 )
		return KEY_F18;
	if( Key == keys.KeyEvents.F19 )
		return KEY_F19;
	if( Key == keys.KeyEvents.F2 )
		return KEY_F2;
	if( Key == keys.KeyEvents.F20 )
		return KEY_F20;
	if( Key == keys.KeyEvents.F21 )
		return KEY_F21;
	if( Key == keys.KeyEvents.F22 )
		return KEY_F22;
	if( Key == keys.KeyEvents.F23 )
		return KEY_F23;
	if( Key == keys.KeyEvents.F24 )
		return KEY_F24;
	if( Key == keys.KeyEvents.F3 )
		return KEY_F3;
	if( Key == keys.KeyEvents.F4 )
		return KEY_F4;
	if( Key == keys.KeyEvents.F5 )
		return KEY_F5;
	if( Key == keys.KeyEvents.F6 )
		return KEY_F6;
	if( Key == keys.KeyEvents.F7 )
		return KEY_F7;
	if( Key == keys.KeyEvents.F8 )
		return KEY_F8;
	if( Key == keys.KeyEvents.F9 )
		return KEY_F9;
	if( Key == keys.KeyEvents.Five )
		return KEY_FIVE;
	if( Key == keys.KeyEvents.ForwardSlash )
		return KEY_FORWARDSLASH;
	if( Key == keys.KeyEvents.Four )
		return KEY_FOUR;
	if( Key == keys.KeyEvents.G )
		return KEY_G;
	if( Key == keys.KeyEvents.H )
		return KEY_H;
	if( Key == keys.KeyEvents.I )
		return KEY_I;
	if( Key == keys.KeyEvents.Insert )
		return KEY_INSERT;
	if( Key == keys.KeyEvents.J )
		return KEY_J;
	if( Key == keys.KeyEvents.K )
		return KEY_K;
	if( Key == keys.KeyEvents.L )
		return KEY_L;
	if( Key == keys.KeyEvents.Left )
		return KEY_LEFT;
	if( Key == keys.KeyEvents.LeftAlt )
		return KEY_LEFTALT;
	if( Key == keys.KeyEvents.LeftControl )
		return KEY_LEFTCONTROL;
	if( Key == keys.KeyEvents.LeftMouse )
		return KEY_LEFTMOUSE;
	if( Key == keys.KeyEvents.LeftShift )
		return KEY_LEFTSHIFT;
	if( Key == keys.KeyEvents.M )
		return KEY_M;
	if( Key == keys.KeyEvents.MiddleMouse )
		return KEY_MIDDLEMOUSE;
	if( Key == keys.KeyEvents.Minus )
		return KEY_MINUS;
	if( Key == keys.KeyEvents.Multiply )
		return KEY_MULTIPLY;
	if( Key == keys.KeyEvents.N )
		return KEY_N;
	if( Key == keys.KeyEvents.Nine )
		return KEY_NINE;
	if( Key == keys.KeyEvents.NumLock )
		return KEY_NUMLOCK;
	if( Key == keys.KeyEvents.Numpad0 )
		return KEY_NUMPAD0;
	if( Key == keys.KeyEvents.Numpad1 )
		return KEY_NUMPAD1;
	if( Key == keys.KeyEvents.Numpad2 )
		return KEY_NUMPAD2;
	if( Key == keys.KeyEvents.Numpad3 )
		return KEY_NUMPAD3;
	if( Key == keys.KeyEvents.Numpad4 )
		return KEY_NUMPAD4;
	if( Key == keys.KeyEvents.Numpad5 )
		return KEY_NUMPAD5;
	if( Key == keys.KeyEvents.Numpad6 )
		return KEY_NUMPAD6;
	if( Key == keys.KeyEvents.Numpad7 )
		return KEY_NUMPAD7;
	if( Key == keys.KeyEvents.Numpad8 )
		return KEY_NUMPAD8;
	if( Key == keys.KeyEvents.Numpad9 )
		return KEY_NUMPAD9;
	if( Key == keys.KeyEvents.O )
		return KEY_O;
	if( Key == keys.KeyEvents.One )
		return KEY_ONE;
	if( Key == keys.KeyEvents.OpenBracket )
		return KEY_OPENBRACKET;
	if( Key == keys.KeyEvents.P )
		return KEY_P;
	if( Key == keys.KeyEvents.PageDown )
		return KEY_PAGEDOWN;
	if( Key == keys.KeyEvents.PageUp )
		return KEY_PAGEUP;
	if( Key == keys.KeyEvents.Pause )
		return KEY_PAUSE;
	if( Key == keys.KeyEvents.Period )
		return KEY_PERIOD;
	if( Key == keys.KeyEvents.Play )
		return KEY_PLAY;
	if( Key == keys.KeyEvents.Print )
		return KEY_PRINT;
	if( Key == keys.KeyEvents.PrintScreen )
		return KEY_PRINTSCREEN;
	if( Key == keys.KeyEvents.Q )
		return KEY_Q;
	if( Key == keys.KeyEvents.Quote )
		return KEY_QUOTE;
	if( Key == keys.KeyEvents.R )
		return KEY_R;
	if( Key == keys.KeyEvents.Right )
		return KEY_RIGHT;
	if( Key == keys.KeyEvents.RightAlt )
		return KEY_RIGHTALT;
	if( Key == keys.KeyEvents.RightControl )
		return KEY_RIGHTCONTROL;
	if( Key == keys.KeyEvents.RightMouse )
		return KEY_RIGHTMOUSE;
	if( Key == keys.KeyEvents.RightShift )
		return KEY_RIGHTSHIFT;
	if( Key == keys.KeyEvents.S )
		return KEY_S;
	if( Key == keys.KeyEvents.ScrollLock )
		return KEY_SCROLLLOCK;
	if( Key == keys.KeyEvents.Select )
		return KEY_SELECT;
	if( Key == keys.KeyEvents.SemiColon )
		return KEY_SEMICOLON;
	if( Key == keys.KeyEvents.Separator )
		return KEY_SEPARATOR;
	if( Key == keys.KeyEvents.Seven )
		return KEY_SEVEN;
	if( Key == keys.KeyEvents.Shift )
		return KEY_SHIFT;
	if( Key == keys.KeyEvents.Six )
		return KEY_SIX;
	if( Key == keys.KeyEvents.Space )
		return KEY_SPACE;
	if( Key == keys.KeyEvents.Subtract )
		return KEY_SUBTRACT;
	if( Key == keys.KeyEvents.T )
		return KEY_T;
	if( Key == keys.KeyEvents.Tab )
		return KEY_TAB;
	if( Key == keys.KeyEvents.Three )
		return KEY_THREE;
	if( Key == keys.KeyEvents.Tilde )
		return KEY_TILDE;
	if( Key == keys.KeyEvents.Two )
		return KEY_TWO;
	if( Key == keys.KeyEvents.U )
		return KEY_U;
	if( Key == keys.KeyEvents.Up )
		return KEY_UP;
	if( Key == keys.KeyEvents.V )
		return KEY_V;
	if( Key == keys.KeyEvents.W )
		return KEY_W;
	if( Key == keys.KeyEvents.X )
		return KEY_X;
	if( Key == keys.KeyEvents.Y )
		return KEY_Y;
	if( Key == keys.KeyEvents.Z )
		return KEY_Z;
	if( Key == keys.KeyEvents.Zero )
		return KEY_ZERO;
	if( Key == keys.KeyEvents.Zoom )
		return KEY_ZOOM;
	return "";
}
// ========================================================================
int cKeys::SecToMil( int Sec ) {
	return Sec*1000;
}
// ========================================================================
int cKeys::NextKeyPress( int WaitTime ) {
	int i = 0;
	while( i < WaitTime ) {
		if( keys.KeyPressed(keys.KeyEvents.A) )
			return keys.KeyEvents.A;
		if( keys.KeyPressed(keys.KeyEvents.Add) )
			return keys.KeyEvents.Add;
		if( keys.KeyPressed(keys.KeyEvents.Alt) )
			return keys.KeyEvents.Alt;
		if( keys.KeyPressed(keys.KeyEvents.B) )
			return keys.KeyEvents.B;
		if( keys.KeyPressed(keys.KeyEvents.BackSlash) )
			return keys.KeyEvents.BackSlash;
		if( keys.KeyPressed(keys.KeyEvents.Backspace) )
			return keys.KeyEvents.Backspace;
		if( keys.KeyPressed(keys.KeyEvents.Break) )
			return keys.KeyEvents.Break;
		if( keys.KeyPressed(keys.KeyEvents.C) )
			return keys.KeyEvents.C;
		if( keys.KeyPressed(keys.KeyEvents.CapsLock) )
			return keys.KeyEvents.CapsLock;
		if( keys.KeyPressed(keys.KeyEvents.Clear) )
			return keys.KeyEvents.Clear;
		if( keys.KeyPressed(keys.KeyEvents.CloseBracket) )
			return keys.KeyEvents.CloseBracket;
		if( keys.KeyPressed(keys.KeyEvents.Comma) )
			return keys.KeyEvents.Comma;
		if( keys.KeyPressed(keys.KeyEvents.Ctrl) )
			return keys.KeyEvents.Ctrl;
		if( keys.KeyPressed(keys.KeyEvents.D) )
			return keys.KeyEvents.D;
		if( keys.KeyPressed(keys.KeyEvents.Decimal) )
			return keys.KeyEvents.Decimal;
		if( keys.KeyPressed(keys.KeyEvents.Delete) )
			return keys.KeyEvents.Delete;
		if( keys.KeyPressed(keys.KeyEvents.Divide) )
			return keys.KeyEvents.Divide;
		if( keys.KeyPressed(keys.KeyEvents.Down) )
			return keys.KeyEvents.Down;
		if( keys.KeyPressed(keys.KeyEvents.E) )
			return keys.KeyEvents.E;
		if( keys.KeyPressed(keys.KeyEvents.Eight) )
			return keys.KeyEvents.Eight;
		if( keys.KeyPressed(keys.KeyEvents.End) )
			return keys.KeyEvents.End;
		if( keys.KeyPressed(keys.KeyEvents.Enter) )
			return keys.KeyEvents.Enter;
		if( keys.KeyPressed(keys.KeyEvents.Equals) )
			return keys.KeyEvents.Equals;
		if( keys.KeyPressed(keys.KeyEvents.Esc) )
			return keys.KeyEvents.Esc;
		if( keys.KeyPressed(keys.KeyEvents.Execute) )
			return keys.KeyEvents.Execute;
		if( keys.KeyPressed(keys.KeyEvents.F) )
			return keys.KeyEvents.F;
		if( keys.KeyPressed(keys.KeyEvents.F1) )
			return keys.KeyEvents.F1;
		if( keys.KeyPressed(keys.KeyEvents.F10) )
			return keys.KeyEvents.F10;
		if( keys.KeyPressed(keys.KeyEvents.F11) )
			return keys.KeyEvents.F11;
		if( keys.KeyPressed(keys.KeyEvents.F12) )
			return keys.KeyEvents.F12;
		if( keys.KeyPressed(keys.KeyEvents.F13) )
			return keys.KeyEvents.F13;
		if( keys.KeyPressed(keys.KeyEvents.F14) )
			return keys.KeyEvents.F14;
		if( keys.KeyPressed(keys.KeyEvents.F15) )
			return keys.KeyEvents.F15;
		if( keys.KeyPressed(keys.KeyEvents.F16) )
			return keys.KeyEvents.F16;
		if( keys.KeyPressed(keys.KeyEvents.F17) )
			return keys.KeyEvents.F17;
		if( keys.KeyPressed(keys.KeyEvents.F18) )
			return keys.KeyEvents.F18;
		if( keys.KeyPressed(keys.KeyEvents.F19) )
			return keys.KeyEvents.F19;
		if( keys.KeyPressed(keys.KeyEvents.F2) )
			return keys.KeyEvents.F;
		if( keys.KeyPressed(keys.KeyEvents.F20) )
			return keys.KeyEvents.F20;
		if( keys.KeyPressed(keys.KeyEvents.F21) )
			return keys.KeyEvents.F21;
		if( keys.KeyPressed(keys.KeyEvents.F22) )
			return keys.KeyEvents.F22;
		if( keys.KeyPressed(keys.KeyEvents.F23) )
			return keys.KeyEvents.F23;
		if( keys.KeyPressed(keys.KeyEvents.F24) )
			return keys.KeyEvents.F24;
		if( keys.KeyPressed(keys.KeyEvents.F3) )
			return keys.KeyEvents.F3;
		if( keys.KeyPressed(keys.KeyEvents.F4) )
			return keys.KeyEvents.F4;
		if( keys.KeyPressed(keys.KeyEvents.F5) )
			return keys.KeyEvents.F5;
		if( keys.KeyPressed(keys.KeyEvents.F6) )
			return keys.KeyEvents.F6;
		if( keys.KeyPressed(keys.KeyEvents.F7) )
			return keys.KeyEvents.F7;
		if( keys.KeyPressed(keys.KeyEvents.F8) )
			return keys.KeyEvents.F8;
		if( keys.KeyPressed(keys.KeyEvents.F9) )
			return keys.KeyEvents.F9;
		if( keys.KeyPressed(keys.KeyEvents.Five) )
			return keys.KeyEvents.Five;
		if( keys.KeyPressed(keys.KeyEvents.ForwardSlash) )
			return keys.KeyEvents.ForwardSlash;
		if( keys.KeyPressed(keys.KeyEvents.Four) )
			return keys.KeyEvents.Four;
		if( keys.KeyPressed(keys.KeyEvents.G) )
			return keys.KeyEvents.G;
		if( keys.KeyPressed(keys.KeyEvents.H) )
			return keys.KeyEvents.H;
		if( keys.KeyPressed(keys.KeyEvents.Help) )
			return keys.KeyEvents.Help;
		if( keys.KeyPressed(keys.KeyEvents.Home) )
			return keys.KeyEvents.Home;
		if( keys.KeyPressed(keys.KeyEvents.I) )
			return keys.KeyEvents.I;
		if( keys.KeyPressed(keys.KeyEvents.Insert) )
			return keys.KeyEvents.Insert;
		if( keys.KeyPressed(keys.KeyEvents.J) )
			return keys.KeyEvents.J;
		if( keys.KeyPressed(keys.KeyEvents.K) )
			return keys.KeyEvents.K;
		if( keys.KeyPressed(keys.KeyEvents.L) )
			return keys.KeyEvents.L;
		if( keys.KeyPressed(keys.KeyEvents.Left) )
			return keys.KeyEvents.Left;
		if( keys.KeyPressed(keys.KeyEvents.LeftAlt) )
			return keys.KeyEvents.LeftAlt;
		if( keys.KeyPressed(keys.KeyEvents.LeftControl) )
			return keys.KeyEvents.LeftControl;
		if( keys.KeyPressed(keys.KeyEvents.LeftMouse) )
			return keys.KeyEvents.LeftMouse;
		if( keys.KeyPressed(keys.KeyEvents.LeftShift) )
			return keys.KeyEvents.LeftShift;
		if( keys.KeyPressed(keys.KeyEvents.M) )
			return keys.KeyEvents.M;
		if( keys.KeyPressed(keys.KeyEvents.MiddleMouse) )
			return keys.KeyEvents.MiddleMouse;
		if( keys.KeyPressed(keys.KeyEvents.Minus) )
			return keys.KeyEvents.Minus;
		if( keys.KeyPressed(keys.KeyEvents.Multiply) )
			return keys.KeyEvents.Multiply;
		if( keys.KeyPressed(keys.KeyEvents.N) )
			return keys.KeyEvents.N;
		if( keys.KeyPressed(keys.KeyEvents.Nine) )
			return keys.KeyEvents.Nine;
		if( keys.KeyPressed(keys.KeyEvents.NumLock) )
			return keys.KeyEvents.NumLock;
		if( keys.KeyPressed(keys.KeyEvents.Numpad0) )
			return keys.KeyEvents.Numpad0;
		if( keys.KeyPressed(keys.KeyEvents.Numpad1) )
			return keys.KeyEvents.Numpad1;
		if( keys.KeyPressed(keys.KeyEvents.Numpad2) )
			return keys.KeyEvents.Numpad2;
		if( keys.KeyPressed(keys.KeyEvents.Numpad3) )
			return keys.KeyEvents.Numpad3;
		if( keys.KeyPressed(keys.KeyEvents.Numpad4) )
			return keys.KeyEvents.Numpad4;
		if( keys.KeyPressed(keys.KeyEvents.Numpad5) )
			return keys.KeyEvents.Numpad5;
		if( keys.KeyPressed(keys.KeyEvents.Numpad6) )
			return keys.KeyEvents.Numpad6;
		if( keys.KeyPressed(keys.KeyEvents.Numpad7) )
			return keys.KeyEvents.Numpad7;
		if( keys.KeyPressed(keys.KeyEvents.Numpad8) )
			return keys.KeyEvents.Numpad8;
		if( keys.KeyPressed(keys.KeyEvents.Numpad9) )
			return keys.KeyEvents.Numpad9;
		if( keys.KeyPressed(keys.KeyEvents.O) )
			return keys.KeyEvents.O;
		if( keys.KeyPressed(keys.KeyEvents.One) )
			return keys.KeyEvents.One;
		if( keys.KeyPressed(keys.KeyEvents.OpenBracket) )
			return keys.KeyEvents.OpenBracket;
		if( keys.KeyPressed(keys.KeyEvents.P) )
			return keys.KeyEvents.P;
		if( keys.KeyPressed(keys.KeyEvents.PageDown) )
			return keys.KeyEvents.PageDown;
		if( keys.KeyPressed(keys.KeyEvents.PageUp) )
			return keys.KeyEvents.PageUp;
		if( keys.KeyPressed(keys.KeyEvents.Pause) )
			return keys.KeyEvents.Pause;
		if( keys.KeyPressed(keys.KeyEvents.Period) )
			return keys.KeyEvents.Period;
		if( keys.KeyPressed(keys.KeyEvents.Play) )
			return keys.KeyEvents.Play;
		if( keys.KeyPressed(keys.KeyEvents.Print) )
			return keys.KeyEvents.Print;
		if( keys.KeyPressed(keys.KeyEvents.PrintScreen) )
			return keys.KeyEvents.PrintScreen;
		if( keys.KeyPressed(keys.KeyEvents.Q) )
			return keys.KeyEvents.Q;
		if( keys.KeyPressed(keys.KeyEvents.Quote) )
			return keys.KeyEvents.Quote;
		if( keys.KeyPressed(keys.KeyEvents.R) )
			return keys.KeyEvents.R;
		//if( keys.KeyPressed(keys.KeyEvents.Right) )
		//	return keys.KeyEvents.Right;
		if( keys.KeyPressed(keys.KeyEvents.RightAlt) )
			return keys.KeyEvents.RightAlt;
		if( keys.KeyPressed(keys.KeyEvents.RightControl) )
			return keys.KeyEvents.RightControl;
		if( keys.KeyPressed(keys.KeyEvents.RightMouse) )
			return keys.KeyEvents.RightMouse;
		if( keys.KeyPressed(keys.KeyEvents.RightShift) )
			return keys.KeyEvents.RightShift;
		if( keys.KeyPressed(keys.KeyEvents.S) )
			return keys.KeyEvents.S;
		if( keys.KeyPressed(keys.KeyEvents.ScrollLock) )
			return keys.KeyEvents.ScrollLock;
		if( keys.KeyPressed(keys.KeyEvents.Select) )
			return keys.KeyEvents.Select;
		if( keys.KeyPressed(keys.KeyEvents.SemiColon) )
			return keys.KeyEvents.SemiColon;
		if( keys.KeyPressed(keys.KeyEvents.Separator) )
			return keys.KeyEvents.Separator;
		if( keys.KeyPressed(keys.KeyEvents.Seven) )
			return keys.KeyEvents.Seven;
		if( keys.KeyPressed(keys.KeyEvents.Shift) )
			return keys.KeyEvents.Shift;
		if( keys.KeyPressed(keys.KeyEvents.Six) )
			return keys.KeyEvents.Six;
		if( keys.KeyPressed(keys.KeyEvents.Space) )
			return keys.KeyEvents.Space;
		if( keys.KeyPressed(keys.KeyEvents.Subtract) )
			return keys.KeyEvents.Subtract;
		if( keys.KeyPressed(keys.KeyEvents.T) )
			return keys.KeyEvents.T;
		if( keys.KeyPressed(keys.KeyEvents.Tab) )
			return keys.KeyEvents.Tab;
		if( keys.KeyPressed(keys.KeyEvents.Three) )
			return keys.KeyEvents.Three;
		if( keys.KeyPressed(keys.KeyEvents.Tilde) )
			return keys.KeyEvents.Tilde;
		if( keys.KeyPressed(keys.KeyEvents.Two) )
			return keys.KeyEvents.Two;
		if( keys.KeyPressed(keys.KeyEvents.U) )
			return keys.KeyEvents.U;
		if( keys.KeyPressed(keys.KeyEvents.Up) )
			return keys.KeyEvents.Up;
		if( keys.KeyPressed(keys.KeyEvents.V) )
			return keys.KeyEvents.V;
		if( keys.KeyPressed(keys.KeyEvents.W) )
			return keys.KeyEvents.W;
		if( keys.KeyPressed(keys.KeyEvents.X) )
			return keys.KeyEvents.X;
		if( keys.KeyPressed(keys.KeyEvents.Y) )
			return keys.KeyEvents.Y;
		if( keys.KeyPressed(keys.KeyEvents.Z) )
			return keys.KeyEvents.Z;
		if( keys.KeyPressed(keys.KeyEvents.Zero) )
			return keys.KeyEvents.Zero;
		if( keys.KeyPressed(keys.KeyEvents.Zoom) )
			return keys.KeyEvents.Zoom;
		i++;
		Sleep(1);
	}
	return keys.KeyEvents.None;
}
// ========================================================================