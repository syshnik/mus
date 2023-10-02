#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#include "../cod_mus/stdafx.h"
#include "../cod_mus/musor.h"
#include "../cod_mus/nssmall.h"
/*
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
*/
namespace NSMY {
namespace NSSmall {
float	strtofloat	(char * str, char ** errorstr) {

	char * savep=str, * error100;
	if(!errorstr) errorstr=&error100;
#ifdef WIN_OPERACION_SYSTEM
	float x1=strtod(str, errorstr );
#endif
#ifdef UNIX_OPERACION_SYSTEM
	float x1=strtof(str, errorstr );
#endif
	return x1;
};


double	strtodouble	(char * str, char ** errorstr) {

	char * savep=str, * error100;
	if(!errorstr) errorstr=&error100;
	double x1=strtod(str, errorstr );
	return x1;
};

bool OneTrue(bool n1, bool n2, bool n3, bool n4, bool n5)
{
	return (1 == SikTrue( n1,  n2,  n3,  n4,  n5));
}

U4 SikTrue(bool n1, bool n2, bool n3, bool n4, bool n5)
{
	U4 ret=0;
	if(n1) ret++;
	if(n2) ret++;
	if(n3) ret++;
	if(n4) ret++;
	if(n5) ret++;
	return ret;
}

void iskluchilka(char * ch) {
	throw(ch);
}


BoolPerebor::BoolPerebor(int sik
						,	int		sik0
						,	int		sik1
						,	int		sik2
						,	int		sik3
						,	int		sik4
						,	int		sik5
						,	int		sik6
						,	int		sik7
						,	int		sik8
						,	int		sik9
	) {
	_sik=sik;			TA(_sik <= 10);				

	sikm[	0	]=	sik0	;				
	sikm[	1	]=	sik1	;				
	sikm[	2	]=	sik2	;												
	sikm[	3	]=	sik3	;												
	sikm[	4	]=	sik4	;												
	sikm[	5	]=	sik5	;												
	sikm[	6	]=	sik6	;												
	sikm[	7	]=	sik7	;												
	sikm[	8	]=	sik8	;												
	sikm[	9	]=	sik9	;												

	begin();
};
					

void BoolPerebor::begin() {	
	USI n1;
	for(n1=0; n1<10; n1++) m[n1]=0;
	for(n1=0; n1<_sik; n1++) if(sikm[n1] == 0) break;
	_monoflag = (n1 == _sik);
};
bool BoolPerebor::mono() { return _monoflag; };
void BoolPerebor::next() { next(_sik-1); };
void BoolPerebor::next(USI nom) {
	m[nom]++;
	if(m[nom] >= sikm[nom]) {
		if(nom > 0) {
			next(nom-1);
			if(_monoflag) m[nom]=0;
		} else _monoflag=F;
	}
};
void BoolPerebor::test() {
	int m1[2][1][4], m2[2][1][4], next=0;
	{//заполнение 1-го массива
		for(int n2=0; n2<2; n2++) {
			for(int n1=0; n1<1; n1++) {
				for(int n4=0; n4<4; n4++) {
					m1[n2][n1][n4]=next;
					next++;
				}
			}
		}
	}////////////////////////////////////////////////////////
	{//заполнение 2-го массива
		next=0;
		BoolPerebor bp(3, 2, 1, 4);
		int & n2 = bp.m[0], & n1 = bp.m[1], & n4 = bp.m[2];
		for(; bp.mono(); bp.next()) {
			m2[n2][n1][n4]=next;
			next++;
		}
		TA(n2==2 && n1==1 && n4==4);
	}////////////////////////////////////////////////////////
	{//сравнение
		for(int n2=0; n2<2; n2++) {
			for(int n1=0; n1<1; n1++) {
				for(int n4=0; n4<4; n4++) {
					TA(m1[n2][n1][n4] ==	m2[n2][n1][n4]);
				}
			}
		}
	}////////////////////////////////////////////////////////
};


USI get_adress_from_matrix(														
USI	n1	 ,	USI	s1	 	,								
USI	n2	 ,	USI	s2	 	,								
USI	n3	 ,	USI	s3	 	,								
USI	n4	 ,	USI	s4	 	,																
USI	n5	 ,	USI	s5	 	) {																
		//дура выдает адрес в линейном массиве представляя его как матрицу m[s1][s2][s3]...																				
		 //         >>>>      return m[n1][n2][n3]...;																				
								TA(	n1	<	s1	&&	s1	>0);								
								TA(	n2	<	s2	&&	s2	>0);								
								TA(	n3	<	s3	&&	s3	>0);								
								TA(	n4	<	s4	&&	s4	>0);								
								TA(	n5	<	s5	&&	s5	>0);								
		USI ret=0;																				
		USI s = 		s1	*	s2	*	s3	*	s4	*	s5	;									
		s/=	s1	;	ret+=	n1	*s;															
		s/=	s2	;	ret+=	n2	*s;															
		s/=	s3	;	ret+=	n3	*s;															
		s/=	s4	;	ret+=	n4	*s;															
		s/=	s5	;	ret+=	n5	*s;															
		return ret;														
}																



int GetProportionNote(int Numerator, int Denominator, int Note) {
	//		Numerator			ret
	//		-------------- = ----------
	//		Denominator			Note
	if(!Denominator && !(Numerator*Note)) return 0;
	if(!Denominator && (Numerator*Note)) return NSMY::NSSmall::GetMaxValue((S4)Note);
	int ret=((S8)Numerator*(S8)Note)/(S8)Denominator;
	if(Numerator < Denominator) {
		for(;;) {
			int n=GetProportionNote(Denominator, Numerator, ret);
			if(Note >= n || n <= 0) break;
			ret--;
		}
		for(;;) {
			int n=GetProportionNote(Denominator, Numerator, ret);
			if(Note <= n || n <= 0) break;
			ret++;
		}
		/*for( ;  < GetProportionNote(Denominator, Numerator, ret); ret--) ;*/
		//for( ; Note > GetProportionNote(Denominator, Numerator, ret); ret++)  ;
	}
	return ret;
}

int BukvaVCifru(char b) {
	if(belong<char>(b, '0', '9')) return (int)b-(int)'0';
	if(belong<char>(b, 'a', 'f')) return 10+(int)b-(int)'a';
	if(belong<char>(b, 'A', 'F')) return 10+(int)b-(int)'A';
	return -1;
};




}//namespace NSMY
}//namespace NSSmall

void cfstr_MassivNotes::VirNotesConstructor(USI adr, USI count) {
	for( ; count; count--, adr++) {
		cfstr * p1=(&(*this)[adr]);
		cfstr * p=new (p1) cfstr ;
	}
}
void cfstr_MassivNotes::VirNotesDestructor(USI adr, USI count) {
	for( ; count; count--, adr++) (&(*this)[adr])->~cfstr();
}



/*


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#ifndef hhhhhhhhhhhhhhhhhhhh8370897342387
#define hhhhhhhhhhhhhhhhhhhh8370897342387 piska

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
template<class TT> TT minusss(TT x, TT y) { 
	if(y > 0) TA(x > x-y);
	if(y < 0) TA(x < x-y);
	return (x-y);
}
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

template<class TT> TT abs(TT p1) { return (p1 < 0 ? -p1 : p1); };

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
	TT ret=1;		ret/=2;

	if(ret!=0) {//пїЅпїЅпїЅпїЅ
		double x1=strtod(str, errorstr );
		ret=(TT)x1;
	//	if(errorstr) if( ((double)ret) != x1) *errorstr=savep;//пїЅпїЅпїЅпїЅпїЅпїЅ
	} else {//пїЅпїЅпїЅ
		S8 x1=strtol(str, errorstr , 10);
		ret=(TT)x1;
		//if(errorstr) if( ((USI)ret) != x1) *errorstr=savep;//пїЅпїЅпїЅпїЅпїЅпїЅ
	}
	return ret;
};


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

#endif


*/