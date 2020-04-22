#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Hammering.h>
#include <Shoveling.h>
#include <WalkLeft.h>
#include <WalkRight.h>

#include <string>

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Idle::hammering(Animation * a)
{
	std::cout << "Idle -> = Hammering" << std::endl;
	a->setCurrent(new Hammering());
	delete this;
}

void Idle::shoveling(Animation * a)
{
	std::cout << "Idle -> = shoveling" << std::endl;
	a->setCurrent(new Shoveling());
	delete this;
}

void Idle::walkLeft(Animation * a)
{
	std::cout << "Idle -> = walkLeft" << std::endl;
	a->setCurrent(new WalkLeft());
	delete this;
}

void Idle::walkRight(Animation * a)
{
	std::cout << "Idle -> = walkRight" << std::endl;
	a->setCurrent(new WalkRight());
	delete this;
}
