#include "../Header Files/Demon.h"
#include "../Header Files/campeon.h"
#include "../Header Files/ProyectileBehavior.h"
#include "../Header Files/GameSoundManager.h"
#include "../Header Files/Constants.h"
namespace game {


	Demon::Demon(sf::Texture * textura, sf::Vector2u imageCount,
		float switchTime, float speed, float jumpHeight, float vel_ataque, float vida, sf::Vector2f position) :
		Entidad(textura, imageCount, switchTime, speed, jumpHeight, vel_ataque, vida),
		canFireballSound(true)
	{
		body.setPosition(position);
		body.setSize(sf::Vector2f(100, 100));
		body.setOrigin(body.getSize() / 2.0f);
		setIsDyingAnimationFinished(false);
		mFireSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mFireBall3Sound)));
		mDeathSound = new sf::Sound(*(GameSoundManager::getSound(game_constants::Constants::mDemonDeathSound)));
		mDeathSound->setVolume(50);
		mFireSound.setVolume(40);
	}
	void Demon::Update(const float deltaTime, Campeon & campeon, std::string & sLevel, const float nTileWidth, const float nTileHeight,
		const float nLevelWidth, const float nLevelHeight)
	{
		bool atacar = false;
		bool morir = false;
		velocity.y = 40;

		if (campeon.GetPosition().x < body.getPosition().x)
		{
			velocity.x = -speed;
			faceRight = false;
		}
		else
		{
			velocity.x = +speed;
			faceRight = true;
		}
		if (vida > 0)
		{
			row = 1;
			if ((abs(campeon.GetPosition().x - body.getPosition().x) < 250) && abs(campeon.GetPosition().y - body.getPosition().y) < 300)
			{
				velocity.x = 0.0f;
				row = 2;
				disparar(campeon.GetPosition());
				if (canFireballSound) {
					mFireSound.play();
					canFireballSound = false;
				}
			}
			else {
				canFireballSound = true;
			}
			procesarImpactos(campeon.getBalas());
			procesarGolpearCampeon(campeon);
		}
		else
		{
			velocity.x = 0;
			morir = true;
			row = 3;
			mFireSound.stop();
			if (animacion.murio == true)
			{
				setIsDyingAnimationFinished(true);
			}	
		}
		CheckCollisionTileMap(sLevel, deltaTime, nTileWidth, nTileHeight, nLevelWidth, nLevelHeight);
		for (Proyectil& bala : mProyectiles)
		{
			if (bala.getIsAlive())
			{
				bala.Update(deltaTime);
			}
		}
		 

		animacion.Update(row, deltaTime, faceRight, atacar, morir);
		body.setTextureRect(animacion.uvRect);
		body.move(velocity * deltaTime);
	}

	void Demon::disparar(sf::Vector2f posicion)
	{
		if (clock_ataque.getElapsedTime().asSeconds() > vel_ataque)
		{
			mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mDemonFireBallTexture),
				sf::Vector2u(10, 1), sf::Vector2f(16, 8), 0.02f, 0.7f, 1.30f, 300.0f, 0,
				(sf::Vector2f)posicion, body.getPosition(),
				rectLineBehavior));
			clock_ataque.restart();
		}
	}

	void Demon::procesarImpactos(std::vector<Proyectil>& balas)
	{
		//Collider cEnemigo = GetCollider();
		for (size_t i = 0; i < balas.size(); ++i){
			if (balas[i].GetCollider().CheckCollision(GetCollider(), sf::Vector2f(0.0f,0.0f), 0.0f)){
				vida -= balas[i].getDaño();
				balas.erase(balas.begin() + i);
				if (vida < 1){
					mDeathSound->play();
				}
			}
		}
	}
	void Demon::procesarGolpearCampeon(Campeon & campeon)
	{
		Collider cCampeon = campeon.GetCollider();
		sf::Vector2f direction;
		for (size_t i = 0; i < mProyectiles.size(); ++i)
		{
			if (mProyectiles[i].GetCollider().CheckCollision(cCampeon, direction, 0.0f))
			{
				if (!campeon.getIsShieldActivated()) {
					campeon.setCurrentLife(campeon.getCurrentLife() - mProyectiles[i].getDaño());
					mProyectiles.erase(mProyectiles.begin() + i);
				}
			}
		}

	}
	void Demon::Draw(sf::RenderWindow & window)
	{
		window.draw(body);
		for (size_t i = 0; i < mProyectiles.size(); ++i)
		{
			if (mProyectiles[i].getIsAlive()==false || mProyectiles[i].eliminar())
			{
				mProyectiles.erase(mProyectiles.begin() + i);
			}
			else {
				mProyectiles[i].Draw(window);
			}
		}
	}


	Demon::~Demon()
	{
		mDeathSound->stop();
		mFireSound.stop();
		mProyectiles.clear();
	}
}