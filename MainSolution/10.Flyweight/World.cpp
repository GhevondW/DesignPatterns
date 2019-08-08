#include "World.h"
#include <thread>

bool** World::table_;
vector<Soldier*> World::soldiers_;


World::World()
{
	player_one_ = FlyweightFactory::get_player("Fn1","Ln1",Color::RED);
	player_two_ = FlyweightFactory::get_player("Fn2","Ln2",Color::BLUE);

	table_ = new bool*[SIZE_X];
	for (size_t i = 0; i < SIZE_X; i++)
	{
		table_[i] = new bool[SIZE_Y];
		for (size_t j = 0; j < SIZE_Y; j++)
		{
			table_[i][j] = false;
		}
	}
}


World::~World()
{
	for (size_t i = 0; i < SIZE_X; i++)
	{
		delete[] table_[i];
	}
	delete[] table_;
}

Direction World::get_random_direction() {
	int r = rand() % 4 + 1;
	Direction direction;
	switch (r)
	{
	case 1:
		direction = Direction::LEFT;
		break;
	case 2:
		direction = Direction::RIGHT;
		break;
	case 3:
		direction = Direction::BOTTOM;
		break;
	default:
		direction = Direction::TOP;
		break;
	}
	return direction;
}

void World::swap_table_values(int x, int y, int x1, int y1) {
	if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y) {
		if (x1 >= 0 && x1 < SIZE_X && y1 >= 0 && y1 < SIZE_Y) {
			bool temp = table_[x][y];
			table_[x][y] = table_[x1][y1];
			table_[x1][y1] = temp;
		}
	}
}

bool World::value_at(int i,int j){
	if (i >= 0 && i < SIZE_X) {
		if (j >= 0 && j < SIZE_Y) {
			return table_[i][j];
		}
	}
	return false;
}
Soldier* World::get_soldier_at(int x, int y) {
	if (value_at(x,y)) {
		for (Soldier* s:soldiers_) {
			if (s->get_location_x() == x && s->get_location_y() == y) {
				return s;
			}
		}
	}
	return nullptr;
}

void World::init_buildings() {
	int count = 0;
	int i, j;
	while (count < 20)
	{
		i = rand() % 100;
		j = rand() % 100;
		int player_id;
		if (count < 10) {
			player_id = player_one_->get_id();
		}
		else {
			player_id = player_two_->get_id();
		}

		if (!table_[i][j]) {
			table_[i][j] = true;
			buildings_.push_back(new Building(player_id,i,j));
			count++;
		}
	}
}

void World::run_buildings() {
	for (Building* b:buildings_) {
		Soldier* s = b->get_soldier();
		if (s) {
			soldiers_.push_back(s);
		}
	}
}

void World::move_soldiers() {
	for (Soldier* s:soldiers_) {
		s->move();
	}
}

void World::attack_soldiers() {
	for (Soldier* s : soldiers_)
	{
		s->attack();
	}
}

void World::print_soldiers_status()const {
	for (Soldier* s : soldiers_)
	{
		cout << *s << endl;
	}
}

void World::run() {
	init_buildings();
	for (size_t i = 0; i < 1000; i++)
	{
		run_buildings();
		move_soldiers();
		attack_soldiers();
		print_soldiers_status();
		std::this_thread::sleep_for(2s);
		system("CLS");
	}
}

