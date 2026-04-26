// 004_겹치지 않는 랜덤 숫자 만들기
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

//1~10까지 10개의 랜덤숫자 출력, 중복 X, 나온숫자인지 체크, 나왔다면 새로 만듬
//int check[] 0 초기화 후 방문확인?
#if 1
int main()
{
	int check[11] = { 0 };
	int rand_max = 10;
	int rand_min = 1;
	int rand_num;
	int rand_order[10] = { 0 };
	int i = 0;

	srand(time(0));
	while (i < 10) {
		//rand_num = rand() % rand_max + rand_min; // 논리적인 오류가 있음. 쓰지말것
		rand_num = rand() % (rand_max - rand_min + 1) + rand_min;
		if (check[rand_num] == 0)
		{
			check[rand_num] = 1;
			rand_order[i++] = rand_num;
		}
	}

	for (i = 0; i < 10; ++i)
	{
		printf("%4d", rand_order[i]);
	}
	return 0;
}
#else
int main()
{
	int check[11] = { 0 };
	int rand_order[10] = { 0 };
	int rand_max = 10;
	int rand_min = 1;

	srand(time(0));
	for(int i = 0 ; i < 10 ; ++i)
	{
		int x;
		do {
			//x = (double)rand() / RAND_MAX * (rand_max - rand_min + 1) + rand_min;
			x = (int)((double)rand() / (RAND_MAX + 1.0) * (rand_max - rand_min + 1)) + rand_min;
		} while (check[x] == 1);
		check[x] = 1;
		rand_order[i] = x;
	}

	for (int i = 0; i < 10; ++i)
		printf("%3d", rand_order[i]);
	printf("\n");
	return 0;
}
#endif // 1

#endif // 1