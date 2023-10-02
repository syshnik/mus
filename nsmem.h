/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_5790712
#define	_pragma_once_5790712

namespace NSMY {
namespace NSMem {
/*class   		EXPORT_OR_IMPPORT		MemPoint {
private:
	void ** pp;
	int _size;
public:
	MemPoint(void **ppar);
	~MemPoint();
	void SetSize(USI size);
	int GetSize();

};
*/
class   		EXPORT_OR_IMPPORT		MemPoint {
private:
	void *_p;
	UUI _size;
public:
	~MemPoint();
	MemPoint();

	void * GetPoint() { return _p; };
	USI GetSize() { return _size; };
		void Create();
		void Destroy();
		void SetSize(USI size);
	//static	int GetSize(void **ppar);

};


class StecPoint {
public:
	S1 * bp;
	StecPoint(S1 * bufpar) { bp=bufpar; };
	void * vershina() { return bp; };
	void load(void * note, USI size) {
		InlineCopyMem((anyp)newdp(bp), (anyp)newdp(note), size);
		bp+=size;
	};
	template<class TT>
	StecPoint & operator << (TT n) {
		*(		(TT *)bp		)		=		n;
		bp+=sizeof(TT);
		return *this;
	};
	template<class TT>
	StecPoint & operator >> (TT & n) {
		bp-=sizeof(TT);
		n		=		*(		(TT *)bp		);
		return *this;
	};
};

template<USI s>
class StecMassiv : public StecPoint {
public:
	char buf[s];
	void * osnovanie() { return buf; };
	StecMassiv() : StecPoint(buf) {};
	USI getsize() { return minusss(UIPO(bp), UIPO(buf)); };
	template<class TT>
	StecMassiv & operator << (TT n) {
		(*(StecPoint *)this) << n;
		TA(getsize() <= s);
		return *this;
	};
	template<class TT>
	StecMassiv & operator >> (TT & n) {
		(*(StecPoint *)this) >> n;
		TA(getsize() <= s);
		return *this;
	};
};


}//	namespace NSMY {
}//	namespace NSMem {
using namespace NSMY::NSMem;

#endif //pragma once



