/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/

#ifndef hhhhhhhhhhhhhhhhhhhh32658790945
#define hhhhhhhhhhhhhhhhhhhh32658790945 piska

namespace NSMY {
namespace NSDebug {
OK_EXTERN  void SeveNextRand();
OK_EXTERN  void ReadNextRand();
OK_EXTERN  void SetNextRand(U4 next);
OK_EXTERN  U4 GetNextRand();
OK_EXTERN  U4 Rand();
OK_EXTERN  U4 RandWidthTime();
OK_EXTERN  U4 Rand(U4 par);
OK_EXTERN  bool RandTrue(U4 in, U4 from);
OK_EXTERN U4 NextRand(U4 next, U4 sikoko);



class  		EXPORT_OR_IMPPORT		RunTime {
public:
	enum { _maxstr_ = 100 };
	int nulltime, next, timem[_maxstr_];
	NSMY::NSStr::cfstr chm[_maxstr_];
	RunTime();
	void init();
	int srez(char * ch = NULL);
	int srez(int nom, char * ch = NULL);
};
#ifdef TEST_V 
const int testtrue = 1;
OK_EXTERN void testadrsik(USI mynzap, USI adr, USI sik);
#else
const int testtrue = 0;
#endif

}//	namespace NSMY {
}//	namespace NSDebug {
using namespace NSMY::NSDebug;


#endif
