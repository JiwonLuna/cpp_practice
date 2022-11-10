//함수인자로 레퍼런스 받기

#include <iostream>

int change_val(int &p) {
	//p가 정의되는 순간은 change_val를
	//호출할 때이므로 int &p는 정의하는 게 아님
	p = 3;
	
	return 0;
}

int main(){
	int number = 5;
	
	std::cout << number << std::endl;
	change_val(number);
	//위 문장에서 int &p = number;가 실행되는 느낌.
	//"p는 앞으로 number의 별명이다."
	
	std::cout << number << std::endl;
}