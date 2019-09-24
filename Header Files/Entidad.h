#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
//#include "campeon.h"
#include "animacion.h"
#include "Collider.h"
#include "Constants.h"
#include "Proyectil.h"
#include "TextureManager.h"
#include "GameSoundManager.h"
namespace game {
	class Campeon;
	class Entidad
	{
	public:

		Entidad(sf::Texture* textura, const sf::Vector2u imageCount, const float switchTime,
			const float speed, const float jumpHeight, const float vel_ataque, const float vida);
		virtual ~Entidad();

		virtual void Update(const float deltaTime, Campeon & campeon, std::string & sLevel, const float nTileWidth,
			const float nTileHeight, const float nLevelWidth, const float nLevelHeight) = 0;
		virtual void Draw(sf::RenderWindow & window);
		void onCollision(sf::Vector2f direction);

		void CheckCollisionTileMap(std::string& sLevel, const float fElapsedTime, const float nTileWidth, const float nTileHeight, const float nLevelWidth, const float nLevelHeight);
		void getHurt(const float daño);


		sf::Vector2f GetPosition()const { return body.getPosition(); }
		void setPosition(const sf::Vector2f position) { body.setPosition(position); }
		Collider GetCollider() { return Collider(body); }

		float GetRecuperacion()const { return recuperacion; }
		sf::Vector2f GetVelocity()const { return velocity; }
		void setVelocity(const float velX, const float velY) { velocity.x = velX; velocity.y = velY; }

		bool getAttacking() const { return attacking; }
		void setAttacking(const bool x) { attacking = x; }

		bool getIsDyingAnimationFinished() const { return isDyingAnimationFinished; }
		void setIsDyingAnimationFinished(const bool x) { isDyingAnimationFinished = x; }
		bool getDying() const { return dying; }
		void setDying(const bool x) { dying = x; }

		bool getIsAlive()const { return (vida >0); }
	protected:
		sf::Clock clock_ataque;
		sf::Clock clock_recuperacion;
		sf::Sound* mDeathSound;
		sf::RectangleShape body;
		Animacion animacion;
		unsigned int row;
		bool faceRight;
		float speed;
		float vel_ataque;
		float recuperacion;
		float vida;

		bool isDyingAnimationFinished;

		bool attacking;
		bool dying;

		sf::Vector2f velocity;
		bool canJump;
		float jumpHeight;
	};

}
#endif