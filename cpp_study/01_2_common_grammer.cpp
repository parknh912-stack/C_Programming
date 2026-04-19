#if 0
#define choice 4
#include <iostream>


// --- 변수 선언 방식도 동일하다.
#if choice == 1
int main() {
	int i;
	char c;
	double d;
	float f;

	int number_of_people;
	int NumberOfPeople;

	int arr[10];
	int* parr = arr;

	int* pi = &i;

	return 0;
}
#endif

// --- 반복문의 형식은 C언어와 동일하다
#if choice == 2
int main() {
	int i, sum = 0;
	for (i = 0; i <= 10; ++i)
	{
		sum += i;
	}
	std::cout << "합계는 = " << sum << std::endl;
	return 0;
}
#endif // choice == 2


// --- 입력은 std::cin >> 으로 받는다. 이 때 주소연산자는 필요없다.
#if choice == 3
int main()
{
	int lucky_number = 3;
	std::cout << "내 비밀 수를 맞춰보세요-" << std::endl;

	int user_input; // 사용자 입구

	while (1) {
		std::cout << "입력 :";
		std::cin >> user_input; //입력 받을 떄는 cin을 사용 + >> 으로 해야함. & 필요 없음
		if (lucky_number == user_input) {
			std::cout << "일치함" << std::endl;
			break;
		}
		else {
			std::cout << "다시 생각" << std::endl;
		}
	}
	return 0;
}
#endif // choice == 3


// --- switch 도 동일함
#if choice == 4

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int user_input;
	cout << "저의 정보를 표시해줍니다" << endl;
	cout << "1. 이름" << endl;
	cout << "2. 나이" << endl;
	cout << "3. 성별" << endl;
	cin >> user_input;

	switch (user_input) {
	case 1:
		cout << "Psi !" << endl;
		break;
	case 2:
		cout << "99살 !" << endl;
		break;
	case 3:
		cout << "남자 !" << endl;
		break;
	default:
		cout << "몰?루 !" << endl;
		break;
	}
	return 0;
}
#endif // choice == 4


#endif // 1
