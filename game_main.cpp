#include "Game.h"

using namespace std;

bool bool_menu = false;
bool titlescreens = true;
int main()
{
	/*
	sf::Music menu_rain;
	menu_rain.openFromFile("rain_sound.wav");
	menu_rain.play();
	menu_rain.setLoop(true);
	*/
	sf::RectangleShape menuShape;

	sf::Font title;
	title.loadFromFile("Championship.ttf");

	sf::RenderWindow okno_gry(sf::VideoMode(1920, 1080), "Cyber Drunk", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);

	okno_gry.setMouseCursorVisible(true);

	//sf::View view(sf::Vector2f(960,540), sf::Vector2f(1920, 1080));

	sf::Event okno;

	sf::Texture protagonist_texture;
	sf::Texture ground_texture;
	sf::Texture city_texture;
	sf::Texture hpbar_texture;

	sf::RectangleShape background;
	sf::RectangleShape ground;

	sf::RectangleShape dmgshape;

	city_texture.loadFromFile("city.png");
	protagonist_texture.loadFromFile("stand&run.png");
	ground_texture.loadFromFile("ground.png");
	hpbar_texture.loadFromFile("hp1.png");

	sf::Texture options_buttons;
	sf::Texture resume_buttons;
	sf::Texture sliver_hand_texture;
	sf::Texture menu_texture;
	sf::Texture play;

	options_buttons.loadFromFile("options_buttons.png");
	resume_buttons.loadFromFile("resume_button.png");
	sliver_hand_texture.loadFromFile("silver_hand.png");
	menu_texture.loadFromFile("menu_rain.png");


	play.loadFromFile("play.png");

	background.setPosition(sf::Vector2f(0, 0));
	background.setSize(sf::Vector2f(1920, 1080));
	background.setTexture(&city_texture);

	ground.setPosition(sf::Vector2f(0, 0));
	ground.setSize(sf::Vector2f(1920, 1080));
	ground.setTexture(&ground_texture);
	

	//needed for collision
	Collider collision(dmgshape);

	protagonis protagonis(&protagonist_texture,&hpbar_texture, sf::Vector2u(8, 2), 0.125f, 300.0f,200.0f);

	//Platforms
	std::vector<Platform> platforms;
	platforms.push_back(Platform(nullptr, sf::Vector2f(1920.0f, 10.0f), sf::Vector2f(900.0f, 1050.0f)));

	//Spikes
	std::vector<Spikes> spikes;
	spikes.push_back(Spikes(&hpbar_texture, sf::Vector2f(400.0f, 400.0f), sf::Vector2f(700.0f, 800.0f)));
	//Na razie zostawiam mo¿e bêdzie potrzebne 
	//Spikes spike1(&hpbar_texture, sf::Vector2f(400.0f, 400.0f), sf::Vector2f(700.0f, 800.0f));


	//clocks
	float deltaTime = 0.0f;
	sf::Clock animation_protag_clock;
	sf::Clock background_clock;
	sf::Clock dmg_clock;

	

	float change = 0;
	float total_time = 0;
	float switch_time = 0.2;
	float dtaTime = 0;

	

	while (okno_gry.isOpen())
	{
		deltaTime = animation_protag_clock.restart().asSeconds();

		//dtaTime = background_clock.restart().asSeconds();
		while (okno_gry.pollEvent(okno))
		{
			switch (okno.type)
			{
			case sf::Event::Closed:
				okno_gry.close();
				break;
			case sf::Event::TextEntered:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					bool_menu = true;
				}
				break;
			}

		}

		okno_gry.clear();
		//protagonis.GetPosition();
		//view.setCenter(protagonis.GetPosition());
		//okno_gry.setView(view);
		if (titlescreens == true)
		{
			sf::Text text;
			text.setFont(title);
			text.setString("PIXELPUNK 2137");
			text.setFillColor(sf::Color::Yellow);
			text.setCharacterSize(250);
			text.setOrigin(-120, -80);

			menuShape.setPosition(sf::Vector2f(0, 0));
			menuShape.setSize(sf::Vector2f(1920, 1080));
			menuShape.setFillColor(sf::Color(0, 0, 0));

			sf::Vector2i position = sf::Mouse::getPosition(okno_gry);
			bool exit = false;
			TitleScreen titlescreen;
			titlescreen.select(position.x, position.y, exit, titlescreens, change, &play, &options_buttons, &sliver_hand_texture);
			if (exit == true)
				okno_gry.close();
			okno_gry.draw(menuShape);
			okno_gry.draw(text);
			titlescreen.Draw(okno_gry);
			okno_gry.display();

		}
		else
		{
			if (bool_menu == true)
			{
				sf::Vector2i position = sf::Mouse::getPosition(okno_gry);
				//menu_rain.pause();
				bool exit = false;

				total_time += deltaTime;

				if (total_time >= switch_time)
				{
					total_time -= switch_time;
					change += 208;
					if (change >= 624)
					{
						change = 0;
					}
				}

				menu option;

				option.option(position.x, position.y, exit, bool_menu, change, &resume_buttons, &options_buttons, &sliver_hand_texture, &menu_texture);
				if (exit == true)
					okno_gry.close();
				option.Draw(okno_gry);
				okno_gry.display();
			}
			else
			{
				

				//collisions
				sf::Vector2f direction;
				Collider protagonisCollision = protagonis.GetCollider();
				sf::Time humanmode = dmg_clock.getElapsedTime();
				sf::Time godmode = sf::seconds(1);

				//ground collision
				for (Platform& platform : platforms)
				{
					if (platform.GetCollider().CheckCollision(protagonisCollision, direction, 1.0f))
					{
						protagonis.OnCollision(direction);
					}
				}
				

				//spikes collision
				for (Spikes& spike : spikes)
				{
					if (spike.GetCollider().CheckCollision(protagonisCollision, direction, 0.0f))
					{
						protagonis.OnCollision(direction);
					}
				}
				//spike1.GetCollider().CheckCollision(protagonisCollision, 0.0f);

				//dmg
				if (humanmode > godmode)
				{
					for (Spikes& spike : spikes)
					{
						collision.CheckDmg(protagonis.body, spike.body, protagonis.hp);
					}
					//collision.CheckDmg(protagonis.body, spike1.body, protagonis.hp);

					dmg_clock.restart();
				}

				//protagonis
				protagonis.Update(deltaTime);
				okno_gry.draw(background);
				protagonis.Draw(okno_gry);
				okno_gry.draw(ground);
				

				//Entities 
				for (Spikes& spike : spikes)
				{
					spike.Draw(okno_gry);
				}
				
				for (Platform& platform : platforms)
				{
					platform.Draw(okno_gry);
				}
				//spike1.Draw(okno_gry);


				okno_gry.display();
			}
		}
	}
	return 0;
}


