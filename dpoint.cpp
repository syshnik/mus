#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#include "../cod_mus/stdafx.h"
#include "../cod_mus/macro.h"
//#include "../cod_mus/dmas.h"
#include "../cod_mus/dpoint.h"
//#include "../cod_mus/tempc.h"
//#include "../cod_mus/defdur1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


#if TEST_P
USI point_idpoint_idpoint_id=0;
/*
charp dpointpar:: icharp(char * ch) {
	for(USI n1=0; ; n1++) if(ch[n1] == 0) break;
	n1++;
	charp ret;
	ret=newdp (ch, n1);
	return ret;
}*/



void dpointpar:: next_point_id() { point_idpoint_idpoint_id++; };
USI & dpointpar:: get_point_id() { return point_idpoint_idpoint_id; };


dpointpar::   dpointpar()  { 
	p=lp=rp=NULL; 
	next=nullid; 
	kto_oshibsy="  :)  ";
}

dpointpar dpointpar::getnotes() {
			dpointpar ret;
ret.	p		 =			p	;
ret.	lp		 =			lp	;
ret.	rp		 =			rp	;
ret.	next		 =			next	;
			return ret;
};

UUI dpointpar::getui() { return p; };
void dpointpar::setnotes(dpointpar par) {
p		 =		par.	p	;
lp		 =		par.	lp	;
rp		 =		par.	rp	;
next		 =		par.	next	;
};
void  dpointpar::settestmov() {	
	l_mov=((UUI)p-(UUI)lp)/_sizenote;
	r_mov=((UUI)rp-(UUI)p)/_sizenote;
	rivnenko=T;
	if(		((UUI)p-(UUI)lp)%_sizenote		) rivnenko=F;
	if(		((UUI)rp-(UUI)p)%_sizenote		) rivnenko=F;
};
void  dpointpar::testpoint(USI  tsize) {	
	settestmov();
	UUI ok=0;
	if(tsize != _sizenote) ok=11111;
	/////////////////////next/////////////////////////////////////
	realnext=get_point_id();
	if(next!=nullid) if(next!=get_point_id()) ok=22222;
	/////////////////////ard//////////////////////////////////////
	if(p < lp) ok=33333;
	if(p+_sizenote > rp ) ok=44444; 
	if(ok) {
		kto_oshibsy="ето я";
		TA(0);
	}
};
void dpointpar::setkry(USI lkry, USI rkry)
{
	lkry*=_sizenote;		rkry*=_sizenote;
	TA(lkry<=rkry);
	USI lp1=p-lkry, rp1=p+rkry;
	TA(lp<=lp1 && rp>=rp1);
	
	lp=lp1;			rp=rp1;
	settestmov();
};
#endif
