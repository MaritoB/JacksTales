#include "../Header Files/GameLoop.h"
#include "../Header Files/EntityManager.h"
#include "../Header Files/GameSoundManager.h"


void game::GameLoop::run()
{
	GameStateManager mGameStateManager;
	GameWindow mGameWindow;
	mGameWindow.intialize();
	sf::RenderWindow * mWindow = mGameWindow.getWindow();
	GameMusicManager mMusicManager;
	mMusicManager.initialize();
	mMusicManager.playMusic();
	GameState * currentState = new GameMainMenu;
	currentState->initialize(mWindow);
	sf::Clock reloj;
	float deltaTime = 0;
	while (mWindow->isOpen())
	{
		deltaTime = reloj.restart().asSeconds();
		sf::Event evento;
		while (mWindow->pollEvent(evento))
		{
			switch (evento.type)
			{
			case sf::Event::Closed:
				mWindow->close();
				break;
			case sf::Event::Resized:
				mGameWindow.ResizedView();
				break;
			}
		}
		GameState * previousState = currentState;
		currentState = mGameStateManager.executeState(currentState, mWindow, deltaTime);
		if (previousState != currentState) {
			mGameStateManager.deleteState(previousState);
			EntityManager::clear();
			//GameSoundManager::clear();
			mGameStateManager.initializeState(currentState, mWindow);

		}
	}
}
