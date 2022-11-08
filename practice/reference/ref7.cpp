//레퍼런스를 리턴하는 함수-1


/*#include <iostream>

int function() {
	int a = 2;
	return a;
}

int main() {
	int b = function();
	std::cout << b << std::endl;
	
	return 0;
}*/

/*
function 안에서 정의된 a 변수의 값이 b에 '복사'됨.
따라서 b에 는 리턴된 a의 값이 그대로 저장되어있음.
단 복사된 것은 function이 종료되고 나면 a는 메모리에서 사라짐. 따라서
더이상 main 안에서는 a를 찾을 수 없고 b만 이용 가능하다.
*/


/*
#include <iostream>

int &function() {
	int a = 2;
	return a;
}

int main() {
	int b = function();
	b = 3;
	return 0;
}
*/
/*
위 파일 -> 컴파일 경고 & 런타임 오류
function 리턴타입은 int& 이다. 따라서 참조자를 리턴하게 됨, 문제는 리턴하는 a는
함수의 리턴과 함께 사라진다는 점. function안에서만 정의되어 있기 때문.

위와 같이 레퍼런스는 있는데 원래 참조하던 것이 사라진 레퍼런스를 댕글링 레퍼런스
(Dangling reference) 라고 부름. Dangling이란 약하게 결합되어서 달랑달랑거리는
것을 뜻함.

따라서 위처럼 레퍼런스를 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴하지
않도록 조심해야함.
*/

