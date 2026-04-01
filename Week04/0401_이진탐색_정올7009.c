#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500001
int N, Q;
int ary[MAX_N];
int ary2[MAX_N];
int res[MAX_N];

int compare_increase(const void* a, const void* b)
{
    const int* pa = (const int*)a;
    const int* pb = (const int*)b;
    return (*pa > *pb) - (*pa < *pb);
}

void input_data()
{
    (void)scanf("%d", &N);
    (void)scanf("%d", &Q);
    for (int i = 0; i < N; ++i)
    {

        (void)scanf("%d", &ary[i]);
    }
    for (int j = 0; j < Q; ++j)
    {
        (void)scanf("%d", &ary2[j]);
    }
}

bool binary_search(int value)
{
    int L = 0;
    int R = N - 1;
    int M;
    while (L <= R)
    {
        M = (int)(L + R) / 2;
        if (ary[M] == value) return M;
        if (value < ary[M]) {
            L = M + 1;
        }
        else if (value > ary[m]) {

        }
    }
}


int main()
{
    input_data();
    qsort(ary, N, sizeof(int), compare_increase);
    qsort(ary2, Q, sizeof(int), compare_increase);

    for (int i = 0; i < Q; ++i)
    {

    }
}