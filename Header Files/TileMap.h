#ifndef TILEMAP_H
#define TILEMAP_H
#include"EntityManager.h"
#include <SFML/Graphics.hpp>
#include "campeon.h"
#include "Bat.h"
#include "Demon.h"
#include "Portal.h"
#include "Potion.h"
#include "BossLevelOne.h"
#include <vector>
namespace game {

	class TileMap
	{
	public:
		TileMap(const char* texture, const  unsigned int nLevelWidth, const  unsigned int nLevelHeight, std::string & sLevel, const  unsigned int nTileWidth, const unsigned int nTileHeight);
		void TileMapDraw(sf::RenderWindow & window, const  float deltaTime, Campeon & campeon);
		std::string texture;
		bool isColliding(Collider aA, Collider aB);
		void CheckCollisionTileMap(const float fElapsedTime, sf::RenderWindow & window, Campeon* campeon);

	private:
		sf::RectangleShape body;
		std::vector<Portal>  portals;
		std::vector<Potion>  mPotions;
		std::string & sLevel;
		unsigned int nLevelWidth;
		unsigned int nLevelHeight;
		unsigned int nTileWidth;
		unsigned int nTileHeight;
		sf::RectangleShape Tiles[128 * 9];
		std::vector<sf::RectangleShape> vTiles;
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
		


	};

}
#endif