#include "___AAA___.h"

#define TEST 0

//qsort 사용 + 형변환 심화 + 구조체 기초
#if TEST == 1
/*비교하는 함수*/
int compInt(void* a, void* b) {
	int* ap = (int*)a;
	int* bp = (int*)b;
	// *ap > *bp : 양수, 1
	// *ap == *bp : 0
	// *ap < *bp : 음수, -1
	// return *ap - *bp;		//INT_MAX - (-1) = overflow , underflow 위험이 있는듯
	return (*ap > *bp) - (*ap < *bp);		//오름차순
	//return (*ap > *bp) - (*ap < *bp);		//내림차순
}
int compStr(void* a, void* b) {
	return strcmp(*(char**)a, *(char**)b);
}
int compStr2(void* a, void* b) {				//배열포인터 <-> char * , 값이 동일해서 strcmp에서 알아서 형변환해버림
	return strcmp((char*)a, (char*)b);		// str2 = str2[0] 둘이 형은 다른데 값은 동일해서 동작하는것
	//return strcmp(a,b);
	//return strcmp(*(char(*)[10])a, *(char(*)[10])b);		//3개 다 같더라...
	//return strcmp(*(char**)a, *(char**)b); <<< 불가능. 왜? str2의 타입이 char [10] 이니까
}
int compStr3(void* a, void* b) {
	return strcmp(*(char***)a, *(char***)b);
}
typedef struct _student {
	char* name;
	int age;
}student;

int compStudent_name(const void* a, const void* b) {
	return strcmp(((student*)a)->name, ((student*)b)->name);
	//return strcmp(*(char**)a, *(char**)b);
}

int compStudent_age(const void* a, const void* b) {
	int ai = ((student*)a)->age;
	int bi = ((student*)b)->age;
	return (ai > bi) - (ai < bi);
}
int main() {
#if 0
	int a[10] = { 9,5,20,50,80,60,22,19,7,77 };
	qsort(a, 10, 4, compInt);	//비교할 배열 포인터, 총 갯수, 원소 하나 크기, 비교를 수행할 함수 포인터
	for (int i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n\n");

	char* str[5] = { "rabbit","elephant", "cat","tiger","dog" };

	for (int i = 0; i < 5; ++i) {
		printf("%s ", str[i]);
	} printf("\n");

	qsort(str, 5, 4, compStr);

	for (int i = 0; i < 5; ++i) {
		printf("%s ", str[i]);
	}printf("\n\n");

	/*2차원 배열 -> 등가포인터는 char (*)[10]*/
	char str2[5][10] = { "rabbit","elephant", "cat","tiger","dog" };
	for (int i = 0; i < 5; ++i) {
		printf("%s ", str2[i]);
	}
	printf("\n");
	qsort(str2, 5, 10, compStr2);	//요소수 : 5개 + char [10] 타입이니까, 비교하는 원소 하나의 크기 = 1byte * 10 = 10
	for (int i = 0; i < 5; ++i) {
		printf("%s ", str2[i]);
	}
	printf("\n\n");

	/*포인터 2차원 배열의 예 */
	char* str3[5][10] = { "rabbit","elephant", "cat","tiger","dog" };
	printf("=== before === \n");
	for (int i = 0; i < 5; ++i) {
		printf("%10s %p\n", str3[0][i], str3[0][i]);
	}
	printf("=== after === \n");
	qsort(str3, 5, 4, compStr3);
	for (int i = 0; i < 5; ++i) {
		printf("%10s %p\n", str3[0][i], str3[0][i]);
	}
	printf("\n\n");
#else
	student stu[5] = {
		{"Tom", 30},
		{"Candy", 50 },
		{"Jerry", 20},
		{"Jaen", 10},
		{"Henry", 40}
	};
	//student A;
	//A = { "Tom",45 };	//->불가능
	qsort(stu, 5, sizeof(student), compStudent_name);
	for (int i = 0; i < 5; ++i) {
		printf("%s %d\n", stu[i].name, stu[i].age);
	}
	printf("\n");

	qsort(stu, 5, sizeof(student), compStudent_age);
	for (int i = 0; i < 5; ++i) {
		printf("%s %d\n", stu[i].name, stu[i].age);
	}
	printf("\n");
	return 0;
#endif

}
#endif

//malloc, free 기초
#if TEST == 2
int main() {
	int* pi;
	double* pd;

	pi = (int*)malloc(10 * sizeof(int));
	if (pi == NULL) {
		printf("메모리 부족");
		exit(1);
	}
	pd = (double*)malloc(10 * sizeof(double));
	if (pd == NULL) {
		printf("메모리 부족");
		exit(1);
	}
	printf("%p %p\n", pi, pd);
	free(pi); free(pd);
	return 0;
}
#endif

//포인터의 사이즈 동적 할당
#if TEST == 3
int main() {
	int* pi;
	int i, sum = 0;
	int N;

	printf("정수 개수 입력: ");
	(void)scanf("%d", &N);
	pi = (int*)malloc(N * sizeof(int));
	if (pi == NULL) {
		printf("메모리가 부족합니다!\n");
		exit(1);
	}
	printf("%d명의 나이를 입력하세요 : ", N);
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", pi + i);
		sum += pi[i];
	}
	printf("%d명의 평균 나이 : %.1lf\n", N, (double)sum / N);
	free(pi);
	pi = NULL;
}
#endif

//메모리 동적할당 횟수 <-> 메모리 할당 해제 횟수
#if TEST == 4
int main() {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int (*b)[4] = NULL;	//메모리 동적할당 1번
	int** c = NULL;		//메모리 동적할당 4번
	int** d = NULL;		//메모리 동적할당 2번
	//int R, C;
	//(void)scanf("%d %d", &R, &C);

	b = (int(*)[4])calloc(3, sizeof(int[4]));	//int[4] 짜리 배열을 3개 만큼 곱한 메모리를 할당받은후, 시작 주소를 int (*) [4] 형으로 반환
	if (b == NULL) exit(0);

	c = (int**)calloc(3, sizeof(int*));
	if (c == NULL) exit(0);
	for (int i = 0; i < 3; ++i) {
		c[i] = (int*)calloc(4, sizeof(int));
		if (c[i] == NULL) exit(0);
	}

	d = (int**)calloc(3, sizeof(int*));	
	if (d == NULL) exit(0);
	d[0] = (int*)calloc(12, sizeof(int));
	if (d[0] == NULL) exit(0);
	for (int i = 1; i < 3; ++i) {
		d[i] = d[0] + sizeof(int) * i;
	}

	int cnt = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			b[i][j] = c[i][j] = d[i][j] = ++cnt;
		}
	}
#if 0
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d ", b[i][j]);
		}
	}
	printf("\n");

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d ", c[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d ", d[i][j]);
		}
	}
	printf("\n");
#endif // 0
	//for (int i = 0; i < 3; ++i) {
	//	for (int j = 0; j < 4; ++j) {
	//		printf("%d %d %d %d\n", a[i][j], b[i][j], c[i][j], d[i][j]);
	//	}
	//}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d %d %d\n", b[i][j], c[i][j], d[i][j]);
		}
	}

}
#endif // TEST == 4

//realloc 활용
#if TEST == 5
int main() {
	int* a = NULL;	//배열의 이름
	int* temp = NULL; //임시 변수
	int N = 0;		//배열의 크기
	int num;		//입력변수
	int count;		//입력받은 데이터 수
	a = (int*)calloc(N, sizeof(int));
	
	for (count = 0; scanf("%d", &num) && num > 0; ++count) {
		if (count == N) {
			N += 3;
			temp = (int*)realloc(a, N * sizeof(int));
			if (temp == NULL) {
				free(temp);
				exit(1);
			}
			a = temp;
		}
		a[count] = num;
	}

	for (int i = 0; i < count; ++i) {
		printf("%d ", a[i]);
	}
	printf("\nN = %d count = %d\n", N, count);
	return 0;
}
#endif

#if TEST == 6
char** inputData(int* N) {
	char temp[80] = { 0 };
	char** str;
	int cnt;
	(void)scanf("%d", N);
	cnt = *N;
	str = (char**)calloc(cnt, sizeof(char*));
	if (str == NULL) exit(1);
	for (int i = 0; i < cnt; ++i) {
		(void)scanf("%s", temp);		//temp를 임시로 입력받고, 그만큼 새로 malloc 할당해서, 주소 지정하고, strcpy로 복사
		str[i] = (char*)malloc(strlen(temp) + 1);
		if (str[i] == NULL) exit(1);
		(void)strcpy(str[i], temp);
	}
	return str;
}
void printData(char** str, int N) {
	for (int i = 0; i < N; ++i) {
		printf("%s ", str[i]);
	}
	printf("\n");
}
void freeHeap(char** str, int N) {
	for (int i = 0; i < N; ++i) {
		free(str[i]);
	}
	free(str);
}
int main() {
	char** str = NULL;
	int N = 0;

	(void)freopen("data.txt", "r", stdin);
	str = inputData(&N);
	printData(str, N);
	freeHeap(str, N);
	str = NULL;
	return 0;
}
#endif
