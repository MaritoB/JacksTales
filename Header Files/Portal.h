#ifndef PORTAL_H
#define PORTAL_H

#include <SFML/Graphics.hpp>
#include "animacion.h"
#include "Collider.h"
namespace game {

	class Portal
	{
	public:
		Portal(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
		~Portal();

		void Update(float deltaTime);
		void Draw(sf::RenderWindow & window);
		Collider GetCollider() { return Collider(body); }

	private:
		Animacion animacion;
		unsigned int row;
		bool faceRight;

		sf::RectangleShape body;

	};

}
#endif