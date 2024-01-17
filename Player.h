#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;
	// Where is the player
	Vector2f m_Position;
	// of course, we will need a sprite
	Sprite m_Sprite;
	// and a  Texture
	// !! Watch this space - Interesting changes here soon!!
	Texture m_Texture;
	// What is the screen resolution
	Vector2f m_Resolution;
	// what size is the current arena
	IntRect m_Arena;
	// How big is each tile of the arena
	int m_TileSize;
	// which direction(s) is the player currently moving in
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	// how much health has the player got
	int m_Health;
	// what is the maximum health the player can have
	int m_MaxHealth;
	// when was the player last hit
	Time m_LastHit;
	// Speed in pixles per second
	float m_Speed;
// all our public functions will come next
public:
	Player();
	
	// call this at the end of every game
	void resetPlayerStats();

	void spawn(IntRect arena, Vector2f resolution, int tileSize);

	// Handle the player getting hit by a zombie
	bool hit(Time timeHit);

	//How long ago was the player last hit
	Time getLastHitTime();

	// where is the player
	FloatRect getPosition();

	// where is the center of the player
	Vector2f getCenter();

	// what angle is the player facing
	float getRotation();

	// Send a copy of the sprite to the main function
	Sprite getSprite();

	// how much health has the player currently got?
	int getHealth();

	// the next four functions move the player
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	// Stop the player moving in a specific direction
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	// we will call this function once every frame
	void update(float elapsedTime, Vector2i mousePostiion);

	// Give the player a speed boost
	void upgradeSpeed();

	// Give the player some health
	void upgradeHealth();

	// INcrease the maximum amount of health the player can have
	void increaseHealthLevel(int amount);

};

#pragma once
