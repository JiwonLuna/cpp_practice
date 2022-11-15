// 소멸자 호출 확인하기

#include <string.h>
#include <iostream>

class Test {
	char c;
	
	public:
	Test(char _c) {
		c = _c;
		std::cout << "생성자 호출 " << c << std::endl;
	}
	~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};

void simple_function() { Test b('b'); }
int main() {
	Test a('a');
	simple_function();
}

/* 출력결과 :
생성자 호출 a
생성자 호출 b
소멸자 호출 b
소멸자 호출 a

출력 결과의 순서에 대해서 잘 이해하고 있자.
*/