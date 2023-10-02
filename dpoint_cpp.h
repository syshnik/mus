/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/

#ifndef TEST_P
		#error		етот файл токо для тяжелых указателей
#endif


#ifdef TTPOINT
template <class TT> 
void DPOINT<TT>::settestmov() {
	see = (TT *)p;
	dpointpar::settestmov();
}
template <class TT> 
DPOINT<TT>::DPOINT<TT> () {	_sizenote = sizeof(TT); };
template <class TT> 
DPOINT<TT>::DPOINT<TT> (dpointpar par) {
	this->setnotes(par);
	_sizenote = sizeof(TT); 
	settestmov();
};
//TT * DPOINT<TT>::changetype(UUI pp) { return (TT *)pp; };
template <class TT> 
DPOINT<TT>& DPOINT<TT>::operator=(TT* pp) {
	p=(USI)pp; lp=p; rp=p+sizeof(TT);;
	settestmov();
	return *this;
}
template <class TT> 
DPOINT<TT>& DPOINT<TT>::operator=(dpointpar  par) {
	*((dpointpar *)this)		=		par;
	settestmov();
	return *this;
}
template <class TT> 
DPOINT<TT>::operator dpointpar() {
	dpointpar ret;
	ret=*this;
	settestmov();
	return ret;
}
///////////////////////////////////////////////////
template <class TT> 
TT * DPOINT<TT>::pp() { return (TT *)p; };
/////двигаем///////////////////////////////////////////////
template <class TT> 
void DPOINT<TT>::operator++(USI) {	p=plusss(p, sizeof(TT)); settestmov(); };//	return *this; 		settestmov(); }
template <class TT> 
void DPOINT<TT>::operator--(USI) {	p=minusss(p, sizeof(TT));	settestmov(); };//return *this; 		settestmov(); }
template <class TT> 
DPOINT<TT>& DPOINT<TT>::operator+=(USI mov) {	p=plusss(p, mov*sizeof(TT));	settestmov(); return *this; 		}
template <class TT> 
DPOINT<TT>& DPOINT<TT>::operator-=(USI mov) {	p=minusss((USI)p, (USI)(mov*sizeof(TT)));	settestmov(); return *this; 		}
template <class TT> 
DPOINT<TT> DPOINT<TT>::operator+(USI mov) {	DPOINT<TT> ret; ret=*this; ret+=mov; return ret; 		}
template <class TT> 
DPOINT<TT> DPOINT<TT>::operator-(USI mov) {	DPOINT<TT> ret; ret=*this; ret-=mov; return ret; 		}

template <class TT> 
DPOINT<TT>& DPOINT<TT>::operator+=(USI mov) {	p=plusss((USI)p, mov*(USI)sizeof(TT));	settestmov(); return *this; 		}
template <class TT> 
DPOINT<TT>& DPOINT<TT>::operator-=(USI mov) {	p=minusss((USI)p, mov*(USI)sizeof(TT));	settestmov(); return *this; 		}
template <class TT> 
DPOINT<TT> DPOINT<TT>::operator+(USI mov) {	DPOINT<TT> ret; ret=*this; ret+=mov; return ret; 		}
template <class TT> 
DPOINT<TT> DPOINT<TT>::operator-(USI mov) {	DPOINT<TT> ret; ret=*this; ret-=mov; return ret; 		}

//получение переменной
template <class TT> 
TT& DPOINT<TT>::operator[](UUI adr) { 
	(*this+adr).testpoint(sizeof(TT));
	return *(pp()+adr); 		
}
/*
template <class TT> 
TT& DPOINT<TT>::operator[](USI adr) { 
	(*this+adr).testpoint(sizeof(TT));
	return *(pp()+adr); 		
}*/
//    DPOINT<TT>::operator TT *(void) {	testpoint(p); 	return p; 		}
template <class TT> 
TT& DPOINT<TT>::operator*(void) {		testpoint(sizeof(TT));  			return *pp(); 		}
//TT* DPOINT<TT>::operator->(void) {		testpoint(pp()); 			return pp(); 		}

//сравнение
template <class TT> 
bool	DPOINT<TT>::operator	 == 	(DPOINT<TT>	par)	{	return	(p	 == 	par.p);	};
template <class TT> 
bool	DPOINT<TT>::operator	> 	(DPOINT<TT>	par)	{	return	(p	> 	par.p);	};
template <class TT> 
bool	DPOINT<TT>::operator	< 	(DPOINT<TT>	par)	{	return	(p	< 	par.p);	};
template <class TT> 
bool	DPOINT<TT>::operator	>= 	(DPOINT<TT>	par)	{	return	(p	>= 	par.p);	};
template <class TT> 
bool	DPOINT<TT>::operator	<= 	(DPOINT<TT>	par)	{	return	(p	<= 	par.p);	};
template <class TT> 
bool	DPOINT<TT>::operator	!= 	(DPOINT<TT>	par)	{	return	(p	!= 	par.p);	};

	#endif

//////////////////////////////////////////////////////////////////////





#else

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void PCLASS::settestmov() { ((DPOINT<TT>)*this).settestmov(); };
PCLASS::PCLASS () : DPOINT<TT> () { /*DPOINT<TT>:*/ };
PCLASS::PCLASS (dpointpar par) : DPOINT<TT>(par) {	 };
DPOINT<TT>& PCLASS::operator=(TT* pp) { return ((DPOINT<TT>)*this = pp); };
DPOINT<TT>& PCLASS::operator=(dpointpar par) { return ((DPOINT<TT>)*this = par); };
PCLASS::operator dpointpar() { return (dpointpar)((DPOINT<TT>)*this); };
///////////////////////////////////////////////////
TT * PCLASS::pp() { return DPOINT<TT>::pp(); };
/////двигаем///////////////////////////////////////////////
void PCLASS::operator++(USI) {	((DPOINT<TT>)*this)++; };
void PCLASS::operator--(USI) {	((DPOINT<TT>)*this)--; };
DPOINT<TT>& PCLASS::operator+=(USI mov) {	return ((DPOINT<TT>)*this)+=mov; };
DPOINT<TT>& PCLASS::operator-=(USI mov) {	return ((DPOINT<TT>)*this)-=mov; };
DPOINT<TT> PCLASS::operator+(USI mov) {	return ((DPOINT<TT>)*this)+mov; };
DPOINT<TT> PCLASS::operator-(USI mov) {	return ((DPOINT<TT>)*this)-mov; };

DPOINT<TT>& PCLASS::operator+=(USI mov) {	return ((DPOINT<TT>)*this)+=(USI)mov; };
DPOINT<TT>& PCLASS::operator-=(USI mov) {	return ((DPOINT<TT>)*this)-=(USI)mov; };
DPOINT<TT> PCLASS::operator+(USI mov) {	return ((DPOINT<TT>)*this)+(USI)mov; };
DPOINT<TT> PCLASS::operator-(USI mov) {	return ((DPOINT<TT>)*this)-(USI)mov; };


//получение переменной
TT& PCLASS::operator[](USI adr) { return (DPOINT<TT>())[adr]; };
TT& PCLASS::operator[](USI adr) { return (DPOINT<TT>())[(USI)adr]; };
TT& PCLASS::operator*(void) {		return *(DPOINT<TT>()); };

//сравнение
bool	PCLASS::operator	== 	(DPOINT<TT>	par)	{	return	((DPOINT<TT>)*this)	 == 	par;	};
bool	PCLASS::operator	> 	(DPOINT<TT>	par)	{	return	((DPOINT<TT>)*this)	> 	par;	};
bool	PCLASS::operator	< 	(DPOINT<TT>	par)	{	return	((DPOINT<TT>)*this)	< 	par;	};
bool	PCLASS::operator	>= 	(DPOINT<TT>	par)	{	return	((DPOINT<TT>)*this)	>= 	par;	};
bool	PCLASS::operator	<= 	(DPOINT<TT>	par)	{	return	((DPOINT<TT>)*this)	<= 	par;	};
bool	PCLASS::operator	!= 	(DPOINT<TT>	par)	{	return	((DPOINT<TT>)*this)	!= 	par;	};

	#ifdef STRELA
		//template <class TT> 						
			TT *	PCLASS::operator	->	() { 			
				DPOINT<TT> bbf;
				bbf-> for_protected_point ;
				return (TT *)pp();
		};
	#endif


//////////////////////////////////////////////////////////////////////

#ifndef COPYCLASS 
dpoint<TT> newdp(TT * par) {
	return t_newdp<TT>(par, 0,  1);
};
dpoint<TT> newdp(TT * par, UUI rmov) {
	return t_newdp<TT>(par, 0,  rmov);
};
dpoint<TT> newdp(TT * par, UUI lmov, UUI rmov) {
	return t_newdp<TT>(par, lmov,  rmov);
};
#endif


#endif


#undef TT 	
#undef PCLASS 	
#undef STRELA 	
#undef DPOINT
#undef COPYCLASS
