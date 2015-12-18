// Steven Groves
// 17 Dec 2015
// CSS-1 Fa15 Final Exam Prog 2
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
bool elfCheck(string S[][C], int y, int x);
int zombieCheck(string S[][C], int y, int x);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("northpole.txt");
	fout.open("status.txt");
	if(fin.fail() || fout.fail())
	{
		cout << "Error opening files" << endl;
		exit(1);
	}
	string snowField[R][C];
	fillArray(fin, snowField);

	fout << "Steven Groves" << endl;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if(elfCheck(snowField, i, j))
			{
				if(zombieCheck(snowField, i, j) == 3)
				{
					fout << "Elf[" << i << "][" << j << "]";
					fout << ": Run!" << endl;
				}
				else if(zombieCheck(snowField, i, j) == 4)
				{
					fout << "Elf[" << i << "][" << j << "]";
					fout << ": Munch!" << endl;
				}
			}
		}
	}
	


	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			A_in >> S[i][j];
		}
	}
	return;
}//end fillArray

// ********************************
bool elfCheck(string S[][C], int y, int x)
{
	if(S[y][x] == "@")
		return true;

	return false;
}// end elfCheck

// ********************************
int zombieCheck(string S[][C], int y, int x)
{
	int counter = 0;
	if (y - 1 >= 0 && S[y-1][x] == "!")
	{
		counter++;
	}
	if (x - 1 >= 0 && S[y][x-1] == "!")
	{
		counter++;
	}
	if (y + 1 < R && S[y+1][x] == "!")
	{
		counter++;
	}
	if (x + 1 < C && S[y][x+1] == "!")
	{
		counter++;
	}
	return counter;
}// end zombieCheck


 