#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER
#include "Entidad.h"
#include "Demon.h"
#include "BossLevelOne.h"
#include "Bat.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <stdlib.h>
namespace game {
	class Campeon;
	class EntityManager
	{
		public:
			static void addBat(const float aXPosition, const float aYPosition);
			static void addDemon(const float aXPosition, const float aYPosition);
			static void addBoss(const float aXPosition, const float aYPosition);
			static Entidad* getClosestEnemy(const float aXPosition, const float aYPosition);
			static void updateDrawEnemies(const float deltaTime, Campeon & campeon, std::string & sLevel, const float nTileWidth,
				const float nTileHeight, const float nLevelWidth, const float nLevelHeight, sf::RenderWindow & window);
			static void clear();

		private:
			static std::vector<Entidad*> mEnemies;
		};
	}

#endif // !ENTITY_MANAGER

