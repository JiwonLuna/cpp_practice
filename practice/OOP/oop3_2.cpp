// 함수의 오버로딩 (2)

#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;
	
	print(a);
	print(b);
	// 결과값 : 'int : 99'
	/*
	1단계에서는 char 타입의 인자를 가진 print가 없어서 넘어감
	2단계에서는 char이 int로 변환된다면 print(int x)를 호출할 수 있기 때문에
	결국 print(int x)가 호출됨.
	*/
	
	print(c);
	
	return 0;
}

/* main 함수에서 a나 c는 자기를 인자로 하는 정확한 함수들이 있어서 성공적으로
호출되지만 char의 경우 자기와 정확히 일치하는 인자를 가지는 함수가 없기 때문에
'자신과 최대로 근접한 함수'를 찾게 된다.*/

/* C++ 컴파일러에서 함수를 오버로딩하는 과정
(https://modoocode.com/173 참고)
1. 자신과 타입이 정화히 일치하는 함수를 찾는다.
2. 정확히 일치하는 타입이 없는 경우 형변환을 통해서 일치하는 함수를 찾아본다.
	char, unsigned char, short 는 int 로 변환.
	unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환.
	float 은 double 로 변환.
	enum 은 int 로 변환.
3. 위와 같이 변환해도 일치하는 것이 없다면 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾음
4. 유저 정의된 타입 변환으로 일치하는 것을 찾음.

위 과정을 통과해도 일치하는 함수 못 찾거나 같은 단계에서 2개 이상 일치하는 경우에는
모호하다(ambiguous)고 판단해서 오류 발생.
*/