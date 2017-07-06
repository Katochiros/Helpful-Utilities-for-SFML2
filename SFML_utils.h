#pragma once
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include <vector>

namespace SFML_utils
{
	bool onKeyReleased(sf::Keyboard::Key key);	
	bool onMouseButtonReleased(sf::Mouse::Button button);
}
	
