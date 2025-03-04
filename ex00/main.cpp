#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::cout << "Converting: " << argv[1] << std::endl;
    std::cout << "----------------------------" << std::endl;

    ScalarConverter::convert(argv[1]);

    return 0;
}
