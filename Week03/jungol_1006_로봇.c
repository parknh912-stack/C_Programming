//정올 1006 로봇 https://jungol.co.kr/problem/1006
//미완성
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_N (100+2)

/*전역 변수 & 배열*/
typedef struct _node {
	int r, c, curr_dir;
}node;

typedef struct _queue {
	int front;
	int rear;
	node data[125000];
}Queue;

node dir[4] = {
	{-1,0},		//상
	{1,0},		//하
	{0,-1},		//좌
	{0,1}		//우
};

int R, C;					//맵 크기
int sR, sC, sD, eR, eC, eD;
int** map = NULL;			//map 2차원 배열
//int** visited = NULL;		//방문표시 2차원배열
Queue queue;				//queue 선언


/*함수 선언*/
void getInputMem();
void freeMem();
void inputData();
void printData();
void BFS();


/*메인함수*/
int main() {
	getInputMem();
	inputData();
	//printData();


	freeMem();
	return 0;
}


/*이하 함수 정의*/
void getInputMem() {
	(void)scanf("%d %d", &R, &C);
	map = (int**)calloc(R, sizeof(int*));
	if (map == NULL) exit(1);

	map[0] = (int*)calloc(R * C, sizeof(int));
	if (map[0] == NULL) exit(1);

	for (int i = 1; i < R; ++i) {
		map[i] = map[0] + i * C;
	}
}


void freeMem() {
	free(map[0]);
	map[0] = NULL;
	free(map);
	map = NULL;
}

void inputData() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			(void)scanf("%d ", &map[i][j]);
		}
	}
	(void)scanf("%d %d %d", &sR, &sC, &sD);
	(void)scanf("%d %d %d", &eR, &eC, &eD);
	sD = 4 - sD;
	eD = 4 - eD;
}

void printData() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

/*
시작점 : n개 -> 1개씩 사용
인접 : 상하좌우 + 육지사이에서만 이동
종료점 : 없음. 완주해야함
큐 : r,c
방문표시 : visited 2차원배열
*/
void BFS() {
	int nR, nC;

	node curr;

	queue.data[queue.rear++] = (node){ sR, sC, sD };

	while (queue.front != queue.rear) {
		curr = queue.data[queue.front++];
		for (int i = 0; i < 4; ++i) {
			
			nR = curr.r + dir[i].r;
			nC = curr.c + dir[i].c;
			if ((nR >= 0) && (nR < R) && (nC >= 0) && (nC < C)) {

				}
			}
		}
	}
}

#endif // 1
