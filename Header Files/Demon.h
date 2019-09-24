#ifndef DEMON_H
#define DEMON_H
#include "Entidad.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "animacion.h"
#include "Collider.h"
#include "Proyectil.h"
#include <vector>
//#include "campeon.h"
namespace game {
	class Demon : public Entidad
	{
		bool canFireballSound;
		sf::Sound mFireSound;
		std::vector<Proyectil> mProyectiles;
	public:
		Demon(sf::Texture * textura, const sf::Vector2u imageCount, const float switchTime, const float speed,
			const float jumpHeight, const float vel_ataque, const float vida, const sf::Vector2f position);
		~Demon();

		void Draw(sf::RenderWindow & window);
		void Update(const float deltaTime, Campeon & campeon, std::string & sLevel, const float nTileWidth, const float nTileHeight,
			const float nLevelWidth, const float nLevelHeight)override;
		void procesarGolpearCampeon(Campeon & campeon);
		void procesarImpactos(std::vector<Proyectil>& balas);
		void disparar(const  sf::Vector2f posicion);

		float getVida()const { return vida; }
		bool getisAlive()const { return isDyingAnimationFinished; }
		void setIsAlive(const bool x) { isDyingAnimationFinished = x; }

	};
}
#endif