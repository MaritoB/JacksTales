#include "../Header Files/EntityManager.h"

namespace game {


	std::vector<Entidad*> EntityManager::mEnemies = std::vector<Entidad*>();
	void EntityManager::addBat(const float aXPosition, const float aYPosition) {
		mEnemies.push_back(new Bat(TextureManager::getTexture(game_constants::Constants::mBatsTexture),
			sf::Vector2u(10, 10), 0.07f, 140, 4, 150.0f, 10.0f, sf::Vector2f(aXPosition, aYPosition+10)));
	}

	void EntityManager::addDemon(const float aXPosition, const float aYPosition)
	{
		mEnemies.push_back(new Demon(TextureManager::getTexture(game_constants::Constants::mDemonTexture),
			sf::Vector2u(10, 4), 0.12f, 130.0f, 100.0f, 0.01f, 50.0f, sf::Vector2f(aXPosition, aYPosition)));
	}

	void EntityManager::addBoss(const float aXPosition, const float aYPosition)
	{
		mEnemies.push_back(new BossLevelOne(TextureManager::getTexture(game_constants::Constants::mBossLevelOneTexture),
			sf::Vector2u(20, 1), 0.08f, 130.0f, 100.0f, 0.01f, 200.0f, sf::Vector2f(aXPosition, aYPosition-80)));
	}

	Entidad* EntityManager::getClosestEnemy(const float aXPosition, const float aYPosition)
	{
		Entidad* auxEntity = nullptr;
		
		//auxEntity = (*it);
		//++it;
		//float auxDelta2 = pow(aXPosition - auxEntity->GetPosition().x, 2) + pow(aYPosition - auxEntity->GetPosition().y, 2);
		float auxDelta2 = std::numeric_limits<float>::max();

		for (std::vector<Entidad*>::iterator it = mEnemies.begin() ; it != mEnemies.end(); ++it) {
			if ((*it)->getIsAlive()==false) {
				continue;
			}
			float auxDelta = pow((*it)->GetPosition().x - aXPosition,2) + pow((*it)->GetPosition().y - aYPosition,2);
			if(auxDelta < auxDelta2){
				auxEntity = (*it);
				auxDelta2 = auxDelta;
			}
		}
		return auxEntity;
	}

	void EntityManager::updateDrawEnemies(const float deltaTime, Campeon & campeon, std::string & sLevel, const float nTileWidth,
		const float nTileHeight, const float nLevelWidth, const float nLevelHeight, sf::RenderWindow & window)
	{
		for (std::vector<Entidad*>::iterator it = mEnemies.begin(); it != mEnemies.end();) {
			if (abs(campeon.GetPosition().x - (*it)->GetPosition().x) < 900 && abs(campeon.GetPosition().y - (*it)->GetPosition().y) < 600) {
				(*it)->Update(deltaTime, campeon, sLevel, nTileWidth, nTileHeight, nLevelWidth, nLevelHeight);
				(*it)->Draw(window);
				if (!(*it)->getIsAlive() && (*it)->getIsDyingAnimationFinished()) {
					(*it)->~Entidad();
					it = mEnemies.erase(it);
					continue;
				}
			}
			++it;
		}
	}

	void EntityManager::clear()
	{
		{
			for (size_t i = 0; i < mEnemies.size(); ++i)
			{
				mEnemies[i]->~Entidad();
			}
			mEnemies.clear();
		}
	}

}