/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_5790716
#define	_pragma_once_5790716


#define BBOOL char
RELIZ		//^^^^умньшить    


	#define get_l_pr(pr1,pr2) max(pr1, pr2)
	#define get_r_pr(pr1,pr2) min(pr1, pr2)
	#define right_pr_order(pleft,pright) (pleft > pright)
	#define ravn_right_pr_order(pleft,pright) (pleft >= pright)
	#define rkry_pr 0
#if TEST_V
	typedef int prtype;
	#define lkry_pr MAX4
#else
	typedef double prtype;
	#define lkry_pr MAXF
#endif
	RELIZ		// преверить значение /\ /\ /\ 


typedef struct wordstr00000{
	cstr<256> w;
	USI type, nomer, preor;
	S4 s4;
	F8 f8;
} wordstr;

	//	КЛЮЧЕВЫЕ СЛОВА					
#define		SELECT_W		((U4)	1	)
#define		FROM_W		((U4)	7	)
#define		WHERE_W		((U4)	8	)
#define		ZV_W		((U4)	9	)
#define		ASC_W		((U4)	12	)
#define		DESK_W		((U4)	13	)
#define		ORDER_W		((U4)	14	)
#define		BY_W		((U4)	15	)
						
						
						
						
						
//	#define	WITH OWNERACCESS OPTION			14	
//	операторы					
#define		MAX_O		((U4)	100	)
#define		MUL_O		((U4)	15	)
#define		DEL_O		((U4)	14	)
#define		RDEL_O		((U4)	13	)
#define		PL_O		((U4)	12	)
#define		MI_O		((U4)	11	)
#define		RMI_O		((U4)	10	)
#define		R_O		((U4)	9	)
#define		B_O		((U4)	8	)
#define		M_O		((U4)	7	)
#define		BR_O		((U4)	6	)
#define		MR_O		((U4)	5	)
#define		NR_O		((U4)	4	)
#define		AND_O		((U4)	3	)
#define		OR_O		((U4)	2	)
#define		XOR_O		((U4)	1	)


						
//	характеристика слова					
#define	KEY_W			((U4)	1	)
#define	TNAME_W			((U4)	2	)
#define	STNAME_W			((U4)	3	)
#define	STRCONST_W			((U4)	4	)
#define	CCONST_W			((U4)	5	)
#define	FCONST_W			((U4)	6	)
#define	LCONST_W			((U4)	7	)
#define	LS_W			((U4)	8	)
#define	RS_W			((U4)	9	)
#define	OPER_W			((U4)	10	)
#define	MAKE_W			((U4)	11	)
#define	STRING_W			((U4)	12	)
#define	ENDSTR_W			((U4)	14	)
#define	MAKECOD_W			((U4)	15	)
////	#define	CMP_W		((U4)	7	)
////	#define	LOG_W		((U4)	7	)
////	#define	MAT_W		((U4)	10	)
////	#define	CHCONST_W		((U4)	11	)

 //типы данных						
#define	NL			((U4)	1	)
#define	NS			((U4)	2	)
#define	ND			((U4)	4	)
#define	NSTR			((U4)	8	)
						
#define	BN			((U4)	1	)
#define	BT			((U4)	3	)
#define	BF			((U4)	0	)

				
///////////////////////////////////////////////////////////
#endif //pragma once