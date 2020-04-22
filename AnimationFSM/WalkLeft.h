#ifndef WALKLEFT_H
#define WALKLEFT_H

#include <State.h>

class WalkLeft : public State
{
public:
	WalkLeft() {};
	~WalkLeft() {};
	void idle(Animation* a);
	void jumping(Animation* a);
	

};

#endif // !IDLE_H