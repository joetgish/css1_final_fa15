// Name: Daniel Calderon
// Date: 12-17-2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void fillArray(ifstream& fin,const int SIZE, string array[]);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("passwords.txt");
	fout.open("good_words.txt");
	if(fin.fail())
	{
		cout << "Error on input file"<<endl;
		exit(1);
	}
	if(fout.fail())
	{
		cout << "Eroor on output file"<<endl;
		exit(1);
	}
	fout << "Daniel Calderon" <<endl;
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!","ambystomidae"};
	
	int count =0;
	string word;
	while(fin >> word)//get size of array
	{
		count +=1;
		
	}

	const int SIZE1 = count;
	string array[SIZE1];

	fillArray (fin,SIZE1,array);
	int count2 = 0;
	for(int i=0; i < SIZE; i++)
	{
		count2=0;
		for(int j=0; j <SIZE1; j++)
		{
			if(possible[i] == array[j])/*if it finds same word*/
			{
				count2 +=1;
				
			}
		}
		if(count2 == 0)//if no equla word was found then write to file
		{
			
			fout << possible[i] <<endl;
			
		}
	}
	fin.close();
	fout.close();
	return 0;
}


//*************************************
void fillArray(ifstream& fin,const int SIZE,string array[])
{	
	fin.clear();//Resets pointer
	fin.seekg(0);
	string eatWord;
	int i =0;
	array[SIZE];
	while(fin >> eatWord)
	{	
		array[i] = eatWord;
		i++;	
	}
}

