// 마이펫 프로그램

#include <iostream>

typedef struct Animal {
	char name[30];	// 이름
	int age;		// 나이
	
	int health;		// 체력
	int food;		// 배부른 정도
	int clean;		// 깨끗한 정도
} Animal;

/* Animal 구조체 만들어 typedef를 통해 struct Animal 을
Animal로 간추림*/

void create_animal(Animal *animal) {
	std::cout << "동물의 이름? ";
	std::cin >> animal->name;
	
	std::cout << "동물의 나이? ";
	std::cin >> animal->age;
	
	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(Animal *animal) {
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void one_day_pass(Animal *animal) {
	// 하루가 지나면
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void show_stat(Animal *animal) {
	std::cout <<animal->name << "의 상태" << std::endl;
	std::cout << "체력   : " << animal->health << std::endl;
	std::cout << "배부름 : " << animal->food << std::endl;
	std::cout << "청결   : " << animal->clean << std::endl;
}

int main() {
	Animal *list[10];
	int animal_num = 0;
	
	for (;;) {
		std::cout << "1. 동물 추가하기" << std::endl;
		std::cout << "2. 놀기 " << std::endl;
		std::cout << "3. 상태 보기 " << std::endl;
		
		int input;
		std::cin >> input;
		
		switch (input) {
			int play_with;
			case 1:
				list[animal_num] = new Animal;
				create_animal(list[animal_num]);
				
				animal_num++;
				break;
			case 2:
				std::cout << "누구랑 놀게? : ";
				std::cin >> play_with;
				
				if (play_with < animal_num) play(list[play_with]);
				
				break;
				
			case 3:
				std::cout << "누구껄 보게? : ";
				std::cin >> play_with;
				if (play_with < animal_num) show_stat(list[play_with]);
				break;
		}
		
		for (int i = 0; i != animal_num; i++) {
			one_day_pass(list[i]);
		}
	}
	for (int i = 0; i != animal_num; i++){
		delete list[i];
	}
}


/* 위 코드는 상당한 낭비 유발

사용자가 play를 호출하면 list[play_with]를 전달해야만 했음. 
하지만 Animal 구조체 자체에 함수를 만들어서 각 구조체 변수가 각각 자신의 함수를
가지게 된다면, list[play_with]->play() 와 같이 "각 변수 자신의 함수"를 호출하여
자신의 데이터를 이용해서 처리하게 됨.

위와 같이 할 수 있다면 play 함수에 귀찮게 인자를 전달할 필요도 없고
함수 내부에서도 위 play 함수와 같이 animal-> 을 앞에 붙여가면서 작업할 필요 x
list[play_with]->play() 라고 했을 때 play 는 '자기 자신의 함수'이기 때문에
animal-> 를 지워도 됨.*/

/* 위에서는 new를 쓰고 create_animal를 반드시 호출해야만 했음->과연 이게 맞나?
create_animal 호출 안하면 변수에 아무런 값이 없어 초기화되지 않은 값에 연산을 수행하는
요류 발생 가능성 존재

만약 new로 새로운 Animal을 생성할 때 자동으로 호울되는 함수가 있으면 좋을 듯

또한 Animal 뿐만 아니라 다른 구조체를 만들게 된다면
조금씩 달라진 부분 때문에 구조체를 새로 더 만들어야 함.
또한 Animal* 배열 뿐만 아니라 다른 배열도 만들어야 하며
play, show_stat 등 함수도 각각에 맞게 새로 작성해야 함.

위 상황은 말도 안되지만 C언어의 세계에서는 모든 것을 꿋꿋히 했음

하지만 C++ 은 객체지향 프로그래밍을 한다.
(물론 C++을 단순히 객체 지향 프로그래밍 언어라고 단정 짓는 것은 어폐가 있다.
나중에 템플릿을 이용해서 제너릭한 프로그램을 작성할 수도 잏고 모던 C++ 에 들어서는
함수형 프로그래밍을 할 수 있음. 물론 기존의 C 스타일로 절차 지향적인 프로그래밍을
할 수도 있음. 즉, C++은 멀티 패러다임 언어.)
*/


