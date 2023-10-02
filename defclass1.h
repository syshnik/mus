/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
///////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

namespace NSMY {
namespace NSDebug {

template <class TT> class test_unique
{
public:
	//пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
	NEWPOINTTYPE(TT,typep);
	typep _p;

	test_unique<TT>() {};
	test_unique<TT>(typep pp, USI sik) {	_p=pp;	test(sik);	};

	virtual TT getnote(USI nom) { return _p[nom]; };
	virtual bool nado(USI nom) { return T; };
	void test(USI sik) {
		for(USI n1=0; n1<sik; n1++) {
			if(!nado(n1)) continue;
			TT note1=getnote(n1);
			for(USI n2=0; n2<sik; n2++) {
				if(n1==n2) continue;
				if(!nado(n2)) continue;
				TT note2=getnote(n2);
				TA(		note1 != note2		);
			}
		}
	};
};

}//namespace NSMY {
}//namespace NSDebug {
using namespace NSMY::NSDebug;

namespace NSMY {
namespace NSMem {

template <class TT> class TemplateMassiv
{
public:
	static TT * GetPoint(MemPoint  * mp) {
		return (TT *)mp->GetPoint();
	};
	static void Constructor(MemPoint  * mp, USI * _size=NULL) {
		mp->Create();
		if(_size) *_size=0;
	};
	static void Destructor(MemPoint  * mp) {
		mp->Destroy();
	};
	static USI Count(MemPoint  * mp) {
		return mp->GetSize()/sizeof(TT);
	};
	static void New(MemPoint  * mp, USI ku, USI sik, USI * _size=NULL, TT * par=NULL) {
		USI oldsik=Count(mp), newsik=Count(mp)+sik, right=Count(mp)-ku;
		mp->SetSize(newsik*sizeof(TT));
		InlineMoveMem((anyp)(GetPoint(mp)+newsik-right), (anyp)(GetPoint(mp)+oldsik-right), right*sizeof(TT));
		if(par) {
			NSMY::NSCopy::CopyMem((anyp)(GetPoint(mp)+ku), (anyp)par, sik);
		}
		if(_size) *_size=newsik;
	};
	static void Delete(MemPoint  * mp, USI ot, USI sik, USI * _size=NULL) {
		USI oldsik=Count(mp), newsik=Count(mp)-sik, right=Count(mp)-(ot+sik);
		InlineMoveMem((anyp)(GetPoint(mp)+ot), (anyp)(GetPoint(mp)+ot+sik), right*sizeof(TT));
		mp->SetSize(newsik*sizeof(TT));
		if(_size) *_size=newsik;
	};
	static void Clear(MemPoint  * mp, USI * _size=NULL) {
		Delete(mp, 0, Count(mp), _size);
	};
	static TT & Get(MemPoint  * mp, USI ot, USI * _size=NULL) {
		#if TEST_V
		USI sik=Count(mp);
		if(_size) TA(sik == *_size);
		#endif
		return (GetPoint(mp))[ot];
	};
};

template <class TT> class TemplateMassivNotes
{
protected:
	MemPoint _mp;
	//TT * _p;
	USI _size;
	virtual void VirNotesConstructor(USI adr, USI count){};
	virtual void VirNotesDestructor(USI adr, USI count) {};
public:
	TemplateMassivNotes() {
		TemplateMassiv<TT>::Constructor(&_mp, &_size);
	};
	virtual ~TemplateMassivNotes(void) {
		TemplateMassiv<TT>::Destructor(&_mp);
	}
	TT * GetPoint() { return (TT *)_mp.GetPoint(); };
	USI Count() {
		return _size;
	}
	void New(USI adr, USI sik) {
		TemplateMassiv<TT>::New(&_mp, adr, sik, &_size);
		VirNotesConstructor(adr, sik);
	}
	void Delete(USI adr, USI sik) {
		VirNotesDestructor(adr, sik);
		TemplateMassiv<TT>::Delete(&_mp, adr, sik, &_size);
	}
	void Clear() {
		TemplateMassiv<TT>::Clear(&_mp, &_size);
	}
	TT & operator [] (USI par) {
		TA(par < Count());
		return TemplateMassiv<TT>::Get(&_mp, par, &_size);
	}
	void SetCount(USI count) {
		if(Count() > count) Delete(count, Count()-count);
		if(Count() < count) New(Count(), count-Count());
	}
};
template <class TT> class TemplateMassivSortNotes : public TemplateMassivNotes<TT>
{
public:
	USI Count() {
		return TemplateMassivNotes<TT>::Count();
	}
	TT * GetPoint() { return TemplateMassivNotes<TT>::GetPoint(); };
	void New(TT note) {
		USI n, count=Count();
		if(count) {
			if((*this)[count-1] < note) n=count;
			else n=Find(note);
		} else n=0;
		//Р° РЅРµ РЅР°РґРѕ Р»Рё РїРѕСЃС‚Р°РІРёС‚СЊ Р·Р° РЅР°Р№РґРµРЅРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ
		if(n < count) if((*this)[n] < note) n++;
		//РїРѕСЃС‚Р°РІРёРј
		TemplateMassivNotes<TT>::New(n, 1);
		(*this)[n]=note;
	};
	bool FindBool(TT note) {
		USI n=Find(note);
		if(Count()) if(note == (*this)[n]) return true;
		return false;
	};
	USI Find(TT note) {
		return FindNoteInOrderMassivOnTemplate(&note, GetPoint(), Count());
	};
};

class FloatMemMassiv : protected TemplateMassivNotes<char> {
public:
	#define __super TemplateMassivNotes<char>
	char * GetPoint() { return __super::GetPoint(); };
	USI GetSize() {
		return __super::Count();
	};
	void New(void * note, USI Adr, USI Size) {
		__super::New(Adr, Size);
		if(note) SetNote(note, Adr, Size);
	};
	void SetNote(void * note, USI Adr, USI Size) {
		InlineCopyMem((anyp)(GetPoint()+Adr), (anyp)note, Size);
	};
	void GetNote(void * note, USI Adr, USI Size) {
		InlineCopyMem((anyp)note, (anyp)(GetPoint()+Adr), Size);
	};
	void Delete(USI Adr, USI Size) {
		__super::Delete(Adr, Size);
	};
	void SetSize(USI Size) {
		__super::SetCount(Size);
	};
	#undef __super
};
class   		EXPORT_OR_IMPPORT		cfstr_MassivNotes : public TemplateMassivNotes<cfstr>
{
protected:
	virtual void VirNotesConstructor(USI adr, USI count);
	virtual void VirNotesDestructor(USI adr, USI count);
};

}//namespace NSMY {
}//namespace NSMem {
using namespace NSMY::NSMem;
