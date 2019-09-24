#include "../Header Files/GameLevelOne.h"
#include <iostream>
#include<cassert>
#include "../Header Files/GameSoundManager.h"
#include "SFML/Graphics/Font.hpp"

namespace game {

		void GameLevelOne::initialize(sf::RenderWindow* window) {
			bool isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mJackTexture);
			assert(isCorrectlyLoaded);
			isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mPortalTexture);
			assert(isCorrectlyLoaded);
			isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mPotionManaTexture);
			assert(isCorrectlyLoaded);
			isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mBossLevelOneTexture);
			assert(isCorrectlyLoaded);
			isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mBossLevelOneFaceTexture);
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
			isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mBackgroundZero_LevelOne);
			assert(isCorrectlyLoaded);
			isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mBackgroundOne_LevelOne);
			assert(isCorrectlyLoaded);
			isCorrectlyLoaded = TextureManager::loadTexture(game_constants::Constants::mTilesTexture);
			assert(isCorrectlyLoaded);
			isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mFireSound);
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
			isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mBossOneSpawnSound);
			assert(isCorrectlyLoaded);
			isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mBossOneGetHitSound);
			assert(isCorrectlyLoaded);
			isCorrectlyLoaded = GameSoundManager::loadSound(game_constants::Constants::mBossOneDeathSound);
			assert(isCorrectlyLoaded);
			mArialFont.loadFromFile("arial.ttf");
			for (size_t i = 0; i < 9; i++)
			{
				sprite_backgroundZero[i].setTexture(*(TextureManager::getTexture(game_constants::Constants::mBackgroundZero_LevelOne)));
				sprite_backgroundOne[i].setTexture(*(TextureManager::getTexture(game_constants::Constants::mBackgroundOne_LevelOne)));
				sprite_backgroundZero[i].setPosition(1920.0f * i, -400);
				sprite_backgroundOne[i].setPosition(1920.0f * i, -400);
				sprite_backgroundZero[i].setScale(1.3f,1.3f);
			}
			campeon  = new Campeon (TextureManager::getTexture(game_constants::Constants::mJackTexture), sf::Vector2u(10, 6), 0.06f, 0.30f, 0.030f, 0.5f, 100.0f);
			campeon->setPosition(sf::Vector2f(200.0f, 200.0f));
			sLevel =  "......................................asd1.....................ad....................1.1..............ad.111111....ad.........as";
			sLevel += "......................................asd1.................1...ad..................fgggwe.....1..1....ad...........ad.........as";
			sLevel += "......................................zsdm....t..fh.......1.1..ad.1.qwe.......fh.......zswe....2......adpmm.....11.ad.........as";
			sLevel += ".......................................aswwwwwd......qwe..qe...ash..zxse...........1..1.asd...qwwe....aswwwwwwe.11.ad.........as";
			sLevel += "...........1.......1......2.qe.111....fsxxxxxxd.....qssswwsd...ad....1ad.......fh.......asd..fxxxxh...zsxxxxxxd....ad.........as";
			sLevel += ".........1........1.....qwwwsswwwwe....b.1.11.b....qssssxxxxh..zxggh..ad...fh......fh...asd...1111.....b..1.1.b...qsd...t.....as";
			sLevel += "..........qe...........qssssssssssswe............qwssssdm2............ad......2.....2..qssswwwwwwwwwe.....qe..m..qssd.......3.as";
			sLevel += "wwwwwwwwwwsswwwwwwwwwwwsssssssssssssswwwwwwwwwwwwssssssswwwwwwwwwwwwwwsswwwwwwwwwwwwwwwsssssssssssssswwwwwsswwwwwsssswwwwwwwwwss";
			sLevel += "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";
			mResume = nullptr;
			map = new TileMap (game_constants::Constants::mTilesTexture, 128, 9, sLevel, 128, 128);

	}

	GameLevelOne::GameLevelOne(sf::RenderWindow* window)
	{
		//loadTexturesLvl1(*window);
	}

	void GameLevelOne::finalize()
	{
		GameSoundManager::clear();
		TextureManager::clear();
		delete map;
		delete campeon;
		delete mResume;
	}


	GameState * GameLevelOne::update(sf::RenderWindow* window, float deltaTime)
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
		if (campeon->getWinLevel()) {
			if (mResume == nullptr) {
				EntityManager::clear();
				mCronometerText = std::to_string(mCronometer.getElapsedTime().asSeconds());
				mResume = new GameStageResume(mCronometerText,
					TextureManager::getTexture(game_constants::Constants::mBossLevelOneFaceTexture),
					window->getView().getCenter(),
					mArialFont);
			}
			mResume->draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				return new GameLevelTwo(window);
			}
		}
		window->display();
		if (campeon->getCurrentLife() <= 0) {
			return new GameOverState;
		}
		return this;
	}



}
