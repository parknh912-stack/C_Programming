// PART 02 - 총 24문제 (자료구조와 알고리즘)
#include "practice.h"

#if PART == 2

// ==================== 문제 01 ====================
#if PROBLEM == 1

/*
문제: 문자열료 표시된 실수를 숫자로 변환하기 (atof) 함수 만들기

풀이 아이디어:
1. 문자열 매개변수, double형 리턴
2. -1.234E-10 이런걸 처리하는 것이 목표
3. 부호 / 정수부 / 가수부 / 지수부 시작 / 지수부 부호 / 지수부 순
*/

#define PLUS 1
#define MINUS -1

double my_atof(char* s)
{
    int sign = PLUS;       //부호
    int value = 0;      //정수부
    double mantissa = 0; //가수부
    double mandigit = 10; //가수부의 자릿수
    int exp = 0;        //지수부
    int expsign = PLUS;    //지수부 부호

    if (*s == '-')  //부호처리
    {
        sign = MINUS;
        s++;
    }
    else if(*s=='+')
        s++;

    //소수점 까지 읽기 (정수부 처리)
    while (*s != '.' && *s != 'E' && *s != 'e' && *s != '\0')
    {
        if (isdigit(*s))
        {
            value *= 10;
            value += (*s - '0');
        }
        s++;
    }

    // 가수부 처리 (있는 경우)
    if (*s == '.')
    {
        while (*s != 'E' && *s != 'e' && *s != '\0')
        {
            if (isdigit(*s))
            {
                mantissa += (*s - '0')/mandigit;
                mandigit *= 10;
            }
            s++;
        }
    }

    // 지수부 부호 처리
    if (*s == 'E' || *s == 'e')
    {
        s++;
        if (*s == '-')  //부호처리
        {
            expsign = MINUS;
            s++;
        }
        else if (*s == '+')
            s++;
    }

    // 지수부 처리 (pow 쓰면 될듯)
    while (*s != '\0')
    {
        if (isdigit(*s)) {
            exp *= 10;
            exp += (*s - '0');
        }
        s++;
    }

    return sign * (value + mantissa) * pow(10, expsign * exp);
}
int main(void)
{
    char s[30] = "1.234";

    printf("%.10g\n", my_atof(s));

    strcpy(s, "1.234E10");
    printf("%.10g\n", my_atof(s));

    strcpy(s, "-1.234E-10");
    printf("%.10g\n", my_atof(s));
 

    return 0;
}

#endif // PROBLEM == 1

// ==================== 문제 02 ====================
#if PROBLEM == 2

/*
문제: 2진수를 10진수로 변환하기

풀이 아이디어:
1. long long 은 자릿수가 19진수
2. int64_t 아닌가?
3. 10101010 이 있다면, 10으로 나눠서 가장 작은것부터 2^i 해서 더하면 될듯
*/
int binary_to_decimal(int64_t n)
{
    int dec = 0;
    int remind_num; //나머지

    for (int i = 0; i < 32; i++)
    {
        remind_num = n % 10;
        dec += remind_num * pow(2, i);
        n /= 10;
    }
    return dec;
}
int main(void)
{
    int64_t bin;
    int dec;

    printf("2진수 입력\n");
    scanf_s("%lld", &bin);

    dec = binary_to_decimal(bin);
    printf("%lld(binary) = %d(decimal)\n", bin, dec);

    return 0;
}

#endif // PROBLEM == 2

// ==================== 문제 03 ====================
#if PROBLEM == 3

/*
문제: 비트 연산으로 10진수를 2진수로 변환하기

풀이 아이디어:
1. 기본적으로 숫자는 2진수로 저장됌
2. 이걸로 각 자리수마다 1 혹은 0만 따로 AND 연산해서 별도로 저장하고
3. right shift 해서 다시 보완
*/
int64_t decimal_to_binary(int decimal)
{
    int decimal_bit;            //decimal_bit 값
    int64_t binary = 0; //결과값
    int mask = 0x01;

    for (int i = 0; i < 16; i++)    //int는 16비트이므로,
    {
        decimal_bit = decimal & mask;
        binary += decimal_bit * pow(10, i); //중요한 부분
        decimal >>= 1;
    }
    return binary;
}
int main(void)
{
    int64_t binary;
    int decimal;

    printf("10진수 입력\n");
    scanf_s("%d", &decimal);

    binary = decimal_to_binary(decimal);
    printf("%d(decimal) = %lld(binary)\n", decimal, binary);

    return 0;
}

#endif // PROBLEM == 3

// ==================== 문제 04 ====================
#if PROBLEM == 4

/*
문제: 재귀함수를 이용해서 10진수를 2진수로 변환하기

풀이 아이디어:
1. 10진수를 계속 2로 나눠가며 진행
2. 몫 -> 2진수 아랫자리
3. 나머지 -> 연산 진행
4. 몫이 0이되면 종료
*/
#define SIZE 32

int check_overflow(char buffer[])
{
    char intmax[11];        //INTMAX는 10자리수 -> 11개의 문자배열 사용

    _itoa(INT_MAX, intmax, 10); //INTMAX 숫자를 intmax 배열에 저장 (10자리 사용)
    if (strlen(buffer) > strlen(intmax))
        return 1;

    else if (strlen(buffer) == strlen(intmax))
    {
        for (int i = 0; i < 11; i++)
        {
            if (buffer[i] > intmax[i])
                return 1;
        }
    }
    return 0;
}
// 1번 = 배열을 이용해서 2진수 구하는 방법 (나눠서 배열에 저장)
void compute(int n)
{
    int arr[SIZE] = { 0 };
    int i, length = 0;      //배열의 길이

    for (int i = 0; n > 0; i++)
    {
        arr[i] = n % 2;
        n /= 2;
        length++;
    }
    length--;

    while (length >= 0)
    {
        printf("%d", arr[length]);
        length--;
    }
}

// 2번 = 재귀함수 사용하는 방법
int recursive_decimal_to_binary(int n)
{
    if (n >= 2)
        recursive_decimal_to_binary(n / 2);
    printf("%d", n % 2);

}
int main(void)
{
    int n;
    char number[11] = { 0 };

    printf("10진수 정수 입력\n");
    scanf("%s", number);

    if (check_overflow(number) == 1)
    {
        printf("정수 범위 넘어섬");
        exit(0);
    }

    n = atoi(number);

    printf("\n10진수 %d의 2진수는 : ", n);
    compute(n);

    printf("\n10진수 %d의 2진수는 : ", n);
    recursive_decimal_to_binary(n);

    return 0;
}

#endif // PROBLEM == 4

// ==================== 문제 05 ====================
#if PROBLEM == 5

/*
문제: 30번 : 하노이의 탑과 메르센 수

풀이 아이디어: 재귀호출을 이용하여 풀수 있는 유명한 예제임 중요함.

A에 있는 n개의 원반을 (B를 이용해) C로 이동하려면
1. n-1개의 원반을 A에서 C를 이용해 B로 이동
2. A 맨밑의 원반을 C 로 이동
3. B에 있는 n-1개의 원반을 B에서 A를 이용해 C로 이동

이 중 n-1개 원반 이동하는 과정을 재귀적으로 ㄱㄱ
O(2^n-1) : 메르센 수 : n의 증가에 따른 기하급수적 증가
    쓰지 말라는 거지요 ㅇㅇ

*/
//원반 갯수 / 출발지 / 도착지 / 통로
void hanoi_tower(int n, char from, char to, char via)
{
    if (n == 1)
        printf("Move : %c -> %c\n", from, to);
    else
    {
        hanoi_tower(n - 1, from, via, to);
        printf("Move : %c -> %c\n", from, to);
        hanoi_tower(n - 1, via, to, from);
    }
}

double mersenne(int i)
{
    return pow(2, i) - 1;
}
int main(void)
{
    hanoi_tower(4, 'A', 'C', 'B');

    for (int i = 1; i <= 50; i++) {
        double m = mersenne(i);

        printf("메르센 수(%d) = %.0f = %.1f일 = %.1f년\n",
            i, m, m / 3600 / 24, m / 3600 / 24 / 365);
    }
    return 0;
}

#endif // PROBLEM == 5

// ==================== 문제 06 ====================
#if PROBLEM == 6

/*
문제: 31번 : 최대공약수와 최소공배수

풀이 아이디어: 유클리드 호제법
"A를 B로 나눈 몫을 Q라고 하고, 나머지를 R이라 하면, gcd(A,B)=gcd(B,R)

gcd(60,24) //60%24 = 12
=gcd(24,12) // 24 % 12 = 0
= gcd(12,0) // 0이 나왔으므로, 12가 최대 공약수

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
*/
int gcd(int a, int b);

int main(void)
{
    int a, b, GCD, LCN;

    printf("2개의 정수 입력\n");
    scanf("%d %d", &a, &b);

    GCD = gcd(a, b);
    LCN = (a * b) / GCD;

    printf("GCD(%d,%d) = %d\n", a, b, GCD);
    printf("LCN(%d,%d) = %d\n", a, b, LCN);
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
#endif // PROBLEM == 6

// ==================== 문제 07 ====================
#if PROBLEM == 7

/*
문제: 32번 : 실행 시간 측정 (clock 함수를 이용한 프로그램 실행시간 측정)

풀이 아이디어: clock_t clock(void);
clock은 cpu가 사용한 clock 수
CLOCKS_PER_SEC 로 나누어서 사용 가능
*/

int main(void)
{
    double start, end;

    start = (double)clock() / CLOCKS_PER_SEC;


    int sum = 0;
    for (int i = 0; i < 10000000; i++)
        sum++;

    end = (double)clock() / CLOCKS_PER_SEC;

    printf("sum = %d, 실행시간 = %lf초\n", sum, end - start);
    return 0;
}

#endif // PROBLEM == 7

// ==================== 문제 08 ====================
#if PROBLEM == 8

/*
문제 : 33번 : 피보나치 수열 + 동적 알고리즘 (재귀함수의 대표격 ㅇㅇ)

풀이 아이디어:
피보나치 수열 = 첫 째 둘째가 1,1이고, 다음은 바로 앞 두수의 합
1,1,2,3,5,8,13,21 ... 이런식인거

재귀라면 아래와 같겠지.
Fibo(1) = 1;
Fibo(2) = 1;
FIbo(n) = Fibo(n-2) + Fibo(n-1);

#1 제일 쉬운 방법
배열 사용하는 방법
Fifo[] 만들어서, 쓰는게 제일 쉽긴해. 그리고 배열에 저장하니까, 한번 저장된거 불러오는건 빠름

#2 재귀쓰는 방법
단점 : 매번 Fibo(n-2) 같은거 하나하나 계산해야됌
개선방법 : 동적 프로그래밍 (한번 계산한건 저장해서 하는거)
*/
void print_Result(int a[], int n, double t) 
{
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n실행시간 = %lf\n", t);
}

int Recursive_Finonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return Recursive_Finonacci(n - 2) + Recursive_Finonacci(n - 1);
}

int dp[100];//n항까지의 피보나치 수열을 구하는 동적 프로그래밍(배열)
int Dynamic_Finonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (dp[n] != 0)
        return dp[n];
    else
        return dp[n] = Dynamic_Finonacci(n - 2) + Dynamic_Finonacci(n - 1);
}
int main(void)
{
    double start, end;
    int n;
    int f[100];

    printf("n항 까지의 피보나치 수열 계산. \nn을 입력하시오 :");
    scanf("%d", &n);

    // 1번 배열 + 반복
    start = (double)clock() / CLOCKS_PER_SEC;
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 2] + f[i - 1];
    }
    end = (double)clock() / CLOCKS_PER_SEC;
    print_Result(f, n, end - start);

    // 2번 재귀
    start = (double)clock() / CLOCKS_PER_SEC;
    for (int i = 1; i <= n; i++)
    {
        f[i] = Recursive_Finonacci(i);
    }
    end = (double)clock() / CLOCKS_PER_SEC;
    print_Result(f, n, end - start);

    // 3번 재귀 + 동적
    start = (double)clock() / CLOCKS_PER_SEC;
    for (int i = 1; i <= n; i++)
    {
        f[i] = Dynamic_Finonacci(i);
    }
    end = (double)clock() / CLOCKS_PER_SEC;
    print_Result(f, n, end - start);

}

#endif // PROBLEM == 8

// ==================== 문제 09 ====================
#if PROBLEM == 9

/*
문제: 34번 선형 탐색 (linear search)

풀이 아이디어: 탐색은 중요하지 ㅇㅇ

그냥 하나하나 처음부터 끝까지 비교하는 방식임 
- O(n) 으로 느리다.
- 정렬 안돼도 상관 X
- 반복문 사용

*/

#define MAX 10000
#define CNT 1000

int search(int a[], int v);
void printArr(int a[], int n);
void find_min_max(int a[], int n);

int main(void)
{
    int a[CNT];
    int value, index;

    srand((unsigned)(time(NULL)));
    for (int i = 0; i < CNT; i++)
        a[i] = rand() % MAX;

    printArr(a, CNT);
    find_min_max(a, CNT);

    printf("찾고자 하는 수 :");
    scanf("%d", &value);

    if ((index = search(a, value)) == -1)
        printf("%d 없음\n",value);
    else
        printf("%d는 %d번째에 있음\n", value, index+1);

    return 0;
}

int search(int a[], int v)
{
    for (int i = 0; i < CNT; i++)
    {
        if (a[i] == v)
            return i;
    }
    return -1;
}
void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
}
void find_min_max(int a[], int n)
{
    int min = a[0];
    int max = a[0];

    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    printf("\nmin = %d , max = %d\n", min, max);
}

#endif // PROBLEM == 9

// ==================== 문제 10 ====================
#if PROBLEM == 10

/*
문제: 35번 이진탐색 (binary search)

풀이 아이디어:
두 수 사이에 중간값보다 크고 작고 하는거 있었지?
L R 해서 재귀해서 푸는거
그거임 ㅇㅇ

정렬해야 빠르다
    - O(log n)  : 정렬시
    - O(n)      : 미정렬시

*/
#define MAX 10000
#define CNT 1000

int binary_search(int a[], int n, int v);
void swap(int v[], int i, int j);
void sort(int v[], int left, int right);
void printArr(int a[], int n);


int main(void)
{
    int a[CNT];
    int value, index;

    srand((unsigned)(time(NULL)));
    for (int i = 0; i < CNT; i++)
        a[i] = rand() % MAX;

    sort(a, 0, CNT);
    printArr(a, CNT);


    printf("\n찾고자 하는 수 :");
    scanf("%d", &value);

    if ((index = binary_search(a, CNT, value)) == -1)
        printf("%d 없음\n", value);
    else
        printf("%d는 %d번째에 있음\n", value, index + 1);

    return 0;
}

int binary_search(int a[], int n, int v)
{
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == v)
            return mid;
        else if (a[mid] < v)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void swap(int v[], int i, int j)
{
    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void sort(int v[], int left, int right)
{
    for (int i = left; i < right; i++)
    {
        for (int j = 0; j < right - 1; j++)
            if (v[j] > v[j + 1])
                swap(v, j, j + 1);
    }
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
}
#endif // PROBLEM == 10

// ==================== 문제 11 ====================
#if PROBLEM == 11

/*
문제: 36번 qsort 라이브러리 사용

풀이 아이디어:
- compare 함수를 만들어야함

void qsort {
    void* base, //배열의 시작
    size_t number   //배열의 크기
    size_t width    //배열 원소의 크기
    int (*compare)(const void*, const void*) // 비교함수
*/
struct student {
    int id;
    char name[20];
    int score;
};

int compare_1(const void* p, const void* q)
{
    int a = ((struct student*)p)->id;
    int b = ((struct student*)q)->id;
    return a - b;
}
int compare_2(const void* p, const void* q)
{
    int a = ((struct student*)p)->score;
    int b = ((struct student*)q)->score;
    return b - a;
}
int compare_3(const void* p, const void* q)
{
    char* a = ((struct student*)p)->name;
    char* b = ((struct student*)q)->name;
    return strcmp(a, b);
}
void printArr(struct student a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%5d %10s %4d\n", a[i].id, a[i].name , a[i].score);
    printf("\n");
}

int main(void)
{
    struct student a[] = { {1001, "steve",88},{1003,"tom",98},{1002,"jane",76} };

    printf("sort by id(ascending) : \n");
    qsort(a, 3, sizeof(struct student), compare_1);
    printArr(a, 3);

    printf("sort by score(descending) : \n");
    qsort(a, 3, sizeof(struct student), compare_2);
    printArr(a, 3);

    printf("sort by name(ascending) : \n");
    qsort(a, 3, sizeof(struct student), compare_3);
    printArr(a, 3);

    return 0;
}

#endif // PROBLEM == 11

// ==================== 문제 12 ====================
#if PROBLEM == 12

/*
문제: 37번 : qsort 를 이용한 재귀 이진 탐색

풀이 아이디어:

*/

#define MAX 10000
#define CNT 100

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
}
int compare(const void* a, const void* b)
{
    return (*(const int*)a - *(const int*)b);
}

int binary_search(int a[], int left, int right, int key)
{
    if (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            return binary_search(a, mid + 1, right, key);
        else
            return binary_search(a, left, mid - 1, key);
    }
    return -1;
}

int main(void)
{
    int a[CNT];
    int value, index;

    srand((unsigned)(time(NULL)));
    for (int i = 0; i < CNT; i++)
        a[i] = rand() % MAX;

    qsort(a, CNT, sizeof(int), compare);
    printArr(a, CNT);


    printf("\n찾고자 하는 수 :");
    scanf("%d", &value);

    if ((index = binary_search(a, 0, CNT-1, value)) == -1)
        printf("%d 없음\n", value);
    else
        printf("%d는 %d번째에 있음\n", value, index + 1);

    return 0;
}




#endif // PROBLEM == 12

// ==================== 문제 13 ====================
#if PROBLEM == 13

/*
문제: 38번 : 이진탐색 라이브러리 (bsearch 사용)

풀이 아이디어:

*/
int compare(const void* a, const void* b)
{
    return (*(const int*)a - *(const int*)b);
}

int main(void)
{
    int a[] = { 10,20,30,40,50,60,70,80,90,100 };
    int* ptr;       //bsearch 반환값
    int key;

    printf("\n찾고자 하는 수 :");
    scanf("%d", &key);

    ptr = (int*)bsearch(&key, a, _countof(a), sizeof(int), compare);

    if (ptr == NULL)
        printf("%d 없음\n", key);
    else
        printf("%d는 a[%d]에 있음\n", *ptr, ptr - a);

}

#endif // PROBLEM == 13

// ==================== 문제 14 ====================
#if PROBLEM == 14

/*
문제: 39번 : 버블 정렬

- 가장 간단한 정렬 알고리즘
- 인접한 2개의 원소를 비교, 더 (큰,작은) 원소를 뒤로 보낸다.
- O(n^2)    : 평균 + 역순정렬
- O(n)      : 최선 (이미 정렬됌)

*/
#define MAX 30
void swap(int v[], int i, int j)
{
    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void bubble_sort(int v[], int left, int right)
{
    for (int i = left; i < right - 1; i++)
        for (int j = left; j < right - 1 - i; j++)
            if (v[j] > v[j + 1])
                swap(v, j, j + 1);
}
int main(void)
{
    int v[MAX];

    srand((unsigned)(time(NULL)));
    for (int i = 0; i < MAX; i++)
        v[i] = rand();

    for (int i = 0; i < MAX; i++)
        printf("%6d %c", v[i], (i + 1) % 10 == 0 ? '\n' : ' ');

    bubble_sort(v, 0, MAX);

    printf("\nbubble sorting\n");
    for(int i = 0 ; i < MAX ; i++)
        printf("%6d %c", v[i], (i + 1) % 10 == 0 ? '\n' : ' ');
}

#endif // PROBLEM == 14

// ==================== 문제 15 ====================
#if PROBLEM == 15

/*
문제: 40번 : 선택정렬 (selection sort)

- 가장 작은걸 [선택] 해서 맨 앞으로 이동
- 그 다음으로 작은걸 [선택] 해서 앞으로 이동
반복

- 처음이 제일 작은걸로 둔다 ~ 마지막-1 까지
- 비교 대상은 2 ~ 마지막까지
- 더 작은걸 앞으로 스왑한다 (현재 위치와 스왑하면 됌)

- O(n²)
- 메모리 사용이 거의 없음 O(1)
*/
#define MAX 30
void swap(int v[], int i, int j)
{
    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void selection_sort(int v[], int left, int right)
{
    for (int i = left; i < right - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < right; j++)
            if (v[min] > v[j])
                min = j;
        swap(v, i, min);
    }
}

int main(void)
{
    int v[MAX];

    srand((unsigned)(time(NULL)));
    for (int i = 0; i < MAX; i++)
        v[i] = rand();

    for (int i = 0; i < MAX; i++)
        printf("%6d %c", v[i], (i + 1) % 10 == 0 ? '\n' : ' ');

    selection_sort(v, 0, MAX);

    printf("\nbubble sorting\n");
    for (int i = 0; i < MAX; i++)
        printf("%6d %c", v[i], (i + 1) % 10 == 0 ? '\n' : ' ');
}

#endif // PROBLEM == 15

// ==================== 문제 16 ====================
#if PROBLEM == 16

/*
문제: 41번 : 퀵 정렬의 구현

- 가장 빠른 정렬
    O(log n)
- 단, 이미 정렬된 배열 대상으로는 
    O(n²)


*/
#define MAX 30
void swap(int v[], int i, int j)
{
    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void my_qsort(int v[], int left, int right)
{
    int i, last;

    if (left >= right)      
        return;
    swap(v, left, (left + right) / 2);      //제일 왼쪽 값을 기준값으로 pivot 삼아서 중앙 이동)
    last = left;
    for (i = left + 1; i <= right; i++)     //기준값보다 작은건 왼쪽으로
        /*
        * i: 지금 검사하는 원소의 위치
        * last: 기준값보다 작은 값들을 모아둔 구간의 마지막 위치
        */
        if (v[i] < v[left])
            swap(v, ++last, i);

    swap(v, left, last);    //기준값을 자기 자리에 넣음

    my_qsort(v, left, last - 1);    //기준값을 제외한 양쪽에 같은 작업을 반복
    my_qsort(v, last + 1, right);
}

int compare(const void* a, const void* b)
{
    return (*(const int*)a - *(const int*)b);
}

int main(void)
{
    int i;
    int v[MAX];

    srand((unsigned)(time(NULL)));
    for (int i = 0; i < MAX; i++)
        v[i] = rand();

    for (int i = 0; i < MAX; i++)
        printf("%6d %c", v[i], (i + 1) % 10 == 0 ? '\n' : ' ');

    my_qsort(v, 0, MAX - 1);


    printf("\nquick sorting\n");
    for (int i = 0; i < MAX; i++)
        printf("%6d %c", v[i], (i + 1) % 10 == 0 ? '\n' : ' ');
}

#endif // PROBLEM == 16

// ==================== 문제 17 ====================
#if PROBLEM == 17

/*
문제: 42번 : 문자열의 정렬

풀이 아이디어:

*/

int main(void)
{
    // 여기에 풀이를 작성하세요.

    return 0;
}

#endif // PROBLEM == 17

// ==================== 문제 18 ====================
#if PROBLEM == 18

/*
문제:

풀이 아이디어:

*/

int main(void)
{
    // 여기에 풀이를 작성하세요.

    return 0;
}

#endif // PROBLEM == 18

// ==================== 문제 19 ====================
#if PROBLEM == 19

/*
문제:

풀이 아이디어:

*/

int main(void)
{
    // 여기에 풀이를 작성하세요.

    return 0;
}

#endif // PROBLEM == 19

// ==================== 문제 20 ====================
#if PROBLEM == 20

/*
문제:

풀이 아이디어:

*/

int main(void)
{
    // 여기에 풀이를 작성하세요.

    return 0;
}

#endif // PROBLEM == 20

// ==================== 문제 21 ====================
#if PROBLEM == 21

/*
문제:

풀이 아이디어:

*/

int main(void)
{
    // 여기에 풀이를 작성하세요.

    return 0;
}

#endif // PROBLEM == 21

// ==================== 문제 22 ====================
#if PROBLEM == 22

/*
문제:

풀이 아이디어:

*/

int main(void)
{
    // 여기에 풀이를 작성하세요.

    return 0;
}

#endif // PROBLEM == 22

// ==================== 문제 23 ====================
#if PROBLEM == 23

/*
문제:

풀이 아이디어:

*/

int main(void)
{
    // 여기에 풀이를 작성하세요.

    return 0;
}

#endif // PROBLEM == 23

// ==================== 문제 24 ====================
#if PROBLEM == 24

/*
문제:

풀이 아이디어:

*/

int main(void)
{
    // 여기에 풀이를 작성하세요.

    return 0;
}

#endif // PROBLEM == 24

#endif // PART == 2
