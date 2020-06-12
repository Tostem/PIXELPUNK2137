#include <SFML/Audio.hpp>
class Music
{
	//funkcje
public:
	void music();
	void on(bool& on);
private:
	sf::Music menu_rain;
	bool isItOn;
};