/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

//헤더 가드
#ifndef _LINUX_POSIX_TYPES_H
#define _LINUX_POSIX_TYPES_H

//Linux에서 사용하는 기본적인 자료형 및 관련 정의를 제공하는 헤더 파일
#include <linux/stddef.h>

#undef __FD_SETSIZE  //기존에 정의된 값을 제거하여 다른 헤더의 매크로 정의와 충돌하지 않도록 함

//파일 디스크립터 집합의 크기를 1024로 정의(이 값은 파일 디스크립터 집합의 표현범위를 의미하며 시스템 전체에서 열수있는 파일의 최대 개수와 다름)
#define __FD_SETSIZE 1024

//파일 디스크립터 집합을 표현하는 구조체(파일 디스크립터들의 상태 또는 포함여부를 비트마스크 형태로 관리하기 위함)
typedef struct {
    unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(long))];
} __kernel_fd_set;

//시그널 핸들러의 자료형의 정의(커널 ABI에서 시그널 핸들러 함수를 표현하는 자료형을 제공하기 위함)
typedef void (*__kernel_sighandler_t)(int);

//System V IPC에서 사용하는 키 자료형을 정의(System V IPC : UNIX System V에서 도입된 프로세스간 통신 방식)
typedef int __kernel_key_t;  //IPC키는 IPC 자원을 찾거나 생성할때 사용하는 값이며, 커널이 부여하는 IPC 식별자와 구분

//POSIX 메시지 큐 디스크립터 자료형을 정의
typedef int __kernel_mqd_t;  //__kernel_mqd_t는 POSIX 메시지 큐용 자료형

//CPU 아키텍처별 POSIX 자료형을 정의하는 헤더를 포함
#include <asm/posix_types.h>

#endif  //헤더가드 종료