// Name Mavey Ma
// Date Dec. 17, 2015 Thurs
// CSS-1 Fa15 Final Exam Prog 2
// 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void north(int& a, int& b);
void south(int& a, int& b);
void east(int& a, int& b);
void west(int& a, int& b);
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

void north(int& a, int& b)
{
	a -= 1;
	return;
}//END NORTH

void south(int& a, int& b)
{
	a += 1;
	return;
}//END SOUTH

void east(int& a, int& b)
{
	b += 1;
	return;
}//END EAST

void west(int& a, int& b)
{
	b -= 1;
	return;
}//END WEST

int countZombie(string S[][C], int a, int b)
{
	int num = 0;
	north(a,b);
	if (S[a][b] == "!")
	{
		num++;
	}
	south(a,b);
	if (S[a][b] == "!")
	{
		num++;
	}
	east(a,b);
	if (S[a][b] == "!")
	{
		num++;
	}
	west(a,b);
	if (S[a][b] == "!")
	{
		num++;
	}
	return num;
}//END COUNT ZOMBIE

void status(string S[][C], ofstream& A_out)
{
	for (int i=0; i<R; i++)
	{
		for (int j=0; j<C; j++)
		{
			if (S[i][j] == "@")
			{
				//HOW MANY ZOMBIES ADJACENT?
				int ans = countZombie(S,i,j);
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
 
