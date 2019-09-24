#ifndef BAT_H
#define BAT_H
#include "Entidad.h"
#include <SFML/Graphics.hpp>
#include "animacion.h"
#include "Collider.h"
#include "Proyectil.h"
//#include "campeon.h"
namespace game {
	class Bat : public Entidad
	{
		public:
			Bat(sf::Texture * textura, const sf::Vector2u imageCount, const float switchTime, const float speed,
				const float jumpHeight, const float vel_ataque, const float vida, const sf::Vector2f position);
			~Bat();

			void procesarGolpearCampeon(Campeon & campeon);
			void procesarImpactos(std::vector<Proyectil>& balas);
			void Update(const float deltaTime, Campeon & campeon, std::string & sLevel, const float nTileWidth,
				const float nTileHeight, const float nLevelWidth, const float nLevelHeight)override;
			//void Update(float deltaTime, Campeon & campeon);

			float getVida()const { return vida; }
	};

}
#endif