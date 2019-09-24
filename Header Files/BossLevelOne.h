#ifndef BOSS_LEVEL_ONE
#define BOSS_LEVEL_ONE
#include "Entidad.h"
#include "campeon.h"
namespace game {
	class BossLevelOne :public Entidad {
	public:

		BossLevelOne(sf::Texture * textura, const sf::Vector2u imageCount, const float switchTime, const float speed,
			const float jumpHeight, const float vel_ataque, const float vida, const sf::Vector2f position);

		void manageHits(std::vector<Proyectil>& balas);
		~BossLevelOne();
		void Draw(sf::RenderWindow & window);
		void Update(const float deltaTime, Campeon & campeon, std::string & sLevel, const float nTileWidth, const float nTileHeight,
			const float nLevelWidth, const float nLevelHeight);
		bool getIsAlive()const { return (vida >= 0); }
	private:
		sf::Clock mBatSpawnClock;
		sf::Clock mRectLineProyectilesClock;
		sf::Clock mHorizontalProyectilesClock;
		sf::Clock mVerticalProyectilesClock;
		sf::RectangleShape mHeart;
		std::vector<Proyectil> mProyectiles;
		sf::Sound mGetHitSound;
		sf::Sound mSpawnSound;
		sf::Sound mDeathSound;
		sf::Sound mFireSound;
	};
}

#endif
