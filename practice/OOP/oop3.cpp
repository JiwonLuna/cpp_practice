// 함수의 오버로딩 (Overloading)

/* 기존 C언어에서는 하나의 이름을 가지는 함수는 딱 1개만 존재할 수 밖에 없기에
과부하 라는 말 자체가 성립x. printf, scanf도 C라이브러리에 단 1개만 존재.
하지만 C++에서는 같은 이름을 가진 함수가 여러 개 존재해도 됨. 즉, 함수의 이름에
과부하가 걸려도 상관없음.

그렇다면 C++에서는 같은 이름의 함수를 호출했을 때 어떻게 구분?
-> 함수를 호출했을 때 사용하는 인자를 보고 결정!!

*/

#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }
// 이름이 똑같이 print 인 함수를 3개 정의

/* 고전적인 C 컴파일러 에서는 오류가 발생할 것이나 C++에서는
함수의 이름이 같더라도 인자가 다르면 다른 함수라고 판단해서 오류 발생 x.
*/

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;
	
	print(a);
	print(b);
	print(c);
	/* C언어였을 경우 int, char, double 타입에 따라 함수의 이름을 제각각 다르게 만들어서
	호출해 주어야 했던 반면에 C++ㅇ[ㅔ서는 컴파일러가 알아서 적합한 인자를 가지는 함수를 찾아서 호출해줌
	*/
	
	return 0;
}