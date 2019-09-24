#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>
namespace game {

	class Collider
	{
	public:
		Collider(sf::RectangleShape& body);
		~Collider();

		void Move(const float dx, const float dy) { body.move(dx, dy); }

		bool CheckCollision(Collider other, sf::Vector2f direction, float push);
		sf::Vector2f GetPosition() const { return  body.getPosition(); }
		sf::Vector2f GetHalfSize() const { return  body.getSize() / 2.0f; }

	private:
		sf::RectangleShape& body;

	};

}
#endif