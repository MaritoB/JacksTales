#ifndef GAME_SOUND
#define GAME_SOUND
#include <SFML/Audio.hpp>
#include <map>
namespace game {
	class GameSoundManager {
	private:
		static std::map<std::string, sf::SoundBuffer*> mSoundMap;
	public:
		static bool  loadSound(const std::string&);
		static sf::SoundBuffer* getSound(const char* path);
		static bool searchKey(const std::string&  key);
		static void clear();
	};
}
#endif
