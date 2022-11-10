// new 와 delete 의 사용

/* 메모리 관리 중요!! 프로그램의 정확한 실행을 위해서 컴파일 시
모든 변수의 주소값은 확정되어야 함. But, 이는 프로그램의 많은 제약 유발

따라서 프로그램 실행 시 메모리를 자유롭게 할당하고 해제할 수 있는
힙(heap) 이라는 공간 만듦.

c언어에서는 malloc, free를 통해 힙 상에서 메모리 할당 지원
c++에서는 비슷하게 new(메모리 할당)와 delete(메모리 해제)를 사용
*/


#include <iostream>

int main() {
	int* p = new int;
	// int 크기의 공간을 할당하여 그 주소값을 p에 집어 넣음	
	
	*p = 10;
	
	std::cout << *p << std::endl;
	
	delete p;
	// 할당된 공간 해제
	// delete로 해제할 수 있는 메모리 공간은
	//사용자가 new를 통해서 할당한 공간만 가능
	return 0;
}

/* new의 사용법

T* pointer = new T;

T : 임의의 타입
*/

