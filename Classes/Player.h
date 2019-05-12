#ifndef __Prefix__Player__
#define __Prefix__Player__

#include "cocos2d.h"
#include "GameSprite.h"
USING_NS_CC;

#define PLAYER_INITIAL_SPEED 4
#define ACCELERATION 0.5
#define GRAVITY 0.2
#define FLOATNG_GRAVITY 0.4
#define TERMINAL_VELOCITY 70
#define FLOATING_FRICTION 0.98f
#define AIR_FRICTION 0.99f
#define PLAYER_JUMP 8

typedef enum
{
	kPlayerMoving,
	kPlayerFalling,
	kPlayerDying

} PlayerState;

class Player : public GameSprite
{
	Player();
	float _speed;
	bool _hasFloated;
	float _floatingTimer;
	int _floatingTimerMax;

public:
	static Player* create();

	void initPlayer();
	void update(float delta) override;
	void setFloating(bool value);
	CC_SYNTHESIZE(float, _maxSpeed, MaxSpeed);
	CC_SYNTHESIZE(PlayerState, _state, State);
	CC_SYNTHESIZE(bool, _jumping, Jumping);
	CC_SYNTHESIZE_READONLY(bool, _floating, Floating);

	int left() {
		return this->getPositionX() - _width * 0.5f;
	}

	int right() {
		return this->getPositionX() + _width * 0.5f;
	}

	int top() {
		return this->getPositionY();
	}

	int bottom() {
		return this->getPositionY() - _height;
	}

	int next_left() {
		return _nextPosition.x - _width * 0.5f;
	}

	int next_right() {
		return _nextPosition.x + _width * 0.5f;
	}

	int next_top() {
		return _nextPosition.y;
	}

	int next_bottom() {
		return _nextPosition.y - _height;
	}
};

#endif // __Prefix__Player__
