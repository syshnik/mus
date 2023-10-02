/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
//#pragma once 
#ifndef	_pragma_once_579077
#define	_pragma_once_579077


namespace NSMY {
namespace NSType {

class SType
{
public:
	//переменные 
	union {
		U4 x;
		struct {
unsigned	x0	: 1;
unsigned	c	: 1;
unsigned	d	: 1;
unsigned	x3	: 1;
unsigned	l	: 1;
unsigned	str	: 1;
unsigned	x6	: 1;
unsigned	x7	: 1;
unsigned	x8	: 1;
unsigned	x9	: 1;
unsigned	x10	: 1;
unsigned	x11	: 1;
unsigned	x12	: 1;
unsigned	x13	: 1;
unsigned	x14	: 1;
unsigned	x15	: 1;
		};
		struct {
			U2 flages, size;
		};
	};
	
	//дуры после которых класс становится емулятором числа
	SType() { TM(x=~0); };
	SType(U4 par) { x=par; };

	operator U4 & () {	return x;	};
	SType & operator = (U4 par) {	x=par; return *this;	};
/*
SType	&	operator	 = 	(U4 par) {		x	 = 	par; return *this;		};
SType	&	operator	 -= 	(U4 par) {		x	 -= 	par; return *this;		};
SType	&	operator	 += 	(U4 par) {		x	 += 	par; return *this;		};
SType	&	operator	 *= 	(U4 par) {		x	 *= 	par; return *this;		};
SType	&	operator	 /= 	(U4 par) {		x	 /= 	par; return *this;		};
SType	&	operator	 %= 	(U4 par) {		x	 %= 	par; return *this;		};
SType	&	operator	 &= 	(U4 par) {		x	 &= 	par; return *this;		};
SType	&	operator	 |= 	(U4 par) {		x	 |= 	par; return *this;		};
SType	&	operator	 ^= 	(U4 par) {		x	 ^= 	par; return *this;		};
SType	&	operator	 >>= 	(int par) {		x	 >>= 	par; return *this;		};
SType	&	operator	 <<= 	(int par) {		x	 <<= 	par; return *this;		};
SType	&	operator	 - 	(U4 par) {		return (SType)(x		 - 	par);	};
SType	&	operator	 + 	(U4 par) {		return (SType)(x		 + 	par);	};
SType	&	operator	 * 	(U4 par) {		return (SType)(x		 * 	par);	};
SType	&	operator	 / 	(U4 par) {		return (SType)(x		 / 	par);	};
SType	&	operator	 % 	(U4 par) {		return (SType)(x		 % 	par);	};
SType	&	operator	 & 	(U4 par) {		return (SType)(x		 & 	par);	};
SType	&	operator	 | 	(U4 par) {		return (SType)(x		 | 	par);	};
SType	&	operator	 ^ 	(U4 par) {		return (SType)(x		 ^ 	par);	};
*/
};



}//	namespace NSMY {
}//	namespace NSType {
using namespace NSMY::NSType;
#endif

