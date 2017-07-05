#include "SFML_utils.h"

namespace SFML_Utils
{
	bool KeyBindings::onKeyReleased(sf::Keyboard::Key key)
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
}
