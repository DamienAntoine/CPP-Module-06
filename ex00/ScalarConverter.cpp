#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>
#include <cctype>
#include <climits>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void	ScalarConverter::convert(const std::string &literal)
{
	bool isint = 0;
	bool ischar = 0;
	bool isdouble = 0;
	bool isfloat = 0;

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		isdouble = 1;
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		isfloat = 1;
	else if (literal.find('.') != std::string::npos && literal.length() > 0 && literal[literal.length() - 1] == 'f')
		isfloat = 1;
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		ischar = 1;
	else if (literal.find('.') != std::string::npos)
		isdouble = 1;
	else
	{
		bool validInt = true;
		for (size_t i = 0; i < literal.length(); i++)
		{
			if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
				continue;
			if (!isdigit(literal[i]))
			{
				validInt = false;
				break;
			}
		}
		if (validInt)
			isint = 1;
	}
	if (!isint && !ischar && !isdouble && !isfloat)
	{
		std::cout << "Error: Invalid literal format" << std::endl;
		return;
	}

	if (isdouble)
	{
		double d_value;

		if (literal == "nan" || literal == "+inf" || literal == "-inf")
		{
			if (literal == "nan")
				d_value = std::numeric_limits<double>::quiet_NaN();
			else if (literal == "+inf")
				d_value = std::numeric_limits<double>::infinity();
			else
				d_value = -std::numeric_limits<double>::infinity();

			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(d_value) << "f" << std::endl;
			std::cout << "double: " << d_value << std::endl;
		}
		else
		{
			d_value = atof(literal.c_str());

			if (d_value < CHAR_MIN || d_value > CHAR_MAX || std::isnan(d_value))
				std::cout << "char: impossible" << std::endl;
			else if (!isprint(static_cast<char>(d_value)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(d_value) << "'" << std::endl;

			if (d_value < INT_MIN || d_value > INT_MAX || std::isnan(d_value))
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(d_value) << std::endl;

			std::cout << "float: " << static_cast<float>(d_value);
			if (d_value == static_cast<int>(d_value))
				std::cout << ".0";
			std::cout << "f" << std::endl;

			std::cout << "double: " << d_value;
			if (d_value == static_cast<int>(d_value))
				std::cout << ".0";
			std::cout << std::endl;
		}
	}
}
