// 010_ 1000까지의 소수를 출력하고 몇 개인지 출력하기
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
2~1000 사이의 소수를 출력하고, 모두 몇개인지 출력하는 프로그램 작성
*/
#if 1
int main()
{
	int index;
	int primes = 0;

	for (int i = 2; i <= 1000; ++i)
	{
		for (index = 2; index < i; ++index)
		{
			if (i % index == 0) // 나머지가 0인데
				break;
		}
		if (i == index)// 동일한 수라면 -> 소수
		{
			primes++;
			printf("%5d\n", i);
		}
	}
	printf("2부터 1000까지의 소수의 개수 : %d개\n", primes);
}
#else

#endif // 1
#endif // 1