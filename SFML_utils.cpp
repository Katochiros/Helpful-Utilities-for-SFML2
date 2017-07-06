#include "SFML_utils.h"

namespace SFML_utils
{
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
}
