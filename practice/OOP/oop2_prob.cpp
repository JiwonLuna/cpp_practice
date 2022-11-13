#include <iostream>

class Date {
	int year_;
	int month_;  // 1 부터 12 까지.
	int day_;    // 1 부터 31 까지.

 public:
	int DaysInMonth(){
		switch (month_){
			case 2:
				if(year_%4 == 0) return 29;
				else return 28;
			case 4:
			case 6:
			case 9:
			case 11:
				return 30;
			default:
				return 31;
		}
	}
	
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}
	void AddDay(int inc) {
		if ((day_ + inc) <= DaysInMonth()) { //달이 바뀌지 않을 때
			day_ += inc;
		}
		else{ //달이 바뀔때
			day_ += inc - DaysInMonth();
			month_++;
		}
	}
	void AddMonth(int inc) {
		if(((month_+inc) % 12)==0) { //개월 수를 더한 후 12월이 예상될때 
			month_ = 12;
			year_ += (month_+inc) / 12 - 1;
		}
		else {
			year_ += (month_+inc) / 12;
			month_ = (month_+inc) % 12;
		}
	}
	void AddYear(int inc) {
		year_ += inc;
	}

	void ShowDate() {
		std::cout <<year_<<"년 " << month_ <<"월 " << day_ << "일" <<std::endl;
	}
};

int main() {
	Date date;
	//개월 수는 제한 없음
	//일 수는 개월 수가 한달 초과로 바뀌도록 하지말 것.
	
	date.SetDate(2019, 1, 10);
	date.ShowDate();
	
	date.AddMonth(13);
	date.ShowDate();
	
	date.AddDay(31);
	date.ShowDate();
	
	return 0; // 운영체제에 main 함수가 에러 없이 끝났다는 것을 알려줌.
	// 요즘은 일반적인 컴파일러에서 에러가 없다면 알아서 해주는 경우도 많지만
	// return 0;을 써주는 것을 권장.
}