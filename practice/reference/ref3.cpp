//함수인자로 레퍼런스 받기

#include <iostream>

int change_val(int &p) {//int &p는 p가 정의되는 순간이 change_val를 호출할 때이므로 정의하는 게 아님
	p = 3;
	
	return 0;
}

int main(){
	int number = 5;
	
	std::cout << number << std::endl;
	change_val(number);
	std::cout << number << std::endl;
}