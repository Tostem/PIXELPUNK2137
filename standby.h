#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Standby
{
public:
	Standby(sf::Texture* texture, sf::Vector2u imageCount, float switch_time);
	~Standby();

	void Update(int row, float deltaTime, bool faceRight);
public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float total_time = 0;
	float switch_time = 0;
};