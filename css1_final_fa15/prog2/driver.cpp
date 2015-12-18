// Name: Samuel Sanchez
// Date: 17 December 2015
// CSS-1 Fa15 Final Exam Prog 2
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void printArray(string S[][C]);
void tracker(string S[][C], ofstream& A_out);

int main()
{
	ifstream fin; // Elf positions
	ofstream fout; // Santa's elf tracker
	string positions[R][C]; // Will hold elf positions
	fin.open("northpole.txt");
	fout.open("status.txt");
	if(fin.fail() || fout.fail()) // fail stuff
	{
		cout << "Error opening file\n";
		exit(1);
	}
	fillArray(fin, positions);
	printArray(positions);
	tracker(positions, fout);
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C]) // Fills an array
{
	string input;
	for(int xi = 0; xi < R; xi++)
	{
		for(int xj = 0; xj < C; xj++)
		{
			A_in >> input;
			S[xi][xj] = input;
		}
	}	
}//end fillArray

void printArray(string S[][C]) // Prints the 30x50 field
{
	for(int xi = 0; xi < R; xi++)
	{
		for(int xj = 0; xj < C; xj++)
		{
			cout << S[xi][xj];
		}
		cout << endl;
	}	
	return;
}
//*******************************************
 void tracker(string S[][C], ofstream& A_out)
 {
 	for(int xi = 1; xi < R - 1; xi++)
	{
		for(int xj = 1; xj < C - 1; xj++)
		{
			int surrounded = 0; // Counts how many grinches surround the elf
			if(S[xi][xj] == "@") // Only executes if @ symbol "elf" is found
			{
				if(S[xi + 1][xj] == "!") // East
				{
					surrounded++;
				}
				if(S[xi][xj + 1] == "!") // North
				{
					surrounded++;
				}
				if(S[xi - 1][xj] == "!") // West
				{
					surrounded++;
				}
				if(S[xi][xj - 1] == "!") // South
				{
					surrounded++;
				}
			}
			switch(surrounded) // If at 3, elf is told to run, if at 4, elf is eaten
			{
				case 3: cout << "elf[" << xi << "] [" << xj << "] Run!\n"; break;
				case 4: cout << "elf[" << xi << "] [" << xj << "] Munch!\n"; break;
			}
		}
	}	
 	return;
 }
 //*********************************************************