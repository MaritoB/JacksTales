#ifndef SHIELD
#define SHIELD
#include "SFML/Graphics.hpp"
#include "animacion.h"
namespace game {
	class Shield {
		sf::RectangleShape mBody;
		Animacion mAnimation;
		unsigned int row;
	public:
		Shield(sf::Texture* textura, const  sf::Vector2u imageCount, sf::Vector2f aSize, const float switchTime);
		void update(sf::Vector2f aPosition, const float deltaTime);
		void Draw(sf::RenderWindow & window);
	};
}
#endif