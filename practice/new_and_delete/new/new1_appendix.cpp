#include <iostream>

/* 변수의 선언 위치에 따른 결과
int main() {
	{
		int a = 4;
		std::cout << "안쪽 a : " << a;
	}
	
	std::cout << "밖에서 a : " << a;
	//변수 a는 위의 중괄호 안에서 선언되었기 때문에
	//변수 a의 사용 범위는 그 중괄호 안 뿐.
}
*/

int a = 4;

int main() {
	{
		std::cout << "외부의 변수 1 : " << a << std::endl;
		int a = 3;
		std::cout << "내부의 변수 : " << a << std::endl;
	} //내부 변수 소멸

	std::cout << "외부의 변수 2 : " << a << std::endl;
}	