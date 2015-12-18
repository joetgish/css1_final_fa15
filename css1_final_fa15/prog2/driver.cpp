// Program comments here 
// Name: Coleman Johnston 
// Date: 17 Dec. 2015
// Final Exam program 2
#include <iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string s[][C]);

int grinchCounter(int row, int col, string s[][C]);//pass the position of the elf

bool isElf(int row , int col, string s[][C]);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("northpole.txt");
	fout.open("status.txt");
	string workShop[R][C];
	int grinch;//number of grinches
	if(fin.fail() || fout.fail())
	{
		cout << "File Error\n";
		exit(1);
	}	
	
	fillArray(fin,workShop);
	
	fout << "Coleman Johnston\n";
	
	for(int i = 1; i < R -1; i++)//don't check top or bottom row
	{
		for(int j = 1; j < C -1; j++)//don't check far left of right col
		{
			if(isElf(i,j,workShop))//if there is an elf at that position
			{
				grinch = grinchCounter(i,j,workShop);//find the number of grinches 
				switch(grinch)//output according to the number of grinches
				{
					case 3:
						fout << "elf [" << i << "][" << j << "]: Run!\n";
						break;
					case 4:
						fout << "elf [" << i << "][" << j << "]: Munch!\n";
				}
			}
		}
	}	
	
	fin.close();
	fout.close();
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string s[][C])
{	
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			A_in >> s[i][j]; 
		}
	}
	return;
}//end fillArray

//***********************************************
int grinchCounter(int row, int col, string s[][C])
{
	int gCount = 0;//grinch Count
	
	if(s[row + 1][col] == "!")//check South
	{
		gCount++;
	}
	if(s[row][col + 1] == "!")//check East
	{
		gCount++;
	}
	if(s[row - 1][col] == "!")//check North
	{
		gCount++;
	}
	if(s[row][col - 1] == "!")// check West
	{
		gCount++;
	}	
	return gCount;	
}

//**********************************************************
bool isElf(int row , int col ,string s[][C])
{
	return(s[row][col] == "@");
}
 
