////////////////////////////////////////////////////////////////////////
// MonsterOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "MonsterOccurrence.hpp"

namespace Collisions
{
	MonsterOccurrence::State MonsterOccurrence::getState()
	{
		return _state;
	}

	void MonsterOccurrence::setState(State state)
	{
		_state = state;
	}


	void MonsterOccurrence::update(RenderWindow& app)
	{
		updateMonsterActivity(app);

		/* Update physic position */
		/* Save actual position in previous prosition */
		_previousPosition = _position;

		/* Compute new position */
		this->setPosition(_position.x + _speed.x * app.GetFrameTime(), 
			_position.y + _speed.y * app.GetFrameTime());
	}

	void MonsterOccurrence::render(RenderWindow& app)
	{

	}

	void MonsterOccurrence::updateMonsterActivity(RenderWindow& app)
	{
		const View& view = app.GetDefaultView();

		if(this->getHitboxPosition().x < view.GetCenter().x - view.GetHalfSize().x
			|| this->getHitboxPosition().x + this->getHitboxSize().x < view.GetCenter().x + view.GetHalfSize().x
			|| this->getHitboxPosition().y > view.GetCenter().y + view.GetHalfSize().y
			|| this->getHitboxPosition().y + this->getHitboxSize().y < view.GetCenter().y - view.GetHalfSize().y)
		{
			
			if(this->_initialPosition.x < view.GetCenter().x - view.GetHalfSize().x
			|| this->_initialPosition.x + this->getHitboxSize().x < view.GetCenter().x + view.GetHalfSize().x
			|| this->_initialPosition.y > view.GetCenter().y + view.GetHalfSize().y
			|| this->_initialPosition.y + this->getHitboxSize().y < view.GetCenter().y - view.GetHalfSize().y)
			{
				/* If view pass monster's initial position, we put monster as the beginning of the level */
				_position = _initialPosition;
				_previousPosition = _initialPosition;
				_state = M_WALK;
				_speed.x = -M_SPEED_WALK_MIN;
				_side = LEFT_SIDE;
			}

			_isActive = false;
		}
		else
			_isActive = true;

	}

    MonsterOccurrence::~MonsterOccurrence()
    {		
    }
} // namespace
