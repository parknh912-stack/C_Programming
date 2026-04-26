// 008_enum으로 커피가격표 출력하기
#if 0
/* --- 공통 헤더 --- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


/*

*/
#if 1
enum Size {
	Short,
	Tall,
	Grande,
	Venti,
};
char sizeName[][7] = { "Short","Tall","Grande","Venti" };
int priceAmericano[] = { 3800, 4100, 4600, 5100 };
int pirceCappuccino[] = { 4600, 5900, 6400, 6900 };

int main()
{
	printf("커피 가격표(아메리카노)\n");
	for (int i = Short; i <= Venti; ++i)
		printf("%10s : %5d\n", sizeName[i], priceAmericano[i]);

	printf("커피 가격표(카푸치노)\n");
	for (int i = Short; i <= Venti; ++i)
		printf("%10s : %5d\n", sizeName[i], pirceCappuccino[i]);
}
#else

#endif // 1
#endif // 1