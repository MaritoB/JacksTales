#include "../Header Files/Potion.h"
#include "../Header Files/campeon.h"
namespace game {
	Potion::Potion(sf::Texture * aTexture, sf::Vector2f aSize, const float aLifeRecover, const float aManaRecover, sf::Vector2f aPosition) :
		mLifeRecover(aLifeRecover),
		mManaRecover(aManaRecover),
		mIsUsed(false)
	{
		mBody.setTexture(aTexture);
		mBody.setSize(aSize);
		mBody.setPosition(aPosition);
		mBody.setOrigin(mBody.getSize() / 2.0f);
	}

	void Potion::update()
	{
		mBody.rotate(25);
	}
	void Potion::draw(sf::RenderWindow & window)
	{
		window.draw(mBody);
	}
	void Potion::use(Campeon* aChampion)
	{
		aChampion->setCurrentMana(aChampion->getCurrentMana() + mManaRecover);
		aChampion->setCurrentLife(aChampion->getCurrentLife() + mLifeRecover);
		mIsUsed = true;
	}
}
