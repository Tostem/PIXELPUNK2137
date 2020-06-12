#include <iostream>
#include <SFML\Graphics.hpp>
using namespace std;
class menu
{
public:
	void Draw(sf::RenderWindow& okno_gry);
	void option(int x, int y, bool& k, bool& m, float deltaTime, sf::Texture* resume_button, sf::Texture* exit_button, sf::Texture* hand, sf::Texture* background);
	~menu();
private:
	sf::RectangleShape mouse;
	sf::RectangleShape menuShape;
	sf::RectangleShape optionShape;
	sf::RectangleShape optionShape2;


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