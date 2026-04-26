// 009_이중 반복문으로 피라미드 그리기
#if 0
/* --- 공통 헤더 --- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


/*

*/
#if 1
int main()
{
	// 1번
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}printf("\n");

	// 2번
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= (2 * i - 1); ++j) {
			printf("*");
		}
		printf("\n");
	}printf("\n");

	// 3번
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= 6-i; ++j) {
			printf("*");
		}
		printf("\n");
	}printf("\n");


	// 4번
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= 5 - i; ++j) {
			printf(" ");
		}
		for (int j = 1; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}printf("\n");


	// 5번
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= 5 - i; ++j) {
			printf(" ");
		}
		for (int j = 1; j <= (2 * i - 1); ++j) {
			printf("*");
		}
		printf("\n");
	}printf("\n");

	// 6번
	for (int i = 5; i >= 1; --i)
	{
		for (int j = 1; j <= 5 - i; ++j) {
			printf(" ");
		}
		for (int j = 1; j <= (2 * i - 1); ++j) {
			printf("*");
		}
		printf("\n");
	}printf("\n");
}
#else

#endif // 1
#endif // 1