#if 0
#define MAX_N (10+2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
int map[MAX_N][MAX_N];
int black[MAX_N][MAX_N];
int white[MAX_N][MAX_N];

int max_count = -999;
int up_M[MAX_N + MAX_N];
int down_M[MAX_N + MAX_N];

void InputData() {
#if 1
	(void)freopen("J1662.txt", "r", stdin);
#endif // 1
	(void)scanf("%d ", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			(void)scanf(" %d", &map[i][j]);
		}
	}
}

void PrintData() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			(void)printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int check(int R, int C) {
	/*UP*/
	if ((up_M[R + C] == 0) &&
		(down_M[R - C + N] == 0)) {
		return 1;
	}
	return 0;
	/*down*/
}

int DFS(int R, int C, int count) {
	if (L >= N*N) {
		if(count > max_count)
		max_count = count;
		return max_count;
	}
	if ((R + C) % 2) {
		if (R % 2) {
			DFS(R + 1, 1, count);
		}
		DFS(R + 1, 0, count);
	}
	for (int C = R; C < N; C += 2) {
		if (map[R][C] == 1 && check(R, C)) {
			map[R][C] = 0;
			up_M[R + C] = 1;
			down_M[R - C + N] = 1;

			DFS(R + 1, count + 1);

			up_M[R + C] = 0;
			down_M[R - C + N] = 0;
			map[R][C] = 1;
		}
	}
}
int main() {
	InputData();
	//PrintData();
	
	int even = DFS(0, 0, 0);
	max_count = -999;
	int odd = DFS(0, 1, 0);

	printf("%d\n", even + odd);
}
#endif // 1
