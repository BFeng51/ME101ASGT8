#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int NEW_DATA_RANGE = 30;
const int MAX_PARKING = 50;

// PART C
void readNewData(ifstream & fin, int isStaff[NEW_DATA_RANGE], string names[NEW_DATA_RANGE])
{
	int staff = 0;
	string name = "";
	int i = 0;
	while(fin >> staff >> name)
	{
		isStaff[i] = staff;
		names[i] = name;
		i++;
	}
}

// PART E
int nextValidParking(int isStaff[MAX_PARKING], int status);

int main()
{
	ifstream parking_current(parking_current.txt);
	ifstream parking_remove(parking_remove.txt);
	ifstream parking_add(parking_add.txt);
	
	if(!parking_current || !parking_remove || !parking_add)
	{
		cout << "File not found :(" << endl;
		return EXIT_FAILURE;
	}
	
	int facultyOrStudent[MAX_PARKING] = {};
	for(int i = 0; i < MAX_PARKING; i++)
		facultyOrStudent[i] = -1;
		
	string names[MAX_PARKING] = {};
	
	
	
}