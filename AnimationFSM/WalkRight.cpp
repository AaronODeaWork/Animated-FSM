#include <WalkRight.h>
#include <Idle.h>
#include <Jumping.h>

void WalkRight::idle(Animation * a)
{
	std::cout << "WalkRight -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void WalkRight::jumping(Animation * a)
{
	std::cout << "WalkRight -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
