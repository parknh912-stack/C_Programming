#if 0


#ifndef __MYLIB_H__
#define __MYLIB_H__

#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum eMENU {
	eMENU_EXIT = 0,		//명시적으로 0을 넣는다.
	eMENU_INPUT,	//1
	eMENU_OUTPUT,	//2
	eMENU_FIND_MAX,	//3
	eMENU_FIND_MIN,
	eMENU_SUM,
	eMENU_AVG,
	eMENU_SORT_ASC,
	eMENU_SORT_DSC,
	eMENU_MAX			// << 제일큰건 유용하게 쓰임 ex) 배열의 크기라던가
};
int scanf_ary(int* pa, int n);
int print_ary(int* pa, int n);
int findmax_ary(int* pa, int n);
int findmin_ary(int* pa, int n);
int sum_ary(int* pa, int n);
int avg_ary(int* pa, int n);
int sort_ary(int* pa, int n);
void ary_control(int c, int* pa, int n);
int choice_menu(void);
int choice_menu2(void);
int sort_ary_decrease(int* pa, int n);

char* to_upper(char* ary);
char* to_upper2(char* ary);

#endif



#endif // 0



