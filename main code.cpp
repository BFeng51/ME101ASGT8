//PARTNER A - BRADY FENG
//PARTNER B - IVAN CHEN
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int NEW_DATA_RANGE = 30;
const int MAX_PARKING = 50;

//PART B
void  populateParking(ifstream & fin, string names[MAX_PARKING], int isStaff[MAX_PARKING] )
{
	
	string currName="";
	int personType, spotNum = -1;
	
	while(fin>>personType>>currName>>spotNum)
	{
		int i=spotNum-101;
		
		isStaff[i]=personType;
		names[i]=currName;
		
	}
}

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

//PART D
void clearSpot(string names[MAX_PARKING],int isStaff[MAX_PARKING], string deleteName, int status)
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

// PART E
int nextValidParking(int isStaff[MAX_PARKING], int status)
{
	for(int i = 0; i < MAX_PARKING; i++)
	{
		if(isStaff[i] == -1)
		{
			
			if(i < 25 && status == 1)
				return i;
				
			else if(i >= 25)
				return i;
				
		}
	}
	return -1;
}

//PART F
bool addName(string names[MAX_PARKING], int isStaff[MAX_PARKING],string addName, int status)
{
	int nextSpot = nextValidParking(isStaff, status);
	
	if(nextSpot == -1)
	{
		 return false;
	}
	
	else
	{
		isStaff[nextSpot]=	status;
		names[nextSpot]=addName;
	}
	
	
	return true;
}

// PART G
void rearrange(int isStaff[NEW_DATA_RANGE], string names[NEW_DATA_RANGE])
{
	for(int i = 25; i < 50; i++)
	{
		if(isStaff[i] == 1)
			addName(names, isStaff, names[i], isStaff[i]);
	}
}


// PART H
void output(ofstream & fout, int isStaff[NEW_DATA_RANGE], string names[NEW_DATA_RANGE])
{
	for(int i = 0; i < MAX_PARKING; i++)
	{
		cout << i + 101;
		
		if(isStaff[i] == -1)
			cout << setw(25) << "Empty" << endl;
		else
			cout << setw(25) << names[i] << setw(5) << isStaff[i] << endl;
	}
}


int main()
{
	ifstream parking_current("parking_current.txt");
	ifstream parking_remove("parking_remove.txt");
	ifstream parking_add("parking_add.txt");
	
	if(!parking_current || !parking_remove || !parking_add)
	{
		cout << "File not found :(" << endl;
		return EXIT_FAILURE;
	}
	
	int facultyOrStudent[MAX_PARKING] = {};
	for(int i = 0; i < MAX_PARKING; i++)
		facultyOrStudent[i] = -1;
		
	string names[MAX_PARKING] = {};
	
	//PART I
	ofstream outputA("outputA.txt");
	//state a)
	populateParking(parking_current, names, facultyOrStudent);
	output(outputA, facultyOrStudent, names);
	
	int facultyOrStudent_remove[NEW_DATA_RANGE] = {};
	string names_remove[NEW_DATA_RANGE] = {};
	readNewData(parking_remove, facultyOrStudent_remove, names_remove);
	//output(outputA, facultyOrStudent_remove, names_remove);
	
	int facultyOrStudent_add[NEW_DATA_RANGE] = {};
	string names_add[NEW_DATA_RANGE] = {};
	readNewData(parking_add, facultyOrStudent_add, names_add);
	//output(outputA, facultyOrStudent_add, names_add);
	
	//clearSpot(names, facultyOrStudent, "Tesla_Nick", 1);
	
	
	cout<<"Test Parking Lot:"<<endl;
	output(outputA, facultyOrStudent, names);
	
	cout << endl << endl << endl;
	addName(names, facultyOrStudent, "Brady_Feng", 0);
	output(outputA, facultyOrStudent, names);
	
	//cout << nextValidParking(facultyOrStudent, 1)+101 << endl;
	//cout << nextValidParking(facultyOrStudent, 0)+101 << endl;
	
	
	//state b)
	
	
	int removingIsStaff[NEW_DATA_RANGE]={};
	string removingNames[NEW_DATA_RANGE]={};
	
	readNewData(parking_remove, removingIsStaff, removingNames);

	
	for(int i = 0; i<NEW_DATA_RANGE; i++)
	{
		clearSpot(names, facultyOrStudent, removingNames[i], removingIsStaff[i]);
	}
	

	rearrange(facultyOrStudent, names );

	
	cout<<"Removed and Reassigned Parking Lot:"<<endl;
	output(outputA, facultyOrStudent, names);

	//state c)
//	cout<<"Final Parking Lot:"<<endl;
	int addingIsStaff[NEW_DATA_RANGE]={};
	string addingNames[NEW_DATA_RANGE]={};
	
	readNewData(parking_add, addingIsStaff, addingNames);
}






