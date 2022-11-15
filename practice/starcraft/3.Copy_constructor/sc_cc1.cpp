// 포토 캐논들의 복사 생성
// 복사 생성자 (copy constroctor)

#include <string.h>
#include <iostream>

class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;
	
	public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(const Photon_Cannon& pc);
	/* 위는 복사 생성자의 표준적인 정의. 복사 생성자는 어떤 클래스 T가 있다면
	T(const T& a);
	라고 정의됨. 즉 다른 T의 객체 a를 상수 레퍼런스로 받는다. a가 const 이기
	때문에 복사 생성자 내부에서 a의 데이터를 변경할 수 없고, 오직 새롭게 초기화
	되는 인스턴스 변수들에게 '복사'만 할 수 있게 된다.
	이는 아래의 복사 생성자 호출 함수에서 복사 생성자 내부에서 pc의 인스턴스
	변수들에 접근해 객체의 shield, coord_x, coord_y 등을 초기화 할 수는
	있지만
	pc.coord_x = 3;
	처럼 pc의 값 자체는 변경할 수 없다는 뜻.
	왜냐하면 const 레퍼런스로 인자를 받았기 때문. 	
	*/
	
	void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	std::cout << "복사 생성자 호출 !" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
	std::cout << "생성자 호출 !" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}

void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
		<< std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	Photon_Cannon pc1(3, 3);
	Photon_Cannon pc2(pc1);
	Photon_Cannon pc3 = pc2;
	
	pc1.show_status();
	pc2.show_status();
	pc3.show_status();
}
