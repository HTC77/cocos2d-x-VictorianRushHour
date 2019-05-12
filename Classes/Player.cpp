#include "Player.h"

Player::Player()
{
	_nextPosition = Point::ZERO;
	_nextPosition.y = _screenSize.height * 0.6f;
	_maxSpeed = PLAYER_INITIAL_SPEED;
	_speed = 0;
	_state = kPlayerMoving;
	_jumping = false;
	_floating = false;
	_floatingTimerMax = 2;
	_floatingTimer = 0;
	_hasFloated = false;
}

Player* Player::create()
{
	auto obj = new Player();
	if (obj && obj->initWithFile("blank.png"))
	{
		obj->autorelease();
		obj->setSize();
		obj->initPlayer();
		return obj;
	}
}

void Player::initPlayer()
{
	this->setAnchorPoint(Vec2(0.5f, 1.0f));
	this->setPosition(Vec2(_screenSize.width * 0.2f, _nextPosition.y));
	this->setNextPosition(this->getPosition());
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

	switch (_state) {
	case kPlayerMoving:
		_vector.y -= GRAVITY;
		break;

	case kPlayerFalling:
		if (_floating) {
			_vector.y -= FLOATNG_GRAVITY;
			_vector.x *= FLOATING_FRICTION;

		}
		else {
			_vector.y -= GRAVITY;
			_vector.x *= AIR_FRICTION;
			_floatingTimer = 0;
		}
		break;

	case kPlayerDying:
		_vector.y -= GRAVITY;
		_vector.x = -_speed;
		this->setPositionX(this->getPositionX() + _vector.x);
		break;
	}

	if (_jumping) {
		_state = kPlayerFalling;
		_vector.y += PLAYER_JUMP * 0.25f;
		if (_vector.y > PLAYER_JUMP) _jumping = false;
	}

	if (_vector.y < -TERMINAL_VELOCITY) _vector.y = -TERMINAL_VELOCITY;

	_nextPosition.y = this->getPositionY() + _vector.y;

	if (_floating) {
		_floatingTimer += delta;
		if (_floatingTimer > _floatingTimerMax) {
			_floatingTimer = 0;
			this->setFloating(false);
		}
	}
}

void Player::setFloating(bool value)
{
	if (_floating == value) return;

	if (value && _hasFloated) return;

	_floating = value;

	if (value) {
		_hasFloated = true;
		_vector.y += PLAYER_JUMP * 0.5f;
	}
}
