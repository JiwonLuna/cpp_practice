//레퍼런스를 리턴하는 함수-2
//외부 변수의 레퍼런스를 리턴

#include <iostream>

int& function(int& a) {		//인자로 받은 레퍼런스를 그대로 리턴
	a = 5;
	return a;
}


int main() {
	int b = 2;
	std::cout << b << std::endl;
	
	int c = function(b);
	std::cout << b <<std::endl<<c<< std::endl;
	
	return 0;
}
//따라서 function이 리턴한 참조자 a는 아직 main에 있는 b를 계속 참조한다.

/*
참조자를 리턴하는 경우의 장점
레퍼런스를 리턴하게 된다면 레퍼런스가 참조하는 타입의 크기와 상관 없이
딱 한 번의 주소값 복사로 전달이 끝나게 된다. -> 효율적

*/
