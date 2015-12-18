// Name: Carlos Huizar Valenzuela
// Date: 17 Dec 2015
// Program 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void status(ofstream& f_out, string a[][C]);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("northpole.txt");
	fout.open("status.txt");

	string arr[R][C]; 
	fillArray(fin, arr);
	status(fout, arr);



	fin.close();
	fout.close();
	
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	
	for(int i = 0; i < R ; i++)
	{
		for(int j = 0; j < C ; j++)
		{
			A_in >> S[i][j];

			
		}
		
	}
	return;
	
}//end fillArray
void status(ofstream& f_out, string a[][C])
{
	f_out << "Carlos Huizar Valenzuela" << endl;
	for(int i = 1; i < R - 1; i++)
	{
		for(int j = 1; j < C - 1; j++)
		{
			
			if(a[i][j] == "@")
			{
				if(a[i-1][j] == "!" && a[i][j+1] == "!" && a[i+1][j] == "!" && a[i][j-1] == "!")
				{
					f_out << "Elf (" << i << ")(" << j << "): Munch!" << endl;
					
				}
				else if((a[i-1][j] == "!" && a[i][j+1] == "!" && a[i+1][j] == "!") ||
						(a[i-1][j] == "!" && a[i][j+1] == "!" && a[i][j-1] == "!") || 
						(a[i-1][j] == "!" && a[i+1][j] == "!" && a[i][j-1] == "!") ||
						(a[i][j+1] == "!" && a[i+1][j] == "!" && a[i][j-1] == "!"))
				{
					f_out << "Elf (" << i << ")(" << j << "): Run!" << endl;
				}

			}
		
		}
	}
	return;

}



 
