// Name: Lesley Amezcua
// Date: December 17, 2015
// Prog2 final
#include <iostream>
#include <fstream>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void printArray(ofstream& A_out, string S[][C]);
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("northpole.txt");
	fout.open("status.txt");
	fout << "Lesley Amezcua" << endl;
	string northPole[R][C];
	fillArray(fin, northPole);
	printArray(fout, northPole);
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	for (int i = 0; i < R; i++)//Rows
	{
		for (int j = 0; j < C; j++)//Cols
		{
			A_in >> S[i][j];//fills array
		}
	}
	return;
	
}//end fillArray
void printArray(ofstream& A_out, string S[][C])
{
	for (int i = 1; i < R-1; i++)//Rows
	{
		for (int j = 1; j < C-1; j++)//Cols
		{
			int zombie = 0;//keeps count of zombies
			if (S[i][j] == "@")
			{
				if (S[i-1][j] == "!")//checks N,S,E,W
				{
					zombie++;//increments the count of zombies
				}
				if (S[i+1][j] == "!")//checks N,S,E,W
				{
					zombie++;//increments the count of zombies
				}
				if (S[i][j-1] == "!")//checks N,S,E,W
				{
					zombie++;//increments the count of zombies
				}
				if (S[i][j+1] == "!")//checks N,S,E,W
				{
					zombie++;//increments the count of zombies
				}
			}
			
			if (zombie == 3)
			{
				A_out << "elf[" << i << "] [" << j << "]: Run!" << endl;
			}
			else if (zombie == 4)
			{
				A_out << "elf[" << i << "] [" << j << "]: Munch!" << endl;
			}
			
			
			
			zombie = 0;
		}
	}

	return;
}//end printArray



 
