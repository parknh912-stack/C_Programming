#include "___AAA___.h"
#if 0
#define MAX_N (100 + 1)

char** map;
int N, M;
int R, C;
int S, K;
int count = 0;
typedef struct _dir {
	int r;
	int c;
}DIR;
DIR dir[8] = {
	{-2,-1},	//11시
	{-2,1},	//1시
	{-1,-2},	//10시
	{-1,2},	//3시
	{1,-2},		//8시
	{1,2},		//4시
	{2,-1},		//7시
	{2,1}		//5시
};

void InputData() {
	(void)scanf("%d %d", &N, &M);
	(void)scanf("%d %d", &R, &C);
	(void)scanf("%d %d", &S, &K);
}

int getMem() {
	N += 1;
	M += 1;
	map = (char**)calloc(N, sizeof(char*));
	if (map == NULL) exit(1);
	map[0] = (char*)calloc(N * M, sizeof(char));
	if (map[0] == NULL) exit(1);

	for (int i = 1; i < N; ++i) {
		map[i] = map[0] + i * M;
	}

}
void freeMem() {
	free(map[0]);
	map[0] = NULL;
	free(map);
	map = NULL;
}
int DFS(int L) {
	int nR, nC;
	if (N > L)
		return;
	for (int i = 0; i < 8; ++i) {
		nR = R + dir[i].r;
		nC = C + dir[i].c;
		
	}
}
int main() {
	InputData();
	getMem();

	count++;
	DFS(1);

	freeMem();
	return 0;
}
#endif