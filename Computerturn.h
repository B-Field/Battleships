#pragma once

using namespace std;

class Computerturn
{
private:
	int rnum1, rnum2;
	int rand_dir;

protected:

public:
	void request_computer_shot();
	void place_computer_ship(int ship_length);
	int getrnum1();
	int getrnum2();
	int getrand_dir();

};
