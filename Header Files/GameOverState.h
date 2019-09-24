#ifndef GAME_OVER_STATE
#define GAME_OVER_STATE
#include "GameState.h"
#include "GameMainMenu.h"
#include "GameStateManager.h"
#include "TextureManager.h"
#include "Constants.h"
#include "animacion.h"
#include <SFML/Graphics.hpp>
namespace game {
	class GameOverState: public GameState {
		sf::Sprite back;
		sf::View* mVista;
		Animacion* mAnimacion;
		sf::RectangleShape mChampionRectangle;
	public:
		GameState* update(sf::RenderWindow* window, float deltaTime)override;
		void initialize(sf::RenderWindow* window)override;
		void finalize()override;
	};
}
#endif