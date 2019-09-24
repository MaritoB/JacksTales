#include "../Header Files/GameWindow.h"

namespace game {

	void GameWindow::ResizedView()
	{
		float aspectRatio = float(mWindow->getSize().x / float(mWindow->getSize().y));
	}
	void GameWindow::intialize()
	{
		//mWindow = new sf::RenderWindow (sf::VideoMode(800, 600), "Juego", sf::Style::Close | sf::Style::Resize);
		//mWindow = new sf::RenderWindow(sf::VideoMode::getDesktopMode() , "Jack's Tales", sf::Style::Fullscreen);
		mWindow = new sf::RenderWindow(sf::VideoMode(1366,768), "Jack's Tales", sf::Style::Close);
	//	mWindow->setVerticalSyncEnabled(true);
		mView = new sf::View (sf::Vector2f(0.0f, 0.0f), sf::Vector2f(mWindow->getSize().x, mWindow->getSize().y) );
		mView->zoom(0.75f);
		mWindow->setView(*mView);
		mWindow->setFramerateLimit(60);
		

	}
}
