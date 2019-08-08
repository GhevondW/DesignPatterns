#include "Location.h"
#include "World.h"


Location::Location(int x,int y){
	if (x >= 0 && x < World::SIZE_X) {
		x_ = x;
	}
	else {
		x_ = 0;
	}
	if (y >= 0 && y < World::SIZE_Y) {
		y_ = y;
	}
	else {
		y_ = 0;
	}
}

Location::Location(const Location& location) {
	x_ = location.get_x();
	y_ = location.get_y();
}

Location::~Location()
{
}


int Location::get_x()const {
	return x_;
}

int Location::get_y()const {
	return y_;
}

void Location::set_x(int x) {
	if (x >= 0 || x < World::SIZE_X) {
		x_ = x;
	}
}

void Location::set_y(int y) {
	if (y >= 0 || y < World::SIZE_X) {
		y_ = y;
	}
}

bool Location::operator==(const Location& other) {
	if (x_ == other.get_x() && y_ == other.get_y()) {
		return true;
	}
	return false;
}