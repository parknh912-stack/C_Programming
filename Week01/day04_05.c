#include "mylib.h"
#define TEST 0

//1~12까지 숫자 .txt로 받아서 출력하기 / 포인터 응용
#if TEST == 1	
#define SIZE(a) (sizeof(a)/sizeof(a[0]))	//런타임 단계에서 계산을 안함
int main(void) {
	(void)freopen("score2.txt", "r", stdin);		//온라인 코테에선 쓰면 안됨

	int score[3][4] = { 0 };

#if 0
	for (int i = 0; i < SIZE(score); i++) {
		for (int j = 0; j < SIZE(score[0]); j++) {
			(void)scanf("%d", &score[i][j]);
			printf("%d ", score[i][j]);	// == *(*(score + i)) + j)
		}
		//printf("\n");
	}

#else
	/*이하 현준님의 방법 (1차원화)*/


	int* scoreP = (int*)(score);	//2차원 배열 score를 1차원 포인터로 형변환
	for (int i = 0; i < sizeof(score) / sizeof(score[0][0]); i++)
	{	//sizeof(score) / sizeof(score[0][0]) : 3*4*4 / 4 = 12
		(void)scanf("%d", scoreP++);	//scoreP + i
		printf("%d ", ((int*)score)[i]);	//*(scoreP + i)
		//scoreP를 증가시켰으니, score를 포인터로 형변환후, 
	}
#endif // 0
	//printf("%d\n", (int*)(&score + 1) - (int*)(&score));
	return 0;
}
#endif	

//strcpy, gets
#if TEST == 2
char* mystrcpy(char* to, const char* from)
{
	char* save = to;

	for (; (*to = *from); ++from, ++to);
	//for (; (*to++ = *from++); );	//동작은 되는데, 이렇게 하면 안된다
									//하나의 명령에 여러 개의 동작이 있으면 안 좋다.

	return save;
}
int main(void) {
	char str1[80] = "tiger";
	char str2[80];
	char ch = 0;

	printf("%s\n", mystrcpy(str2, str1));

	printf("%s\n", str1);
	gets(str1);	//엔터키 까지도 읽어왔다.
	(void)scanf("%c", &ch);
	printf("%s%c\n", str1,ch);

	return 0;
}
#endif

//함수 포인터 예제
#if TEST == 3
int sum(int a, int b) {
	return a + b;
}
int main() {
	//int p = sum;	//sum : 함수 포인터 상수 //이걸 정수형에 넣으면 손실은 없는데...
	int (*p)(int, int) = sum;	//함수 포인터 변수 정의? // 앞에 타입 , 뒤에 파라미터 타입
	//int* p(int, int) = sum;	이건 불가능함 / 이유 : 변수 선언임.
	printf("%d\n", p(10, 10));

	return 0;
}
#endif

//함수의 argument로 배열 넣는 법 -> 배열 등가 포인터 및 사이즈 보내기
#if TEST == 4

#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

int func1(int* ap, int n) {
	int total = 0;
	for (int i = 0; i < n; ++i) {
		total += ap[i];
	}
	return total;
}

int func2(int (*bp)[4], int nr, int nc) {	//int 4개짜리 배열을 가리키는 포인터 = 배열 등가 포인터
	int total = 0;
	for (int i = 0; i < nr; ++i) {
		for (int j = 0; j < nc; ++j) {
			total += bp[i][j];
		}
	}
	return total;
}


int main(void) {
	int arr[5] = { 1,2,3,4,5 };
	int brr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	printf("func1 total : %d\n", func1(arr, SIZE(arr)));
	printf("func2 total : %d\n", func2(brr, SIZE(brr), SIZE(brr[0])));
	printf("func1 total with brr : %d\n", func1(brr, 12));	//어짜피, 메모리에는 1차원이니까, 그냥 address+i 해서 add
	
	return 0;
}
#endif

//가변 배열
#if TEST == 5
int main(void) {
	char* p[3] = { "a","abcd","abc" };
	printf("%c %c %c\n", p[0][2], p[1][1], p[2][2]);
	//굉장히 위험한 코드. 실행은 되는데, p[0][2]는 의도한게 아님
	return 0;
}
#endif

//가변 배열 어딘가에는 길이 정보를 넣어야한다. (가능하면 맨앞)
#if TEST == 6
int main(void) {
	int arr[3] = { 2,1,2 };
	int brr[6] = { 5,1,2,3,4,5 };
	int crr[4] = { 3,1,2,3 };
	//그래서 맨 앞에 0번자리는 갯수를 넣는다
	int* p[3] = { arr,brr,crr };
	printf("%d %d %d\n", p[0][1], p[1][1], p[2][2]);
	//여기선 p[0][2] 이런건 이상하게 읽힘
	//문자열에선 \0이라도 있지, 여기에도 그런게 필요함, 몇개의 데이터가 있는지
	return 0;
}
#endif'

//함수에서 배열의 주소를 지지고 볶아도 의미가 없는 이유
#if TEST == 7
int func(int* p, int n) {
	//++p;	//함수는 배열의 주소를 "복사"해서 받는다. -> 주소끼리 지지고 볶아도 의미가 없다.
	++(*p);	//이건 의미 있음 ㅇㅇ
}

int main(void) {
	int arr[5] = { 1,3,5,7,9 };
	func(arr, 5);

	printf("%d\n", arr[0]);
	return 0;
}
#endif // TEST == 7

//메뉴를 선택하여, 사용자가 원하는 식으로 동작
//시작하면 바로 읽고, 동작 하나 선택하면, 출력 할수도 안할수도
//mylib.c를 사용하는 main
#if TEST == 8
int main(void) {
	//(void)freopen("score.txt", "r", stdin);
	int arr[5] = { 0 };
	int index;
	while (index = choice_menu()) {
		ary_control(index, arr, SIZE(arr));
		system("pause");	//터미널 에서의 동작을 지원하는함수, 깔끔하게 하려고 쓰셨나봄
		system("cls");
	}

	return 0;
}
#endif // TEST == 8

//mylib.c를 읽는 구조체
#if TEST == 9
int main() {
	int ary[5] = { 0 };
	int c;
	while (c = choice_menu2()) {
		ary_control(c, ary, SIZE(ary));
		system("pause");
		system("cls");
	}
	return 0;
}
#endif

//scanf %c 앞에는 공백,탭,개행문자를 넣어야한다.
#if TEST == 10
int main(void) {
	char ch1, ch2;
	//scanf("%c%c", &ch1, &ch2);
	scanf(" %c %c", &ch1, &ch2);
	printf("[%c%c]", ch1, ch2);
	return 0;
}
#endif

//getchar, putchar 기초
#if TEST == 11
int main(void) {
	char ch1, ch2;
	ch1 = getchar();		//얘는 공백,탭,개행 도 입력받는다.
	ch2 = getchar();
	putchar(ch1);
	putchar(ch2);
	printf("[%c%c]", ch1, ch2);
	return 0;
}
#endif

//08-5 
#if TEST == 12
int main(void) {
	char str[6];
	my_gets(str, SIZE(str));
	printf("%s\n", str);

	return 0;
}
#endif

//08-6 to_upper 만들기
#if TEST == 13
int main(void) {
	char name[40] = "Tom & Jerry!";
	//to_upper(name, SIZE(name));
	printf("%s\n", to_upper(name));
	printf("%s\n", to_upper2(name));
	return 0;
}
#endif