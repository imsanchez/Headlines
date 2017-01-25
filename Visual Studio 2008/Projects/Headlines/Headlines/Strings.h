// ========================================================================
#ifndef _STRINGS_
#define _STRINGS_
// ========================================================================
#pragma once
// ========================================================================
#define CRYPT8(str)	{ CRYPT8_(str "\0\0\0\0\0\0\0\0") }
#define CRYPT8_(str) (str)[0] + 1, (str)[1] + 2, (str)[2] + 3, (str)[3] + 4, (str)[4] + 5, (str)[5] + 6, (str)[6] + 7, (str)[7] + 8, '\0'
// ========================================================================
#define STRING_LOG_PATH							/*E:\\HEADLINES_LOG.txt*/XorStr<0x2D,21,0xC31ED18C>("\x68\x14\x73\x78\x74\x73\x77\x78\x7C\x78\x72\x6B\x66\x76\x74\x7B\x13\x4A\x47\x34"+0xC31ED18C).s
#define CONFIG_PATH							/*E:\\HEADLINES_CONFIG.ini*/XorStr<0xCB,24,0x9491EAE3>("\x8E\xF6\x91\x86\x8A\x91\x95\x9E\x9A\x9A\x90\x85\x88\x9B\x96\x94\x9D\x95\x9A\xF0\xB6\x8E\x88"+0x9491EAE3).s
// ========================================================================
#define STRING_GET_SCREEN_WIDTH				/*screenwidth*/XorStr<0x0D,12,0x11D2A1FC>("\x7E\x6D\x7D\x75\x74\x7C\x64\x7D\x71\x62\x7F"+0x11D2A1FC).s
#define STRING_GET_SCREEN_HEIGTH			/*screenheight*/XorStr<0x68,13,0x85932093>("\x1B\x0A\x18\x0E\x09\x03\x06\x0A\x19\x16\x1A\x07"+0x85932093).s
// ========================================================================
#define STRING_DEBUG_FONTINIT				/*Fonts Initialized.*/XorStr<0x31,19,0x5868F469>("\x77\x5D\x5D\x40\x46\x16\x7E\x56\x50\x4E\x52\x5D\x51\x57\x45\x25\x25\x6C"+0x5868F469).s
#define STRING_FONT_VERDANA					/*Verdana*/XorStr<0x19,8,0x6CC5D8F5>("\x4F\x7F\x69\x78\x7C\x70\x7E"+0x6CC5D8F5).s
#define STRING_FONT_SEGOE_UI				/*Segoe UI*/XorStr<0xCF,9,0x6CC7641C>("\x9C\xB5\xB6\xBD\xB6\xF4\x80\x9F"+0x6CC7641C).s
#define STRING_FONT_SEGOE_UI_LIGHT			/*Segoe UI Light*/XorStr<0xC5,15,0x74A47DE9>("\x96\xA3\xA0\xA7\xAC\xEA\x9E\x85\xED\x82\xA6\xB7\xB9\xA6"+0x74A47DE9).s
// ========================================================================
#define STRING_MENU_CCENTER					/*CursorCenter 0*/XorStr<0x01,15,0xD2434D93>("\x42\x77\x71\x77\x6A\x74\x44\x6D\x67\x7E\x6E\x7E\x2D\x3E"+0xD2434D93).s
#define	STRING_2DRADAR_TITLE				/*2D Radar*/XorStr<0xFE,17,0x5B9AB22B>("\xD0\xC5\x3A\x21\x30\x47\x24\x57\x67\x63\x69\x7B\x2A\x31\x36\x23"+0x5B9AB22B).s
// ========================================================================
#define STRING_MENU_TAB_VISUALS				/*Visuals*/XorStr<0x2F,8,0xE202E57A>("\x79\x59\x42\x47\x52\x58\x46"+0xE202E57A).s
#define STRING_MENU_TAB_PLAYERS				/*Players*/XorStr<0x5E,8,0x35D6FE6F>("\x0E\x33\x01\x18\x07\x11\x17"+0x35D6FE6F).s
#define STRING_MENU_TAB_REMOVALS			/*Removals*/XorStr<0xF5,9,0x237BE626>("\xA7\x93\x9A\x97\x8F\x9B\x97\x8F"+0x237BE626).s
#define STRING_MENU_TAB_SETTINGS			/*Settings*/XorStr<0x06,9,0xD8F59095>("\x55\x62\x7C\x7D\x63\x65\x6B\x7E"+0xD8F59095).s

#define STRING_MENU_TAB_AIMBOT				/*Aimbot*/XorStr<0x07,7,0x68BF7ECB>("\x46\x61\x64\x68\x64\x78"+0x68BF7ECB).s
#define STRING_MENU_TAB_ESP					/*Esp*/XorStr<0x2B,4,0x33E26CAB>("\x6E\x5F\x5D"+0x33E26CAB).s
#define STRING_MENU_TAB_MEMORY				/*Memory*/XorStr<0xD9,7,0x93078E42>("\x94\xBF\xB6\xB3\xAF\xA7"+0x93078E42).s
#define STRING_MENU_TAB_OTHERS				/*Others*/XorStr<0xF0,7,0xDD82C1E1>("\xBF\x85\x9A\x96\x86\x86"+0xDD82C1E1).s
#define STRING_MENU_TAB_CONFIG				/*Config*/XorStr<0x82,7,0xF877EB64>("\xC1\xEC\xEA\xE3\xEF\xE0"+0xF877EB64).s
// ========================================================================
#define STRING_DECREASE						/*<*/ XorStr<0x50,2,0x1BF8DBC7>("\x6C"+0x1BF8DBC7).s
#define STRING_INCREASE						/*>*/XorStr<0x90,2,0xE75880CC>("\xAE"+0xE75880CC).s
#define STRING_SS							/*%s [%s]*/XorStr<0xA1,8,0x72584BDA>("\x84\xD1\x83\xFF\x80\xD5\xFA"+0x72584BDA).s
#define STRING_SI							/*%s: [%i]*/XorStr<0x45,9,0x860958A0>("\x60\x35\x7D\x68\x12\x6F\x22\x11"+0x860958A0).s
// ========================================================================
#define STRING_MENU_GROUPING_MEM			/*.:: Memory ::.*/XorStr<0x98,15,0xE228AC9C>("\xB6\xA3\xA0\xBB\xD1\xF8\xF3\xF0\xD2\xD8\x82\x99\x9E\x8B"+0xE228AC9C).s
#define STRING_MENU_GROUPING_RAGE			/*.:: Rage ::.*/XorStr<0xAC,13,0x744A3F4F>("\x82\x97\x94\x8F\xE2\xD0\xD5\xD6\x94\x8F\x8C\x99"+0x744A3F4F).s
#define STRING_MENU_GROUPING_PLAYER			/*.:: Player ::.*/XorStr<0x55,15,0x2CBF4F07>("\x7B\x6C\x6D\x78\x09\x36\x3A\x25\x38\x2C\x7F\x5A\x5B\x4C"+0x2CBF4F07).s
#define STRING_MENU_GROUPING_AIMCONFIG		/*.:: Aimbot #2::.*/XorStr<0xF4,17,0xE77D16EA>("\xDA\xCF\xCC\xD7\xB9\x90\x97\x99\x93\x89\xDE\xDC\x32\x3B\x38\x2D"+0xE77D16EA).s
#define STRING_MENU_GROUPING_AIMBOT			/*.:: Aimbot #1::.*/XorStr<0x21,17,0x5459B782>("\x0F\x18\x19\x04\x64\x4F\x4A\x4A\x46\x5E\x0B\x0F\x1C\x14\x15\x1E"+0x5459B782).s
#define STRING_MENU_GROUPING_CONFIG			/*.:: Keys ::.*/XorStr<0x2C,13,0x432B3124>("\x02\x17\x14\x0F\x7B\x54\x4B\x40\x14\x0F\x0C\x19"+0x432B3124).s
#define STRING_MENU_GROUPING_OBJECT			/*.:: Object ::.*/XorStr<0x40,15,0x0FF544A3>("\x6E\x7B\x78\x63\x0B\x27\x2C\x22\x2B\x3D\x6A\x71\x76\x63"+0x0FF544A3).s
#define STRING_MENU_GROUPING_REMOVALS		/*.:: Removals ::.*/XorStr<0xB1,17,0x694753A9>("\x9F\x88\x89\x94\xE7\xD3\xDA\xD7\xCF\xDB\xD7\xCF\x9D\x84\x85\xEE"+0x694753A9).s
#define STRING_MENU_GROUPING_MISC			/*.:: Misc ::.*/XorStr<0x67,13,0x0E478352>("\x49\x52\x53\x4A\x26\x05\x1E\x0D\x4F\x4A\x4B\x5C"+0x0E478352).s
// ========================================================================
#define STRING_MENU_CBOX_NOFOG				/*No Fog*/XorStr<0x3F,7,0x05C83F4E>("\x71\x2F\x61\x04\x2C\x23"+0x05C83F4E).s
#define STRING_MENU_CBOX_NOKNOCKBACK		/*No Knockback*/XorStr<0xF5,13,0x8B604980>("\xBB\x99\xD7\xB3\x97\x95\x98\x97\x9F\x9F\x9C\x6B"+0x8B604980).s
#define STRING_MENU_CBOX_NORELOAD			/*No Reload*/XorStr<0x31,10,0xDEB52565>("\x7F\x5D\x13\x66\x50\x5A\x58\x59\x5D"+0xDEB52565).s
#define STRING_MENU_CBOX_NOSMOKE			/*No Smoke*/XorStr<0x53,9,0xCCD7AC50>("\x1D\x3B\x75\x05\x3A\x37\x32\x3F"+0xCCD7AC50).s
#define STRING_MENU_CBOX_NOSPREAD			/*No Spread*/XorStr<0x21,10,0xC23BDB7E>("\x6F\x4D\x03\x77\x55\x54\x42\x49\x4D"+0xC23BDB7E).s
#define STRING_MENU_CBOX_NOSWAY				/*No Sway*/XorStr<0x4A,8,0x30AEDBD0>("\x04\x24\x6C\x1E\x39\x2E\x29"+0x30AEDBD0).s

#define STRING_MENU_CBOX_2DRADAR			/*2D Radar*/XorStr<0x38,9,0x3DA1A808>("\x0A\x7D\x1A\x69\x5D\x59\x5F\x4D"+0x3DA1A808).s
#define STRING_MENU_CBOX_AIMCORRECTION		/*Aim Correction*/XorStr<0x3C,15,0x139E6FF3>("\x7D\x54\x53\x1F\x03\x2E\x30\x31\x21\x26\x32\x2E\x27\x27"+0x139E6FF3).s
#define STRING_MENU_CBOX_STATS				/*Stats*/XorStr<0xB7,6,0x40C8E464>("\xE4\xCC\xD8\xCE\xC8"+0x40C8E464).s
#define STRING_MENU_CBOX_DRAWFPS			/*Draw FPS*/XorStr<0x59,9,0x06A8062A>("\x1D\x28\x3A\x2B\x7D\x18\x0F\x33"+0x06A8062A).s
#define STRING_MENU_CBOX_UNLIMITEDSTAM		/*Unlimited Stamina*/XorStr<0xCA,18,0x398B44DD>("\x9F\xA5\xA0\xA4\xA3\xA6\xA4\xB4\xB6\xF3\x87\xA1\xB7\xBA\xB1\xB7\xBB"+0x398B44DD).s
#define STRING_MENU_CBOX_ACTIVATEBOT		/*Activate Aimbot*/XorStr<0xB0,16,0xFFA59F1E>("\xF1\xD2\xC6\xDA\xC2\xD4\xC2\xD2\x98\xF8\xD3\xD6\xDE\xD2\xCA"+0xFFA59F1E).s
#define STRING_MENU_CBOX_VISIBLE_ONLY		/*Visible Only*/XorStr<0x12,13,0xFFB58B00>("\x44\x7A\x67\x7C\x74\x7B\x7D\x39\x55\x75\x70\x64"+0xFFB58B00).s
#define STRING_MENU_CBOX_AIM_AT_TEAM		/*Aim At Team*/XorStr<0x14,12,0x811BB159>("\x55\x7C\x7B\x37\x59\x6D\x3A\x4F\x79\x7C\x73"+0x811BB159).s
#define STRING_MENU_CBOX_SPAWN_CHECK		/*Spawn Check*/XorStr<0x7B,12,0xE3E439DB>("\x28\x0C\x1C\x09\x11\xA0\xC2\xEA\xE6\xE7\xEE"+0xE3E439DB).s
#define STRING_MENU_CBOX_AUTOSWITCH			/*AutoSwitch*/XorStr<0x87,11,0x13862186>("\xC6\xFD\xFD\xE5\xD8\xFB\xE4\xFA\xEC\xF8"+0x13862186).s
#define STRING_MENU_CBOX_AIMBONE			/*Aim Bone*/XorStr<0x5B,9,0x7F64A7A4>("\x1A\x35\x30\x7E\x1D\x0F\x0F\x07"+0x7F64A7A4).s
#define STRING_MENU_CBOX_AUTOAIM			/*Auto Aim*/XorStr<0x76,9,0x424E2373>("\x37\x02\x0C\x16\x5A\x3A\x15\x10"+0x424E2373).s
#define STRING_MENU_CBOX_AUTOFIRE			/*Auto Fire*/XorStr<0x7B,10,0x88351D5E>("\x3A\x09\x09\x11\x5F\xC6\xE8\xF0\xE6"+0x88351D5E).s
#define STRING_MENU_CBOX_AIMMODE			/*Aim Mode*/XorStr<0x6E,9,0x2B153F4C>("\x2F\x06\x1D\x51\x3F\x1C\x10\x10"+0x2B153F4C).s
#define STRING_MENU_CBOX_MAXFOV				/*Max FOV*/XorStr<0x91,8,0x0693B734>("\xDC\xF3\xEB\xB4\xD3\xD9\xC1"+0x0693B734).s
#define STRING_MENU_CBOX_FPSCORRECTION		/*FPS Correction*/XorStr<0xE1,15,0xEA8C1776>("\xA7\xB2\xB0\xC4\xA6\x89\x95\x9A\x8C\x89\x9F\x85\x82\x80"+0xEA8C1776).s
#define STRING_MENU_CBOX_PREDICTION			/*Prediction*/XorStr<0x43,11,0xB6F37B44>("\x13\x36\x20\x22\x2E\x2B\x3D\x23\x24\x22"+0xB6F37B44).s
#define STRING_MENU_CBOX_NAME				/*Name*/XorStr<0x24,5,0x418235B7>("\x6A\x44\x4B\x42"+0x418235B7).s
#define STRING_MENU_CBOX_DISTANCE			/*Distance*/XorStr<0xD1,9,0x1AEB78C9>("\x95\xBB\xA0\xA0\xB4\xB8\xB4\xBD"+0x1AEB78C9).s
#define STRING_MENU_CBOX_HEALTH				/*Health*/XorStr<0xBB,7,0xFD076E63>("\xF3\xD9\xDC\xD2\xCB\xA8"+0xFD076E63).s
#define STRING_MENU_CBOX_BOX				/*Box*/XorStr<0xD9,4,0xDD4667FD>("\x9B\xB5\xA3"+0xDD4667FD).s
#define STRING_MENU_CBOX_LINES				/*Lines*/XorStr<0xDE,6,0xBE7F0526>("\x92\xB6\x8E\x84\x91"+0xBE7F0526).s
#define STRING_MENU_CBOX_VIS_CHECK			/*Visible Check*/XorStr<0xFB,14,0xC0125136>("\xAD\x95\x8E\x97\x9D\x6C\x64\x22\x40\x6C\x60\x65\x6C"+0xC0125136).s
#define STRING_MENU_CBOX_BEHINDYOU			/*Behind You Warning*/XorStr<0xDD,19,0x4ADD720A>("\x9F\xBB\xB7\x89\x8F\x86\xC3\xBD\x8A\x93\xC7\xBF\x88\x98\x85\x85\x83\x89"+0x4ADD720A).s
#define STRING_MENU_CBOX_VISBILEWARN		/*Visible Warning*/XorStr<0x2C,16,0xEA6FFE17>("\x7A\x44\x5D\x46\x52\x5D\x57\x13\x63\x54\x44\x59\x51\x57\x5D"+0xEA6FFE17).s
#define STRING_MENU_CBOX_NPC				/*NPC*/XorStr<0x33,4,0x725BDBE5>("\x7D\x64\x76"+0x725BDBE5).s
#define STRING_MENU_CBOX_EXPLOSIVE_NAME     /*Explosive Name*/XorStr<0xC4,15,0x06968909>("\x81\xBD\xB6\xAB\xA7\xBA\xA3\xBD\xA9\xED\x80\xAE\xBD\xB4"+0x06968909).s
#define STRING_MENU_CBOX_EXP_OWNER			/*Explosive Owner*/XorStr<0x53,16,0x1649C224>("\x16\x2C\x25\x3A\x38\x2B\x30\x2C\x3E\x7C\x12\x29\x31\x05\x13"+0x1649C224).s
#define STRING_MENU_CBOX_EXP_DISTANCE		/*Explosive Distance*/XorStr<0xA7,19,0x99755AF7>("\xE2\xD0\xD9\xC6\xC4\xDF\xC4\xD8\xCA\x90\xF5\xDB\xC0\xC0\xD4\xD8\xD4\xDD"+0x99755AF7).s
#define STRING_MENU_CBOX_EXP_WARNING		/*Explosive Warning*/XorStr<0x67,18,0x479B2A77>("\x22\x10\x19\x06\x04\x1F\x04\x18\x0A\x50\x26\x13\x01\x1A\x1C\x18\x10"+0x479B2A77).s
#define STRING_MENU_CBOX_PICKUP				/*Pickup Esp*/XorStr<0xE0,11,0x30566768>("\xB0\x88\x81\x88\x91\x95\xC6\xA2\x9B\x99"+0x30566768).s
#define STRING_MENU_CBOX_PICKUP_DISTANCE	/*Pickup Distance*/XorStr<0xA7,16,0x1C9F8FE6>("\xF7\xC1\xCA\xC1\xDE\xDC\x8D\xEA\xC6\xC3\xC5\xD3\xDD\xD7\xD0"+0x1C9F8FE6).s
#define STRING_MENU_CBOX_SUPERBULLETS		/*Super Bullets*/ XorStr<0xD2,14,0x9D167F72>("\x81\xA6\xA4\xB0\xA4\xF7\x9A\xAC\xB6\xB7\xB9\xA9\xAD"+0x9D167F72).s
#define STRING_MENU_CBOX_WEAPONRANGE		/*Weapon Range*/XorStr<0x4E,13,0xA17772C3>("\x19\x2A\x31\x21\x3D\x3D\x74\x07\x37\x39\x3F\x3C"+0xA17772C3).s
#define STRING_MENU_CBOX_SERVERCRASHER		/*Server Crasher*/XorStr<0x74,15,0xEFD9742F>("\x27\x10\x04\x01\x1D\x0B\x5A\x38\x0E\x1C\x0D\x17\xE5\xF3"+0xEFD9742F).s
#define STRING_MENU_CBOX_SPAMMER			/*Spammer*/XorStr<0x06,8,0xBE404FE0>("\x55\x77\x69\x64\x67\x6E\x7E"+0xBE404FE0).s
#define STRING_MENU_CBOX_TELEKILL			/*Telekill*/XorStr<0xF0,9,0x361DC832>("\xA4\x94\x9E\x96\x9F\x9C\x9A\x9B"+0x361DC832).s
#define STRING_MENU_CBOX_AIMKEY				/*Aim Key*/XorStr<0x74,8,0xA030871E>("\x35\x1C\x1B\x57\x33\x1C\x03"+0xA030871E).s
#define STRING_MENU_CBOX_MENUKEY			/*Menu Key*/XorStr<0x64,9,0x3ABA85F6>("\x29\x00\x08\x12\x48\x22\x0F\x12"+0x3ABA85F6).s
#define STRING_MENU_CBOX_TELEKEY			/*Tele Key*/XorStr<0x2F,9,0xC3FBBDEB>("\x7B\x55\x5D\x57\x13\x7F\x50\x4F"+0xC3FBBDEB).s
#define STRING_MENU_CBOX_CHAMS				/*Chams*/XorStr<0xF6,6,0x4CF8E3CE>("\xB5\x9F\x99\x94\x89"+0x4CF8E3CE).s
#define STRING_MENU_CBOX_NORECOIL			/*No Recoil*/XorStr<0xA1,10,0x00260571>("\xEF\xCD\x83\xF6\xC0\xC5\xC8\xC1\xC5"+0x00260571).s

#define STRING_MENU_CBOX_NOCAMDAM			/*No Cam Damage*/XorStr<0x32,14,0x51CB284A>("\x7C\x5C\x14\x76\x57\x5A\x18\x7D\x5B\x56\x5D\x5A\x5B"+0x51CB284A).s
#define STRING_MENU_CBOX_NOSFX				/*No SFX*/XorStr<0x22,7,0x928569D9>("\x6C\x4C\x04\x76\x60\x7F"+0x928569D9).s
#define STRING_MENU_CBOX_NOGUN				/*No Gun*/XorStr<0x6A,7,0x56E410C2>("\x24\x04\x4C\x2A\x1B\x01"+0x56E410C2).s
#define STRING_MENU_CBOX_SPEED				/*Speed*/XorStr<0xFF,6,0x9172B742>("\xAC\x70\x64\x67\x67"+0x9172B742).s
#define STRING_MENU_CBOX_HULK				/*Hulk Jump*/XorStr<0x55,10,0xC3E982DC>("\x1D\x23\x3B\x33\x79\x10\x2E\x31\x2D"+0xC3E982DC).s
#define STRING_MENU_CBOX_WINDOWED			/*Windowed*/XorStr<0xE8,9,0x7CB46207>("\xBF\x80\x84\x8F\x83\x9A\x8B\x8B"+0x7CB46207).s
#define STRING_MENU_CBOX_TRACERS			/*Tracers*/XorStr<0x10,8,0x79410E4B>("\x44\x63\x73\x70\x71\x67\x65"+0x79410E4B).s
#define STRING_MENU_CBOX_FULLBRIGHT			/*Fullbright*/XorStr<0x82,11,0x139863A8>("\xC4\xF6\xE8\xE9\xE4\xF5\xE1\xEE\xE2\xFF"+0x139863A8).s
#define STRING_MENU_CBOX_CROSSHAIR			/*Crosshair*/XorStr<0xD1,10,0xC2D996D9>("\x92\xA0\xBC\xA7\xA6\xBE\xB6\xB1\xAB"+0xC2D996D9).s
#define STRING_MENU_CBOX_EAGLE				/*Eagle Eye*/XorStr<0xE4,10,0x1B44487A>("\xA1\x84\x81\x8B\x8D\xC9\xAF\x92\x89"+0x1B44487A).s
#define STRING_MENU_CBOX_ADISTANCE			/*Activation Dist*/XorStr<0xC9,16,0xDDEFEC81>("\x88\xA9\xBF\xA5\xBB\xAF\xBB\xB9\xBE\xBC\xF3\x90\xBC\xA5\xA3"+0xDDEFEC81).s
#define STRING_MENU_CBOX_FLY				/*Fly*/XorStr<0x8F,4,0x69D76314>("\xC9\xFC\xE8"+0x69D76314).s
#define STRING_MENU_ARRR_REMOTEKILL			/*Remote Kill*/XorStr<0x36,12,0xD7548B3F>("\x64\x52\x55\x56\x4E\x5E\x1C\x76\x57\x53\x2C"+0xD7548B3F).s
// ========================================================================
#define STRING_HookShark					/*HookShark.exe*/XorStr<0xA8,14,0xB38189C2>("\xE0\xC6\xC5\xC0\xFF\xC5\xCF\xDD\xDB\x9F\xD7\xCB\xD1"+0xB38189C2).s
#define STRING_OLLYexe						/*OLLYDBG.exe*/XorStr<0x9D,12,0x698473BD>("\xD2\xD2\xD3\xF9\xE5\xE0\xE4\x8A\xC0\xDE\xC2"+0x698473BD).s
#define STRING_WIN_HEX						/*WinHex.exe*/XorStr<0xF9,11,0x253D5B3A>("\xAE\x93\x95\xB4\x98\x86\xD1\x65\x79\x67"+0x253D5B3A).s
#define STRING_Hook_Shark					/*hookshark*/XorStr<0x2C,10,0x795D9072>("\x44\x42\x41\x44\x43\x59\x53\x41\x5F"+0x795D9072).s
#define STRING_OllyWT						/*ollydbg*/XorStr<0x06,8,0xC3A2D3BF>("\x69\x6B\x64\x70\x6E\x69\x6B"+0xC3A2D3BF).s
#define STRING_KernelDet					/*Kernel Detective.exe*/XorStr<0x6B,21,0x6FB6F82C>("\x20\x09\x1F\x00\x0A\x1C\x51\x36\x16\x00\x10\x15\x03\x11\x0F\x1F\x55\x19\x05\x1B"+0x6FB6F82C).s
#define STRING_ReClassexe					/*ReClass.exe*/XorStr<0x56,12,0xD5A1FD7C>("\x04\x32\x1B\x35\x3B\x28\x2F\x73\x3B\x27\x05"+0xD5A1FD7C).s
#define STRING_ReClass						/*reclass*/XorStr<0x3D,8,0x16E64180>("\x4F\x5B\x5C\x2C\x20\x31\x30"+0x16E64180).s
#define STRING_StructBuildWT				/*struct builder*/XorStr<0x70,15,0x87AB6244>("\x03\x05\x00\x06\x17\x01\x56\x15\x0D\x10\x16\x1F\x19\x0F"+0x87AB6244).s
#define STRING_StructBuildExe 				/*StructBuild.exe*/XorStr<0xE0,16,0xE5859E96>("\xB3\x95\x90\x96\x87\x91\xA4\x92\x81\x85\x8E\xC5\x89\x95\x8B"+0xE5859E96).s
#define STRING_CEWT			  				/*cheat engine*/XorStr<0xDF,13,0x7C5AAD1A>("\xBC\x88\x84\x83\x97\xC4\x80\x88\x80\x81\x87\x8F"+0x7C5AAD1A).s
#define STRING_CEEXE		  				/*Cheat Engine.exe*/XorStr<0x95,17,0x32669071>("\xD6\xFE\xF2\xF9\xED\xBA\xDE\xF2\xFA\xF7\xF1\xC5\x8F\xC7\xDB\xC1"+0x32669071).s
#define STRING_WinHexWT       				/*winhex*/XorStr<0x2D,7,0x1D810D48>("\x5A\x47\x41\x58\x54\x4A"+0x1D810D48).s
#define STRING_KEY_NOT_FOUND  				/*KEY NOT FOUND*/XorStr<0xBC,14,0x4FD7F23E>("\xF7\xF8\xE7\x9F\x8E\x8E\x96\xE3\x82\x8A\x93\x89\x8C"+0x4FD7F23E).s
// ========================================================================
#define STRING_D3D9DOTDLL					/*d3d9.dll*/XorStr<0xD6,9,0x987BDCF7>("\xB2\xE4\xBC\xE0\xF4\xBF\xB0\xB1"+0x987BDCF7).s
#define STRING_ENGINEDOTEXE					/*Engine.exe*/XorStr<0xB3,11,0x3FD973F4>("\xF6\xDA\xD2\xDF\xD9\xDD\x97\xDF\xC3\xD9"+0x3FD973F4).s
#define STRING_CSHELLDOTDLL					/*CShell.dll*/XorStr<0x83,11,0x2ABEBD9B>("\xC0\xD7\xED\xE3\xEB\xE4\xA7\xEE\xE7\xE0"+0x2ABEBD9B).s
#define STRING_CLIENTFXDOTFXD				/*Clientfx.fxd*/XorStr<0xB5,13,0xA14E5965>("\xF6\xDA\xDE\xDD\xD7\xCE\xDD\xC4\x93\xD8\xC7\xA4"+0xA14E5965).s
#define STRING_EHSVCDOTDLL					/*EhSvc.dll*/XorStr<0x62,10,0x8463DDED>("\x27\x0B\x37\x13\x05\x49\x0C\x05\x06"+0x8463DDED).s
#define STRING_INITIALIZING					/*Initializing...*/XorStr<0x91,16,0xE61DBCFE>("\xD8\xFC\xFA\xE0\xFC\xF7\xFB\xF1\xE3\xF3\xF5\xFB\xB3\xB0\xB1"+0xE61DBCFE).s
#define STRING_DEVICEMISMATCH				/*Device Mismatch...*/XorStr<0xAB,19,0x0846BA5E>("\xEF\xC9\xDB\xC7\xCC\xD5\x91\xFF\xDA\xC7\xD8\xD7\xC3\xDB\xD1\x94\x95\x92"+0x0846BA5E).s
#define STRING_OBJECTSRECREATED				/*Objects Re-Created...*/XorStr<0xBA,22,0x0162BC32>("\xF5\xD9\xD6\xD8\xDD\xCB\xB3\xE1\x90\xA6\xE9\x86\xB4\xA2\xA9\xBD\xAF\xAF\xE2\xE3\xE0"+0x0162BC32).s
#define STRING_OBJECTSRELEASED				/*Objects Released...*/XorStr<0x7C,20,0x0C9BCE58>("\x33\x1F\x14\x1A\xE3\xF5\xF1\xA3\xD6\xE0\xEA\xE2\xE9\xFA\xEF\xEF\xA2\xA3\xA0"+0x0C9BCE58).s
#define STRING_CLASSESCREATED				/*Classes Created...*/XorStr<0x6D,19,0x957BEC62>("\x2E\x02\x0E\x03\x02\x17\x00\x54\x36\x04\x12\x19\x0D\x1F\x1F\x52\x53\x50"+0x957BEC62).s
#define STRING_DETOURINGRESET				/*Placing Detour on Reset...*/XorStr<0x83,27,0x643303DB>("\xD3\xE8\xE4\xE5\xEE\xE6\xEE\xAA\xCF\xE9\xF9\xE1\xFA\xE2\xB1\xFD\xFD\xB4\xC7\xF3\xE4\xFD\xED\xB4\xB5\xB2"+0x643303DB).s
#define STRING_DETOURINGPRESENT				/*Placing Detour on Present...*/XorStr<0xA6,29,0x500DEBB2>("\xF6\xCB\xC9\xCA\xC3\xC5\xCB\x8D\xEA\xCA\xC4\xDE\xC7\xC1\x94\xDA\xD8\x97\xE8\xCB\xDF\xC8\xD9\xD3\xCA\x91\xEE\xEF"+0x500DEBB2).s
#define STRING_DETOURINGENDSCENE			/*Placing Detour on Endscene...*/XorStr<0x6C,30,0x0C2F689B>("\x3C\x01\x0F\x0C\x19\x1F\x15\x53\x30\x10\x02\x18\x0D\x0B\x5A\x14\x12\x5D\x3B\x11\xE4\xF2\xE1\xE6\xEA\xE0\xA8\xA9\xA6"+0x0C2F689B).s
#define STRING_DETOUR_SUCCESS				/*Detoured Functions Successfully...*/XorStr<0x44,35,0x9E08174C>("\x00\x20\x32\x28\x3D\x3B\x2F\x2F\x6C\x0B\x3B\x21\x33\x25\x3B\x3C\x3A\x26\x76\x04\x2D\x3A\x39\x3E\x2F\x2E\x38\x2A\x0C\x0D\x1B\x4D\x4A\x4B"+0x9E08174C).s
#define STRING_CLASSCREATIONFAILURE 		/*Failed to Create Classes...*/XorStr<0x5D,28,0x05D6B6A3>("\x1B\x3F\x36\x0C\x04\x06\x43\x10\x0A\x46\x24\x1A\x0C\x0B\x1F\x09\x4D\x2D\x03\x11\x02\x01\x16\x07\x5B\x58\x59"+0x05D6B6A3).s
#define STRING_WINDOWNAME					/*Combat_Arms*/XorStr<0x17,12,0x7C5F992B>("\x54\x77\x74\x78\x7A\x68\x42\x5F\x6D\x4D\x52"+0x7C5F992B).s
#define STRING_CLASSFAILURE_dwMain			/*Class Failure in dwMain*/XorStr<0x69,24,0x5881832B>("\x2A\x06\x0A\x1F\x1E\x4E\x29\x11\x18\x1E\x06\x06\x10\x56\x1E\x16\x59\x1E\x0C\x31\x1C\x17\x11"+0x5881832B).s
// ========================================================================
#define STRING_KERNEL						/*Kernel32.dll*/XorStr<0xC0,13,0x48E0E858>("\x8B\xA4\xB0\xAD\xA1\xA9\xF5\xF5\xE6\xAD\xA6\xA7"+0x48E0E858).s
#define STRING_MTBWC						/*MultiByteToWideChar*/XorStr<0x4C,20,0x2929D48E>("\x01\x38\x22\x3B\x39\x13\x2B\x27\x31\x01\x39\x00\x31\x3D\x3F\x18\x34\x3C\x2C"+0x2929D48E).s
// ========================================================================
#define STRING_KILLS						/*Kills: %i*/XorStr<0xB1,10,0xFEC6D441>("\xFA\xDB\xDF\xD8\xC6\x8C\x97\x9D\xD0"+0xFEC6D441).s
#define STRING_DEATHS						/*Deaths: %i*/XorStr<0x43,11,0xDD928961>("\x07\x21\x24\x32\x2F\x3B\x73\x6A\x6E\x25"+0xDD928961).s
#define STRING_HEADSHOTS					/*Headshots: %i*/XorStr<0x7B,14,0x0E525432>("\x33\x19\x1C\x1A\x0C\xE8\xEE\xF6\xF0\xBE\xA5\xA3\xEE"+0x0E525432).s
#define STRING_KILLDEATHRATION				/*Kill Death Ratio: %.1f*/XorStr<0x91,23,0xCD740196>("\xDA\xFB\xFF\xF8\xB5\xD2\xF2\xF9\xED\xF2\xBB\xCE\xFC\xEA\xF6\xCF\x9B\x82\x86\x8A\x94\xC0"+0xCD740196).s
#define STRING_HEADSHOTRATION				/*Headshot Ratio: %.1f*/XorStr<0xFB,21,0x47C0301C>("\xB3\x99\x9C\x9A\x8C\x68\x6E\x76\x23\x56\x64\x72\x6E\x67\x33\x2A\x2E\x22\x3C\x68"+0x47C0301C).s
#define STRING_STATS_GUI_STRING				/*.:: Stats ::.*/XorStr<0x9B,14,0xE803A3E3>("\xB5\xA6\xA7\xBE\xCC\xD4\xC0\xD6\xD0\x84\x9F\x9C\x89"+0xE803A3E3).s
// ========================================================================
#define STRING_CRASH_MESSAGE				/*Later Nubs*/XorStr<0x05,11,0x3B98DC5D>("\x49\x67\x73\x6D\x7B\x2A\x45\x79\x6F\x7D"+0x3B98DC5D).s
// ========================================================================
#define STRING_NOFOG_ON						/*FogEnable 0*/XorStr<0xAC,12,0xAA7D5C4B>("\xEA\xC2\xC9\xEA\xDE\xD0\xD0\xDF\xD1\x95\x86"+0xAA7D5C4B).s
#define STRING_NOFOG_OFF					/*FogEnable 1*/XorStr<0x60,12,0x1A4F348E>("\x26\x0E\x05\x26\x0A\x04\x04\x0B\x0D\x49\x5B"+0x1A4F348E).s
#define STRING_SHOWFPS_ON					/*+ShowFps 1.0*/XorStr<0xF3,13,0x5271A881>("\xD8\xA7\x9D\x99\x80\xBE\x89\x89\xDB\xCD\xD3\xCE"+0x5271A881).s
#define STRING_SHOWFPS_OFF					/*+ShowFps 0.0*/XorStr<0xFB,13,0x7C32B6FE>("\xD0\xAF\x95\x91\x88\x46\x71\x71\x23\x34\x2B\x36"+0x7C32B6FE).s

#define STRING_NOGUNS_ON					/*drawguns 0*/XorStr<0x8E,11,0x1C078CEC>("\xEA\xFD\xF1\xE6\xF5\xE6\xFA\xE6\xB6\xA7"+0x1C078CEC).s
#define STRING_NOGUNS_OFF					/*drawguns 1*/XorStr<0x6F,11,0xA2F827B9>("\x0B\x02\x10\x05\x14\x01\x1B\x05\x57\x49"+0xA2F827B9).s
#define STRING_CHAMSON						/*SkelModelStencil 1*/XorStr<0x4F,19,0x48B52A23>("\x1C\x3B\x34\x3E\x1E\x3B\x31\x33\x3B\x0B\x2D\x3F\x35\x3F\x34\x32\x7F\x51"+0x48B52A23).s
#define STRING_CHAMSOFF						/*SkelModelStencil 0*/XorStr<0xDC,19,0xE062DEE9>("\x8F\xB6\xBB\xB3\xAD\x8E\x86\x86\x88\xB6\x92\x82\x86\x8A\x83\x87\xCC\xDD"+0xE062DEE9).s
#define STRING_CAMDAMAGE1					/*CamDamage 0*/XorStr<0xDC,12,0xF197AB9F>("\x9F\xBC\xB3\x9B\x81\x8C\x83\x84\x81\xC5\xD6"+0xF197AB9F).s
#define STRING_CAMDAMAGE2					/*CamDamagePitch 0*/XorStr<0xA6,17,0x415B5D9A>("\xE5\xC6\xC5\xED\xCB\xC6\xCD\xCA\xCB\xFF\xD9\xC5\xD1\xDB\x94\x85"+0x415B5D9A).s
#define STRING_CAMDAMAGE3					/*CamDamageRoll 0*/XorStr<0x03,16,0x49756EFE>("\x40\x65\x68\x42\x66\x65\x68\x6D\x6E\x5E\x62\x62\x63\x30\x21"+0x49756EFE).s
#define STRING_CAMDAMAGE4					/*CamDamageTime1 0*/XorStr<0x24,17,0xF7BFBBF1>("\x67\x44\x4B\x63\x49\x44\x4B\x4C\x49\x79\x47\x42\x55\x00\x12\x03"+0xF7BFBBF1).s
#define STRING_CAMDAMAGE5					/*CamDamageTime2 0*/XorStr<0x63,17,0x3D01D315>("\x20\x05\x08\x22\x06\x05\x08\x0D\x0E\x38\x04\x03\x0A\x42\x51\x42"+0x3D01D315).s
#define STRING_CAMDAMAGE6					/*CamDamageMinPitchVal 0*/XorStr<0x28,23,0x6DB15AE5>("\x6B\x48\x47\x6F\x4D\x40\x4F\x48\x55\x7C\x5B\x5D\x64\x5C\x42\x54\x50\x6F\x5B\x57\x1C\x0D"+0x6DB15AE5).s
#define STRING_CAMDAMAGE7					/*CamDamageMaxPitchVal 0*/XorStr<0xB0,23,0x20836B4D>("\xF3\xD0\xDF\xF7\xD5\xD8\xD7\xD0\xDD\xF4\xDB\xC3\xEC\xD4\xCA\xDC\xA8\x97\xA3\xAF\xE4\xF5"+0x20836B4D).s
#define STRING_CAMDAMAGE8					/*CamDamageMinRollVal 0*/XorStr<0x96,22,0x7D9956A3>("\xD5\xF6\xF5\xDD\xFB\xF6\xFD\xFA\xFB\xD2\xC9\xCF\xF0\xCC\xC8\xC9\xF0\xC6\xC4\x89\x9A"+0x7D9956A3).s
#define STRING_CAMDAMAGE9					/*CamDamageMaxRollVal 0*/XorStr<0xA9,22,0x30C74AA3>("\xEA\xCB\xC6\xE8\xCC\xC3\xCE\xD7\xD4\xFF\xD2\xCC\xE7\xD9\xDB\xD4\xEF\xDB\xD7\x9C\x8D"+0x30C74AA3).s 
#define STRING_CAMDAMAGE10					/*CamDamagePitchMin 0*/XorStr<0xF8,20,0xA466DDE5>("\xBB\x98\x97\xBF\x9D\x90\x9F\x98\x65\x51\x6B\x77\x67\x6D\x4B\x6E\x66\x29\x3A"+0xA466DDE5).s
#define STRING_CAMDAMAGE11					/*CamDamageRollMin 0*/XorStr<0xE6,19,0xC3901B4A>("\xA5\x86\x85\xAD\x8B\x86\x8D\x8A\x8B\xBD\x9F\x9D\x9E\xBE\x9D\x9B\xD6\xC7"+0xC3901B4A).s
#define STRING_SNOWOFF						/*SnowEnable 0*/XorStr<0x42,13,0x16532BC4>("\x11\x2D\x2B\x32\x03\x29\x29\x2B\x26\x2E\x6C\x7D"+0x16532BC4).s
#define STRING_DEBRISOFF					/*DebrisFXLevel 0*/XorStr<0x75,16,0xEF505024>("\x31\x13\x15\x0A\x10\x09\x3D\x24\x31\x1B\x09\xE5\xED\xA2\xB3"+0xEF505024).s
#define STRING_SCATTEROFF					/*ScatterEnable 0*/XorStr<0x0B,16,0xA4578F7C>("\x58\x6F\x6C\x7A\x7B\x75\x63\x57\x7D\x75\x77\x7A\x72\x38\x29"+0xA4578F7C).s
#define STRING_DETAILOFF					/*ClientFXDetailLevel 0*/XorStr<0x74,22,0x2F336841>("\x37\x19\x1F\x12\x16\x0D\x3C\x23\x38\x18\x0A\x1E\xE9\xED\xCE\xE6\xF2\xE0\xEA\xA7\xB8"+0x2F336841).s
#define STRING_MODELSHADOWOFF				/*ModelShadow_Proj_Enable 0*/XorStr<0x9B,26,0x7620F967>("\xD6\xF3\xF9\xFB\xF3\xF3\xC9\xC3\xC7\xCB\xD2\xF9\xF7\xDA\xC6\xC0\xF4\xE9\xC3\xCF\xCD\xDC\xD4\x92\x83"+0x7620F967).s
#define STRING_WEATHOFF						/*EnableWeatherFX 0*/XorStr<0xB1,18,0x56D88706>("\xF4\xDC\xD2\xD6\xD9\xD3\xE0\xDD\xD8\xCE\xD3\xD9\xCF\xF8\xE7\xE0\xF1"+0x56D88706).s
#define STRING_BLUROFF						/*modelshadow_proj_blurenable 0*/XorStr<0x99,30,0x6C05B3A2>("\xF4\xF5\xFF\xF9\xF1\xED\xF7\xC1\xC5\xCD\xD4\xFB\xD5\xD4\xC8\xC2\xF6\xC8\xC7\xD9\xDF\xCB\xC1\xD1\xD3\xDE\xD6\x94\x85"+0x6C05B3A2).s
#define STRING_MODELSHADOWSOFF				/*DrawAllModelShadows 0*/XorStr<0xF7,22,0xDFC1F5DC>("\xB3\x8A\x98\x8D\xBA\x90\x91\xB3\x90\x64\x64\x6E\x50\x6C\x64\x62\x68\x7F\x7A\x2A\x3B"+0xDFC1F5DC).s 
#define STRING_MINCOLORCOMPOFF				/*ModelShadow_Proj_MinColorComponent 0*/XorStr<0xFB,37,0x5549A425>("\xB6\x93\x99\x9B\x93\x53\x69\x63\x67\x6B\x72\x59\x57\x7A\x66\x60\x54\x41\x64\x60\x4C\x7F\x7D\x7D\x61\x57\x7A\x7B\x67\x77\x77\x7F\x75\x68\x3D\x2E"+0x5549A425).s
#define STRING_MAXSHADOWDISTOFF				/*ModelShadow_Proj_MaxProjDist 0*/XorStr<0xC4,31,0xFC413709>("\x89\xAA\xA2\xA2\xA4\x9A\xA2\xAA\xA8\xA2\xB9\x90\x80\xA3\xBD\xB9\x8B\x98\xB7\xAF\x88\xAB\xB5\xB1\x98\xB4\xAD\xAB\xC0\xD1"+0xFC413709).s
#define STRING_SHADOWALHPAOFF				/*ModelShadow_Proj_Alpha 0*/XorStr<0x18,25,0xEA7087D3>("\x55\x76\x7E\x7E\x70\x4E\x76\x7E\x44\x4E\x55\x7C\x74\x57\x49\x4D\x77\x68\x46\x5B\x44\x4C\x0E\x1F"+0xEA7087D3).s
#define STRING_SNOWENABLEON					/*SnowEnable 1*/XorStr<0x70,13,0x0C80AE64>("\x23\x1F\x1D\x04\x31\x1B\x17\x15\x14\x1C\x5A\x4A"+0x0C80AE64).s
#define STRING_DEBRISON						/*DebrisFXLevel 1*/XorStr<0x0D,16,0xB65E92C2>("\x49\x6B\x6D\x62\x78\x61\x55\x4C\x59\x73\x61\x7D\x75\x3A\x2A"+0xB65E92C2).s
#define STRING_SCATTERON					/*ScatterEnable 1*/XorStr<0x75,16,0xAC85FB10>("\x26\x15\x16\x0C\x0D\x1F\x09\x39\x13\x1F\x1D\xEC\xE4\xA2\xB2"+0xAC85FB10).s
#define STRING_CLIENTDETAILON				/*ClientFXDetailLevel 1*/XorStr<0x79,22,0x0602172E>("\x3A\x16\x12\x19\x13\x0A\x39\xD8\xC5\xE7\xF7\xE5\xEC\xEA\xCB\xED\xFF\xEF\xE7\xAC\xBC"+0x0602172E).s
#define STRING_WEATHERON					/*EnableWeatherFX 1*/XorStr<0x0E,18,0xDF72A8B8>("\x4B\x61\x71\x73\x7E\x76\x43\x70\x77\x63\x70\x7C\x68\x5D\x44\x3D\x2F"+0xDF72A8B8).s
#define STRING_BLURON						/*modelshadow_proj_blurenable 1*/XorStr<0x05,30,0x7B2744DF>("\x68\x69\x63\x6D\x65\x79\x63\x6D\x69\x61\x78\x4F\x61\x60\x7C\x7E\x4A\x74\x7B\x6D\x6B\x7F\x75\x7D\x7F\x72\x7A\x00\x10"+0x7B2744DF).s
#define STRING_MSGENABLE					/*ModelShadow_Proj_Enable 1*/XorStr<0x0B,26,0x06BE125D>("\x46\x63\x69\x6B\x63\x43\x79\x73\x77\x7B\x62\x49\x47\x6A\x76\x70\x44\x59\x73\x7F\x7D\x4C\x44\x02\x12"+0x06BE125D).s
#define STRING_DrawPolyGrids0				/*DrawPolyGrids 0*/XorStr<0xBC,16,0xAB8D4F9C>("\xF8\xCF\xDF\xC8\x90\xAE\xAE\xBA\x83\xB7\xAF\xA3\xBB\xE9\xFA"+0xAB8D4F9C).s
#define STRING_DrawParticles0				/*DrawParticles 0*/XorStr<0xB2,16,0xDD6C31FA>("\xF6\xC1\xD5\xC2\xE6\xD6\xCA\xCD\xD3\xD8\xD0\xD8\xCD\x9F\xF0"+0xDD6C31FA).s
#define STRING_DrawPolyGrids1				/*DrawPolyGrids 1z*/XorStr<0x66,16,0x8071D6F8>("\x22\x15\x09\x1E\x3A\x04\x00\x14\x29\x1D\x19\x15\x01\x53\x45"+0x8071D6F8).s
#define STRING_DrawParticles1				/*DrawParticles 1*/XorStr<0x65,16,0x8949CFDB>("\x21\x14\x06\x1F\x39\x0B\x19\x18\x04\x0D\x03\x15\x02\x52\x42"+0x8949CFDB).s
#define STRING_ShowFirepath0				/*ShowFirePath 0*/XorStr<0x19,15,0x8D8759E1>("\x4A\x72\x74\x6B\x5B\x77\x6D\x45\x71\x43\x57\x4C\x05\x16"+0x8D8759E1).s
#define STRING_ShowFirepath1				/*ShowFirePath 1*/XorStr<0xBB,15,0x6C4C9648>("\xE8\xD4\xD2\xC9\xF9\xA9\xB3\xA7\x93\xA5\xB1\xAE\xE7\xF9"+0x6C4C9648).s
#define STRING_Windowed0					/*windowed 0*/XorStr<0xDD,11,0x7EDB6FE2>("\xAA\xB7\xB1\x84\x8E\x95\x86\x80\xC5\xD6"+0x7EDB6FE2).s
#define STRING_Windowed1					/*windowed 1*/XorStr<0x5A,11,0x48CE3E44>("\x2D\x32\x32\x39\x31\x28\x05\x05\x42\x52"+0x48CE3E44).s
#define STRING_Jumpvel600					/*JumpVel 600*/XorStr<0xE4,12,0xCAF179A6>("\xAE\x90\x8B\x97\xBE\x8C\x86\xCB\xDA\xDD\xDE"+0xCAF179A6).s
#define STRING_JumpVel330					/*JumpVel 330*/XorStr<0xDA,12,0x8E630B80>("\x90\xAE\xB1\xAD\x88\xBA\x8C\xC1\xD1\xD0\xD4"+0x8E630B80).s
#define STRING_FULLBRIGHTON					XorStr<0x7D,13,0x9950B0A5>("\x3B\x0B\x13\xEC\xC3\xF0\xEA\xE3\xED\xF2\xA7\xB9"+0x9950B0A5).s
#define STRING_FULLBRIGHTOFF				XorStr<0x10,13,0x499153F3>("\x56\x64\x7E\x7F\x56\x67\x7F\x70\x70\x6D\x3A\x2B"+0x499153F3).s
// ========================================================================
#define STRING_NADE_ESP1					/*[%s]*/XorStr<0x8F,5,0x290D314E>("\xD4\xB5\xE2\xCF"+0x290D314E).s
#define STRING_NADE_ESP2					/*%s*/XorStr<0xBD,3,0xC324A8AD>("\x98\xCD"+0xC324A8AD).s
#define STRING_NADE_ESP3					/*[D: %.2f]*/XorStr<0xB5,10,0x9C4714FA>("\xEE\xF2\x8D\x98\x9C\x94\x89\xDA\xE0"+0x9C4714FA).s
#define STRING_NADE_ESP4					/*%s [%s]*/XorStr<0x31,8,0x2583B638>("\x14\x41\x13\x6F\x10\x45\x6A"+0x2583B638).s
#define STRING_NADE_ESP5					/*%s [D: %.2f]*/XorStr<0x4D,13,0xB4FFEF06>("\x68\x3D\x6F\x0B\x15\x68\x73\x71\x7B\x64\x31\x05"+0xB4FFEF06).s
#define STRING_NADE_ESP6					/*[%s] [D: %.2f]*/XorStr<0x31,15,0xDAF5E4E7>("\x6A\x17\x40\x69\x15\x6D\x73\x02\x19\x1F\x15\x0E\x5B\x63"+0xDAF5E4E7).s
#define STRING_NADE_ESP7					/*%s [%s] [D: %.2f]*/XorStr<0xC8,18,0xEA8BFD34>("\xED\xBA\xEA\x90\xE9\xBE\x93\xEF\x8B\x95\xE8\xF3\xF1\xFB\xE4\xB1\x85"+0xEA8BFD34).s
#define STRING_ESP_EXPLOSIVE_DANGER 		/*DANGER EXPLOSIVE NEAR YOU!*/XorStr<0xEB,27,0x98CF1B88>("\xAF\xAD\xA3\xA9\xAA\xA2\xD1\xB7\xAB\xA4\xB9\xB9\xA4\xB1\xAF\xBF\xDB\xB2\xB8\xBF\xAD\x20\x58\x4D\x56\x25"+0x98CF1B88).s
#define STRING_ESP_PICKUP_DIST				/*D: %.2f*/XorStr<0x6F,8,0xB875C1CD>("\x2B\x4A\x51\x57\x5D\x46\x13"+0xB875C1CD).s
#define STRING_ESP_WEAPON					/*Weapon*/XorStr<0x72,7,0xBA35884F>("\x25\x16\x15\x05\x19\x19"+0xBA35884F).s
#define STRING_ESP_WEAPON_DIST				/*Weapon D: %.2f*/XorStr<0x18,15,0x248959DB>("\x4F\x7C\x7B\x6B\x73\x73\x3E\x5B\x1A\x01\x07\x0D\x16\x43"+0x248959DB).s
#define STRING_ESP_ENEMYS_VISIBLE   		/*[%i] Enemys Visible!*/XorStr<0xC0,21,0x6377E63D>("\x9B\xE4\xAB\x9E\xE4\x80\xA8\xA2\xA5\xB0\xB9\xEB\x9A\xA4\xBD\xA6\xB2\xBD\xB7\xF2"+0x6377E63D).s
#define STRING_ESP_ENEMYS_BEHIND_U  		/*[%i] Enemys Behind You!*/XorStr<0x86,24,0xF187EDD0>("\xDD\xA2\xE1\xD4\xAA\xCE\xE2\xE8\xE3\xF6\xE3\xB1\xD0\xF6\xFC\xFC\xF8\xF3\xB8\xC0\xF5\xEE\xBD"+0xF187EDD0).s
// ========================================================================
#endif
// ========================================================================