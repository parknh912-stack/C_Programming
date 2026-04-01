#include "___AAA___.h"

#define TEST 0

//형 변환 복습
#if TEST == 1
int sum(int a, int b) {
	return a + b;
}
int main() {
	int func = sum;
	// func을 사용하여 2+3 결과를 출력하려면? 
	// int형 func에 저장된건? 함수의 이름 = 함수의 주소 -> 함수 포인터로 가공해서, 입력?
	int (*p)(int, int) = func;
	printf("%d\n", p(2, 3));
	printf("%d\n", ((int (*)(int, int))func)(2,3));	//형변환func(2,3) 하면 후치가 우선이라 안됌. 괄호 필수
	return 0;
}
#endif

//구조체 학습
#if TEST == 2
struct profile {
	int age;
	double height;
	char* name;
};
void init_profile(struct profile *pf) {
	pf->age = 27;
	pf->height = 177.7;
	pf->name = "박남현";
	//(*pf).age = 99;
	//(pf[0]).height = 180;
}
void print_struct(struct profile pf) {
	printf("%d %.1lf %s\n", pf.age, pf.height, pf.name);
}
int main() {
	struct profile pf = { 30, 150, "홍길동"};
	init_profile(&pf);		//값이 안바뀜 -> 왜? 구조체는 복사해서 넘겨주기 때문이다.
	print_struct(pf);
	return 0;
}
#endif // TEST == 2

//구조체 + 메모리 할당 예제
#if TEST == 3
struct student {
	int id;
	int scores[3];
	char name[20];
};

void input_data1(struct student* stu, int N) {
	for (int i = 0; i < N; ++i) {	/*stu[i]. == (stu+i)->*/
		(void)scanf("%d %d %d %d %s", &(stu+i)->id, &(stu+i)->scores[0], &(stu+i)->scores[1], &(stu+i)->scores[2], (stu+i)->name);
	}
}
void input_data2(struct student* stu, int N) {
	struct student temp = { 0 };
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d %d %d %d %s", &temp.id, &temp.scores[0], &temp.scores[1], &temp.scores[2], temp.name);
		stu[i] = temp;
	}
}
void input_data3(struct student* stu, int N) {
	struct student* temp = stu;
	int* scores;
	for (int i = 0; i < N; ++i, ++temp) {
		scores = temp->scores;
		//(void)scanf("%d %d %d %d %s", &temp->id, &scores[0], &scores[1], &scores[2], temp->name);
		printf("%p %p\n", temp, &temp->id);
		(void)scanf("%d %d %d %d %s", temp, scores, scores + 1, scores + 2, temp->name);

	}
}
void input_data4(struct student* stu, int N) {
	for (struct student* temp = stu; temp < stu + N; ++temp) {
		(void)scanf("%d %d %d %d %s", &temp->id, &temp->scores[0], &temp->scores[1], &temp->scores[2], temp->name);
	}
}
void input_data5(struct student* stu, int N) {
	for (int i = 0; i < N; ++i) {
		int j;
		int* p = stu + i;
		for (j = 0; j < 4; ++j) {
			(void)scanf("%d", p + j);
		}
		(void)scanf("%s", (char*)(p + j));
	}
}

void print_data(struct student* stu, int N) {
	for (int i = 0; i < N; ++i) {
		printf("%d %3d %3d %3d %s\n", stu[i].id, stu[i].scores[0], stu[i].scores[1], stu[i].scores[2], stu[i].name);
	}
}
void print_data2(struct student* stu, int N) {
	for (struct student* temp = stu; temp < stu + N; ++temp) {
		int* scores = temp->scores;
		printf("%d %3d %3d %3d %s\n", temp->id, *scores, *(scores + 1), *(scores + 2), temp->name);
	}
}

int main() {
	struct student* stu = NULL;
	int N;
	(void)freopen("student.txt", "r", stdin);
	(void)scanf("%d", &N);

	stu = (struct student*)calloc(N, sizeof(struct student));
	if (stu == NULL) exit(0);

	input_data1(stu, N);
	print_data2(stu, N);

	free(stu);
	return 0;
}
#endif

//Little Endian 확인
#if TEST == 4
int main() {
	char a = 0x1234;
	printf("%x\n", a);
	return 0;
}
#endif // TEST == 4

//비트필드 구조체
#if TEST == 5
typedef struct _IP {
	uint16_t VERSION : 4;
	uint16_t HL : 4;
	uint16_t TOS : 8;
	uint16_t IP_Flags_x : 1;
	uint16_t IP_Flags_D : 1;
	uint16_t IP_Flags_M : 1;
	uint16_t Fragment_OFFEST : 13;
} IP_HEADER;

struct bit {
	unsigned a : 3;
	unsigned b : 3;
	unsigned c : 3;
	unsigned d : 3;
}x;
int main() {
	IP_HEADER a = { 0x3,0x3,0x78,0x1,0x1,0x0,0x8191 };
	printf("%X %X %X %X %X %X %X\n", a.VERSION, a.HL, a.TOS, a.IP_Flags_x, a.IP_Flags_D, a.IP_Flags_M, a.Fragment_OFFEST);

	x.a = 2;		//010
	x.b = 1;		//001
	x.c = 1;		//001
	//a부터 이니까, 010 001 001 인데, little endian이라서
	//001 001 010 인데 8개씩이니까, 가장 왼쪽은 다음 비트로
	// 01 001 010 | 0 -> 0100 1010 | 0 -->>>>>>> 4 a | 0
	//printf("%x\n", x.a);
	printf("%X\n", *(char*)&x);		//4a

	x.a = 2;		//010
	x.b = 1;		//001
	x.c = 3;		//011
	//11001010 | 0 -> CA
	printf("%X\n", *(char*)&x);		//FFFFFFCA -> 부호비트가 있는 char 라서 11001010 -> 음수나 마찬가지니까, signed char 확장시 F로 채워짐.
	printf("%X\n", *(unsigned char*)&x);		//CA

	x.a = 3;		//010
	x.b = 1;		//001
	x.c = 3;		//011
	x.d = 5;		//101
	//11001010 | 1010 -> CA | A
	unsigned char* p = &x;
	printf("%X %X %X\n", *p, *(p + 1), *((unsigned char*)&x + 1));		//CA | A

	return 0;
}
#endif 

//비트필드 구조체, 1bit씩 넣어보기
#if TEST == 6
struct IP {
	unsigned char Flag_a : 1;
	unsigned char Flag_b : 1;
	unsigned char Flag_c : 1;
	unsigned char Flag_d : 1;
	unsigned char Flag_e : 1;
	unsigned char Flag_f : 1;
	unsigned char Flag_g : 1;
	unsigned char Flag_h : 1;
};
union Data {
	unsigned char ALL;
	struct IP Part;
};

int main() {
	struct IP A;		//A 에 1010 1010 -> little endian 식이면, 0101 0101
	unsigned char* p = (unsigned char*)&A;
	*p = 0b01010101;	
	printf("%X\n", *p);
	//*(unsigned char*)&A = 0b01010101;

	union Data B;
	B.ALL = 0x55;
	printf("%X\n", B.ALL);

}	

#endif

//Union
#if TEST == 7
union student {
	int a;
	char b;
	short c;
};
int main() {
	union student stu = { 0x12345678 };
	printf("%X %X %X\n", stu.a, stu.b, stu.c);
	return 0;
}
#endif

#if TEST == 8
typedef struct trgb {
	unsigned short blue : 5;
	unsigned short green : 6;
	unsigned short red : 5;
}tRGB;

typedef union pixelcolor {
	tRGB rgb;
	unsigned short color;
}tColor;

int main() {
	
}
#endif