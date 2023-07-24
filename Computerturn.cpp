#include <conio.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <ctime>
#include "Computerturn.h"

using namespace std;
/*	using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;	*/

void Computerturn::request_computer_shot()
{
	srand(time(0));
	rnum1 = rand() % 10;
	rnum2 = rand() % 10;
}

void Computerturn::place_computer_ship(int ship_length)
{
	srand(time(0));
	rand_dir = rand() % 2;
	if (rand_dir == 0)
	{
		rnum1 = rand() % ship_length;
		rnum2 = rand() % 10;
	}
	else if (rand_dir == 1)
	{
		rnum1 = rand() % 10;
		rnum2 = rand() % ship_length;
	}
}

int Computerturn::getrnum1()
{
	return rnum1;
}

int Computerturn::getrnum2()
{
	return rnum2;
}

int Computerturn::getrand_dir()
{
	return rand_dir;
}