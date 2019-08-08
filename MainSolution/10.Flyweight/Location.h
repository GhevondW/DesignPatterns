#pragma once
class Location
{
public:
	Location(int x = 0,int y = 0);
	Location(const Location& other);
	~Location();

	int get_x()const;
	int get_y()const;

	void set_x(int x);
	void set_y(int y);

	bool operator==(const Location& other);
	bool operator!=(const Location& other) {
		return !operator==(other);
	}

private:
	int x_;
	int y_;
};

