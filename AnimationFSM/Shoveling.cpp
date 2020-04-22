#include <Shoveling.h>
#include <Idle.h>

#include <string>

void Shoveling::idle(Animation * a)
{
	std::cout << "shoveling -> idel" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

