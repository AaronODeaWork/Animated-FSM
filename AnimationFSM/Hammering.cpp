#include <Hammering.h>
#include <Idle.h>

#include <string>

void Hammering::idle(Animation * a)
{
	std::cout << "hammering -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
