// PART 01 - 총 25문제
#include "practice.h"

#if PART == 1

// ==================== 문제 01 ====================
#if PROBLEM == 1

/*
문제: 정수를 배열에 저장하고, 최소값, 최대값, 평균값 계산하기

풀이 아이디어: 정수 입력 받아서, sum에다가 다 더하고, min과 max를 비교하면서 갱신하고, 마지막에 평균값 계산

*/

int main(void)
{
	int arr[10];
	int min = INT16_MAX;
	int max = INT16_MIN;
	int sum = 0;


	for (int i = 0; i < 10; i++) {
		printf("%d번째 숫자를 입력하세요.", i + 1);
		scanf("%d", &arr[i]);

		sum += arr[i];	//평균을 구하기 위해서

		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	printf("최소값 : %d\n", min);
	printf("최대값 : %d\n", max);
	printf("평균값 : %.2f\n", (float)sum / 10);
	return 0;
}

#endif // PROBLEM == 1

// ==================== 문제 02 ====================
#if PROBLEM == 2

/*
문제: 랜덤 숫자 만들기

풀이 아이디어: 대충 rand() 함수 쓰면 된다 ㅇㅇ

*/

int main(void)
{
	int arr[10];
	int dice[30];
	int rand_min = 1;
	int rand_max = 6;

	srand(time(0));		//시드 매번 초기화 해주는거
	for (int i = 0; i < 30; i++) {
		dice[i] = rand() % (rand_max - rand_min + 1) + rand_min;
		printf("%6d%c", dice[i], (i + 1) % 10 != 0 ? ' ' : '\n');
	}

	return 0;
}

#endif // PROBLEM == 2

// ==================== 문제 03 ====================
#if PROBLEM == 3

/*
문제: 주사위 2개를 백만번 던져서 나오는 두 주사위 숫자의 합을 배열에 저장 및 확률 출력

풀이 아이디어: 두 주사위를 랜덤한 값으로 뱉어서, 더하면 2~12 거든요? 아마 중간값이 제일 확률이 높겠죠?
1. 주사위를 2개를 던진다.
2. 주사위를 더한다
3. 배열에 저장한다.
4. 확률을 계산한다
5. 확률을 출력한다.

*/
#define TRIALS 1000000
int main(void)
{
	int sum[13] = { 0 };	// 합은 2 ~ 12 까지니까.. 그냥 대충 0 ~ 12 저장하는 배열로 만들자.
	int rand_min = 1;
	int rand_max = 6;
	int dice;
	
	srand(time(0));

	for (int i = 0; i < TRIALS; i++)
	{
		dice = (rand() % (rand_max - rand_min + 1) + rand_min;) + (rand() % (rand_max - rand_min + 1) + rand_min;);
		sum[dice]++;	//횟수 셀때 이런거 자주 쓰임 ㅇㅇ
	}
	int total = 0;
	for (int j = 2; j < 13; j++) {
		printf("sum[%d] = %d 번, %.2f %%\n", j, sum[j], (float)sum[j] / TRIALS * 100);
		total += sum[j];
	}
	printf("TRIALS = %d\n", total);
	return 0;
}

#endif // PROBLEM == 3

// ==================== 문제 04 ====================
#if PROBLEM == 4

/*
문제: 겹치지 않는 1~10까지의 랜덤 숫자 출력

풀이 아이디어:	visited[] 만들어서, 체크할거 같아요 저라면.
1. 랜덤 숫자를 뽑는다.
2. visited와 대조한다.
3. 중복 아니면, true로 만들고, 결과에 넣는다.
4. 결과 (배열)을 출력한다.


참고 : 피셔-에이츠 방식이 더 반복횟수도 적고 좋지만, 해당 문제의 핵심은 중복검사이므로 제외함
*/

int main(void)
{
	bool visited[11] = { false };
	int rand_min = 1;
	int rand_max = 10;
	int number[10];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		int rand_number;
		while (1) {
			rand_number = rand() % (rand_max - rand_min + 1) + rand_min;
			if (visited[rand_number] == false) {
				visited[rand_number] = true;
				number[i] = rand_number;
				break;
			}
		}
	
		printf("%6d%c", number[i], (i + 1 ) % 5 != 0 ? ' ' : '\n');
	}

	return 0;
}

#endif // PROBLEM == 4

// ==================== 문제 05 ====================
#if PROBLEM == 5

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 5

// ==================== 문제 06 ====================
#if PROBLEM == 6

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 6

// ==================== 문제 07 ====================
#if PROBLEM == 7

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 7

// ==================== 문제 08 ====================
#if PROBLEM == 8

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 8

// ==================== 문제 09 ====================
#if PROBLEM == 9

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 9

// ==================== 문제 10 ====================
#if PROBLEM == 10

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 10

// ==================== 문제 11 ====================
#if PROBLEM == 11

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 11

// ==================== 문제 12 ====================
#if PROBLEM == 12

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 12

// ==================== 문제 13 ====================
#if PROBLEM == 13

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 13

// ==================== 문제 14 ====================
#if PROBLEM == 14

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 14

// ==================== 문제 15 ====================
#if PROBLEM == 15

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 15

// ==================== 문제 16 ====================
#if PROBLEM == 16

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 16

// ==================== 문제 17 ====================
#if PROBLEM == 17

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 17

// ==================== 문제 18 ====================
#if PROBLEM == 18

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 18

// ==================== 문제 19 ====================
#if PROBLEM == 19

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 19

// ==================== 문제 20 ====================
#if PROBLEM == 20

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 20

// ==================== 문제 21 ====================
#if PROBLEM == 21

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 21

// ==================== 문제 22 ====================
#if PROBLEM == 22

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 22

// ==================== 문제 23 ====================
#if PROBLEM == 23

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 23

// ==================== 문제 24 ====================
#if PROBLEM == 24

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 24

// ==================== 문제 25 ====================
#if PROBLEM == 25

/*
문제:

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 25

#endif // PART == 1
