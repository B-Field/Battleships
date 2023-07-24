#include <conio.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "Battlemap.h"
#include "Playerturn.h"
#include "Computerturn.h"
#include "Ships.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main(void)
{
	Battlemap map;
	Playerturn player;
	Computerturn computer;
	Carrier player_carrier;
	Battleship player_battleship;
	Cruiser player_cruiser;
	Submarine player_sub;
	Destroyer player_destroyer;
	Carrier computer_carrier;
	Battleship computer_battleship;
	Cruiser computer_cruiser;
	Submarine computer_sub;
	Destroyer computer_destroyer;


	int game = 0;

	map.displaymap();

	player.place_ship(player_carrier.getsname(), player_carrier.getslength());

	map.add_player_ship(player.get_x(), player.get_y(), player.get_selection(), player_carrier.getslength());

	system("CLS");

	map.displaymap();

	player.place_ship(player_battleship.getsname(), player_battleship.getslength());

	map.add_player_ship(player.get_x(), player.get_y(), player.get_selection(), player_battleship.getslength());

	system("CLS");

	map.displaymap();

	player.place_ship(player_cruiser.getsname(), player_cruiser.getslength());

	map.add_player_ship(player.get_x(), player.get_y(), player.get_selection(), player_cruiser.getslength());

	system("CLS");

	map.displaymap();

	player.place_ship(player_sub.getsname(), player_sub.getslength());

	map.add_player_ship(player.get_x(), player.get_y(), player.get_selection(), player_sub.getslength());

	system("CLS");

	map.displaymap();

	player.place_ship(player_destroyer.getsname(), player_destroyer.getslength());

	map.add_player_ship(player.get_x(), player.get_y(), player.get_selection(), player_destroyer.getslength());

	system("CLS"); 

	computer.place_computer_ship(computer_carrier.getslength());

	map.add_computer_ship(computer.getrnum1(), computer.getrnum2(), computer.getrand_dir(), computer_carrier.getslength());

	map.displaymap();

	system("CLS");

	sleep_for(2s);

	computer.place_computer_ship(computer_battleship.getslength());

	map.add_computer_ship(computer.getrnum1(), computer.getrnum2(), computer.getrand_dir(), computer_battleship.getslength());

	map.displaymap();

	system("CLS");

	sleep_for(2s);

	computer.place_computer_ship(computer_cruiser.getslength());

	map.add_computer_ship(computer.getrnum1(), computer.getrnum2(), computer.getrand_dir(), computer_cruiser.getslength());

	map.displaymap();

	system("CLS");

	sleep_for(2s);

	computer.place_computer_ship(computer_sub.getslength());

	map.add_computer_ship(computer.getrnum1(), computer.getrnum2(), computer.getrand_dir(), computer_sub.getslength());

	map.displaymap();

	system("CLS");

	sleep_for(2s);

	computer.place_computer_ship(computer_destroyer.getslength());

	map.add_computer_ship(computer.getrnum1(), computer.getrnum2(), computer.getrand_dir(), computer_destroyer.getslength());

	map.displaymap();

	system("CLS");



	while (game == 0)
	{
		map.displaymap();

		player.request_player_shot();

		system("CLS");

		map.player_shot_result(player.get_a(), player.get_b());

		computer.request_computer_shot();

		map.computer_shot_result(computer.getrnum1(), computer.getrnum2());

//		cout << computer.getrnum1();			// Test for rnum1

//		cout << computer.getrnum2();			// Test for rnum2

		map.update_game_state();

		if (map.get_pmap_state() == map.get_victory_condition())
		{
			cout << "GAME OVER" << "\n\n\ " << "You have won!\n You have conquered the computer!";
			game = 1;
		}
		else if (map.get_cmap_state() == map.get_victory_condition())
		{
			cout << "GAME OVER" << "\n\n\ " << "You have lost!\n The computer has beaten you!";
			game == 1;
		}
	}
}
