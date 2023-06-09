#pragma once
#include <Trackable.h>
#include "Animation.h"
//Unit - A class to hold state information for a game entity � for now, it holds location info for an animation
class Unit : public Trackable
{
private:
	////-DATA-
	
	//Status Data
	bool mEnabled = false;
	bool mIsRed = false;

	//Movement Data
	Vector2D mOrigin = Vector2D(0, 0);
	Vector2D mLoc;
	Vector2D mVel;

	//Animation Data
	int mCurrentAnimation;
	std::vector<Animation> mAnimations;
	

public:
	////-FUNCTIONS-
	
	// constructor(s) / destructor
	Unit(Vector2D loc, const std::vector<Animation>& animations);
	Unit(const std::vector<Animation>& animations);
	~Unit();

	// update � adjusts the state of the Unit � in this case at minimum will call animation�s update function
	void update(float dt);
	
	// draw � draw the current animation�s current sprite in the location of the unit
	void draw();
	
	// swapAnimation � switch to a new animation
	void swapAnimation();
	
	// swapState - switch the state of the opposite
	void swapUnit();

	Animation* getAnimation() { return &mAnimations[mCurrentAnimation]; }
	Vector2D getPosition() { return mLoc; }
	void setPosition(Vector2D newPos) { mLoc = newPos; }
	void setVelocity(Vector2D newDir, float newSpeed);

	bool isEnabled() { return mEnabled; }
	void enable() { mEnabled = true; }
	void disable() { mEnabled = false; }

	void reset();

};