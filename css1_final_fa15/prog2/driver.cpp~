// Emily Garcia
// Dec 17 2015
// CSS-1 Fa15 Final Exam Prog 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void printArray(string ary[][C]);
void checkZombies(string S[][C], ofstream& A_out);

int main()
{
	ifstream fin;
	fin.open("northpole.txt");
	ofstream fout;
	fout.open("status.txt");
	
	string map[R][C];
	
	fillArray(fin, map);
	//printArray(map);
	fout << "Emily Garcia\n" << endl;
	checkZombies(map, fout);
	
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	string makeMap;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			A_in >> S[i][j];
		}
	}
	return;
}//end fillArray
//*************************************
void printArray(string S[][C])
{
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			cout << S[i][j];
		}
		cout << endl;
	}
	return;
}// end print Vector(_)
//*************************************
void checkZombies(string S[][C], ofstream& A_out)
{
	string elf = "@";
	string zombie = "!";
	string blankSpace = "*";
	for(int i = 1; i < R-1; i++)
	{
		for(int j = 1; j < C-1; j++)
		{
			if(S[i][j] == elf)
			{
				//check for three zombies
				if(((S[i-1][j] == zombie) && (S[i][j-1] == zombie) && (S[i][j+1] == zombie) && (S[i+1][j] == blankSpace)) ||
				((S[i-1][j] == zombie) && (S[i][j-1] == zombie) && (S[i][j+1] == blankSpace) && (S[i+1][j] == zombie)) || 
				((S[i-1][j] == zombie) && (S[i][j-1] == blankSpace) && (S[i][j+1] == zombie) && (S[i+1][j] == zombie)) || 
				((S[i-1][j] == blankSpace) && (S[i][j-1] == zombie) && (S[i][j+1] == zombie) && (S[i+1][j] == zombie)))
				{
					A_out << "elf[" << i << "][" << j << "]: Run!" << endl;
				}
				
				//check for four zombies
				if((S[i-1][j] == zombie) && (S[i][j-1] == zombie) && (S[i][j+1] == zombie) && (S[i+1][j] == zombie))
				{
					A_out << "elf[" << i << "][" << j << "]: Munch!" << endl;
				}
			}
		}
	}
	return;
}// end check Zombies(_)



 
