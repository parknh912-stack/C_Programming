/****문제 번호****/
#define TEST 0
/*****************/

#if TEST > 0
#ifndef ___AAA___
#define ___AAA___

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>	

#endif
#endif // TEST > 0

// 1 - 정수 10개를 배열에 저장하고 최소값, 최대값, 평균값 계산하기 <limits.h>
#if TEST == 1
int main(void)
{
	int a[10];
	int min = INT_MAX;	//<limits.h>로 지정 가능한 최대값을 최소로 넣고 비교하면 됌
	int max = INT_MIN;
	//double avg = 0.0;	//개선점1. 굳이 double 쓰지말고, 어짜피 정수의 합은 정수니까, 결과만 형변환해도 될듯

	int avg = 0;

	for (int i = 0; i < 10; i++)
	{
		printf("숫자 입력해주세요 : ");
		if (scanf("%d", a + i) != 1)	//이건 에러코드 대응용
			return 1;
		if (a[i] < min) min = a[i];		//개선완료 : for문 2개 써서 20번 반복보다는, 그냥 한번 에 바로 계산, 비교
		if (a[i] > max) max = a[i];
		avg += a[i];

	}
	//min = max = a[0];		

	//for (int i = 0; i < 10; i++) 
	//{
	//	if (a[i] < min) {
	//		min = a[i];
	//	}
	//	if (a[i] > max) {
	//		max = a[i];
	//	}
	//	avg += a[i];
	//}
	//avg /= 10.0;

	printf("min : %d, max : %d, avg: %.2lf\n", min, max, avg / 10.0);
	return 0;
}
#endif // 1

// 2 - 랜덤 숫자 만들기 (랜덤 시드 srand 함수 , 랜덤 숫자 rand 함수 <stdlib.h>
//time(0) <<시드 <time.h>
// 1~6까지 정수 30개 랜덤 -> 배열 저장 및 확인
// rand -> [0,32767]
#if TEST == 2
#include <time.h>
int main(void)	
{	
	int a[10];
	int dice[30];
	int rand_min = 1;
	int rand_max = 6;

	srand(time(0));

	for (int i = 0; i < 10; i++) {
		a[i] = rand();
		printf("%6d", a[i]);
	}
	puts("");
	printf("RAND_MAX : %x, %d\n", RAND_MAX, RAND_MAX);
	
	for (int i = 0; i < 30; i++) {
		dice[i] = rand_min + rand() % rand_max;
		printf("%6d%c", dice[i], (i + 1) % 10 != 0 ? ' ' : '\n');
	}
	
}
#endif

// 정올 - 구구단 문제 1
#if TEST == 3
#include <stdio.h>

void gugudan(int start, int end) {
	int step = (start <= end) ? 1 : -1;
	for (int i = 1; i <= 9; i++) {
		for (int j = start; ; j+=step) {
			printf("%d * %d = %2d", j, i, j * i);
			if (j == end)
				break;
			printf("   ");
		}
		printf("\n");
	}
}

int main(void) {
	int start, end;
	int res;
	while (1) {
		scanf("%d %d", &start, &end);
		if (1 < start && start < 10 && 1 < end && end < 10)
			break;
		printf("INPUT ERROR!\n");
	}
	gugudan(start, end);
}
#endif

// 정올 - 배열 2	- 5ms
#if TEST == 4
void count_num(int* ary, int n) {
	int cnt[10] = { 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j == ary[i])
				++cnt[j];
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (cnt[i] != 0)
			printf("%d : %d개\n", i, cnt[i]);
	}
}

int main(void) {
	int num[100] = { 0 };

	int i = 0;
	while (scanf("%d", num + i)) {
		if (num[i] == 0)
			break;
		num[i] %= 10;
		++i;
	}
	count_num(num, i);
}
#endif // TEST == 4

// 정울 - 배열 2 - 개선판	-3ms
#if TEST == 5
#include <stdio.h>
int main() {
	int arr[10] = { 0 };
	int num;
	while (scanf("%d", &num) && num != 0) {
		arr[num % 10]++;
	}
	for (int i = 0; i < 10; ++i) {
		if (arr[i] != 0)
			printf("%d : %d개\n", i, arr[i]);
	}
}
#endif

// 정올 - 도약
#if TEST == 6
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
#include <stdio.h>

void _scanf_ary(unsigned int* pa, unsigned int index) {
	for (int i = 0; i < index; ++i) {
		(void)scanf("%ud", &pa[i]);
	}
}
void _sort_ary(int* pa, int n) {
	int temp;
	for (int i = 0; i < n; ++i) {	// 개선점 : n-1도 연산인데 줄여도 상관없지 않나?
		for (int j = i + 1; j < n; ++j) {	// 개선점 : j=i+1 역시 줄여도 괜찮나?
			if (pa[i] > pa[j]) {
				temp = pa[i];
				pa[i] = pa[j];
				pa[j] = temp;
			}
		}
	}
}
int _jump(int* pa, int n) {
	int d1, d2;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		d1 = 0;
		d2 = 0;
		for (int j = i + 1; j < n; ++j) {
			d1 = pa[j] - pa[i];				//a 구함 
			for (int k = j + 1; k < n; ++k) {
				d2 = pa[k] - pa[j];			//b 구함
				if ((d2 >= d1) && (d2 <= (2 * d1)))
					++count;
			}
		}
	}
	return count;
}
int main() {
	unsigned int num[1000];
	unsigned int index;

	(void)scanf("%d", &index);	//연잎의 수
	_scanf_ary(num, index);		//연잎 좌표 입력
	_sort_ary(num, index);		//연잎 좌표 오름차순
	printf("%d", _jump(num, index));
}

#endif

// 정올 - 도약 - 바이너리 서치
#if TEST == 7
#include <stdio.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

void _scan_ary(unsigned int* pa, const unsigned int N) {
	for (int i = 0; i < N; ++i) {
		(void)scanf("%ud", &pa[i]);
	}
}
void _sort_ary(int* pa, int n) {
	int temp;
	for (int i = 0; i < n; ++i) {	
		for (int j = i + 1; j < n; ++j) {
			if (pa[i] > pa[j]) {
				temp = pa[i];
				pa[i] = pa[j];
				pa[j] = temp;
			}
		}
	}
}

int main() {
	int* num = NULL;
	int N;

	(void)scanf("%d", &N);	//연잎의 수
	num = (int*)calloc(N, sizeof(int));
	if (num == NULL) exit(0);

	_scan_ary(num, N);		//연잎 좌표 입력
	_sort_ary(num, N);		//연잎 좌표 오름차순
	printf("%d", _jump(num, N));

	free(num);
	return 0;
}
#endif

// 정올 - 회전초밥 중
#if TEST == 8
#define MAX_N 30001
#define MAX_d 3001
#define MAX_k 3001
int dish[MAX_N + MAX_k];
//main에 넣으니 배열 너무 크다고 경고떠서, 전역배열로 설정

void scan_ary(int* ary, int N, int index) {
	int i,j;
	for (i = 0; i < N; ++i) {
		(void)scanf("%d", ary + i);
	}
	for (i = 0, j = N; j < index; ++i, ++j) {
		ary[j] = ary[i];
	}
}
void print_ary(int* pa, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", *(pa + i));
	}
}

int sliding_window(int* ary, int N, int d, int k, int c) {
	int count[MAX_d] = { 0 };
	int kinds = 0;
	int max_kinds = kinds;
	//window 생성
	for (int i = 0; i < k; ++i) {
		if (count[ary[i]] == 0)
			++kinds;
		count[ary[i]]++;
	}
	if (count[c] == 0)
		++kinds;
	count[c]++;

	if (max_kinds < kinds)
		max_kinds = kinds;
	
	//윈도우 반복
	for (int i = 1; i <N; ++i) {
		--count[c];
		if (count[c] == 0)
			--kinds;

		--(count[ary[i - 1]]);
		if (count[ary[i - 1]] == 0)
			--kinds;

		if (count[ary[i + k - 1]] == 0)
			++kinds;
		++count[ary[i + k - 1]];

		if(count[c] == 0)
			++kinds;
		++count[c];

		if (max_kinds < kinds)
			max_kinds = kinds;
	}
	return max_kinds;

}
int main() {
	int N = 0;	//접시의 수
	int d = 0;	//초밥의 가짓수
	int k = 0;	//연속해서 먹는 접시의 수
	int c = 0;	//쿠폰 번호(공짜 접시)
	
	(void)freopen("score2.txt", "r", stdin);
	(void)scanf("%d %d %d %d", &N, &d, &k, &c);
	int index = N + k - 1;

	scan_ary(dish, N, index);

	printf("%d", sliding_window(dish, N, d, k, c));
	
	return 0;
}
#endif


// 정올 - 회전초밥 중 - fix
#if TEST == 9
#include <stdio.h>
#define MAX_N 30001
#define MAX_d 3001
#define MAX_k 3001 
int dish[MAX_N + MAX_k];
//main에 넣으니 배열 너무 크다고 경고떠서, 전역배열로 설정

void scan_ary(int* ary, int N, int index) {
	int i, j;
	for (i = 0; i < N; ++i) {
		(void)scanf("%d", ary + i);
	}
	for (i = 0, j = N; j < index; ++i, ++j) {
		ary[j] = ary[i];
	}
}
void print_ary(int* pa, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", *(pa + i));
	}
}

int sliding_window(int* ary, int N, int d, int k, int c) {
	int count[MAX_d] = { 0 };
	int kinds = 0;
	int eff_kinds;
	int max_kinds;
	//window 생성
	for (int i = 0; i < k; ++i) {
		if (count[ary[i]] == 0)
			++kinds;
		count[ary[i]]++;
	}
	max_kinds = kinds + (count[c] == 0);

	//윈도우 반복
	for (int i = 1; i < N; ++i) {
		--(count[ary[i - 1]]);
		if (count[ary[i - 1]] == 0)
			--kinds;

		if (count[ary[i + k - 1]] == 0)
			++kinds;
		++count[ary[i + k - 1]];

		eff_kinds = kinds + (count[c] == 0);
		if (max_kinds < eff_kinds)
			max_kinds = eff_kinds;
	}
	return max_kinds;

}
int main() {
	int N = 0;	//접시의 수
	int d = 0;	//초밥의 가짓수
	int k = 0;	//연속해서 먹는 접시의 수
	int c = 0;	//쿠폰 번호(공짜 접시)

	//(void)freopen("score2.txt", "r", stdin);
	(void)scanf("%d %d %d %d", &N, &d, &k, &c);
	int index = N + k - 1;

	scan_ary(dish, N, index);

	printf("%d", sliding_window(dish, N, d, k, c));

	return 0;
}
#endif

#if TEST == 10
int main() {
	char* a[5];
	a[0] = "cat";
	printf("%s\n", a[0]);

	printf("%d %c\n", sizeof(a[0]), * (a[0] + 1));
	a[0] = "nananana";
	printf("%s\n", a[0]);
}
#endif