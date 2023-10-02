/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_579073
#define	_pragma_once_579073


namespace NSMY {
namespace NSStr {


class  		EXPORT_OR_IMPPORT		class_to_char  
{
public:
public:
	static void Init();
		
	static 	char  ToBig(char par) 	;
	static 	char  ToSmall(char par) 	;
	static 	char  eng_bukva(char par) 	;
	static 	char  bukva(char par) 	;
	static 	char  cifra(char par) 	;
	static 	char  simvol(char par) 	;
	static 	char  sees(char par) 	;
	static 	char  tbtext(char par) 	;
	static 	char  namech(char par) 	;
	static 	char  wtobaz(char par) 	;
	static 	char  baztow(char par) 	;

};

}
}
//namespace NSMY {
//namespace NSStr {
using namespace NSMY::NSStr;

#endif //pragma once

