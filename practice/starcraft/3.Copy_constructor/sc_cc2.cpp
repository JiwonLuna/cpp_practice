// 디폴트 복사 생성자의 한계

#include <string.h>
#include <iostream>

class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;
	
	char *name;
	
	public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, const char *cannon_name);
	~Photon_Cannon();
	
	void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	
	name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
	std::cout << "생성자 호출 !" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	
	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
	/* 0이 아닌 값은 if 문에서 true로 처리되므로
	0 인가 아닌가를 비교할 때 그냥 if(name) 하면
	if(name != 0) 과 동일한 의미를 가질 수 있다.
	*/
	if (name) delete[] name;
}

void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon :: " << name << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
		<< std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	Photon_Cannon pc1(3, 3, "Cannon");
	Photon_Cannon pc2 = pc1;
	
	pc1.show_status();
	pc2.show_status();
	
}