#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
// bazstr.cpp: implementation of the bazstr class.
//
//////////////////////////////////////////////////////////////////////

#include "../cod_mus/stdafx.h"
#include "../cod_mus/musor.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../cod_mus/in_for_file_work.h"

//////////////////////////////////////////////////////////////////////
/*using namespace NSMY::NSCmp;
using namespace NSMY::NSSmall;
using namespace NSMY::NSType;
*/
#define Q_BAZ_STR 1

#if !defined TEST_V
	#if !defined Q_BAZ_STR
		#error nnnnnnnnnnnnnnn
	#endif
#endif
//////////////////////////////////////////////////////////////////////
/*
extern char w_char_to_baz_char(char par);
extern char try_w_char_to_baz_char(char par);
extern char baz_char_to_w_char(char par);
*/
//#include "../cod_mus/../w_bigcod/w_baz_str.h"
/*
bazchar::bazchar(char par) {
	note=class_to_char::wtobaz(par);
}

bazchar::operator char() {
	return class_to_char::baztow(note);
}
*/
namespace NSMY {
namespace NSStr {


///////////////////////////////////////////////////////////////////////////////
bool test_right_wchar(char ch) { return (class_to_char::wtobaz(ch) != 0); };

bool test_right_wstr(char * ch) {
	for( ; *ch; ch++) if(!class_to_char::wtobaz(*ch)) return F;
	return T;
}

/*void stringcopy(bazchar * ku, char * ot) {
	TA(test_right_wstr(ot));
	for( ; *ot; ot++, ku++) *(char *)ku = w_char_to_baz_char(*ot);
	*(char *)ku=0;
}

void stringcopy(char * ku, bazchar * ot) {
	for( ; *ot; ot++, ku++) *ku = baz_char_to_w_char(*(char *)ot);
	*ku=0;
}*/
#define __break__			*((char *)ot) != 0

USI stringcopy(bazchar * ku, char * ot) {
	TA(test_right_wstr(ot));
	void * savech=ot;
	for( ; __break__; ot++, ku++) {
		*(char *)ku = class_to_char::wtobaz(*ot);
	}
	*(char *)ku=0;
	return ((USI)ot-(USI)savech);
}

USI stringcopy(char * ku, bazchar * ot) {
	void * savech=ot;
	for( ; __break__; ot++, ku++) *ku = class_to_char::baztow(*(char *)ot);
	*ku=0;
	return ((USI)ot-(USI)savech);
}

USI stringcopy(char * ku, char * ot) {
	void * savech=ot;
	for( ; __break__; ot++, ku++) *ku = *ot;
	*ku=0;
	return ((USI)ot-(USI)savech);
}

USI stringcopy(bazchar * ku, bazchar * ot) {
	void * savech=ot;
	for( ; __break__; ot++, ku++) *ku = *ot;
	*ku=0;
	return ((USI)ot-(USI)savech);
}

void stringcopy(bazchar * ku, char * ot, USI strsize) {
	for( ; strsize; strsize--, ot++, ku++) 
		*(char *)ku = class_to_char::wtobaz(*ot);
	*(char *)ku=0;
}

void stringcopy(char * ku, bazchar * ot, USI strsize) {
	for( ; strsize; strsize--, ot++, ku++) 
		*ku = class_to_char::baztow(*(char *)ot);
	*ku=0;
}

void stringcopy(char * ku, char * ot, USI strsize) {
//	memcpy(ku, ot, strsize);
	InlineMoveMem((anyp)newdp(ku), (anyp)newdp(ot), strsize);
	ku[strsize]=0;
}

void stringcopy(bazchar * ku, bazchar * ot, USI strsize) {
	//memcpy(ku, ot, strsize);
	InlineMoveMem((anyp)newdp(ku), (anyp)newdp(ot), strsize);
	ku[strsize]=0;
}

USI ppstringcopy(anyp ku, char * ot) {
	TM(ku[0]);				TM(ku[strlen(ot)+1]);
	return stringcopy((bazchar *)&ku[0], ot);
}

USI ppstringcopy(char * ku, anyp ot) {
	TM(findendstr(ot, ~0));
	return stringcopy(ku, (bazchar *)&ot[0]);
}

/*void qstringcopy(bazchar ** kup, char ** otp) {
	bazchar * ku=*kup;
	char * ot=*otp;
	TA(test_right_wstr(ot));
	
	for( ; *ot; ot++, ku++) *(char *)ku = w_char_to_baz_char(*ot);
	
	*(char *)ku=0;	ku++;
	*kup=ku;		*otp=ot;
}

void qstringcopy(char ** kup, bazchar ** otp) {
	bazchar * ot=*otp;
	char * ku=*kup;

	for( ; *ot; ot++, ku++) *ku = baz_char_to_w_char(*(char *)ot);
	*ku=0;	ku++;
	
	*kup=ku;		*otp=ot;
}*/
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

bool test_null_bazstr(bazchar * bch) {
	if(*(char *)bch == 0) return T;
	return F; 
}


bool test_false_bazstr(bazchar * bch) {
	char ziro_bazchar=class_to_char::wtobaz('0');
	if(*(char *)bch == ziro_bazchar) if(*(char *)bch == 0) return T;
	return F; 
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
						
#define LR_MAC(X1,X2) 						\
		if(!X1 || !X2) return T;				\
		if(X1 != X2) return F;				

#define R_MAC(X1,X2) 						\
		if(X1 != X2) return F;				\
		if(!X1) return T;				
#define NR_MAC(X1,X2) 						\
		if(X1 != X2) return T;				\
		if(!X1) return F;				
#define BOR_MAC(X1,X2) 						\
		if(X1 < X2) return F;				\
		if(X1 > X2) return T;				\
		if(!X1) return T;				
#define MER_MAC(X1,X2) 						\
		if(X1 > X2) return F;				\
		if(X1 < X2) return T;				\
		if(!X1) return T;				
#define ME_MAC(X1,X2) 						\
		if(X1 < X2) return T;				\
		if(X1 > X2) return F;				\
		if(!X1) return F;				
#define BO_MAC(X1,X2) 						\
		if(X1 > X2) return T;				\
		if(X1 < X2) return F;				\
		if(!X1) return F;				

#define W_DELSIZE(X)		if(belong(X, 'A', 'Z')) X='a'+(X-'A');\
		else if(belong(X, 'А', 'Я')) X='а'+(X-'А');\
		else if(X=='Ё') X='ё';

#define W_LOC_CH char c1=*ch1, c2=*ch2;	W_DELSIZE(c1)		W_DELSIZE(c2)





//приблизительное сравнение ("aaa" == "aaa" && "aaa" == "a")

bool bazstr::w_lr (char * ch1, char * ch2)
{
	for(; ;   ch1++, ch2++) {		W_LOC_CH;		LR_MAC(c1,c2);	}
	TA(0);			return ~0;
}

//точное сравнение ("aaa" == "aaa" && "aaa" > "a")

bool bazstr::w_r (char * ch1, char * ch2)
{
	for(; ;   ch1++, ch2++) {		W_LOC_CH;		R_MAC(c1,c2);	}
	TA(0);			return ~0;
}

bool bazstr::w_nr (char * ch1, char * ch2)
{
	for(; ;   ch1++, ch2++) {		W_LOC_CH;		NR_MAC(c1,c2);	}
	TA(0);			return ~0;
}

bool bazstr::w_bor (char * ch1, char * ch2)
{
	for(; ;   ch1++, ch2++) {		W_LOC_CH;		BOR_MAC(c1,c2);	}
	TA(0);			return ~0;
}

bool bazstr::w_mer (char * ch1, char * ch2)
{
	for(; ;   ch1++, ch2++) {		W_LOC_CH;		MER_MAC(c1,c2);	}
	TA(0);			return ~0;
}

bool bazstr::w_me (char * ch1, char * ch2)
{
	for(; ;   ch1++, ch2++) {		W_LOC_CH;		ME_MAC(c1,c2);	}
	TA(0);			return ~0;
}

bool bazstr::w_bo (char * ch1, char * ch2)
{
	for(; ;   ch1++, ch2++) {		W_LOC_CH;		BO_MAC(c1,c2);	}
	TA(0);			return ~0;
}



//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//
//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//baz//str//
#if !defined Q_BAZ_STR
	bool bazstr::	baz_r	(bazchar	*	ch1,	bazchar	*	ch2)	{ return	w_r	(	(char *)ch1,	(char *)ch2)	; }		
	bool bazstr::	baz_nr	(bazchar	*	ch1,	bazchar	*	ch2)	{ return	w_nr	(	(char *)ch1,	(char *)ch2)	; }		
	bool bazstr::	baz_bor	(bazchar	*	ch1,	bazchar	*	ch2)	{ return	w_bor	(	(char *)ch1,	(char *)ch2)	; }		
	bool bazstr::	baz_mer	(bazchar	*	ch1,	bazchar	*	ch2)	{ return	w_mer	(	(char *)ch1,	(char *)ch2)	; }		
	bool bazstr::	baz_me	(bazchar	*	ch1,	bazchar	*	ch2)	{ return	w_me	(	(char *)ch1,	(char *)ch2)	; }		
	bool bazstr::	baz_bo	(bazchar	*	ch1,	bazchar	*	ch2)	{ return	w_bo	(	(char *)ch1,	(char *)ch2)	; }		
#else

	#define DW_AND	(~(128 + 0x100*128 + 0x10000*128 + 0x1000000*128))
	#define BAZ_LOC_CH \
												int c1=*((int *)ch1);		int c2=*((int *)ch2);\
												c1 &= DW_AND;		c2 &= DW_AND;

	#define BAZ_RET(MAC1) 						\
			MAC1;				\
			c1/=0x100;		c2/=0x100;		\
			MAC1;				\
			c1/=0x100;		c2/=0x100;		\
			MAC1;				\
			c1/=0x100;		c2/=0x100;		\
			MAC1;				
//del g:\mu   sdll.dll 
	bool bazstr::baz_lr (bazchar * ch1, bazchar * ch2)
	{
		for(; ;   ch1+=4, ch2+=4) {		BAZ_LOC_CH;		BAZ_RET(LR_MAC(((char)c1),((char)c2))); };
		TA(0);			return ~0;
	}
	//copy debug\musdll.dll g:\musdll.dll
	bool bazstr::baz_r (bazchar * ch1, bazchar * ch2)
	{
		for(; ;   ch1+=4, ch2+=4) {		BAZ_LOC_CH;		BAZ_RET(R_MAC(((char)c1),((char)c2))); };
		TA(0);			return ~0;
	}

	bool bazstr::baz_nr (bazchar * ch1, bazchar * ch2)
	{
		for(; ;   ch1+=4, ch2+=4) {		BAZ_LOC_CH;		BAZ_RET(NR_MAC(((char)c1),((char)c2))); };
		TA(0);			return ~0;
	}

	bool bazstr::baz_bor (bazchar * ch1, bazchar * ch2)
	{
		for(; ;   ch1+=4, ch2+=4) {		BAZ_LOC_CH;		BAZ_RET(BOR_MAC(((char)c1),((char)c2))); };
		TA(0);			return ~0;
	}

	bool bazstr::baz_mer (bazchar * ch1, bazchar * ch2)
	{
		for(; ;   ch1+=4, ch2+=4) {		BAZ_LOC_CH;		BAZ_RET(MER_MAC(((char)c1),((char)c2))); };
		TA(0);			return ~0;
	}

	bool bazstr::baz_bo (bazchar * ch1, bazchar * ch2)
	{
		for(; ;   ch1+=4, ch2+=4) {		BAZ_LOC_CH;		BAZ_RET(BO_MAC(((char)c1),((char)c2))); };
		TA(0);			return ~0;
	}

	bool bazstr::baz_me (bazchar * ch1, bazchar * ch2)
	{
		for(; ;   ch1+=4, ch2+=4) {		BAZ_LOC_CH;		BAZ_RET(ME_MAC(((char)c1),((char)c2))); };
		TA(0);			return ~0;
	}

#endif


#if TEST_V
bool findendstr(anyp par, USI size) {
	charp ch=(charp)par;
	for( ; size>0; ch++, size--) if(*ch == 0) return T;
	return F;
}
#endif

//char * itostr(		USI	note, char * buf, int bufsize,  Radix r)			{	itos<USI, char*>(note, buf, bufsize, r);	return buf;		};


#ifdef VISUALCPP2015
char * itostrd(double	note, char * buf, int bufsize, Radix r) { sprintf_s(buf, bufsize, "%f", note);	return buf; };
char * itostr(double	note, char * buf, int bufsize, Radix r) { sprintf_s(buf, bufsize, "%f", note);	return buf; };
char * itostr(float	note, char * buf, int bufsize, Radix r) { sprintf_s(buf, bufsize, "%f", note);	return buf; };
#else
char * itostrd(		double	note, char * buf, int bufsize,  Radix r)			{  	sprintf(buf, "%f", note);	return buf;		};
char * itostr(		double	note, char * buf, int bufsize,  Radix r)			{  	sprintf(buf, "%f", note);	return buf;		};
char * itostr(		float	note, char * buf, int bufsize,  Radix r)			{  	sprintf(buf, "%f", note);	return buf;		};
#endif
char * itostr(		S1	note, char * buf, int bufsize,  Radix r)			{	itos<S1, char*>(note, buf, bufsize, r);	return buf;		};
char * itostr(		S2	note, char * buf, int bufsize,  Radix r)			{	itos<S2, char*>(note, buf, bufsize, r);	return buf;		};
char * itostr(		S4	note, char * buf, int bufsize,  Radix r)			{	itos<S4, char*>(note, buf, bufsize, r);	return buf;		};
char * itostr(		S8	note, char * buf, int bufsize,  Radix r)			{	itos<S8, char*>(note, buf, bufsize, r);	return buf;		};
char * itostr(		U1	note, char * buf, int bufsize,  Radix r)			{	itos<U1, char*>(note, buf, bufsize, r);	return buf;		};
char * itostr(		U2	note, char * buf, int bufsize,  Radix r)			{	itos<U2, char*>(note, buf, bufsize, r);	return buf;		};
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
char * itostr(		U4	note, char * buf, int bufsize,  Radix r)			{	itos<U4, char*>(note, buf, bufsize, r);	return buf;		};
#endif
char * itostr(		U8	note, char * buf, int bufsize,  Radix r)			{	itos<U8, char*>(note, buf, bufsize, r);	return buf;		};
char * itostr(		voidtype	note, char * buf, int bufsize,  Radix r)			{ TA(0); return 	NULL;			};

S1	strtoi1	(char * str, char ** errorstr)			{ return strtoi<	S1	> (str, errorstr); }	
S2	strtoi2	(char * str, char ** errorstr)			{ return strtoi<	S2	> (str, errorstr); }	
S4	strtoi4	(char * str, char ** errorstr)			{ return strtoi<	S4	> (str, errorstr); }	
S8	strtoi8	(char * str, char ** errorstr)			{ return strtoi<	S8	> (str, errorstr); }	
U1	strtou1	(char * str, char ** errorstr)			{ return strtoi<	U1	> (str, errorstr); }	
U2	strtou2	(char * str, char ** errorstr)			{ return strtoi<	U2	> (str, errorstr); }	
U4	strtou4	(char * str, char ** errorstr)			{ return strtoi<	U4	> (str, errorstr); }	
U8	strtou8	(char * str, char ** errorstr)			{ return strtoi<	U8	> (str, errorstr); }	
F4	strtof4	(char * str, char ** errorstr)			{ return strtofloat (str, errorstr); }	
F8	strtof8	(char * str, char ** errorstr)			{ return strtodouble (str, errorstr); }	

void	StringToNumber(	S1	&ret, char * str, char ** errorstr)		{ ret= strtoi<	S1	> (str, errorstr); }	
void	StringToNumber(	S2	&ret, char * str, char ** errorstr)		{ ret= strtoi<	S2	> (str, errorstr); }	
void	StringToNumber(	S4	&ret, char * str, char ** errorstr)		{ ret= strtoi<	S4	> (str, errorstr); }	
void	StringToNumber(	S8	&ret, char * str, char ** errorstr)		{ ret= strtoi<	S8	> (str, errorstr); }	
void	StringToNumber(	U1	&ret, char * str, char ** errorstr)		{ ret= strtoi<	U1	> (str, errorstr); }	
void	StringToNumber(	U2	&ret, char * str, char ** errorstr)		{ ret= strtoi<	U2	> (str, errorstr); }	
void	StringToNumber(	U4	&ret, char * str, char ** errorstr)		{ ret= strtoi<	U4	> (str, errorstr); }	
void	StringToNumber(	U8	&ret, char * str, char ** errorstr)		{ ret= strtoi<	U8	> (str, errorstr); }	
void	StringToNumber(	F4	&ret, char * str, char ** errorstr)		{ ret= strtofloat (str, errorstr); }	
void	StringToNumber(	F8	&ret, char * str, char ** errorstr)		{ ret= strtodouble (str, errorstr); }	
}//	namespace NSMY {
}//	namespace NSStr {
using namespace NSMY::NSStr;

