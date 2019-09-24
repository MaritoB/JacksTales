#include "../Header Files/TextureManager.h"
//#include <map>
#include <cassert>
namespace game {

	std::map<std::string, sf::Texture*> TextureManager::mTextureMap = std::map<std::string, sf::Texture*>();

	bool TextureManager::loadTexture(const std::string & path)
	{
		if (TextureManager::searchKey(path)) {
			return false;
		}
		std::pair<std::map<std::string, sf::Texture*>::iterator, bool> r;
		sf::Texture* mTexture = new sf::Texture;
		bool isLoaded = mTexture->loadFromFile(path);
		assert(isLoaded);
		r = mTextureMap.insert(std::pair<std::string,sf::Texture* >(path, mTexture));
		assert(r.second);
		return r.second && isLoaded;
	}

	sf::Texture* TextureManager::getTexture(const char* path)  
	{
		std::map<std::string, sf::Texture*>::const_iterator it = mTextureMap.find(path);
		return it != mTextureMap.end() ? it->second : nullptr;
	}

	bool TextureManager::searchKey(const std::string&  path)
	{
		std::map<std::string, sf::Texture*>::const_iterator it = mTextureMap.find(path);
		return it != mTextureMap.end();
	}

	void TextureManager::clear()
	{
		std::map<std::string, sf::Texture*>::iterator it = mTextureMap.begin();
		for (; it != mTextureMap.end();) {
			it->second->~Texture();
			std::string toErase = it->first;
			++it;
			mTextureMap.erase(toErase);
		}
	}

}
