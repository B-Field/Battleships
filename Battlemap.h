#pragma once

using namespace std;

class Battlemap
{
private:
	int pmap[10][10];
	int cmap[10][10];
	int col;
	int row;
	int pmap_state = 0;
	int cmap_state = 0;
	int victory_condition = 17;

protected:

public:
	Battlemap();		// Initialise constructor
	void displaymap();
	void player_shot_result(string a, string b);
	void computer_shot_result(int rnum1, int rnum2);
	void add_player_ship(string x, string y, string selection, int ship_length);
	void add_computer_ship(int rnum1, int rnum2, int rand_dir, int ship_length);
	void update_game_state();
	void setpmap(int i, int j, int value);
	int getpmap(int i, int j);
	void setcmap(int i, int j, int value);
	int getcmap(int i, int j);
	int get_pmap_state();
	int get_cmap_state();
	int get_victory_condition();

};
