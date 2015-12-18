// Name: Regie Daquioag
// Date: December 17, 2015
// Final Program 2

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void report(string S[][C]);
void status(ofstream& A_out, string S[][C]);

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

	string elfs[R][C];

	fillArray(fin, elfs);

	report(elfs);

	status(fout, elfs);


	fin.close();
	fout.close();
	return 0;
}

// ********************************

void fillArray(ifstream& A_in, string S[][C])
{
	for(int i = 0; i < R; i++)
	{
		for(int ix = 0; ix < C; ix++)
		{
			A_in >> S[i][ix];
			//cout << S[i][ix];
		}
	}
}
// ********************************

void report(string S[][C])
{
	for(int i = 1; i < R-1; i++)
	{
		for(int ix = 1; ix < C-1; ix++)
		{
			int count = 0;
			if((S[i][ix] == "@") && (i != R-1) && (ix != C-1) )
			{
				if(S[i-1][ix] == "!")
				{
					count++;
				}
				if(S[i+1][ix] == "!")
				{
					count++;
				}
				if(S[i][ix-1] == "!")
				{
					count++;
				}
				if(S[i][ix-1] == "!")
				{
					count++;
				}
				
				if(count == 3)
				{
					S[i][ix] = "Run!";
				}
				if(count == 4)
				{
					S[i][ix] = "MUNCH";
				}

			}
		}
	}
}
// ********************************

void status(ofstream& A_out, string S[][C])
{
	for(int i = 0; i < R; i++)
	{
		for(int ix = 0; ix < C; ix++)
		{
			A_out << S[i][ix];
		}
	}

}











 
