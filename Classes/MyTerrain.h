#ifndef __Prefix__MyTerrain__
#define __Prefix__MyTerrain__

#include "cocos2d.h"
#include "Block.h"

class Player;
USING_NS_CC;

class MyTerrain : public Node
{
public:
	static MyTerrain* create();
    virtual bool init();

	Vector<Block*> _blockPool, _blocks;
	int _blockPoolIndex;

	int _minTerrainWidth;
    Size _screenSize;
	int _currentTypeIndex;
	int _lastBlockHeight;
	int _lastBlockWidth;

	SpriteBatchNode* _blockBatchNode;

	void addBlocks(int currentWidth);
	void initBlock(Block* block);
	void distributeBlocks();
	void move(float xMove);
	void checkCollision(Player * player);
};
#endif // __Prefix__MyTerrain__
