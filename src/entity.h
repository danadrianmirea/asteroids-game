#pragma once

#include "raylib.h"
#include "raymath.h"

// base entity class that contains common data used by all entity types
class Entity
{
public:
	virtual ~Entity() = default;

	bool Alive = false;	

	Vector2 Position = { 0 };
	float Orientation = 0;

	Vector2 Velocity = { 0 };
	float RotationalVelocity = 0;

	float Radius = 0;

	virtual void Update();

	virtual bool Collide(const Entity& other);

	inline virtual void Draw() const {}
};