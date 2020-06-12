#include <SFML\Graphics.hpp>
#include "standby.h"
#include "Collider.h"

class protagonis
{
public:
	protagonis(sf::Texture* texture,sf::Texture* hp_texture, sf::Vector2u imageCount, float switch_time, float speed,float jumpHeight);
	~protagonis();

	
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& okno_gry);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition() { return body.getPosition(); }

	Collider GetCollider()
	{
		return Collider(body);
	}


	int hp;
	sf::RectangleShape hpbar1;
	sf::RectangleShape hpbar2;
	sf::RectangleShape hpbar3;
	sf::RectangleShape body;
private:

	

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	Standby standby;
	unsigned int row;
	float speed;
	bool faceRight;
};