#include "../Header Files/GameLevelTwo.h"
#include <iostream>
#include<cassert>

namespace game {

	void GameLevelTwo::initialize(sf::RenderWindow* window) {
		bool isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mJackTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mBackgroundZero_LevelTwo);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mBackgroundOne_LevelTwo);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mPortalTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mPotionManaTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mBossLevelOneTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mBossLevelOneMeteoro);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mBatsTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mDemonTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mLifeBarTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mKnifeTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mShieldTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mProyectilLightning);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mDemonFireBallTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mTilesTwoTexture);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mFireBall3Sound);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mKnifeThrowSound);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mElectricSound);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mBatDeathSound);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mDemonDeathSound);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mChampionJumpSound);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mChampionRunSound);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mChampionDashSound);
		assert(isCorrectlyLoaded);
		isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mChampionShieldSound);
		assert(isCorrectlyLoaded);


		for (size_t i = 0; i < 9; i++)
		{
			sprite_backgroundZero[i].setTexture(*(TextureManager::getTexture(game_constants::Constants::mBackgroundZero_LevelTwo)));
			sprite_backgroundOne[i].setTexture(*(TextureManager::getTexture(game_constants::Constants::mBackgroundOne_LevelTwo)));
			sprite_backgroundZero[i].setPosition(1920.0f * i, -50);
			sprite_backgroundOne[i].setPosition(1920.0f * i, -50);
		}
		campeon = new Campeon(TextureManager::getTexture(game_constants::Constants::mJackTexture), sf::Vector2u(10, 6), 0.06f, 0.30f, 0.030f, 0.5f, 100.0f);
		campeon->setPosition(sf::Vector2f(200.0f, 200.0f));
		sLevel =  "....................asd........111....................................................................111............ad.......ad";
		sLevel += "....................asd...................................................11.........................................ad.......ad";
		sLevel += "....................asd....fgggggggwe.........11..............11..........................11.............2...........ad.......ad";
		sLevel += "............fggwe...asd............ase..............qwe.................fh......................qwggggggggggggggggh..ad.......ad";
		sLevel += ".....fgh.....11ad...zxxgh..........asd........fh....asd.....fgh................qwe.....fgh......sd.....111...111.....ad.......ad";
		sLevel += ".............11ad...........fgh....asd..............asd.............qwe........asd.............qsd..fggggggggggggggggsd..12212ad";
		sLevel += "..........qwwwwsswe.....11......11masd....fh.....11.asswe...........asd....111.asd..fh...11111.asd.....111..111.111..ad...1212ad";
		sLevel += "..........asssssssse....2.......qwwssd..............asssd...111..2..asswwe.111masd.......2.m.2masd......2....2...2mmpad...2122ad";
		sLevel += "wwwwwwwwwwsssssssssswwwwwwwwwwwwsssssswwwwwwwwwwwwwwssssswwwwwwwwwwwsssssswwwwwssswwwwwwwwwwwwwssswwwwwwwwwwwwwwwwwwwsswwwwwwwss";

		map = new TileMap(game_constants::Constants::mTilesTwoTexture, 128, 9, sLevel, 128, 128);

	}

	GameLevelTwo::GameLevelTwo(sf::RenderWindow* window)
	{
		//loadTexturesLvl1(*window);
	}

	void GameLevelTwo::finalize()
	{
		GameSoundManager::clear();
		TextureManager::clear();
		delete map;
		delete campeon;
	}


	GameState * GameLevelTwo::update(sf::RenderWindow* window, float deltaTime)
	{
		for (int i = 0; i < 9; ++i)
		{
			sprite_backgroundZero[i].setPosition(sprite_backgroundZero[i].getPosition().x - 0.15f * campeon->GetVelocity().x, sprite_backgroundZero[i].getPosition().y);
			sprite_backgroundOne[i].setPosition(sprite_backgroundOne[i].getPosition().x - 0.45f * campeon->GetVelocity().x, sprite_backgroundOne[i].getPosition().y);
		}
		window->clear();
		map->CheckCollisionTileMap(deltaTime, *window, campeon);
		for (int i = 0; i < 9; ++i)
		{
			window->draw(sprite_backgroundZero[i]);
			window->draw(sprite_backgroundOne[i]);
		}
		map->TileMapDraw(*window, deltaTime, *campeon);
		campeon->Draw(*window);
		window->display();
		if (campeon->getCurrentLife() <= 0) {
			return new GameOverState;
		}

		return this;
	}



}
