#ifndef GAME_WINDOW
#define GAME_WINDOW
#include <SFML/Graphics.hpp>
#include "GameStateManager.h"
namespace game {
	class GameWindow {
		private:
			sf::View* mView;
			sf::RenderWindow* mWindow;
		public:
			void ResizedView();
			void intialize();
			sf::RenderWindow* getWindow() { return mWindow; }
			sf::View* getView() { return mView; }
	};

}
#endif