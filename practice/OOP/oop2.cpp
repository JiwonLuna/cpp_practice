/* 클래스
C++ 상에서 객체를 만들어 내는 객체의 설계도, 클래스(class)
C++ 에서 클래스를 이용해서 만들어진 객체를 인스턴스(instance)라고 부름.
(그래서 위에서 객체의 변수와 메소드를 인스턴스 변수와 인스턴스 메소드리고 했음)
*/

#include <iostream>

class Animal {
	/* 이 class는 Animal 클래스를 통해서 생성될 임의의 객체에 대한 설계도.
	즉, Animal 클래스를 통해서 생성될 객체는 food, weight 라는 변수가 있고,
	set_animal, increase_food, view_stat 이라는 함수들이 있는데, Animal
	클래스 상에서 이들을 지칭할 때 각각 맴버 변수(member variable)과
	멤버 함수(member function)이라고 부름.
	
	멤버 변수와 멤버 함수는 실재하지는 않는다. 인스턴스가 만들어 져야 그제서야
	세상에 나오는 것. 즉, 설계도 상에 있다고 해서 아파트가 실제로 존재하는 것은
	아닌 것과 마찬가지.
	*/
	
	private:
	int food;
	int weight;
	/* '접근 지시자'
	private 키워드의 경우, 아래에 쓰여진 것들은 모두 객체 내에서 보호되고 있다는 의미.
	private 되고 있는 모든 것들은 자기 객체 안에서만 접근할 수 있을 뿐 객체 외부에서는
	접근할 수 없게 된다.
	키워드 명시를 하지 않았다면 기본적으로 private로 설정된다. 즉, 맨 위의 private를
	지워도 food와 weight는 알아서 private로 설정됨.
	*/
		
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
	/* 멤버 함수들을 public으로 지정. public 에 들어간 것은 외부에서 마음껏 이용가능.
	그래서 main 함수에서도 이들을 사용*/
	
	
};  // class 만들고 세미콜론 잊지 말기!!!

int main() {
	Animal animal;
	/* 기존의 구조체에서 구조체 변수를 생성할 때와 동일한데, 구조체의 경우 앞에 struct를
	명시했어야 했지만 여기서는 그러지 않아도 됨. 그냥 int 나 char 처럼 Animal 이라고
	써주면 됨. 이와 같이 Animal animal;을 하면 Animal 클래스의 인스턴스 animal을 
	만들게 된 것.
	*/
	
	animal.set_animal(100, 50);
	animal.increase_food(30);
	
	animal.view_stat();
	return 0;
}