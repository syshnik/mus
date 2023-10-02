#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/

//99//////////////////////////////////////////////////////////////////////


#include "../cod_mus/stdafx.h"
//#include <stdio.h>
//#include <io.h>
#include <errno.h>
#include "../cod_mus/musor.h"
//#include <io.h>

#include "../cod_mus/in_for_file_work.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

namespace NSMY {
namespace NSSmall {
/*
	void vrvrvrvrInlineCopyMem(anyp ku, anyp ot, FL size) {
		//GETTESTP(kup, ku, size);
		//GETTESTP(otp, ot, size);
		                         
		//TA(		(rdp(ku)) >= rdp(ot)+size		|| rdp(ku)+size<=(rdp(ot))		);
		                                                              
	
		memcpy(&ku[0], &ot[0], size);
	}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction

#define stream (* point_for_point_for_stream)
#define ________init________ FILE ** point_for_point_for_stream = (FILE **)&point_for_stream;

AFile:: AFile()	{		
#if TEST_V
	//пїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ
	FL f1=1;
	fpos_t f2=1;
	for(int n1=0; n1<1000; n1++, f1*=2, f2*=2) A(f1 == f2);
#endif
	________init________;
	stream=(FILE *)NULL;		
	point=~0;
}

bool AFile:: new_open(char * name, bool shta, bool tokoread)
{
	A(0);
	return new_open(name, shta ? "w+b" : "r+b");
}
bool AFile:: new_open(char * name, char * parametr)
{
	________init________;
	TA(stream == NULL && point == ~0);
	stream = fopen(name, parametr);
	return (stream != NULL);
}

void AFile:: close() {
	________init________;
	fclose(stream);
	stream=NULL;
	point=~0;
}

void AFile:: get_set_note(anyp note, FL adr, FL size, bool shta) {
	________init________;
	TM(testadrsik(getsize(), adr, size));
	if(size) {		*note;		note[size-1];		}

	if(point == ~0 || point != adr) A(!fseek(stream, getsize()-adr, SEEK_END));
	
	if(shta)	A(fread((void *)rdp(note), 1, size, stream) == size);
	else	A(fwrite((void *)rdp(note), 1, size, stream) == size);

	point=adr+size;
}

FL AFile:: getsize() {
	________init________;
	//struct _stat st;	int _fstat( int handle, struct _stat *buffer );
	return filelength((int)stream);;
}
void AFile:: setnote(anyp note, FL adr, FL size) {
	get_set_note(note, adr, size, F);
}

void AFile:: getnote(anyp note, FL adr, FL size) {
	get_set_note(note, adr, size, T);
}
*/
////
//////////////////////////////////////////////////////////////////
/*static void correctpath(char * path) {
	//пїЅпїЅ пїЅпїЅпїЅeпїЅ'\' пїЅ '/'
	for( ; *path; path++) if(*path == 0x5c) *path='/';
}

cstr<256> getnextprogrammpath() {
	char nextpath[256], * name = "xxxxxxx";
	LPTSTR lpszFilePart;
	if (GetFullPathName(name, 256, nextpath, &lpszFilePart)) {
		nextpath[strlen(nextpath)-strlen(name)]=0;
	} else strcpy(nextpath, "C:/");
	correctpath(nextpath);

	return cstr<256>(nextpath);
}

//static cstr<256> programmpath = getnextprogrammpath();

cstr<256> getprogrammpath() {
	char buf[256];
	const char * p1=AfxGetApp()->m_pszHelpFilePath;
	for(const char * endp=p1+strlen(p1); endp > p1; endp--) if(*endp == 0x5c) break;
	FL size=minusss((FL)endp, (FL)p1);
	stringcopy(buf, (char *)p1, min(255, size));
	correctpath(buf);
	return cstr<256>(buf);
}
//	programmpath = getnextprogrammpath();
//extern cstr<256> getnextprogrammpath();




void AFile:: lock(CFile * fp)
{
	TA(f == NULL);
	point=~0;
	f=fp;
}

void AFile:: unlock() {
	f=NULL;
	point=~0;
}

}

void AFile:: setsize(FL size) {
	f->SetLength(size);
	point=~0;
}

FL AFile:: getsize() {
	return f->GetLength();
}

CFile * AFile::filepoint() {
	return f;
}

void AFile::push_pop(anyp note, FL size, bool shta)
{
	FL adr=getsize();
	if(shta) setsize(adr+size);

	get_set_note(note, (shta ? adr : adr-size), size, !shta);
	
	if(!shta) setsize(adr-size);
}


*/

}
}
//namespace NSMY {
//namespace NSSmall {
