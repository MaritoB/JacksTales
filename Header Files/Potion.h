#ifndef POTION
#define POTION
#include "SFML/Graphics.hpp"
#include "Collider.h"
namespace game{
	class Campeon;
	class Potion
	{
		sf::RectangleShape mBody;
		float mLifeRecover;
		float mManaRecover;
		bool mIsUsed;

	public:
		Potion(sf::Texture* aTexture,sf::Vector2f aSize ,const float aLifeRecover, const float aManaRecover, sf::Vector2f aPosition);
		void update();
		void draw(sf::RenderWindow & window);
		void use(Campeon* aChampion);
		bool getIsUsed()const {return mIsUsed;}
		Collider GetCollider() { return Collider(mBody); }
	};
}
#endif
