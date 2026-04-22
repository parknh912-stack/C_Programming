#if 1
#define choice_2_1 ( 5 )
#include <iostream>

// 객체와 클래스 만들어보기
#if choice_2_1 == 1
class Animal {
private:
	int food;
	int weight;

public:
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}
	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}
	void view_stat() {
		std::cout << "이 동물의 food : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
	}
};

int main()
{
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}
#endif // choice_2_1 == 1

// 생각해볼 문제 1
#if choice_2_1 == 2
/*
2012년 2월 28일에 3일 더하면, 2012 3월 2일
*/
class Date {
private:
	int year_;
	int month_; // 1 부터 12 까지.
	int day_; // 1 부터 31 까지.
public:
	void SetDate(int year, int month, int date)
	{
		year_ = year;
		month_ = month;
		day_ = date;
	}
	void AddDay(int inc)
	{
		//홀수달 : 31, 짝수달 : 30, 2월 : 28
		day_ += inc;
		if (month_ % 2) {
			month_ += (day_ / 31);
			day_ %= 31;
		}
		else
		{
			if (month_ == 2)
			{
				month_ += (day_ / 28);
				day_ %= 28;
			}
			else
			{
				month_ += (day_ / 30);
				day_ %= 30;
			}
		}
	}
	void AddMonth(int inc)
	{
		month_ += inc;
		year_ += (month_ / 12);
		month_ %= 12;
	}
	void AddYear(int inc)
	{
		year_ += inc;
	}
	void ShowDate() {
		std::cout << year_ << "-" << month_ << "-" << day_ << std::endl;
	}
};

int main()
{
	Date day;
	day.SetDate(2011, 3, 1);
	day.ShowDate();

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31); // 윤년
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();
	return 0;
}
#endif // choice_2_1 == 2

//함수의 오버로딩
#if choice_2_1 == 3
/* 함수의 오버로딩 */

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }
int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;
	print(a);
	print(b);
	print(c);
	return 0;
}
#endif // choice_2_1 == 3

#if choice_2_1 == 4

class Date {
	int year_;
	int month_; // 1 부터 12 까지.
	int day_; // 1 부터 31 까지.
public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);
	// 해당 월의 총 일 수를 구한다.
	int GetCurrentMonthTotalDays(int year, int month);
	void ShowDate();
};

void Date::SetDate(int year, int month, int day) {
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
	static int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month != 2) {
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return 29; // 윤년
	}
	else {
		return 28;
	}
}

void Date::AddDay(int inc) {
	while (true) {
		// 현재 달의 총 일 수
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);
		// 같은 달 안에 들어온다면;
		if (day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		}
		else {
			// 다음달로 넘어가야 한다.
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc) {
	AddYear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }
void Date::ShowDate() {
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
		<< " 일 입니다 " << std::endl;
}

int main()
{
	Date day;
	day.SetDate(2011, 3, 1);
	day.ShowDate();

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31); // 윤년
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();
	return 0;
}
#endif // choice_2_1 == 4

// p83 생각해보기 - 문제 2
/*
수학 관련 소프트웨어를 만드는 회사에서 의뢰가 들어왔습니다. 중학생용 기하학 소프트웨워를
만드는 것인데요, 클래스는 총 두 개로 하나는 Point 로 점에 관한 정보를 담는 것이고 다른 하나는
Geometry 로 점들을 가지고 연산을 하는 클래스 입니다. 즉 아래와 같은 두 클래스의 함수들을
모두 정의하세요 (난이도 : 上)
*/
#if choice_2_1 == 5
#include <cmath>
#include <cstring>

class Point {
	int x, y;
public:
	Point(int pos_x, int pos_y);

	int GetX() const {
		return x;
	}
	int GetY() const {
		return y;
	}
};

Point::Point(int pos_x, int pos_y) {
	x = pos_x;
	y = pos_y;
};

class Geometry {
	// 점 100 개를 보관하는 배열.
	Point* point_array[100];
	int num_points;
public:
	Geometry(Point** point_list);
	Geometry();

	void AddPoint(const Point& point);

	// 모든 점들 간의 거리를 출력하는 함수 입니다.
	void PrintDistance();

	// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
	// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
	// 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
	// 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
	void PrintNumMeets();
};

Geometry::Geometry() {
	memset(point_array, 0, sizeof(point_array));
	num_points = 0;
}

void Geometry::AddPoint(const Point& point) {
	point_array[num_points++] = new Point(point);
}

void Geometry::PrintDistance() {
	for (int i = 0; i < num_points - 1; ++i) {
		for (int j = i + 1; j < num_points; ++j) {
			double dx = point_array[i]->GetX() - point_array[j]->GetX();
			double dy = point_array[i]->GetY() - point_array[j]->GetY();
			double d = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
			std::cout << d << std::endl;
		}
	}
}



#endif // choice_2_1 == 5

#endif