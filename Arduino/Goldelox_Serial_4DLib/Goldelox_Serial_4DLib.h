/*
	4DSerial - Library for 4D Systems Serial Environment.
	Released into the public domain.
*/
 
#ifndef Goldelox_Serial_4DLib_h
#define Goldelox_Serial_4DLib_h
 
#if (ARDUINO >= 100)
	#include "Arduino.h" // for Arduino 1.0
#else
	#include "WProgram.h" // for Arduino 23
#endif

#define Err4D_OK 		0
#define Err4D_Timeout		1
#define Err4D_NAK		2 // other than ACK received

#include "Goldelox_Types4D.h"	         	// Defines for 4dgl constants, generated by conversion of 4DGL constants to target language
#include "Goldelox_const4DSerial.h"        	// Defines for 4dgl constants, generated by conversion of 4DGL constants to target language
#include "Goldelox_const4D.h"	         	// Defines for 4dgl constants, generated by conversion of 4DGL constants to target language

typedef void (*Tcallback4D)(int, unsigned char); 

class Goldelox_Serial_4DLib
{
	public:
		Goldelox_Serial_4DLib(Stream * virtualPort);
		Tcallback4D Callback4D ;
		
		//Compound 4D Routines
		void blitComtoDisplay(word  X, word  Y, word  Width, word  Height, t4DByteArray  Pixels) ;
		void gfx_BGcolour(word  Color) ;
		void gfx_ChangeColour(word  OldColor, word  NewColor) ;
		void gfx_Circle(word  X, word  Y, word  Radius, word  Color) ;
		void gfx_CircleFilled(word  X, word  Y, word  Radius, word  Color) ;
		void gfx_Clipping(word  OnOff) ;
		void gfx_ClipWindow(word  X1, word  Y1, word  X2, word  Y2) ;
		void gfx_Cls(void) ;
		void gfx_Contrast(word  Contrast) ;
		void gfx_FrameDelay(word  Msec) ;
		void gfx_Line(word  X1, word  Y1, word  X2, word  Y2, word  Color) ;
		void gfx_LinePattern(word  Pattern) ;
		void gfx_LineTo(word  X, word  Y) ;
		void gfx_MoveTo(word  X, word  Y) ;
		void gfx_OutlineColour(word  Color) ;
		void gfx_Polygon(word  n, t4DWordArray  Xvalues, t4DWordArray  Yvalues, word  Color) ;
		void gfx_Polyline(word  n, t4DWordArray  Xvalues, t4DWordArray  Yvalues, word  Color) ;
		void gfx_PutPixel(word  X, word  Y, word  Color) ;
		void gfx_Rectangle(word  X1, word  Y1, word  X2, word  Y2, word  Color) ;
		void gfx_RectangleFilled(word  X1, word  Y1, word  X2, word  Y2, word  Color) ;
		void gfx_ScreenMode(word  ScreenMode) ;
		void gfx_Set(word  Func, word  Value) ;
		void gfx_Transparency(word  OnOff) ;
		void gfx_TransparentColour(word  Color) ;
		void gfx_Triangle(word  X1, word  Y1, word  X2, word  Y2, word  X3, word  Y3, word  Color) ;
		void media_Image(word  X, word  Y) ;
		void media_SetAdd(word  Hiword, word  Loword) ;
		void media_SetSector(word  Hiword, word  Loword) ;
		void media_Video(word  X, word  Y) ;
		void media_VideoFrame(word  X, word  Y, word  Framenumber) ;
		void pokeB(word  Address, word  ByteValue) ;
		void pokeW(word  Address, word  wordValue) ;
		void putCH(word  wordChar) ;
		void setbaudWait(word  Newrate) ;
		void SSMode(word  Parm) ;
		void SSSpeed(word  Speed) ;
		void SSTimeout(word  Seconds) ;
		void txt_Attributes(word  Attribs) ;
		void txt_BGcolour(word  Color) ;
		void txt_Bold(word  Bold) ;
		void txt_FGcolour(word  Color) ;
		void txt_FontID(word  FontNumber) ;
		void txt_Height(word  Multiplier) ;
		void txt_Inverse(word  Inverse) ;
		void txt_Italic(word  Italic) ;
		void txt_MoveCursor(word  Line, word  Column) ;
		void txt_Opacity(word  TransparentOpaque) ;
		void txt_Set(word  Func, word  Value) ;
		void txt_Underline(word  Underline) ;
		void txt_Width(word  Multiplier) ;
		void txt_Xgap(word  Pixels) ;
		void txt_Ygap(word  Pixels) ;
		void BeeP(word  Note, word  Duration) ;
		word charheight(char  TestChar) ;
		word charwidth(char  TestChar) ;
		word gfx_GetPixel(word  X, word  Y) ;
		word gfx_Orbit(word  Angle, word  Distance, word *  Xdest, word *  Ydest) ;
		word gfx_SetClipRegion(void) ;
		word joystick(void) ;
		word media_Flush(void) ;
		word media_Init(void) ;
		word media_ReadByte(void) ;
		word media_ReadWord(void) ;
		word media_WriteByte(word  Byte) ;
		word media_WriteWord(word  word) ;
		word peekB(word  Address) ;
		word peekW(word  Address) ;
		word putstr(char *  InString) ;
		word sys_GetModel(char *  ModelStr) ;
		word sys_GetPmmC(void) ;
		word sys_GetVersion(void) ;

		void GetAck(void);
		
		//4D Global Variables Used
		int Error4D;  				// Error indicator,  used and set by Intrinsic routines
		unsigned char Error4D_Inv;	// Error byte returned from com port, onl set if error = Err_Invalid
	//	int Error_Abort4D;  		// if true routines will abort when detecting an error
		unsigned long TimeLimit4D;	// time limit in ms for total serial command duration, 2000 (2 seconds) should be adequate for most commands
									// assuming a reasonable baud rate AND low latency AND 0 for the Serial Delay Parameter
									// temporary increase might be required for very long (bitmap write, large image file opens)
									// or indeterminate (eg file_exec, file_run, file_callFunction) commands
		
	private:
                Stream * _virtualPort;

		//Intrinsic 4D Routines
		void WriteChars(char * charsout);
		void WriteBytes(char * Source, int Size);
		void WriteWords(word * Source, int Size);
		void getbytes(char * data, int size);
		word GetWord(void);
		void getString(char * outStr, int strLen);
		word GetAckResp(void);
		word GetAckRes2Words(word * word1, word * word2);
		void GetAck2Words(word * word1, word * word2);
		word GetAckResStr(char * OutStr);
	//	word GetAckResData(t4DByteArray OutData, word size);
		void SetThisBaudrate(int Newrate);
};
 
#endif
