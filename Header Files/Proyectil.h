#ifndef PROYECTIL_H
#define PROYECTIL_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "animacion.h"
#include "Collider.h"
namespace game {

	class Proyectil
	{
	public:
		Proyectil(sf::Texture* textura, const  sf::Vector2u imageCount, sf::Vector2f aSize, const float switchTime,
			const float daño, const float duracion, const float velocidad, const unsigned int aBounce,
			sf::Vector2f direccion, sf::Vector2f inicio,
			void(*behavior)(Proyectil* aProyectil, const float deltaTime));

		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);
		bool eliminar();
		void innerUpdate(int row, float deltaTime, bool faceRight, bool a, bool b,sf::Vector2f vel);
		void setDirection(const sf::Vector2f x) { direccion = x; }
		sf::Vector2f getPosition() { return body.getPosition(); }
		sf::Vector2f getInicio() { return inicio; }
		void setInicio(const sf::Vector2f x) { inicio = x; }
		float& getVelocity() { return velocidad; }
		sf::Clock& getClock() { return clock_duracion;}
		float& getDuration() { return duracion; }
		sf::Vector2f getDirection() { return direccion; }
		Collider GetCollider() { return Collider(body); }
		float getDaño() { return daño; }
		void setIsAlive(bool x) { isAlive = x; }
		bool getIsAlive() { return isAlive; }
		void addCountBounce() { ++mCountBounces; }
		unsigned int getCountBounces()const { return mCountBounces; }
		unsigned int getNumberBounces()const { return mNumberBounces; }
		Animacion& getAnimation() { return animacion;}
		sf::RectangleShape& getBody() { return body; }

	private:
		Animacion animacion;
		sf::RectangleShape body;
		sf::Clock clock_duracion;
		float daño;
		sf::Vector2f direccion;
		float duracion;
		bool faceRight;
		bool makeSound;
		sf::Vector2f inicio;
		bool isAlive;
		unsigned int mNumberBounces;
		unsigned int mCountBounces;
		unsigned int row;
		float velocidad;
		void(*mBehavior)(Proyectil* aProyectil, const float deltaTime);


	};

}	
#endif