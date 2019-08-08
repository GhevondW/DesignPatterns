#include "Player.h"


int Player::id_counter;

Player::Player(const string& first_name,const string& last_name,const Color& color)
	: id_(++id_counter),
	first_name_(first_name),
	last_name_(last_name),
	color_(color)
{

}

Player::Player(const Player& other)
	:id_(other.get_id()),
	first_name_(other.get_first_name()),
	last_name_(other.get_last_name()),
	color_(other.get_color())
{

}

Player::~Player()
{
	id_counter--;
}

int Player::get_id()const {
	return id_;
}
const string& Player::get_first_name()const {
	return first_name_;
}
const string& Player::get_last_name()const {
	return last_name_;
}
Color Player::get_color()const {
	return color_;
}
