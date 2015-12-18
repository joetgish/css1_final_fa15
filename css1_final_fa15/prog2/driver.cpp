// Program comments here 
// Jesus Perez
// 12/17/2015
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void status(ofstream& A_out, string S[][C]);


int main()
{
	ifstream fin;
	ofstream fout;
	
	string ara[R][C];
	fillArray(fin, ara);
	status(fout, ara);
	
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	A_in.open("northpole.txt");
	string str;
	for(int i =0; i< R; i++)
	{
		for(int j =0; j< C; j++)
		{
			A_in >> S[i][j];
			
		}
	}
	for(int i =0; i< R; i++)
	{
		for(int j =0; j< C; j++)
		{
			cout << S[i][j];
			
		}
		cout << endl;
	}
	return;
	
	
}//end fillArray
void status(ofstream& A_out, string S[][C])
{
	A_out.open("status.txt");
	A_out << "Jesus Perez"<< endl;
	for(int i =0; i<R-1; i++)
	{
		for(int j =0; j<C-1; j++)
		{
			if(S[i][j] =="@")
			{
				if((S[i-1][j] =="!") && (S[i][j+1] =="!")&& (S[i+1][j] =="!")&& (S[i][j-1]=="!"))
				{
					A_out <<i << j<< "MUNCH" << endl;
				}
				else if(((S[i-1][j] == "!") && (S[i][j+1] == "!")&& (S[i+1][j] == "!")) ||
				((S[i-1][j] == "!") && (S[i][j+1] == "!") && (S[i][j-1] == "!")) ||
				((S[i-1][j] == "!") && (S[i+1][j] == "!") && (S[i][j-1] == "!")) ||((S[i][j+1] == "!") && (S[i+1][j] == "!") && (S[i][j-1] == "!")))
				{
					A_out <<"ELF" << i<<j<< "RUN" << endl;
				}
				 
				
			}
		}
	}
	return;
	

}




 
