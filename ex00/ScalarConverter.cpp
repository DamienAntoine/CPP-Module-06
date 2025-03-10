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

static bool isChar(const std::string &literal)
{
	return (literal.length() == 1);
}

static bool isInt(const std::string &literal)
{
	if (literal.empty())
		return false;

	for (size_t i = 0; i < literal.length(); i++) {
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue;
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

static bool isFloat(const std::string &literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;

	return (literal.find('.') != std::string::npos &&
			literal.length() > 0 &&
			literal[literal.length() - 1] == 'f');
}

static bool isDouble(const std::string &literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;

	return (literal.find('.') != std::string::npos);
}

static void convertChar(const std::string &literal)
{
	char c_value = literal[0];

	std::cout << "char: '" << c_value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c_value) << std::endl;
	std::cout << "float: " << static_cast<float>(c_value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c_value) << ".0" << std::endl;
}

static void convertInt(const std::string &literal)
{
	int i_value = atoi(literal.c_str());

	if (i_value < CHAR_MIN || i_value > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(i_value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i_value) << "'" << std::endl;

	std::cout << "int: " << i_value << std::endl;
	std::cout << "float: " << static_cast<float>(i_value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i_value) << ".0" << std::endl;
}

static void convertFloat(const std::string &literal)
{
	float f_value;

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		if (literal == "nanf")
			f_value = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff")
			f_value = std::numeric_limits<float>::infinity();
		else
			f_value = -std::numeric_limits<float>::infinity();

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f_value << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f_value) << std::endl;
	}
	else
	{
		std::string trimmed = literal.substr(0, literal.length() - 1);
		f_value = atof(trimmed.c_str());

		if (f_value < CHAR_MIN || f_value > CHAR_MAX || std::isnan(f_value))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<char>(f_value)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f_value) << "'" << std::endl;

		if (f_value < INT_MIN || f_value > INT_MAX || std::isnan(f_value))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f_value) << std::endl;


		std::cout << "float: " << f_value;
		if (f_value == static_cast<int>(f_value))
			std::cout << ".0";
		std::cout << "f" << std::endl;


		std::cout << "double: " << static_cast<double>(f_value);
		if (f_value == static_cast<int>(f_value))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

static void convertDouble(const std::string &literal)
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

void	ScalarConverter::convert(const std::string &literal)
{
	if (isChar(literal))
		convertChar(literal);
	else if (isInt(literal))
		convertInt(literal);
	else if (isFloat(literal))
		convertFloat(literal);
	else if (isDouble(literal))
		convertDouble(literal);
	else
		std::cout << "Error: Invalid literal format" << std::endl;
}
