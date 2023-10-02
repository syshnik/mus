#include "stdafx.h"
/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#include "../cod_mus/stdafx.h"
#include "../cod_mus/musor.h"
#include <memory.h>
#include "../cod_mus/nscopywritefind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

namespace NSMY {
namespace NSWrite {
void WriteMem(anyp kup, anyp otp, USI notesize, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(notesize*(sikoko-1)+notesize);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(notesize*(sikoko-1)+notesize);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<USI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
UB * ku=(UB *)&kup[0], * ot=(UB *)&otp[0];
USI n;
for(n=0; n<sikoko; n++) {
memcpy(ku, ot, notesize);
ku+=notesize;
}
}
;
void WriteMemMovku(anyp kup, anyp otp, USI kumov, USI notesize, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
UUI kukry=(kumov*(sikoko-1)+notesize);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
UUI otkry=(notesize*(sikoko-1)+notesize);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
UB * ku=(UB *)&kup[0], * ot=(UB *)&otp[0];
USI n;
for(n=0; n<sikoko; n++) {
memcpy(ku, ot, notesize);
ku+=kumov;
}
}
;
void WriteBit(UBP kup, UB note, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
}
;
void WriteBitMovku(UBP kup, UB note, USI kumov, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
}
;
void WriteBitMaskkuMaskot(UBP kup, UB note, UB kumask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
}
;
void WriteBitMovkuMaskkuMaskot(UBP kup, UB note, USI kumov, UB kumask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
}
;
void WriteBitMaskkuMaskot(UBP kup, UB note, UB kumask, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
}
;
void WriteBitMovkuMaskkuMaskot(UBP kup, UB note, USI kumov, UB kumask, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
}
;
}//namespace NSMY
}//namespace NSMY::NSWrite
using namespace NSMY::NSWrite;
namespace NSMY {
namespace NSCopy {
void MoveMem(anyp kup, anyp otp, USI size){
			   InlineMoveMem(kup, otp, size); 
}
void CopyMem(anyp kup, anyp otp, USI size){
				TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kup), size, rdp(otp), size));
			   InlineCopyMem(kup, otp, size); 
}
void CopyMemMovot(anyp kup, anyp otp, USI otmov, USI notesize, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(notesize*(sikoko-1)+notesize);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(otmov*(sikoko-1)+notesize);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
UB * ku=(UB *)&kup[0], * ot=(UB *)&otp[0];
USI n;
for(n=0; n<sikoko; n++) {
memcpy(ku, ot, notesize);
ku+=notesize;
ot+=otmov;
}
}
;
void CopyMemMovku(anyp kup, anyp otp, USI kumov, USI notesize, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+notesize);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(notesize*(sikoko-1)+notesize);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
UB * ku=(UB *)&kup[0], * ot=(UB *)&otp[0];
USI n;
for(n=0; n<sikoko; n++) {
memcpy(ku, ot, notesize);
ku+=kumov;
ot+=notesize;
}
}
;
void CopyMemMovkuMovot(anyp kup, anyp otp, USI kumov, USI otmov, USI notesize, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+notesize);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(otmov*(sikoko-1)+notesize);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
UB * ku=(UB *)&kup[0], * ot=(UB *)&otp[0];
USI n;
for(n=0; n<sikoko; n++) {
memcpy(ku, ot, notesize);
ku+=kumov;
ot+=otmov;
}
}
;
void CopyBit(UBP kup, UBP otp, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(1*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMovot(UBP kup, UBP otp, USI otmov, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(otmov*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMovku(UBP kup, UBP otp, USI kumov, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(1*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMovkuMovot(UBP kup, UBP otp, USI kumov, USI otmov, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(otmov*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMaskkuMaskot(UBP kup, UBP otp, UB kumask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(1*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMovotMaskkuMaskot(UBP kup, UBP otp, USI otmov, UB kumask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(otmov*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMovkuMaskkuMaskot(UBP kup, UBP otp, USI kumov, UB kumask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(1*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMovkuMovotMaskkuMaskot(UBP kup, UBP otp, USI kumov, USI otmov, UB kumask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(otmov*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMaskkuMaskot(UBP kup, UBP otp, UB kumask, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(1*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMovotMaskkuMaskot(UBP kup, UBP otp, USI otmov, UB kumask, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(otmov*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMovkuMaskkuMaskot(UBP kup, UBP otp, USI kumov, UB kumask, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(1*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
void CopyBitMovkuMovotMaskkuMaskot(UBP kup, UBP otp, USI kumov, USI otmov, UB kumask, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(otmov*(sikoko-1)+1);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
A(0);
}
;
}//namespace NSMY
}//namespace NSMY::NSCopy
using namespace NSMY::NSCopy;
namespace NSMY {
namespace NSFind {
USI FindMem(anyp kup, anyp otp, USI notesize, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(notesize*(sikoko-1)+notesize);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(notesize*(sikoko-1)+notesize);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
UB * ku=(UB *)&kup[0], * ot=(UB *)&otp[0];
USI n;
for(n=0; n<sikoko; n++) {
if(memcmp(ku, ot, notesize)==0) return n;
ku+=notesize;
}
return n;
}
;
USI FindMemMovku(anyp kup, anyp otp, USI kumov, USI notesize, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+notesize);
*kutest;	kutest[kukry-1];
UBP ottest=(UBP)otp;
USI otkry=(notesize*(sikoko-1)+notesize);
*ottest;	ottest[otkry-1];
TA(NSMY::NSCmp::notbelongmas<UUI>(rdp(kutest), kukry, rdp(ottest), otkry));
}
#endif
UB * ku=(UB *)&kup[0], * ot=(UB *)&otp[0];
USI n;
for(n=0; n<sikoko; n++) {
if(memcmp(ku, ot, notesize)==0) return n;
ku+=kumov;
}
return n;
}
;
USI FindBit(UBP kup, UB note, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
return ~0;
}
;
USI FindBitMovku(UBP kup, UB note, USI kumov, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
return ~0;
}
;
USI FindBitMaskkuMaskot(UBP kup, UB note, UB kumask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
return ~0;
}
;
USI FindBitMovkuMaskkuMaskot(UBP kup, UB note, USI kumov, UB kumask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
return ~0;
}
;
USI FindBitMaskkuMaskot(UBP kup, UB note, UB kumask, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(1*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
return ~0;
}
;
USI FindBitMovkuMaskkuMaskot(UBP kup, UB note, USI kumov, UB kumask, UB otmask, USI sikoko){
#if TEST_V
if(sikoko>0) {
UBP kutest=(UBP)kup;
USI kukry=(kumov*(sikoko-1)+1);
*kutest;	kutest[kukry-1];
}
#endif
A(0);
return ~0;
}
;
}
}
