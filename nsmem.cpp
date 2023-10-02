#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#include "../cod_mus/stdafx.h"
#include "../cod_mus/musor.h"
#include "../cod_mus/nssmall.h"
#include <malloc.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

namespace NSMY {
namespace NSMem {
/*
	MemPoint::MemPoint(void ** ppar) {
		pp=ppar;
		_size=0;
		if((*pp = malloc(1)) == NULL ) NSMY::NSSmall::iskluchilka("Ошибка распределения памяти");
	}
	MemPoint::~MemPoint() {
		free(*pp);
	}
	void MemPoint::SetSize(UI size) {
		UI oldsize;
		TM(oldsize=GetSize());
		if((*pp = realloc(*pp, size+1)) == NULL ) NSMY::NSSmall::iskluchilka("Ошибка распределения памяти");
		_size=size;
		if(oldsize<GetSize()) TM(memset((char *)*pp+oldsize, -1, GetSize()-oldsize));
	}
	USI MemPoint::GetSize() {
		TA((USI)_msize(*pp)-1 == _size);
		return _size;
	}
*/
int StaticMemPoint__CoutCreate=0;
int StaticMemPoint__CoutDestroy=0;

MemPoint::~MemPoint() {
	TA(_p==NULL);
	TA(_size==~0);
}
MemPoint::MemPoint() {
	_p=NULL;
	_size=~0;
}
void MemPoint::Create() {
	if((_p = malloc(1)) == NULL ) NSMY::NSSmall::iskluchilka("Ошибка распределения памяти");
	_size=0;
	StaticMemPoint__CoutCreate++;
}
void MemPoint::Destroy() {
	free(_p);
	_p=NULL;
	_size=~0;
	StaticMemPoint__CoutDestroy++;
}
void MemPoint::SetSize(USI size) {
	if((_p = realloc(_p, size+1)) == NULL ) NSMY::NSSmall::iskluchilka("Ошибка распределения памяти");
#ifdef TEST_V
	if(_size<size) memset((char *)_p+_size, -1, size-_size);
#endif
	_size=size;
}/*
USI StaticMemPoint::GetSize(void **pp) {
	return _msize(*pp)-1;
}*/

}//namespace NSMY
}//namespace NSSmall
