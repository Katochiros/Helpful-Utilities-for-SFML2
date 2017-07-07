#pragma once
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include <SFML\Graphics.hpp>
#include <vector>




namespace SFML_utils
{	
	bool onKeyReleased(sf::Keyboard::Key key);	
	bool onMouseButtonReleased(sf::Mouse::Button button);

	class Text {
	public:
		static void		initialise(std::string fontPath);
		static void		draw(sf::Vector2f pos, unsigned int size, std::string text, sf::RenderWindow & window, sf::Color color = sf::Color::White);
	private:
		static sf::Font				font;
		static sf::Text				text;
	};
}
	
