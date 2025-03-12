#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Base baseInstance;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "\nTest #" << i+1 << ":" << std::endl;

		Base* obj = baseInstance.generate();
		std::cout << "Identifying with pointer: ";
		baseInstance.identify(obj);

		std::cout << "Identifying with reference: ";
		baseInstance.identify(*obj);

		delete obj;
	}

	std::cout << "\n=== TESTING WITH SPECIFIC INSTANCES ===" << std::endl;

	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	std::cout << "\nInstance A:" << std::endl;
	std::cout << "Pointer: ";
	baseInstance.identify(a);
	std::cout << "Reference: ";
	baseInstance.identify(*a);

	std::cout << "\nInstance B:" << std::endl;
	std::cout << "Pointer: ";
	baseInstance.identify(b);
	std::cout << "Reference: ";
	baseInstance.identify(*b);

	std::cout << "\nInstance C:" << std::endl;
	std::cout << "Pointer: ";
	baseInstance.identify(c);
	std::cout << "Reference: ";
	baseInstance.identify(*c);

	delete a;
	delete b;
	delete c;

	return 0;
}
