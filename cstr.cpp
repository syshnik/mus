#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#include "../cod_mus/stdafx.h"
#include "../cod_mus/musor.h"
#include "../cod_mus/in_for_file_work.h"

# include <stdio.h>
# include <string.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#ifndef DEBUG_NEW
	#define DEBUG_NEW new 
#endif

using namespace NSMY::NSCmp;
using namespace NSMY::NSSmall;
using namespace NSMY::NSCopy;
using namespace NSMY::NSType;

#pragma comment( exestr, "Автор: Сафаров  Олег  Айратович.  2002 г." )

RELIZ		//для все релиза ети дуры в .h
#define ________TEST___________				TM(test());
#define ________TESTPLUS_______(X)				TM(testplus(X));
//	#undef ________TESTPLUS_______	#undef ________TEST___________

//    DPOINT<TT> operator+(USI mov);
//operator dpointpar();
namespace NSMY {
namespace NSStr {

	static 	int Static_DebugDrawNext=0, StaticTopTop123=0;
	bool GlobalDebugFlag=false;
	
void GlobalDebugToFile(char * par, char * file, bool CreateNewFile) {
	if(!GlobalDebugFlag) return;
#ifdef WIN_OPERACION_SYSTEM
	if(!file) file="d:/vrem/45/AAAGlobalDebug.txt";
	system((char *)(cfstr()  << "Attrib -r "  << file << " /s"));
	
#endif
#ifdef UNIX_OPERACION_SYSTEM
	if(!file) file="/home/z/zavodilasu/AAAGlobalDebug.txt";
	system((char *)(cfstr()  << "chmod 777 "  << file << " "));

#endif
	//откроем файл
	int fh;
	if(CreateNewFile) fh = fcnSMacro__sopen_s( file, O_CREAT|O_TRUNC|O_WRONLY|O_CREAT | O_BINARY);
	else fh = fcnSMacro__sopen_s( file, O_WRONLY | O_BINARY);
	if(fh == -1 )
	{
		return ;
	}
	_lseek(fh, 0, SEEK_END);
	_write(fh, par, strlen(par));
	char buf[100];
	buf[0]=(char)0x0d;
	buf[1]=(char)0x0a;
	buf[2]=(char)0;
	_write(fh, buf, strlen((char *)buf));
	//закрытие потока
	_close( fh );
}
void GlobalDebugDraw(char * par) {
	if(!GlobalDebugFlag) return;
	if(1) {
		cout << "<div class=\"debugdraw\"  style=\"top: " << StaticTopTop123 
			<< "px;\">Debug" << Static_DebugDrawNext  << ", " << (par ? par : (char *)"no par")
			<< "</div>";
		Static_DebugDrawNext++;
		StaticTopTop123+=20;
	}
}


#if TEST_V
//#define BIGTESTCFSTR 1
//#define BIGTESTCFSTR 0
	void  chhh::test() {
		if(abs(_nom) > 255) {
			switch(_nom) {
			case tabnom: break;
			case endnom: break;
			default:TA(0);
			}
		}
	}

	strmask::strmask() {
		TM(_ch=NULL); 
		TM(_size=~0); 
		TM(t_size=~0/2);
		TM(mypoint=this); 
	}
	USI strmask::maxsize() { return t_size; }

	void  strmask::testplus(USI size) {
		test();
		USI maxsize1=maxsize();
		TA(plusss(_size, size) < maxsize1);
	}

	void  strmask::test() {
		USI maxsize1=maxsize(), n1;
/*
		for(n1=0; n1<maxsize1; n1++) if(!_ch[n1]) break;
		TA(n1<maxsize() && n1==_size);
*/
		TA(mypoint == this);
	}
#endif



void strmask::init(char * ch) {
	_ch=ch; 
	for( ; *ch; ch++) ;
	_size=minusss((USI)ch, (USI)_ch);
	________TEST___________;
}

void strmask::nullinit(char * ch) {
	_ch=ch; 
	*_ch=0;
	_size=0;
	________TEST___________;
}
strmask::operator cfstr() { return (cfstr(chp())); };

void strmask::changetab(char newch) {	
	changechar(0x09, newch);
}
void strmask::changechar(char oldch, char newch) {	
	for(char * ch = chp(); *ch; ch++) if(*ch == oldch) *ch = newch;
	________TEST___________; 
}

void strmask::FillSetSize(USI size) {
	USI oldsize=this->size();
	________TESTPLUS_______(size-oldsize); 
	for( ; oldsize < size; oldsize++) _ch[oldsize]='z';
	_ch[size]=0;
	_size=size;
	________TEST___________; 
}
strmask &  strmask::addch(char ch) {	
	________TESTPLUS_______(1); 
	_ch[_size]=ch;
	_size++;
	_ch[_size]=0;
	return *this;
}

strmask & strmask::operator << (cfstr & str) {
	return *this << (char *)str;
}
strmask & strmask::operator = (cfstr & str) {
	return *this = (char *)str;
}
strmask & strmask::operator << (strmask & str) {
	________TESTPLUS_______(str._size); 
	InlineCopyMem(q p()+_size,q str.p(), str._size+1);
	_size+=str._size;
	//uje		________ZIRO___________;
	return *this;
}

strmask & strmask::operator =(strmask & str) {
	________TEST___________; 
	InlineCopyMem(q p(),q str.p(), str._size+1);
	_size=str._size;
	//uje		________ZIRO___________;
	________TEST___________; 
	return *this;
}

strmask & strmask::operator << (chhh nom) {
	if(nom._nom < 256) {//рельный символ
		_ch[_size]=(char)nom._nom;	_size++;		
		_ch[_size]=0;
	} else {
		switch(nom._nom) {
		case chhh::tabnom:
			_ch[_size]=0x09;	_size++;		
			_ch[_size]=0;
			break;
		case chhh::endnom: 
			_ch[_size]=0x0d;				_size++;		
			_ch[_size]=0x0a;				_size++;		
			_ch[_size]=0;
			break;
		default:
			TA(0);
		}
	}
	return *this;
}

strmask & strmask::operator << (char * ch) {
	________TESTPLUS_______(strlen(ch)); 
	_size += stringcopy(&_ch[_size], ch);
	________TEST___________; 
	return *this;
	//NSMY::NSStr::itostr(
}


strmask & strmask:: operator >> (char * ch) {
	________TEST___________; 
	stringcopy(ch, _ch);
	return *this;
}

//strmask &	strmask::	operator << (		USI	par)		{ char buf[256]; return *this << itostr(par, buf); }
//strmask &	strmask::	operator << (		U2	par)		{ char buf[256]; return *this << itostr(par, buf); }
strmask &	strmask::	operator << (		U1	par)
{
	char buf[256]; 
return *this << itostr(par, buf); 
}
strmask &	strmask::	operator << (		U2	par)		{ char buf[256]; return *this << itostr(par, buf); }
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
strmask &	strmask::	operator << (		U4	par)		{ char buf[256]; return *this << itostr(par, buf); }
#endif
strmask &	strmask::	operator << (		U8	par)		{ char buf[256]; return *this << itostr(par, buf); }
strmask &	strmask::	operator << (		S1	par)		{ char buf[256]; return *this << itostr(par, buf); }
strmask &	strmask::	operator << (		S2	par)		{ char buf[256]; return *this << itostr(par, buf); }
strmask &	strmask::	operator << (		S4	par)		{ char buf[256]; return *this << itostr(par, buf); }
strmask &	strmask::	operator << (		S8	par)		{ char buf[256]; return *this << itostr(par, buf); }
strmask &	strmask::	operator << (		F4	par)		{ char buf[256]; return *this << itostr(par, buf); }
strmask &	strmask::	operator << (		F8	par)		{ char buf[256]; return *this << itostr(par, buf); }
strmask &	strmask::	operator << (		voidtype	par)		{ char buf[256]; return *this << itostr(par, buf); }


strmask & strmask:: operator = (char * ch) {
	________TEST___________; 
	_size=0;
	_ch[0]=0;
	*this << ch;
	return *this;
}
strmask & strmask::operator << (bazchar * ch) {
	________TESTPLUS_______(strlen((char *)ch)); 
	_size += stringcopy(&_ch[_size], ch);
	________TEST___________; 
	return *this;
}
strmask & strmask::operator = (bazchar * ch) {
	________TEST___________; 
	_size=0;
	_ch[0]=0;
	return (*this << ch);
}

//------------------------------------------   ------------------------------------------   
//cfstr		cfstr		cfstr		cfstr		cfstr		cfstr		cfstr		
#define _CH_ ((char *)*this)
#define _STATIC_ (_mp.GetPoint() == NULL)

cfstr::operator strmask() {
	strmask ret;
	ret.init(_CH_);
	return ret;
}
cfstr::operator char * () {

	if(_STATIC_) return this->sstr;
	return (char *)_mp.GetPoint();
}


#if TEST_V
void cfstr::test() {
	USI n1;
//	for(n1=0; n1<GetSize()+1; n1++) if(!_CH_[n1]) break;
//	TA(n1==GetSize());
	TM(n1=GetSize());
	TA(n1 > 255 ? !_STATIC_ : _STATIC_);
}
#endif
void cfstr::Constructor() {
	//TM(ForSees=sstr);
	sstr[0]=0;
	_size=0;
}
//void cfstr::Destructor() {}
cfstr::~cfstr() {
	if(!_STATIC_) _mp.Destroy();
	//Destructor();
}

cfstr::cfstr() {
	Constructor();	
}
cfstr::cfstr(const cfstr & str) {
	Constructor();
	*this << (cfstr &)str;
}

cfstr::cfstr(char * ch1, char * ch2, char * ch3  , char * ch4  , char * ch5  ) {
	Constructor();
	if(ch1) *this << ch1;
	if(ch2) *this << ch2;
	if(ch3) *this << ch3;
	if(ch4) *this << ch4;
	if(ch5) *this << ch5;
}

USI cfstr::GetSize() {
#if TEST_V
	if(_STATIC_) {
		TA(sstr[_size]==0);
		TA(_size <= 255);
	} else {
		TA(_mp.GetSize() == _size+1);
		TA(_size > 255);
	}
#endif
	 return _size; 
};

void cfstr::SetSize(USI size) {

	if(_STATIC_) {
		if(size > 255) {
			_mp.Create();
			_mp.SetSize(size+1);
			stringcopy((char *)_mp.GetPoint(), sstr);
			TM(stringcopy(sstr, "piska"));
			TM(ForSees=(char *)_mp.GetPoint());
		}
	} else {
		if(size <= 255) {
			//stringcopy(sstr, (char *)_mp.GetPoint());
			//memcpy(sstr, _mp.GetPoint(), 255+1);
			InlineCopyMem((anyp)newdp(sstr), (anyp)_mp.GetPoint(), min(255+1, size+1));
			_mp.Destroy();
			TM(ForSees=sstr);
		} else {
			_mp.SetSize(size+1);
			TM(ForSees=(char *)_mp.GetPoint());
		}
	}
	_size=size;
	((char *)*this)[_size]=0;
}

void cfstr::FillSetSize(USI size) {
	USI oldsize=this->GetSize();
	this->SetSize(size);
	for( ; oldsize < size; oldsize++) _CH_[oldsize]='z';
	_CH_[size]=0;
}
void cfstr::PerevestiRegistr(bool doun) {
	if(doun) {
		for(char * ch=(char *)(*this); *ch; ch++) {
			if(belong(*ch, 'A', 'Z')) {	*ch='a'+*ch-'A';	continue;	}
			if(belong(*ch, 'А', 'Я')) {	*ch='а'+*ch-'А';	continue;	}
			if(*ch == 'Ё') {	*ch='ё';	continue;	}
		}
	} else {
		TA(0);
	}
}

bool cfstr::operator == (char * ch) {		________TEST___________; 		return bazstr::w_r(_CH_, ch);		};
bool cfstr::operator != (char * ch) {		________TEST___________; 		return !bazstr::w_r(_CH_, ch);		};
bool cfstr::operator == (strmask & par) {		________TEST___________; 		return bazstr::w_r(_CH_, par.chp());		};
bool cfstr::operator != (strmask & par) {		________TEST___________; 		return !bazstr::w_r(_CH_, par.chp());		};
bool cfstr::operator == (cfstr & par) {		________TEST___________; 		return bazstr::w_r(_CH_, (char *)par);		};
bool cfstr::operator != (cfstr & par) {		________TEST___________; 		return !bazstr::w_r(_CH_, (char *)par);		};


cfstr & cfstr::operator << (cfstr & str) {
	return *this << (char *)str;
}
cfstr & cfstr::operator =(cfstr & str) {
	return *this = (char *)str;
}

void cfstr::Insert(char * ch, USI Adress, USI Count) {
	TA(belong<USI>(Adress, 0, GetSize()));
	if(Count == MAXUSI) Count=strlen(ch);
	USI oldsize=this->GetSize();
	this->SetSize(oldsize+Count);
	stringcopy((char *)*this+Adress+Count,
		(char *)*this+Adress, oldsize-Adress);
	memcpy((char *)*this+Adress, ch, Count);
}

void cfstr::CutMejdu(char * leftstr, char * rightstr) {
	//убираем все вхождения от leftstr до rightstr...">" включ-но
	USI rightsize=strlen(rightstr);
	for(USI adr=0; adr < GetSize(); ) {
		//определим края
		USI find1=FindString(leftstr, adr);
		if(find1 >= GetSize()) break;
		USI find2=FindString(rightstr, find1);
		TA(find2 < GetSize()) ;
		//удалим
#if TEST_D
		char * debugsee=(char *)(*this)+find1;
#endif
		CutString(find1, find2+rightsize-find1);
		//
		adr=find1;

	}
}

void cfstr::CutString(USI Adress, USI Count) {
	//вырезаем из строки кусок с адреса Adress длинной Count
	if(Count == MAXUSI) Count=GetSize()-Adress;
	TM(NSMY::NSDebug::testadrsik(this->GetSize(), Adress, Count));
//	USI mysize=Adress+Count, oldsize=strlen(oldstr), newsize=strlen(newstr);
	USI fullsize=GetSize();
	char * mych=(char *)*this+Adress;
	//сдвинем конец
	stringcopy(mych, mych+Count, fullsize-Adress-Count);
	//изменим размер строки
	fullsize-=Count;
	this->SetSize(fullsize);
	//конец строки
	((char *)*this)[fullsize]=0;
	TA(fullsize==GetSize());
}
void cfstr::ReplaceString(char * oldstr, char * newstr, USI Adress, USI Count) {
	USI vr5=0;
	if(Count == MAXUSI) Count=GetSize()-Adress;
	TM(NSMY::NSDebug::testadrsik(this->GetSize(), Adress, Count));
	USI mysize=Adress+Count, oldsize=strlen(oldstr), newsize=strlen(newstr);
	USI fullsize=GetSize();
	if(vr5) this->_mp.Destroy();
//			USI plussize=newsize-oldsize;
	//ищем строку
	for(char * mych=(char *)*this+Adress; mysize >= Adress+oldsize; Adress++, mych++) {
		if(strncmp(mych, oldstr, oldsize)) continue;
		//нашли строку
		//сдвинем направо
//		if(plussize > 0) {
		if(newsize > oldsize) {
			USI plussize=newsize-oldsize;
			//изменим размер строки
			fullsize+=plussize;
			this->SetSize(fullsize);
			//обновим указатель
			mych=(char *)*this+Adress;
			//размер изменился
			mysize+=plussize;
			//сдвинем конец
			stringcopy(mych+plussize,
				mych, fullsize-Adress-plussize);
		}
		//сдвинем налево
		if(newsize < oldsize) {
			USI plussize=oldsize-newsize;
			//сдвинем конец
			stringcopy(mych, mych+plussize, fullsize-Adress-plussize);
			//изменим размер строки
			fullsize-=plussize;
			this->SetSize(fullsize);
			//обновим указатель
			mych=(char *)*this+Adress;
			//размер изменился
			mysize-=plussize;
		}
		//заменим
		memcpy(mych, newstr, newsize);
		//сдвинем за новое слово
		Adress+=(newsize-1);
		mych+=(newsize-1);
#if TEST_D
		//проверим
		USI vr1=(USI)mych, vr2=(USI)((char *)*this+Adress);
		TA(vr1==vr2);
#endif
	}
	//конец строки
	((char *)*this)[fullsize]=0;
	TA(fullsize==GetSize());
}

USI cfstr::SikokoVhojdeniy(char * ch, bool ProverkaNextNotCifraEngBukva) {
	//считает кол-во вхождений строки ch
	char * point=(char *)*this;
	USI mono1=0, size1=strlen(ch);
	for(USI find22=0; ; ) {
		find22=FindString(ch, find22);
		if(find22 < GetSize()) {
			if(ProverkaNextNotCifraEngBukva && (class_to_char::eng_bukva(point[find22+size1]) || class_to_char::cifra(point[find22+size1]))) {
				//если стоит флаг проверки, чтобы слово в строке заканчивалось
				find22+=size1;
			} else {
				//если все нормально то прибывим
				mono1++;
				find22+=size1;
			}
		} else break;

	}
	return mono1;
}
#include <string.h>  
#include <locale.h>  

USI cfstr::FindStringNotRegistr(char * ch, USI Adress, USI Count) {
	if(Count == MAXUSI) Count=GetSize()-Adress;
	TM(NSMY::NSDebug::testadrsik(this->GetSize(), Adress, Count));
	USI mysize=Adress+Count, parsize=strlen(ch);
	for(char * mych=(char *)*this+Adress; mysize >= Adress+parsize; Adress++, mych++) {
		if(!_strnicmp(mych, ch, parsize)) return Adress;
	}
	return mysize;
}

USI cfstr::FindString(char * ch, USI Adress, USI Count) {
	if(Count == MAXUSI) Count=GetSize()-Adress;
	TM(NSMY::NSDebug::testadrsik(this->GetSize(), Adress, Count));
	USI mysize=Adress+Count, parsize=strlen(ch);
	for(char * mych=(char *)*this+Adress; mysize >= Adress+parsize; Adress++, mych++) {
		if(!strncmp(mych, ch, parsize)) return Adress;
	}
	return mysize;
}

cfstr cfstr::GetString(USI Adress, USI Count) {
	if(Count == MAXUSI) Count=GetSize()-Adress;
	TM(NSMY::NSDebug::testadrsik(this->GetSize(), Adress, Count));
	cfstr ret;
	ret.Insert((char *)*this+Adress, 0, Count);
	return ret;
}

cfstr & cfstr::operator << (strmask & str) {
	return *this << str.chp();
}
cfstr & cfstr::operator =(strmask & str) {
	return *this = str.chp();
}
cfstr & cfstr::operator << (const char * ch) {
	*this << (char *)ch;
	return *this;
}
cfstr & cfstr::operator << (char * ch) {
	USI parsize=strlen(ch), oldsize=GetSize();
	SetSize(parsize+oldsize);
	stringcopy(&_CH_[oldsize], ch);
	________TEST___________; 
	return *this;
}
cfstr & cfstr::operator >> (char * ch) {
	________TEST___________; 
	stringcopy(ch, _CH_);
	return *this;
}
cfstr & cfstr::operator = (char * ch) {
	this->SetSize(0);
	_CH_[0]=0;
	*this << ch;
	return *this;
}
#ifdef VISUALCPP6
cfstr &	cfstr::	operator << (		int	par)		{ char buf[256]; return *this << itostr((S4)par, buf); }
#endif
//cfstr &	cfstr::	operator << (		USI	par)		{ char buf[256]; return *this << itostr(par, buf); }
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
cfstr &	cfstr::	operator << (		U1	par)		{ char buf[256]; return *this << itostr(par, buf); }
cfstr &	cfstr::	operator << (		U4	par)		{ char buf[256]; return *this << itostr(par, buf); }
#endif
cfstr &	cfstr::	operator << (		U2	par)		{ char buf[256]; return *this << itostr(par, buf); }
cfstr &	cfstr::	operator << (		U8	par)		{ char buf[256]; return *this << itostr(par, buf); }
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
cfstr &	cfstr::	operator << (		S1	par)		{ char buf[256]; return *this << itostr(par, buf); }
cfstr &	cfstr::	operator << (		S4	par)		{ char buf[256]; return *this << itostr(par, buf); }
#endif
cfstr &	cfstr::	operator << (		S2	par)		{ char buf[256]; return *this << itostr(par, buf); }
cfstr &	cfstr::	operator << (		S8	par)		{ char buf[256]; return *this << itostr(par, buf); }
cfstr &	cfstr::	operator << (		F4	par)		{ char buf[256]; return *this << itostr(par, buf); }
cfstr &	cfstr::	operator << (		F8	par)		{ char buf[256]; return *this << itostr(par, buf); }
cfstr &	cfstr::	operator << (		voidtype	par)		{ char buf[256]; return *this << itostr(par, buf); }
/*
cfstr::operator F4 () {		return strtof4((char *)(*this), NULL);	}
cfstr::operator F8 () {		return strtof8((char *)(*this), NULL);	}
cfstr::operator S1 () {		return strtoi1((char *)(*this), NULL);	}
cfstr::operator S2 () {		return strtoi2((char *)(*this), NULL);	}
cfstr::operator S4 () {		return strtoi4((char *)(*this), NULL);	}
cfstr::operator S8 () {		return strtoi8((char *)(*this), NULL);	}
*/
//  fnote   fnote   fnote   fnote   fnote   fnote   fnote   fnote   fnote   fnote 
//  fnote   fnote   fnote   fnote   fnote   fnote   fnote   fnote   fnote   fnote 

/*void from_char_to_anyp_change(anyp note, char * ch, bool shta) {
	if(shta) for( ; ; note++, ch++) { *note=*((voidtype *)ch); if(!*ch) break; }
	if(!shta) for( ; ; note++, ch++) { *((voidtype *)ch)=*note; if(!*ch) break; }
}*/

#if TEST_V
	USI fnote::maxsize() { return 256; }
	void fnote::testplus(USI size) {
		test();
		TA(plusss(_size, size) < maxsize());
	}
	void fnote::test() {
		USI n1;
		for(n1=0; n1<maxsize(); n1++) if(!_ch[n1]) break;
		TA(n1<maxsize() && n1==_size);/////////
	}
#endif
	fnote::fnote() { TM(_size=~0); }
	fnote::fnote(char * ch) {		*this=ch;	}
	fnote::fnote(strmask & str) {		*this=str;		}

	bool fnote::like(char * ch) {
		________TEST___________;
		bazchar buf[256];
		stringcopy(buf, ch);
		return baz_lr(_ch, buf);		
	}
	bool fnote::operator != (char * ch) { return !(*this == ch); }
	bool fnote::operator != (fnote & par) { return !(*this == par); }

	bool fnote::operator == (char * ch) {
		________TEST___________;
		bazchar buf[256];
		stringcopy(buf, ch);
		return baz_r(_ch, buf);		
	}
	bool fnote::operator == (fnote & par) {
		________TEST___________;
		return baz_r(_ch, par.bchp());
	}
	char * fnote::getstr(char * ch) {
		________TEST___________;
		stringcopy(ch, _ch);
		return &ch[_size];
	}

	cstr<256> fnote::getstr() {
		________TEST___________;
		cstr<256> str;
		stringcopy(str._ch, _ch);
		str._size=_size;

		return str;
	}

	fnote &  fnote::addch(char ch) {	
		________TESTPLUS_______(1); 
		_ch[_size]=(bazchar)ch;
		_size++;
		_ch[_size]=0;
		TM(stringcopy(seestr, _ch));
		return *this;
	}

	fnote &  fnote::insertch(char ch, USI adr) {
		TA(adr <= size());
		________TESTPLUS_______(1); 
		InlineCopyMem(q p()+adr+1,q p()+adr, size()-adr+1);
		_ch[adr] = (bazchar)ch;
		_size++;
		TM(stringcopy(seestr, _ch));
		return *this;
	}

	fnote &  fnote:: operator << (fnote &  fn) {
		________TESTPLUS_______(fn._size); 
		InlineCopyMem(q  p()+_size,q  fn.p(), fn._size+1);
		_size+=fn._size;
		TM(stringcopy(seestr, _ch));
		return *this;
	}
	fnote &  fnote:: operator =(fnote &  fn) {
		InlineCopyMem(q newdp((voidtype *)_ch, maxsize()),q  fn.p(), fn._size+1);
		_size=fn._size;
		TM(stringcopy(seestr, _ch));
		return *this;
	}
	fnote &  fnote:: operator << (char * ch) {
		________TESTPLUS_______(strlen(ch)); 
	_size += stringcopy(&_ch[_size], ch);
		________TEST___________; 
		TM(stringcopy(seestr, _ch));
		return *this;
	}
	fnote &  fnote:: operator << (bazchar * ch) {
		________TESTPLUS_______(strlen((char *)ch)); 
	_size += stringcopy(&_ch[_size], ch);
		________TEST___________; 
		TM(stringcopy(seestr, _ch));
		return *this;
	}
	fnote &  fnote::operator << (voidtype * ch) {
		return (*this << (char *)ch);
	}
//fnote &	fnote::	operator << (		USI	par)		{ char buf[256]; return *this << itostr(par, buf); }
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
fnote &	fnote::	operator << (		U1	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		U4	par)		{ char buf[256]; return *this << itostr(par, buf); }
#endif
//fnote &	fnote::	operator << (		U1	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		U2	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		U8	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		S1	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		S2	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		S4	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		S8	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		F4	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		F8	par)		{ char buf[256]; return *this << itostr(par, buf); }
fnote &	fnote::	operator << (		voidtype	par)		{ char buf[256]; return *this << itostr(par, buf); }
	fnote &  fnote:: operator = (char * ch) {
		_size=0;
		_ch[0]=0;
		return (*this << ch);
	}
	fnote &  fnote:: operator = (bazchar * ch) {
		_size=0;
		_ch[0]=0;
		return (*this << ch);
	}
	fnote &  fnote:: operator = (strmask & str) {
		return (*this = str.chp());
	}

}
}
//namespace NSMY {
//namespace NSStr {



