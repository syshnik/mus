#include "stdafx.h"
/*—айт "«аводила" © —афаров ќлег јйратович 2014 г. инн 027304982940*/
/*BlackBase © —афаров ќлег јйратович 2001 г. инн 027304982940*/
// musor.cpp: implementation of the musor class.
//
//////////////////////////////////////////////////////////////////////

#include "../cod_mus/stdafx.h"
//#include "../cod_mus/ok.h"
#include <math.h>
#include <stdlib.h>
//#include "../cod_mus/Windows.h"

#include "../cod_mus/musor.h"
//#include "../cod_mus/musor.h" 
#include "../cod_mus/in_for_file_work.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

using namespace NSMY;
using namespace NSMY::NSCmp;
using namespace NSMY::NSSmall;
using namespace NSMY::NSType;
using namespace NSMY::NSStr;
using namespace NSMY::NSOld;

/*
struct A {};
struct B : A {};
struct X {};
struct D : B, X {};
void operator+( X, X );
void operator+( A, B );
D d;
int main()
{
   d +  d;         // C2593, D has an A, B, and X 
   (X)d + (X)d;    // OK, uses operator+( X, X )
*/

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
char *	StaticPointForDebug_NotesPoint=NULL;


#define BEGSIKL(MET) __asm cmp ecx, 0		__asm	je MET

#if !defined TEST_P
	#define ku	kup 
	#define ot	otp 
#endif
		//ret
void qbigobmen(void * kup, USI size1, USI size2)
{
	bigobmen((anyp) newdp((char *)kup, size1+size2), size1, size2);
}
void qbigobmen(void * kup, USI size1, USI size2, USI size3)
{
	bigobmen((anyp) newdp((char *)kup, size1+size2+size3), size1, size2, size3);
}
void NSMY::NSOld::bigobmen(anyp kup, USI size1, USI size2)
{
 //дура обменивает 2 р€дом сто€щие переменные разного размера
 //используетс€ при сортировке
 dmas1<voidtype,  256> buf;
#if TEST_V 
 USI size11=NSMY::NSDebug::Rand()%100+1;
	#define  SIZEBUF4 size11
#else
	#define SIZEBUF4 256
#endif
 anyp lp, rp;
 lp=kup;
 rp=kup+size1;
 while(size2) {
	 USI size=min((USI)SIZEBUF4, size2);
	 size2-=size;
	 NSMY::NSCopy::CopyMem(buf.ppp(0), rp, size);
	 NSMY::NSCopy::CopyMem(lp+size, lp, size1);
	 NSMY::NSCopy::CopyMem(lp, buf.ppp(0), size);
	 lp+=size;
	 rp+=size;
 }
}

void NSMY::NSOld::bigobmen(anyp p, USI sik1, USI sik2, USI sik3)
{
	//l	s	r
	NSMY::NSOld::bigobmen(p+sik1, sik2, sik3);
	obmen(sik2, sik3);
	//l	r	s
	NSMY::NSOld::bigobmen(p, sik1, sik2);
	obmen(sik1, sik2);
	//r	l	s
	NSMY::NSOld::bigobmen(p+sik1, sik2, sik3);
	//r	s	l
}
bool test_one_note_in_bool_massiv(UBP bytep, USI sik)
{//возвращает 1 если все (не 0) байты массива равны
	//find not null
	UB byte;
	for( ; sik>0; sik--, bytep++) if(*bytep) {
		byte=*bytep; 
		break; 
	}
	//найдем не равный байт
	for( ; sik>0; sik--, bytep++) if(*bytep) { 
		if(byte != *bytep) return F; 
	}
	return T;
}

bool some_test_one_note_in_bool_massiv(UBP bytep, USI shag, USI sik)
{//возвращает 1 если все (не 0) байты массива равны
	//find not null
	UB byte;
	for( ; sik>0; sik--, bytep+=shag) if(*bytep) {
		byte=*bytep; 
		break; 
	}
	//найдем не равный байт
	for( ; sik>0; sik--, bytep+=shag) if(*bytep) { 
		if(byte != *bytep) return F; 
	}
	return T;
}
size_nsector get_s_size(USI sum, USI maxs)
{	//определ€ет мин-й средний размер сектора
	//чтоб ћ»Ќ»ћјЋ№Ќќ≈ кол-во секторов вместили всю сумму
	size_nsector ret;
	if(!sum) {//пустое
		TM(ret.size=454545);
		ret.ns=0;
		return ret;
	}
	ret.ns=deli( sum, maxs);
	USI mins=sum/ret.ns;
	while(mins!=maxs) {
		if(mins+1==maxs) {
			if(mins*ret.ns >= sum) maxs=mins;
			else mins=maxs;
		}	else {
			USI s2=mins+(maxs-mins)/2;
			if(s2*ret.ns >= sum) maxs=s2;
			else mins=s2;
		}
	}
	TA((mins-1)*ret.ns < sum && mins*ret.ns >= sum && mins==maxs);
	ret.size=maxs;
	return ret;
}
void deltab_fromstr(char *  ch)
{
	for( ; *ch; ch++) {
		if(*ch==9) *ch=' ';
	}
}
USI uvelichim(USI par, USI mulstep, USI delstep, USI maxret) {
	double step=mulstep;		step/=delstep;
	return min( (USI)pow((double)par, step), maxret);
}
void wrightmus(anyp ku, SType type, UB mask, USI mov, USI sik) {
	macrovar mv;
	mv.musorim(type, mask);
	if(!type.l) NSWrite::WriteMemMovku(ku, (anyp)newdp(&mv), mov, type.size, sik);
	else NSWrite::WriteBitMovku((UBP)ku, mv.l, mov, mask, sik);
}
USI SikTrue(UBP notep, USI sik) {
	USI ret=0;
	for( ; sik>0;		sik--, notep++) if(*notep) ret++;
	return ret;
}


#if TEST_V

void call_error_met() {
	abort();
}

UUI UIPO(void * point) {
	return (UUI)point;
}


void tvtestflag(UUI flagp)
{
	bool one=T;
	for(UUI mask11=1 ; mask11!=0; mask11*=2) {
		if(one) {
			if((flagp&mask11) ==0) one=F;
		} else {
			TA((flagp&mask11) ==0); 
		}
	}
}

#endif

void new_nzap_sik(USI & nzap, USI & sik, USI thisnzap, USI maxnzap) {
	nzap=NSMY::NSDebug::Rand()%(thisnzap+1);
	sik=NSMY::NSDebug::Rand()%(minusss((USI)maxnzap, (USI)thisnzap)+1);
}
void del_nzap_sik(USI & nzap, USI & sik, USI thisnzap) {
	sik=NSMY::NSDebug::Rand()%(thisnzap+1);
	nzap=NSMY::NSDebug::Rand()%(minusss((USI)thisnzap, (USI)sik)+1);
}




void macrovar::musorim(SType type, UB mask, bool bazformat)
{
	switch((U4)type) {
case (	C_ST	|	1	*0x10000) :			s1	 = 	44	;	break;
case (	C_ST	|	2	*0x10000) :			s2	 = 	4444	;	break;
case (	C_ST	|	4	*0x10000) :			s4	 = 	444444	;	break;
case (	C_ST	|	8	*0x10000) :			s8	 = 	44444444	;	break;
case (	D_ST	|	4	*0x10000) :			f4	 = 	555555	;	break;
case (	D_ST	|	8	*0x10000) :			f8	 = 	55555555	;	break;
case (	L_ST	|	1	*0x10000) :			u1	 = 	255	;	break;
default:				TA(type.str);		
	NSWrite::WriteTempl<U1> ((U1P)newdp(str, 256), '*', type.size);
	str[type.size-1]=0;									
	if(bazformat) stringcopy((bazchar *)str, str);
	}
}





void stop_if_not_true(bool par, char * filename, int line, char * SaveErrorFile) 
{
	if(par) return;
	if(SaveErrorFile) {
		//удалим файл
		char * file=SaveErrorFile;
		cfstr str, del;
		#ifdef WIN_OPERACION_SYSTEM
		del << "del " << "\"" << file << "\"";
		#ifdef WIN_OPERACION_SYSTEM
		for(char * p1=(char *)del; *p1; p1++) if(*p1 == '/') *p1 = '\\';
		#endif
		del  << " /q /f /f";
		#endif
		#ifdef UNIX_OPERACION_SYSTEM
		del << "rm " << "" << file << " -f";
		#endif
		system(del);
		//запись
		str << (char *)"file: ";
		str << filename;
		str << (char *)"\nstring: ";
		str << line;
		str << (char *)"\n";
		if(StaticPointForDebug_NotesPoint) str << StaticPointForDebug_NotesPoint << "\n";
		if(FILE * f = fcnSMacro_fopen_s(file, "w")) {
			fwrite(str, sizeof(char), strlen(str), f);
			fclose(f);
		} 
	}
	abort();
}

