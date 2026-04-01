#define TEST_RECURSIVE 0

#include "___AAA___.h"

//DFS 작성을 위한 재귀함수 이해 (숫자 출력, 뒤부터 출력, 역출력, 마름모 등등등)
#if TEST_RECURSIVE == 1
int N = 5;

void test(int L) {			// 1 2 3 4 5
	//int arr[1000] = { 0 };	//지역변수 ->매우큰 영향 , return -> 큰 영향 X
	if (L > N) return 0;		//호출 횟수 : 6회
	printf("%d\n", L);
	if (L >= N) return 0;		//호출 횟수 : 5회
	test(L + 1);
}
void test1(int L) {
	if (L > N) return;
	test1(L + 1);			// 5 4 3 2 1 
	printf("%d ", L);
}
void test2(int L) {			// 1 2 3 4 5 5 4 3 2 1 
	if (L > N) return;
	printf("%d ", L);
	test2(L + 1);
	printf("%d ", L);
}
void test3(int L) {			// 1 2 3 4 5 4 3 2 1 
	printf("%d ", L);
	if (L >= N) return;		//L이 5가 되는 순간, 일단 출력하고, 확인후 리턴하니까, 뒤의 출력이 무시됌
	test3(L + 1);
	printf("%d ", L);
}
void test4(int L) {			// 1 2 3 4 5 1 2 3 4 5
	if (L > N) return;
	printf("%d ", L);
	test4(L + 1);
	printf("%d ", N - L + 1);
}
void test5(int L) {			// * ** *** **** *****	(왼쪽 정렬)
	for (int i = 0; i < L; ++i) {
		printf("*");
	}printf("\n");
	if (L >= N) return;
	test5(L + 1);
}
void test6(int L) {			//    * ** *** **** ***** (오른쪽 정렬 버전)
	for (int i = N; i > L; --i) {
		printf(" ");
	}
	for (int i = 0; i < L; ++i) {
		printf("*");
	}printf("\n");
	if (L >= N) return;
	test6(L + 1);
}
void test7(int L) {			// ***** **** *** ** *
	if (L > N) return;
	test7(L + 1);
	for (int i = 0; i < L; ++i) {
		printf("*");
	}printf("\n");
}
void test8(int L) {            // 마름모 ver.1
	for (int i = 0; i < N - L; ++i) {
		printf(" ");
	}
	for (int i = N - L; i < N + L - 1; ++i) {
		printf("*");
	}
	printf("\n");
	if (L >= N) return;
	test8(L + 1);
	for (int i = 0; i < N - L; ++i) {
		printf(" ");
	}
	for (int i = N - L; i < N + L - 1; ++i) {		//굳이 이렇게 할 필요가 있을까? 그냥 바로 옆에 붙이느거니까 0부터해도 돼잖아.
		printf("*");
	}
	printf("\n");
}
void print_star_plus(int L) {							//위나 아래나 똑같음.
	for (int i = 0; i < N - L; ++i) printf(" ");
	for (int i = 0; i < 2 * L - 1; ++i) printf("*");
	printf("\n");
}
void print_star_minus(int L) {
	for (int i = N; i > L; --i) printf(" ");
	for (int i = 2 * L - 1; i > 0; --i) printf("*");
	printf("\n");
}
void test9(int L) {			// 마름모 ver.2
	print_star_plus(L);
	if (L >= N) return;
	test9(L + 1);
	print_star_minus(L);
}
int main() {
	//test(1);
	//test2(1);
	//test4(1);
	//test5(1);
	test9(1);
	return 0;
}
#endif

//재귀함수 심화 - 3/13 금
#if TEST_RECURSIVE == 2
//for문만으로 해보기 : O(2^n) :파멸적인 시간복잡도
int tot = 0;
void for_test(void) {
	int A[3] = { 4,2,1 };
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				int tot = 0;
				if (i == 1) tot += A[0];
				if (j == 1) tot += A[1];
				if (k == 1) tot += A[2];
				if (tot == 5) printf("%d %d %d\n", i, j, k);
			}
		}
	}
}

//재귀함수 ->
int N = 4;
int arr[10] = { 0 };
int data[10] = {8, 4,2,1 };
int Target = 5;
void print_ary() {
	for (int i = 1; i <= N; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void recursive_test(int L,int cnt) {	//총 시간복잡도 O(2^n)
	if (L > N) {
		printf("cnt = %d : ", cnt);		//사실상 cnt는 1의 갯수를 새는 것과 동일하네?
		print_ary();
		return;
	}
	arr[L] = 0;
	recursive_test(L + 1,cnt);
	arr[L] = 1;
	recursive_test(L + 1,cnt+1);		//내려가면서 cnt값을 가지고 가는 것
}

void recursive_test2(int L) {//총 시간복잡도 O(2^n * n)
	if (L > N) {
		int cnt = 0;
		for (int i = 0; i < L; ++i) {		//마지막 depth에 도달해서야 for문 돌리는 방식 = O(n)
			cnt += arr[i];
		}
		printf("cnt = %d : ", cnt);
		print_ary();
		return;
	}
	for (int i = 0; i < 2; ++i) {
		arr[L] = i;
		recursive_test2(L + 1);
	}
}
//cnt가 2인 경우가 몇 개인지 출력

int T = 0;
int count = 0;
#define num_check 2

void recursive_test3(int L, int cnt) {
	count++;
	if ((num_check - cnt) < (N - (L - 1))) {	//0으로 가고 싶으면 ,남은 1의 갯수 < 남은 하위비트수
		arr[L] = 0;
		recursive_test3(L + 1, cnt);
	}
	if (cnt + 1 == num_check) {		//1로 가려는 순간 -> cnt가 1이면 -> 2가 되는게 확정이니, 중단
		T++;
		return;
	}
	arr[L] = 1;
	recursive_test3(L + 1, cnt + 1);
}
int main(void) {
	//recursive_test(1,0);
	//printf("\n");
	T = 0;
	recursive_test3(1, 0);
	printf(" T = %d", T);
	printf(" count = %d", count);
	return 0;
}
#endif

//강사님이 올려주신 답
#if TEST_RECURSIVE == 3
int N = 5;
int k = 2;
int arr[10] = { 0 };
int data[10] = { 8, 4, 2, 1 };
int T = 0;
int loop = 0;		//몇번 함수를 호출하는가? 에 대한 성능분석을 위한 변수

void print_arr2(int n) {
	printf("%2d: ", loop);
	for (int i = 1; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void make_num3(int L, int cnt) {
	++loop;
	if (L > N) {
		return;
	}
	arr[L] = 0;
	make_num3(L + 1, cnt);
	if (cnt == 1) {
		++T;
		return;
	}
	arr[L] = 1;
	make_num3(L + 1, cnt + 1);
}

void make_num4(int L, int cnt) {
	++loop;
	// 필요한 1의 개수 < 남은 비트 개수  >>>> 0을 넣을 수 있다.
	if ((2 - cnt) < N - (L - 1)) {		//"선택"적인 실행
		arr[L] = 0;
		make_num4(L + 1, cnt);
	}
	if (cnt == 1) {
		++T;
		return;
	}
	arr[L] = 1;
	make_num4(L + 1, cnt + 1);
}

int main(void) {
	N = 4;
	T = loop = 0;
	make_num3(1, 0);
	printf("A : T = %d, loop = %d\n", T, loop);

	T = loop = 0;
	make_num4(1, 0);
	printf("B : T = %d, loop = %d\n\n", T, loop);


}
#endif

//백준 #2667 단지숫자구하기 (재귀함수, 피보나치 수, 좌표이동)
#if TEST_RECURSIVE == 4
#define MAX_N (25+2)
int n;	//배열 사이즈
int** ary = NULL;	//2차원 배열을 저장할 포인터
int address_count[MAX_N*MAX_N] = { 0 };
int P = 0;

void print_ary() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", ary[i][j]);
		}
		printf("\n");
	}
}

void scan_ary() {
	for (int i = 1; i <n-1; ++i) {
		for (int j = 1; j <n-1; ++j) {
			(void)scanf("%1d", &ary[i][j]);
		}
	}
}

int** call_mem() {
	ary = (int**)calloc(n, sizeof(int*));
	if (ary == NULL) exit(1);
	ary[0] = calloc(n*n, sizeof(int));
	if (ary[0] == NULL) exit(1);
	for (int i = 1; i < n; ++i) {
		ary[i] = ary[0] + i * n;
	}
	return ary;
}

void move_map(int R, int C) {
	//값을 읽어서 1 -> 0으로 바꾸고, 카운터 증가
	if (ary[R][C] == 1) {
		ary[R][C] = 0;
		address_count[P]++;
	}
	//하
	if (ary[R + 1][C] == 1) {
		move_map(R + 1, C);
	}
	//우
	if (ary[R][C + 1] == 1) {
		move_map(R, C + 1);
	}
	//상
	if (ary[R - 1][C] == 1) {
		move_map(R - 1, C);
	}
	//좌
	if (ary[R][C - 1] == 1) {
		move_map(R, C - 1);
	}
}

int move_map2(int R, int C) {
	int result = 0;
	if (R < 1 || R > n && C<1 && C > n) return 0;
	if (ary[R][C] == 1) {
		ary[R][C] = 0;
		++result;
		return result + move_map2(R - 1, C) + move_map2(R + 1, C) + move_map2(R, C - 1) + move_map2(R, C + 1);
	}
	return result;
}
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int** mem_release() {
	if (ary == NULL) return NULL;
	free(ary[0]);
	ary[0] = NULL;
	free(ary);
	ary = NULL;
}
int main() {
	/*
	1. 배열 동적 할당
	2. 지정된 txt에서 배열 크기 및 정보 입력
	3. map 출력
	4-1. move_map1 후 단지 수 카운트
	4-2. move_map2 로 단지 수 카운트
	*/
	(void)freopen("b2667.txt", "r", stdin);
	(void)scanf("%d", &n);
	n += 2;

	/*Map Loading*/
	ary = call_mem();
	scan_ary();
	print_ary();
	printf("\n");
#if 1
	/*Ver.1 - move_map1 : 카운트해서 전역변수 address_count에 저장*/
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ary[i][j] == 1) {
				move_map(i, j);
				P++;
			}
		}
	}
	/* Output*/
	qsort(address_count, P, sizeof(int), compare);
	printf("총 단지수 : %d\n", P);
	for (int i = 0; i < P; ++i) {
		printf("count : %d\n", address_count[i]);
	}
	mem_release();
	return 0;
#else
	/*Ver.2 - move_map2: 피보나치 수 이용한 버전*/
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ary[i][j] == 1) {
				address_count[P] = move_map2(i, j);
				P++;
			}
		}
	}
	/* Output*/
	qsort(address_count, P, sizeof(int), compare);
	printf("%d\n", P);
	for (int i = 0; i < P; ++i) {
		printf("count %d\n", address_count[i]);
	}
#endif
}
#endif

//백준 #2667 문경한님 코드 - 효율적인 코드 작성법
#if TEST_RECURSIVE == 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int search(int, int);
int compare(const void*, const void*);
void print_result();
void get_input();

int N;
int arr[25][25] = { 0 };
int size_list[625] = { 0 };
int size = 0;

int main() {
	get_input();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == 1) {
				size_list[size++] = search(i, j);
			}
		}
	}

	// 배열 정렬
	qsort(size_list, size, sizeof(int), compare);

	print_result();
}

int search(int r, int c) {
	int result = 0;
	if (r < 0 || N <= r || c < 0 || N <= c) return 0;
	if (arr[r][c] == 1) {
		arr[r][c] = 0;
		++result;
		return result + search(r - 1, c) + search(r + 1, c) + search(r, c - 1) + search(r, c + 1);
	}
	return 0;
}

// 입력 받는 함수
void get_input() {
	(void)(scanf("%d", &N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			(void)scanf("%1d", &arr[i][j]);
		}
	}
}

// qsort 비교용 함수
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void print_result() {
	printf("%d\n", size);
	for (int i = 0; i < size; ++i) {
		printf("%d", size_list[i]);
		if (i != size - 1) {
			printf("\n");
		}
	}
}
#endif

//백준 #2667 김진수님 코드 - 코딩 스타일, enum 사용, 주석 사용법 등을 참고할만하다
#if TEST_RECURSIVE == 6
#if 1

#define TEST_AUTO        (0)

typedef enum {
	ePOS_X = 0,
	ePOS_Y,
	ePOS_MAX
} ePOS;

typedef enum {
	eDIR_L = 0,
	eDIR_R,
	eDIR_U,
	eDIR_D,
	eDIR_MAX
} eDIR;

int move_pos[eDIR_MAX][ePOS_MAX] = {
	[eDIR_L] = {-1, 0},
	[eDIR_R] = {+1, 0},
	[eDIR_U] = {0, +1},
	[eDIR_D] = {0, -1}
};

typedef enum { MAP_X_MAX = 0xFF, MAP_Y_MAX = 0xFF, MAP_MARGIN = 2 };

/* map의 최대 크기 */
int pos_max[ePOS_MAX];
/* 테두리는 0으로 채움 */
char map[MAP_Y_MAX + MAP_MARGIN][MAP_X_MAX + MAP_MARGIN];
int area_cnt = 0;
int area_size[MAP_X_MAX * MAP_X_MAX];

void remove_area_dfs(int pos_x, int pos_y)
{
	for (eDIR iMove = 0; iMove < eDIR_MAX; iMove++) {
		int iY = pos_y + move_pos[iMove][ePOS_Y];
		int iX = pos_x + move_pos[iMove][ePOS_X];

		if (map[iY][iX] != 0) {
			map[iY][iX] = 0;
			area_size[area_cnt]++;
			remove_area_dfs(iX, iY);
		}
	}
}

void input(void)
{
	int N;

#if (TEST_AUTO == 1)
	(void)freopen("test_input.txt", "r", stdin);
#endif

	(void)scanf("%d", &N);

	pos_max[ePOS_X] = N;
	pos_max[ePOS_Y] = N;

	for (int iY = 1; iY <= pos_max[ePOS_Y]; iY++) {
		(void)scanf("%s", map[iY] + 1);
		for (int iX = 1; iX <= pos_max[ePOS_X]; iX++) {
			map[iY][iX] -= '0';
		}
	}
}

int main(void)
{
	/*
	*    1. 각 좌표마다 한번씩 찍어봄
	*    2. 0인 경우 갈수 없으니 탐색하지 않음
	*    3. 1인 경우 탐색할 수 있으니 탐색 함수 사용
	*    4. 탐색 함수는 1을 0으로 지워나감
	*    5. 더이상 갈수없는 경로라면 종료
	*    위 과정을 반복
	*/

	input();

	/* Process */
	for (int iY = 1; iY <= pos_max[ePOS_Y]; iY++) {
		for (int iX = 1; iX <= pos_max[ePOS_X]; iX++) {
			if (map[iY][iX] != 0) {
				remove_area_dfs(iX, iY);
				area_cnt++;
			}
		}
	}

	/* Output */
	for (int iArea = 0; iArea < area_cnt; iArea++) {
		printf("%d\n", area_size[iArea]);
	}
	return 0;
}
#endif
#endif

// 백준 #2667 제출용
#if TEST_RECURSIVE == 7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (25+2)
int n;	//배열 사이즈
int** ary = NULL;	//2차원 배열을 저장할 포인터
int address_count[MAX_N * MAX_N] = { 0 };
int P = 0;

/*
void print_ary() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", ary[i][j]);
		}
		printf("\n");
	}
}*/

void scan_ary() {
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			(void)scanf("%1d", &ary[i][j]);
		}
	}
}

int** call_mem() {
	ary = (int**)calloc(n, sizeof(int*));
	if (ary == NULL) exit(1);
	ary[0] = calloc(n * n, sizeof(int));
	if (ary[0] == NULL) exit(1);
	for (int i = 1; i < n; ++i) {
		ary[i] = ary[0] + i * n;
	}
	return ary;
}

void move_map(int R, int C) {
	//값을 읽어서 1 -> 0으로 바꾸고, 카운터 증가
	if (ary[R][C] == 1) {
		ary[R][C] = 0;
		address_count[P]++;
	}
	//하
	if (ary[R + 1][C] == 1) {
		move_map(R + 1, C);
	}
	//우
	if (ary[R][C + 1] == 1) {
		move_map(R, C + 1);
	}
	//상
	if (ary[R - 1][C] == 1) {
		move_map(R - 1, C);
	}
	//좌
	if (ary[R][C - 1] == 1) {
		move_map(R, C - 1);
	}
}
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main() {
	/*
	1. 배열 동적 할당
	2. 지정된 txt에서 배열 크기 및 정보 입력
	3. map 출력
	4-1. move_map1 후 단지 수 카운트
	4-2. move_map2 로 단지 수 카운트
	*/
	(void)scanf("%d", &n);
	n += 2;

	/*Map Loading*/
	ary = call_mem();
	scan_ary();
	/*Ver.1 - move_map1 : 카운트해서 전역변수 address_count에 저장*/
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ary[i][j] == 1) {
				move_map(i, j);
				P++;
			}
		}
	}
	/* Output*/
	qsort(address_count, P, sizeof(int), compare);
	printf("%d\n", P);
	for (int i = 0; i < P; ++i) {
		printf("%d\n", address_count[i]);
	}
}
#endif


