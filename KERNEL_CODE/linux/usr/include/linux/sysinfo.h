/*SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note*/

//헤더가드
#ifndef _LINUX_SUSINFO_H
#define _LINUX_SYSINFO_H 

//Linux 커널과 사용자 공간에서 공통으로 사용하는 자료형을 정의하는 헤더
#include <linux/types.h>

//시스템 평균 부하를 표현할때 사용하는 고정소수점 값의 비트 이동 크기
#define SI_LOAD_SHIFT 16

//sysinfo 구조체
struct sysinfo {
    __kernel_long_t uptime;  //시스템 가동시간(시스템이 부팅된 이후 경과한 시간을 초단위로 저장)
    __kernel_ulong_t loads[3];  //시스템 평균부하(1분, 5분, 15분 평균 부하)
    __kernel_ulong_t totalram;  //전체 사용가능한 물리 메모리 크기
    __kernel_ulong_t freeram;  //사용하지 않는 물리메모리
    __kernel_ulong_t sharedram;  //공유 메모리 사용량
    __kernel_ulong_t bufferram;  //버퍼 메모리 사용량
    __kernel_ulong_t totalswap;  //전체 스왑 메모리 크기
    __kernel_ulong_t freeswap;  //사용가능한 스왑 메모리 크기
    __u16 procs  //현재 시스템의 프로세스 수
    __u16 pad;  //m68k아키텍처의 ABI 호환성을 위한 padding
    __kernel_ulong_t totalhigh;  //전체 High Memory 크기 
    __kernel_ulong_t freehigh;  //사용가능한 High Memory 크기
    __u32 mem_uint;  //메모리 크기계산에 사용하는 단위

    //구조체 크기 및 ABI 호환성을 위한 Padding 영역(char 배열을 사용하여 구조체 내부에 추가적인 메모리 공간을 확보)
    char _f[20=2*sizeof(__kernel_ulong_t)-sizeof(__u32)];  
};

#endif