// new로 배열 할당하기

#include <iostream>

int main() {
	int arr_size;
	
	std::cout << "array size : ";
	std::cin >> arr_size;
	
	int *list = new int[arr_size];
	/* list에 new를 이용하여 크기가 arr_size인 int 배열을 생성
	
	*/
	
	
	
	for (int i = 0; i < arr_size; i++) {
		std::cin >> list[i];
	}
	for (int i = 0; i < arr_size; i++) {
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}
	delete[] list;
	return 0;
}