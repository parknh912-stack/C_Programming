#if 0
#include <stdio.h>
//extern으로 외부의 함수도 가져올 수 있다.
//함수는 기본적으로 extern 상태이기 때문에 앞에 extern을 붙이면, 명시적 표현
extern int GetNum();
extern void Increment();

int main() {
	printf("num : %d\n", GetNum());
	Increment();
	printf("num : %d\n", GetNum());
	Increment();
	printf("num : %d\n", GetNum());
	return 0;
}
#endif