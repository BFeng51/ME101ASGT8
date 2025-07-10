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
int nextValidParking(int isStaff[MAX_PARKING], int status)
{
	for(int i = 0; i < MAX_PARKING; i++)
	{
		if(isStaff[i] == -1)
		{
			
			if(i < 25)
			{
				if(status == 1)
					return i;
			}
			else
				return i;
				
		}
	}
	return -1;
}

// PART H
void output(ofstream & fout, int isStaff[NEW_DATA_RANGE], string names[NEW_DATA_RANGE])
{
	for(int i = 0; i < MAX_PARKING; i++)
	{
		fout << i + 101;
		
		if(isStaff[i] == -1)
			fout << "   Empty";
		else
			fout << setw(25) << names[i] << setw(5) << isStaff[i] << endl;
	}
}


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

//PART B
void  populateParking(ifstream & fin, string names[MAX_PARKING], int isStaff[MAX_PARKING] )
{
	
	string currName="";
	int personType, spotNum = -1;
	
	while(fin>>personType>>currName>>spotNum)
	{
		i=spotNum-101;
		
		isStaff[i]=personType;
		names[i]=currName;
		
	}
}

//PART D
void clearSpot(names[MAX_PARKING],isStaff[MAX_PARKING], string deleteName, int status)
{
	for(int i = 0; i<MAX_PARKING; i++)
	{
		if(names[i]==deleteName)
		{
			names[i]=" ";
			isStaff[i]=-1;
		}
	}
}

//PART F
bool addName(names[MAX_PARKING],isStaff[MAX_PARKING],string addName, int status)
{
	bool addedSuccessfully = true;
	
	if(nextValidParking(isStaff[MAX_PARKING], status)==-1)
	{
		 addedSuccessfully = false;
		 return addedSuccessfully;
	}
	
	return addedSuccessfully;
}
