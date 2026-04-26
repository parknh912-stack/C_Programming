// 003_몬테카를로 시뮬레이션으로 크랩스 게임 확률 계산하기
#if 0
/* --- 공통 헤더 --- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


//크랩스 -> 주사위 2개 던져서 숫자의 합이 배팅한 숫자와 맞으면 이김
//100만번 던져서, 나오는 두 주사위 숫자의 합을 배열에 저장, 출력
#define TRIALS 1000000
#include <time.h>

#if 0
// 내방식
int main()
{
	int rand_min = 1;
	int rand_max = 6;
	int count_nums[13] = { 0 }; // 1~12 까지니까 뭐...
	int dice[2];
	srand(time(0)); //현재 시간으로 랜덤시드

	for (int i = 0; i < TRIALS; ++i)
	{
		dice[0] = rand() % rand_max + rand_min;	//이부분이 굳이 필요없긴 하겠네요
		dice[1] = rand() % rand_max + rand_min;
		count_nums[dice[0] + dice[1]]++;
	}
	for (int i = 2; i < 13; ++i)
	{
		printf("cnt[%2d]= %d, %.2f\n", i, count_nums[i], (count_nums[i] / (float)TRIALS) * 100.0);
	}
	printf("TRIALS : %d\n", TRIALS);
	return 0;
}
#else
//책 방식
int main()
{
	int rand_min = 1;
	int rand_max = 6;
	int count_nums[13] = { 0 }; // 1~12 까지니까 뭐...
	int dice;
	srand(time(0)); //현재 시간으로 랜덤시드

	for (int i = 0; i < TRIALS; ++i)
	{
		dice = rand() % rand_max + rand_min;
		dice += rand() % rand_max + rand_min;
		count_nums[dice]++;
	}

	int total = 0;
	for (int i = 2; i < 13; ++i)
	{
		printf("cnt[%2d]= %8d, %.2f%%\n", i, count_nums[i], (double)count_nums[i] / TRIALS * 100);
		total += count_nums[i];
	}
	printf("TRIALS : %d\n", total);
	return 0;
}
#endif // 1


#endif // 1