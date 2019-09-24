#include "../Header Files/ProyectileBehavior.h"
#include "../Header Files/EntityManager.h"
namespace game {
	void rectLineBehavior(Proyectil * aProyectil, const float  deltaTime)
	{

		float deltaX = aProyectil->getDirection().x - aProyectil->getInicio().x;
		float deltaY = aProyectil->getDirection().y - aProyectil->getInicio().y;
		float angulo = atan2f(deltaY, deltaX);
		sf::Vector2f vel;
		vel.x = cos(angulo)*aProyectil->getVelocity();
		vel.y = sin(angulo)*aProyectil->getVelocity();
		int row = 0;
		aProyectil->innerUpdate(row, deltaTime, vel.x > 0, false, false, vel);
	
	}

	void chainingBehavior(Proyectil* aProyectil, const float deltaTime)
	{
		aProyectil->setInicio(aProyectil->getPosition());
		if (EntityManager::getClosestEnemy(aProyectil->getPosition().x, aProyectil->getPosition().y) == nullptr)
		{
			return;
		}
		aProyectil->setDirection(EntityManager::getClosestEnemy(aProyectil->getPosition().x, aProyectil->getPosition().y)->GetPosition());
		float deltaX = aProyectil->getDirection().x - aProyectil->getInicio().x;
		float deltaY = aProyectil->getDirection().y - aProyectil->getInicio().y;
		float angulo = atan2f(deltaY, deltaX);
		sf::Vector2f vel;
		vel.x = cos(angulo)*aProyectil->getVelocity();
		vel.y = sin(angulo)*aProyectil->getVelocity();
		int row = 0;
		aProyectil->innerUpdate(row, deltaTime, vel.x > 0, false, false, vel);

	}

}
