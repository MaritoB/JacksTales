#include "../Header Files/GameStateManager.h"
namespace  game {
	void GameStateManager::deleteState(GameState * aState)
	{
		aState->finalize();
		delete aState;
	}
	void GameStateManager::initializeState(GameState * aState, sf::RenderWindow* window)
	{
		aState->initialize(window);
	}
	GameState* GameStateManager::executeState(GameState* aState, sf::RenderWindow* window, float deltaTime) {
		
		GameState* nextState = aState->update(window, deltaTime);
		return nextState;
	}
}
