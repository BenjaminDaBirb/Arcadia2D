#pragma once
#include "Actor.h"
#include <string>

class Character : public Actor {

public:
	Character(Properties props): Actor(props) {}

	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void Update(float dt) = 0;

protected:
	std::string m_name;
};