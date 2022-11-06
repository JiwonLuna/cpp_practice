#include <iostream>


int main(){
	int lucky_number;
	std::cout<<"나만의 비밀 수를 입력하세요 : ";
	
	std::cin>> lucky_number;
	
	int user_input;
	std::cout<< "상대방은 맞춰보세요" << std::endl;
	
	while(1){
		
		std::cout <<"입력 : ";
		std::cin >> user_input;
		if (lucky_number == user_input){
			std::cout<<"맞추셨습니다!!"<<std::endl;
			break;
		}else{
			std::cout <<"다시 생각해 보세요"<<std::endl;
		}
			
	}
	
	return 0;
}