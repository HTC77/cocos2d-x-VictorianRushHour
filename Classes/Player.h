#ifndef __Prefix__Player__
#define __Prefix__Player__

#include "cocos2d.h"
#include "GameSprite.h"
USING_NS_CC;

class Player : public GameSprite
{
	Player();
public:
	static Player* create();

	void initPlayer();
};

#endif // __Prefix__Player__
