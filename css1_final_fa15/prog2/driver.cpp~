// Louis Paul Romero
// December 17, 2015
// Program 2

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& fin, string ary[][C]);

void printArray(string ary[][C]);

int main()
{
	ifstream finNorthPoleText;
	ofstream foutStatusText;
	string arrayOfData[R][C];
	int numberOfZombies = 0;
	
	finNorthPoleText.open("northpole.txt");
	foutStatusText.open("status.txt");
	
	if(finNorthPoleText.fail()||foutStatusText.fail())
	{
		cout << "Error opening file" << endl;
		exit(1);	
	}

	
	

	fillArray(finNorthPoleText, arrayOfData);

	foutStatusText << "Louis Paul Romero" << endl;
	//CHECKING FOR ZOMBIES
	for(int ix = 1; ix < R-1; ix++)
	{
		for(int jx = 1; jx < C-1; jx ++)
		{
			if((arrayOfData[ix][jx] == "@") && (arrayOfData[ix-1][jx] == "!")) //check north
			{
				numberOfZombies++;						
			}
			if( (arrayOfData[ix][jx] == "@") && (arrayOfData[ix+1][jx] == "!"))//check south 
			{
				numberOfZombies++;						
			}
			if( (arrayOfData[ix][jx] == "@") && (arrayOfData[ix][jx+1] == "!"))//check east
			{
				numberOfZombies++;						
			}
			if( (arrayOfData[ix][jx] == "@") && (arrayOfData[ix][jx-1] == "!"))//check west
			{
				numberOfZombies++;						
			}
			
			if(numberOfZombies == 4)
			{
				foutStatusText << "elf[" << ix << "]" << "[" << jx <<"]: MUNCH!";	
				foutStatusText << endl;
						
			}
			if(numberOfZombies == 3)
			{
				foutStatusText << "elf[" << ix << "]" << "[" << jx <<"]: Run!";	
				foutStatusText << endl;		
			}
			numberOfZombies = 0;	
		}
		
	}
	//CHECKING FOR ZOMBIES


	finNorthPoleText.close();
	foutStatusText.close();
	
		
	return 0;
}

// ********************************
void fillArray(ifstream& fin, string ary[][C])
{
	for(int ix = 0; ix < R; ix++)
	{
		for(int jx = 0; jx < C; jx ++)
		{
			fin >> ary[ix][jx];		
		}
	}

}//end fillArray

void printArray(string ary[][C])
{
	for(int ix = 0; ix < R; ix++)
	{
		for(int jx = 0; jx < C; jx++)
		{
			cout << ary[ix][jx];		
		}
		cout << endl;
	}
}//end printArray




 
