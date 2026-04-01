// 0401 - C프 교육 - 이진탐색


#include "___AAA___.h"

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
	//int res = binary_search(ary, SIZE(ary), value);
	//printf("input : %d\nindex : %d\nary[index] : %d\n", value, res, ary[res]);

	int res = binary_search_recursive(ary, value, 0, SIZE(ary) - 1);
	printf("input : %d\nindex : %d\nary[index] : %d\n", value, res,ary[res]);
	return 0;
}