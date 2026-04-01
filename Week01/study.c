/****문제 번호****/
#define TEST 0
/*****************/

#if TEST > 0
#ifndef ___AAA___
#define ___AAA___

#define SIZE(a) sizeof(a)/sizeof((a)[0])	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>	

#endif
#endif // TEST > 0


#if TEST == 1
int main() {
	char* a[5] = { "lion","tiger","monkey","human","bird" };
	int* b[5] = { 1,2,3,4,5 };

	printf("%p\n", a);		//a 는 배열의 주소
	printf("%s\n", *a);		//*a는 첫 참조의 값 = lion
	printf("%c\n", *a[0]);

	return 0;
}
#endif

#if TEST == 2
int print_ary(int* ary[], int r, int c) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("%d ", ary[i][j]);
		}
		printf
	}
}
int main() {
	int num[9][9];
	int* p = num;
	(void)freopen("study.txt", "r", stdin);
	(void)scanf("%d", num);

	printf_ary(num, SIZE(num), SIZE(num[0]);
}
#endif