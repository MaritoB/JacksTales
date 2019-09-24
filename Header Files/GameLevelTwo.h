#ifndef GAME_LEVEL_TWO
#define GAME_LEVEL_TWO
#include "GameState.h"
#include"campeon.h"
#include "TileMap.h"
#include <SFML/Audio/Music.hpp>
#include "TextureManager.h"
#include "GameMainMenu.h"
#include "GameLevelOne.h"
#include "GameOverState.h"
namespace game {


	class GameLevelTwo :public GameState {
		std::string sLevel;
		Campeon* campeon;
		TileMap* map;
		sf::Sprite sprite_backgroundZero[9];
		sf::Sprite sprite_backgroundOne[9];

	public:
		GameLevelTwo(sf::RenderWindow* window);
		void finalize()override;
		GameState* update(sf::RenderWindow* window, float deltaTime) override;
		void initialize(sf::RenderWindow* window)override;
	};

}
#endif