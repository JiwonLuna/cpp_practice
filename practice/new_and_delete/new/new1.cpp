// new로 배열 할당하기

#include <iostream>

int main() {
	int arr_size;
	
	std::cout << "array size : ";
	std::cin >> arr_size;
	
	int *list = new int[arr_size];
	// list에 new를 이용하여 크기가 arr_size인 int 배열을 생성
	
	
	// 밑부분 읽기 전에 new1_appendix.cpp 읽고 오기	
	
	for (int i = 0; i < arr_size; i++) {
		std::cin >> list[i];
	}
	// 위 코드 처럼 for문 안에서 int i 를 선언하면
	// 밖에서 i를 다른 용도로 사용했더라도 for 문 안에서는
	// counter로 사용할 수 있기 때문에 좋음
	
	for (int i = 0; i < arr_size; i++) {
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}
	delete[] list;
	// new로 할당했다면 delete로 해제
	// new[]로 할당했다면 delete[]로 해제
	// 서로 짝을 이룸
	
	return 0;
}