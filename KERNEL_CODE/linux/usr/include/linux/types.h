/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

//헤더 가드
#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

//CPU 아키텍처별 기본 자료형 정의를 포함
#include <asm/types.h>

//어셈블리 코드가 아닌 경우에만 내부 코드를 처리
#ifndef __ASSEMBLY__

//POSIX 관련 자료형을 정의하는 헤더
#include <linux/posix_types.h>

//컴파일러가 128비트 정수 자료형을 지원하는지 확인(16바이트 정렬 조건을 만족하도록 배치)
#ifdef __SIZEOF_INT128__
typedef __signed__ __int128 __s128 __attribute__((aligned(16)));
typedef unsigned __int128 __u128 __attribute__((aligned(16)));
#endif

//Linux 전용 자료형(일반적인 자료형과 이름이 충돌하지 않기 위해 사용)

//Sparse 정적 분서 도구가 활성화 되었는지 확인(일반 컴파일러에서는 별도동작하지 않음, Sparse 분석시 자료형 사용 오류를 검출할수 있음)
#ifdef __CHECKER__  //__CHECKER__ : Sparse가 코드를 분석할때 정의하는 매크로
#define __bitwise __attribute__((bitwise))  //__bitwise : Sparse가 특정 정수 자료형을 일반정수와 구분하여 검사하도록하는 속성
#else
#define __bitwise
#endif

//__bitwise__는 __bitwise의 과거 호환용 이름(하위 호환성을 위해 두 매크로를 연결)
#define __bitwise__ __bitwise

//바이트 순서를 구분하는 자료형을 정의(__le : Little Endian, __be : Big Endian)
typedef __u16 __bitwise __le16;
typedef __u16 __bitwise __be16;
typedef __u32 __bitwise __le32;
typedef __u32 __bitwise __be32;
typedef __u64 __bitwise __le64;
typedef __u64 __bitwise __be64;

//체크섬 관련 자료형을 정의(주로 네트워크 프로토콜의 체크섬 처리에 사용)
typedef __u16 __bitwise __sum16;  //__sum16 : 16비트 체크섬 값을 표현하는 자료형
typedef __u32 __bitwise __wsum;  //__wsum : 체크섬 계산과정에서 사용하는 32비트 값을 표현하는 자료형

//64비트 자료형의 메모리 정렬을 8바이트로 강제하는 매크로(ABI 호환성 문제를 줄이기 위함)
#define __aligned_u64 __u64 __attribute__((aligned(8)))  //__aligned_u64 : 부호 없는 64비트 정수
#define __aligned_s64 __s64 __attribute__((aligned(8)))  //__aligned_s64 : 부호 있는 64비트 정수
#define __aligned_be64 __be64 __attribute__((aligned(8)))  //__aligned_be64 : Big Endian 형식의 64비트 정수
#define __aligned_le64 __le64 __attribute__((aligned(8)))  //__aligned_le64 : Little Endian 형식의 64비트 정수

//poll 관련 이벤트 비트 마스크 자료형을 정의
typedef unsigned __bitwise __poll_t;

//C언어 전용 자료형 정의 영역 종료(#ifndef __ASSEMBLY__ 에 대응)
#endif

//헤더 가드 종료(#ifndef _LINUX_TYPES_H에 대응)
#endif