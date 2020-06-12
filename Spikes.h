#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Spikes
{
public:

	Spikes(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Spikes();

	void Draw(sf::RenderWindow& window);

	Collider GetCollider()
	{
		return Collider(body);
	}
	
	sf::RectangleShape body;

};

