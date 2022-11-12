#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date) {
	  year_ = year;
	  month_ = month;
	  day_ = date;
  }
  void AddDay(int inc) {
	  if(month_ == 2){
		  if(year_%4 ==0){ //윤년인 경우
			  if(day_+inc > 29){
				  
			  }
		  }
	  }
  }
  void AddMonth(int inc) {
	  year_ += (month_+inc) / 12;
	  month_ = (month_+inc) % 12;
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
	
	date.SetDate(2022, 11, 12);
	date.AddMonth(14);
	
	date.ShowDate();
}