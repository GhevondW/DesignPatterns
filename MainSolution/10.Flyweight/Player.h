#pragma once
#include <iostream>
#include "Enums.h"

using namespace std;

class Player
{
public:
	Player(const string& first_name, const string& last_name, const Color& color);
	Player(const Player& other);
	~Player();

public:

	int get_id()const;
	const string& get_first_name()const;
	const string& get_last_name()const;
	Color get_color()const;

private:
	const int id_;
	const string first_name_;
	const string last_name_;
	const Color color_;

private:
	static int id_counter;
};

