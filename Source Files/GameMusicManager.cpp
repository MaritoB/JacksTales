#include "../Header Files/GameMusicManager.h"
#include "../Header Files/Constants.h"
void game::GameMusicManager::initialize()
{
	mMusic.openFromFile(game_constants::Constants::mLevelOneMusic);
	mMusic.setVolume(40);
}

void game::GameMusicManager::playMusic()
{
	mMusic.play();
	mMusic.setLoop(true);
}
