#ifndef STAGE_RESUME
#define STAGE_RESUME
#include "SFML/Graphics.hpp"
#include <string>
namespace game {
	class GameStageResume {
		sf::Text mTimeText;
		sf::Text mEnterText;
		sf::RectangleShape mBackLayer;
		sf::RectangleShape mBossImage;
	public:
		GameStageResume(std::string aTime, sf::Texture* aTexture, sf::Vector2f aPosition, sf::Font& aFont);
		void draw(sf::RenderWindow* aWindow);
	};
}
#endif