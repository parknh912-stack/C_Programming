#include "___AAA___.h"

//False로 취급되는 것들 : 0.0 0'\0' NULL 
#if 0
int main(void)
{
	if () {
		printf("True\n");
	}
	else {
		printf("False\n");
	}
	return 0;
}
#endif

//조건문 statement 로 올수 없는 것 -> 대표1. 함수 정의
#if 0
int main(void) {
	int a = 100;
	if (a > 0) 
	{
#include <stdbool.h>

	}
	//{
	//int sum(int a, int b) {
	//return a + b;}
	//}
	return 0;
}
#endif // 1

//짝수 홀수 판정 프로그램	
#if 0
int main(void)
{
	char* msg = NULL;
	int num = 100;
	//if (num % 2) {			//num%2 = num%2!=0
	//	msg = "홀수";
	//}
	//else {
	//	msg = "짝수";
	//}

	msg = (num % 2) ? "홀수" : "짝수";
	printf("%d 는 %s 입니다\n", num, msg);

	return 0;
}
#endif // 0

//배수 판단 - skip (2부터 내려오면 됌)
#if 0
int main(void) {
	int num = 0;
	int res;

	if (num % 2) {
		res = 2;
	}
	else if (num % 3) {
		res = 3;
	}
	else if (num % 5) {
		res = 5;
	}
	else
		res = 0;

}
#endif // 1

//if-else if - else 문
#if 0
int main(void) {
	int score = 100;
	char* msg = "";

	if (score >= 70) {
		msg = "합격";
	}
	else if (score > 59) {
		msg = "재시험";
	}
	else {
		msg = "불합격";
	}

	//if (score >= 70) {				//위 if ~ else if ~ else 문과 어셈블리는 똑같은데, 가독성이 구림
	//	msg = "합격";
	//}
	//else
	//{
	//	if (score > 59) {
	//		msg = "재시험";
	//	}
	//	else
	//		msg = "불합격";
	//	
	//}


	printf("결과 : %s\n", msg);
	return 0;
}
#endif // 1	

//switch-case 문
//가능하면 배열을 활용할 수 있는 방안을 모색해 볼 것
//case 내부에 break 사용을 안하는 방법으로 명령의 실행 조정시에는 강점
#if 0
int main(void) {
	int a = 10;
	char* msg = "";

	switch (a) 
	{
	default:
		msg = "F";
		break;
	case 1:
		msg = "A";
	case 2:
		msg = "B";
		break;
	case 3:
		msg = "C";
	case 4:
		msg = "D";
		break;
	}
	printf("%s\n", msg);
	return 0;
}
#endif // 0

//1. if문
#if 0
int main(void) {
	int score = 0;
	char* msg = "";

	scanf("%d", &score);

	if (score >= 90)
		msg = "A";
	else if (score >= 80)
		msg = "B";
	else if (score >= 70)
		msg = "C";
	else if (score >= 60)
		msg = "D";
	else
		msg = "F";

	printf("학점 : %s\n", msg);
	return 0;
}
#endif // 1

//2. 조건 연산자
#if 0
int main(void) {
	int score = 0;
	char* msg = "";

	scanf("%d", &score);
	
	msg = (score >= 90) ? "A" : 
		(score >= 80) ? "B" : 
		(score >= 70) ? "C":
		(score >= 60) ? "D" : "F";

	printf("학점 : %s\n", msg);
	return 0;
}
#endif // 1

//3. 배열
#if 0
int main(void) {
	int score = 0;
	char msg[11] = {'F','F','F','F','F','F','D','C','B','A','A'};
	scanf("%d", &score);
	
	msg[0] = msg[score / 10];

	printf("학점 : %c\n", msg[0]);
	return 0;
}
#endif // 1

//패스워드 판정 프로그램 (while / dowhile 사용해보기)
#if 0
#define TEST 2 //1 = while , 2 = do-while

int main(void) {
	int num = 1234;
	int pw = NULL; 

#if TEST == 1
	printf("while문\n");
	scanf("%d", &pw);
	while (pw != num) {
		printf("다시 입력하세요 :");
		scanf("%d", &pw);
	}
#endif

#if TEST == 2
	printf("do-while문\n");
	do {				//do-while 속에 제어문을 넣는건 bad
		if(pw!=NULL)
			printf("다시 입력하세요 :");		
		scanf("%d", &pw);
	} while (pw != num);
#endif

	printf("로그인 되셨습니다.");
}
#endif // 1

//조건에 함수호출이나 scanf 같은걸 넣을 수 있는가?
#if 0
int main(void)
{
	int num = 78;

	(num % 2) ? printf("홀수") : printf("짝수");

	return 0;
}
#endif // 1

//패스워드 while 조건식에 넣어서 한 그 머리아픈 식. (scanf 버퍼 초기화 관련)
#if 0

int main(void) {
	int num = 1234;
	int pw = 0xFFFFAAAA;

	while (((scanf("%d", &pw) == 1) && (pw != num))) {	//scanf의 버퍼를 초기화해야한다. 이건 몰랐네
		printf("다시 :");
		pw = 0;
	}
	printf("pw = %d\n", pw);

	printf("로그인 되셨습니다.");
}
#endif // 1

//1~100 까지중 홀수의 합
#if 0
int main(void) {
	int num=0;

	for (int i = 1; i < 101; i+=2) {	//홀수 = 2씩 증가하면 된다
		num += i;
	}
	printf("num : %d\n", num);

	return 0;
}
#endif // 1

//void 함수 -> 리턴 가능, 리턴값 불가능
#if 0
void func(int a, int b) {
	return;
}
int func2(int a, int b) {
}

int main(void) {

	printf("%d\n",func2(10, 20)); //초기화 되지 않은 쓰레기값 같은데
	return 0;
}
#endif // 1

//배열의 이름 +1 : 2번째 요소의 주소
#if 0
int main(void) {
	int arr[5] = { 1,2,3,4,5 };

	printf("%p %p %p\n", arr, arr + 1, arr - 1);	//배열의 이름 +1 : 다음 주소
	printf("%p %d\n", &arr+1, sizeof(arr));		//&arr+1 : 배열 전체의 크기만큼 다음 배열 주소 //sizeof(arr)배열의 크기
	printf("%d %d\n", *arr, *(arr + 3));	//*arr : arr을 참조

	for (int i = 0; i < 5; ++i) {
		scanf("%d", arr+i);			//주소를 넣어야 한다. &arr[i] = arr+i
	}
	for (int i = 0; i < 5; ++i) {
		printf("%d ", *(arr+i));	//값을 불러오고 싶다. arr[i] = *(arr+i)
	}
	printf("\n");
	return 0;
}
#endif // 1

//.txt로 입력 받아서, 배열에 저장하고, 합계 구하기
#if 0
#define SIZE(a) (sizeof(a)/sizeof(a[0]))
int main(void) {
	int score[5];
	int total = 0;
	int average = 0;

	freopen("score.txt", "r",stdin);		//stdin : 키보드 입력
	for (int i = 0; i < SIZE(score); ++i) {
		scanf("%d", score + i);
		total += score[i];
	}
	printf("total : %d\n", total);
	printf("average : %d\n", total/SIZE(score));

	return 0;
}
#endif // 1
