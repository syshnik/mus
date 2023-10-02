/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/

/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_579076
#define	_pragma_once_579076


#if TEST_P
	#define NEWPOINTTYPE(TT,PTT) typedef		dpoint< TT >		 PTT; 
	#define SNEWPOINTTYPE(TT,PTT) typedef		sdpoint< TT >		 PTT; 
	#define GETPOINTTYPE(TT) 		dpoint< TT > 
	#define GETPOINTTYPE_TT 		dpoint< TT > 
#else
	#define NEWPOINTTYPE(TT,PTT) typedef		TT	*	 PTT; 
	#define SNEWPOINTTYPE(TT,PTT) typedef		TT	*	 PTT; 
	#define GETPOINTTYPE(TT) 		TT *
	#define GETPOINTTYPE_TT 		TT *
#endif


#if TEST_P

#define rdp(P) (P).p

class				 	dpointpar {
	private:
public:
	enum {
		nullid = 1000000000
	};
	char * kto_oshibsy;
	UUI l_mov, r_mov, rivnenko, _sizenote;
	UUI lp, p, rp;
	USI  next, realnext;

	dpointpar();
	dpointpar getnotes();
	UUI getui();// { return p; };
	void setnotes(dpointpar par);
	void  settestmov();// {	
	void  testpoint(UUI  tsize);// {	
	void setkry(UUI lkry, UUI rkry);//
#if TEST_V
	void next_point_id();
	UUI & get_point_id();
#endif
};
template <class TT> UUI realpoint (TT p, USI sik, bool up) {
	USI ret=0;
	if(sik) {
		if(up) {
			p-=sik;
			*p;
			p[sik-1];
			p+=sik;
		} else {
			*p;
			p[sik-1];
		}
		ret=p.getui();
	}
	return ret; 
};

#define TTPOINT 1
			#include "../cod_mus/dpoint_h.h"	
		//	#include "../cod_mus/dpoint_cpp.h"	
#define TTPOINT 1
#define STRELA 1
			#include "../cod_mus/dpoint_h.h"	
		//	#include "../cod_mus/dpoint_cpp.h"	
#undef TTPOINT 	

template <class TT> dpoint<TT> t_newdp(TT * par, USI lmov=0, USI rmov=1) {
//dpoint newdp(dpoint::ST * par, USI lmov=0, USI rmov=1) {
	lmov*=sizeof(TT);
	rmov*=sizeof(TT);
	dpoint<TT> ret;
	ret.p=(UUI)par;
	ret.rp=ret.p+rmov;
	ret.lp=ret.p-lmov;
	ret.settestmov();
	return ret;
};
 template <class TT>  dpoint<TT> newdp(TT * par);
 template <class TT>  dpoint<TT> newdp(TT * par, UUI rmov);
 template <class TT>  dpoint<TT> newdp(TT * par, UUI lmov, UUI rmov);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#else								
	template <class TT>  TT *  newdp(TT * par) { return par; };
	template <class TT>  TT *  newdp(TT * par, UUI rmov) { return par; };
	template <class TT>  TT *  newdp(TT * par, UUI lmov, UUI rmov) { return par; };
	#define rdp(P)	UIPO(P)
	//#define newdp(P)	P
#endif								
						

NEWPOINTTYPE(		U1	,	U1P	)
NEWPOINTTYPE(		U2	,	U2P	)
NEWPOINTTYPE(		U4	,	U4P	)
NEWPOINTTYPE(		U8	,	U8P	)
NEWPOINTTYPE(		S1	,	S1P	)
NEWPOINTTYPE(		S2	,	S2P	)
NEWPOINTTYPE(		S4	,	S4P	)
NEWPOINTTYPE(		S8	,	S8P	)
NEWPOINTTYPE(		UB	,	UBP	)
NEWPOINTTYPE(		UUI	,	UUIP	)
NEWPOINTTYPE(		F4	,	F4P	)
NEWPOINTTYPE(		F8	,	F8P	)
NEWPOINTTYPE(		NSMY::NSType::voidtype	,	anyp	)
NEWPOINTTYPE(		char	,	charp	)
								
								
#if TEST_V
	template<class TT> void testpoint(GETPOINTTYPE(TT) kup, USI sik, USI strsize = MAXUSI)
	{
		if(sik == 0) return;
		if(strsize != MAXUSI) sik*=strsize;
		TT	note1 = kup[0];
		TT	note2 = kup[sik-1];
	};
#endif
							
#if TEST_P 

	inline anyp newdp() { return newdp((voidtype *)NULL); };

#endif
#define q (anyp)
template<class TT> anyp getanyp(TT & note) { return newdp((voidtype *)&note, sizeof(note)); };

#endif //pragma once



