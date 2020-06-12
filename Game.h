#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "protagonis.h"
#include "menu.h"
#include "Music.h"
#include "Collider.h"
#include "Spikes.h"
#include "Platform.h"
#include "TitleScreen.h"
#include <string>
#include <algorithm>
#include <vector>

class Game
{
private:
	//zmienne
	sf::RenderWindow* okno_gry;
	sf::Event okno;

	void initWindow();

public:
	virtual ~Game();
	Game();

	//Funkcje
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};