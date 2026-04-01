//정올 1111 등산로 https://jungol.co.kr/problem/1111

#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 등산로
#define MAX_N (100 + 2)
#define INF (10000)
int map[MAX_N][MAX_N];
int cost[MAX_N][MAX_N]; //해당 좌표까지의 비용 저장
int N;
int dR, dC; // 산 정상 좌표
typedef struct _node {
	int r;
	int c;
}node;
node Queue[MAX_N * MAX_N * 10];
int front, rear;

void inputData(void) {
	(void)scanf("%d", &N);
	(void)scanf("%d %d", &dR, &dC);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cost[i][j] = INF;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			(void)scanf("%d", &map[i][j]);
			if ((i == 1) || (i == N) || (j == 1) || (j == N)) {
				Queue[rear++] = (node){ i, j };
				cost[i][j] = map[i][j] * map[i][j];
			}
		}
	}
}

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };


int BFS(void) {
	int nR, nC, i;
	node curr;
	int nCost; // curr -> (nR, nC)로 가는 추가비용

	while (front != rear) {
		curr = Queue[front++];
		//if (curr.r == dR && curr.c == dC) continue; // 정상에 도착했으면 탐색 더 X

		for (i = 0; i < 4; i++) {
			nR = curr.r + dx[i];
			nC = curr.c + dy[i];

			if (nR < 1 || nR > N || nC < 1 || nC > N) continue; // 경계 검사

			if (map[nR][nC] <= map[curr.r][curr.c]) {    // 내리막, 평지
				nCost = map[curr.r][curr.c] - map[nR][nC];
			}
			else {    // 오르막
				nCost = (map[nR][nC] - map[curr.r][curr.c]) * (map[nR][nC] - map[curr.r][curr.c]);
			}

			if (cost[nR][nC] > cost[curr.r][curr.c] + nCost) {
				cost[nR][nC] = cost[curr.r][curr.c] + nCost;
				Queue[rear++] = (node){ nR, nC };
			}
		}
	}
	return cost[dR][dC];
}
int main(void) {
	inputData();
	printf("%d\n", BFS());
	return 0;
}

#endif // 0
