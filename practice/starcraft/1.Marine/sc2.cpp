// 스타크래프트 마린 구현하기_배열, new, delete

#include <iostream>

class Marine {
	int hp;									// 마린 체력
	int coord_x, coord_y;		// 마린 위치
	int damage;							// 공격력
	bool is_dead;
	
	public:
	Marine();								// 기본 생성자
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
}

Marine::Marine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
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
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
		<< std::endl;
	std::cout << "HP : " << hp << std::endl;
}

int main() {
	Marine* marines[100];
	marines[0] = new Marine(2, 3);
	marines[1] = new Marine(3, 5);
	/* new 와 malloc 모두 동적으로 할당하지만 다른 점이 있음
	바로 new 의 경우 객체를 동적으로 생성하면서 동시에 자동으로
	생성자도 호출해준다는 점.
	
	물론 Marine 들의 포인터를 가리키는 배열이기 때문에 메소드를 호출할 때 . 이 아니라
	-> 를 사용해줘야 한다. (아래 코드 참고)
	*/
	
	
	marines[0]->show_status();
	marines[1]->show_status();
	
	std::cout << std::endl << "마린 1 이 마린 2 를 공격!" << std::endl;
	
	marines[0]->be_attacked(marines[1]->attack());
	
	marines[0]->show_status();
	marines[1]->show_status();
	
	delete marines[0];
	delete marines[1];
	// 동적으로 할당한 메모리는 언제나 해제해 주어야 한다.
}