// PART 01 - 총 25문제
#include "practice.h"

#if PART == 1

// ==================== 문제 01 ====================
#if PROBLEM == 1

/*
문제: 정수를 배열에 저장하고, 최소값, 최대값, 평균값 계산하기

풀이 아이디어: 정수 입력 받아서, sum에다가 다 더하고, min과 max를 비교하면서 갱신하고, 마지막에 평균값 계산

*/

int main(void)
{
	int arr[10];
	int min = INT16_MAX;
	int max = INT16_MIN;
	int sum = 0;


	for (int i = 0; i < 10; i++) {
		printf("%d번째 숫자를 입력하세요.", i + 1);
		scanf("%d", &arr[i]);

		sum += arr[i];	//평균을 구하기 위해서

		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	printf("최소값 : %d\n", min);
	printf("최대값 : %d\n", max);
	printf("평균값 : %.2f\n", (float)sum / 10);
	return 0;
}

#endif // PROBLEM == 1

// ==================== 문제 02 ====================
#if PROBLEM == 2

/*
문제: 랜덤 숫자 만들기

풀이 아이디어: 대충 rand() 함수 쓰면 된다 ㅇㅇ

*/

int main(void)
{
	int arr[10];
	int dice[30];
	int rand_min = 1;
	int rand_max = 6;

	srand(time(0));		//시드 매번 초기화 해주는거
	for (int i = 0; i < 30; i++) {
		dice[i] = rand() % (rand_max - rand_min + 1) + rand_min;
		printf("%6d%c", dice[i], (i + 1) % 10 != 0 ? ' ' : '\n');
	}

	return 0;
}

#endif // PROBLEM == 2

// ==================== 문제 03 ====================
#if PROBLEM == 3

/*
문제: 주사위 2개를 백만번 던져서 나오는 두 주사위 숫자의 합을 배열에 저장 및 확률 출력

풀이 아이디어: 두 주사위를 랜덤한 값으로 뱉어서, 더하면 2~12 거든요? 아마 중간값이 제일 확률이 높겠죠?
1. 주사위를 2개를 던진다.
2. 주사위를 더한다
3. 배열에 저장한다.
4. 확률을 계산한다
5. 확률을 출력한다.

*/
#define TRIALS 1000000
int main(void)
{
	int sum[13] = { 0 };	// 합은 2 ~ 12 까지니까.. 그냥 대충 0 ~ 12 저장하는 배열로 만들자.
	int rand_min = 1;
	int rand_max = 6;
	int dice;

	srand(time(0));

	for (int i = 0; i < TRIALS; i++)
	{
		dice = (rand() % (rand_max - rand_min + 1) + rand_min;) + (rand() % (rand_max - rand_min + 1) + rand_min;);
		sum[dice]++;	//횟수 셀때 이런거 자주 쓰임 ㅇㅇ
	}
	int total = 0;
	for (int j = 2; j < 13; j++) {
		printf("sum[%d] = %d 번, %.2f %%\n", j, sum[j], (float)sum[j] / TRIALS * 100);
		total += sum[j];
	}
	printf("TRIALS = %d\n", total);
	return 0;
}

#endif // PROBLEM == 3

// ==================== 문제 04 ====================
#if PROBLEM == 4

/*
문제: 겹치지 않는 1~10까지의 랜덤 숫자 출력

풀이 아이디어:	visited[] 만들어서, 체크할거 같아요 저라면.
1. 랜덤 숫자를 뽑는다.
2. visited와 대조한다.
3. 중복 아니면, true로 만들고, 결과에 넣는다.
4. 결과 (배열)을 출력한다.


참고 : 피셔-에이츠 방식이 더 반복횟수도 적고 좋지만, 해당 문제의 핵심은 중복검사이므로 제외함
*/

int main(void)
{
	bool visited[11] = { false };
	int rand_min = 1;
	int rand_max = 10;
	int number[10];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		int rand_number;
		while (1) {
			rand_number = rand() % (rand_max - rand_min + 1) + rand_min;
			if (visited[rand_number] == false) {
				visited[rand_number] = true;
				number[i] = rand_number;
				break;
			}
		}

		printf("%6d%c", number[i], (i + 1) % 5 != 0 ? ' ' : '\n');
	}

	return 0;
}

#endif // PROBLEM == 4

// ==================== 문제 05 ====================
#if PROBLEM == 5

/*
문제:	0~51 까지의 숫자를 랜덤하게 만들고, visited[] 배열을 만들기.
		0~12 까지가 클로버, 하트 스페이드 다이아몬드 순으로
		0~51 까지 겹치지 않는 숫자 52개와 이를 해석해서 카드로 출력하는 프로그램 작성
풀이 아이디어:

*/
#define CARDS	52
#define CLOVER	0
#define HEART	1
#define SPADE	2
#define DIAMOND	3

int main(void)
{
	bool visited[CARDS] = { false };
	int cards[CARDS];
	int rand_min = 0;
	int rand_max = 51;
	char suit;				//카드 무늬 (클로버, 하트, 스페이드, 다이아몬드 순)

	srand((unsigned)time(NULL));
	for (int i = 0; i < CARDS; i++) {
		int x;
		do {
			x = rand() % CARDS;
		} while (visited[x] == true);
		visited[x] = true;
		cards[i] = x;
	}
	printf("\n");

	for (int i = 0; i < CARDS; i++)
	{
		printf("%5d%c", cards[i], (i + 1) % 13 != 0 ? ' ' : '\n');
	}

	for (int i = 0; i < CARDS; i++)
	{
		int denom = cards[i] % 13 + 1;
		suit = (cards[i] / 13 == CLOVER) ? 'C' : (cards[i] / 13 == HEART) ? 'H' : (cards[i] / 13 == SPADE) ? 'S' : 'D';
		printf("%c %2d%c", suit, denom, (i + 1) % 13 != 0 ? ' ' : '\n');
	}


	return 0;
}

#endif // PROBLEM == 5

// ==================== 문제 06 ====================
#if PROBLEM == 6

/*
문제: 라이프니츠의 원주율 공식으로 원주율 계산하는 프로그램 작성

풀이 아이디어:
1. 반복문을 2씩 증가시켜서, 라이프니츠 공식에 사용
2. 숫자는 대략 1천만까지 증가
3. sign이라는 플래그를 이용하여 더하기 빼기를 반복
4. AI 사용 최소화 (전체 작성은 지양)
5. pi는 더블형
*/

int main(void)
{
	bool sign = true;	//true면 더하기, false면 빼기
	double pi = 0;		//초기화 할것;;;

	for (int i = 1; i <= 10000000; i += 2)
	{
		if (sign == true) {
			pi += (1.0 / i);
			sign = false;
		}
		else {
			pi -= (1.0 / i);
			sign = true;
		}
		if (i < 10 || i >(10000000 - 10))
			printf("i = %10d, pi = %.18f\n", i, 4 * pi);
	}
	return 0;
}

#endif // PROBLEM == 6

// ==================== 문제 07 ====================
#if PROBLEM == 7

/*
문제: 몬테카를로 시뮬레이션으로 원주율 구하기

풀이 아이디어:
1. pi = (원의 면적) / (사각형의 면적) * 4
2. 원의 면적을 구하는 방법
	사각형 안에 위치하는 점을 랜덤하게 만든다.
	원 안에 위치하는 점과 바깥에 위치하는 점의 갯수를 카운트 한다.
	아주 많이 만들면, 면적에 대한 비율로 점의 갯수를 사용 가능
	A = 원 안의 점의 갯수
	N = 전체 점의 갯수
	즉, pi = A / N * 4
3. 원의 방정식으로 사용함. (x-r)^2 + (y-r)^2 <= r^2

개선점
1. x,y 좌표를 double로 만들기
2. 중심에서의 거리를 변수로 분리
*/
#define TRIALS 10000000

int main(void)
{
	double pi = 0;
	//int x, y;
	double x, y;
	int inside_count = 0;
	int outside_count = 0;
	int radius = 50;	//반지름

	srand((unsigned)time(NULL));
	//for (int i = 0; i < TRIALS; i++) {
	//	x = rand() % 100;
	//	y = rand() % 100;	//(0 ~ 99 까지인가?)

	//	if ((x - radius) * (x - radius) + (y - radius) * (y - radius) <= radius * radius)
	//		inside_count++;
	//	else
	//		outside_count++;
	//}
	for (int i = 0; i < TRIALS; i++) {
		x = (double)rand() / RAND_MAX * (2 * radius);
		y = (double)rand() / RAND_MAX * (2 * radius);

		double dx = x - radius;
		double dy = y - radius;
		if (dx * dx + dy * dy <= radius * radius)
			inside_count++;
		else
			outside_count++;
	}

	if (TRIALS != inside_count + outside_count)
		return 1;
	pi = (double)inside_count / TRIALS * 4;
	printf("inside_count = %d , outside_count = %d , pi = %.18f", inside_count, outside_count, pi);

	return 0;
}

#endif // PROBLEM == 7

// ==================== 문제 08 ====================
#if PROBLEM == 8

/*
문제: enum으로 커피 가격표 출력

풀이 아이디어:

*/
enum Size {
	S,
	T,
	G,
	V
};
char sizeName[][7] = {
	"Short",
	"Tall",
	"Grande",
	"Venti",
};
int price_Americano[] = {
	3800, 4100, 4600, 5100
};
int price_Cappuccino[] = {
	4600, 5900, 6400, 6900
};
int main(void)
{
	printf("커피 가격표(아메리카노)\n");
	for (int i = S; i <= V; i++)
		printf("%10s : %5d\n", sizeName[i], price_Americano[i]);


	printf("커피 가격표(카푸치노)\n");
	for (int i = S; i <= V; i++)
		printf("%10s : %5d\n", sizeName[i], price_Cappuccino[i]);


	return 0;
}

#endif // PROBLEM == 8

// ==================== 문제 09 ====================
#if PROBLEM == 9

/*
문제: (패스) 이중 반복문으로 피라미드 그리기

풀이 아이디어:

*/

int main(void)
{
	// 여기에 풀이를 작성하세요.

	return 0;
}

#endif // PROBLEM == 9

// ==================== 문제 10 ====================
#if PROBLEM == 10

/*
문제: 2 ~ 1000까지 소수 출력 + 몇개인지 출력

풀이 아이디어:
1. 1과 자신 외에는 나눠지지 않는 숫자
2. % 와 이중 반복문 사용하면 될듯
*/

int main(void)
{
	int primes_count = 0;
	int index;

	for (int i = 2; i <= 1000; i++) {
		for (index = 2; index < i; index++) {
			if (i % index == 0)
				break;
		}
		if (index == i) {
			primes_count++;
			printf("%5d%c", i, (primes_count) % 10 == 0 ? '\n' : ' ');
		}
	}
	printf("\n소수의 갯수 : %5d\n", primes_count);
	return 0;
}

#endif // PROBLEM == 10

	// ==================== 문제 11 ====================
#if PROBLEM == 11

/*
문제: 에라스토테네스의 체 (소수를 찾는 또 다른 방법인듯)

풀이 아이디어:
1. 1과 0을 저장하는 배열을 만들고 소수면 1 아니면 0
2. i 의 배수가 되는 배열의 원소를 0으로 바꿈
3. 과정을 반복한뒤, 앞에서 부터 a[i] == 1 인걸 출력
---
1. 처음에는 모든 배열이 1
2. 2의 배수를 0으로
3. 3의 배수를 0으로
4. N/2 까지 반복
---
개선점
1. 이미 지워진 i는 생략하기
2. 배수 지우기를 i * i 부터 시작하기
3. 바깥 반복은 i * i < N 까지만 하기
*/
#define N (1000)
int main(void)
{
	bool a[N + 1];
	for (int i = 0; i <= N; i++)
		a[i] = true;
	a[0] = a[1] = false;

	int primes_count = 0;
	int count = 0;	//연산 기록용
#if 0
	for (int i = 2; i <= N / 2; i++)
	{
		for (int j = 2; j <= N / i; j++)
		{
			a[i * j] = false;
			count++;
		}
	}
#endif // 0

	for (int i = 2;  i * i <= N; i++)
	{
		if (a[i] == false)	// 1. 이미 지워진 i는 생략하기
			continue;

		for (int j = i; j <= N / i; j++)
		{
			a[i * j] = false;
			count++;
		}
	}
	
	for (int i = 0; i <= N; i++)
	{
		if (a[i] == true) {
			primes_count++;
			printf("%5d%c", i, (primes_count) % 10 == 0 ? '\n' : ' ');
		}
	}

	printf("\n소수의 갯수 : %5d\n", primes_count);
	printf("\n연산 횟수 : %5d\n", count);

	return 0;
}

#endif // PROBLEM == 11

	// ==================== 문제 12 ====================
#if PROBLEM == 12

/*
문제: scanf 심화 사용법 (패스)

풀이 아이디어:

*/

	int main(void)
	{
		// 여기에 풀이를 작성하세요.

		return 0;
	}

#endif // PROBLEM == 12

	// ==================== 문제 13 ====================
#if PROBLEM == 13

/*
문제: 문자열의 처리

풀이 아이디어:

*/

int main(void)
{
	char s[10] = { 'a','b','c','d','e' };
	char t[] = { 'a','b','c','d','e','\0' };
	char u[] = "abcde";
	char v[] = "안녕하세요";

	printf("s = |%s| size = %d\n", s, sizeof(s));
	printf("s = |%s| size = %d\n", t, sizeof(t));
	printf("s = |%s| size = %d\n", u, sizeof(u));
	printf("s = |%s| size = %d\n", v, sizeof(v));

	return 0;
}

#endif // PROBLEM == 13

	// ==================== 문제 14 ====================
#if PROBLEM == 14

/*
문제: 문자열 배열 (너무 쉽다 스킵)

풀이 아이디어:

*/

	int main(void)
	{
		// 여기에 풀이를 작성하세요.

		return 0;
	}

#endif // PROBLEM == 14

	// ==================== 문제 15 ====================
#if PROBLEM == 15

/*
문제: 포인터 연산자 사용하기 (스킵)

풀이 아이디어:

*/

	int main(void)
	{
		// 여기에 풀이를 작성하세요.

		return 0;
	}

#endif // PROBLEM == 15

	// ==================== 문제 16 ====================
#if PROBLEM == 16

/*
문제: call by value 와 call by reference
* 기본적으로 c언어는 call by value 라서 매개변수로 포인터를 보내야 call by reference가 가능함 ㅇㅇ 스킵
풀이 아이디어:

*/

	int main(void)
	{
		// 여기에 풀이를 작성하세요.

		return 0;
	}

#endif // PROBLEM == 16

	// ==================== 문제 17 ====================
#if PROBLEM == 17

/*
문제: 포인터와 배열 (중요한 내용이긴해)(근데 알고있으니 스킵ㅇㅇ)
* 배열의 이름은 포인터이다.
* 배열등가포인터를 쓰면 배열을 매개변수로 넘길 수 있다
* a = &a[0] 이다 ㅇㅇ
* p = a; 로 포인터와 배열을 연결시키면?
* *p = a[0]
* *(p+1) = a[1]

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
문제: 포인터의 연산 (스~킵)
* 

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
문제: 이중 포인터와 포인터 배열 *p[] 이런거가 포인터 배열임 ㅇㅇ 너무 쉬우니 패스

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
문제: 문자열의 길이와 문자열의 비교 함수 구현 (임베디드 스쿨 day06 참고)

풀이 아이디어: strlen , strcmp를 직접 구현하는 거. 이거 예~~전에 해봤었지? ㅇㅇ 근데 기억 안나니까 다시 해보자고
* size_t = unsigned int
*/

	size_t my_strlen(const char* s)
	{
		size_t i = 0;
		while (s[i] != '\0')
			i++;
		return i;
	}
	size_t my_strlen2(const char* s)
	{
		char* p = s;
		while (*p != '\0')
			p++;
		return p - s;	//주소의 차이를 이용한 방식이네 이건
	}
	int my_strlen3(char* str) {
		char* s;
		if (str == 0)
			return 0;
		for (s = str; *s; ++s);
		return s - str;
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
	int main(void)
	{
		// 여기에 풀이를 작성하세요.
		
		return 0;
	}

#endif // PROBLEM == 20

	// ==================== 문제 21 ====================
#if PROBLEM == 21

/*
문제: strcpy, strcat (임베디드 스쿨 day06 참고)

풀이 아이디어:

*/
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
	int main(void)
	{
		// 여기에 풀이를 작성하세요.

		return 0;
	}

#endif // PROBLEM == 21

	// ==================== 문제 22 ====================
#if PROBLEM == 22

/*
문제: 대문자 소문자의 변환
upper lower 인데 
아스키 코드에다가 32였나 더하면 됌, 혹은 그냥 바로 'A' - 'a' 해도 무방함ㅋㅋ

풀이 아이디어: 기본적으로는 strcpy 와 비슷할듯?

*/
	char* to_upper(char* s)
	{
		char* ptr = s;
		while (*ptr)
		{
			if (*ptr >= 'a' && *ptr <= 'z')
				*ptr +=  ('A' - 'a');
			ptr++;
		}
		return s;
	}
	char* to_lower(char* s)
	{
		char* ptr = s;
		while (*ptr)
		{
			if (*ptr >= 'A' && *ptr <= 'Z')
				*ptr -=  ('A' - 'a');
			ptr++;
		}
		return s;
	}
	int main(void)
	{
		// 여기에 풀이를 작성하세요.
		char s[] = "Hello World";

		printf("to_upper() : %s\n", to_upper(s));
		printf("to_lower() : %s\n", to_lower(s));
		return 0;
	}

#endif // PROBLEM == 22

	// ==================== 문제 23 ====================
#if PROBLEM == 23

/*
문제: 문자열 뒤집기 (strrev와 같은 기능) (★★★★★직접 해보자!!!)

풀이 아이디어: 기본적으로 흠... 맨 뒤에서 부터 복사하는 느낌으로 하면 될거같긴해...
strcat 에서 마지막으로 이동하는 그 함수에다가,
마지막부터 -1 하면서 새롭게 저장하는 느낌으로 하면될듯,
즉, strcat의 응용판일거 같다.
*/	
	char* my_strrev(char* s)
	{
		char* end = s + strlen(s) - 1;
		for (char* ptr = s ;ptr < end; ptr++, end--)
		{
			char temp = *ptr;
			*ptr = *end;
			*end = temp;
		}
		return s;
	}
	char* my_strrev2(char* s)
	{
		char* save = s;  // 반환할 시작 주소
		char* ptr = s;   // 왼쪽 포인터

		if (*s == '\0')  // 빈 문자열 처리
			return save;

		while (*s)
			s++;        // '\0' 위치까지 이동
		s--;            // 마지막 문자 위치로 이동

		for (; ptr < s; ptr++, s--)
		{
			char temp = *ptr;
			*ptr = *s;
			*s = temp;
		}

		return save;
	}

	int main(void)
	{
		char s[] = "Hello World";
		char s1[] = "Hello World";

		printf("_strrev() : %s\n", _strrev(s));
		printf("my_strrev() : %s\n", my_strrev2(s1));

		return 0;
	}

#endif // PROBLEM == 23

	// ==================== 문제 24 ====================
#if PROBLEM == 24

/*
문제: 정수와 문자열의 반환 (atoi, itoa)

풀이 아이디어:
문자열을 받아서 (문자열인데, 내용은 숫자인거)


*/
	int my_atoi(const char* s)
	{
		int value = 0;
		
		while (*s)	//내용물이 있다면
		{
			if (*s >= '0' && *s <= '9') {
				value = value * 10 + *s - '0';
				s++;
			}
			else {
				return -1; //숫자인 문자열이 아님
			}
		}
		return value;
	}

	char* my_itoa(int v)
	{
		int digits = 0; //자리수 구해야지
		int t = v;

		while (t)
		{
			digits++;
			t /= 10;
		}
		char* number = (char*)calloc(digits + 1, sizeof(char));
		number[digits] = NULL;
		while (digits != 0)
		{
			number[--digits] = v % 10 + '0';
			v /= 10;
		}
		return number;
	}
	int main(void)
	{
		char buffer[20];

		printf("atoi() : %d\n", atoi("1234567"));
		printf("my_atoi() : %d\n", my_atoi("1234567"));

		_itoa_s(1234567, buffer, _countof(buffer), 10);
		printf("itoa() : %s\n", buffer);
		printf("my_itoa() : %s\n", my_itoa(1234567));
		return 0;
	}

#endif // PROBLEM == 24

	// ==================== 문제 25 ====================
#if PROBLEM == 25

/*
문제: 문자열 안에서 다른 문자열 찾기 (strstr)

풀이 아이디어:
1. 매개변수는 2개일거임. 원본(const) 와 찾을 내용(const)
2. 있으면 해당 문자열을, 없으면 NULL을 반환
3. 찾는 방식은... 

*/
	char str[] = "ababacabcaab";
	char sub[] = "abc";
	char* my_strstr(const char* str, const char* sub)
	{
		int len1 = strlen(str);
		int len2 = strlen(sub);

		if (len2 == 0)
			return (char*)str;	//sub가 없으면 그냥 맞는다고 가정

		while (len1 >= len2)
		{
			char* s = (char*)str;
			char* t = (char*)sub;
			while (*s == *t && *t != NULL) //둘이 동일하고, *t가 비어있지 않다면
			{
				s++;
				t++;
			}
			if (*t == NULL)			// 동일하게 되었다면?
				return (char*)str;	
			str++;
			len1--;
		}
		return NULL;
	}


	char* my_strstr2(const char* str, const char* sub)
	{
		if (*sub == '\0')
			return (char*)str;

		for (; *str != '\0'; str++)
		{
			const char* s = str;
			const char* t = sub;

			while (*t != '\0' && *s == *t)
			{
				s++;
				t++;
			}

			if (*t == '\0')
				return (char*)str;
		}

		return NULL;
	}


	int main(void)
	{
		printf("strstr() : %s\n", strstr(str, sub));
		printf("my_strstr() : %s\n", my_strstr(str, sub));
		printf("my_strstr2() : %s\n", my_strstr2(str, sub));

		return 0;
	}

#endif // PROBLEM == 25

#endif // PART == 1
