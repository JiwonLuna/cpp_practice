#include <iostream>
/*
int main () {
	int& ref = 4;
	
	std::cout << ref << std::endl;
}

위 코드는 리터럴인 상수 값 자체를 레퍼런스로 참조하게 되면
ref = 5;
와 같이 리터럴의 값을 바꾸는 말도 안되는 행위가 가능하게 되므로
C++문법 상 상수 리터럴을 일반적인 레퍼런스가 참조하는 것은 불가능

대신에 상수참조자로 선언한다면 아래와 같이 리터럴도 참조할 수 있다.
*/

int main () {
	const int& ref = 4;
	
	std::cout << ref << std::endl;
}

