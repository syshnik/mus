/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_579075
#define	_pragma_once_579075


namespace NSMY {
namespace NSSmall {

class 			dmastest {
public:
	void test(USI n1, USI s1) {
		TA(n1<s1);
	};
	void test(U8 n1, U8 s1) {
		TA(n1>=0 && n1<(U8)s1);
	};
};


template <class TT, USI s>
 class dmas1	  : public dmastest {
public:
	NEWPOINTTYPE(TT,TTP)
	TT m[s];

	USI sik() { return s; };
//ST_V	//USI _size;	dmas1<TT, s> () { };//_size=sizeof(TT); };#endif
	TT& operator [] (USI n) {	test(n, s);	return m[n];	};
	TTP ppp(USI n) {
		test(n, s);
		//return initdp(TTP, &m[n], n, s-n, dpoint<char> :: nullid);
		return newdp(&m[n], n, s-n);
	};
	TTP ppp(int n) { return ppp((USI) n); };
	//TT& operator [] (U8 n) {	test(n, s);	return m[n];	};
	//TTP ppp(U8 n) {		test((USI)n, s);		return newdp(&m[n], n, s-n);	}; 
	TTP  operator + (USI n) {	return ppp(0)+n;	};
	TTP  operator + (U8 n) {	return ppp(0)+n;	};
};

/*


del c:\Util\Programm\prvc6_dll_all\test_dlls\prvc6_dll_mus.dll
copy c:\Util\Programm\prvc6_dll_mus\Debug\prvc6_dll_mus.dll c:\Util\Programm\prvc6_dll_all\test_dlls\prvc6_dll_mus.dll



del c:\Util\Programm\prvc6_dll_all\test_libs\pr_dll_mus.lib
copy c:\Util\Programm\prvc6_dll_mus\Debug\prvc6_dll_mus.lib c:\Util\Programm\prvc6_dll_all\test_libs\pr_dll_mus.lib


*/

/*#ifndef VISUALCPP6
template <class TT, USI s1, USI s2> class dmas2  : public dmastest {
  public:
#if TEST_V
	USI see_s1, see_s2;
	dmas2<TT, s1, s2> () {
		see_s1 = s1;
		see_s2 = s2;
	};
	TT mm[s1][s2];
#endif
	dmas1<TT, s2>	m[s1];
	NEWPOINTTYPE(TT,TTP)

	dmas1<TT, s2> & operator [] (USI n) {	
		see(); test(n, s1);	
		return m[n];	
	};
	TTP ppp(USI n1, USI n2) {
		see(); test(n1, s1);
		return m[n1].ppp(n2);
	};
	dmas1<TT, s2> & operator [] (USI n) {	
		see(); test(n, s1);	
		return m[n];	
	};
	TTP ppp(USI n1, USI n2) {
		see(); test(n1, s1);
		return m[n1].ppp(n2);
	};
	
	void see() {
#if TEST_V
		for(USI n1=0; n1<s1; n1++) {
			for(USI n2=0; n2<s2; n2++) {
				mm[n1][n2]=m[n1].m[n2];
			}
		}
#endif
	};
};

#endif

*/
#if TEST_V
	#define   NOTE_MASSIV_X(TT,X,NAME)      dmas1<TT, X> NAME;
	#define   NOTE_MASSIV_X_Y(TT,Y,X,NAME)      dmas2<TT, Y, X> NAME;
#else
	#define   NOTE_MASSIV_X(TT,X,NAME)      TT NAME[X];
	#define   NOTE_MASSIV_X_Y(TT,Y,X,NAME)      TT NAME[Y][X];
#endif

template <class TT, USI nel> class stek_class  {
  public:
	NOTE_MASSIV_X(TT, nel, m);
	USI np;
	USI sik() { return np; };
	USI sikmax() { return nel; };
	bool fool() { return (np == nel); };
	stek_class  <TT, nel> () {	np=0; };
	stek_class  <TT, nel>  & operator << (TT par) {
		m[np]=par;
		np++;
		return *this;
	};
	stek_class  <TT, nel>  & operator >> (TT & par) {
		np--;
		par=m[np];
		return *this;
	};
	TT & operator [] (USI nom) {
		TA(nom < np);
		return m[nom];
	};
};

class NullClass {};



}//namespace NSMY {
}//namespace NSSmall {
using namespace NSMY::NSSmall;
#endif //pragma once



