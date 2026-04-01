#include "___AAA___.h"
#define TEST 0

//문자 상수 와 정수의 연관성
#if 0
int main(void)
{
	int a = 'A';
	int b, c;
	b = a + 32;
	c = a + ('a' - 'A');

	printf("%c %c \n", b, c);
	return 0;
}
#endif

//typedef의 사용
#if 0
typedef int INTARR5[5];
typedef int* IP;

int main(void)
{
	int a[5] = { 1 }, b[5] = { 2 }, c[5] = { 3 };
	INTARR5 x, y, z;	//int 5개짜리 배열 타입을 만들 수 있다.
	IP ai, bi, ci;
	printf("%d %d %d\n", a[0], b[0], c[0]);

	return 0;
}
#endif

//bit로 저장되니까, 주의해야함	(overflow) 에 대한 내용임
#if 0
int main(void)
{
	unsigned char uch1 = -1;	//0XFF
	unsigned char uch2 = 128;	//0x80 (1000 0000)

	signed char ch1 = -1;		//0XFFFFFFFF
	signed char ch2 = 128;		//OXFFFFFF80

	printf("unsigned char(%%u) : %x %x\n", uch1, uch2);
	printf("signed char(%%d) : %x %x\n", ch1, ch2);

}
#endif

// 포인터와 sizeof
#if 0
int main(void)
{
	int num = 10;
	int* p = &num;
	
	printf("%zu %zu\n", sizeof(num), sizeof(p));
	printf("%p %p\n", p, &num);
	printf("%d %d\n", *p, num);

}
#endif

//const 변수와 포인터 활용
#if 0
#include <string.h>

int main(void)
{
	int income = 0;
	double tax;
	const double tax_rate = 0.12;
	double* dp = &tax_rate; //const로 변경 불가능하지만, 주소에 접근해서 데이터를 덮어씌운다.

	*dp = 0.15;
	
	income = 456;
	tax = income * tax_rate;
	printf("세율 : %.2lf\n", tax_rate);
	printf("세금 : %.2lf\n", tax);
	printf("%d\n", strlen("apple"));	//""은 문자열 상수, RO(read only)에 쓴다.
	return 0;
}
#endif

//scanf 사용법
#if 0
int main(void)
{
	int a;
	scanf_s("%d", &a);
	printf("입력된 값 : %d\n", a);
	return 0;
}
#endif

//scanf의 런타임 에러 발생의 경우
#if 0
int main(void)
{
	char str[5];
	printf("문자열 입력 : ");
	//scanf("%s", str);	//길이 제한 없음 -> 버퍼 초과시 런타임 에러 발생
	scanf_s("%s", str, 5);	//길이 제한 있음. 에러 X
	printf("입력값: %s\n", str);
	return 0;
}
#endif

//비트 연산자 활용 1 - 시험	01-10n
#if 0
unsigned int setBit(unsigned int num, int bitPosition)
{
	return num | (0x1 << bitPosition);
}

unsigned int clearBit(unsigned int num, int bitPosition)
{
	return num & ~(0x1 << bitPosition);
}

unsigned int toggleBit(unsigned int num, int bitPosition)
{
	return num ^ (0x1 << bitPosition);
}

int main(void)
{
	unsigned int num = 0b1010;
	printf("Initial value : %X\n", num);

	num = setBit(num, 2);
	printf("After setting bit 2 : %X\n", num);

	num = clearBit(num, 1);
	printf("After clearing bit 1 : %X\n", num);

	num = toggleBit(num, 3);
	printf("After toggling bit 3 : %X\n", num);
}
#endif // 0

//비트 연산자 활용 2 - 시험 01-10o
#if 0
unsigned int setBits(unsigned int num, int start, int count)
{
	return num | ((0x1 << count) - 1) << start;		//2^(3)-1 = 0b1000-0b1 = 0b0111 이니까 그거 활용
}

unsigned int clearBits(unsigned int num, int start, int count)
{
	return num & ~(((0x1 << count) - 0x1) << start);
}

unsigned int toggleBits(unsigned int num, int start, int count)
{
	return num ^ (((0x1 << count) - 0x1) << start);
}

int main(void)
{
	unsigned int num = 0xAA;

	printf("Initial value : %X\n", num);

	num = setBits(num, 2,3);
	printf("%X\n", num);

	num = clearBits(num, 4,2);
	printf("%X\n", num);

	num = toggleBits(num, 1,5);
	printf("%X\n", num);

	return 0;
}
#endif // 0

//비트 연산자 활용 3 - 시험 01-10q
#if 0
static unsigned int isBitSet(unsigned int num, int bitPosition)
{
	return (num >> bitPosition) & 0x1;
}
int main(void)
{
	unsigned int num = 0;
	unsigned int bitPosition = 0;
	printf("숫자 입력 : ");
	scanf("%u", &num);

	printf("비트위치 입력 (0-31) : ");
	scanf("%u", &bitPosition);
	unsigned int res = isBitSet(num, bitPosition);

	printf("숫자 %u의 %d번째 위치 : %u\n", num, bitPosition, res);
	return 0;
}
#endif // 0

//01-11a 변수의 연산 (부호 비트)
#if 0
int main(void)
{
	char x = 127; //127 = 0xFF
	char y = x + 1;
	printf("x = %d, x + 1 = %d, y = %d\n", x, x + 1, y);

	return 0;
}
#endif // 0

//숫자 뒤집기
#if 0
int main(void)
{
	int a;
	int b = 0;

	scanf("%d", &a);
	
	while(a!=0){
		b += a % 10;
		a /= 10;
		if (a!=0) {
			b *= 10;
		}
	}
	printf("%d\n", b);
	return 0;
}
#endif // 0

//복합대입연산자
#if 0
int main(void)
{
	int a = 20, b = 5;
	//a %= b -= 1;				//똑같넹
	a = a % (b = b - 1);		//python 에서는 막아둠
	printf("a= %d, b= %d\n", a, b);
	return 0;
}
#endif

