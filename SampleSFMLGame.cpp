/*#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
	sf::RenderWindow window{ {800,600}, "Dupa" };

	while (window.isOpen())
	{
		sf::Event windowEvent;
		while(window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Blue);
		window.display();
	}
}*/

