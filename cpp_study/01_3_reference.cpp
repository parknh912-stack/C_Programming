#if 0
#define choice_3 5
#include <iostream>

// --- 포인터 사용 = 동일
#if choice_3 == 1
int change_val(int* p)
{
	*p = 3;
	return 0;
}

int main() {
	int number = 5;
	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
}

#endif 

// --- 또 다른 방식, 참조자 (레퍼런스 (reference))
#if choice_3 == 2
int main()
{
	int a = 3;
	int b = 10;
	int& another_a = a; // 메모리에 존재할 필요가 없는 경우.
	// 참조자는 앞에 &를 붙인다. 
	// 참조자라는건, a의 또다른 이름을 정의해주는 것.
	// ** 반드시, 누구의 별명인지 명시해야함. **
	// ** 참조자의 참조자를 만드는건 금지 **
	// 왜 참조자를 사용하는가? 포인터가 있는데?
		// 왜냐하면, 불필요한 & 와 * 이 필요없음. 선언시에만 사용

	another_a = 5; // 가능
	another_a = b; // a=b와 동치임
	// &another_a = b; // 불가능

	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;

	return 0;
}
#endif 


// --- 함수 인자로 레퍼런스 받기
#if choice_3 == 3
int change_val(int& p) // int& p = number;
{
	p = 3;

	return 0;
}

int main()
{
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);
	std::cout << number << std::endl;

	return 0;
}
#endif // choice_3 == 3

#if choice_3 == 4
int main()
{
	int a, b;
	//int& arr[2] = { a, b }; // 불가능
	int arr[3] = { 1, 2, 3 };
	int(&ref)[3] = arr; // 배열의 크기 명시해야함
	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;
	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return 0;
}
#endif // choice_3 == 4

// 레퍼런스를 리턴하는 함수
#if choice_3 == 5
int& function(int& a) {
	a = 5;
	return a;
}
int main() {
	int b = 2;
	int c = function(b);
	return 0;
}
#endif // choice_3 == 5


#endif // 1
