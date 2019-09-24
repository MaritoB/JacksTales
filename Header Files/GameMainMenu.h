#ifndef GAME_MAIN_MENU
#define GAME_MAIN_MENU
#include "GameState.h"
#include "GameLevelOne.h"
#include "GameStateManager.h"
#include "TextureManager.h"
#include "Constants.h"
#include "animacion.h"
#include <SFML/Graphics.hpp>
namespace game {
	class GameMainMenu :public GameState {
		sf::Sprite back;
		sf::View* mVista;
		Animacion* mAnimacion;
		sf::RectangleShape mChampionRectangle;
	public:
		GameMainMenu();
		GameState* update(sf::RenderWindow* window, float deltaTime)override;
		void initialize(sf::RenderWindow* window)override;
		void finalize()override;
	};
}

#endif