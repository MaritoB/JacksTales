#include "../Header Files/GameSoundManager.h"
#include "../Header Files/Constants.h"
#include <cassert>
namespace game{

	std::map<std::string, sf::SoundBuffer*> GameSoundManager::mSoundMap = std::map<std::string, sf::SoundBuffer*>();
	
	bool GameSoundManager::loadSound(const std::string & path)
	{
		if (GameSoundManager::searchKey(path)) {
			return false;
		}
		std::pair<std::map<std::string, sf::SoundBuffer*>::iterator, bool> r;
		sf::SoundBuffer* mSoundBuffer = new sf::SoundBuffer;
		bool isLoaded = mSoundBuffer->loadFromFile(path);
		assert(isLoaded);
		r = mSoundMap.insert(std::pair<std::string, sf::SoundBuffer* >(path, mSoundBuffer));
		assert(r.second);
		return r.second && isLoaded;
	}

	sf::SoundBuffer* GameSoundManager::getSound(const char* path)
	{
		std::map<std::string, sf::SoundBuffer*>::const_iterator it = mSoundMap.find(path);
		return it != mSoundMap.end() ? it->second : nullptr;
	}

	bool GameSoundManager::searchKey(const std::string&  path)
	{
		std::map<std::string, sf::SoundBuffer*>::const_iterator it = mSoundMap.find(path);
		return it != mSoundMap.end();
	}

	void GameSoundManager::clear()
	{
		std::map<std::string, sf::SoundBuffer*>::iterator it = mSoundMap.begin();
		for (; it != mSoundMap.end();) {
			it->second->~SoundBuffer();
			std::string toErase = it->first;
			++it;
			mSoundMap.erase(toErase);
		}
	}

}
