#include "Building.h"
#include "World.h"


Building::Building(int owner_id,int x,int y)
	:owner_(FlyweightFactory::get_player(owner_id)),
	attack_value_(rand()%5 +1),
	defense_value_(rand()%5 + 1),
	location_(x,y),
	direction_(World::get_random_direction()),
	counter(0)
{
	
}


Building::~Building()
{
}

Soldier* Building::get_soldier() {
	if (counter <= 100) {
		counter++;
		int health = rand() % 100 + 1;
		return new Soldier(owner_->get_id(), health, attack_value_, defense_value_, location_, direction_);
	}
	return nullptr;
}
