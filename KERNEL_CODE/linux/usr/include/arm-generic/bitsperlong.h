/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

//헤더 가드
#ifndef __ASM_GENERIC_BITS_PER_LONG
#define __ASM_GENERIC_BITS_PER_LONG

//_BITS_PER_LONG 매크로가 정의되어 있는지 확인
#ifndef __BITS_PER_LONG

//컴파일러가 비트 크기 계산에 필요한 두 매크로를 제공하는지 확인
#if defined (__CHAR_BIT__) && defined(__SIZEOF_LONG__)  //컴파일러가 두 매크로를 모두 제공하면 내부코드를 처리

//long 자료형의 비트 크기를 계산(CPU 아키텍처별로 long자료형의 비트크기를 직접 지정하지 않고 컴파일러가 제공하는 자료형 크기 정보를 이용하여 자동 계산)
#define __BITS_PER_LONG(__CHAR_BIT__ * __SIZEOF_LONG__)

#else  //컴파일러가 __CHAR_BIT 또는 SIZEOF_LONG__ 매크로를 제공하지 않는 경우 처리하는 분기

//long 자료형의 비트 크기를 기본값 32로 정의(64비트 long을 사용하는 아키텍처에서는 아키텍처별 헤더를 통해 올바른 값을 정의해야함)
#define __BITS_PER_LONG 32

#endif//__CHAR_BIT__및 __SIZEOF_LONG__ 지원여부에 따른 조건부 전처리 영역 종료

#endif  //__BITS_PER_LONG 정의 여부에 따른 조건부 전처리 영역 종료

#endif  //__ASM_GENERIC_BITS_PER_LONG 헤더가드 종료