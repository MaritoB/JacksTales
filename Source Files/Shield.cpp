#include"../Header Files/Shield.h"
namespace game {
	Shield::Shield(sf::Texture * textura, const sf::Vector2u imageCount, sf::Vector2f aSize, const float switchTime):
		mAnimation(textura, imageCount, switchTime)
	{
		mBody.setTexture(textura);
		mBody.setSize(aSize);
		mBody.setOrigin(mBody.getSize() / 2.0f);
	}

	void Shield::Draw(sf::RenderWindow & window)
	{
		window.draw(mBody);
	}
	void Shield::update(sf::Vector2f aPosition, const float deltaTime)
	{
		mBody.setPosition(aPosition);
		mAnimation.Update(0, deltaTime, true, false, false);
		mBody.setTextureRect(mAnimation.uvRect);		
	}
}