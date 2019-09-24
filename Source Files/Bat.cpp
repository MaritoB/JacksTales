#include "../Header Files/Bat.h"
#include "../Header Files/campeon.h"
#include <iostream>
namespace game {

	Bat::Bat(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed,
		float jumpHeight, float vel_ataque, float vida, sf::Vector2f position) :
		Entidad(textura, imageCount, switchTime, speed, jumpHeight, vel_ataque, vida)
	{
		mDeathSound = new sf::Sound(*(GameSoundManager::getSound(game_constants::Constants::mBatDeathSound)));
		body.setPosition(position);
		body.setSize(sf::Vector2f(32, 32));
		body.setOrigin(body.getSize() / 2.0f);
		body.setScale(2, 2);
		setDying(false);
		setIsDyingAnimationFinished(false);
	}


	Bat::~Bat()
	{

	}

	void Bat::procesarGolpearCampeon(Campeon& campeon){
		if (campeon.GetCollider().CheckCollision(GetCollider(), sf::Vector2f(0,0), 1.0f)){
			campeon.getHurtRecovery(10.0f);
		}
	}

	void Bat::procesarImpactos(std::vector<Proyectil>& balas){
		for (size_t i = 0; i < balas.size(); ++i){
			if (balas[i].GetCollider().CheckCollision(GetCollider(), sf::Vector2f(0,0), 0.0f)){				
				balas[i].addCountBounce();
				vida -= balas[i].getDaño();
				if (balas[i].getCountBounces() > balas[i].getNumberBounces()) {
					balas.erase(balas.begin() + i);
				}
				if (vida < 1) {
					mDeathSound->play();
					return;
				}
			}
		}
	}

	void Bat::Update(const float deltaTime, Campeon& campeon, std::string & sLevel,
		const float nTileWidth, const float nTileHeight, const float nLevelWidth, const float nLevelHeight)
	{
		bool morir = false;

		if (abs(campeon.GetPosition().x - body.getPosition().x) < 30) {
			row = 8;
		}
		else {
			if (campeon.GetPosition().x < body.getPosition().x){
				velocity.x = -speed;
			}else{
				velocity.x = +speed;
			}
			if ((campeon.GetPosition().y - 200) < body.getPosition().y) {
				velocity.y = -speed;
			}				
		}
		if (abs(campeon.GetPosition().x - body.getPosition().x) < 200){
			if (campeon.GetPosition().y > body.getPosition().y){
				velocity.y = speed * 1.50f;
			}else{
				velocity.y = -speed;
			}
		}
		CheckCollisionTileMap(sLevel, deltaTime, nTileWidth, nTileHeight, nLevelWidth, nLevelHeight);
		if (velocity.x == 0.0f){
			row = 5;
		}else{
			row = 7;
			if (velocity.x > 0.0f)
				faceRight = false;
			else
				faceRight = true;
		}
		if (vida <= 0){
			velocity.x = 0;
			velocity.y = 30;
			setDying(true);
			morir = true;
			row = 9;
			if (animacion.murio == true){
				setIsDyingAnimationFinished(true);
			}
		}else{
			procesarImpactos(campeon.getBalas());
			procesarGolpearCampeon(campeon);
		}
		animacion.Update(row, deltaTime, faceRight, false, morir);
		body.setTextureRect(animacion.uvRect);
		body.move(velocity * deltaTime);
		//
	}

}