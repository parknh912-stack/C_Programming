// 랜선자르기, 백준 1654 https://www.acmicpc.net/problem/1654
// Binary_search

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N (10000 + 1)

int N, K;
unsigned int ary[MAX_N];
long long max_length;

void input_data()
{
	(void)freopen("1654.txt", "r", stdin);
	(void)scanf("%d %d", &K, &N);
	for (int i = 0; i < K; ++i)
	{
		(void)scanf("%d", &ary[i]);
	}
}

void print_data()
{
	printf("K = %d, N = %d\n", K,N);
	for (int i = 0; i < K; ++i)
	{
		printf("%d ", ary[i]);
	}printf("\n");
}

void find_max_length()
{
	long long temp = 0;
	for (int i = 0; i < K; ++i)
	{
		temp += ary[i];
	}
	max_length = temp / N;
}

int check_length_count(long long length)
{
	long long count = 0;
	
	for (int i = 0; i < K; ++i) 
	{
		count += (ary[i] / length);
	}
	//printf("count = %d\n", count);
	if (count >= N) return 1; // 짧을 때
	else if (count < N) return -1; // 길 때
	
	return 0;
}

void binary_search(long long length)
{
	long long L = 1;
	long long R = length;
	long long M = 1;
	long long ret = 0;
	int is_short;

	while (L <= R)
	{
		M = (L + R) / 2;
		is_short = check_length_count(M);

		if (is_short > 0)
		{
			ret = M;
			L = M + 1;
		}
		else if (is_short < 0)
		{
			R = M - 1;
		}
		else exit(1);
	}
	//printf("M = ");
	printf("%lld\n", ret);
}

int main()
{
	input_data();
	//print_data();
	find_max_length();
	//printf("max length : %d\n", max_length);
	binary_search(max_length);

	return 0;
}

/* 아이디어 메모
K개의 랜선으로 N개의 같은 길이의 랜선을 만드는 문제
K랑 N이 주어지고, K는 1~10000의 정수, N 1~1,000,000 정수 K<=N


합계를 쓰는건 맞는거 같아. 그리고 그걸 N으로 나눈 값이 있고, 이것보다 무조건 짧을 수 밖에 없다.

최대 길이에서... 계속 작아지는데, 어느 순간 저 조건을 만족하면 멈추고, 길이를 반환하는건가...?
시간 제한에 안될거 같은데...결국 최대 길이보다 짧고, 조건 만족시 멈춤

최대 길이의 절반 -> 이것보다 긴가 짦은가? (이진탐색) 
조건 : 각 길이별로 했을때 N개가 나오는가 -> 함수화
갯수를 셌을 때,
1. N보다 많을 때 -> 짧은 것 -> 길어져야함 -> L 위치 이동 ( M < wish_length )
2. N보다 적을 때 -> 긴 것 -> 짧아져야함 -> R 위치 이동	( M > wish_length )
3. N과 같을 때 -> 짧은 것으로 간주해야돼 -> 길어져야함 (우리는 최대 길이를 구하는 거니까)

탈출 조건 : 한번 더 했을 때 (L > R) 이 순간에만 멈출 수 있다.


제출 완료 (정답)

배운점
1. 오버플로우를 조심하자. long long 같은 매우 큰 정수를 감당가능한 자료형을 사용할 것.
그리고 가능하면 
#include <stdint.h> 에 있는
int32_t == int
int64_t == longlong
uint64_t == unsigned long long
이런걸 쓰자

2. 무한반복으로 빼지말고 나눗셈으로 몫...챙기자
3. 이진탐색의 맹점. 종료조건 주의
*/