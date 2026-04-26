// 005_플레잉 카드 한 벌을 랜덤하게 출력하기
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


//클로버, 하트, 스페이드, 다이아몬드 1~13 총 52장
// 0~51까지 겹치지 않는 랜덤숫자 52장 + 이를 해석해서 카드로 출력
#if 0
int main()
{
	int check[52] = { 0 };
	int rand_max = 51;
	int rand_min = 0;
	int rand_order[52] = { 0 };
	char suit;
	srand(time(0));
	for (int i = 0; i < 52;) {
		int rand_num = (double)rand() / RAND_MAX * (rand_max - rand_min + 1) + rand_min;
		if (check[rand_num] == 0)
		{
			check[rand_num] = 1;
			rand_order[i++] = rand_num;
		}
	}
	printf("card order[] :\n");
	for (int i = 0; i < 52; ++i)
	{
		printf("%-4d%c", rand_order[i], (i + 1) % 13 == 0 ? '\n' : ' ');
	}

	printf("card:\n");
	for (int i = 0; i < 52; ++i)
	{
		switch (rand_order[i] / 13) {
		case 0:
			suit = 'C';
			break;
		case 1:
			suit = 'H';
			break;
		case 2:
			suit = 'S';
			break;
		case 3:
			suit = 'D';
			break;

		}
		printf("%c %-4d%c", suit, rand_order[i] % 13 + 1, (i + 1) % 13 == 0 ? '\n' : ' ');
	}

	return 0;
}
#else
#define CARDS		52
#define CLOVER		0
#define HEART		1
#define SPADE		2
#define DIAMOND		3

int main()
{
	int check[CARDS] = { 0 };
	int cards_order[CARDS] = { 0 };
	int rand_max = 51;
	char suit;

	srand(time(0));
	for (int i = 0; i < CARDS; ++i)
	{
		int x;
		do {
			x = (int)((double)rand() / RAND_MAX * rand_max);
		} while (check[x] != 0);
		check[x] = 1;
		cards_order[i] = x;
	}
	printf("card order[] :\n");
	for (int i = 0; i < CARDS; ++i)
	{
		printf("%-5d%c", cards_order[i], (i + 1) % 13 == 0 ? '\n' : ' ');
	}printf("\n");

	printf("card:\n");
	for (int i = 0; i < CARDS; ++i)
	{
		int denom = cards_order[i] % 13 + 1;
		switch (cards_order[i] / 13) {
		case CLOVER:
			suit = 'C';
			break;
		case HEART:
			suit = 'H';
			break;
		case SPADE:
			suit = 'S';
			break;
		case DIAMOND:
			suit = 'D';
			break;
		}
		printf("%c %-4d%c", suit, denom, (i + 1) % 13 == 0 ? '\n' : ' ');
	}

	return 0;
}
#endif // 1



#endif // 1