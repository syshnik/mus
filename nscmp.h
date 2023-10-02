/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/

/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_5790711
#define	_pragma_once_5790711

namespace NSMY {
namespace NSCmp {
template<class TT> bool ravno(TT cmpnote, TT note1)
{
	return (cmpnote==note1);
};
template<class TT> bool ravno(TT cmpnote, TT note1, TT note2)
{
	if(cmpnote==note1) return T;
	if(cmpnote==note2) return T;
	return F;
};
template<class TT> bool ravno(TT cmpnote, TT note1, TT note2, TT note3)
{
	if(cmpnote==note1) return T;
	if(cmpnote==note2) return T;
	if(cmpnote==note3) return T;
	return F;
};
template<class TT> bool ravno(TT cmpnote, TT note1, TT note2, TT note3, TT note4)
{
	if(cmpnote==note1) return T;
	if(cmpnote==note2) return T;
	if(cmpnote==note3) return T;
	if(cmpnote==note4) return T;
	return F;
};
template<class TT> bool ravno(TT cmpnote, TT note1, TT note2, TT note3, TT note4, TT note5)
{
	if(cmpnote==note1) return T;
	if(cmpnote==note2) return T;
	if(cmpnote==note3) return T;
	if(cmpnote==note4) return T;
	if(cmpnote==note5) return T;
	return F;
};

template<class TT> bool inside(TT x, TT l, TT r) { 
	TA(l <= r);
	return INSIDE(x, l, r);
}
template<class TT> bool belong(TT x, TT l, TT r) { 
	TA(l <= r);
	return ((l)<=(x) && (x)<=(r));
}
template<class TT> bool notbelongmas (TT adr1, TT sik1, TT adr2, TT sik2 ) {
	return (		(adr1) >= NSSmall::plusss(adr2, sik2)		|| NSSmall::plusss(adr1, sik1)<=(adr2)		);
}
template<class TT> bool belongmas (TT adr1, TT sik1, TT adr2, TT sik2 ) {
	return !notbelongmas(adr1,  sik1,  adr2,  sik2);
}
#ifndef min
template<class TT> TT min(TT p1, TT p2) { return (p1 < p2 ? p1 : p2); };
#define min(p1, p2) ((p1) < (p2) ? (p1) : (p2))
#endif
template<class TT> TT minimum(TT p1, TT p2) { return (p1 < p2 ? p1 : p2); };
template<class TT> TT minimum(TT p1, TT p2, TT p3) { return minimum(p1, minimum(p2, p3)); };
template<class TT> TT minimum(TT p1, TT p2, TT p3, TT p4) { return minimum(minimum(p1, p2), minimum(p3, p4)); };
template<class TT> TT minimum(TT p1, TT p2, TT p3, TT p4, TT p5) { return minimum(p1, minimum(p2, p3, p4, p5)); };

#ifndef max
//template<class TT> TT max(TT p1, TT p2) { return (p1 < p2 ? p1 : p2); };
#define max(p1, p2) ((p1) > (p2) ? (p1) : (p2))
#endif
template<class TT> TT maximum(TT p1, TT p2) { return (p1 < p2 ? p1 : p2); };
template<class TT> TT maximum(TT p1, TT p2, TT p3) { return maximum(p1, maximum(p2, p3)); };
template<class TT> TT maximum(TT p1, TT p2, TT p3, TT p4) { return maximum(maximum(p1, p2), maximum(p3, p4)); };
template<class TT> TT maximum(TT p1, TT p2, TT p3, TT p4, TT p5) { return maximum(p1, maximum(p2, p3, p4, p5)); };



}//namespace NSCmp
}
using namespace NSMY::NSCmp;
#endif //pragma once







