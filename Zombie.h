#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Zombie

{
private:
	// how fast is each zombie type?
	const float BLOATER_SPEED = 40;
	const float CHASER_SPEED = 80;
	const float CRAWLER_SPEED = 20;
	//how tough is each zombie type
	const float BLOATER_HEALTH = 5;
	const float CHASER_HEALTH = 1;
	const float CRAWLER_HEALTH = 3;
	// Make eacch zombie vary its speed slightly
	const int MAX_VARRIANCE = 30;
	const int OFFSET = 101 - MAX_VARRIANCE;
	// Where is this zombie?
	Vector2f m_Position;
	// a sprite for the zombie
	Sprite m_Sprite;
	// how fast can this one run/crawl?
	float m_Speed;
	// how much health has it got?
	float m_Health;
	// is it still alive?
	bool m_Alive;

	// public prototypes go here
public:
	// Handle when a bullet hits a zombie
	bool hit();
	// Find out if the zombie is alive
	bool isAlive();
	// Spawn a new zombie
	void spawn(float startX, float startY, int type, int seed);
	// Return a rectangle that is the position in the world
	FloatRect getPosition();
	// get a copy of the sprite to draw
	Sprite getSprite();
	//update the zombie each frame
	void update(float elapsedTime, Vector2f playerLocation);


};