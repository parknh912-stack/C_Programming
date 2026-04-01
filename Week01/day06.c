#include "___AAA___.h"
#define TEST 0

// #define vs const (매크로 상수 주의사항)
#if TEST == 1
#define TAX_RATE 0.11
double TaxA(int income) {
#define TAX_RATE 0.03
	return ((double)income * TAX_RATE);
}
double TaxB(int income) {
	return ((double)income * TAX_RATE);
}
int main() {
	printf("Tax_Rate(3%%) : %.1lf\n", TaxA(1000000));
	printf("Tax_Rate(11%%) : %.1lf\n", TaxB(1000000));
}
#endif // TEST == 1

// #define vs const (매크로 상수 주의사항)
#if TEST == 2
const double TAX_RATE = 0.11;
double TaxA(int income) {
	const double TAX_RATE = 0.03;		//이건 지역에서만 0.03이고, 밖은 0.11을 쓰게댐
	return ((double)income * TAX_RATE);
}
double TaxB(int income) {
	return ((double)income * TAX_RATE);
}
int main() {
	printf("Tax_Rate(3%%) : %.1lf\n", TaxA(1000000));
	printf("Tax_Rate(11%%) : %.1lf\n", TaxB(1000000));
}
#endif 

//const의 장점이자, 포인터 주의사항
#if TEST == 3
int main() {
	const char* pc = "mango";	//const를 붙이면, 안돼는게 컴파일 단에서 바로 보이니까 굿
	pc = "banana";
	//pc[0] = 't';			//pc는 char 포인터 -> 문자열 상수의 주소만 있는거라서, RO 이다.
	(void)scanf("%s", pc);

	return 0;
}
#endif

//const의 장점이자, 포인터 주의사항, my_{strlen, strcpy, strcat } 만들기
#if TEST == 4
int my_strlen(char* str) {
	char* s;
	if (str == 0)
		return 0;
	for (s = str; *s; ++s);
	return s - str;
}
char* my_strcpy(char* to, const char* from) {
	char* save = to;
	//for (; (*to = *from); ++from, ++to);
	while (*to++ = *from++);
	return save;
}
char* my_strcat(char* s, const char* append) {
	char* save = s;	//주소 수정이 되기 전, s의 시작주소를 save
	for (; *s; ++s);		//*s가 \0이 나올 때 까지 주소를 더해가며 찾음.
	//while(*s++);
	//while ((*s++ = *append++));	//*append를 *s에 대입시키고, 바로 다음 주소로 넘어가며 반복, 대입했는데 그게 \0이면 종료
	for (; *s = *append; ++s, ++append);	//위와 동일함 ㅇㅇ
	return save;				//대입이 완료되면, 해당 s의 시작주소는 훼손돼었으므로, 미리 저장한 save의 주소를 반환 (기존 s)
}
int my_strcmp(const char* s1, const char* s2) {
	while (*s1 == *s2) {		//해당 주소 값이 같으면? 반복문 진행
		if (*s1 == 0)			//같은데, 널이다 -> 완전히 같은것
			return 0;
		++s1;					// 값이 동일할 경우, 둘다 다음 주소를 가르킨다.
		++s2;
	}
	//return (*(unsigned const char*)s1 > *(unsigned const char*)s2) ? 1 : -1;		// 왼쪽이 더 크면 1, 오른쪽이 더 크면 -1
	return *(unsigned const char*)s1 - *(unsigned const char*)(s2);	//이 경우 차이값을 return 하는구나
}
int main() {
	char str[80] = "0xFF";	//const를 붙이면, 컴파일 단에서 오류가 바로 보이니까 굿
	char str2[80] = "0x01";
	printf("%d\n", my_strcmp(str, str2));
#if 0
	my_strcpy(str, "banana");
	printf("%s\n", str);
	str[0] = 't';			//str는 char 배열 -> 문자열 상수를 복사해서 가져온거임 -> RW이다.
	printf("%s\n", str);
	(void)scanf("%s", str);

	my_strcat(str2, str);
	printf("%s\n", str2);
	memset(str2, 0, SIZE(str2));
	printf("초기화 : <%s>\n", str2);
	return 0;
#endif
}
#endif

#if TEST == 5
int main(void) {
	int a = 10, b = 5;
	int c;
	c = a + b;
	printf("%d\n", c);

	return 0;
}
#endif

//static 은 1번만 초기화하는 특징이 있다. + 0으로 자동 초기화 + 메모리가 프로그램 종료까지 남음
#if TEST == 6
int cnt = 0;
int factorial(int n) {
	static int memo[100] = { 0 };	//변수가 선언 뒤로 유지된다. (함수 끝나도, 초기화 X)
	if (n == 0 || n == 1) return 1;
	if (memo[n] != 0) return memo[n];
	memo[n] = n * factorial(n - 1);
	cnt++;
	return memo[n];
}
int main(void) {
	int n = 0;
	printf("factorial(%d) : %d\n", n, factorial(n));
	printf("cnt = %d\n", cnt);
	printf("factorial(%d) : %d\n", n, factorial(n));
	printf("cnt = %d\n", cnt);
}
#endif

//2차원 배열 -> 포인터를 사용하여 참조
#if TEST == 7
int main() {
	int score[3][4] = { 0 };
	int* p= (int *)score;		//명시적 표현이 들어가면 좋다

	(void)freopen("score.txt", "r", stdin);

	for (int i = 0; i < (sizeof(score) / sizeof(score[0][0])); ++i) {
		(void)scanf("%d\n", p + i);	//개선점 : ((int*)score + i) 를 넣는게 더 연산이 적다. 왜? -> 컴파일러가 바로 메모리 주소 연산 가능
		printf("%d ", *(p + i));
	}
	return 0;
}
#endif

/*
2차원 배열 -> scanf로 한번에 4개씩 읽기 vs 12번 읽기
성능 차이는? -> 일단 4개씩 읽는게 더 낫다. 함수 호출 횟수 자체가 느려지니까,
근데 사실 사람이 최적화 하는것보다 컴파일러가 하는게 낫다.
가장 직관적인 코드를 쓰고, 비싼 컴파일러에게 해달라고 하면, 알아서 최적화 해준다.
*/
#if TEST == 8
int main() {
	int score[3][4] = { 0 };	

	(void)freopen("score.txt", "r", stdin);

	for (int i = 0; i < 3; ++i ) {
		(void)scanf("%d %d %d %d", score[i], score[i] + 1, score[i] + 2, score[i] + 3);
	}
	for (int i = 0; i < (sizeof(score) / sizeof(score[0][0])); ++i) {
		(void)scanf("%d", (int*)score + i);
	}
	return 0;
}
#endif