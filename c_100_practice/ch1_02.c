// 002_랜덤숫자 만들기
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
// 주사위 30번 던져서 1~6까지의 정수 랜덤하게 30개 만들어서
// 배열에 확인하고 확인

#if 1
// 내가 짠 코드
int main()
{
	int dice[30];
	srand(time(0)); //현재 시간으로 랜덤시드
	for (int i = 0; i < 30; ++i)
	{
		dice[i] = rand() % 6 + 1;
		printf("%3d", dice[i]);
	}

}
#else
// 예제를 참고한 코드
int main()
{
	int dice[30];
	int rand_min = 1;
	int rand_max = 6;

	srand(time(0)); //현재 시간으로 랜덤시드

	for (int i = 0; i < 30; ++i)
	{
		dice[i] = (double)rand() / RAND_MAX 
			* (rand_max - rand_min + 1) + rand_min;
		//dice[i] = rand() % rand_max + rand_min; 모듈러의 편향 오류 생김
	}
	for (int i = 0; i < 30; ++i)
	{
		printf("%6d%c", dice[i], (i + 1) % 10 != 0 ? ' ' : '\n'); // 특이하다.
	}

}
#endif // 0


#endif // 1