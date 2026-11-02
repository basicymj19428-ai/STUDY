/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

//_LINUX_KERNEL_H 매크로가 정의되어 있지 않은 경우 #endif까지의 코드를 전처리 대상으로 포함
#ifndef _LINUX_KERNEL_H

//중복처리 방지
#define _LINUX_KERNEL_H

//시스템 상태 및 메모리 사용량 정보를 표현하는 struct sysinfo 구조체와 관련 상수를 정의
#include <linux/sysinfo.h>

//C언어 및 어셈블리 코드에서 공통으로 사용할수 있는 정수 상수 정의 관련 매크로 제공
#include <linux/const.h>

#endif  //헤더가드 종료