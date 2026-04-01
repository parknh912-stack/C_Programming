#include "___AAA___.h"
#define TEST 0

#if TEST == 1

int main() {
	int a[5] = { 1,2,3,4,5 };
	int* p = a;
	for (int i = 0; i < SIZE(a); ++i) {
		printf("%d ", a[i]);
		printf("%d\n\n", p[i]);		//확실히, 배열등가포인터 쓰면 어셈블리 1줄 늘어나긴하네
		printf("%d ", *(a + i));
		printf("%d\n\n", *(p + i));
	}
	return 0;
}
#endif

#if TEST == 2

int main() {
	int a[2][3][4] = { 0 };	
	int (*b[3])[4] = { 0 };
	int* (*c[2])(int*) = { 0 };
	int* d[3][4] = { 0 };
	int(*(*e[5])(void))[4] = { 0 };
	//e : 포인터를 담은 5개짜리 배열, 이 포인터는 매개변수가 void고, return이 포인터인 함수를 가리킴
	//이 함수의 반환값은 int [4] 인 배열을 가리킨다.
	//정리 : int [4] 배열을 가리키는 포인터를 리턴하는 매개변수가 void인 함수를 가리키는 포인터를 5개 담은 배열 e

	// b : 포인터 배열 / 요소 : 3개 / datatype : int(*)[4] : 4개짜리 배열을 가리키는 '포인터'
	// sizeof(b) : 요수의 수 * 요소 타입 = 3 * 4 (포인터니까) = 12
	printf("%d\n", sizeof(b));	

	//배열 등가 포인터 선언 pa ~ pe
	int (*pa)[3][4] = a;
	int (**pb)[4] = b;
	int* (**pc)(int*) = c;
	int* (*pd)[4] = d;
	int(*(**pe)(void))[4] = e;
}
#endif

//배열의 이름 (연산, sizeof 등)
#if TEST == 3
int main() {
	int a[3][4] = { 0 };
	//printf("%d %d %d\n", sizeof(a), sizeof(a[0]), sizeof(a[0][0]));
	//printf("%d %d\n", sizeof(&a), sizeof(&a[0]));	//포인터 사이즈 = 4
	//printf("%d %d\n", sizeof(*a), sizeof(*a[0]));	//a -> int [4] 타입 = 16 / *a[0] -> int 타입 = 4
	//printf("%p ", &a);
	//printf("%p\n", &a + 1);
	//printf("%p ", a);
	//printf("%p\n", a + 1);
	//printf("%p ", a[0]);
	//printf("%p\n", a[0] + 1);	//이거랑 바로 위랑 cost 동일
	//printf("%p ", a[1]);
	//printf("%p\n", a[1] + 1);
	/* 순서대로
	0 48
	0 16
	0 4
	16 16+4
	*/
}
#endif
#if TEST == 4
static void print_ary(char (*ary)[10], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%s ", ary[i]);
	}
}
int main() {
	char animal[5][10] = { 0 };
	int i;
	(void)freopen("animal.txt", "r", stdin);
	for (i = 0; i < SIZE(animal); ++i) {
		(void)scanf("%s", animal[i]);
	}
	print_ary(animal, SIZE(animal));
	return 0;
}
#endif

#if TEST == 5
int main() {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	printf("%p\n", a);
	printf("%p\n", &(a + 1)[2]);
	printf("%p\n", &(a + 1)[2]+1);
}
#endif

#if TEST ==6
int main() {
	int* ptr;
	int n[] = { 5,10,22,34,36,44 };
	ptr = n;

	printf("%d ", *ptr++);
	printf("%d\n", *ptr);
	printf("%d ", *ptr+1);
	printf("%d\n", *ptr);
	printf("%d ", ++*ptr);
	printf("%d ", *ptr);
	printf("%d ", *(ptr+1));
	printf("%d ", *ptr);

	printf("%d ", *ptr+=1);
	printf("%d ", *ptr);
	printf("%d ", *++ptr);
	printf("%d ", *ptr);
	printf("%d ", (*ptr)++);
	printf("%d ", *ptr);

}
#endif

#if TEST == 7
int main(void) {
	int a[2][4] = { 0 };
	printf("%d %d", sizeof(a) + 1, sizeof(a[0]));
}
#endif

#if TEST == 8
int main() {
	char* ptr[] = { "red","orange","pink","white","blue","brown","black","gray" };
	printf("%c\n", **ptr);

	printf("%s\n", ptr[1]);

	printf("%s\n", ptr[1]+3);

	printf("%c\n", *(*(ptr+1)+1));

	printf("%c\n", (*(*(ptr + 2) + 1)));

	printf("%s\n", ptr[3]+2);
}
#endif