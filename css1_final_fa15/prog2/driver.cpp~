//David Jia
//12-17-15 
//CSS-1 Final Exam Prog2 
#include <iostream> //input output
#include <fstream> // files
#include <string> // strings
#include <cstdlib> // exit()
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);

int main()
{
	string ary[R][C];
	
	int zombieCount = 0;
	
	ifstream fin;
	ofstream fout;
	
	fin.open("northpole.txt");
	
	if (fin.fail())
	{
		cout << "Error opening input file." << endl;
		exit(1);
	}
	
	fout.open("status.txt");
	
	if (fout.fail())
	{
		cout << "Error opening output file." << endl;
		exit(1);
	}
	
	fillArray(fin, ary);
	
	fout << "David Jia" << endl;
	
	for (int i = 1; i < R - 1; i++) //goes through each row
	{
		for (int j = 1; j < C - 1; j++) //goes through each column in the row
		{
			if (ary[i][j] == "@") //checks if an elf is located on the current position
			{
				if (ary[i - 1][j] == "!") //if zombie above, zombieCount increments by 1
				{
					zombieCount += 1;
				}
				
				if (ary[i][j - 1] == "!") //if zombie to left, zombieCount increments by 1
				{
					zombieCount += 1;
				}
				
				if (ary[i][j + 1] == "!") //if zombie to right, zombieCount increments by 1
				{
					zombieCount += 1;
				}
				
				if (ary[i + 1][j] == "!") //if zombie below, zombieCount increments by 1
				{
					zombieCount += 1;
				}
			}
			
			if (zombieCount == 3) //if zombieCount is 3
			{
				fout << "elf[" << i << "][" << j << "]: Run!" << endl;	
			}
			
			if (zombieCount == 4) //if zombieCount is 4
			{
				fout << "elf[" << i << "][" << j << "]: Munch!" << endl;
			}
			
			zombieCount = 0;
		}
	}
	
	fin.close();
	fout.close();
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			A_in >> S[i][j];
		}
	}
}//end fillArray




 
