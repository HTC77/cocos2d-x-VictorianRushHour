#ifndef __Prefix__GameSprite__
#define __Prefix__GameSprite__

#include "cocos2d.h"
USING_NS_CC;

class GameSprite : public Sprite
{
protected:
	Size _screenSize;
	GameSprite();
	~GameSprite();

public:
	CC_SYNTHESIZE(Vec2, _nextPosition, NextPosition)
	CC_SYNTHESIZE(float, _width, Width)
	CC_SYNTHESIZE(float, _height, Height)
	CC_SYNTHESIZE(Vec2, _vector, Voctor)
};

#endif // __Prefix__GameSprite__