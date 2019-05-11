#include "MyTerrain.h"
#include <algorithm>
using namespace std;

vector<int> _blockTypes = {1,2,3,4,1,3,2,4,3,2,1,4,2,3,1,4,2,3,1,2,3,2,3,4,1,2,4,3,1,3,1,4,2,4,2,1,2,3 };

MyTerrain* MyTerrain::create()
{
	auto mt = new MyTerrain();
	if(mt && mt->init())
	{
		mt->autorelease();
		return mt;
	}
	CC_SAFE_DELETE(mt);
	return nullptr;
}

bool MyTerrain::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Node::init() )
    {
        return false;
    }
    _screenSize = Director::getInstance()->getWinSize();

	_blockPool = Vector<Block*>(20);
	_currentTypeIndex = 0;
	_blockBatchNode = SpriteBatchNode::create("blank.png", 200);
	this->addChild(_blockBatchNode);

	// init object pools
	Block * block;
	for (int i = 0; i < 20; i++) {
		block = Block::create();
		_blockBatchNode->addChild(block);
		_blockPool.pushBack(block);
	}

	_blocks = Vector<Block*>(20);
	_minTerrainWidth = _screenSize.width * 1.5f;
	
	this->addBlocks(0);

	return true;
}

void MyTerrain::initBlock(Block* block)
{
	int blockWidth;
	int blockHeight;

	int type = _blockTypes[_currentTypeIndex];
	_currentTypeIndex++;

	if (_currentTypeIndex == _blockTypes.size()) {
		_currentTypeIndex = 0;
	}

	_lastBlockHeight = 2;
	_lastBlockWidth = rand() % 2 + 2;
	block->setupBlock(_lastBlockWidth, _lastBlockHeight, type);
}

void MyTerrain::distributeBlocks()
{
	int count = _blocks.size();

	Block * block;
	Block * prev_block;
	int i;

	for (i = 0; i < count; i++) {
		block = _blocks.at(i);
		if (i != 0) {
			prev_block = _blocks.at(i - 1);
			block->setPositionX(prev_block->getPositionX() + prev_block->getWidth());
		}
		else
		{
			block->setPositionX(0);
		}
	}
}

void MyTerrain::addBlocks(int currentWidth)
{
	Block * block;
	while (currentWidth < _minTerrainWidth)
	{
		block = _blockPool.at(_blockPoolIndex);
		_blockPoolIndex++;
		if (_blockPoolIndex == _blockPool.size()) {
			_blockPoolIndex = 0;
		}
		this->initBlock(block);
		currentWidth += block->getWidth();
		_blocks.pushBack(block);
	}

	this->distributeBlocks();
}

