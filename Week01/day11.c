#include "___AAA___.h"

#define TEST 0


// 화살표를 입력받는 프로그램
// 장점 : 메모리 사용이 가장 작음, 연산도 적절함
// 확장성이 부족함.
#if TEST == 1
#include <conio.h>	//_getch()를 위한 함수
int main(void) {
	char* msg[4] = { "DOWN", "LEFT", "UP" , "RIGHT" };
	int c;
	while(_getch() == 224){
		c = _getch();
		printf("%s\n", *(msg + (c%10)%4));
	}
	//c에 들어올 수 있는 값 : 72_up, 80_down, 75_left, 77_right   |  244

	return 0;
}
#endif
// 메모리 9개 쓰는 방식, 뺄셈 1번 (-72)
#if TEST == 2
int main() {
    char* msg[9] = { "UP", 0, 0, "LEFT", 0, "RIGHT", 0, 0, "DOWN" };
    int c;

    if (_getch() == 224) {
        c = _getch();
        printf("%s\n", msg[c - 72]);
    }
    return 0;
}
#endif
// 메모리 낭비는 심함 : (char * ) 70개 이상 = 4byte * 256 = 1024byte
// 그러나 연산은 없음, 바로 배열참조
// 확장성 : 다른 키도 추가 가능
#if TEST == 3

int main() {

    char* msg[256] = { 0 };

    msg[72] = "Up";
    msg[75] = "Left";
    msg[77] = "Right";
    msg[80] = "Down";

    int c;

    if (_getch() == 224) {
        c = _getch();
        printf("%s\n", msg[c]);
    }

    return 0;
}
#endif
// 메모리는 4개만 씀 : (char *) 4개 = 4byte * 4 = 16byte
// map은 256개 씀   : (char ) 256개 = 256byte
// 확장성 : 다른 키도 추가 가능
// 배열 참조 연산 1회
#if TEST == 4
int main(void) {
    char* msg[4] = { "Down","Left","Up","Right" };
    unsigned char map[256] = {
        [80] = 0,
        [75] = 1,
        [72] = 2,
        [77] = 3
    };
    int c;
    if (_getch() == 224) {
        c = _getch();
        printf("%s\n", msg[map[c]]);
    }
    return 0;
}
#endif
// 강사님 버젼 (TEST 4 와 동일한데, enum으로 가독성 향상)
// 메모리는 4개만 씀 : (char *) 4개 = 4byte * 4 = 16byte
// map은 256개 씀   : (char ) 256개 = 256byte
// 확장성 : 다른 키도 추가 가능
// 배열 참조 연산 1회
#if TEST == 5
#include <stdio.h>
#include <conio.h>

enum Direction {
    DIR_DOWN,
    DIR_LEFT,
    DIR_UP,
    DIR_RIGHT
};

int main() {

    const char* msg[] = {
        "Down",
        "Left",
        "Up",
        "Right"
    };

    unsigned char map[256] = {
        [80] = DIR_DOWN,
        [75] = DIR_LEFT,
        [72] = DIR_UP,
        [77] = DIR_RIGHT
    };

    int c;

    if (_getch() == 224) {
        c = _getch();
        enum Direction dir = map[c];
        printf("%s\n", msg[dir]);
    }

    return 0;
}
#endif
//형 재정의 에 대한 내용
#if TEST == 6
typedef char C_ARR_10 [10];
typedef C_ARR_10* C_ARR_10_P;
typedef int(*FP)(C_ARR_10_P, int);

int printAry(C_ARR_10_P ary, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%s ", ary[i]);
    }
    printf("\n");
}
int main() {
    C_ARR_10 fruit[] = {"apple","melon","cherry"}; //char fruit[][10] -> char* fruit [10]
    FP fn = printAry;                            // int (*fn)(char (*ary)[10], int size) -> FP fn
    fn(fruit, sizeof(fruit) / sizeof(fruit[0]));
    return 0;
}
#endif
#if TEST == 7

int func(int a, int b) {
    return a + b;
}
typedef int(*FP)(int, int);
int main(void) {
    int a = (int)func;
    printf("%d\n", fucn(3, 4));
    printf("%d\n", ((FP)a)(3, 4));
}
#endif
//#error 연습
#if TEST == 8
#include <stdio.h>

#define SOUND_DEVICE_TYPE 1

int main(void) {

#if !SOUND_DEVICE_TYPE
    printf("사운드 장치를 사용하지 않음\n");
#else
#error CODE 10 : Unknown Device!
#endif

    printf("사운드 모드 = %d\n", SOUND_DEVICE_TYPE);

    return 0;
}
#endif

//#line 연습
#if TEST == 9
#include <stdio.h>
/*  \ : enter 무시하는 키임*/
#define Assert(x) { \
    if ((x) >= 4) printf("Range error : %s, %d\n", __FILE__, __LINE__); \
}

int main(void) {
    int a[4] = { 10, 20, 30, 40 };
    int i;

    for (i = 0; i <= 4; ++i) {
#line 100
        Assert(i);
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
#endif

#if TEST == 10
#include <stdio.h>
#define NDEBUG
#include <assert.h>

int main(void) {
    int x;

    printf("\nEnter an integer value: ");
    (void)scanf("%d", &x);

    assert(x >= 0); 

    printf("You entered %d.", x);

    return 0;
}
#endif

#if TEST == 11
typedef int(*F4)[4];
int main() {
    int score[3][4] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
    int x;
    F4 sp;
    F4 sa[5];
    F4* sd;

    sd = (F4*)malloc(sizeof(F4) * 5);
    x = (int)score; //대입되도록 수정하시오
    sp = (F4)x;//대입되도록 수정하시오

    printf("%d ", ((int(*)[4])x)[0][0] + 1);    //x를 사용해 12출력
    printf("%d ", ((int(*)[4])x)[1][1]);    //x를 사용해 6출력
    printf("%d\n", sp[2][2]);   //sp 사용해 1출력
}
#endif