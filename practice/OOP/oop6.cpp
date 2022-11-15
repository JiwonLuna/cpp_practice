// 생성자 오버로딩

#include <iostream>

class Date {
	int year_;
	int month_;
	int day_;
	
	public:
	void ShowDate();
	
	Date() {
		std::cout << "기본 생성자 호출!" << std::endl;
		year_ = 2022;
		month_ = 11;
		day_ = 15;
	}
	
	Date(int year, int month, int day) {
		std::cout << "인자 3 개인 생성자 호출!" << std::endl;
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

void Date::ShowDate() {
	std::cout << "오늘은 " << year_ << "년 " << month_ << "월 " << day_
		<< "일 입니다." << std::endl;
}

int main() {
	Date day = Date();
	Date day2(2012, 10, 31);
	// 적절히 오버로딩이 되어서 사용자가 원하는 생성자를 호출할 수 있게 됨.
		
	day.ShowDate();
	day2.ShowDate();
	
	return 0;
}

