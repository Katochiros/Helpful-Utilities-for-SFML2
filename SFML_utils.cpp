#include "SFML_utils.h"
#include <iostream>

namespace SFML_utils
{
	sf::Font Text::font = sf::Font();
	sf::Text Text::text = sf::Text();

	bool onKeyReleased(sf::Keyboard::Key key)
	{	
	static int key_pressed_index;
	key_pressed_index = static_cast<int>(key);

	static std::vector<bool> keys_pressed(sf::Keyboard::Key::KeyCount);

	if (sf::Keyboard::isKeyPressed(key) == true && keys_pressed[key_pressed_index] == false)
	{
		keys_pressed[key_pressed_index] = true;
		return false;
	}
		
		
	if (sf::Keyboard::isKeyPressed(key) == false && keys_pressed[key_pressed_index] == true)
	{
		keys_pressed[key_pressed_index] = false;
		return true;
	}
	
	return false;
	}

	bool onKeyPress(sf::Keyboard::Key key)
	{
		static int key_pressed_index;
		key_pressed_index = static_cast<int>(key);

		static std::vector<bool> keys_pressed(sf::Keyboard::Key::KeyCount);

		if (sf::Keyboard::isKeyPressed(key) == true && keys_pressed[key_pressed_index] == false)
		{
			keys_pressed[key_pressed_index] = true;
			return true;
		}


		if (sf::Keyboard::isKeyPressed(key) == false && keys_pressed[key_pressed_index] == true)
		{
			keys_pressed[key_pressed_index] = false;
			return false;
		}

		return false;
	}

	bool onMouseButtonReleased(sf::Mouse::Button button)
	{
		static int button_pressed_index;
		button_pressed_index = static_cast<int>(button);

		static std::vector<bool> buttons_pressed(sf::Mouse::Button::ButtonCount);

		if (sf::Mouse::isButtonPressed(button) == true && buttons_pressed[button_pressed_index] == false)
		{
			buttons_pressed[button_pressed_index] = true;
			return false;
		}

		if (sf::Mouse::isButtonPressed(button) == false && buttons_pressed[button_pressed_index] == true)
		{
			buttons_pressed[button_pressed_index] = false;
			return true;
		}

		return false;
	}

	void Text::initialise(std::string fontPath)
	{
		if (!Text::font.loadFromFile(fontPath))
			std::cout << "Could not load font\n";
		else
			std::cout << "Font loaded!\n";

		Text::text.setFont(Text::font);
	}

	void Text::draw(sf::Vector2f pos, unsigned int size, std::string text, sf::RenderWindow & window, sf::Color color)
	{
		Text::text.setString(text);
		Text::text.setPosition(pos);
		Text::text.setCharacterSize(size);
		Text::text.setColor(color);
		window.draw(Text::text);
	}

	void quantiseVector(sf::Vector2f & vec, sf::Vector2i quantise_size)
	{
		sf::Vector2i pos((int)vec.x, (int)vec.y);
		pos.x = (pos.x / quantise_size) * quantise_size.x;
		pos.y = (pos.y / quantise_size) * quantise_size.y;
		vec.x = (float)pos.x;
		vec.y = (float)pos.y;
	}
}
