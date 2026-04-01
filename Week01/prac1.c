#if 0
#ifndef ___AAA___
#define ___AAA___

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif
#endif // 0


#if 0
int main(void) {
	double a = 4.0, b = 1.2;

	printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
	printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
	printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
	printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);

}
#endif // 1

//연산자 활용 기초 1
#if 0
int main(void) {
	int a, b, tot;
	double avg;
	printf("두 과목의 점수 : ");
	scanf("%d%d", &a, &b);
	tot = a + b;
	avg = tot / 2.0;

	printf("평균 : %.1lf", avg);

	return 0;
}
#endif // 1

//연산자 활용 기초 1
#if 0
int main(void) {
	int kor = 3, eng = 5, mat = 4;
	int credits;
	int res;

	double kscore = 3.8, escore = 4.4, mscore = 3.9;
	double grade;

	credits = kor + eng + mat;
	grade = (kscore + escore + mscore) / 3.0;
	res = (credits > 10) && (grade > 4.0);
	printf("%d\n", res);

	return 0;
}
#endif // 1

//p148 도전 실전 예제
#if 0
int main(void) {
	double weight, height;
	double bmi = 0;

	printf("몸무게(kg)와 키(cm) 입력 : ");
	scanf("%lf%lf", &weight, &height);

	height /= 100.0;
	bmi = weight / (height * height);
	printf("bmi : %.1lf\n", bmi);
	(bmi >= 20.0) && (bmi < 25.0) ?
		printf("표준") :
		printf("체중관리 ㄱㄱ");
	//(bmi > 25.0) ? printf("과체중\n") : (bmi >= 20.0) ? printf("표준\n") : printf("저체중\n");
}
#endif // 1

//02-4i 반복문 연습문제 1 - 양수 덧셈 프로그램 (이런건 while 쓸것)
#if 0
int main(void)
{
	int total = 0;
	int num = 0xFFFF;
	//for (int num = 0xFFFF; num>0; )
	//{
	//	scanf("%d", &num);
	//	total += num;
	//}
	while (num > 0) {
		scanf("%d", &num);
		total += num;
	}
	printf("total : %d\n", total);
}
#endif 

//02-4i 반복문 연습문제 2 - 암호 확인 프로그램
#if 0
int main(void) {
	int collet_pw = 1357;
	int pw;
	for (int i = 0; i < 3; i++) {
		printf("암호 입력 : ");
		scanf("%d", &pw);
		if (pw == collet_pw) {
			printf("로그인 성공");
			return 0;
		}
	}
	printf("관리자에게 문의하세요");
	return 0;
}
#endif // 1

//02-4j 반복문 연습문제 3 - 자릿수 구하기 프로그램
//1~10,000,000 사이의 임의의 정수를 받아서 자릿수 출력, while문 사용
#if 0
int main(void) {
	int num = 0xFFFF;
	int count = 0;
	if (scanf("%d", &num) != 1)
		return 1;

	while (num >0) {
		num /= 10;
		count++;
	}
	printf("자리수 : %d\n", count);
	return 0;
}
#endif // 1

//04-8 strcpy 연습
#if 0
int main(void) {
	char str1[80] = "cat";
	char str2[80];

	strcpy(str1, "tiger");
	strcpy(str2, str1);
	printf("%s, %s\n", str1, str2);

	char str[80];

	printf("문자열 입력 : ");
	gets(str);
	puts("입력된 문자열 : ");
	puts(str);
}
#endif // 1

//swap 함수 (포인터 활용)
#if 0
void swap(int* pa, int* pb);
int main(void) {
	int a = 10, b = 20;

	swap(&a, &b);
	printf("a: %d, b: %d\n", a, b);

	return 0;
}
void swap(int* pa, int* pb) {
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
#endif // 1
