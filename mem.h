/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef _pragma_once_for_Wnd_Small33
#define _pragma_once_for_Wnd_Small33

//namespace NSMY {
//namespace NSMem {
#ifdef WIN_OPERACION_SYSTEM_COPY_BUFFER

extern UINT BlackClipboardFormat;
//}namespace NSMY {}//namespace NSMem {using namespace NSMY::NSMem;


class 		EXPORT_OR_IMPPORT		FloatMemMassivWin : public FloatMemMassiv {
public:
	HGLOBAL CopyToHandle();
	void CopyFromHandle(HGLOBAL h);
	bool CopyToClipboard(DWORD flag);
	bool CopyFromClipboard(DWORD flag);
	template<class TNote>
	FloatMemMassivWin & operator << (TNote n) {
		New(&n, GetSize(), sizeof(n));
		return *this;
	};
	template<class TNote>
	FloatMemMassivWin & operator >> (TNote & n) {
		GetNote(&n, GetSize()-sizeof(n), sizeof(n));
		Delete(GetSize()-sizeof(n), sizeof(n));
		return *this;
	};
	void PushString(char * ch);
	cfstr PopString();
};

OK_EXTERN HGLOBAL WINAPI CopyHandle (HGLOBAL h);
OK_EXTERN bool BigSetClipboardData(HANDLE hp, DWORD flag, bool thish);
OK_EXTERN HANDLE BigGetClipboardData(DWORD flag);
OK_EXTERN void Copy_StringMem_FloatMemMassivWin(cfstr * strp, bool ToMem, DWORD flag = BlackClipboardFormat);
#endif




#endif //#pragma once
