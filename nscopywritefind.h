/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/

#pragma once
namespace NSMY {
namespace NSWrite {
OK_EXTERN void WriteMem(anyp kup, anyp otp, USI notesize, USI sikoko);
OK_EXTERN void WriteMemMovku(anyp kup, anyp otp, USI kumov, USI notesize, USI sikoko);
OK_EXTERN void WriteBit(UBP kup, UB note, UB otmask, USI sikoko);
OK_EXTERN void WriteBitMovku(UBP kup, UB note, USI kumov, UB otmask, USI sikoko);
OK_EXTERN void WriteBitMaskkuMaskot(UBP kup, UB note, UB kumask, USI sikoko);
OK_EXTERN void WriteBitMovkuMaskkuMaskot(UBP kup, UB note, USI kumov, UB kumask, USI sikoko);
OK_EXTERN void WriteBitMaskkuMaskot(UBP kup, UB note, UB kumask, UB otmask, USI sikoko);
OK_EXTERN void WriteBitMovkuMaskkuMaskot(UBP kup, UB note, USI kumov, UB kumask, UB otmask, USI sikoko);
template<class TT> void WriteTempl(GETPOINTTYPE_TT kup, TT note, USI sikoko){
USI n;
for( n=0; n<sikoko; n++) {
*kup=note;
kup++;
}
}
;
template<class TT> void WriteTemplMovku(GETPOINTTYPE_TT kup, TT note, USI kumov, USI sikoko){
USI n;
for(USI n=0; n<sikoko; n++) {
*kup=note;
kup=(GETPOINTTYPE_TT)(((UBP)kup)+kumov);
}
}
;
}//namespace NSMY
}//namespace NSMY::NSWrite
using namespace NSMY::NSWrite;
namespace NSMY {
namespace NSCopy {
OK_EXTERN void MoveMem(anyp kup, anyp otp, USI size);
OK_EXTERN void CopyMem(anyp kup, anyp otp, USI size);
OK_EXTERN void CopyMemMovot(anyp kup, anyp otp, USI otmov, USI notesize, USI sikoko);
OK_EXTERN void CopyMemMovku(anyp kup, anyp otp, USI kumov, USI notesize, USI sikoko);
OK_EXTERN void CopyMemMovkuMovot(anyp kup, anyp otp, USI kumov, USI otmov, USI notesize, USI sikoko);
OK_EXTERN void CopyBit(UBP kup, UBP otp, UB otmask, USI sikoko);
OK_EXTERN void CopyBitMovot(UBP kup, UBP otp, USI otmov, UB otmask, USI sikoko);
OK_EXTERN void CopyBitMovku(UBP kup, UBP otp, USI kumov, UB otmask, USI sikoko);
OK_EXTERN void CopyBitMovkuMovot(UBP kup, UBP otp, USI kumov, USI otmov, UB otmask, USI sikoko);
OK_EXTERN void CopyBitMaskkuMaskot(UBP kup, UBP otp, UB kumask, USI sikoko);
OK_EXTERN void CopyBitMovotMaskkuMaskot(UBP kup, UBP otp, USI otmov, UB kumask, USI sikoko);
OK_EXTERN void CopyBitMovkuMaskkuMaskot(UBP kup, UBP otp, USI kumov, UB kumask, USI sikoko);
OK_EXTERN void CopyBitMovkuMovotMaskkuMaskot(UBP kup, UBP otp, USI kumov, USI otmov, UB kumask, USI sikoko);
OK_EXTERN void CopyBitMaskkuMaskot(UBP kup, UBP otp, UB kumask, UB otmask, USI sikoko);
OK_EXTERN void CopyBitMovotMaskkuMaskot(UBP kup, UBP otp, USI otmov, UB kumask, UB otmask, USI sikoko);
OK_EXTERN void CopyBitMovkuMaskkuMaskot(UBP kup, UBP otp, USI kumov, UB kumask, UB otmask, USI sikoko);
OK_EXTERN void CopyBitMovkuMovotMaskkuMaskot(UBP kup, UBP otp, USI kumov, USI otmov, UB kumask, UB otmask, USI sikoko);
template<class TT> void CopyTempl(GETPOINTTYPE_TT kup, GETPOINTTYPE_TT otp, USI sikoko){
USI n;
for(USI n=0; n<sikoko; n++) {
*kup=*otp;
kup++;
otp++;
}
}
;
template<class TT> void CopyTemplMovot(GETPOINTTYPE_TT kup, GETPOINTTYPE_TT otp, USI otmov, USI sikoko){
USI n;
for(USI n=0; n<sikoko; n++) {
*kup=*otp;
kup++;
otp=(GETPOINTTYPE_TT)(((UBP)otp)+otmov);
}
}
;
template<class TT> void CopyTemplMovku(GETPOINTTYPE_TT kup, GETPOINTTYPE_TT otp, USI kumov, USI sikoko){
USI n;
for(USI n=0; n<sikoko; n++) {
*kup=*otp;
kup=(GETPOINTTYPE_TT)(((UBP)kup)+kumov);
otp++;
}
}
;
template<class TT> void CopyTemplMovkuMovot(GETPOINTTYPE_TT kup, GETPOINTTYPE_TT otp, USI kumov, USI otmov, USI sikoko){
USI n;
for(USI n=0; n<sikoko; n++) {
*kup=*otp;
kup=(GETPOINTTYPE_TT)(((UBP)kup)+kumov);
otp=(GETPOINTTYPE_TT)(((UBP)otp)+otmov);
}
}
;
}//namespace NSMY
}//namespace NSMY::NSCopy
using namespace NSMY::NSCopy;
namespace NSMY {
namespace NSFind {
OK_EXTERN USI FindMem(anyp kup, anyp otp, USI notesize, USI sikoko);
OK_EXTERN USI FindMemMovku(anyp kup, anyp otp, USI kumov, USI notesize, USI sikoko);
OK_EXTERN USI FindBit(UBP kup, UB note, UB otmask, USI sikoko);
OK_EXTERN USI FindBitMovku(UBP kup, UB note, USI kumov, UB otmask, USI sikoko);
OK_EXTERN USI FindBitMaskkuMaskot(UBP kup, UB note, UB kumask, USI sikoko);
OK_EXTERN USI FindBitMovkuMaskkuMaskot(UBP kup, UB note, USI kumov, UB kumask, USI sikoko);
OK_EXTERN USI FindBitMaskkuMaskot(UBP kup, UB note, UB kumask, UB otmask, USI sikoko);
OK_EXTERN USI FindBitMovkuMaskkuMaskot(UBP kup, UB note, USI kumov, UB kumask, UB otmask, USI sikoko);
template<class TT> USI FindTempl(GETPOINTTYPE_TT kup, TT note, USI sikoko){
USI n;
for(USI n=0; n<sikoko; n++) {
if(*kup==note) return n;
kup++;
}
return n;
}
;
template<class TT> USI FindTemplMovku(GETPOINTTYPE_TT kup, TT note, USI kumov, USI sikoko){
USI n;
for(USI n=0; n<sikoko; n++) {
if(*kup==note) return n;
kup=(GETPOINTTYPE_TT)(((UBP)kup)+kumov);
}
return n;
}
;
}
}
