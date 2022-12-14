/*
생성자를 통해 이전에 C 프로그래밍 시에 변수 초기화를 하지 않아서 생겼던 수 많은
오류들을 효과적으로 없앨 수 있었음.
뿐만 아니라 함수 오버로딩 덕분에 함수 이름을 일일이 따로 지정하지 않더라도
성공적으로 인자들의 타입에 따라 원하는 함수들만 호출 할 수 있게 됨. 실제로 
C 언어였다면 인자의 타입에 따라서 함수의 이름들을 위워야 했지만 C++에서는
그럴 필요가 전혀 없게 됨.
*/

// 스타크래프트 마린 구현하기

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
/* 위 클래스의 객체들이 바로 개개의 마린들이 됨. 어떠한 객체의 내부적 성질, 상태 등에
관련된 변수들은 모두 private 범주에 두고, 그 객체가 외부헤 하는 행동들은 함수로써
구현하여 public 에 둠.
*/

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
	Marine marine1(2, 3);
	Marine marine2(3, 5);
	
	marine1.show_status();
	marine2.show_status();
	
	std::cout << std::endl << "마린 1 이 마린 2 를 공격!" << std::endl;
	marine2.be_attacked(marine1.attack());
	/* 위 코드는 단순한 상황이지만 약간의 문제가 있음. 수십 명의 마린들이 서로
	뒤엉켜 싸운다면? 그럴 때는 수십 개의 marine1, marine2, marine3,... 이렇게
	미리 만들 수도 없다. -> 해답 : marine 들을 배열로 정해 버리면 됨.
	클래스는 위와 동일한 다음 파일을 열어보라.
	*/
	marine1.show_status();
	marine2.show_status();
}