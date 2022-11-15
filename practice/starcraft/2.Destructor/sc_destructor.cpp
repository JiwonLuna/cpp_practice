// 마린의 이름 만들기
#include <string.h>
#include <iostream>

class Marine {
	int hp;									// 마린 체력
	int coord_x, coord_y;		// 마린 위치
	int damage;							// 공격력
	bool is_dead;
	char* name;	// 마린 이름
	
	public:
	Marine();								// 기본 생성자
	Marine(int x, int y, const char* marine_name);	// 이름까지 지정
	Marine(int x, int y);		// x, y 좌표에 마린 생성
	
	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);
	
	void show_status();
};

Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) {
	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);
	
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}
/* 분명히 위 코드에서 name 에 우리가 생성하는 마린의 이름을 넣어줄 때, name 을
동적으로 생성해서 문자열을 복사했는데, 그럼 동적으로 할당된 char 배열에 대한
delete 는 언제 이루어 지는 것인가?

안타깝게도, 명확히 delete 를 지정하지 않는 한 자동으로 delete 가 되는 경우는 x.
다시 말해 동적으로 할당한 저 name은 영원히 메모리 공간 속에서 떠다닌다는 이야기.
위와 같은 name 들이 쌓이고 쌓이게 되면 메모리 누수(Memory Leak)라는 문제점이 발생.

만약 main 함수 끝에서 Marine 이 delete 될 때, 즉 우리가 생성했던 객체가 소멸될
때 자동으로 호출되는 함수, 마치 객체가 생성될 때 자동으로 호출되었던 생성자처럼
소멸 될 때 자동으로 호출되는 함수가 있다면 얼마나 좋을까? 그것이 바로 소멸자.
(Destructor) -> 다음 파일로 이동.
*/

Marine::Marine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	name = NULL;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
	std::cout << " *** Marine : " << name << " ***"<< std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
		<< std::endl;
	std::cout << "HP : " << hp << std::endl;
}

int main() {
	Marine* marines[100];
	
	marines[0] = new Marine(2, 3, "Marine 2");
	marines[1] = new Marine(3, 5, "Marine 1");
	
	marines[0]->show_status();
	marines[1]->show_status();
	
	std::cout << std::endl << "마린 1 이 마린 2 를 공격!" << std::endl;
	
	marines[0]->be_attacked(marines[1]->attack());
	
	marines[0]->show_status();
	marines[1]->show_status();
	
	delete marines[0];
	delete marines[1];
}

