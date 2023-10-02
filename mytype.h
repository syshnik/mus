/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once 
#ifndef	_pragma_once_5790710
#define	_pragma_once_5790710


namespace NSMY {
namespace NSType {
//---------------------------------------------------------------------------------------------------------------------------------
/*
format:
	кол_во индексов секторов(long) - индексы секторов - индексы - типы таблиц - таблицы
типы таблиц:
	таблица с данными типа столбец//(TABTYPE	)
таблицы:
	индексы - данные
данные:
	данные 1-го столбца,данные 2-го столбца, и т.д.
type если 1-й бит 1 то переенный размер
*/

class voidtype {
public:
	voidtype() {};
//	voidtype(voidtype par) {};
	
	voidtype(USI  par) {};
	void EmptyDur() {};
	char xxxxxxxxxxxxxxxxxxxxx;
	bool operator == (voidtype par) { A(0);		TM(par.EmptyDur()); return true; };
	bool operator != (voidtype par) { A(0);		TM(par.EmptyDur()); return 0; };
	bool operator >= (voidtype par) { A(0);		TM(par.EmptyDur()); return 0; };
	bool operator <= (voidtype par) { A(0);		TM(par.EmptyDur()); return 0; };
	bool operator > (voidtype par) { A(0);		TM(par.EmptyDur()); return 0; };
	bool operator < (voidtype par) { A(0);		TM(par.EmptyDur()); return 0; };

	bool operator == (USI  par) { A(0);		TM(par=9); return 0; };
	bool operator != (USI  par) { A(0);		TM(par=9); return 0; };
	bool operator >= (USI  par) { A(0);		TM(par=9); return 0; };
	bool operator <= (USI  par) { A(0);		TM(par=9); return 0; };
	bool operator > (USI  par) { A(0);		TM(par=9); return 0; };
	bool operator < (USI  par) { A(0);		TM(par=9); return 0; };

	USI operator = (USI par) { A(0);		TM(par=9); return 0; };
	USI operator /= (USI par) { A(0);		TM(par=9); return 0; };

	operator double () { A(0);		 return 0; };
	operator USI () { A(0);		 return 0; };
};
/*typedef struct voidtype0000000 {
	char xxxxxxxxxxxxxxxxxxxxx;
} voidtype;*/

//#include <rpcndr.h>
template <class BUFTYPE> class mas4note	{	BUFTYPE mas[4];	};
template <class BUFTYPE> class mas2note	{	BUFTYPE mas[2];	};
typedef struct movinfo00000{
	USI n, l, r;
} movinfo;
class   		EXPORT_OR_IMPPORT		macrovar
{
public:
	union {
		char for_protected_point;
		U1 u1;
		U2 u2;
		U4 u4;
		U8 u8;
		S1 s1;
		S2 s2;
		S4 s4;
		S8 s8;
		float f4;
		double f8;
		char str[256];
		UB l;
	};
	USI vr1, vr2;
	void musorim(SType type, UB mask = 255, bool bazformat = T);
};
typedef struct stolbst00000{
	USI h,type, sel;
	U2 sizenote;
} stolbst;
typedef struct plasest00000{
	bool mov, sel, l, up, in;
	USI nst, nzap, x, y;
} plasest;
typedef struct ret_2_reg0000{
	USI r1, r2;//(eax, edx)
} ret_2_reg;
typedef struct size_nsector0000{
	USI size, ns;//(eax, edx)
} size_nsector;
class  		truetype {		
public:			
	enum {	blin=1	};		
	operator bool () { return blin; };
};
class  		falsetype {		
public:			
	enum {	blin=0	};		
	operator bool () { return blin; };
};

}
}
using namespace NSMY::NSType;
#endif //pragma once

