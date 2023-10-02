/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/

#ifndef TEST_P
		#error		етот файл токо для тяжелых указателей
#endif

template <class TT> class 	DPOINT : public dpointpar {
public:
	TT * see;
	void settestmov();
/////конструктор///////////////////////////////////////////////
PCLASS ();
PCLASS (dpointpar par);
    DPOINT<TT>& operator=(TT* pp);
    DPOINT<TT>& operator=(dpointpar  par);
operator dpointpar();
TT * pp();
/////двигаем///////////////////////////////////////////////
    void operator++(USI);
    void operator--(USI);
    DPOINT<TT>& operator+=(USI mov);
    DPOINT<TT>& operator-=(USI mov);
    DPOINT<TT> operator+(USI mov);
    DPOINT<TT> operator-(USI mov);

    DPOINT<TT>& operator+=(USI mov);
    DPOINT<TT>& operator-=(USI mov);
    DPOINT<TT> operator+(USI mov);
    DPOINT<TT> operator-(USI mov);


    TT& operator[](USI adr);
    TT& operator[](USI adr);
    TT& operator*(void);
    
bool operator == (DPOINT<TT>par);
bool operator> (DPOINT<TT>par);
bool operator< (DPOINT<TT>par);
bool operator>= (DPOINT<TT>par);
bool operator<= (DPOINT<TT>par);
bool operator!= (DPOINT<TT>par);
};

 dpoint<TT> newdp(TT * par);
 dpoint<TT> newdp(TT * par, USI rmov);
 dpoint<TT> newdp(TT * par, USI lmov, USI rmov);

#undef TT 	
#undef PTT 	
#undef PCLASS 	
#undef STRELA
#undef DPOINT
#undef COPYCLASS
