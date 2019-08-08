#include "Soldier.h"
#include "World.h"


Soldier::Soldier()
	:owner_(nullptr),
	health_(0),
	attack_(0),
	defense_(0),
	current_direction_(Direction::BOTTOM),
	location_()
{
}

Soldier::Soldier(int owner_id, int health, int attack, int defense,const Location& location,Direction direction) 
	:owner_(FlyweightFactory::get_player(owner_id)),
	health_(health),
	attack_(FlyweightFactory::get_attack(attack)),
	defense_(FlyweightFactory::get_defense(defense)),
	current_direction_(direction),
	location_(location)
{
	
}


Soldier::~Soldier()
{
	delete owner_;
}


const Player* Soldier::get_owner()const {
	return owner_;
}

int Soldier::get_health()const {
	return health_;
}

int Soldier::get_attack()const {
	return *attack_;
}

int Soldier::get_defense()const {
	return *defense_;
}

int Soldier::get_location_x()const {
	return location_.get_x();
}
int Soldier::get_location_y()const {
	return location_.get_y();
}

void Soldier::set_health(int health) {
	if (health >= 0 || health<= 100) {
		health_ = health;
	}
}

const Location& Soldier::get_location()const {
	return location_;
}

void Soldier::set_location(const Location& location) {
	location_.set_x(location.get_x());
	location_.set_y(location.get_y());
}

void Soldier::set_location_x(int x) {
	location_.set_x(x);
}
void Soldier::set_location_y(int y) {
	location_.set_y(y);
}

Direction Soldier::get_current_direction()const {
	return current_direction_;
}

void Soldier::set_current_direction(Direction dir) {
	current_direction_ = dir;
}

void Soldier::move() {
	int x, y;
	switch (current_direction_)
	{
	case Direction::RIGHT:
		x = get_location_x() + 1;
		y = get_location_y();
		break;
	case Direction::LEFT:
		x = get_location_x() - 1;
		y = get_location_y();
		break;
	case Direction::TOP:
		x = get_location_x();
		y = get_location_y() - 1;
		break;
	case Direction::BOTTOM:
		x = get_location_x();
		y = get_location_y() + 1;
		break;
	default:
		break;
	}

	if (!World::value_at(x,y)) {
		World::swap_table_values(location_.get_x(),location_.get_y(),x,y);
		set_location_x(x);
		set_location_y(y);
	}

	current_direction_ = World::get_random_direction();
}

void Soldier::attack() const{
	int x, y;
	switch (current_direction_)
	{
	case Direction::RIGHT:
		x = get_location_x() + 1;
		y = get_location_y();
		break;
	case Direction::LEFT:
		x = get_location_x() - 1;
		y = get_location_y();
		break;
	case Direction::TOP:
		x = get_location_x();
		y = get_location_y() - 1;
		break;
	case Direction::BOTTOM:
		x = get_location_x();
		y = get_location_y() + 1;
		break;
	default:
		break;
	}

	if (World::value_at(x,y)) {
		Soldier* other = World::get_soldier_at(x,y);
		if (other) {
			other->be_attacked(this);
		}
	}

}
void Soldier::be_attacked(const Soldier* other) {
	set_health(other->get_attack()*10/other->get_defense());
}

ostream& operator<<(ostream& out,const Soldier& soldier) {
	out << "[owner_id:" << soldier.owner_->get_id() << " health:" << soldier.health_
		<< " attack:" << *soldier.attack_ << " defense:" << *soldier.defense_ << " x:" << soldier.location_.get_x() << " y:" 
		<< soldier.location_.get_y() << endl;
	return out;
}