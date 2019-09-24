#include "GameStageResume.h"
#include "..\Header Files\GameStageResume.h"
#include <iostream>
namespace game {
	GameStageResume::GameStageResume(std::string aTime, sf::Texture * aTexture, sf::Vector2f aPosition, sf::Font & aFont) :
		mTimeText(aTime, aFont)
	{
		mTimeText.setPosition(aPosition.x+20, aPosition.y- 100 );
		//mTimeText.setScale(, );
		//mTimeText.setCharacterSize(72);
		mTimeText.setString("Time: "+ aTime + "\n" + "\n" +"Press Enter");
		mTimeText.setStyle(sf::Text::Bold);
		mTimeText.setFillColor(sf::Color::White);;
		mBackLayer.setFillColor(sf::Color(100,20,20));
		mBossImage.setTexture(aTexture);
		mBackLayer.setPosition(aPosition.x - 200, aPosition.y - 300);
		mBackLayer.setSize(sf::Vector2f(600, 400));
		mBossImage.setPosition(aPosition.x-200, aPosition.y - 300 );
		mBossImage.setSize(sf::Vector2f(200, 400));

	}

	void GameStageResume::draw(sf::RenderWindow * aWindow)
	{
		//std::cout << "DIBUJANDO: "<< mBackLayer.getPosition().x <<" Y: "<< mBackLayer.getPosition().y<< std::endl;
			//aWindow->clear();
			aWindow->draw(mBackLayer);
			aWindow->draw(mBossImage);
			aWindow->draw(mTimeText);

	}
}


