// Name Coleman Johnston
// Date 17 December 2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);

bool isPresent(string str, vector<string> v);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("passwords.txt");
	fout.open("good_words.txt");
	if(fin.fail() || fout.fail())//fail stuff
	{
		cout << "File Error.\n";
		exit(1);
	}
	
	vector<string> vect;
	
	fillVector(vect,fin);
	
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};
	fout << "Coleman Johnston\n";
	for(int i = 0; i < SIZE; i++)
	{
		if(!isPresent(possible[i],vect))
		{
			fout << possible[i] << endl;
		}
	}
	
	fin.close();
	fout.close();
	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string str;	
	while(A_in >> str)
	{
		PW.push_back(str);	
	}
	return;
			
}// end fill Vector(_)

//******************************************

bool isPresent(string str, vector<string> v)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == str)
		{
			return true;
		}
	}
	return false;
}
