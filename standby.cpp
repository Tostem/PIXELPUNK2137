#include "standby.h"

Standby::Standby(sf::Texture* texture, sf::Vector2u imageCount, float switch_time)
{
	this->imageCount = imageCount;
	this->switch_time = switch_time;
	total_time = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / static_cast<float>(imageCount.x);
	uvRect.height = texture->getSize().y / static_cast<float>(imageCount.y);
}

Standby::~Standby()
{

}

void Standby::Update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	total_time += deltaTime;

	if (total_time >= switch_time)
	{
		total_time -= switch_time;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}


	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}