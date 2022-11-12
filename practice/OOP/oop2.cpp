/* 클래스
C++ 상에서 객체를 만들어 내는 객체의 설계도, 클래스(class)
C++ 에서 클래스를 이용해서 만들어진 객체를 인스턴스(instance)라고 부름.
(그래서 위에서 객체의 변수와 메소드를 인스턴스 변수와 인스턴스 메소드리고 했음)
*/

#include <iostream>

class Animal {
	private:
	int food;
	int weight;
	
	public:
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}
	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}
	void view_stat() {
		std::cout << "이 동물의 food   : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
	}
};  // class 만들고 세미콜론 잊지 말기!!!

int main() {
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);
	
	animal.view_stat();
	return 0;
}