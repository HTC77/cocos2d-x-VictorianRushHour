#include "Player.h"

Player::Player()
{
	_nextPosition = Point::ZERO;
	_nextPosition.y = _screenSize.height * 0.6f;
	_maxSpeed = PLAYER_INITIAL_SPEED;
	_speed = 0;
}

Player* Player::create()
{
	auto obj = new Player();
	if (obj && obj->initWithFile("blank.png"))
	{
		obj->autorelease();
		obj->initPlayer();
		return obj;
	}
}

void Player::initPlayer()
{
	this->setAnchorPoint(Vec2(0.5f, 1.0f));
	this->setPosition(Vec2(_screenSize.width * 0.2f, _nextPosition.y));

	_height = 22.8;
	_width = 18;
	this->setTextureRect(Rect(0, 0, _width, _height));
	this->setColor(Color3B(255, 255, 255));
}

void Player::update(float delta)
{
	if (_speed + ACCELERATION <= _maxSpeed) {
		_speed += ACCELERATION;
	}
	else {
		_speed = _maxSpeed;
	}

	_vector.x = _speed;
}

