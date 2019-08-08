#pragma once
#include "Location.h"
#include "FlyweightFactory.h"

class Soldier
{
public:
	Soldier();
	Soldier(int owner_id, int health, int attack, int defense,const Location& location,Direction direction);
	~Soldier();

	const Player* get_owner()const;
	int get_health()const;
	int get_attack()const;
	int get_defense()const;
	Direction get_current_direction()const;
	const Location& get_location()const;
	int get_location_x()const;
	int get_location_y()const;

	void set_health(int health);
	void set_location(const Location& location);
	void set_location_x(int x);
	void set_location_y(int y);
	void set_current_direction(Direction direction);

	friend ostream& operator<<(ostream& out,const Soldier& soldier);

public:

	void move();
	void attack() const;
	void be_attacked(const Soldier* other);

private:
	const Player* owner_;
	int health_;
	const int* attack_;
	const int* defense_;
	Location location_;
	Direction current_direction_;
};

