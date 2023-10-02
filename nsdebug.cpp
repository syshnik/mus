#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#include "../cod_mus/stdafx.h"
#include "../cod_mus/musor.h"
#include "../cod_mus/nsdebug.h"
#include <time.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

namespace NSMY {
namespace NSDebug {

U4 next_for_randmassiv, save_next_for_randmassiv;

void SeveNextRand() { save_next_for_randmassiv = next_for_randmassiv; }
void ReadNextRand() { next_for_randmassiv = save_next_for_randmassiv; }
void SetNextRand(U4 next) { next_for_randmassiv = next; }
U4 GetNextRand() { return next_for_randmassiv; }

U4 Rand() {
				return(((next_for_randmassiv = next_for_randmassiv * 214013L
						+ 2531011L) >> 16) & 0x7fff );
}
U4 RandWidthTime() {
	return Rand()*(((U4)time(NULL)) % 60);
}

U4 Rand(U4 par) {
				return(((par = par * 214013L
						+ 2531011L) >> 16) & 0x7fff );
}
bool RandTrue(U4 in, U4 from) {
	//дура возвращает случайную правду с вероятностью in/from
	if(in > from)					return !RandTrue(from, in);
	else if(in == from)		return (Rand()%10 > 0);
	else									return (Rand()%from < in);
}


RunTime::RunTime() {
	init();
}
void RunTime::init() { 
	nulltime=clock(); next=0; 
	for(USI n1=0; n1<_maxstr_; n1++) {
		chm[n1]="нету";
		timem[n1]=0;
	}
}

int RunTime::srez(char * ch) {
	next++;
	return srez(next-1, ch);
}

int RunTime::srez(int nom, char * ch) {
	TA(nom<_maxstr_);
	int & time	=		timem[nom];
	time			+=	clock()-nulltime;
	(chm[nom]="") << time;
	if(ch) chm[nom] << "        " << ch;
	nulltime=clock();
	return time;
}
U4 NextRand(U4 next, U4 sikoko)
{
	U4 rm[4]={1, 2, 0, 3};
	TA(next<sikoko);
	U4 maxn=(sikoko/4)*4; 
	if(next < maxn) return (next/4)*4+rm[next%4];
	else return next;
}

#if TEST_V
void testadrsik(USI mynzap, USI adr, USI sik)
{
	TA(mynzap >= adr);
	TA(mynzap >= sik);
	TA(mynzap >= adr+sik);
}
#endif
}//namespace NSMY
}//namespace NSDebug
