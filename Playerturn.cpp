#include <conio.h>
#include <iostream>
#include "Playerturn.h"
#include "Ships.h"

using namespace std;

void Playerturn::request_player_shot()
{
    cout << "\n";
    std::cout << "Enter a letter a-j" << '\n';
    std::cin >> a;
    std::cout << "Enter a number 0-9" << '\n';
    std::cin >> b;
    std::cout << '\n';
    //      std::cout << a << " " << b << '\n';
}

void Playerturn::place_ship(string ship_name, int ship_length)
{
    retry:
    std::cout << "\n" << "The current ship is : " << ship_name << " With length " << ship_length << '\n';
    std::cout << "Would you like to place this ship horizontally? (Y/N)" << '\n';
    std::cin >> selection;
    if (selection == "y")
        selection = "Y";
    if (selection == "n")
        selection = "N";
    if (get_selection() == "Y")
        // Horizontal placement
    {
        std::cout << "Please select where you would like to place this ship" << '\n';
        std::cout << "The ship will begin at the location you choose and will continue right" << '\n';
        std::cout << "Enter a letter a-j" << '\n';
        std::cin >> x;
        std::cout << "Enter a number 0-9" << '\n';
        std::cin >> y;
    }
    // Vertical placement
    else if (get_selection() == "N")
    {
        std::cout << "Please select where you would like to place this ship" << '\n';
        std::cout << "The ship will begin at the location you choose and will continue down" << '\n';
        std::cout << "Enter a letter a-j" << '\n';
        std::cin >> x;
        std::cout << "Enter a number 0-9" << '\n';
        std::cin >> y;
    }
    else 
    {
        std::cout << "\nTry again!\n";
        goto retry;
    }
};

string Playerturn::get_a()
{
    return a;
}

string Playerturn::get_b()
{
    return b;
}

string Playerturn::get_selection()
{
    return selection;
}

string Playerturn::get_x()
{
    return x;
}

string Playerturn::get_y()
{
    return y;
}