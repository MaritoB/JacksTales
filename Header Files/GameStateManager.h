#ifndef GAME_STATE_MANAGER
#define GAME_STATE_MANAGER
#include "GameState.h"
namespace game {
	class GameStateManager {
	
	public:
		void deleteState(GameState* aState);
		void initializeState(GameState* aState, sf::RenderWindow* window);
		GameState* executeState(GameState * aState, sf::RenderWindow* window, float deltaTime);


	};
}
#endif
