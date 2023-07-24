#pragma once

using namespace std;

class Playerturn
{
private:
	string a, b;
	string selection;
	string x, y;

protected:

public:
	void request_player_shot();
	void place_ship(string ship_name, int ship_length);
	string get_a();
	string get_b();
	string get_selection();
	string get_x();
	string get_y();

};
