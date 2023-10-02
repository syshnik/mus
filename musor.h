/*���� "��������" � ������� ���� ��������� 2014 �. ��� 027304982940*/
/*BlackBase � ������� ���� ��������� 2001 �. ��� 027304982940*/
#pragma once
#ifndef	_pragma_once_579079
#define	_pragma_once_579079


#include "../cod_mus/macro.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

extern char *	StaticPointForDebug_NotesPoint;
#if TEST_V
	inline void reliza(bool par) { };
	inline void ta(bool par) { A(0); };
	OK_EXTERN  UUI UIPO(void * point);
#else
	inline void reliza(bool par) { A(0); };
	inline void ta(bool par) {  };
	inline UUI UIPO(void * point) { return (UUI)point; };
#endif


#if TEST_P
	#define GETTESTP(NEWP,P,SIK) UUI NEWP=realpoint (P, SIK, F);
	#define GETTESTP_UP(NEWP,P,SIK) UUI NEWP=realpoint (P, SIK, T);
#else
	#define GETTESTP(NEWP,P,SIK) 
	#define GETTESTP_UP(NEWP,P,SIK) 
#endif

namespace NSMY {
}
using namespace NSMY;

#include "../cod_mus/dpoint.h"

namespace NSMY {
namespace NSCopy {
	inline void InlineCopyMem(anyp ku, anyp ot, USI size) {
		GETTESTP(kup, ku, size);
		GETTESTP(otp, ot, size);
		//�������� �� �����������
		TA(		(rdp(ku)) >= rdp(ot)+size		|| rdp(ku)+size<=(rdp(ot))		);
		//TA(NSMY::NSCmp::notbelongmas(rdp(ku), size, rdp(ot), size));
	
		memcpy(&ku[0], &ot[0], size);
	};
	template<class TT> void NoteCpy (TT & ku, TT & ot) {
		//�������� �� �����������
		TA(		((UUI)&ku) >= (UUI)&ot+sizeof(TT)		|| (UUI)&ku+sizeof(TT)<=((UUI)&ot)		);
//		TA(NSMY::NSCmp::notbelongmas((UUI)&ku, sizeof(TT), (UUI)&ot, sizeof(TT)));
		memcpy(&ku, &ot, sizeof(TT));	
	};
	inline void InlineMoveMem(anyp ku, anyp ot, USI size) {
		GETTESTP(ku, ku, size);
		GETTESTP(ot, ot, size);
		memmove(&ku[0], &ot[0], size);
	};
	template<class TT> void NoteMove (TT & ku, TT & ot) {
		memmove(&ku, &ot, sizeof(TT));	
	};
}//	namespace NSMY {
}//	namespace NSCopy {
using namespace NSMY::NSCopy;

#include "../cod_mus/dmas.h"
#include "../cod_mus/class_to_char.h"
#include "../cod_mus/nsmem.h"
#include "../cod_mus/cstr.h"
#include "../cod_mus/afile.h"
#include "../cod_mus/nsdebug.h"
#include "../cod_mus/nssmall.h"
#include "../cod_mus/nscmp.h"
#include "../cod_mus/nscopywritefind.h"
#include "../cod_mus/defclass1.h"
#include "../cod_mus/mem.h"
namespace NSMY {
namespace NSOld {

	OK_EXTERN void qbigobmen(void * ch, USI size1, USI size2);
	OK_EXTERN void qbigobmen(void * ch, USI sik1, USI sik2, USI sik3);
	OK_EXTERN void bigobmen(anyp ch1, USI size1, USI size2);
	OK_EXTERN void bigobmen(anyp p, USI sik1, USI sik2, USI sik3);
	OK_EXTERN NSMY::NSType::size_nsector get_s_size(USI sum, USI maxs);
	OK_EXTERN  void deltab_fromstr(char *  ch);


	OK_EXTERN USI uvelichim(USI par, USI mulstep, USI delstep, USI maxret);
	OK_EXTERN void new_nzap_sik(USI & nzap, USI & sik, USI thisnzap, USI maxnzap);
	OK_EXTERN void del_nzap_sik(USI & nzap, USI & sik, USI thisnzap);
	OK_EXTERN void wrightmus(anyp ku, NSMY::NSType::SType type, UB mask, USI mov, USI sik);
	OK_EXTERN USI SikTrue(UBP notep, USI sik);
	#if TEST_V
	OK_EXTERN void tvtestflag(UUI flagp);
	#endif
}//	namespace NSMY {
}//	namespace NSOld {
using namespace NSMY::NSOld;


namespace NSMY {
namespace NSCmp {
	template<class TT> bool NoteCmp (TT & note1, TT & note2) {
		return (memcmp(&note1, &note2, sizeof(TT)) == 0);	
	};
}//	namespace NSMY {
}//	namespace NSCmp {
using namespace NSMY::NSCmp;

namespace NSMY {
namespace NSWrite {
	template<class TT> void NoteZiro (TT & note) {
		memset(&note, 0, sizeof(TT));	
	};
	template<class TT> void NoteOne (TT & note) {
		memset(&note, -1, sizeof(TT));	
	};
}//	namespace NSMY {
}//	namespace NSWrite {
using namespace NSMY::NSWrite;
#ifdef VISUALCPP2015
#include <io.h>
inline extern
FILE*   fcnSMacro_fopen_s(char *fname, char *mode)
{
	FILE *fptr;
	fopen_s(&fptr, fname, mode);
	return fptr;
}
inline extern
int  fcnSMacro__sopen_s(char *fname, int mode)
{
	int fd = 0;
	errno_t errno = _sopen_s(&fd, fname, mode, _SH_DENYRW, 0);
	return fd;
}
inline extern
void  fcnSMacro__strcpy_s(char * dest, rsize_t destsz, const char * src)
{
	strcpy_s(dest, destsz, src);
}
inline extern
void  fcnSMacro__strcat_s(	char *strDestination,	size_t numberOfElements,	const char *strSource)
{
	strcat_s(strDestination, numberOfElements, strSource);
}
#else
inline extern
FILE*   fcnSMacro_fopen_s(char *fname, char *mode)
{
	return fopen(fname, mode);
}
inline extern
///#include <host_io.h>
int  fcnSMacro__sopen_s(char *fname, int mode)
{
	return 	_open(fname, mode);
}
inline extern
void  fcnSMacro__strcpy_s(char * dest, int destsz, const char * src)
{
	strcpy(dest, src);
}
inline extern
void  fcnSMacro__strcat_s(char *strDestination, int numberOfElements, const char *strSource)
{
	strcpy(strDestination, strSource);
}
#endif

#endif //pragma once





