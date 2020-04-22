#ifndef WALKRIGHT_H
#define WALKRIGHT_H

#include <State.h>

class WalkRight : public State
{
public:
	WalkRight() {};
	~WalkRight() {};
	void idle(Animation* a);
	void jumping(Animation* a);
};

#endif // !IDLE_H