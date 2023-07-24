#pragma once
#include <iostream>

using namespace std;

class Ships
{
private:
	int ship_length;
	string ship_name;

protected:

public:
	int getslength();
	string getsname();
};

 class Destroyer : public Ships
{
private:
	int ship_length = 2;
	string ship_name = "Destroyer";

public:
	int getslength();
	string getsname();
};

 class Cruiser : public Ships
{
private:
	int ship_length = 3;
	string ship_name = "Cruiser";

public:
	int getslength();
	string getsname();
};

 class Submarine : public Ships
{
private:
	int ship_length = 3;
	string ship_name = "Sub";

public:
	int getslength();
	string getsname();
};

 class Battleship : public Ships
{
private:
	int ship_length = 4;
	string ship_name = "Battleship";

public:
	int getslength();
	string getsname();
};

 class Carrier : public Ships
{
private:
	int ship_length = 5;
	string ship_name = "Carrier";

public:
	int getslength();
	string getsname();

};
