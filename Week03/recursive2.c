#define TEST_RECURSIVE2 0

#include "___AAA___.h"

/*재귀(123), 난 역순출력씀6 by 남0현*/
#if TEST_RECURSIVE2 == 1

int arr[10] = { 0 };
int num;

/*저장한 arr[num] 부터 역순 출력*/
void print_arr() {
	for (int i = num; i > 0; --i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test(int N) {
	if (N == 0) {		//자릿수가 0이 되면, 해당 배열을 출력하고 리턴.
		print_arr();
		return;
	}
	for (int i = 1; i <= 3; ++i) {
		arr[N] = i;		//배열에 i를 넣는다.
		test(N - 1);	//아랫자리 수로 이동
	}
}

int main(void) {
	int N;
	(void)scanf("%d", &N);
	num = N;
	test(N);
}
#endif

/* TEST 1의 강사님버전 정순출력*/
#if TEST_RECURSIVE2 == 2

int arr[10] = { 0 };
int N = 3;

/*저장한 arr[num] 부터 역순 출력*/
void print_arr(int L) {
	for (int i = 1; i < L; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test(int L) {
	if (L > N) {		//자릿수가 0이 되면, 해당 배열을 출력하고 리턴.
		print_arr(L);
		return;
	}
	for (int i = 1; i <= 3; ++i) {
		arr[L] = i;		//배열에 i를 넣는다.
		test(L + 1);	//아랫자리 수로 이동
	}
}

int main(void) {
	test(1);
	return 0;
}
#endif

//★TEST 2에서 중복제거 (visited) 추가
#if TEST_RECURSIVE2 == 3
int arr[10] = { 0 };
int visited[10] = { 0 };
int N;

/*저장한 arr[num] 부터 역순 출력*/
void print_arr(int L) {
	for (int i = 1; i < L; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test(int L) {
	if (L > N) {		
		print_arr(L);
		return;
	}
	for (int i = 1; i <= 3; ++i) {
		if (visited[i] == 0) {	//방문하지 않았을 때.
			arr[L] = i;
			visited[i] = 1;		//방문했다고 표시하고,
			test(L + 1);		//다음 자리 ㄱㄱ
			visited[i] = 0;		//결국 돌아온 다음에, 해당 자리 방문 초기화
		}
	}
}
int main(void) {
	(void)scanf("%d", &N);
	test(1);
}

#endif

//현재 배열의 값을 이전 배열의 값들과 비교하는걸로 중복제거 구현
//근데 훨씬 더 복잡해서 쓰지 말것.
//한번쯤은 볼만하긴해 ㅇㅇ
#if TEST_RECURSIVE2 == 4
int arr[10] = { 0 };
int visited[10] = { 0 };
int N;

/*저장한 arr[num] 부터 역순 출력*/
void print_arr(int L) {
	for (int i = 1; i < L; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test(int L) {
	if (L > N) {
		print_arr(L);
		return;
	}
	for (int i = 1; i <= 3; ++i) {
		int flag = 0;		//continue를 위한 flag
		for (int j = 1; j < L; ++j) {
			if (arr[j] == i) {	//이전에 넣은 숫자 [1,L) == 현재 넣으려는 숫자
				flag = 1;		//flag 활성화
				break;			//break (하나라도 같으면 continue 할거니까)
			}
		}
		if (flag) continue;		//만약 같은 숫자가 있으면 -> 재귀 미실행, 다른 숫자 넣기
		arr[L] = i;
		test(L + 1);	
	}
}

int main(void) {
	(void)scanf("%d", &N);
	test(1);
}
#endif

//백준 - 바이러스 #2606
#if TEST_RECURSIVE2 == 5
#define MAX_N (100+1)
int adjM[MAX_N][MAX_N];
int adjL[MAX_N][MAX_N];
int visited[MAX_N];
int V, E;

int count = 0;

void inputDataM(void) {
	int from, to;
	(void)scanf("%d", &V);
	(void)scanf("%d", &E);
	for (int i = 1; i <= E; ++i) {
		(void)scanf("%d %d", &from, &to);
		adjM[from][to] = 1;
		adjM[to][from] = 1;
	}
}

void inputDataL(void) {
	for (int from = 1; from <= V; ++from) {
		int index = 2;
		for (int to = 1; to <= V; ++to) {
			if (adjM[from][to] == 1) {
				adjL[from][1]++;
				adjL[from][index] = to;
				index++;
			}
		}
	}
}

//void inputDataL2(void) {
//	int from, to;
//	int* pA, * pB;
//	(void)scanf("%d", &V);
//	(void)scanf("%d", &E);
//	for (int i = 1; i <= E; ++i) {
//		(void)scanf("%d %d", &from, &to);
//		pA = adjL[from];
//		pB = adjL[to];
//		//++adjL[from][0];
//		pA[++pA[0]] = to;
//		//++adjL[to][0]
//		pB[++pB[0]] = from;
//	}
//}

void print_adjM() {
	for (int from = 1; from <= V; ++from) {
		for (int to = 1; to <= V; ++to) {
			printf("%d ", adjM[from][to]);
		}
		printf("\n");
	}
}

void print_adjL() {
	for (int from = 1; from <= V; ++from) {
		for (int to = 1; to <= V; ++to) {
			printf("%d ", adjL[from][to]);
		}
		printf("\n");
	}
}
//L : 웜 바이러스에 감염된 정점 번호
//i : 연결된 정점 번호
int testM(int L) {
	++count;
	for (int i = 1; i <= V; ++i) {
		if ((adjM[L][i] == 1) && (visited[i] == 0)) {
			visited[i] = 1;
			testM(i);
		}
	}
}
//인접 리스트
//L : 웜 바이러스에 감염된 정점 번호
//i : index 번호 ->
//adj[L][1] : 연결된 컴퓨터 갯수
//adj[L][i] : 연결된 컴퓨터 번호 (i : 2 ~ )
int testL(int L) {
	++count;
	int next;
	for (int i = 2; i <= adjL[L][1] + 1; ++i) {
		next = adjL[L][i];
		if (visited[next] == 0) {
			visited[next] = 1;
			testL(next);
		}
	}
}
int main() {
	(void)freopen("B2606.txt", "r", stdin);
	memset(adjM, 0, sizeof(adjM));
	memset(visited, 0, sizeof(visited));
	/*
	배열의 인덱스 : 1~N 까지임. (0은 미사용)
	*/
	inputDataM();
	inputDataL();
	 
	print_adjM();
	printf("*************\n");
	print_adjL();

	/*초기화*/
	count = 0;
	visited[1] = 1;

	testM(1);
	printf("count M : %d\n", count - 1);

	/*초기화*/
	count = 0;
	memset(visited, 0, sizeof(visited));
	visited[1] = 1;

	testL(1);
	printf("count L : %d\n", count - 1);

	return 0;
}
#endif

//백준 - NQueen #9663 https://www.acmicpc.net/problem/9663 / 정올 https://jungol.co.kr/problem/1889
#if TEST_RECURSIVE2 == 6
#define MAX_N (15+1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N;
int Matrix[MAX_N][MAX_N];
int count = 0;
int up_M[MAX_N + MAX_N];
int down_M[MAX_N + MAX_N];
int col_M[MAX_N];

int check(int R, int C) {
	/*UP 체크*/
	if ((up_M[R + C] == 0) && 
		(down_M[R - C + N] == 0) && 
		(col_M[C]) == 0) {
		return 1;
	}
	return 0;
	/*down 체크*/
}
void Nqueen(int R) {
	if (R > N) {
		count++;
		return;
	}
	for (int C = 1; C <=N; ++C) {
		if (check(R, C)) {
			up_M[R + C] = 1;
			down_M[R - C + N] = 1;
			col_M[C] = 1;
			Nqueen(R + 1);
			up_M[R + C] = 0;
			down_M[R - C + N] = 0;
			col_M[C] = 0;
		}
	}
}

int main(void) {
	(void)scanf("%d", &N);
	Nqueen(1);
	printf("%d", count);
	return 0;
}
#endif

//정올 - 해밀턴 순환회로 https://jungol.co.kr/problem/1681
#if TEST_RECURSIVE2 == 7
#define MAX_N (13+1)
#include <limits.h>

int N;
int place_cost[MAX_N][MAX_N];
int visited[MAX_N] = { 0 };
int sum_cost;
int min_cost = INT_MAX;
int move_count;
void input_data() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			(void)scanf("%d", &place_cost[i][j]);
		}
	}
}

void print_data() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%3d ", place_cost[i][j]);
		}printf("\n");
	}
}
int compare_min_cost(int sum_cost) {
	if (min_cost > sum_cost)
		min_cost = sum_cost;
	return min_cost;
}

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

int main(void) {
	(void)freopen("J1681.txt", "r", stdin);
	(void)scanf("%d", &N);
	input_data();
	print_data();

	move_count = 0;
	sum_cost = 0;
	move_place(1, 1);
	printf("%d", min_cost);

	return 0;
}
#endif