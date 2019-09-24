#include "..\Header Files\BossLevelOne.h"
#include "../Header Files/EntityManager.h"
#include "../Header Files/ProyectileBehavior.h"
#include "../Header Files/Constants.h"
#include "../Header Files/GameSoundManager.h"
namespace game {
	BossLevelOne::BossLevelOne(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida, sf::Vector2f position) :
		Entidad(textura, imageCount, switchTime, speed, jumpHeight, vel_ataque, vida)
	{
		body.setPosition(position);
		body.setSize(sf::Vector2f(400, 400));
		//body.setScale(1.75f, 1.75f);
		body.setOrigin(body.getSize() / 2.0f);
		mHeart.setSize(sf::Vector2f(70, 100));
		mHeart.setOrigin(mHeart.getSize() / 2.0f);
		isDyingAnimationFinished=true;
		mFireSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mFireSound)));
		mGetHitSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mBossOneGetHitSound)));
		mDeathSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mBossOneDeathSound)));
		mSpawnSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mBossOneSpawnSound)));
		//mHeart.setPosition(body.getOrigin());
	}

	void BossLevelOne::manageHits(std::vector<Proyectil>& balas)
	{
		
		Collider cEnemigo = (Collider)mHeart;
		sf::Vector2f direction;
		direction.x = 0;
		direction.y = 0;

		for (size_t i = 0; i < balas.size(); ++i)
		{
			Proyectil bala = balas[i];
			if (bala.GetCollider().CheckCollision(cEnemigo, direction, 0.0f))
			{
				mGetHitSound.play();
				vida -= bala.getDaño();
				balas.erase(balas.begin() + i);
				if (vida < 1) {
					mDeathSound.play();
				}
		
			}
		}
				
	}

	BossLevelOne::~BossLevelOne()
	{
		mGetHitSound.stop();
		mSpawnSound.stop();
		mDeathSound.stop();
		mProyectiles.clear();
	}

	void BossLevelOne::Draw(sf::RenderWindow & window)
	{
		window.draw(body);
		for (Proyectil& p : mProyectiles)
		{
			p.Draw(window);
		}
		//	window.draw(mHeart);
	}

	void BossLevelOne::Update(const float deltaTime, Campeon & campeon, std::string & sLevel, const float nTileWidth,
		const float nTileHeight, const float nLevelWidth, const float nLevelHeight)
	{
		int heartPosition = 27;
		if (mBatSpawnClock.getElapsedTime().asSeconds() > 6) {
			mSpawnSound.play();
			mBatSpawnClock.restart();
			EntityManager::addBat(16000, 600);
			EntityManager::addBat(16100, 600);
			EntityManager::addBat(15900, 700);

		}
		if (mRectLineProyectilesClock.getElapsedTime().asSeconds() > 4) {
			mFireSound.play();
			mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mBossLevelOneMeteoro),
				sf::Vector2u(1, 1), sf::Vector2f(20, 20), 0.04f, 10.00f, 4.0f, 400.0f, 0,
				campeon.GetPosition(), sf::Vector2f(16000, 600), rectLineBehavior));
			mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mBossLevelOneMeteoro),
				sf::Vector2u(1, 1), sf::Vector2f(20, 20), 0.04f, 10.00f, 4.0f, 400.0f, 0,
				campeon.GetPosition(), sf::Vector2f(16000, 700), rectLineBehavior));
			mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mBossLevelOneMeteoro),
				sf::Vector2u(1, 1), sf::Vector2f(20, 20), 0.04f, 10.00f, 4.0f, 400.0f, 0,
				campeon.GetPosition(), sf::Vector2f(16000, 800), rectLineBehavior));
			mRectLineProyectilesClock.restart();
		}
		if (mHorizontalProyectilesClock.getElapsedTime().asSeconds() > 5) {
			mFireSound.play();
			mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mBossLevelOneMeteoro),
				sf::Vector2u(1, 1), sf::Vector2f(40, 40), 0.04f, 10.00f, 4.0f, 400.0f, 0,
				sf::Vector2f(10000, 580), sf::Vector2f(16000, 580), rectLineBehavior));
			mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mBossLevelOneMeteoro),
				sf::Vector2u(1, 1), sf::Vector2f(40, 40), 0.04f, 10.00f, 4.0f, 400.0f, 0,
				sf::Vector2f(10000, 850), sf::Vector2f(16000, 850), rectLineBehavior));
			mHorizontalProyectilesClock.restart();
		}
		if (mVerticalProyectilesClock.getElapsedTime().asSeconds() > 3) {
			mFireSound.play();
			mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mBossLevelOneMeteoro),
				sf::Vector2u(1, 1), sf::Vector2f(15, 15), 0.04f, 10.00f, 4.0f, 600.0f, 0,
				sf::Vector2f(15300, 1920), sf::Vector2f(15300, 200), rectLineBehavior));
			mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mBossLevelOneMeteoro),
				sf::Vector2u(1, 1), sf::Vector2f(15, 15), 0.04f, 10.00f, 4.0f, 600.0f, 0,
				sf::Vector2f(15600, 1920), sf::Vector2f(15500, 200),
				rectLineBehavior));
			mVerticalProyectilesClock.restart();
		}
		if (abs(campeon.GetPosition().x - body.getPosition().x) > 20 ) {
			if(campeon.GetPosition().x < body.getPosition().x){
				//velocity.x = -200;
				faceRight = false;
				mHeart.setPosition(body.getPosition().x + heartPosition, body.getPosition().y - 40);
			}
			else
			{
				//velocity.x = 200;
				faceRight = true;
				heartPosition *= -1;
				mHeart.setPosition(body.getPosition().x + heartPosition, body.getPosition().y - 40);
			}
		}
		velocity.y = 20;
		CheckCollisionTileMap(sLevel, deltaTime, nTileWidth, nTileHeight, nLevelWidth, nLevelHeight);
		manageHits(campeon.getBalas());
		if (vida < 1) {
			campeon.setWinLevel(true);
		}
		for (size_t i = 0; i < mProyectiles.size(); ++i)
		{
			//Collider a = campeon.GetCollider();
			mProyectiles[i].Update(deltaTime);
			mProyectiles[i].getBody().rotate(50);
			if (mProyectiles[i].GetCollider().CheckCollision(campeon.GetCollider(), sf::Vector2f(0,0), 0.0f))
			{
				mProyectiles[i].addCountBounce();
				campeon.getHurt(mProyectiles[i].getDaño());
				if (mProyectiles[i].getCountBounces() > mProyectiles[i].getNumberBounces()) {
					mProyectiles.erase(mProyectiles.begin() + i);
				}
			}
		}
		
		animacion.Update(row, deltaTime, faceRight, false, false);
		body.setTextureRect(animacion.uvRect);
		body.move(velocity * deltaTime);
	}
}
