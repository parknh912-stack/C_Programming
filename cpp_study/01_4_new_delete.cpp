#if 0
#define choice_4 4
#include <iostream>

/* new 와 delete 의 사용 */
#if choice_4 == 1
int main() {
	int* p = new int;
	*p = 10;
	std::cout << *p << std::endl;
	delete p;
	return 0;
}
#endif // choice_4 == 1

/* new 로 배열 할당하기 */
#if choice_4 == 2
int main() {
	int arr_size;
	std::cout << "array size : ";
	std::cin >> arr_size;
	int* list = new int[arr_size];
	for (int i = 0; i < arr_size; i++) {
		std::cin >> list[i];
	}
	for (int i = 0; i < arr_size; i++) {
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}
	delete[] list;
	return 0;
}
#endif // choice_4 == 2

// --- 변수의 동작 범위 : 가까운거
#if choice_4 == 3
int main()
{
	int a = 4;
	{
		std::cout << "외부의 변수 1 :" << a << std::endl;
		int a = 3;
		std::cout << "내부의 변수 " << a << std::endl;
	}
	std::cout << "외부의 변수 2 : " << a << std::endl;
}
#endif // choice_4 == 3

// 예제 : 마이펫 만들기
// 구조체로만 구현 -> 객체지향의 소중함 깨닫기
#if choice_4 == 4
typedef struct _animal {
	char name[30];
	int age;
	int health;
	int food;
	int clean;
} ANIMAL;

void create_animal(ANIMAL* animal)
{
	std::cout << "동물의 이름 : ";
	std::cin >> animal->name;

	std::cout << "동물의 나이 : ";
	std::cin >> animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(ANIMAL* animal)
{
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void show_stat(ANIMAL* animal)
{
	std::cout << "이름 : " << animal->name << std::endl;
	std::cout << "나이 : " << animal->age << std::endl;
	std::cout << "체력 : " << animal->health << std::endl;
	std::cout << "배부름 : " << animal->food << std::endl;
	std::cout << "청결도 : " << animal->clean << std::endl;
}

void one_day_pass(ANIMAL* animal)
{
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}
int main() {
	ANIMAL* list[30];
	int animal_num = 0;

	while (1)
	{
		std::cout << "1. 동물 추가하기" << std::endl;
		std::cout << "2. 놀기 " << std::endl;
		std::cout << "3. 상태 보기 " << std::endl;

		int input;
		std::cin >> input;

		switch (input) {
			int play_with;
		case 1:
			list[animal_num] = new ANIMAL;
			create_animal(list[animal_num]);
			animal_num++;
			break;
		case 2:
			std::cout << "누구랑 놀게?" << std::endl;
			std::cin >> play_with;

			if (play_with < animal_num) play(list[play_with]);
			break;
		case 3:
			std::cout << "누구껄 보게?" << std::endl;
			std::cin >> play_with;

			if (play_with < animal_num) show_stat(list[play_with]);
			break;
		}
		for (int i = 0; i != animal_num; ++i)
		{
			one_day_pass(list[i]);
		}
	}
	for (int i = 0; i != animal_num; ++i)
	{
		delete list[i];
	}
}
#endif // choice_4 == 4


#endif // 1


