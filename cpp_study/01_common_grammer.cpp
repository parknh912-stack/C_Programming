#if 1
#include <iostream>
#define choice 3

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

	int i;
	int* pi = &i;

	return 0;
}
#endif

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

#if choice == 3
int main()
{
	int lincky_number = 3;
	std::cout << "내 비밀 수를 맞춰보세요-" << std::endl;

	int user_input; // 사용자 입구

}
#endif // choice == 3


#endif // 1
