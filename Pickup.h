#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
using namespace sf;

class Pickup

{
private:
	// Start value for health pickups
	const int HEALTH_START_VALUE = 50;
	const int AMMO_START_VALUE = 12;
	const int START_WAIT_TIME = 10;
	const int START_SECONDS_TO_LIVE = 5;
	// the sprite that represents this pickup
	/// </summary>
	Sprite m_Sprite;
	// the arena it exists in
	IntRect m_Arena;
	//how much is this pickup worth?
	int m_Value;

	// what type of pickup is this?
	// 1 - health, 2 = ammo
	int m_Type;
	// handle spawning and disappearing
	bool m_Spawned;
	float m_SecondsSinceSpawn;
	float m_SecondsSinceDeSpawn;
	float m_SecondsToLive;
	float m_SecondsToWait;
	// public prototypes go here
public:
	Pickup(int type);
	// Prepare a new pickup
	void setArena(IntRect arena);
	void spawn();
	// Check the position of a pickup
	FloatRect getPosition();
	// Get the sprite for drawing
	Sprite getSprite();
	// Let the pickup update itself each frame
	void update(float elapsedTime);
	// Is this pickup currently spawned?
	bool isSpawned();
	// Get the goodness from the pickup
	int gotIt();
	// Upgrade the value of each pickup
	void upgrade();

};

