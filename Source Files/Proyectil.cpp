#include "../Header Files/Proyectil.h"
#include <iostream>
namespace game {

	using namespace std;
	Proyectil::Proyectil(sf::Texture * textura, const sf::Vector2u imageCount, sf::Vector2f aSize,
		const float switchTime, const float daño, const float duracion,
		const float velocidad, const unsigned int aBounce,
		sf::Vector2f direccion, sf::Vector2f inicio,
		void(*behavior)(Proyectil *aProyectil, const float deltaTime)):
		animacion(textura, imageCount, switchTime),
		daño(daño),
		direccion(direccion),
		duracion(duracion),
		inicio(inicio),
		isAlive(true),
		mBehavior(behavior),
		mNumberBounces(aBounce),
		mCountBounces(0),
		velocidad(velocidad)
	{
	
		row = 0;
		faceRight = true;
		body.setSize(aSize);
		body.setOrigin(body.getSize() / 2.0f);
		body.setPosition(inicio);
		body.setTexture(textura);
		body.setScale(2, 2);
	}

	void Proyectil::Update(const float deltaTime)
	{
		mBehavior(this, deltaTime);
	}
	void Proyectil::Draw(sf::RenderWindow & window)
	{
		window.draw(body);
	}
	bool Proyectil::eliminar()
	{
		return (clock_duracion.getElapsedTime().asSeconds() > duracion);
	}
	void Proyectil::innerUpdate(int row, float deltaTime, bool faceRight, bool a, bool b, sf::Vector2f vel)
	{
		animacion.Update(row, deltaTime, faceRight, false, false);
		body.setTextureRect(animacion.uvRect);
		body.move(vel * deltaTime);
	}
}