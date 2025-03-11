#ifndef __SERIALIZER__
#define __SERIALIZER__

//#include <cstdint>
#include <stdint.h>
#include "data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
