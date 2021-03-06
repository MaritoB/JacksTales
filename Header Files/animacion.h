#ifndef ANIMATION_H
#define ANIMATION_H
#include<SFML/Graphics.hpp> 
namespace game {

	class Animacion {
	public:
		Animacion(sf::Texture * textura, sf::Vector2u cantImagenes, float switchTime);
		~Animacion();
		void Update(int row, float deltaTime, bool faceRigth, bool attack, bool die);

	public:
		sf::IntRect uvRect;
		bool ataco;
		bool murio;
	
	private:
		sf::Vector2u currentImage;
		sf::Vector2u imageCount;
		float totalTime;
		float switchTime;
	};
}
#endif 