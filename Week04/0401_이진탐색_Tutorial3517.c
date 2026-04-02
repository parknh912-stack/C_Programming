// 0401 - 이진탐색 - Tutorial: 이진탐색 - 정올 3517 https://jungol.co.kr/problem/3517

#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAX_N 500001
int N, Q;
int ary[MAX_N];
int ary2[MAX_N];
int res[MAX_N];

void input_data()
{
    (void)scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {

        (void)scanf("%d", &ary[i]);
    }
    (void)scanf("%d", &Q);
    for (int j = 0; j < Q; ++j)
    {
        (void)scanf("%d", &ary2[j]);
    }
}

int binary_search(int value)
{
    int L = 0;
    int R = N - 1;
    int M;
    while (L <= R)
    {
        M = (int)(L + R) / 2;

        if (ary[M] == value) return M;

        if (value < ary[M])
        {
            R = M - 1;
        }
        else if (value > ary[M])
        {
            L = M + 1;
        }
    }
    return -1;
}


int main()
{
    input_data();
    for (int i = 0; i < Q; ++i)
    {
        printf("%d ", binary_search(ary2[i]));
    }
    return 0;
}

#endif // 0