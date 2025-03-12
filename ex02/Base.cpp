#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	Base::generate(void)
{
	int random = rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object is of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object is of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object is of type C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	Base::identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Object is of type A" << std::endl;
		return;
	}
	catch (...)
	{}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Object is of type B" << std::endl;
		return;
	}
	catch (...)
	{}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Object is of type C" << std::endl;
		return;
	}
	catch (...)
	{
		std::cout << "Unknown type" << std::endl;
	}
}
