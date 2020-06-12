#include <iostream>
#include <SFML\Graphics.hpp>
class TitleScreen
{
public:
	void Draw(sf::RenderWindow& okno_gry);
	void select(int x, int y, bool& k, bool& m, float deltaTime, sf::Texture* resume_button, sf::Texture* exit_button, sf::Texture* hand);
	~TitleScreen();

private:
	sf::RectangleShape mouse;
	sf::RectangleShape optionShape;
	sf::RectangleShape optionShape2;

	sf::Text text;

	float change;

	float optionWidth = 96;
	float optionHeight = 30;

	float menuWidth = 1920;
	float menuHeight = 1080;

	float button_width = (menuWidth - optionWidth) / 2;
	float button_height = (menuHeight - optionHeight) / 2;

	float total_time;
	float switch_time = 0.25;
};