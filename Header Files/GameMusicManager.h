#ifndef GAME_MUSIC
#define GAME_MUSIC
#include <SFML/Audio/Music.hpp>
namespace game {
	class GameMusicManager {
		sf::Music mMusic;
	public:
		void initialize();
		void playMusic();
	};
}
#endif
