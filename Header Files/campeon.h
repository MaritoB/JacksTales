#ifndef CAMPEON_H
#define CAMPEON_H
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include "animacion.h"
#include "Collider.h"
#include "Proyectil.h"
#include "Constants.h"
#include "EntityManager.h"
#include "Shield.h"

namespace game {
	class Campeon
	{

	public:
		Campeon(sf::Texture* textura, const sf::Vector2u imageCount, const float switchTime, const float speed, const float jumpHeight, const float vel_ataque, const float vida);
		~Campeon();

		void inputHandler(sf::RenderWindow & window);

		void Update(const float deltaTime, sf::RenderWindow & window);
		void Draw(sf::RenderWindow & window);

		void onCollision(const sf::Vector2f direction);
		void castLightningSkill();
		void disparar(const sf::Vector2i posicion);
		void dash();
		void getHurt(const float daño);
		void getHurtRecovery(const float daño);
		sf::Vector2i procesarMouse(sf::RenderWindow & window);
		sf::Vector2f GetPosition() const { return body.getPosition(); }
		void setPosition(const  sf::Vector2f position) { body.setPosition(position); }
		bool getIsAlive()const { return isAlive; }
		void setIsAlive(const bool x) { isAlive = x; }
		void setCanJump(const bool x) { canJump = x; }
		void setCanSecondJump(const bool x) { canJump = x; }
		Collider GetCollider() { return Collider(body); }
		sf::RectangleShape getBody() { return body; }
		sf::Clock GetClockRecuperacion() const { return clock_recuperacion; }
		float GetRecuperacion() const { return recuperacion; }
		sf::Vector2f GetVelocity() const { return velocity; }
		void setVelocity(const float velX, const  float velY) { velocity.x = velX; velocity.y = velY; }
		std::vector<Proyectil>& getBalas() { return  mProyectiles; }
		float getCurrentLife() const { return mCurrentLife; }
		void setCurrentLife(const float x) { 
			mCurrentLife = x;
			if (mCurrentLife > mMaximumLife) {
				mCurrentLife = mMaximumLife;
			}
		}
		float getCurrentMana() const { return mCurrentMana; }
		void setCurrentMana(const float x) {
			mCurrentMana = x; 
			if (mCurrentMana > mMaximumMana) {
				mCurrentMana = mMaximumMana;
			}
		}
		float getMaximumMana() const { return mMaximumMana; }
		void setMaximumMana(const float x) { mMaximumMana = x; }
		bool getIsShieldActivated() const { return isShieldActivated; }
		void setIsShieldActivated(const bool x) { isShieldActivated = x; }
		bool getAttacking() const { return attacking; }
		void setAttacking(const bool x) { attacking = x; }

		bool getDying() const { return dying; }
		void setDying(const bool x) { dying = x; }

		bool getWinLevel() const { return winLevel; }
		void setWinLevel(const bool x) { winLevel= x; }

	private:
		sf::View mView;
		Animacion animacion;
		unsigned int row;
		bool faceRight;
		sf::Texture txt_lifeBar;
		Shield* mShield;
		std::vector<Proyectil>  mProyectiles;
		sf::Clock clock_ataque;
		sf::Clock clock_recuperacion;
		sf::Clock clock_dash;
		sf::Clock mClockRunSound;
		sf::Sound mElectricSound;
		sf::Sound mKnifeThrowSound;
		sf::Sound mJumpSound;
		sf::Sound mRunSound;
		sf::Sound mDashSound;
		sf::Sound mShieldSound;

		sf::RectangleShape body;
		sf::RectangleShape mMaximumManaBar;
		sf::RectangleShape mCurrentManaBar;
		sf::RectangleShape mMaximumLifeBar;
		sf::RectangleShape mCurrentLifeBar;


		float speed;
		float vel_ataque;
		float recuperacion;
		float cld_dash;
		float mCurrentLife;
		float mMaximumLife;
		float mMaximumMana;
		float mCurrentMana;
		sf::Vector2f velocity;
		bool canShieldSound;
		bool isShieldActivated;
		bool canJump;
		bool canSecondJump;
		bool isAlive;
		bool attacking;
		bool dying;
		bool winLevel;
		float jumpHeight;
	};
}
#endif