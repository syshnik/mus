#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
// class_to_char.cpp: implementation of the baz_to_char class.
//
//////////////////////////////////////////////////////////////////////

#include "../cod_mus/stdafx.h"
#include "../cod_mus/musor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
using namespace NSMY::NSCmp;
using namespace NSMY::NSSmall;
	
/*
/////////////////////////////////////////////////////////////////////
cifra					цифры 0-9
bukva					русские и латинские буквы
simvol				любой текстовой видимый (включая пробел) символ
tbtext				simvol		+		 0x09, 0x0d, 0x0a 
namech				cifra + bukva
///////////////////////////////////////////////////////////////////
*/
#define sim(X) (		(U4)		((UB)X)			)
#define simbelong(X,X1,X2) belong(sim(X), sim(X1), sim(X2))

static 	char _bukva[256], _cifra[256], _simvol[256], _sees[256], _tbtext[256], _namech[256], _eng_bukva[256];
static 	char _wtobaz[256];
static 	char _baztow[256];
static 	char _ToBig[256];
static 	char _ToSmall[256];
static bool InitFlag=false;

namespace NSMY {
namespace NSStr {



void class_to_char::Init() {
	InitFlag=true;
	U4 n1;

	
	for(n1=0; n1<256; n1++) 
		if(simbelong(n1, '0', '9')) _cifra[n1]=n1; 
		else _cifra[n1]=0; 

	for(n1=0; n1<256; n1++) if(
		simbelong(n1, '_', '_') ||
		simbelong(n1, 'a', 'z') ||
		simbelong(n1, 'A', 'Z') 
		) _eng_bukva[n1]=n1; 
		else _eng_bukva[n1]=0; 

	for(n1=0; n1<256; n1++) if(
		simbelong(n1, '_', '_') ||
		simbelong(n1, 'ё', 'ё') || simbelong(n1, 'Ё', 'Ё') ||
		simbelong(n1, 'a', 'z') ||
		simbelong(n1, 'A', 'Z') ||
		simbelong(n1, 'а', 'я') ||
		simbelong(n1, 'А', 'Я') 
		) _bukva[n1]=n1; 
		else _bukva[n1]=0; 
	
	for(n1=0; n1<256; n1++) if(
		simbelong(n1, ' ', ' ') || simbelong(n1, '!', '~') || bukva(n1)
		) _simvol[n1]=n1; 
		else _simvol[n1]=0; 

	for(n1=0; n1<256; n1++) if(
		!simbelong(n1, ' ', ' ') && simvol(n1)
		) _sees[n1]=n1; 
		else _sees[n1]=0; 

	for(n1=0; n1<256; n1++) if(
		n1==0x09 || n1==0x0d || n1==0x0a || simvol(n1)
		) _tbtext[n1]=n1; 
		else _tbtext[n1]=0; 
	//ToBig
	for(n1=0; n1<256; n1++) 
		if(simbelong(n1, 'ё', 'ё')) _ToBig[n1]='Ё';
		else if(simbelong(n1, 'a', 'z')) _ToBig[n1]='A'+(n1-'a');
		else if(simbelong(n1, 'а', 'я')) _ToBig[n1]='А'+(n1-'а');
		else _ToBig[n1]=n1;
	//ToSmall
	for(n1=0; n1<256; n1++) 
		if(simbelong(n1, 'Ё', 'Ё')) _ToSmall[n1]='ё';
		else if(simbelong(n1, 'A', 'Z')) _ToSmall[n1]='a'+(n1-'A');
		else if(simbelong(n1, 'А', 'Я')) _ToSmall[n1]='а'+(n1-'А');
		else _ToSmall[n1]=n1;

	for(n1=0; n1<256; n1++) 
		if(cifra(n1) || bukva(n1)) _namech[n1]=n1;
		else _namech[n1]=0; 
	//------------------------------------------   
	//базовые массивы
	char * p1=_baztow;
	NSMY::NSWrite::WriteTempl<char>(newdp(_baztow, 256), 0, 256);

	*p1=0;		p1++;
	for(n1=sim('0'); n1<=sim('9'); n1++, p1++) *p1=n1;
	*p1='_';		p1++;
	for(n1=sim('a'); n1<=sim('z'); n1++, p1++) *p1=n1;
	for(n1=sim('а'); n1<=sim('я'); n1++, p1++) {
		*p1=n1;
		if(n1==sim('е')) {
			p1++;
			*p1='ё';
		}
	}
	//back
	char backstr[256], * p2=backstr;
	*p2=' ';		p2++;
	*p2='!';		p2++;
	*p2='"';		p2++;
	stringcopy(p2, "#$%&'()*+,-./:;<=>?@");
	for( ; *p2; p2++) ;
	*p2='[';		p2++;
	*p2=0x5c;		p2++;
	stringcopy(p2, "]^`{|}~");
	for( ; *p2; p2++) ;

	p1=&_baztow[128];
	p1-=strlen(backstr);
	stringcopy(p1, backstr);
	//тень БОЛЬШИЕ БУКОВКИ
	NSMY::NSCopy::CopyMem(q newdp(&_baztow[128], 128), q newdp(&_baztow[0], 128), 128);
	p1=&_baztow[128];
	for(n1=0; n1<128; n1++, p1++) {
		char & c=*p1;
		if(simbelong(c, 'a', 'z')) c='A'+(c-'a');
		else if(simbelong(c, 'а', 'я')) c='А'+(c-'а');
		else if(c=='ё') c='Ё';
	}

	//переводим wtobaz
	NSMY::NSWrite::WriteTempl<char>(newdp(_wtobaz, 256), 0, 256);
	p1=_baztow;
	for(n1=0; n1<256; n1++, p1++) {
		_wtobaz[(UB)*p1]=n1;
	}
	_wtobaz[0]=0;
#if TEST_V
	for(n1=0; n1<256; n1++) {
		U4 bch=sim(wtobaz(baztow(n1)));
		if(bch) {
			TA((bch & ~0x80) == (n1 & ~0x80));
		}
		if(simvol(n1)) {
			U4 wch=sim(baztow(wtobaz(n1)));
			TA(wch==n1);
		}
	}
#endif
}

char class_to_char::  eng_bukva(char par) { TA(InitFlag); return _eng_bukva[(UB)par]; };
char class_to_char::  bukva(char par) { TA(InitFlag); return _bukva[(UB)par]; };
char class_to_char::  cifra(char par) { TA(InitFlag); return _cifra[(UB)par]; };
char class_to_char::  simvol(char par) { TA(InitFlag); return _simvol[(UB)par]; };
char class_to_char::  sees(char par) { TA(InitFlag); return _sees[(UB)par]; };
char class_to_char::  tbtext(char par) { TA(InitFlag); return _tbtext[(UB)par]; };
char class_to_char::  namech(char par) { TA(InitFlag); return _namech[(UB)par]; };
char class_to_char::  wtobaz(char par) { TA(InitFlag); return _wtobaz[(UB)par]; };
char class_to_char::  baztow(char par) { TA(InitFlag); return _baztow[(UB)par]; };
char class_to_char::  ToBig(char par) { TA(InitFlag); return _ToBig[(UB)par]; };
char class_to_char::  ToSmall(char par) { TA(InitFlag); return _ToSmall[(UB)par]; };



}
}
//namespace NSMY {
//namespace NSStr {


