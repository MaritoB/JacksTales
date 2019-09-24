#include "GameOverState.h"
namespace game {

	GameState* GameOverState::update(sf::RenderWindow* window, float deltaTime)
	{
		window->clear();
		window->draw(back);
		mAnimacion->Update(2, deltaTime, false, false, false);
		mChampionRectangle.setTextureRect(mAnimacion->uvRect);
		window->setView(*mVista);
		window->draw(mChampionRectangle);
		window->display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			GameState* gamePtr = new GameMainMenu();
			return gamePtr;

		}
		return this;
	}
	void GameOverState::initialize(sf::RenderWindow * window)
	{
		TextureManager::loadTexture(game_constants::Constants::mDemonTexture);
		TextureManager::loadTexture("Textures/GameOverBack.png");
		back.setTexture(*(TextureManager::getTexture("Textures/GameOverBack.png")));
		mAnimacion = new Animacion(TextureManager::getTexture(game_constants::Constants::mDemonTexture), sf::Vector2u(10, 4), 0.1f);
		mVista = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800, 600));
		back.setPosition(-450, -300);

		mChampionRectangle.setSize(sf::Vector2f(64, 64));
		mChampionRectangle.setOrigin(mChampionRectangle.getSize() / 2.0f);
		mChampionRectangle.setTexture(TextureManager::getTexture(game_constants::Constants::mDemonTexture));
		mChampionRectangle.setPosition(300, 135);
		mChampionRectangle.setScale(3, 3);
	}
	void GameOverState::finalize()
	{
		delete mVista;
		TextureManager::clear();
	}
}