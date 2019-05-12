#ifndef __Prefix__Block__
#define __Prefix__Block__

#include "cocos2d.h"
#include "GameSprite.h"
USING_NS_CC;
enum {
	kBlockGap,
	kBlock1,
	kBlock2,
	kBlock3,
	kBlock4
};
class Block : public GameSprite
{
	int _tileWidth;
	int _tileHeight;
	Block();

public:
	static Block* create();
	void setupBlock(float width, float height, int type);

	CC_SYNTHESIZE(int, _type, Type);
	
	virtual int left() {
		return this->getPositionX();
	}

	virtual int right() {
		return this->getPositionX() + _width;
	}

	virtual int top() {
		return this->getHeight();
	}

	virtual int bottom() {
		return 0;
	}
};

#endif // __Prefix__Block__
