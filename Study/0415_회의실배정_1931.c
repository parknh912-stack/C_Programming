// 회의실 배정
// 백준 1931 https://www.acmicpc.net/problem/1931
// 정올 1370 https://jungol.co.kr/problem/1370
// 그리디 알고리즘, 정렬

#if 1
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_N (100000 + 1)
int32_t N;

typedef uint64_t CLOCK;
typedef struct data {
	CLOCK start;
	CLOCK end;
}DATA;

DATA ary[MAX_N];
CLOCK current_time = 0;
int32_t count = 0;

void input_data()
{
	(void)freopen("1931.txt", "r", stdin);
	(void)scanf("%d", &N);
	for (int32_t i = 0; i < N; ++i)
	{
		(void)scanf("%llu %llu", &ary[i].start, &ary[i].end);
	}
}

void print_data()
{
	printf("N = %d\n", N);
	for (int32_t i = 0; i < N; ++i)
	{
		printf("%llu %llu\n", ary[i].start, ary[i].end);
	}
}

int compare(const void* a, const void* b) {
	const DATA* pa = (const DATA*)a;
	const DATA* pb = (const DATA*)b;
	if (pa->end == pb->end)
	{
		return (pa->start > pb->start) - (pa->start < pb->start);
	}
	return (pa->end > pb->end) - (pa->end < pb->end);
}

void sort_data()
{
	qsort(ary, N, sizeof(DATA), compare);
}

void count_data()
{
	for (int i = 0; i < N; ++i)
	{
		if (ary[i].start >= current_time)
		{
			count++;
			current_time = ary[i].end;
		}
	}
}


int32_t main()
{
	input_data();
	sort_data();
	count_data();
	printf("%d", count);

	return 0;
}
#endif // 0

/*
아이디어 메모
--- 그리드 알고리즘 ---
현재 가장 좋다고 판단한 값을 우선적으로 취함 -> 반복

--- 조건 ---
Greedy Choice : 현재 선택이 이후 선택에 영향 X
최적 부분구조 : 해당 문제의 최적 솔류션 -> 부분 문제 솔류션으로 구성

--- 입력 ---
N : 회의의 수 [1,100,000]
각 회의의 정보 : 시작시간, 종료시간 [0 ~ 2^31-1] -> uint64_t

--- 출력 ---
최대 사용할 수 있는 회의의 최대 갯수


--- 문제 분석 ---
회의실이 1개인데, N개의 회의에 대한 사용표 작성하려고함 ㅇㅇ

조건
1. 회의 시간 겹치면 안됌
2. 회의는 중단되지 않음 + 끝나자마자 시작하는거 가능
3. 시작하자마자 끝낼 수 도 있음

sort일단 해야하고
종료 시간을 기준으로 sort 하고
앞에서부터 더하면서 하면 될듯


*/