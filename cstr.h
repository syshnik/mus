/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_579074
#define	_pragma_once_579074


#include "../cod_mus/bazstr.h"


namespace NSMY {
namespace NSStr {

#define ________TEST___________				TM(test());

class   		EXPORT_OR_IMPPORT		chhh {
public:
	enum {				tabnom=1001,			endnom=1002	};
	USI _nom;
	chhh(USI par) { _nom=par; TM(test()); };
#if TEST_V
	void  test();
#endif
};
class   		EXPORT_OR_IMPPORT		cfstr;
class   		EXPORT_OR_IMPPORT		strmask : public bazstr {
public:

#if TEST_V
	strmask();
	USI t_size;
	virtual USI maxsize();
	void testplus(USI size);
	virtual void test();
	strmask * mypoint;
#else
	USI maxsize() { return MAXUSI; };
#endif
	char * _ch;
	USI _size;

	void FillSetSize(USI size);
	void init(char * ch);
	void nullinit(char * ch);
	operator cfstr();

	USI size() {	________TEST___________;  return _size; };

//	char * p(USI n1) {	TA(0);	________TEST___________; TA((USI)n1<=_size); return _ch+n1; };
	char * p(UUI n1) {		TA(0); ________TEST___________; TA(n1<=_size); return _ch+n1; };
	char * chp() {		________TEST___________; return _ch; };
	charp p() {		________TEST___________; return newdp(_ch, maxsize()); };

	bool operator == (char * ch) {		________TEST___________; 		return w_r(_ch, ch);		};
	bool operator == (strmask & par) {		________TEST___________; 		return w_r(_ch, par.chp());		};

	void changetab(char newch);
	void changechar(char oldch, char newch);

	strmask &  addch(char ch);	
	strmask & operator << (cfstr & str);
	strmask & operator =(cfstr & str);
	strmask & operator << (strmask & str);
	strmask & operator =(strmask & str);
	strmask & operator << (chhh nom);
	strmask & operator << (char * ch);
	strmask & operator >> (char * ch);
	strmask & operator = (char * ch);
	strmask & operator << (bazchar * ch);
	strmask & operator = (bazchar * ch);

//strmask &		operator << (		USI	par)	;
strmask &		operator << (		U1	par)	;
strmask &		operator << (		U2	par)	;
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
strmask &		operator << (		U4	par)	;
#endif
strmask &		operator << (		U8	par)	;
strmask &		operator << (		S1	par)	;
strmask &		operator << (		S2	par)	;
strmask &		operator << (		S4	par)	;
strmask &		operator << (		S8	par)	;
strmask &		operator << (		F4	par)	;
strmask &		operator << (		F8	par)	;
strmask &		operator << (		NSMY::NSType::voidtype	par)	;

};

//template <USI bufsize> class cstr;// : public strmask {

class   		EXPORT_OR_IMPPORT		cfstr_notes {
public:
};

class   		EXPORT_OR_IMPPORT		cfstr : public cfstr_notes {
private:

#if TEST_V
	char * Vrem;
	char * ForSees;
#endif
	void Constructor();
	char sstr[256];
	MemPoint _mp;
	//char * MemPoint::GetPoint();
	USI _size;
	void SetSize(USI size);
public:
	//void Destructor();
#if TEST_V
	void test();
#endif

	operator strmask();
	operator char * ();
	cfstr();
	~cfstr();
	cfstr(const cfstr & str);
	cfstr(char * ch1, char * ch2=NULL, char * ch3 = NULL, char * ch4 = NULL, char * ch5 = NULL);
	USI GetSize();
	void PerevestiRegistr(bool doun);
	void FillSetSize(USI size);
	void Insert(char * ch, USI Adress, USI Count=MAXUSI);
	USI FindString(char * ch, USI Adress=0, USI Count=MAXUSI);
	USI FindStringNotRegistr(char * ch, USI Adress=0, USI Count=MAXUSI);
	USI SikokoVhojdeniy(char * ch, bool ProverkaNextNotCifraEngBukva=false) ;
	void ReplaceString(char * oldstr, char * newstr, USI Adress=0, USI Count=MAXUSI);
	//void DelAllHTMLZnak() ;
	void CutMejdu(char * leftstr, char * rightstr) ;
	void CutString(USI Adress=0, USI Count=MAXUSI);
	cfstr GetString(USI Adress=0, USI Count=MAXUSI);
	bool operator == (char * ch);
	bool operator == (strmask & par);
	bool operator != (char * ch);
	bool operator != (strmask & par);
	bool operator == (cfstr & par);
	bool operator != (cfstr & par);

	cfstr & operator << (cfstr & str);
	cfstr & operator =(cfstr & str);
	cfstr & operator << (strmask & str);
	cfstr & operator =(strmask & str);
	cfstr & operator << (char * ch);
	cfstr & operator << (const char * ch);
	cfstr & operator >> (char * ch);
	cfstr & operator = (char * ch);
#ifdef VISUALCPP6
cfstr &		operator << (		int	par)	;
#endif
//cfstr &		operator << (		USI	par)	;
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
cfstr &		operator << (		U1	par)	;
cfstr &		operator << (		U4	par)	;
#endif
cfstr &		operator << (		U2	par)	;
cfstr &		operator << (		U8	par)	;
cfstr &		operator << (		S1	par)	;
cfstr &		operator << (		S2	par)	;
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
cfstr &		operator << (		S4	par)	;
#endif
cfstr &		operator << (		S8	par)	;
cfstr &		operator << (		F4	par)	;
cfstr &		operator << (		F8	par)	;
cfstr &		operator << (		NSMY::NSType::voidtype	par)	;
/*
operator F4 ();
operator F8 ();
operator S1 ();
operator S2 ();
operator S4 ();
operator S8 ();*/
	bool operator != (const char * ch) { return (*this) != (char *)ch; };
	bool operator == (const char * ch) { return (*this) == (char *)ch; };

};

template <USI bufsize> class cstr : public strmask {
public:
	char llll9990[60];
	strmask & operator = (char * ch) { return *((strmask *)this) = ch; };
	strmask & operator = (strmask & par) { return *((strmask *)this) = par; };
	operator strmask() { return *((strmask *)this); };

#if TEST_V
	virtual USI maxsize() { return bufsize; };
	virtual void test() {
		TA(_ch == _bufer);
		strmask::test();
	};		

#else
	USI maxsize() { return MAXUSI; };
#endif
	char _bufer[bufsize+1];
	void init_parent() {
		_bufer[0]=0;
		strmask::init(_bufer);
	};
	cstr<bufsize>() { init_parent(); };
	cstr<bufsize>(char * ch1, char * ch2, char * ch3 = NULL, char * ch4 = NULL, char * ch5 = NULL) {
		init_parent();
		if(ch1) *this << ch1;
		if(ch2) *this << ch2;
		if(ch3) *this << ch3;
		if(ch4) *this << ch4;
		if(ch5) *this << ch5;
	};
	cstr<bufsize>(char * ch) { 	init_parent(); *this << ch;	};
	cstr<bufsize>(strmask & str) { 	init_parent(); *this << str;	};
	cstr<bufsize>(const cstr<bufsize>& strpar) {
		//восстановим указатели после записи в стек
		init_parent();
		(*this) << *((strmask *)&strpar);
		TM(test());
	};
};

class  		EXPORT_OR_IMPPORT		 fnote : public bazstr {
public:

	bazchar _ch[256];
	USI _size;
#if TEST_V
	char seestr[256];
	USI maxsize();
	void testplus(USI size);
	void test();
#else
	USI maxsize() { return MAXUSI; };
#endif

	fnote();
	fnote(char * ch);
	fnote(strmask & str);

	USI size() {	________TEST___________;  return _size; };
	bazchar * bchp() {	________TEST___________; return _ch; };
	anyp p() {		________TEST___________; return newdp((NSMY::NSType::voidtype *)_ch, maxsize()); };

	bool like(char * ch);
	bool operator != (char * ch);
	bool operator != (fnote & par);
	bool operator == (char * ch);
	bool operator == (fnote & par);

	cstr<256> getstr();
	char * getstr(char * ch);
	fnote &  addch(char ch);	
	fnote &  insertch(char ch, USI adr);	
	fnote & operator << (fnote & fn);
	fnote & operator =(fnote & fn);
	fnote & operator << (char * ch);
	fnote & operator << (bazchar * ch);
	fnote & operator << (NSMY::NSType::voidtype * ch);
	fnote & operator = (char * ch);
	fnote & operator = (bazchar * ch);
	fnote & operator = (strmask & str);

//fnote &		operator << (		USI	par)	;
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
fnote &		operator << (		U1	par)	;
fnote &		operator << (		U4	par)	;
#endif
fnote &		operator << (		U2	par)	;
fnote &		operator << (		U8	par)	;
fnote &		operator << (		S1	par)	;
fnote &		operator << (		S2	par)	;
fnote &		operator << (		S4	par)	;
fnote &		operator << (		S8	par)	;
fnote &		operator << (		F4	par)	;
fnote &		operator << (		F8	par)	;
fnote &		operator << (		NSMY::NSType::voidtype	par)	;
};
OK_EXTERN void GlobalDebugDraw(char * par) ;
OK_EXTERN void GlobalDebugToFile(char * par, char * file=NULL, bool CreateNewFile=false) ;
extern	bool GlobalDebugFlag;

}
}
//namespace NSMY {
//namespace NSStr {
using namespace NSMY::NSStr;



#ifdef WIN_OPERACION_SYSTEM
  #define _tcsnicmp strnicmp
#endif
#ifdef UNIX_OPERACION_SYSTEM
  #define _tcsnicmp strncasecmp
#endif


#undef ________TEST___________

#endif //pragma once



