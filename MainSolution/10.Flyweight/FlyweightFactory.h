#pragma once
#include <vector>
#include "Player.h"
using namespace std;

class FlyweightFactory
{
public:
	FlyweightFactory();
	~FlyweightFactory();

public:

	static const Player* get_player(const string first_name,const string last_name,const Color color);
	static const Player* get_player(int id);
	static const int* get_attack(int key);
	static const int* get_defense(int key);

private:
	static vector<Player*> players_;
	static int attack_values_[];
	static int defense_values_[];
};

