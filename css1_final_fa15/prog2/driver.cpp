// Kori Gann
// 
// Elf Report
#include <iostream>
#include <fstream>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& a_in, string S[][C], int row, int column);
void printArray(string S[][C], int row, int column);

int main()
{
	ifstream a_in;
	a_in.open("northpole.txt");
	ofstream fout;
	fout.open("status.txt");
	
	fout << "Kori Gann" << endl;

	string S[R][C];

	fillArray(a_in, S, R, C);
	
	






	for(int i = 1; i < (R -1); i++)
		{
			for (int j = 1; j < (C -1); j++)
			{
				if(S[i][j] == "@")
				{


					if(S[(i+1)][j] == "!" && S[(i-1)][j] == "!" && S[i][(j+1)] == "!" && S[i][(j-1)] == "!")
					{
						fout << "elf[" << i << "][" << j<<"]: Munch!" << endl;
					}
			
					if(S[(i+1)][j] == "*" && S[(i-1)][j] == "!" && S[i][(j+1)] == "!" && S[i][(j-1)] == "!")
					{
						fout << "elf[" << i << "][" << j<<"]: Run!" << endl;
					}
					if(S[(i+1)][j] == "!" && S[(i-1)][j] == "*" && S[i][(j+1)] == "!" && S[i][(j-1)] == "!")
					{
						fout << "elf[" << i << "][" << j<<"]: Run!" << endl;
					}
					if(S[(i+1)][j] == "!" && S[(i-1)][j] == "!" && S[i][(j+1)] == "*" && S[i][(j-1)] == "!")
					{
						fout << "elf[" << i << "][" << j<<"]: Run!" << endl;
					}
					if(S[(i+1)][j] == "!" && S[(i-1)][j] == "!" && S[i][(j+1)] == "!" && S[i][(j-1)] == "*")
					{
						fout << "elf[" << i << "][" << j<<"]: Run!" << endl;
					}







				}
			}
		}
	
























	a_in.close();
	fout.close();
	
	return 0;
}

// ********************************
void fillArray(ifstream& a_in, string S[][C], int row, int column)
{
	string map;
	string holder;
	while (a_in >> map)
	{
		holder = holder + map;
	}
	int k = 0;
	for(int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				S[i][j] = holder[k];
				k = k + 1;
			}
		}
	
}//end fillArray

void printArray(string S[][C], int row, int column)
{

	for(int i = 0; i < row; i++)
	{
			for (int j = 0; j < column; j++)
			{
				cout << S[i][j] << " ";
			}
	}
}

 
