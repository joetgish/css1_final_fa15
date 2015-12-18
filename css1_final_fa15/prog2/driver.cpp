// Name: Chanel Aquino
// Date Created: 17 December 2015
// Description: CSS-1 Fa15 Final Exam Prog 2: Elf Report

#include <iostream>
#include <fstream>	// ifstream, ofstream
#include <cstdlib>	// exit()
#include <string>	

using namespace std;

// given constants
const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void checkElf(string ary[][C], ofstream& A_out);

int main()
{
	// create input and output file streams
	ifstream fin;
	ofstream fout;

	// open files
	fin.open("northpole.txt");
	fout.open("status.txt");
	
	// check fail
	if(fin.fail() || fout.fail())
	{
		cout << "Error. Exiting now."<<endl;
		exit(1);
	}

	fout << "Name: Chanel Aquino" << endl << endl;

	// create empty 2D array with dimensions R x C
	string christmas[R][C];

	// fill array christmas with input values from fin
	fillArray(fin, christmas);

	// check status of elf in array christmas and output data to fout
	checkElf(christmas, fout);

	// close files
	fin.close();
	fout.close();
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	string symbol;

	// execute loop R amount of times
	for(int i = 0; i < R; i++)
	{
		// execute loop C amount of times
		for(int j = 0; j < C; j++)
		{
			// read data from A_in and store value in symbol
			A_in >> symbol;

			// set value of S array at index [i][j] to symbol
			S[i][j] = symbol;
		}
	}

	return;
} //end fillArray()

// ********************************
void checkElf(string ary[][C], ofstream& A_out)
{
	// execute loop R amount of times
	for(int i = 0; i < R; i++)
	{
		// execute loop C amount of times
		for(int j = 0; j < C; j++)
		{
			// ignore outer rows and columns
			if( (i != 0 && i != R-1) && (j != 0 && j != C-1) )
			{
				// if ary[i][j] is an elf is surrounded by zombies (indicated by "!") on 4 adjacent sides
				if( (ary[i][j] == "@") 
					&& (ary[i - 1][j] == "!")	// element directly above
					&& (ary[i][j + 1] == "!") 	// element to the right
					&& (ary[i + 1][j] == "!")	// element directly below
					&& (ary[i][j - 1] == "!") 	// element to the left
				  )
				{
					// output to file: "elf[i][j]: Munch!"
					A_out << "elf" << "[" << i << "]" << "[" << j << "]: Munch!" << endl; 
				} // end if

				// if ary[i][j] is an elf and is surrounded by zombies on 3 adjacent sides
				if( (ary[i][j] == "@") 
					&& 
				  ( 	((ary[i - 1][j] == "!") 	// element directly above
				  		&& (ary[i][j + 1] == "!")	// element to the right
				  		&& (ary[i + 1][j] == "!")) 	// element directly below
				  	|| 
				  		((ary[i - 1][j] == "!") 	// element directly above
				  		&& (ary[i + 1][j] == "!")	// element directly below
				  		&& (ary[i][j - 1] == "!"))	// element to the left
				  	|| 
				  		((ary[i - 1][j] == "!")		// element directly above
				  		&& (ary[i][j + 1] == "!") 	// element to the right
				  		&& (ary[i][j - 1] == "!"))	// element to the left
				  	||
				  		((ary[i][j + 1] == "!") 	// element to the right
				  		&& (ary[i + 1][j] == "!")	// element directly below
				  		&& (ary[i][j - 1] == "!"))	// element to the left
				  ))
				{
					// output to file: "elf[i][j]: Run!"
					A_out << "elf" << "[" << i << "]" <<"[" << j << "]: Run!" << endl;
				} // end if
			} // end outer if
		} // end inner for
	} // end outer for

	return;
} // end checkElf()



 