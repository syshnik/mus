/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#include "../cod_mus/export_dll_exe.h"												
	#ifdef	EXEF							 //	EXEF	NOT_EXEF	
	#ifdef	NOT_EXEF										
	#error	Blya.	2 Macroses		EXEF	NOT_EXEF						
	#endif											
	#endif											
												
	#ifndef	EXEF										
	#ifndef	NOT_EXEF										
	#error	Blya.	No Macroses		EXEF	NOT_EXEF						
	#endif											
	#endif											
												
												
	#ifdef	TEST_V							 //	TEST_V	NOT_TEST_V	
	#ifdef	NOT_TEST_V										
	#error	Blya.	2 Macroses		TEST_V	NOT_TEST_V						
	#endif											
	#endif											
												
	#ifndef	TEST_V										
	#ifndef	NOT_TEST_V										
	#error	Blya.	No Macroses		TEST_V	NOT_TEST_V						
	#endif											
	#endif											
												
												
	#ifdef	TEST_P							 //	TEST_P	NOT_TEST_P	
	#ifdef	NOT_TEST_P										
	#error	Blya.	2 Macroses		TEST_P	NOT_TEST_P						
	#endif											
	#endif											
												
	#ifndef	TEST_P										
	#ifndef	NOT_TEST_P										
	#error	Blya.	No Macroses		TEST_P	NOT_TEST_P						
	#endif											
	#endif											
												
												
	#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
	#ifdef	NOT_UNIX_OPERACION_SYSTEM										
	#error	Blya.	2 Macroses		UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM						
	#endif											
	#endif											
												
	#ifndef	UNIX_OPERACION_SYSTEM										
	#ifndef	NOT_UNIX_OPERACION_SYSTEM										
	#error	Blya.	No Macroses		UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM						
	#endif											
	#endif											
												
												
	#ifdef	WIN_OPERACION_SYSTEM							 //	WIN_OPERACION_SYSTEM	NOT_WIN_OPERACION_SYSTEM	
	#ifdef	NOT_WIN_OPERACION_SYSTEM										
	#error	Blya.	2 Macroses		WIN_OPERACION_SYSTEM	NOT_WIN_OPERACION_SYSTEM						
	#endif											
	#endif											
												
	#ifndef	WIN_OPERACION_SYSTEM										
	#ifndef	NOT_WIN_OPERACION_SYSTEM										
	#error	Blya.	No Macroses		WIN_OPERACION_SYSTEM	NOT_WIN_OPERACION_SYSTEM						
	#endif											
	#endif											
												
												
												
												
												
												

/////////////////////////////////////////////////////////////////////////////////
////STANDART/////////////////////////////////////////////////////////////////////////////
/*test dll
NOT_EXEF
TEST_V
NOT_TEST_P
NOT_UNIX_OPERACION_SYSTEM
WIN_OPERACION_SYSTEM
NOT_UNIX_MY_KOMPUTER
WIN_MY_KOMPUTER
*/
/////////////////////////////////////////////////////////////////////////////////

#ifdef EXEF
	#define OK_EXPORT 
	#define OK_IMPORT 
	#define OK_EXTERN extern
#else
	#define OK_EXPORT __declspec(dllexport)
	#define OK_IMPORT __declspec(dllimport)
	#define OK_EXTERN EXPORT_OR_IMPPORT
#endif

//unix or windows
//#define UNIX_OPERACION_SYSTEM 
//#define WIN_OPERACION_SYSTEM 

//test macros
/*#ifndef UNIX_OPERACION_SYSTEM
#ifndef WIN_OPERACION_SYSTEM
		#error hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh unix win macros
#endif
#endif

//test macros
#ifdef UNIX_OPERACION_SYSTEM
#ifdef WIN_OPERACION_SYSTEM
		#error hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh unix win macros
#endif
#endif
*/
//komputer

//версия компилятора
#ifdef UNIX_OPERACION_SYSTEM 
#define KDevelop_COMPIL936
#endif
#ifdef WIN_OPERACION_SYSTEM 
#define VNET_COMPIL936
#endif

//корректировка макросов БАЗ ДАННЫХ
#define MACROS_MYSQL_BD 1
//#define MACROS_MSSQL_BD 1

