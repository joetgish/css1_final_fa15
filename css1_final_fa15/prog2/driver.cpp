// Kristine Laranjo 
// 16 December 2015
// CSS-1 Fa15 Final Exam Prog 2
#include <iostream> //input output stream
#include <fstream> //files
#include <string> //string library
#include <cstdlib> //exit
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void elfReport(ofstream& A_out, string S[][C]);

int main()
{
	string ary[R][C];
	ifstream fin;
	ofstream fout;
	fin.open("northpole.txt"); //opens file for input
	fout.open("status.txt"); //opens file for output
	if (fin.fail() || fout.fail()) //checks if files opened correctly
	{
		cout << "Error opening file.";
		exit(1);
	}
	fillArray(fin, ary);
	fout << "Kristine Laranjo" << endl << endl;
	elfReport(fout, ary);

	fin.close(); //closes input file
	fout.close(); //closes output file
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	for(int i = 0; i < R; i++) //loop through rows
	{
		for(int j = 0; j < C; j++) //loops through columns
		{
			A_in >> S[i][j]; //adds value in file to array
		}//end of column
	}//end of rows
	return;	
}//end fillArray
// ********************************
void elfReport(ofstream& A_out, string S[][C])
{
	string north, south, east, west;
	for (int i = 1; i < R-1; i++)
	{
		for (int j = 1; j < C-1; j++)
		{
			north = S[i-1][j];
			south = S[i+1][j];
			east = S[i][j+1];
			west = S[i][j-1];

			if (north == "!" && south == "!" && east == "!" && west == "!") //all 4 zombies
			{
				A_out << "elf[" << i << "][" << j << "]: Munch!" << endl; //prints to file
			}
			else if ((north == "!" && south == "!" && east == "!") || (north == "!" && south == "!" && west == "!") ||
				(west == "!" && south == "!" && east == "!") || (north == "!" && west == "!" && east == "!") ||
				(north == "!" && south == "!" && east == "!")) //3 zombies
			{
				A_out << "elf[" << i << "][" << j << "]: Run!" << endl; //prints to file
			}
			else
			{
				continue;
			}
		}//end of column
	}//end of rows
	return;
}//end elfReport