// Name: Nicholas Rosas
// Date: 12-17-15
// CSS-1 Fa15 Final Exam Prog 2
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
/*
	Summary: Function fills array with values read from an input file
	Precondition: File input stream, empty array to store values from file
	Postcondition: Filled array
*/
void statusUpdate(string S[][C], ofstream& A_out);
/*
	Summary: Checks the status of the elves and uses the 'checkSides()' and 'elfStatus()' functions
	Precondition: Array that contains the grid of elves, zombies, and blank spaces, output file stream: to be passed to 'elfStatus()' (Not used in this function besides to pass to the elfStatus function.
	Postcondition: When finished running, an update containing the status of the elves will be in 'status.txt'
*/
int checkSides(string S[][C], int row, int col);
/*
	Summary: Checks the sides of an elf to look for zombies
	Precondition: Location of elf (row/col), full layout of elves/zombies (array)
	Postcondition: Returns the number of zombies adjacent to the elf (0 - 4)
*/
void elfStatus(int numberOfZombies, int row, int col, ofstream& A_out);
/*
	Summary: Writes the elf status in the output file
	Precondition: Number of zombies adjacent to elf, elf's location, and output stream
	Postcondition: Status of current elf written to 'status.txt'
*/

int main()
{
	string ary[R][C];
	ifstream fin;
	ofstream fout;

	fin.open("northpole.txt");
	fout.open("status.txt");

	if(fin.fail() || fout.fail())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}

	fout << "Nicholas Rosas\n\n";

	fillArray(fin, ary);
	statusUpdate(ary, fout);

	fin.close();
	fout.close();
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	string str;

	for(int ix = 0; ix < R; ix++)
	{
		str = "";
		for(int jx = 0; jx < C; jx++)
		{
			if(A_in >> str)
			{
				S[ix][jx] = str;
			}
		}
	}
}//end fillArray
// ********************************
void statusUpdate(string S[][C], ofstream& A_out)
{
	int numZombies;

	for(int ix = 1; ix < R - 1; ix++)
	{
		numZombies = 0;

		for(int jx = 1; jx < C - 1; jx++)
		{
			string str = S[ix][jx];
			if(str == "@")
			{
				numZombies = checkSides(S, ix, jx);
				elfStatus(numZombies, ix, jx, A_out);
			}	
		}
	}

} // statusUpdate()

int checkSides(string S[][C], int row, int col)
{
	int counter = 0;
	if(S[row-1][col] == "!")
		counter++;
	if(S[row+1][col] == "!")
		counter++;
	if(S[row][col-1] == "!")
		counter++;
	if(S[row][col+1] == "!")
		counter++;
	
	return counter;
} // checkSides()

void elfStatus(int numberOfZombies, int row, int col, ofstream& A_out)
{
	if(numberOfZombies == 3)
	{
		A_out << "elf[" << row << "][" << col << "]: Run!\n";
	}
	if(numberOfZombies == 4)
	{
		A_out << "elf[" << row << "][" << col << "]: Munch!\n";
	}
} // end elfStatus
 
