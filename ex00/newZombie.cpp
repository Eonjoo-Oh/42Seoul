#include "Zombie.hpp"
/*
Zombie* newZombie(std::string name)
{
	Zombie z1(name);

	return &z1;
//->함수의 지역변수를 리턴하기 때문에 함수가 호출된 후에도 
	Zombie* zombie = new()
	Zombie* zombie(name);
//동적할당안하고 이렇게?
	return (zombie);
}
*/
//함수를 실행할때 stack영역에 함수가 할당됐다가 해제되는데 이 함수안에서의 지역변수도 사라지기 때문에 참조하면 문제가 생길 수 있다.
//동적할당을 해야하는 이유

Zombie* newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie(name);
	return (zombie);
}