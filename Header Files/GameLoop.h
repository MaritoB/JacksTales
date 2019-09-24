#ifndef GAME_LOOP
#define GAME_LOOP
#include "GameState.h"
#include "GameMainMenu.h"
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "GameMusicManager.h"
namespace game {
	class GameLoop {
	public:
		void run();
	};
}
#endif

