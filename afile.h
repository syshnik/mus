/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_579071
#define	_pragma_once_579071


namespace NSMY {
namespace NSSmall {

/*
class   		EXPORT_OR_IMPPORT		 AFile
{
private:
	//FILE *stream;
	void * point_for_stream;
	FL point;
public:
	AFile();
//	CFile * filepoint();
	bool new_open(char * name, bool shta, bool tokoread = F);
	bool new_open(char * name, char * parametr);
	void close();
//	void lock(CFile * fp);
//	void unlock();
	void get_set_note(anyp note, FL adr, FL size, bool shta);
	void setnote(anyp note, FL adr, FL size);
	void getnote(anyp note, FL adr, FL size);
//	void setsize(FL size);
	FL getsize();
//	void push_pop(anyp note, FL size, bool shta);

};

//OK_EXTERN cstr<256> getnextprogrammpath();
//OK_EXTERN cstr<256> getprogrammpath();

	*/

/*
cl
ass   		EXPORT_OR_IMPPORT		 AFile
{
private:
	CFile * f;
	FL point;
public:
	AFile();
	CFile * filepoint();
	bool new_open(char * name, bool shta, bool tokoread = F);
	void close();
	void lock(CFile * fp);
	void unlock();
	void get_set_note(anyp note, FL adr, FL size, bool shta);
	void setnote(anyp note, FL adr, FL size);
	void getnote(anyp note, FL adr, FL size);
	void setsize(FL size);
	FL getsize();
	void push_pop(anyp note, FL size, bool shta);

};

OK_EXTERN cstr<256> getnextprogrammpath();
OK_EXTERN cstr<256> getprogrammpath();
*/


}//namespace NSMY {
}//namespace NSSmall {
using namespace NSMY::NSSmall;

#endif //once



