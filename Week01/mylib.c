#if 0
#include "mylib.h"

//구조체 연습
struct _stARY {
	char* msg;
	int (*func)(int*, int);	//함수 포인터 
};

struct _stARY stARY[] = {
	{"종료", 0},
	{"데이터 읽기" ,scanf_ary},
	{"데이터 출력", print_ary},
	{"최대값", findmax_ary},
	{"최소값", findmin_ary},
	{"합계", sum_ary},
	{"평균", avg_ary},
	{"오름차순 정렬", sort_ary},
	{"내림차순 정렬", sort_ary_decrease}
};

int scanf_ary(int* pa, int n) {
	printf("정수 5개 입력 : ");
	for (int i = 0; i < n; ++i) {
		(void)scanf("%d", &pa[i]);
	}
	return n;
}
int print_ary(int* pa, int n) {
	int temp = 0;
	for (int i = 0; i < n; ++i) {
		temp += printf("%d ", *(pa + i));
	}
	printf("\n\n");
	return temp;
}
int findmax_ary(int* pa, int n) {
	int max = pa[0];
	for (int i = 1; i < n; ++i) {	//어짜피 0번 들어갔으니 0은 빼자
		if (pa[i] > max) {
			max = pa[i];
		}
	}
	return max;
}
int findmin_ary(int* pa, int n) {
	int min = pa[0];
	for (int i = 1; i < n; ++i) {
		if (pa[i] < min) {
			min = pa[i];
		}
	}
	return min;
}
int sum_ary(int* pa, int n) {
	int res = *pa;	//여기도 0을 넣지말고 *pa로 초기화 한뒤 더해도 될듯
	for (int i = 1; i < n; ++i) {
		res += *(pa + i);
	}
	return res;
}
//평균을 반올림해서 정수로 반환
int avg_ary(int* pa, int n) {
	int sum = sum_ary(pa, n);
	int avg = (int)((double)sum / n);
	return avg;
}
//정렬한 인수 개수 반환
int sort_ary(int* pa, int n) {
	int temp;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {	// 개선점 : n-1도 연산인데 줄여도 상관없지 않나?
		for (int j = i + 1; j < n; ++j) {	// 개선점 : j=i+1 역시 줄여도 괜찮나?
			if (pa[i] > pa[j]) {
				temp = pa[i];
				pa[i] = pa[j];
				pa[j] = temp;
				cnt++;
			}
		}
	}
	print_ary(pa, n);
	return cnt;
}

int sort_ary_decrease(int* pa, int n) {
	int temp;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {	// 개선점 : n-1도 연산인데 줄여도 상관없지 않나?
		for (int j = i + 1; j < n; ++j) {	// 개선점 : j=i+1 역시 줄여도 괜찮나?
			if (pa[i] < pa[j]) {
				temp = pa[i];
				pa[i] = pa[j];
				pa[j] = temp;
				cnt++;
			}
		}
	}
	print_ary(pa, n);
	return cnt;
}

/********************************************************/
int choice_menu() {
	int index;
	printf("메뉴\n");
	printf("1 - 입력\n"
		"2 - 출력\n" //1. 여러번 호출하는 것보다, 하나만 하는게 낫다 (성능)
		"3 - 최댓값\n"
		"4 - 최소값\n"			//2. 가독성이 높아진다, 이식성이 좋다.
		"5 - 합계\n"
		"6 - 평균\n"
		"7 - 정렬 (오름차순)\n"
		"0 - 종료\n");
	printf("번호를 입력하세요 : ");
	(void)scanf("%d", &index);
	printf("\n");
	return index;
}

/* 구조체 연습용 */
int choice_menu2(void) {
	int c;
	for (int i = 0; i < SIZE(stARY); ++i) {
		printf("%d. %s\n", i, stARY[i].msg);
	}
	printf("번호를 입력하세요 : ");
	(void)scanf("%d", &c);

	return c;
}
/* 사실상 메인 컨트롤 함수이긴함 이게 */
void ary_control(int index, int* pa, int n) {
	//1. switch case
#if 0
	char* msg[eMENU_MAX] = { 0,0,0,"최대","최소","합계","평균" };
	int result = 0;
	switch (index) {	//이것도 따로 빼서 함수화 하면 좋을듯
	case eMENU_INPUT:
		scanf_ary(pa, n); break;
	case eMENU_OUTPUT:
		print_ary(pa, n); break;
	case eMENU_FIND_MAX:
		result = findmax_ary(pa, n); break;
	case eMENU_FIND_MIN:
		result = findmin_ary(pa, n); break;
	case eMENU_SUM:
		result = sum_ary(pa, n); break;
	case eMENU_AVG:
		result = avg_ary(pa, n); break;
	case eMENU_SORT_ASC:
		sort_ary(pa, n); break;
	case eMENU_SORT_DSC:
		sort_ary_decrease(pa, n); break;
	default:
		printf("없는 번호입니다.\n");
	}
	if ((index >= eMENU_FIND_MAX) && (index < eMENU_SORT_DSC)) {
		printf("%s : %d\n", msg[index], result);
	}
#endif
	//2. 함수포인터 배열
#if 0
	int result = 0;
	char* msg[eMENU_MAX] = { 0,0,0,"최대","최소","합계","평균" };

	int (*cmd[8])(int*, int) = { 0, scanf_ary, print_ary, findmax_ary, findmin_ary, sum_ary, avg_ary, sort_ary };
	result = cmd[index](pa, n);	//어셈블리 상으로 인덱스 연산한번 하는게 배열을 메모리에 쓰는 것보다 나은것 같다. 특히 더 커지면

	if ((index >= eMENU_FIND_MAX) && (index < eMENU_SORT_DSC)) {
		printf("%s : %d\n", msg[index], result);
	}
#endif
	//3. 구조체
#if 1
	int result = 0;
	result = stARY[index].func(pa, n);
	if ((index >= eMENU_FIND_MAX) && (index < eMENU_SORT_DSC)) {
		printf("%s : %d\n", stARY[index].msg, result);
	}
#endif // 1
}

//for TEST 12 (08-5)
//
void my_gets(char* ary, int n) {
	int i;
	for (i = 0; i < n - 1; ++i) {
		ary[i] = getchar();
		if (ary[i] == '\n') {
			/*ary[i] = '\0';*/		//개선점 : 같은게 밖에 있으니까, 굳이 안에 이건 필요엾다.
			break;
		}
	}
	ary[i] = '\0';
}

char* to_upper(char* ary) {
	int i = 0;
	while (ary[i] != '\0') {
		if ((ary[i] >= 'a') && (ary[i] <= 'z')) {
			ary[i] += ('A' - 'a');		//참조가 많이 들어감 -> 어셈블리어 기준으로 많이 연산
		}
		++i;
	}
	return ary;

}

// i 없이 포인터로만 증감시키는 것 by 김진수님.
char* to_upper2(char* buf)
{
	char* _buf = buf;
	char ch = 0;
	while ((ch = *_buf) != 0) {
		if (ch >= 'a' && ch <= 'z') {		//위 배열과는 다르게, 문자 변수라서 해당 주소에서 이동하여 바로 읽음.
			ch -= ('A' - 'a');
			*_buf = ch;
		}
		_buf++;
	}
	return buf;
}


#endif // 0
