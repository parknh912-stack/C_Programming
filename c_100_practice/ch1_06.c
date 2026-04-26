// 006_원주율의 계산
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


//라이프니츠의 원주율 공식을 프로그램 합니다.
// 덧셈 -> 뺄셈 -> 덧셈 순 sign 이라는 플래그 변수를 사용합니다.
// 앞에서 10개, 뒤에서 5개 출력
#if 1
int main()
{
	bool sign = false;
	double pi = 0;
	double num = 0;

	for (int i = 1; i < 1000000000; i+=2)
	{
		if (sign)
		{
			num -= ((double)1 / i);
			sign = false;
		}
		else
		{
			num += ((double)1 / i);
			sign = true;
		}
		pi = 4 * num;
		if(i < 20 || i > 999999990)
			printf("i = %9d, pi = %.18lf\n", i, pi);
	}
	return 0;
}
#else
#endif // 1
#endif // 1