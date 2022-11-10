//여러가지 참조자 예시들, 참조자 이해하기

#include <iostream>

int main() {
	int x;
	int& y = x;
	int& z = y;// z역시 x의 참조자가 된다. 
	
	x = 1;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
	
	y = 2;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
	
	z = 3;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

/*
참조자의 장점(굳이 포인터로 할 수 있는 것을 왜 참조자로 해야하느냐)
: 불필요한 &와 * 가 필요 없기 때문 -> 코드를 훨씬 간결하게 나타낼 수 있다.


*/