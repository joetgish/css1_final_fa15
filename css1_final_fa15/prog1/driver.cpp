// Kori Gann
// Date
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);
void printVector(vector<string>& PW);
int main()
{
	const int SIZE = 6;
	ifstream A_in;
	ofstream fout;
	vector<string> PW;

	A_in.open("passwords.txt");
	fout.open("good_words.txt");
	fout << "Kori Gann" << endl;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};
	fillVector(PW, A_in);
	
	string word2;
	
	while(A_in >> word2)
	{
		if (possible[0] == word2)
		{
			possible[0] = " ";
		}
		if ( possible[1] == word2)
		{
			possible[1] = " ";
		}
		if (possible[2] == word2)
		{
			possible[2] = " ";
		}
		if (possible[3] == word2)
		{
			possible[3] = " ";
		}
		if (possible[4] == word2)
		{
			possible[4] = " ";
		}
		if (possible[5] == word2)
		{
			possible[5] = " ";
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		fout << possible[i] << " ";
	}
		
	
	A_in.close();
	fout.close();
	return 0;
	
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string word;
	while(A_in >> word)
	{
		PW.push_back(word);
		PW.push_back(" ");
	}
	
}// end fill Vector(_)


void printVector(vector<string>& PW)
{
	for(int i = 0; i < PW.size(); i++)
	{
		cout << PW[i];
	}
}

	
