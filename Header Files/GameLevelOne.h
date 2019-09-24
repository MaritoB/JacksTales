#ifndef GAME_LEVEL_ONE
#define GAME_LEVEL_ONE
#include "GameState.h"
#include"campeon.h"
#include "TileMap.h"
#include <SFML/Audio/Music.hpp>
#include "TextureManager.h"
#include "GameMainMenu.h"
#include "GameLevelOne.h"
#include "GameOverState.h"
#include "GameLevelTwo.h"
#include "GameStageResume.h"
namespace game {		
	class GameLevelOne:public GameState {
		std::string sLevel;
		Campeon* campeon;
		TileMap* map;
		sf::Sprite sprite_backgroundZero[9];
		sf::Sprite sprite_backgroundOne[9];
		sf::Font mFont;
		sf::Clock mCronometer;
		std::string  mCronometerText;
		sf::Font mArialFont;
		GameStageResume* mResume;
	public:
		GameLevelOne(sf::RenderWindow* window);
		void finalize()override;
		GameState* update(sf::RenderWindow* window, float deltaTime) override;
		void initialize(sf::RenderWindow* window)override;
	};
}
#endif