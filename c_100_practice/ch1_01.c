// 001_정수를 배열에 저장하고 최소값, 최대값, 평균값 계산하기
#if 0
/* --- 공통 헤더 --- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>



int main()
{
	int a[10];
	int min, max;
	int sum = 0;

	for (int i = 0; i < 10; ++i)
	{
		printf("숫자 입력 : ");
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%6d",a[i]);
	}printf("\n");

	min = max = a[0];
	
	for (int i = 0; i < 10; ++i)
	{
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
		sum += a[i];
	}
	
	printf("min = %d, max = %d, mean = %.2f\n", min, max, sum / 10.0);

}

#endif // 1