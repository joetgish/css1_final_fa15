// Name: Diego Medina
// Date: 12-17-15
// Description: Prog 2
#include <iostream>	//cin cout
#include <fstream>	//fin fout
#include <cstdlib>	//exit()
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void printArray(ofstream& A_out, string S[][C]);
void checkZombies(ofstream& A_out, string S[][C]);

int main()
{

	string map[R][C];

	ifstream fin;
	ofstream fout;

	fin.open("northpole.txt");
	fout.open("status.txt");

	if(fin.fail() )
	{
		cout << "Error opening input file." << endl;
		exit(1);
	}

	if(fout.fail() )
	{
		cout << "Error opening output file." << endl;
		exit(1);
	}

	fillArray(fin, map);
	//printArray(fout, map);
	checkZombies(fout, map);

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

		for(int jx = 0; jx < C; jx++)
		{
			A_in >> str;
			S[ix][jx] = str;

		}

	}


	return;
}//end fillArray

// ********************************
void printArray(ofstream& A_out, string S[][C])
{
	for(int ix = 0; ix < R; ix++)
	{

		for(int jx = 0; jx < C; jx++)
		{
			A_out << S[ix][jx] << " ";
		}

		A_out << endl;
	}

	return;

}

// ********************************
void checkZombies(ofstream& A_out, string S[][C])
{
	int zombies = 0;

	A_out << "Diego Medina" << endl << endl;


	//start at 1 and subtract 1 from R and C to avoid looking at the borders
	for(int ix = 1; ix < R - 1; ix++)
	{

		for(int jx = 1; jx < C - 1; jx++)
		{

			if(S[ix][jx] == "@")
			{
				//checks N,S,E,W for zombies
				if(S[ix - 1][jx] == "!")
				{
					zombies++;
				}
			
				if(S[ix + 1][jx] == "!")
				{
					zombies++;
				}

				if(S[ix][jx + 1] == "!")
				{
					zombies++;
				}

				if(S[ix][jx - 1] == "!")
				{
					zombies++;
				}	

				//displays message to file
				if(zombies == 3)
				{
					A_out << "Elf[" << ix << "][" << jx << "]: Run!" << endl << endl;
				}

				if(zombies == 4)
				{
					A_out << "Elf[" << ix << "][" << jx << "]: Munch!" << endl << endl;
				}
			
			}//end if array location is an elf
	
			zombies = 0;
		}//for jx

	}//forix

	return;	


}


 
