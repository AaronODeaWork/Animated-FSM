#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	default:
	case Input::Action::IDLE:
		//std::cout << "Player Idling" << std::endl;
		m_animation.idle();
		break;
	case Input::Action::UP:
		//std::cout << "Player Up" << std::endl;
		m_animation.climbing();
		break;
	case Input::Action::LEFT:
		//std::cout << "Player Left" << std::endl;
		m_animation.walkLeft();
		break;
	case Input::Action::RIGHT:
		//std::cout << "Player right" << std::endl;
		m_animation.walkRight();  
		break;
	case Input::Action::SPACE:
		//std::cout << "Player jumping" << std::endl
		m_animation.jumping();
		break;
	case Input::Action::H:
		//std::cout << "Player hammering" << std::endl
		m_animation.hammering();
		break;
	case Input::Action::DOWN:
		//std::cout << "Player shoveling" << std::endl
		m_animation.shoveling();
		break;
	
	}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();

	if(m_inputTimer != 0 )
	{
		m_inputTimer--;
	}

	if (m_inputTimer == 0)
	{
		pressedKey = false;
	}

}