#ifndef __Prefix__Player__
#define __Prefix__Player__

#include "cocos2d.h"
#include "GameSprite.h"
USING_NS_CC;

#define PLAYER_INITIAL_SPEED 4
#define ACCELERATION 0.5

class Player : public GameSprite
{
	Player();
	float _speed;
public:
	static Player* create();

	void initPlayer();
	void update(float delta) override;
	CC_SYNTHESIZE(float, _maxSpeed, MaxSpeed);
};

#endif // __Prefix__Player__
