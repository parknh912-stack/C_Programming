// 0401 - 이진탐색 - 도약 #2788 https://jungol.co.kr/problem/2788

// --- 함수 선언
#define JUMP0401 1
#if JUMP0401 == 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_N (1000 + 1)
int ary[MAX_N];
int N;


// --- Function Prototypes
void input_data();
void print_data();
int compare_int(const void* a, const void* b);
int jump();
int binary_search_lower(int value);
int binary_search_upper(int value);

// --- Main
int main()
{
	input_data();
	qsort(ary, N, sizeof(int), compare_int);

	int res = jump();
	printf("%d\n", res);
	return 0;
}


// --- Functions
/*
1. input_data() : 숫자 입력부
2. print_data() : 입력 확인용 (test용)
3. compare_int() : qsort를 위한 기준 함수
4. jump() : 개구리 도약 함수, O(n^2 * log(n))
			이중 for문 : 기준이 될 2번째 연잎 선택
			이진 탐색 : lower, upper의 index 검색 -> count를 구함
5. binary_search_lower : 기준 숫자와 같거나, 기준 숫자보다 (기준숫자 바로 위 index) return 
6. binary_search_upper : 기준 숫자와 같거나, 기준 숫자보다 (기준숫자 바로 아래 index) return
	5 & 6 에서 주어진 배열 size보다 큰 경우엔 -1 return
*/
void input_data()
{
	(void)scanf(" %d", &N);
	for (int i = 0; i < N; ++i) {
		(void)scanf(" %d", &ary[i]);
	}
}

void print_data()
{
	for (int i = 0; i < N; ++i) {
		printf("%d ", ary[i]);
	}
	printf("\n");
}

int compare_int(const void* a, const void* b)
{
	const int* pa = (const int*)a;
	const int* pb = (const int*)b;
	return (*pa > *pb) - (*pa < *pb);
}

// --- 도약 함수
/*
* @brief 개구리가 도약할 수 있는 모든 경우의 수 계산 O(N^2 log N)
* 1번 연잎 (i), 2번 연잎 (j) 고정한 뒤,
* 3번 연잎이 가능한 범위를 이진탐색
*/
int jump()
{
	int d1;
	int lower, upper;
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			d1 = ary[j] - ary[i];	//첫 번째 점프 거리

			// 가능한 3번 연잎의 범위 : [ary[j] + d1, ary[j] + 2 * d1]
			lower = binary_search_lower(ary[j] + d1);
			upper = binary_search_upper(ary[j] + (2 * d1));

			// 잘못된 범위 일 경우 : 카운트 예외
			if (lower == -1 || upper == -1) continue;
			count += (upper - lower + 1);
		}
	}
	return count;
}

/*
* @brief Lower Bound 탐색
*/
int binary_search_lower(int value)
{
	int L = 0;
	int R = N - 1;
	int ret = -1;
	int M;
	while (L <= R)
	{
		M = (int)(L + R) / 2;

		if (ary[M] == value) return M;

		if (value < ary[M]) {
			ret = M;
			R = M - 1;
		}
		else if (value > ary[M]) {
			L = M + 1;
		}
	}
	return ret;
}

/*
* @brief Upper Bound 탐색
*/
int binary_search_upper(int value)
{
	int L = 0;
	int R = N - 1;
	int ret = -1;
	int M;
	while (L <= R)
	{
		M = (int)(L + R) / 2;

		if (ary[M] == value) return M;

		if (value < ary[M]) {
			R = M - 1;
		}
		else if (value > ary[M]) {
			ret = M;
			L = M + 1;
		}
	}
	return ret;
}
#endif // JUMP0401 == 1