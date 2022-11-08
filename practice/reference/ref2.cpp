//참조자 정의

#include <iostream>

int main() {
	int a = 3;
	int& another_a = a;
	//'another_a는 a의 참조자다!' 정의
	//가리키고자 하는 타입(int) 뒤에 &를 붙이면 참조자를 정한다
	
	/*
	another_a는 a의 또다른 이름,
	another_a에 어떠한 작업을 수행해도 
	사실상 a에 그 작업을 하는 것과 마찬가지!
	*/
	
	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
	
	return 0;
}

/*
레퍼런스와 포인터의 차이점
1. 레퍼런스는 정의 시에 반드시 누구의 별명인지 명시해야한다.
	따라서
	int& another_a;
	는 불가능!
	int* p;는 가능
	
2. 레퍼런스가 한번 별명이 되면 절대로 다른이의 별명이 될 수 없다.

3. 레퍼런스는 메모리 상에 존재하지 않을 수도 있다.




*/