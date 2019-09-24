#ifndef GAME_STATE
#define GAME_STATE
#include <SFML/Graphics.hpp>
namespace game {
	class GameState {
	public:
		virtual GameState* update(sf::RenderWindow* window, float deltaTime) = 0;
		virtual void  initialize(sf::RenderWindow* window)=0;
		virtual void finalize() = 0;
	};
}
#endif
