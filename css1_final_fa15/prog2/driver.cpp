// Program comments here 
// Name Noe Lomeli
// Date December 17, 2015
#include <iostream>
#include <fstream>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void findElves(ofstream& A_out, string S[][C]);

int main()
{

	string elves[R][C];
	ifstream fin;
	ofstream fout;
	fout.open("status.txt");
	fin.open("northpole.txt");
	if(fin.fail() || fout.fail())
	{
		cout << "Error opening file" << endl;
	}

	fout << "Noe Lomeli" << endl;
	fillArray(fin, elves);
	findElves(fout, elves);

	fin.close();
	fout.close();
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	for(int i(0); i < R; i++)
	{
		for(int j(0); j < C; j++)
		{
			A_in >> S[i][j];
			
		}
		
	}
}//end fillArray
void findElves(ofstream& A_out, string S[][C])
{
	int count = 0;
	for(int i(1); i < R-1; i++)
	{
		for(int j(1); j < C-1; j++)
		{
			if(S[i][j] == "@")
			{
				if(S[i-1][j] == "!")
					count++;
				if(S[i+1][j] == "!")
					count++;
				if(S[i][j-1] == "!")
					count++;
				if(S[i][j+1] == "!")
					count++;
				if(count == 3)
				{
				 	A_out << "elf[" << i << "][" << j <<"]: Run!" << endl;	
					count = 0;
				}
				if(count >= 4)
				{
				 	A_out << "elf[" << i << "][" << j <<"]: Munch!" << endl;	
					count = 0;
				}
			}
			
		}

	}
}




 