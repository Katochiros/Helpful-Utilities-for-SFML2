#include "SFML_utils.h"
#include <iostream>
#include <sstream>
#include <fstream>

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
		pos.x = (pos.x / quantise_size.x) * quantise_size.x;
		pos.y = (pos.y / quantise_size.y) * quantise_size.y;
		vec.x = (float)pos.x;
		vec.y = (float)pos.y;
	}

	float vecfLength(const sf::Vector2f & v)
	{
		return sqrtf((v.x * v.x) + (v.y * v.y));
	}

	sf::Vector2f normaliseVecf(const sf::Vector2f & v)
	{
		float l = vecfLength(v);	
		return sf::Vector2f(v.x / l, v.y / l);
	}

	sf::Vector2f vecfMul(const sf::Vector2f & a,const sf::Vector2f & b)
	{
		return sf::Vector2f(a.x * b.x, a.y *b.y);
	}

	sf::Vector2f quantiseVecf(const sf::Vector2f & vec, int quantise_size)
	{
		sf::Vector2i pos((int)vec.x, (int)vec.y);
		return sf::Vector2f((int)(pos.x / quantise_size) * quantise_size, (int)(pos.y / quantise_size) * quantise_size);	
	}

	std::string vecfToString(const sf::Vector2f & v)
	{
		std::stringstream s;
		s << "{x:" << v.x << ",y:" << v.y << "}";
		return  s.str();
	}

	sf::Vector2f vecfFromString(const std::string & s)
	{
		std::string x_s = sub_string("x:", ",", s);
		std::string y_s = sub_string("y:", "}", s);
		int x = atoi(x_s.c_str());
		int y = atoi(y_s.c_str());

		return sf::Vector2f((float)x, (float)y);
	}

	int vecLength(const sf::Vector2i & v)
	{
		return sqrt((v.x * v.x) + (v.y * v.y));
	}

	sf::Vector2i normaliseVec(const sf::Vector2i & v)
	{
		int l = vecLength(v);
		return sf::Vector2i(v.x / l, v.y / l);
	}

	sf::Vector2i vecMul(const sf::Vector2i & a, const sf::Vector2i & b)
	{
		return sf::Vector2i(a.x * b.x, a.y *b.y);
	}

	sf::Vector2i quantiseVec(const sf::Vector2i & vec, int quantise_size)
	{
		sf::Vector2i pos((int)vec.x, (int)vec.y);
		return sf::Vector2i((int)(pos.x / quantise_size) * quantise_size, (int)(pos.y / quantise_size) * quantise_size);
	}

	std::string vecToString(const sf::Vector2i & v)
	{
		std::stringstream s;
		s << "{x:" << v.x << ",y:" << v.y << "}";
		return  s.str();
	}

	sf::Vector2i vecFromString(const std::string & s)
	{
		std::string x_s = sub_string("x:", ",", s);
		std::string y_s = sub_string("y:", "}", s);
		int x = atoi(x_s.c_str());
		int y = atoi(y_s.c_str());

		return sf::Vector2i(x, y);
	}

	//returns the sub string from the specified start + count (vec2f.x + y)
	std::string sub_string(const std::string string, sf::Vector2i positions)
	{
		return string.substr(positions.x, positions.y);
	}


	/*returns the sub string between the two specified sub strings*/
	std::string sub_string(const std::string substr1, const std::string substr2, const std::string data_string)
	{
		return sub_string(data_string, string_dataposition(substr1, substr2, data_string));
	}

	bool string_contains(std::string string, char character)
	{
		if (string.find(character, 0) == -1)
			return false;
		else
			return true;
	}

	bool string_contains(std::string string, std::string  characters)
	{
		for (auto c : characters)
		{
			if (string_contains(string, c))
				return true;
		}
		return false;
	}

	//returns the position of the sub string between the two specified substrings
	sf::Vector2i string_dataposition(const std::string substr1, const std::string substr2, const std::string data_string)
	{
		int start = data_string.find(substr1) + substr1.length();
		return sf::Vector2i(start, data_string.find(substr2) - start);
	}

	bool file_exists(std::string file_name)
	{
		struct stat buf;
		if (stat(file_name.c_str(), &buf) != -1)
		{
			return true;
		}
		return false;
	}

	void fileout(std::string filename, std::string data)
	{
		std::ofstream myfile;
		myfile.open(filename);
		myfile << data;
		myfile.close();
	}

	std::vector<std::string>* filein(std::string filename)
	{
		std::vector<std::string>* vec = new std::vector<std::string>;
		vec->reserve(200);
		std::string line;
		std::ifstream myfile(filename);
		if (myfile.is_open())
		{
			while (std::getline(myfile, line))
			{
				vec->push_back(line);
			}
			myfile.close();
		}
		else
			std::cout << "ERROR: could not open file: " << filename << "\n";
		return vec;
	}

	std::vector<char> filein_binary(std::string filename)
	{		
		if(!file_exists(filename))
		{
			std::cout << "ERROR: could not open file: " << filename << "\n";
			return std::vector<char>;
		}

		std::ifstream myfile(filename, std::ios::binary);
		
		std::vector<char> in(
			(std::istreambuf_iterator<char>(myfile)),
			(std::istreambuf_iterator<char>())
			);
		
		return in;
	}
}
