#include "../Header Files/TileMap.h"
#include <iostream>
#include <vector>
namespace game {

	TileMap::TileMap(const char* aTexture, const  unsigned int nLevelWidth, const unsigned int nLevelHeight,
		std::string& sLevel, const unsigned int nTileWidth, const unsigned int nTileHeight) :
		nLevelWidth(nLevelWidth), nLevelHeight(nLevelHeight), sLevel(sLevel), nTileWidth(nTileWidth), nTileHeight(nTileHeight)
	{
		auto GetTile = [&](int x, int y)
		{
			if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight)
				return sLevel[y * nLevelWidth + x];
			else
				return ' ';
		};
		auto SetTile = [&](int x, int y, char c)
		{
			if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight)
				sLevel[y * nLevelWidth + x] = c;

		};

		for (int x = 0; x < nLevelWidth; ++x)
		{
			for (int y = 0; y < nLevelHeight; ++y)
			{
				Tiles[x + y * nLevelWidth].setPosition(x * nTileWidth, y * nTileHeight);
				Tiles[x + y * nLevelWidth].setSize(sf::Vector2f(nTileWidth, nTileHeight));

				wchar_t sTileID = GetTile(x, y);
				switch (sTileID)
				{
				case '.':
					break;
				case '{':
					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(0, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'q':
					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(0, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'w':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 1, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'e':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 2, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'a':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 3, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;

				case 's':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 4, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'd':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 5, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'z':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 6, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'x':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 7, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;

				case 'c':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 8, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'r':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 9, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 't':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 10, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'f':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 11, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;

				case 'g':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 12, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'h':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 13, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'b':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 14, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'y':

					Tiles[x + y * nLevelWidth].setTexture(TextureManager::getTexture(aTexture));
					Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 15, 0, 128, 128));
					vTiles.push_back(Tiles[x + y * nLevelWidth]);
					break;
				case 'p':
					portals.push_back(Portal(TextureManager::getTexture(game_constants::Constants::mPortalTexture), sf::Vector2u(7, 1), 0.08f, sf::Vector2f(x*nTileWidth + 45, 55 + y * nTileHeight)));
					SetTile(x, y, '.');
					break;
				case 'm':
					mPotions.push_back(Potion(TextureManager::getTexture(game_constants::Constants::mPotionManaTexture), sf::Vector2f(20, 20), 50, 50, sf::Vector2f(x*nTileWidth + 45, 55 + y * nTileHeight)));

					SetTile(x, y, '.');
					break;
				case '1':
					EntityManager::addBat(x*nTileWidth, y*nTileHeight);
					SetTile(x, y, '.');
					break;
				case '2':

					EntityManager::addDemon(x*nTileWidth, y*nTileHeight);
					SetTile(x, y, '.');
					break;
				case '3':

					EntityManager::addBoss(x*nTileWidth, y*nTileHeight);
					SetTile(x, y, '.');
					break;
				default:
					break;
				}

			}

		}
	}

	void TileMap::TileMapDraw(sf::RenderWindow & window, float deltaTime, Campeon & campeon)
	{
		for (sf::RectangleShape& Tile : vTiles)
		{
			window.draw(Tile);
		}
		for (Portal& portal : portals)
		{
			portal.Update(deltaTime);
			portal.Draw(window);

		}
		for (size_t i = 0; i < mPotions.size(); ++i)
		{
			mPotions[i].update();
			mPotions[i].draw(window);
			if (mPotions[i].getIsUsed()) {
				mPotions.erase(mPotions.begin() + i);
			}
		}

		EntityManager::updateDrawEnemies(deltaTime,campeon, sLevel,nTileWidth,nTileHeight,nLevelWidth,nLevelHeight,window);
	}


	void TileMap::CheckCollisionTileMap(float fElapsedTime, sf::RenderWindow & window, Campeon * campeon) {

		campeon->inputHandler(window);
		campeon->setVelocity(campeon->GetVelocity().x*0.91f, campeon->GetVelocity().y*0.99f);
		float fPlayerVelX = campeon->GetVelocity().x;
		float fPlayerVelY = campeon->GetVelocity().y;
		float fPlayerPosX = campeon->GetPosition().x / nTileWidth;
		float fPlayerPosY = campeon->GetPosition().y / nTileHeight;
		float playerHalfSize = campeon->GetCollider().GetHalfSize().x / nTileWidth;
		fPlayerVelY += 20.0f * fElapsedTime;

		float fNewPlayerPosX = fPlayerPosX + fPlayerVelX * fElapsedTime;
		float fNewPlayerPosY = fPlayerPosY + fPlayerVelY * fElapsedTime;



		auto GetTile = [&](int x, int y)
		{
			if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight)
				return sLevel[y * nLevelWidth + x];
			else
				return ' ';
		};
		auto SetTile = [&](int x, int y, wchar_t c)
		{
			if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight)
				sLevel[y * nLevelWidth + x] = c;

		}; 
		/*
		if (GetTile(fNewPlayerPosX - playerHalfSize, fNewPlayerPosY + playerHalfSize) == L'p' || GetTile(fNewPlayerPosX + playerHalfSize, fNewPlayerPosY + playerHalfSize) == L'p')
		{
			campeon->setWinLevel(true);
			return;
		}
		   */
		if (GetTile(fNewPlayerPosX + playerHalfSize, fPlayerPosY - playerHalfSize) == L'{' || GetTile(fNewPlayerPosX + playerHalfSize, fPlayerPosY + playerHalfSize) == L'{'){
			float porcentaje = fNewPlayerPosX - (int)fNewPlayerPosX;
			if (fPlayerPosY < (fPlayerPosY + fPlayerPosY * porcentaje)){
				fPlayerPosY -= porcentaje*0.0001;
			}
		}
		else {

			 if (GetTile(fNewPlayerPosX - playerHalfSize, fPlayerPosY - playerHalfSize) != L'.' || GetTile(fNewPlayerPosX - playerHalfSize, fPlayerPosY + playerHalfSize) != L'.')
				{
					fNewPlayerPosX = (int)fNewPlayerPosX + 1;
					fPlayerVelX = 0;
				}
			else // Moving Right
			{
				//if (GetTile(fNewPlayerPosX + 1.0f, fPlayerPosY + 0.0f) != L'.' || GetTile(fNewPlayerPosX + 1.0f, fPlayerPosY + 0.9f) != L'.')
				if (GetTile(fNewPlayerPosX + playerHalfSize, fPlayerPosY - playerHalfSize) != L'.' || GetTile(fNewPlayerPosX + playerHalfSize, fPlayerPosY + playerHalfSize) != L'.')
				{
					fNewPlayerPosX = (int)fNewPlayerPosX;
					fPlayerVelX = 0;
				}
			}

			campeon->setCanJump(false);
			if (fPlayerVelY <= 0) // Moving Up
			{
				if (GetTile(fNewPlayerPosX - playerHalfSize, fNewPlayerPosY - playerHalfSize) != L'.' || GetTile(fNewPlayerPosX + playerHalfSize, fNewPlayerPosY - playerHalfSize) != L'.')
				{
					fNewPlayerPosY = (int)fNewPlayerPosY + 1;
					fPlayerVelY = 0;
				}
			}
			else // Moving Down
			{
				if (GetTile(fNewPlayerPosX - playerHalfSize, fNewPlayerPosY + playerHalfSize) != L'.' || GetTile(fNewPlayerPosX + playerHalfSize, fNewPlayerPosY + playerHalfSize) != L'.')
				{
					fNewPlayerPosY = (int)fNewPlayerPosY;
					fPlayerVelY = 0;
					campeon->setCanJump(true); // Player has a solid surface underfoot
											//nDirModX = 0;
				}
			}

		}

		// Apply new position
		for (Portal& portal : portals)
		{
			if (isColliding(campeon->GetCollider(), portal.GetCollider())) {
				
				campeon->setPosition(sf::Vector2f(15300, 300));
				return;
				break;
			}
		}
		for (Potion& potion : mPotions)
		{
			if (isColliding(campeon->GetCollider(), potion.GetCollider())) {
				potion.use(campeon);
				break;
			}
		}

		fNewPlayerPosX = fPlayerPosX + fPlayerVelX * fElapsedTime;
		fNewPlayerPosY = fPlayerPosY + fPlayerVelY * fElapsedTime;
		campeon->setPosition(sf::Vector2f(fNewPlayerPosX*nTileWidth, fNewPlayerPosY*nTileHeight));
		campeon->setVelocity(fPlayerVelX, fPlayerVelY);
		campeon->Update(fElapsedTime, window);

	}
	bool TileMap::isColliding(Collider aA, Collider aB) {
		sf::Vector2f direction(0,0);
		return aA.CheckCollision(aB, direction, 0.0f);
	}
}