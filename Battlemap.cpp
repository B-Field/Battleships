#include <conio.h>
#include <iostream>
#include "Battlemap.h"

using namespace std;

Battlemap::Battlemap()						// Initialise the map
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			setpmap(i, j, 0);
			setcmap(i, j, 0);
		}
	}
}

// Display map
void Battlemap::displaymap()
{
    cout << "  Your board. \t\t\t\t  Computer board.\n\n";
    cout << "  A B C D E F G H I J\t\t\t  A B C D E F G H I J\n";
    for (int i = 0; i < 10; i++)
    {

        //draw pmap
        cout << i << " ";
        for (int j = 0; j < 10; j++)
        {
            if (getpmap(i, j) == 0) cout << "~ ";
            if (getpmap(i, j) == 1) cout << "S ";
            if (getpmap(i, j) == 2) cout << "M ";
            if (getpmap(i, j) == 3) cout << "H ";
        }
        cout << "\t\t\t";
        //draw cmap
        cout << i << " ";
        for (int j = 0; j < 10; j++)
        {
            if (getcmap(i, j) == 0) cout << "~ ";
            if (getcmap(i, j) == 1) cout << "S ";       // Set thsi to S to see thwe ships being placed when testing
            if (getcmap(i, j) == 2) cout << "M ";
            if (getcmap(i, j) == 3) cout << "H ";
        }

        cout << "\n"; // New line
    }
}

void Battlemap::player_shot_result(string a, string b)
{
    if (a == "a") row = 0;
    if (a == "b") row = 1;
    if (a == "c") row = 2;
    if (a == "d") row = 3;
    if (a == "e") row = 4;
    if (a == "f") row = 5;
    if (a == "g") row = 6;
    if (a == "h") row = 7;
    if (a == "i") row = 8;
    if (a == "j") row = 9;

    if (b == "0") col = 0;
    if (b == "1") col = 1;
    if (b == "2") col = 2;
    if (b == "3") col = 3;
    if (b == "4") col = 4;
    if (b == "5") col = 5;
    if (b == "6") col = 6;
    if (b == "7") col = 7;
    if (b == "8") col = 8;
    if (b == "9") col = 9;

    if (getcmap(col, row) == 0)
    {
        cout << "You miss!!! ... Ahahahahahaha" << '\n' << '\n';
        setcmap(col, row, 2);
    }
    else if (getcmap(col, row) == 1)
    {
        cout << "That's a hit!!!" << '\n' << '\n';
        setcmap(col, row, 3);
    }
    else
    {
        cout << '\n';
        cout << "You've already made this shot, fool!" << '\n' << '\n';
    }
};

void Battlemap::add_player_ship(string x, string y, string selection, int ship_length)
{
    if (x == "a") row = 0;
    if (x == "b") row = 1;
    if (x == "c") row = 2;
    if (x == "d") row = 3;
    if (x == "e") row = 4;
    if (x == "f") row = 5;
    if (x == "g") row = 6;
    if (x == "h") row = 7;
    if (x == "i") row = 8;
    if (x == "j") row = 9;

    if (y == "0") col = 0;
    if (y == "1") col = 1;
    if (y == "2") col = 2;
    if (y == "3") col = 3;
    if (y == "4") col = 4;
    if (y == "5") col = 5;
    if (y == "6") col = 6;
    if (y == "7") col = 7;
    if (y == "8") col = 8;
    if (y == "9") col = 9;

    if (selection == "Y")
    {
        for (int i = ship_length; i > 0; i--)
        {
            setpmap(col, row, 1);
            row++;
        }
    }
    else if (selection == "N")
    {
        for (int i = ship_length; i > 0; i--)
        {
            setpmap(col, row, 1);
            col++;
        }
    }
}

void Battlemap::add_computer_ship(int rnum1, int rnum2, int rand_dir, int ship_length)
{
    row = rnum1;
    col = rnum2;

    if (rand_dir == 0)
    {
        for (int i = ship_length; i > 0; i--)
        {
            setcmap(col, row, 1);
            row++;
        }
    }
    else if (rand_dir == 1)
    {
        for (int i = ship_length; i > 0; i--)
        {
            setcmap(col, row, 1);
            col++;
        }
    }
}

void Battlemap::computer_shot_result(int rnum1, int rnum2)
{
    row = rnum1;
    col = rnum2;

    if (getpmap(col, row) == 0)
    {
        cout << "The computer missed! ... Lucky you!" << '\n' << '\n';
        setpmap(col, row, 2);
    }
    else if (getpmap(col, row) == 1)
    {
        cout << "That's a hit!!!" << '\n' << '\n';
        setpmap(col, row, 3);
    }
    else
    {
        cout << '\n';
        cout << "You've already made this shot, fool!" << '\n' << '\n';
    }
}

void Battlemap::update_game_state()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (getpmap(i, j) == 3);
            pmap_state++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (getcmap(i, j) == 3);
            cmap_state++;
        }
    }
}

void Battlemap::setpmap(int i, int j, int value)
{
    pmap[i][j] = value;
}

int Battlemap::getpmap(int i, int j)
{
    return pmap[i][j];
}

void Battlemap::setcmap(int i, int j, int value)
{
    cmap[i][j] = value;
}

int Battlemap::getcmap(int i, int j)
{
    return cmap[i][j];
}

int Battlemap::get_pmap_state()
{
    return pmap_state;
}

int Battlemap::get_cmap_state()
{
    return cmap_state;
}

int Battlemap::get_victory_condition()
{
    return victory_condition;
}