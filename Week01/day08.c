#include "___AAA___.h"

#define TEST 0
/******************/
//배열의 크기
#if TEST == 1
int main() {
	int ary[5] = { 1,2,3,4,5 };
	printf("%p %p %p\n", &ary, ary, &ary[0]);
	printf("%zu %zu %zu\n", sizeof(&ary), sizeof(ary), sizeof(&ary[0]));

	char c_ary[10] = "rabbit";
	printf("%p %p %p\n", &ary, ary, &ary[0]);
	printf("%zu %zu %zu\n", sizeof(&ary), sizeof(ary), sizeof(&ary[0]));
	printf("%zu %zu\n", sizeof(&"rabbit"), sizeof("rabbit") );

}
#endif

// 다중포인터
#if TEST == 2
void exchange1(int** a, int** b) {
	int temp = **a;
	**a = **b;
	**b = temp;
}
void exchange2(int*** a, int*** b) {
	int temp = ***a;
	***a = ***b;
	***b = temp;
}
void exchange3(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void exchange4(int** a, int** b) {
	int temp = **a;
	**a = **b;
	**b = temp;
}
void exchange5(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int a = 10;
	int b = 20;
	int* ap = &a;
	int* bp = &b;
	int** app = &ap;
	int** bpp = &bp;

	printf("%d %d\n", a, b);
	exchange1(&ap, &bp);
	printf("%d %d\n", a, b);
	exchange2(&app, &bpp);
	printf("%d %d\n\n", a, b);

	printf("%p %p\n", ap, bp);
	exchange3(&ap, &bp);
	printf("%p %p\n", ap, bp);
	exchange4(&app, &bpp);
	printf("%p %p\n\n", ap, bp);

	printf("%p %p\n", app, bpp);
	exchange5(&app, &bpp);
	printf("%p %p\n", app, bpp);

	return 0;
}

#endif // TEST == 2

//배열 등가 포인터 ( 2차원 에서의 례)
#if TEST == 3
void print_ary(char (* ary)[10], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%s\n", ary[i]); //=pary[i]
	}
}
void print_ary2(char** ary, int size) {		//불가능
	for (int i = 0; i < size; ++i) {
		printf("%s\n", ary[i]); //=pary[i]
	}
}
int main() {
	char pary[5][10] = {"dog","elephant","horse","tiger","lion"};
	print_ary(pary, SIZE(pary));
	print_ary2(pary, SIZE(pary));
	return 0;
}
#endif // TEST == 3

//포인터 배열 내용
#if TEST == 4
int main() {
	int ary1[5] = { 4, 1,2,3,4 };
	int ary2[8] = { 7, 11,12,13,14,15,16,17 };
	int ary3[4] = { 3, 21,22,23 };
	int* pary[4] = { ary1, ary2, ary3 };
	int ary[3][4] = { 1,2,3,4,11,12,13,14,21,22,23,24 };
	for (int i = 0; i < 3; ++i) {
		for (int j = 1; j <= pary[i][0]; ++j) {
			printf("%5d", pary[i][j]);
			//printf("%5d", ary[i][j]);
		}
		printf("\n");
	}
}
/*A : 느린 동작 -> 메모리 접근 4회
	printf("%5d", pary[i][j]);
007F578C  mov         eax,dword ptr [ebp-0A4h]  
007F5792  mov         ecx,dword ptr pary[eax*4]  
007F5796  mov         edx,dword ptr [ebp-0B0h]  
007F579C  mov         eax,dword ptr [ecx+edx*4]  

B : 빠른 동작 -> 메모리 접근 2회
	printf("%5d", ary[i][j]);
007F57AD  mov         eax,dword ptr [ebp-0A4h]  
007F57B3  shl         eax,4  
007F57B6  lea         ecx,ary[eax]  
007F57BD  mov         edx,dword ptr [ebp-0B0h]  
007F57C3  mov         eax,dword ptr [ecx+edx*4]  */
#endif

//함수 포인터 예시 -> 함수 자체를 매개변수로 사용하는 법
#if TEST == 5
void print_ary(int* ary, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
}
int comp_asc(int a, int b) {
	return a > b;
}
int comp_desc(int a, int b) {
	return a < b;
}
void sort_ary(int* ary, int size, int(*func)(int, int)) {
	int temp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (func(ary[i],ary[j])) {
				temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
}

#define size_ary(x) (sizeof(x) / sizeof((x)[0]))

int main() {

	int ary[] = { 8, 5, 2, 12, 7, 9, 4, 6, 10, 3 };

	print_ary(ary, size_ary(ary));
	sort_ary(ary, size_ary(ary), comp_asc);
	print_ary(ary, size_ary(ary));
	sort_ary(ary, size_ary(ary), comp_desc);
	print_ary(ary, size_ary(ary));

	return 0;
}
#endif // TEST == 5

//함수포인터배열 및 형 변환의 중요성
#if TEST == 6
int sum(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
void func(int(**op)(int, int), int size, char** ch,int a, int b) {
	for (int i = 0; i < size; ++i) {
		printf("%d %s %d = %d\n", a, ch[i], b, (*(op + i))(a, b));	//=op[i](a,b)
	}
}
void funcv(void(**vop), int size, char** ch, int a, int b) {
	for (int i = 0; i < size; ++i) {
		printf("%d %s %d = %d\n", a, ch[i], b, ((int (*)(int,int))vop[i])(a,b));	//void 형이면 엄청나게 긴 형변환이 필요하다... -> 비추천
	}
}
int main() {
	int (*op[3])(int, int) = { sum, sub, mul };	//함수를 가리키는 포인터의 배열 - 함수 포인터 배열
	void* vop[3] = { sum,sub,mul };		//void 형 포인트 배열 -> 함수도 넣을 수 있음

	char* ch[3] = { "+", "-", "*" };			//char형 포인터 배열
	int a, b;

	(void)scanf("%d %d", &a, &b);
	func(op, 3, ch, a, b);
	funcv(vop, 3, ch, a, b);
	return 0;
}
#endif // TEST == 6

//분석 해볼것
#if TEST == 7
int sum(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int(*func(int (**op)(int, int), int n))(int, int) {	//int를 반환하는 함수를 가리키는  (매개변수로 함수 2중포인터와 정수형을 가지는 포인터함수)
	int a = 20;
	int b = 5;
	for (int i = 0; i < n; ++i) {
		printf("%d\n", op[i](a, b));
	}
	return op[0];
}

void funcv(void** vop, int n) {
	int a = 20;
	int b = 5;
	for (int i = 0; i < n; ++i) {
		printf("%d\n", ((int(*)(int, int))vop[i])(a, b));
	}
}

int main(void) {
	int (*op[3])(int, int) = { sum, sub, mul };
	void* vop[3] = { sum, sub, mul };

	func(op, 3);
	funcv(vop, 3);
	return 0;
}
#endif
