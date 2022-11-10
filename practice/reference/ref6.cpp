//레퍼런스의 배열, 배열들의 레퍼런스

/*
주소값이 존재한다는 의미는 해당 원소가 메모리 상에서 존재한다는 의미
하지만 레퍼런스는 특별한 경우가 아닌 이상 메모리 상에서 공간을 차지 하지 않는다.
따라서 이러한 모순 때문에 레퍼런스들의 배열을 정의하는 것은 언어차원에서 금지.

그와 반대인 배열들의 레퍼런스는 가능

*/

#include <iostream>

int main(){
	int arr[3] = {1, 2, 3};
	int (&ref)[3] = arr;
	/*
	포인터와는 다르게 배열의 레퍼런스는 참조하기 위해선 반드시 배열의 크기를 명시해야 함.
	int (&ref)[5]라면 크기가 5인 int 배열의 별명이 되어야 함.
	*/
		
	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	std::cout << ref[0] << ref[1] << ref[2] << std::endl;
	std::cout << arr << std::endl;
	
	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;
	
	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	std::cout << ref[0] << ref[1] << ref[2] << std::endl;
	
	// int arr[3][2] = {1, 2, 3, 4, 5, 6};
	// int (&ref)[3][2] = arr;
	
	// std::cout << arr[0][0] << arr[1][0] << arr[2][0] << std::endl
	// 	<< arr[0][1] << arr[1][1] << arr[2][1] << std::endl;
	
	
	return 0;
}