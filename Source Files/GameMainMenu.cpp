#include "../Header Files/GameMainMenu.h"

namespace game {
	GameMainMenu::GameMainMenu()
	{
	}
	GameState* GameMainMenu::update(sf::RenderWindow* window, float deltaTime)
	{
		window->clear();
		window->draw(back);
		mAnimacion->Update(0, deltaTime, true, false, false);
		mChampionRectangle.setTextureRect(mAnimacion->uvRect);
		window->setView(*mVista);
		window->draw(mChampionRectangle);
		window->display();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				GameState* gamePtr = new GameLevelOne(window);
				return gamePtr;

			}
			return this;
	}
	void GameMainMenu::initialize(sf::RenderWindow * window)
	{

		TextureManager::loadTexture(game_constants::Constants::mJackTexture);
		TextureManager::loadTexture("Textures/MainMenuBack.png");
		back.setTexture(*(TextureManager::getTexture("Textures/MainMenuBack.png")));
		mAnimacion = new Animacion(TextureManager::getTexture(game_constants::Constants::mJackTexture), sf::Vector2u(10, 6), 0.07f);
		mVista = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800, 600));
		back.setPosition(-450, -300);

		mChampionRectangle.setSize(sf::Vector2f(64, 64));
		mChampionRectangle.setOrigin(mChampionRectangle.getSize() / 2.0f);
		mChampionRectangle.setTexture(TextureManager::getTexture(game_constants::Constants::mJackTexture));
		mChampionRectangle.setPosition(-300, 135);
		mChampionRectangle.setScale(5, 5);
	}
	void GameMainMenu::finalize()
	{
		delete mVista;
		TextureManager::clear();
		//GameSoundManager::clear();
	}
	/*
	void GameMainMenu::changeState()
	{
		delete mVista;
		TextureManager::clear();
		

	}
	*/

}
