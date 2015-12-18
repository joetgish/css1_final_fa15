// Name Mavey Ma
// Date Dec. 17, 2015 Thurs
// CSS-1 Fa15 Final Exam Prog 2
// CHRISTMAS ELVES.
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
int north(int a, int b, int count, string S[][C]);
int south(int a, int b, int count, string S[][C]);
int east(int a, int b, int count, string S[][C]);
int west(int a, int b, int count, string S[][C]);
void status(string S[][C], ofstream& A_out);
int countZombie(string S[][C], int a, int b);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("northpole.txt");
	fout.open("status.txt");
	//fail check
	//fout << "Mavey Ma" << endl;

	string winter[R][C];

	fillArray(fin, winter);
	status(winter, fout);
	
	fin.close();
	fout.close();
	return 0;
}//END MAIN

// ********************************

void fillArray(ifstream& A_in, string S[][C])
{
	for (int i=0; i<R; i++)
	{
		for (int j=0; j<C; j++)
		{
			A_in >> S[i][j];
		}//END COL
	}//END ROW 
}//end fillArray

/*
int north(int a, int b, int count, string S[][C])
{
	a -= 1;
	if (S[a][b] == "!")
	{
		count++;
	}
	return count;
}//END NORTH

int south(int a, int b, int count, string S[][C])
{
	a += 1;
	if (S[a][b] == "!")
	{
		count++;
	}
	return count;
}//END SOUTH

int east(int a, int b, int count, string S[][C])
{
	b += 1;
	if (S[a][b] == "!")
	{
		count++;
	}
	return count;
}//END EAST

int west(int a, int b, int count, string S[][C])
{
	b -= 1;
	if (S[a][b] == "!")
	{
		count++;
	}
	return count;
}//END WEST

int countZombie(string S[][C], int valA, int valB)
{
	int num = 0;
	num += north(valA, valB, num, S);
	num += south(valA, valB, num, S);
	num += east(valA, valB, num, S);
	num += west(valA, valB, num, S);
	return num;
}//END COUNT ZOMBIE
*/
void status(string S[][C], ofstream& A_out)
{
	for (int i=1; i<R-1; i++)
	{
		for (int j=1; j<C-1; j++)
		{
			//WHENEVER THERE'S AN ELF...
			if (S[i][j] == "@")
			{
				//HOW MANY ZOMBIES ADJACENT?
				//int ans = countZombie(S,i,j);
				int ans = 0;
				//NORTH
				if (S[i-1][j] == "!")
				{
					ans++;
				}
				//SOUTH
				if (S[i+1][j] == "!")
				{
					ans++;
				}
				//EAST
				if (S[i][j+1] == "!")
				{
					ans++;
				}
				//WEST
				if (S[i][j-1] == "!")
				{
					ans++;
				}
				if (ans == 4)
				{
					S[i][j] = "E";
					A_out << "elf [" << i << "][" << j << "]: Munch!" << endl;
				}
				else if (ans == 3)
				{
					S[i][j] = "R";
					A_out << "elf [" << i << "][" << j << "]: Run!" << endl;
				}
			}//END ELF
		}//END COL
	}//END ROW
	return;
}//END RUN
 
