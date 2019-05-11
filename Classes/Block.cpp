#include "Block.h"
#define TILE_H_SIZE 6
#define TILE_W_SIZE 8


Block::Block()
{
	_tileWidth = _screenSize.width / TILE_W_SIZE;
	_tileHeight = _screenSize.height / TILE_H_SIZE;

	this->setVisible(false);
}

Block* Block::create()
{
	auto obj = new Block();
	if (obj && obj->initWithFile("blank.png"))
	{
		obj->autorelease();
		return obj;
	}
	CC_SAFE_DELETE(obj);
	return nullptr;
}

void Block::setupBlock(float width, float height, int type)
{
	_type = type;
	_width = width * _tileWidth;
	_height = height * _tileHeight;
	this->setAnchorPoint(_vector);
	this->setTextureRect(Rect(0, 0, _width, _height));
	
	switch (type) {
	case kBlockGap:
		this->setVisible(false);
		return;

	case kBlock1:
		this->setColor(Color3B(200, 200, 200));
		break;

	case kBlock2:
		this->setColor(Color3B(150, 150, 150));
		break;

	case kBlock3:
		this->setColor(Color3B(100, 100, 100));
		break;

	case kBlock4:
		this->setColor(Color3B(50, 50, 50));
		break;
	
	}
	this->setVisible(true);
}