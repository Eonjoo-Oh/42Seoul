#include "Serializer.hpp"

int main()
{
	Data		data1;
	Data		*data2 = NULL;
	uintptr_t	uintptr;

	data1.name = "bokdong";
	data1.age = 3;
	std::cout << "data1 : " << &data1 << std::endl;
	std::cout << "data2 : " << data2 << std::endl;
	
	uintptr = Serializer::serialize(&data1);
	std::cout << "serialize data to uintptr: " << uintptr << std::endl;
	
	data2 = Serializer::deserialize(uintptr);
	std::cout << "deserialize uintptr to data2: " << data2 << std::endl;
	std::cout << "data2 name: " << data2->name << std::endl;
	std::cout << "data2 age: " << data2->age << std::endl;
}