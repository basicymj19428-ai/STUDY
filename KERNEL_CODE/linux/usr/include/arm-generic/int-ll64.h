/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

//헤더 가드
#ifndef _ASM_GENERIC_INT_LL64_H
#define _ASM_GENERIC_INT_LL64_H

//CPU 아키텍처별 long 자료형 크기 관련 헤더(아키텍처별 자료형 정의에 필요한 기본적인 비트 크기 정보를 제공)
#include <asm/bitsperlong.h>

//C언어 코드와 어셈블리 코드 구분(어셈블리 코드에서 이 헤더를 포함하더라도 C언어 전용 자료형 선언을 처리하지 않도록 함)
#ifndef __ASSEMBLY__

//LINUX 전용 자료형 명명 규칙(사용자 프로그램이나 라이브러리에서 사용하는 일반적인 자료형 이름과 충돌하지 않도록 하기 위함)
typedef __signed__ char __s8;  //8비트 부호있는 정수 자료형 정의
typedef unsigned char __u8;  //8비트 부호없는 정수 자료형 정의
typedef __signed__ short __s16;  //16비트 부호있는 정수 자료형 정의
typedef unsigned short __u16;  //16비트 부호없는 정수 자료형 정의
typedef __signed__ int __s32;  //32비트 부호있는 정수 자료형 정의
typedef unsigned int __u32;  //32비트 부호없는 정수 자료형 정의

//64비트 정수 자료형 정의
#ifdef __GNUC__  //GCC 컴파일러 사용 여부를 확인
__extension__ typedef __signed__ long long __s64;
__extension__ typedef unsigned long long __u64;

#else  //GCC 호환 컴파일러가 아닌 경우
typedef __signed__ long long __s64;
typedef unsigned long long __u64;

#endif  //GCC 컴파일러 여부에 따른 조건부 컴파일 종료

#endif  //#ifndef __ASSEMBLY__에 대응

#endif //#ifndef _ASM_GENERIC_INT_LL64_H에 대응