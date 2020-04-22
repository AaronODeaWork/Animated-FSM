#include <WalkLeft.h>
#include <Idle.h>
#include <Jumping.h>


void WalkLeft::idle(Animation * a)
{
	std::cout << "walkLeft -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void WalkLeft::jumping(Animation * a)
{
	std::cout << "walkleft -> jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}


