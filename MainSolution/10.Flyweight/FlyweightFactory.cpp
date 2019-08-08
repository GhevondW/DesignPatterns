#include "FlyweightFactory.h"

vector<Player*> FlyweightFactory::players_;
int FlyweightFactory::attack_values_[5] = {0};
int FlyweightFactory::defense_values_[5] = {0};


FlyweightFactory::FlyweightFactory()
{
}


FlyweightFactory::~FlyweightFactory()
{
}



const Player* FlyweightFactory::get_player(const string first_name, const string last_name, const Color color) {
	Player* newPlayer = new Player(first_name,last_name,color);
	players_.push_back(newPlayer);
	return players_[players_.size()-1];
}

const Player* FlyweightFactory::get_player(int id) {
	for (Player* player : players_) {
		if (player->get_id() == id) {
			return player;
		}
	}
	return nullptr;
}

const int* FlyweightFactory::get_attack(int key) {
	if (attack_values_[key-1] == 0) {
		attack_values_[key-1] = key;
	}
	return &attack_values_[key-1];
}

const int* FlyweightFactory::get_defense(int key) {
	if (defense_values_[key-1] == 0) {
		defense_values_[key-1] = key;
	}
	return &defense_values_[key-1];
}