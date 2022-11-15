// 소멸자(Destructor) 사용하기

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
	~Marine();
	
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

Marine::~Marine(){
	std::cout << name << " 의 소멸자 호출 ! " << std::endl;
	if (name != NULL) {
		delete[] name;
	}
}
/* name 이 NULL이 아닐 경우에(동적으로 할당이 되었을 경우에)만 delete로
name을 삭제. name 자체가 char의 배열로 동적할당 하였기 때문에 delete 역시
delete[] name, []를 꼭 써줘야 한다.*/

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

/* 생상자가 클래스 이름과 똑같이 생겼다면 소멸자는 그 앞에 ~ 만 붙이면 됨.
생성자와 다른 점은, 소멸자는 인자를 아무 것도 가지지 않는다는 것.
소멸하는 객체에 인자를 넘겨서 할 것도 없음. 따라서 소멸자는 오버로딩도 되지 않음.


*/