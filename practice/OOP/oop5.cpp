// 디폴트 생성자 (Default Constructor)

/* 맨 처음에 단순히 SetDate 함수 이용해서 객체를 초기화 했을 때
생성자 명시하지 않음.
Date day;
로 했을 때도 생성자가 호출되었음. 정의하지도 않았는데 호출된 생성자
-> "디폴트 생성자"(Default Constructor)

디폴트 생성자 : 인자를 하나도 가지지 않는 생성자, 클래스에서 사용자가 어떠한
생성자도 명시적으로 정의하지 않았을 경우에 컴파일러가 자동으로 추가해주는 생성자.
*/

// 디폴트 생성자 정의해보기

#include <iostream>

class Date {
	int year_;
	int month_;
	int day_;
	
	public:
	void ShowDate();
	
	Date() {
		year_ = 2012;
		month_ = 7;
		day_ = 12;
	}	// 디폴트 생성자 Date() 정의
};

void Date::ShowDate() {
	std::cout << "오늘은 " << year_ << "년 " << month_ << "월 " << day_
		<< "일 입니다." << std::endl;
}

int main() {
	Date day = Date();
	Date day2;
	
	day.ShowDate();
	day2.ShowDate();
	
	return 0;
}


