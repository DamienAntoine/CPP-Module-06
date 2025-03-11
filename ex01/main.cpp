#include <iostream>
#include "Serializer.hpp"
#include "data.hpp"

int main()
{
	Data original;
	original.id = 42;
	original.content = "Test Data";

	Data* ptr = &original;
	std::cout << "Original Data object:" << std::endl;
	std::cout << "	Address: " << ptr << std::endl;
	std::cout << "	Name: " << ptr->id << std::endl;
	std::cout << "	Content: " << ptr->content << std::endl;


	uintptr_t serialized = Serializer::serialize(ptr);
	std::cout << "\nSerialized value: " << serialized << std::endl;


	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "\nDeserialized Data object:" << std::endl;
	std::cout << "	Address: " << deserialized << std::endl;
	std::cout << "	ID: " << deserialized->id << std::endl;
	std::cout << "	Content: " << deserialized->content << std::endl;

	std::cout << "\nPointer comparison: "<< std::endl;
	if (ptr == deserialized)
		std::cout << "MATCH" << std::endl;
	else
	std::cout << "DIFFERENT" << std::endl;

	return 0;
}
