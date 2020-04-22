#include <AnimatedSprite.h>


AnimatedSprite::AnimatedSprite() 
{
	m_current_frame = 0;
}

AnimatedSprite::AnimatedSprite(const sf::Texture& t) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {}

AnimatedSprite::AnimatedSprite(const sf::Texture& t, const sf::IntRect& rect) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {
	m_frames.push_back(rect);
}

AnimatedSprite::~AnimatedSprite() {}

const sf::Clock& AnimatedSprite::getClock() {
	return m_clock;
}

const sf::Time& AnimatedSprite::getTime() {
	return m_time;
}

const vector<IntRect>& AnimatedSprite::getFrames() {
	return m_frames;
}

const IntRect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

void AnimatedSprite::addFrame(IntRect& frame) {
	m_frames.push_back(frame);
	
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::update(){
	m_frames.clear();


		switch (m_animatedType)
		{
		default:
		case 0:

			addFrame(sf::IntRect(3, 3, 84, 84));
			addFrame(sf::IntRect(88, 3, 84, 84));
			addFrame(sf::IntRect(173, 3, 84, 84));
			addFrame(sf::IntRect(258, 3, 84, 84));
			addFrame(sf::IntRect(343, 3, 84, 84));

			break;
		case 1:

			addFrame(sf::IntRect(3, 176, 84, 84));
			addFrame(sf::IntRect(88, 176, 84, 84));
			addFrame(sf::IntRect(173, 176, 84, 84));
			addFrame(sf::IntRect(258, 176, 84, 84));
			addFrame(sf::IntRect(343, 176, 84, 84));

			break;
		case 2:

			addFrame(sf::IntRect(3, 88, 84, 84));
			addFrame(sf::IntRect(88, 88, 84, 84));
			addFrame(sf::IntRect(173, 88, 84, 84));
			addFrame(sf::IntRect(258, 88, 84, 84));
			addFrame(sf::IntRect(343, 88, 84, 84));

			break;

		case 3:
			addFrame(sf::IntRect(3, 352, 84, 84));
			addFrame(sf::IntRect(88, 352, 84, 84));
			addFrame(sf::IntRect(176, 352, 84, 84));
			addFrame(sf::IntRect(264, 352, 84, 84));
			addFrame(sf::IntRect(352, 352, 84, 84));

			break;

		case 4:

			addFrame(sf::IntRect(264, 264, 84, 84));
			addFrame(sf::IntRect(352, 264, 84, 84));
			addFrame(sf::IntRect(264, 264, 84, 84));
			addFrame(sf::IntRect(352, 264, 84, 84));
			addFrame(sf::IntRect(264, 264, 84, 84));

			break;

		case 5:

			addFrame(sf::IntRect(440, 176, 84, 84));
			addFrame(sf::IntRect(440, 88, 84, 84));
			addFrame(sf::IntRect(440, 3, 84, 84));
			addFrame(sf::IntRect(440, 88, 84, 84));
			addFrame(sf::IntRect(440, 176, 84, 84));

			break;

		case 6:

			addFrame(sf::IntRect(88, 264, 84, 84));
			addFrame(sf::IntRect(173, 264, 84, 84));
			addFrame(sf::IntRect(88, 264, 84, 84));
			addFrame(sf::IntRect(173, 264, 84, 84));
			addFrame(sf::IntRect(88, 264, 84, 84));

			break;

		}

		if (m_clock.getElapsedTime() > m_time) {
			if (m_frames.size() > m_current_frame + 1)
			{
				m_current_frame++;
			}
			else {
				m_current_frame = 0;
			}
			m_clock.restart();
		
	}
	
}

void AnimatedSprite::setAnimationType(int type)
{
	m_animatedType = type;
}




