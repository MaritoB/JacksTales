#ifndef LIFEBAR_H
#define LIFEBAR_H
#include <SFML/Graphics.hpp>
#include "animacion.h"
namespace game {

	class LifeBar
	{
	public:
		LifeBar(sf::Texture* textura, const  sf::Vector2u imageCount, const float switchTime, const float vida);
		~LifeBar();
		void Draw(sf::RenderWindow & window);
		void Update(const float deltaTime, const float vida, sf::Vector2f  posicion, const float size);

	private:
		sf::RectangleShape body;
		Animacion animacion;
		unsigned int row;

	};

}
#endif