#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);


	// Setup the Player
	Player player(animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (player.pressedKey == false)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						
						input.setCurrent(Input::Action::LEFT);
						animated_sprite.setAnimationType(1);
						player.m_inputTimer = 1000;
						player.pressedKey = true;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						input.setCurrent(Input::Action::RIGHT);
						animated_sprite.setAnimationType(2);
						player.m_inputTimer = 1000;
						player.pressedKey = true;

					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						input.setCurrent(Input::Action::UP);
						animated_sprite.setAnimationType(3);
						player.m_inputTimer = 1000;
						player.pressedKey = true;

					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						input.setCurrent(Input::Action::DOWN);
						animated_sprite.setAnimationType(4);
						player.m_inputTimer = 1000;
						player.pressedKey = true;


					}
			case sf::Event::TextEntered:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					input.setCurrent(Input::Action::SPACE);
					animated_sprite.setAnimationType(5);
					player.m_inputTimer = 1000;
					player.pressedKey = true;


				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				{
					input.setCurrent(Input::Action::H);
					animated_sprite.setAnimationType(6);
					player.m_inputTimer = 1000;
					player.pressedKey = true;


				}
				break;


			default:
				input.setCurrent(Input::Action::IDLE);
				animated_sprite.setAnimationType(0);


				break;
				
				}
			}
		}

		// Handle input to Player
		player.handleInput(input);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};