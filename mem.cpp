#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
// graf.cpp: implementation of the graf class.
//
//////////////////////////////////////////////////////////////////////

#include "../cod_mus/stdafx.h"
#include "../cod_mus/stdafx.h"
#include "../cod_mus/musor.h"
#include "../cod_mus/nssmall.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//namespace NSMY {
//namespace NSMem {
#ifdef WIN_OPERACION_SYSTEM_COPY_BUFFER
#include <windows.h>
#include  <winuser.h>
UINT BlackClipboardFormat;

HGLOBAL FloatMemMassivWin::CopyToHandle()
{
	HGLOBAL hCopy = ::GlobalAlloc(GHND, GetSize());

	if (hCopy != NULL)
	{
		void* lpCopy = ::GlobalLock((HGLOBAL) hCopy);
		GetNote(lpCopy, 0, GetSize());
		::GlobalUnlock(hCopy);
	}

	return hCopy;
}

void FloatMemMassivWin::CopyFromHandle(HGLOBAL h)
{
	DWORD size = (DWORD)::GlobalSize((HGLOBAL) h);
	SetSize(size);

	void* lp     = ::GlobalLock((HGLOBAL) h);
	SetNote(lp, 0, size);
	::GlobalUnlock(h);
}


bool FloatMemMassivWin::CopyToClipboard(DWORD flag)
{
	bool ok=false;
	if(HANDLE h = CopyToHandle()) {
		if (OpenClipboard(NULL)) {
			if(EmptyClipboard()) {
				SetClipboardData(flag, h);
				ok=true;
			}
			ok=(CloseClipboard() && ok);
		}
	}
	return ok;
}
  
bool FloatMemMassivWin::CopyFromClipboard(DWORD flag)
{
	bool ok=false;
	if (OpenClipboard(NULL))	{
		if(HANDLE h = GetClipboardData(flag)) {
			CopyFromHandle(h);
			ok=true;
		}
		ok=(CloseClipboard() && ok);
	}
	return ok;
}

void FloatMemMassivWin::PushString(char * ch) {
	//пїЅпїЅпїЅпїЅ, пїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
	//пїЅпїЅпїЅпїЅпїЅпїЅ- пїЅпїЅпїЅ пїЅпїЅпїЅпїЅ пїЅ2-пїЅпїЅпїЅпїЅ
	(*this) << (char)0;
	this->New(ch, this->GetSize(), strlen(ch)+1);
}
cfstr FloatMemMassivWin::PopString() {
	//пїЅпїЅпїЅпїЅ, пїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
	//пїЅпїЅпїЅпїЅпїЅпїЅ- пїЅпїЅпїЅ пїЅпїЅпїЅпїЅ пїЅ2-пїЅпїЅпїЅпїЅ
	USI size=this->GetSize();
	if(!size) return cfstr("");//пїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
	size--;
	char * p=this->GetPoint()+size;
	if(*p) return cfstr("");//пїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
	for( ; size && p[-1]; p--, size--) ;
	if(!size) return cfstr("");//пїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
	//ok
	cfstr ret(p);
	p--;
	//пїЅпїЅпїЅпїЅ пїЅпїЅпїЅ
	USI adr=(USI)p-(USI)GetPoint();
	this->Delete(adr, this->GetSize()-adr);
	return ret;
}

bool BigSetClipboardData(HANDLE hp, DWORD flag, bool thish)
{
	bool ok=false;
	if(HANDLE h = (thish ? hp : CopyHandle(hp))) {
		if (OpenClipboard(NULL)) {
			if(EmptyClipboard()) {
				SetClipboardData(flag, h);
				ok=true;
			}
			ok=(CloseClipboard() && ok);
		}
	}
	return ok;
}

HANDLE BigGetClipboardData(DWORD flag)
{
	HANDLE ret=NULL;	
	if (OpenClipboard(NULL))	{
		ret = CopyHandle(GetClipboardData(flag));
		CloseClipboard();
	}
	return ret;
}

//пїЅпїЅ пїЅ пїЅ (пїЅпїЅпїЅ)
HGLOBAL WINAPI CopyHandle (HGLOBAL h)
{
	if (h == NULL)
		return NULL;

	DWORD dwLen = (DWORD)::GlobalSize((HGLOBAL) h);
	HGLOBAL hCopy = ::GlobalAlloc(GHND, dwLen);

	if (hCopy != NULL)
	{
		void* lpCopy = ::GlobalLock((HGLOBAL) hCopy);
		void* lp     = ::GlobalLock((HGLOBAL) h);
		memcpy(lpCopy, lp, dwLen);
		::GlobalUnlock(hCopy);
		::GlobalUnlock(h);
	}

	return hCopy;
}
//static void Copy_StringMem_FloatMemMassivWin(StringMem & sm, bool ToMem) {
void Copy_StringMem_FloatMemMassivWin(cfstr * strp, bool ToMem, DWORD flag) {
	FloatMemMassivWin m;
	if(ToMem) {
		m.New((char *)*strp, 0, strp->GetSize()+1);
		m.CopyToClipboard(flag);
	} else {
		if(m.CopyFromClipboard(flag)) {
			*strp=(char *)m.GetPoint();
		}
	}
}
#endif
//}//namespace NSMY {
//}//namespace NSMem {


