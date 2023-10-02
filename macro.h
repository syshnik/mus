/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_579078
#define	_pragma_once_579078

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////
#if !defined EXPORT_OR_IMPPORT 
#error hhhhh
#endif

#define RELIZ_V 0


#ifdef RELIZ_V
	#if RELIZ_V==0
		#define RELIZ 
	#else
		#define RELIZ пїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅ
	#endif
#else
	#error пїЅпїЅ пїЅпїЅпїЅпїЅпїЅ reliz
#endif 
#define INLINE_RELIZ RELIZ


#define LTYPE  (NL | sizeof(BBOOL)*0x10000)
//пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ
//#define BYTES 1
#define DWORDS 1
#define K(X) 
// /\ /\ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ

#define INDNC 12349
#define VTABNC 12348
#define TABNC 12347
#define FBOOLBNC 12345
#define STOLBNC 12346



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FBEG 20
//#define GSETF 3
#define SETF 2
#define NEWF 4
#define DELF 8
#define ALLF (SETF|NEWF|DELF)
#define NOTETYPE ( C_ST	| D_ST | P_ST	| L_ST | STR_ST	| 0xffff0000 )	

#define C_ST		2
#define D_ST		4
#define P_ST		8
#define L_ST		16
#define STR_ST		32	
#define I_ST		64
#define U_ST		128
#define MI_ST	1024
#define EY_ST		2048
#define F_C_ST		0x1000
#define	S1_ST		1*0x10000
#define	S2_ST		2*0x10000
#define	S4_ST		4*0x10000
#define	S8_ST		8*0x10000

/////////////////////////////////////////////////////////////////////////////////////
//intptr_t
			//для адреса памяти			#define UUI uintptr_t
			//для адреса памяти			#define UUI uintptr_t
#ifdef ENVIRONMENT64 
	#ifdef WIN_OPERACION_SYSTEM
			#define USI  long long
			#define UUI  unsigned long long
	#endif
	#ifdef UNIX_OPERACION_SYSTEM
			#define USI  long long
			#define UUI  unsigned long long
	#endif
			#define MAXUSI 0xffffffffffffffff
			#define MAXUUI 0xffffffffffffffff
#else
			#define USI unsigned int
			#define UUI unsigned int
			#define MAXUSI 0xffffffff
			#define MAXUUI 0xffffffff
#endif
#define BOLBOL unsigned __int8
		//-----------MAX	AND		MIN---------------------------
		#define	MAXF	3.4E38	
		#define	MINF	3.4E38	
		#define	MAXD	1.7E308	
		#define	MIND	1.7E308	
		//--------------TYPE------------------------------------------
		//#if	sizeof(long)!=8	#define	_int64	long#else
		#define	F4	float
		#define	F8	double
		#ifdef WIN_OPERACION_SYSTEM
			#define	U1	unsigned	__int8
			#define	U2	unsigned	__int16
			#define	U4	unsigned	__int32
			#define	U8	unsigned	__int64
			#define	S1		__int8
			#define	S2		__int16
			#define	S4		__int32
			#define	S8		__int64
			//#define	UI		U4
			//#define	SI		S4
			#define	UB		U1
			#define	FL	long
			#define	MAXU1	0xff
			#define	MAXU2	0xffff
			#define	MAXU4	0xffffffff
			#define	MAXU8	0xffffffffffffffff
		#endif
		#ifdef UNIX_OPERACION_SYSTEM

			#define	U1	unsigned	char
			#define	U2	unsigned	short
			#define	U4	unsigned	int
			#define	U8	unsigned	long long
			#define	S1		char
			#define	S2		short
			#define	S4		int
			#define	S8		long long
			//#define	UI		U4
			//#define	SI		S4
			#define	UB		U1
			#define	FL	long
			#define	MAXU1	0xff
			#define	MAXU2	0xffff
			#define	MAXU4	0xffffffff
			#define	MAXU8	0xffffffffffffffff
		#endif
		//-----------MAX	AND		MIN---------------------------


		#define	MAX1	(	MAXU1	/	2	)
		#define	MIN1	(	MAXU1	/	2		+		1		)
		#define	MAX2	(	MAXU2	/	2	)
		#define	MIN2	(	MAXU2	/	2		+		1		)
		#define	MAX4	(	MAXU4	/	2	)
		#define	MIN4	(	MAXU4	/	2		+		1		)
		#define	MAX8	(	MAXU8	/	2	)
		#define	MIN8	(	MAXU8	/	2		+		1		)
/////////////////////////////////////////////////////////////////////////////////////
#define NEWFLAG 1
#define MAXSIZEI 300
#define MAX_USER_STR_SIZE 5000
#ifdef TEST_V 
	//#define TEST_D 1
	#define NAMESIZE 10
	#define TESTSEL(XTEST,XRELIZ)			XTEST
	#define TM(X) (X)
	//#define TA(X) stop_if_not_true((bool)(X), __FILE__, __LINE__, "D:/Vrem/ErrorsFromCPPProg.txt")
	#define TA(X) stop_if_not_true((bool)(X), __FILE__, __LINE__, NULL)
	#define TNOTE0(TT,NOTE) TT NOTE;
	#define TNOTE(TT,NOTE,PAR) TT NOTE = PAR ;
#else 
	#define NAMESIZE 64
	#define TESTSEL(XTEST,XRELIZ)			XRELIZ
	#define TM(X)
	#define TA(X)
	#define TNOTE0(TT,NOTE)  ;
	#define TNOTE(TT,NOTE,PAR)  ;
#endif
#if TEST_P
	#define TPM(X) (X)
#else
	#define TPM(X)
#endif

#define DEL 1
OK_EXTERN void stop_if_not_true(bool par, char * filename, int line , char * SaveErrorFile=NULL);
#define A(X) stop_if_not_true((bool)(X), __FILE__, __LINE__)
#define CPAR
#define NULT  .ziro()
#define GI(X) (X).my
#define IT fnote


#define P pizdec=T
#define SSIZE 15
#define TNAME 64
//пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ
#define OPEN 1
#define MAKE 2
#define CHANGE 4
#define FORMA 8
#define OTCHOT 8*2
#define ZAPROS 8*4
#define TABLICA 8*8
#define FILE_TYPE_STR "bbf"


#define minminus(X1,X2) X1 -= min(X1, X2)
#define XORBIT(PAR,BIT) 		PAR = (PAR&~BIT) | ((BIT^PAR)&BIT);
#define F 0
#define FILENAME sizeof(long)
#define T 1

#define VSECTOR    bufersize
#define MEMSIZE    1000000
#define NOPARENT 32000
#define GINDEXUNIT		100
#define LINDEXUNIT		101
#define TABTYPEUNIT		104
#define TABUNIT			105
#define STOLBUNIT		200
#define STRINGUNIT		1
#define SUNIT			2
#define UUNIT			3
#define COMMENT(X) 



#include "../cod_mus/intemul.h"
#include "../cod_mus/mytype.h"
#include "../cod_mus/macroasm.h"

#endif //pragma once



