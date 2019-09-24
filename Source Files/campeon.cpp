
#include "../Header Files/campeon.h"
#include <iostream>
#include "../Header Files/ProyectileBehavior.h"
#include "../Header Files/Constants.h"
#include "../Header Files/GameSoundManager.h"
namespace game {

	Campeon::Campeon(sf::Texture * textura, const  sf::Vector2u imageCount, const float switchTime,
		const float speed, const float jumpHeight, const float vel_ataque, const float vida) :
		animacion(textura, imageCount, switchTime),
		speed(speed), jumpHeight(jumpHeight), vel_ataque(vel_ataque), mCurrentLife(vida),
		recuperacion(0.50f),
		row(0),
		faceRight(true),
		cld_dash(1.0f),
		winLevel(false),
		canShieldSound(true),
		mMaximumMana(100),
		mCurrentMana(100),
		mMaximumLife(100)
	{
		setCanSecondJump(true);
		body.setSize(sf::Vector2f(64, 64));
		body.setOrigin(body.getSize() / 2.0f);
		body.setPosition(15120, 260);
		body.setTexture(textura);
		mMaximumLifeBar.setFillColor(sf::Color(0, 100, 0));
		mMaximumLifeBar.setScale(2, 1);
		mCurrentLifeBar.setFillColor(sf::Color(0, 150, 0));
		mCurrentLifeBar.setScale(2, 1);
		mMaximumManaBar.setFillColor(sf::Color(0, 0, 100));
		mMaximumManaBar.setScale(2, 1);
		mCurrentManaBar.setFillColor(sf::Color(0, 0, 150));
		mCurrentManaBar.setScale(2, 1);
		mDashSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mChampionDashSound)));
		mElectricSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mElectricSound)));
		mShieldSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mChampionShieldSound)));
		mJumpSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mChampionJumpSound)));
		mKnifeThrowSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mKnifeThrowSound)));
		mShieldSound.setVolume(20);
		mJumpSound.setVolume(20);
		mDashSound.setVolume(20);
		mElectricSound.setVolume(20);
		mKnifeThrowSound.setVolume(20);
		mRunSound.setBuffer(*(GameSoundManager::getSound(game_constants::Constants::mChampionRunSound)));
		mShield = new Shield(TextureManager::getTexture(game_constants::Constants::mShieldTexture), sf::Vector2u(4, 1), sf::Vector2f(130,130), 0.03f);
		
	}

	Campeon::~Campeon()
	{
	}

	sf::Vector2i Campeon::procesarMouse(sf::RenderWindow & window) {

		sf::Vector2i posicion_mouse = sf::Mouse::getPosition(window);
		posicion_mouse = (sf::Vector2i)window.mapPixelToCoords(posicion_mouse);
		return posicion_mouse;
	}

	void Campeon::inputHandler(sf::RenderWindow & window)
	{
		setAttacking(false);
		setDying(false);
		sf::Vector2i posicionMouse;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			velocity.x -= speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x += speed;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			velocity.x = 0.0f;
			row = 3;
			setAttacking(true);
			if (animacion.ataco == true)
			{
				if (!animacion.murio)
				{
					posicionMouse = procesarMouse(window);
					disparar(posicionMouse);
					if (posicionMouse.x > body.getPosition().x) faceRight = true;
					else  faceRight = false;

				}
			}

		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			castLightningSkill();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
			if (mCurrentMana > 0) {
				if (canShieldSound) {
					canShieldSound = false;
					mShieldSound.play();
				}
				setIsShieldActivated(true);
				mCurrentMana -= 0.3f;

			}
		}
		else
		{
			setIsShieldActivated(false);
			canShieldSound = true;
		}
		if (mCurrentMana < 1) {
			setIsShieldActivated(false);
		}
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			velocity.y += speed;
		}
		 */

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canSecondJump && velocity.y > 0 ) {
			mJumpSound.play();
			canSecondJump = false;
			velocity.y = -sqrtf(2.0f * 918.0f * jumpHeight);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
		{
			mJumpSound.play();
			canJump = false;
			canSecondJump = true;
			velocity.y = -sqrtf(2.0f * 918.0f * jumpHeight);

		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
		{
			if (clock_dash.getElapsedTime().asSeconds() > cld_dash)
			{
				//velocity.x = 10;
				mDashSound.play();
				clock_dash.restart();
			}
		}
		//limitacion de la velocidad
		if (velocity.x < -4)velocity.x = -4;
		if (velocity.x > 4)velocity.x = 4;
		//duracion del dash
		if (clock_dash.getElapsedTime().asSeconds() < 0.15f) {
			velocity.x *= 2.5f;
		}

	}
	void Campeon::Update(const float deltaTime, sf::RenderWindow & window)
	{

		//velocity.y += 981.0f * deltaTime;



		if (!getAttacking())
		{

			if (abs(velocity.x) < 0.60f)
			{
				row = 0;

			}
			else
			{
				//RUNING
				if (mClockRunSound.getElapsedTime().asSeconds() > 0.3f && canJump) {
					mClockRunSound.restart();
					mRunSound.play();
				}
				row = 2;
				if (velocity.x > 0.0f)
					faceRight = true;
				else
					faceRight = false;
			}
		}
		if (velocity.y > 0) {
			row = 4;
		}

		if (velocity.y < 0) {
			row = 5;
		}

		if (abs(velocity.x) > 3.3f) row = 1;

		if (mCurrentLife <= 0)
		{
			setDying(true);
			row = 4;
			if (animacion.murio == true)
			{
				setIsAlive(false);
			}
		}
		if (clock_recuperacion.getElapsedTime().asSeconds() < recuperacion)
		{
			body.setFillColor(sf::Color::Red);
		}
		else
		{
			body.setFillColor(sf::Color::White);
		}
		animacion.Update(row, deltaTime, faceRight, getAttacking(), getDying());
		body.setTextureRect(animacion.uvRect);
		//body.move(velocity * deltaTime );
		sf::View mView = window.getView();

		sf::Vector2i posicionMouse;
		posicionMouse = procesarMouse(window);
		//vista fija al personaje
		mView.setCenter(GetPosition().x , GetPosition().y - 70);
		//vista relativa al mouse
	//	mView.setCenter(GetPosition().x + ((posicionMouse.x - GetPosition().x)*0.1), GetPosition().y - 70 +((posicionMouse.y - GetPosition().y)*0.1));
		window.setView(mView);
		sf::Vector2u windowSize = window.getSize();
		windowSize.x *= 0.2;
		windowSize.y *= 0.2;
		sf::Vector2f viewCenter = window.getView().getCenter();

		mMaximumLifeBar.setSize(sf::Vector2f(mMaximumLife + 10, 20));
		mCurrentLifeBar.setSize(sf::Vector2f(mCurrentLife , 10));
		mMaximumManaBar.setSize(sf::Vector2f(mMaximumMana + 10, 20));
		mCurrentManaBar.setSize(sf::Vector2f(mCurrentMana, 10));
		/*
			mMaximumLifeBar.setPosition(viewCenter.x - windowSize.x , viewCenter.y + windowSize.y);
			mCurrentLifeBar.setPosition(viewCenter.x - windowSize.x+5 , viewCenter.y + windowSize.y + 5);
			mMaximumManaBar.setPosition(viewCenter.x - windowSize.x, viewCenter.y + windowSize.y + 30);
			mCurrentManaBar.setPosition(viewCenter.x - windowSize.x+5, viewCenter.y + windowSize.y + 35);
		*/

		mMaximumLifeBar.setPosition(viewCenter.x - 400, viewCenter.y + 200);
		mCurrentLifeBar.setPosition(viewCenter.x - 400  + 5, viewCenter.y + 200+ 5);
		mMaximumManaBar.setPosition(viewCenter.x - 400 , viewCenter.y +200 + 30);
		mCurrentManaBar.setPosition(viewCenter.x - 400 + 5, viewCenter.y + 200+ 35);

		if (isShieldActivated) {
			mShield->update(body.getPosition(), deltaTime);
		}
		for (size_t i = 0; i < mProyectiles.size(); ++i){
			mProyectiles[i].Update(deltaTime);
		}
	}

	void Campeon::Draw(sf::RenderWindow & window)
	{
		window.draw(body);
		window.draw(mMaximumLifeBar);
		window.draw(mCurrentLifeBar);
		window.draw(mMaximumManaBar);
		window.draw(mCurrentManaBar);
		
		if (isShieldActivated) {
			mShield->Draw(window);
		}
		for (size_t i = 0; i < mProyectiles.size(); ++i)
		{
			if (!mProyectiles[i].getIsAlive() || mProyectiles[i].eliminar())
			{
				mProyectiles.erase(mProyectiles.begin() + i);
			}
			else {
				mProyectiles[i].Draw(window);
			}
		}
	}

	void Campeon::onCollision(const  sf::Vector2f direction)
	{
		if (direction.x < 0.0f)
		{
			//colision en la izq
			velocity.x = 0.0f;

		}
		else if (direction.x > 0.0f)
		{

			//colision en la der
			velocity.x = 0.0f;
		}
		if (direction.y < 0.0f)
		{
			//colision en la bot
			velocity.y = 0.0f;
			canJump = true;
			canSecondJump = true;
		}
		else if (direction.y > 0.0f)
		{
			//top
			velocity.y = 0.0f;
		}

	}

	void Campeon::castLightningSkill()
	{
		if (mCurrentMana > 10) {
			if (clock_ataque.getElapsedTime().asSeconds() > vel_ataque) {
				mElectricSound.play();
				mCurrentMana -= 10;
				mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mProyectilLightning),
					sf::Vector2u(9, 1), sf::Vector2f(20, 10), 0.04f, 10.00f, 0.8f, 800.0f, 2,
					EntityManager::getClosestEnemy(body.getPosition().x, body.getPosition().y)->GetPosition(),
					body.getPosition(),
					chainingBehavior));
				clock_ataque.restart();
			}
		}
	}

	void Campeon::disparar(const  sf::Vector2i posicion)
	{
		if (clock_ataque.getElapsedTime().asSeconds() > vel_ataque)
		{
			mKnifeThrowSound.play();
			mProyectiles.push_back(Proyectil(TextureManager::getTexture(game_constants::Constants::mKnifeTexture),
				sf::Vector2u(10, 1), sf::Vector2f(16, 8), 0.04f, 20.00f, 2.0f, 400.0f, 0,
				(sf::Vector2f)posicion, body.getPosition(),
				rectLineBehavior));
			clock_ataque.restart();
		}

	}


	void Campeon::getHurt(const  float daño)
	{
		mCurrentLife -= daño;		
	}
	void Campeon::getHurtRecovery(const  float daño)
	{
		if (clock_recuperacion.getElapsedTime().asSeconds() > recuperacion)
		{
			clock_recuperacion.restart();
			mCurrentLife -= daño;
		}
	}

}
