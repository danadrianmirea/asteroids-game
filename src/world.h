#pragma once

#include "entity.h"
#include "asteroid.h"
#include "bullet.h"
#include "explosion.h"
#include "player.h"
#include "powerup.h"

#include <vector>

class World
{
public:
	static World* Instance;
	
	static World& Create();
	static void Destory();
	
	virtual ~World() = default;

	Rectangle Bounds = { -6000, -6000, 12000, 12000 };

	void Reset(int level = 1);

	void Update();

	void Draw(Rectangle& screenInWorld) const;

	std::vector<Asteroid> Asteroids;
	std::vector<Bullet> Bullets;
	std::vector<Explosion> Explosions;
	std::vector<PowerUp> PowerUps;
	Player PlayerShip;

	bool IsLevelClear() const { return LevelClear; }

	size_t GetActiveAsteroidCount() const { return ActiveAsteroidCount; }

	bool BounceBounds(Entity& entity);

	bool Shake() const { return PlayerShip.Alive && PlayerShip.Boost; }

protected:
	bool LevelClear = false;
	size_t ActiveAsteroidCount = 0;
	World() {}

};
