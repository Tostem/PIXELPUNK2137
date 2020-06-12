#include "menu.h"
void menu::Draw(sf::RenderWindow& okno_gry)
{
	okno_gry.draw(menuShape);
	okno_gry.draw(optionShape);
	okno_gry.draw(optionShape2);
	okno_gry.draw(mouse);
}

void menu::option(int x, int y, bool& k, bool& m, float deltaTime, sf::Texture* resume_button, sf::Texture* exit_button, sf::Texture* hand, sf::Texture* background)
{


	mouse.setSize(sf::Vector2f(34.0f, 22.0f));
	mouse.setTexture(hand);
	mouse.setPosition((x)-34.0f, (y)-22.0f);

	menuShape.setPosition(sf::Vector2f(0, 0));
	menuShape.setSize(sf::Vector2f(menuWidth, menuHeight));
	menuShape.setTexture(background);
	menuShape.setTextureRect(sf::IntRect(deltaTime, 0, 208, 117));

	optionShape2.setSize(sf::Vector2f(optionWidth, optionHeight));
	optionShape2.setPosition(sf::Vector2f(button_width, button_height - 30));
	optionShape2.setTexture(resume_button);

	optionShape.setSize(sf::Vector2f(optionWidth, optionHeight));
	optionShape.setPosition(sf::Vector2f(button_width, button_height + 30));
	optionShape.setTexture(exit_button);

	if ((x >= button_width) && (x <= (button_width + optionWidth)) && ((y >= button_height - 30) && (y <= button_height + optionHeight - 30)))
	{
		optionShape2.setOutlineColor(sf::Color::Red);
		optionShape2.setOutlineThickness(5);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m = false;
		}
	}

	if ((x >= button_width) && (x <= (button_width + optionWidth)) && ((y >= button_height + 30) && (y <= button_height + optionHeight + 30)))
	{
		optionShape.setOutlineColor(sf::Color::Red);
		optionShape.setOutlineThickness(5);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			k = true;
		}
	}
}

menu::~menu()
{

}