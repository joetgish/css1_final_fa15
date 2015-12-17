// Steven Groves
// 17 Dec 2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);
bool isCracked(vector<string> PW, string str, int n);

int main()
{
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};
	ifstream fin;
	ofstream fout;
	fin.open("passwords.txt");
	fout.open("good_words.txt");

	vector<string> cracked;
	fillVector(cracked, fin);

	fout << "Steven Groves" << endl;
	for (int i = 0; i < SIZE; ++i)
	{
		if(isCracked(cracked, possible[i], SIZE))
		{
			continue;
		}
		fout << possible[i] << endl;
	}

	fin.close();
	fout.close();
	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string temp;
	while(A_in >> temp)
	{
		PW.push_back(temp);
	}

	return;
}// end fill Vector(_)


 //*************************************
bool isCracked(vector<string> PW, string str, int n)
{
	for(int i = 0; i < PW.size(); i++)
	{
		if(str == PW[i])
			return true;
	}

	return false;
}// end is Cracked(_)