/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/

#ifndef hhhhhhhhhhhhhhhhhhhh8370897342387
#define hhhhhhhhhhhhhhhhhhhh8370897342387 piska
#include <stdlib.h>


namespace NSMY {
namespace NSSmall {

template <class TT> class CmpClassOnVirtual
{
public:
	NEWPOINTTYPE(TT,TTP)
	bool bo(TTP left, TTP right) { return Menshe(right, left); };
	bool r(TTP left, TTP right) { return (!Menshe(right, left) && !Menshe(left, right)); };
	bool me(TTP left, TTP right) { return Menshe(left, right); };
	bool mer(TTP left, TTP right) { return !Menshe(right, left); };
	bool bor(TTP left, TTP right) { return !Menshe(left, right); };
	virtual bool Menshe(TTP left, TTP right) { return true; };
};
template <class TT> class SortFindClassOnVirtual : public CmpClassOnVirtual<TT>
{
public:
	NEWPOINTTYPE(TT,TTP)
	void Sort(TTP p1, USI count) {
		for(bool find=true; find; ) {
			find=false;
			for(USI n1=1; n1<count; n1++) {
				if(bo(&p1[n1-1], &p1[n1])) {
					Obmen(&p1[n1-1], &p1[n1]);
					find=true;
				}
			}
		}
	};
	bool TestOrder(TTP p1, USI count) {
		for(USI n1=1; n1<count; n1++) if(bo(&p1[n1-1], &p1[n1])) return false;
		return true;
	};
	USI Find(GETPOINTTYPE(TT) NoteP, GETPOINTTYPE(TT) MassivP, USI Count, bool LeftKray=false, bool RightKray = false)
	{
		//пїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
		#define FindNote_Mac_Move_Left	{ right=left-left/2; left/=2; }
		#define FindNote_Mac_Move_Right	{ left=right/2; right=right-right/2; }
		//-------------------------------------------------------
		TA(TestOrder(MassivP, Count));
		USI left=Count/2, right=Count-Count/2;
		GETPOINTTYPE(TT) p1;
		for(p1=MassivP; left; ) {
			if(me(NoteP, &p1[left])) {
				FindNote_Mac_Move_Left;
			} else if(bo(NoteP, &p1[left])) {
				p1+=left;
				FindNote_Mac_Move_Right;
			} else if(LeftKray && r(NoteP, &p1[left]) && r(NoteP, &p1[left-1])) {
				FindNote_Mac_Move_Left;
			} else if(RightKray && r(NoteP, &p1[left])) {
				p1+=left;
				FindNote_Mac_Move_Right;
			} else {
				p1+=left;
				break;
			}
		}
		return (rdp(p1)-rdp(MassivP))/sizeof(TT);
		#undef FindNote_Mac_Move_Left
		#undef FindNote_Mac_Move_Right
	};
	virtual void Obmen(TTP left, TTP right) { obmen(*left, *right); };
};

/*
example
class c1 : public SortFindClassOnVirtual<int> {
public:
	virtual void Obmen(TTP left, TTP right) { obmen(*left, *right); };
	virtual bool Menshe(TTP left, TTP right) { return *left < *right; };
};*/

template<class TT> bool TestOrderMassivOnTemplate(GETPOINTTYPE(TT) MassivP, USI Count)
{
	for(USI n1=1; n1<Count; n1++) if(MassivP[n1-1] > MassivP[n1]) return false;
	return true;
}
template<class TT> USI FindNoteInOrderMassivOnTemplate(GETPOINTTYPE(TT) NoteP, GETPOINTTYPE(TT) MassivP, USI Count, bool LeftKray=false, bool RightKray = false)
{
	//пїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
	#define FindNote_Mac_Move_Left	{ right=left-left/2; left/=2; }
	#define FindNote_Mac_Move_Right	{ left=right/2; right=right-right/2; }
	//-------------------------------------------------------
	TA(TestOrderMassivOnTemplate(MassivP, Count));
	USI left=Count/2, right=Count-Count/2;
	GETPOINTTYPE(TT) p1;
	for(p1=MassivP; left; ) {
		if(*NoteP < p1[left]) {
			FindNote_Mac_Move_Left;
		} else if(*NoteP > p1[left]) {
			p1+=left;
			FindNote_Mac_Move_Right;
		} else if(LeftKray && *NoteP == p1[left] && *NoteP == p1[left-1]) {
			FindNote_Mac_Move_Left;
		} else if(RightKray && *NoteP == p1[left]) {
			p1+=left;
			FindNote_Mac_Move_Right;
		} else {
			p1+=left;
			break;
		}
	}
	return (rdp(p1)-rdp(MassivP))/sizeof(TT);
	#undef FindNote_Mac_Move_Left
	#undef FindNote_Mac_Move_Right
}
template<class TT> void SortMassivOnTemplate(GETPOINTTYPE(TT) p1, USI count) {
	for(bool find=true; find; ) {
		find=false;
		for(USI n1=1; n1<count; n1++) {
			if(p1[n1-1] > p1[n1]) {
				obmen(p1[n1-1], p1[n1]);
				find=true;
			}
		}
	}
};


OK_EXTERN bool OneTrue(bool n1=0, bool n2=0, bool n3=0, bool n4=0, bool n5=0);
OK_EXTERN U4 SikTrue(bool n1=0, bool n2=0, bool n3=0, bool n4=0, bool n5=0);
OK_EXTERN void iskluchilka(char * ch);
OK_EXTERN int GetProportionNote(int Numerator, int Denominator, int Note);

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
template<class TT> void Correct_LeftBOR_RightME(TT & par, TT beg, TT end) {
	if(par < beg) par=beg;
	if(par >= end) par = (end > beg ? end-1 : beg);
}

template<class TT> void obmen (TT &x, TT &y) { TT save=x; x=y; y=save; }
//пїЅпїЅ
template<class TT> TT getbit (U4 nom) {
	TA(nom < sizeof(TT)*8);
	TT bit=1;
	bit <<= nom;
	return bit;
}

template<class TT> U4 getnbit (TT x) {
	U4 nbit=0;
	TT bit=1;
	for(U4 n1=sizeof(TT)*8; n1>0; n1--) { if(x&bit) nbit++; bit*=2; }
	return nbit;
}
template<class TT> void CirclingMassiv(GETPOINTTYPE(TT) mp, USI sik) {
	for(USI n=0; n < sik/2; n++) obmen(mp[n], mp[sik-n-1]);
}
template<class TT> void setifme(TT & ku, TT ot) { if(ku < ot) ku=ot; }
template<class TT> void setifbo(TT & ku, TT ot) { if(ku > ot) ku=ot; }
template<class TT> void setifmer(TT & ku, TT ot) { if(ku <= ot) ku=ot; }
template<class TT> void setifbor(TT & ku, TT ot) { if(ku >= ot) ku=ot; }
template<class TT> void setifr(TT & ku, TT ot) { if(ku == ot) ku=ot; }
template<class TT> void setifnr(TT & ku, TT ot) { if(ku != ot) ku=ot; }
template<class TT> void SetifDucted(bool RightToLeft, TT & left, TT & right) { if(RightToLeft) left=right; else right=left; }
template<class TT> void SetAnother(TT & ku, TT one, TT two) { if(ku == one) ku=two; else ku=one; }

inline void setformask(UB & note, UB par, UB mask) {
	if(par) note |= mask;
	else note &= ~mask;
};

template<class TT>  void xorset(TT & note, TT par) {
	TA(note != par);
	note=par;
};

template<class TT> TT null_del(TT note, TT sik)
{
	if(!note) return note;
	return note/sik;
};
template<class TT> void TTT(TT & note)
{
	TA(!note);
	note=T;
};
template<class TT> void FFF(TT & note)
{
	TA(note);
	note=F;
};

template<class TT> TT plusss (TT x, TT y) { 
	if(x >= 0   &&   y >= 0) TA((x+y) >= 0   &&   (x+y) >= x);
	if(x <= 0   &&   y <= 0) TA((x+y) <= 0   &&   (x+y) <= x);
	// пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ пїЅпїЅпїЅ
	return (x+y);
}

#if TEST_V
	template<class TT> TT minusss(TT x, TT y) { 
		if(y > 0) TA(x > x-y);
		if(y < 0) TA(x < x-y);
		return (x-y);
	}
#else
	#define minusss(XXX,YYY) ((XXX)-(YYY))
#endif

OK_EXTERN void call_error_met();
template <class TT> TT er(TT ret) {
	TM(call_error_met());
	return ret;
}
template<class TT> TT deli (TT x, TT y) {
	TT ret=x/y; if(x%y) ret++; 
	TA(ret == (x/y+(x%y!=F)) );
	return ret; 
}
OK_EXTERN
USI get_adress_from_matrix(						
USI	n1	 =0,	USI	s1	 =1	,
USI	n2	 =0,	USI	s2	 =1	,
USI	n3	 =0,	USI	s3	 =1	,
USI	n4	 =0,	USI	s4	 =1	,
USI	n5	 =0,	USI	s5	 =1	);

template<class TT> TT abs(TT p1) { return (p1 < 0 ? p1*(-1) : p1); };

template<class TT> U4 sikbit(TT note)
{
	TT bit=-1;		TA(bit>=0);		bit=1;
	U4 ret=0;
	for( ; bit!=0; bit*=2) if(note&bit) ret++;
	return ret;
};
inline bool _xor(bool note1, bool note2)
{
	if(note1 && note2) return F;
	if(!note1 && !note2) return F;
	return T;
};

inline bool _mer(bool note1, bool note2)
{
	if(note1) note1=1;	if(note2) note2=1;
	return (note1 <= note2);
};

template <class TT> void randwright(TT & note) {
	UB * p1=(UB *)&note;
	for(USI n1=0; n1<sizeof(TT); n1++, p1++) *p1=Rand();
};


template <class TT> TT	strtoi	(char * str, char ** errorstr=NULL) {

	char * savep=str, * error100;
	if(!errorstr) errorstr=&error100;
#ifdef WIN_OPERACION_SYSTEM
	S8 x1=_strtoi64(str, errorstr , 10);
#endif
#ifdef UNIX_OPERACION_SYSTEM
	long long x1 = strtoll(str, errorstr , 10);
#endif
	return x1;
};
extern float	strtofloat	(char * str, char ** errorstr=NULL) ;

extern double	strtodouble	(char * str, char ** errorstr=NULL) ;


inline	float	GetMaxValue	(	float	TypeNote) { TM(TypeNote=9); return 		3.4E38										; }
inline	float	GetMinValue	(	float	TypeNote) { TM(TypeNote=9); return 		3.4E38										; }
inline	double	GetMaxValue	(	double	TypeNote) { TM(TypeNote=9); return 		1.7E308										; }
inline	double	GetMinValue	(	double	TypeNote) { TM(TypeNote=9); return 		1.7E308										; }
inline	U1	GetMaxValue	(	U1	TypeNote) { TM(TypeNote=9); return 		0xff										; }
inline	U2	GetMaxValue	(	U2	TypeNote) { TM(TypeNote=9); return 		0xffff										; }
inline	U4	GetMaxValue	(	U4	TypeNote) { TM(TypeNote=9); return 		0xffffffff										; }
inline	U8	GetMaxValue	(	U8	TypeNote) { TM(TypeNote=9); return 		MAXU8										; }
inline	S1	GetMaxValue	(	S1	TypeNote) { TM(TypeNote=9); return 		(	0xff	/	2	)						; }
inline	S1	GetMinValue	(	S1	TypeNote) { TM(TypeNote=9); return 		(	0xff	/	2		+		1		)	; }
inline	S2	GetMaxValue	(	S2	TypeNote) { TM(TypeNote=9); return 		(	0xffff	/	2	)						; }
inline	S2	GetMinValue	(	S2	TypeNote) { TM(TypeNote=9); return 		(	0xffff	/	2		+		1		)	; }
inline	S4	GetMaxValue	(	S4	TypeNote) { TM(TypeNote=9); return 		(	0xffffffff	/	2	)						; }
inline	S4	GetMinValue	(	S4	TypeNote) { TM(TypeNote=9); return 		(	0xffffffff	/	2		+		1		)	; }
inline	S8	GetMaxValue	(	S8	TypeNote) { TM(TypeNote=9); return 		(	MAXU8	/	2	)						; }
inline	S8	GetMinValue	(	S8	TypeNote) { TM(TypeNote=9); return 		(	MAXU8	/	2		+		1		)	; }


class   		EXPORT_OR_IMPPORT		BoolPerebor {
	//пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ
	//for(BoolPerebor bp(3, 2, 1, 4); bp.mono(); bp.next()) ;
private:
		USI _sik, sikm[10];
public:
		bool _monoflag;
		int m[10];
		BoolPerebor(int sik
								,	int		sik0	 = 	2				
								,	int		sik1	 = 	2				
								,	int		sik2	 = 	2				
								,	int		sik3	 = 	2				
								,	int		sik4	 = 	2				
								,	int		sik5	 = 	2				
								,	int		sik6	 = 	2				
								,	int		sik7	 = 	2				
								,	int		sik8	 = 	2				
								,	int		sik9	 = 	2				
			);
		void begin();
		bool mono();
		void next();
		void next(USI nom);
		void test();
};
OK_EXTERN int BukvaVCifru(char b);


}//	namespace NSMY {
}//	namespace NSSmall {
using namespace NSMY::NSSmall;
using namespace std;
#endif

