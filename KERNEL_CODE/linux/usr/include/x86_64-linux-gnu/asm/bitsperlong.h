/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

//헤더 가드
#ifndef __ASM_X86_BITSPERLONG_H
#define __ASM_X86_BITSPERLING_H

//x86-64아키텍처이고 ILP32 데이터 모델을 사용하지 않으면 __BITS_PER_LONG을 64로 정의
#if defined(__x86_64__) && !defined(__ILP32__)  //__ILP32__ : int, long, 포인터가 각각 32비트인 데이터 모델을 나타내는 매크로

#define __BITS_PER_LONG 64  //__BITS_PER_LONG : long 자료형의 비트 크기를 나타내는 매크로

//위 조건이 거짓인 경우에 실행되는 전처리 분기(ex : 32비트 x86 환경, x86-64의 x32 ABI 환경 -> long 자료형의 크기가 32비트)
#else

#define __BITS_PER_LONG 32  //long 자료형의 비트 크기를 32로 정의

#endif  //아키텍처 및 ABI 조건부 전처리 영역 종료

//CPU 아키텍처에 공통으로 적용할수 있는 long 자료형의 비트 크기 관련 정의를 제공
#include <asm-generic/bitsperlong.h>

#endif  //#ifndef __ASM_X86_BITSPERLONG_H에 대응하는 헤더 가드 종료