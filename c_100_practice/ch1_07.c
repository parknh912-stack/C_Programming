// 007_몬테카를로 시뮬레이션으로 원주율 구하기
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
몬테카를로 시뮬레이션 - 컴퓨터에서 확률적으로 어떤 값을 찾는 방법
난수를 활용함
pi = 원의 면적 / 사각형 면적*4
원의 면적을 카운트하는거임
N : 전체 점의 갯수 , A : 원안에 찍히는 점의 갯수
pi = A / N * 4
*/ 
#if 1
// 100 * 100 정사각형
// 반지름 50짜리인 원이 있는거에요
bool isPowerofTen(int x)
{
	for (int i = 1; i < 11; ++i)
	{
		if (x == pow(10, i))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int x, y;
	int in_count = 0;
	int out_count = 0;
	int r = 50; // 원의 중심 좌표이기도 함
	double pi = 0;

	for (int i = 0; i < 100000000; ++i)
	{
		x = rand() % 100;
		y = rand() % 100;
		
		if (pow(x - r, 2) + pow(y - r, 2) < pow(r, 2))
			in_count++;
		else
			out_count++;

		pi = (double)in_count / (in_count + out_count) * 4.0;
		if (isPowerofTen(i))
		{
			printf("i=%d, pi=%.10f\n", i, pi);
		}
	}
	printf("iCnt = %d, oCnt = %d, pi = %f\n", in_count, out_count, pi);
}
#else

#endif // 1
#endif // 1