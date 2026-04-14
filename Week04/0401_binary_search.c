// 0401 - 이진탐색 - 기초
#define TEST0401 0
#include "___AAA___.h"


#if TEST0401 == 1
int binary_search(int* ary, int size, int value)
{
	int L = 0;
	int R = size - 1;
	int M;
	while (L <= R)
	{
		M = (int)(L + R) / 2;

		if (ary[M] == value) return M;

		if (value < ary[M]) {
			R = M - 1;
		}
		else if (value > ary[M]) {
			L = M + 1;
		}
	}
	return -1;
}

int binary_search_recursive(int* ary, int value, int L, int R)
{
	int M = (int)(L + R) / 2;
	if (ary[M] == value) return M;
	if (L > R) return -1;

	if (value < ary[M]) binary_search_recursive(ary, value, L, M - 1);
	else if (value > ary[M]) binary_search_recursive(ary, value, M + 1, R);
}

/* 메인 함수 */
int main()
{
	int ary[10] = { 1,3,5,7,9,11,13,15,17,19 };
	int value;
	(void)scanf("%d", &value);

	int res = binary_search(ary, SIZE(ary), value);
	printf("input : %d\nindex : %d\nary[index] : %d\n", value, res, ary[res]);

	int res = binary_search_recursive(ary, value, 0, SIZE(ary) - 1);
	printf("input : %d\nindex : %d\nary[index] : %d\n", value, res, ary[res]);


	return 0;
}

#endif


#if TEST0401 == 2

int binary_search_lower(int* ary, int size, int value)
{
	int L = 0;
	int R = size - 1;
	int ret = -1;
	int M;
	while (L <= R)
	{
		M = (int)(L + R) / 2;

		if (ary[M] == value) return M;

		if (ary[M] > value) {
			ret = M;
			R = M - 1;
		}
		else if (ary[M] < value) {
			L = M + 1;
		}
	}
	//if (L < size)
	//	return L;
	return ret;
}

int binary_search_upper(int* ary, int size, int value)
{
	int L = 0;
	int R = size - 1;
	int ret = -1;
	int M;
	while (L <= R)
	{
		M = (int)(L + R) / 2;

		if (ary[M] == value) return M;

		if (value < ary[M]) {
			R = M - 1;
		}
		else if (value > ary[M]) {
			ret = M;
			L = M + 1;
		}
	}
	//if (R >= 0)
	//	return R;
	return ret;
}

int main()
{
	int ary[10] = { 1,3,6,9,12,13,14,17,22,25 };

	int up, down, res;
	(void)scanf("%d %d", &up, &down);

	res = binary_search_lower(ary, 10, up);
	printf("%d %d\n", res, ary[res]);

	res = binary_search_upper(ary, 10, down);
	printf("%d %d\n", res, ary[res]);

	return 0;
}
#endif