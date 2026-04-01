#if 0
//정올 - 1681 해밀턴 순환회로 https://jungol.co.kr/problem/1681
//주석 및 순서 업데이트 (26.03.20)
#define MAX_N (15+2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*---전역 변수 및 배열 선언---*/
int N;
int place_cost[MAX_N][MAX_N];
int visited[MAX_N] = { 0 };
int sum_cost;
int min_cost = INT_MAX;
int move_count;

/*---함수 선언---*/
void input_data();
void print_data();
int compare_min_cost(int sum_cost);
void move_place(int L, int depth);

/*---Main---*/
int main(void) {
	//(void)freopen("J1681.txt", "r", stdin);
	(void)scanf("%d", &N);
	input_data();
	//print_data();

	move_count = 0;
	sum_cost = 0;
	move_place(1, 1);
	printf("%d", min_cost);

	return 0;
}

/*이하 함수 정의*/

/*Input*/
void input_data() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			(void)scanf("%d", &place_cost[i][j]);
		}
	}
}

/*Print*/
void print_data() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%3d ", place_cost[i][j]);
		}printf("\n");
	}
}
/*최소 코스트 비교용*/
int compare_min_cost(int sum_cost) {
	if (min_cost > sum_cost)
		min_cost = sum_cost;
	return min_cost;
}

/*1열 : 회사까지 가는 코스트 -> 가장 나중에 가야함 -> depth가 N일때 간다.
가장 경제적인 루트를 구하는 법
minimum cost : 재귀함수의 가장 마지막에서만 수정가능
current cost를 재귀 직전에 minimum cost와 비교하여, 작을 경우에만 재귀한다.
*/
void move_place(int L, int depth) {
	if (depth == N) {
		if ((visited[1] == 0) && (place_cost[L][1] != 0)) {
			sum_cost += place_cost[L][1];
			min_cost = compare_min_cost(sum_cost);
			sum_cost -= place_cost[L][1];
			return;
		}
	}
	for (int next = 2; next <= N; ++next) {
		if ((visited[next] == 0) && (place_cost[L][next] != 0)) {
			sum_cost += place_cost[L][next];
			if (sum_cost < min_cost) {
				visited[next] = 1;
				move_place(next, depth + 1);
				visited[next] = 0;
			}
			sum_cost -= place_cost[L][next];
		}
	}
}
#endif

#if 0
/*
개선사항
1. sum_cost를 move_place의 argument화

*/
#define MAX_N (15+2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*---전역 변수 및 배열 선언---*/
int N;
int cost[MAX_N][MAX_N];
int visited[MAX_N] = { 0 };
//int sum_cost;
int min_cost = INT_MAX;
//int move_count;

/*---함수 선언---*/
void input_data();
void print_data();
void move_place(int L, int depth, int sum_cost);

/*---Main---*/
int main(void) {
	//(void)freopen("J1681.txt", "r", stdin);
	(void)scanf("%d", &N);
	input_data();
	//print_data();

	//move_count = 0;
	move_place(1, 1, 0);
	printf("%d", min_cost);

	return 0;
}

/*이하 함수 정의*/

/*Input*/
void input_data() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			(void)scanf("%d", &cost[i][j]);
		}
	}
}

/*Print*/
void print_data() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%3d ", cost[i][j]);
		}printf("\n");
	}
}

/*1열 : */
void move_place(int L, int depth, int sum_cost){
	if (depth == N) {
		if (cost[L][1] != 0) {
			if (min_cost > sum_cost)
				min_cost = sum_cost + cost[L][1];
		}
		return;
	}
	for (int next = 2; next <= N; ++next) {
		if (visited[next]) continue;
		if (cost[L][next] == 0) continue;

		if ((sum_cost + cost[L][next]) < min_cost) {
			visited[next] = 1;
			move_place(next, depth + 1, sum_cost + cost[L][next]);
			visited[next] = 0;
		}
	}
}
#endif // 0


/* 무시 */
#if 0
int N = 4;
int visited[10];
int arr[10];
void print_arr(void) {
	for (int i = 1; i <= N; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void DFS(int L, int cost) {
	if (L > N) {
		print_arr();
		return;
	}
	for (int i = 2; i <= N; ++i) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		arr[L] = i;
		DFS(L + 1, cost + L);
		//arr[L] = 0;
		visited[i] = 0;
	}
}

void inputData() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			(void)scanf("%d", &map[i][j]);
			cost[i][j] = INT_MAX;
		}
	}
}

int main(void) {
	(void)freopen("J1681.txt", "r", stdin);

	visited[1] = 1;  // 해도 되고 안해도 되고
	arr[1] = 1; //첫번째 선택 완료
	DFS(1, 0);
	return 0;
}
#endif
