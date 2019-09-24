#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <map>
#include <string>
#include "SFML/Graphics.hpp"
namespace game
{
	class TextureManager {
	private:
		static std::map<std::string, sf::Texture*> mTextureMap;

	public:
		static bool  loadTexture(const std::string&);
		static sf::Texture* getTexture(const char* path);
		static bool searchKey(const std::string&  key);
		static void clear();
	};

}
#endif