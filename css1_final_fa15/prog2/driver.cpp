// Sandra Flores
// Dec. 17, 2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void printArray(string S[][C]);
void status(string S[][C], ofstream& A_out);

int main()
{
	ifstream fin;
    ofstream fout;
    fin.open("northpole.txt");
    fout.open("status.txt");
    
    if(fin.fail() || fout.fail())
    {
        cout << "Files failed to open." << endl;
        exit(1);
    }
    
    string Arry[R][C] = { };
    
    fillArray(fin, Arry);
    //printArray(Arry);
    
    status(Arry, fout);
    
	return 0;
}

// ********************************************
void fillArray(ifstream& A_in, string S[][C])
{
    
	for(int i = 0; i < R; i++)
	{
	    for(int j = 0; j < C; j++)
	    {
	        A_in >> S[i][j];
	    }
	    
	}
}//end fillArray
//********************************************
void printArray(string S[][C])
{
    for(int i = 0; i < R; i++)
	{
	    for(int j = 0; j < C; j++)
	    {
	        cout << S[i][j] << " ";
	    }
	    cout << endl;
	}
	return;
}

//*********************************************
void status(string S[][C], ofstream& A_out)
{
    A_out << "Sandra Flores" << endl;   
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(S[i][j] == "@")
            {
                if((S[i][j-1] == "!") && (S[i+1][j] == "!") && (S[i][j+1] == "!") && (S[i-1][j] == "!"))
                {
                    A_out << "Elf [" << i << "][" << j << "]:" << "Munch!";
                }
                else if((S[i][j-1] != "!") && (S[i+1][j] == "!") && (S[i][j+1] == "!") && (S[i-1][j] == "!"))
                {
                    A_out << "Elf [" << i << "][" << j << "]:" << "RUN!";
                }
                else if((S[i][j-1] == "!") && (S[i+1][j] != "!") && (S[i][j+1] == "!") && (S[i-1][j] == "!"))
                {
                    A_out << "Elf [" << i << "][" << j << "]:" << "RUN!";
                }
                else if((S[i][j-1] == "!") && (S[i+1][j] == "!") && (S[i][j+1] != "!") && (S[i-1][j] == "!"))
                {
                    A_out << "Elf [" << i << "][" << j << "]:" << "RUN!";
                }
                else if((S[i][j-1] == "!") && (S[i+1][j] == "!") && (S[i][j+1] == "!") && (S[i-1][j] != "!"))
                {
                    A_out << "Elf [" << i << "][" << j << "]:" << "RUN!";
                }
                else
                {
                    continue;
                }
            }
        }
    }
    
    return;
}






