// Date class

#include <iostream>

class Date {
	int year_;
	int month_;	// 1 부터 12 까지.
	int day_;	// 1 부터 31 까지.
	
	public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);
	
	// 해당 월의 총 일수를 구한다.
	int GetCurrentonthTotalDays(int year, int month);
	
	void ShowDate();
};
/* 클래스 내부에 함수의 정의만 나와 있고, 함수 전체 내용은
아래와 같이 클래스 밖에 나와있음. 'Date::' 을 함수 이름 앞에 붙여주게 되면
이 함수가 Date 클래스에 정의된 함수 라는 뜻.

만약
void ShoDate() { // ...}
와 같이 작성했다면 위 함수는 클래스의 멤버 함수가 아니라 그냥 일반적인 함수가 됨.
보통 대부분의 함수들은 클래스 바깥에서 정의함. 클래스 내부에 쓸 경우
클래스 크기가 너무 길어져서 보기 안 좋기 때문.

다만 예외적으로 템플릿 클래스의 경우 모두 클래스 내부에 작성함.
*/

void Date::SetDate(int year, int month, int day) {
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::GetCurrentonthTotalDays(int year, int month) {
	static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month != 2) {
		return month_day[month -1];
	} else if (year % 4 == 0 && year % 100 != 0) {
		return 29;	// 윤년인 2월
	} else {
		return 28;	// 윤년이 아닌 2월
	}
}

void Date::AddDay(int inc) {
	while (true) {
		// 현재 달의 총 일 수
		int current_month_total_days = GetCurrentonthTotalDays(year_, month_);
		
		// 같은 달 안에 들어온다면;
		if (day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		} else {
			// 다음 달로 넘어가야 한다.
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
	std::cout << "오늘은" << year_ << "년 " << month_ << "월 "
		<< day_ << "일 입니다." << std::endl;
}

int main() {
	Date day;	// day 인스턴스 생성
	day.SetDate(2011, 3, 1);
	day.ShowDate();
	/* SetDate 상당히 중요!! 만약 SetDate 하지 않았다면 초기화 되지 않은
	값들에 덧셈과 출력 명령이 내려저서 이상한 쓰레기 값이 출력되기 때문.
	항상 생성 후 초기화를 숙지하고 있을 것!!
	
	다만 C++에서는 이를 언어 차원에서 도와주는 장치가 있음
	"생성자 (constructor)"
	
	위 코드에서
	Date day;
	day.SetDate(2011, 3, 1);
	두 줄은
	Date day(2011, 3, 1);
	한 줄로 변경 가능
	
	생성자는 기본적으로 "객체 생성 시 자동으로 호출되는 함수" 라고 볼 수 있음.
	이 때 자동으로 호출되면서 객체를 초기화 해주는 역할을 담당.
	생성자의 정의:
	// 객체를 초기화 하는 역할을 하기 때문에 리턴값이 없다.
	클래스 이름 (인자) {}
	Date의 생성자 정의 예시:
	Date(int year, int month, int day)
	위와 같이 정의가 된 생성자는 객체를 생성할 때 다음과 같이 위 함수에서 정의한
	인자에 맞게 마치 함수를 호출하듯이 써준다면 위 생성자를 호출하며 객체를
	생성할 수 있게 됨.
	Date day(2011, 3, 1);
	위 줄은 Date 클래스의 day 객체를 만들면서 생성자 Date(int year, int month,
	int day) 를 호출한다 라는 의미가 됨. 따라서 Date 의 객체를 생성할 때 생성자의
	인자로 year, month, day에 각각 2011, 3, 1 을 전달하며 객체를 생성하는 것.
	
	Date day(2011, 3, 1);					// 암시적 방법 (implicit)
	Date day = Date(2011, 3, 1);	// 명시적 방법 (explicit)
	
	주로 암시적 방법 선호.
	*/
	
	day.AddDay(30);
	day.ShowDate();
	
	day.AddDay(2000);
	day.ShowDate();
	
	day.SetDate(2012, 1, 31);	// 윤년
	day.AddDay(29);
	day.ShowDate();
	
	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();
	
	return 0;
}





