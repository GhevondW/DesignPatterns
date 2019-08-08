#pragma once
#include "Soldier.h"
#include "Building.h"

class World
{
public:
	World();
	~World();
public:
	static Direction get_random_direction();
public:
	const static int SIZE_X = 100;
	const static int SIZE_Y = 100;
	static bool** table_;
public:

	void run();
	static bool value_at(int x,int y);
	static Soldier* get_soldier_at(int x,int y);
	static void swap_table_values(int x,int y,int x1,int y1);

private:

	void init_buildings();
	void run_buildings();
	void move_soldiers();
	void attack_soldiers();
	void print_soldiers_status()const;

private:
	const Player* player_one_;
	const Player* player_two_;
	static vector<Soldier*> soldiers_;
	vector<Building*> buildings_;

};

