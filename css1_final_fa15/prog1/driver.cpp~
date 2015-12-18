// David Jia
// 12-17-15
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream> // input output
#include <fstream> // files
#include <string> // strings
#include <cstdlib> // exit(1)
#include <vector> // vectors
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);

int main()
{
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};
	vector<string> passwords; //vector to hold all cracked passwords
	string bad; //string that holds a possible password that has been cracked
	ifstream fin;
	ofstream fout;
	fin.open("passwords.txt");
	
	if (fin.fail())
	{
		cout << "Error opening input file." << endl;
		exit(1);
	}
	
	fout.open("good_words.txt");
	
	if (fout.fail())
	{
		cout << "Error opening output file." << endl;
		exit(1);
	}

	fillVector(passwords, fin);
	
	fout << "David Jia" << endl; //puts name on top of output file
	
	for (int i = 0; i < SIZE; i++) //runs through array for possible passwords
	{
		for (int j = 0; j < passwords.size(); j++) //runs through vector for cracked passwords
		{
			if (possible[i] == passwords[j]) //if possible password is cracked, string bad is 
			{								 //initialized to the cracked possible password
				bad = possible[i];
			}	
		}
		
		if (bad != possible[i]) //if the possible password is not cracked, it won't ever be equal to 
		{						//string bad so it will send that string to the good_words.txt
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
	string pass;
	while (A_in >> pass)
	{
		PW.push_back(pass);
	}
}// end fill Vector(_)


 
