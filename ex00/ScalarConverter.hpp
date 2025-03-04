#ifndef __SCALAR_CONVERTER__
#define __SCALAR_CONVERTER__

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void	convert(const std::string &literal);
};

#endif
