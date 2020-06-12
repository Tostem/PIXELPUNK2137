#include "protagonis.h"

protagonis::protagonis(sf::Texture* texture,sf::Texture* hp_texture, sf::Vector2u imageCount, float switch_time, float speed,float jumpHeight) :
	standby(texture, imageCount, switch_time)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	hp = 3;

	
	hpbar1.setSize(sf::Vector2f(100.0f, 100.0f));
	hpbar1.setOrigin(0, 0);
	hpbar2.setSize(sf::Vector2f(100.0f, 100.0f));
	hpbar2.setOrigin(-100, 0);
	hpbar3.setSize(sf::Vector2f(100.0f, 100.0f));
	hpbar3.setOrigin(-200, 0);
	hpbar1.setTexture(hp_texture);
	hpbar2.setTexture(hp_texture);
	hpbar3.setTexture(hp_texture);

	body.setSize(sf::Vector2f(150.0f, 280.0f));
	body.setTexture(texture);
	body.setPosition(sf::Vector2f(100.0f, 10.0f));
	body.setOrigin(body.getSize()/2.0f);

}

protagonis::~protagonis()
{

}

void protagonis::Update(float deltaTime)
{
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&canJump)
	{
		canJump = false;

		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	//gravity
	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	standby.Update(row, deltaTime, faceRight);
	body.setTextureRect(standby.uvRect);
	body.move(velocity*deltaTime);
	
}


void protagonis::Draw(sf::RenderWindow& okno_gry)
{
	okno_gry.draw(body);

	if (hp == 3)
	{
		okno_gry.draw(hpbar1);
		okno_gry.draw(hpbar2);
		okno_gry.draw(hpbar3);
	}
	else if (hp == 2)
	{
		okno_gry.draw(hpbar1);
		okno_gry.draw(hpbar2);
	}
	else
	{
		okno_gry.draw(hpbar1);
	}
	
}

void protagonis::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//left collision
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//right collision
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		//bottom collision
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//celling collision
		velocity.y = 0.0f;
	}
}