#pragma once

#include "Soldier.h"

class Building
{
public:
	Building(int owner_id,int x,int y);
	~Building();

public:
	Soldier* get_soldier();
private:
	const Player* owner_;
	const int attack_value_;
	const int defense_value_;
	const Location location_;
	Direction direction_;

private:
	const int MAX_SOLDIERS_COUNT = 100;
	int counter;
};

