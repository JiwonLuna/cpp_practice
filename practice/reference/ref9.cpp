//참조자가 아닌 값을 리턴하는 함수를 참조자로 받기
//함수가 값을 리턴하는데 참조자로 받는 경우

#include <iostream>
/*
int function() {
	int a = 5;
	return a;
}

int main() {
	int& c = function(); //댕글링 레퍼런스이기 때문에 컴파일 오류 발생
	return 0;
}
*/

//But C++에서의 중요한 예외 규칙!!

int function() {
	int a = 5;
	return a;
}

int main() {
	const int& c = function();
	//function()의 리턴값을 참조자로 받음, 하지만 const참조자로 받으면
	//문제없이 컴파일
	
	std::cout << "c : " << c << std::endl;
	return 0;
}

/*
기존에 int&로 함수의 리턴값을 받았을 때는 컴파일 자체가 안되었음
하지만 예외적으로 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값은
레퍼런스가 사라질때까지 유지 가능.
*/