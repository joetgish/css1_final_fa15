// Name: Samuel Sanchez
// Date: 17 December 2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);
void checkPass(vector<string>& PW, ofstream& A_out, string ary[], int arySize);

int main()
{
	const int SIZE = 6;
	ifstream fin; // For passwords
	ofstream fout; // To output secure words from possible
	vector<string> passwords; // Will hold possible passwords
	fin.open("passwords.txt");
	fout.open("good_words.txt");
	if(fin.fail() || fout.fail()) // fail stuff
	{
		cout << "Error opening file\n";
		exit(1);
	}
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};

	fout << "Samuel Sanchez\n"; // Output header
	fout << "16 December 2015\n";
	fout << "CSS-1 Fa15 Final Exam Prog 1\n";	

	fillVector(passwords, fin); // Function calls
	checkPass(passwords, fout, possible, SIZE);
	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string input; // Will contain a cracked password
	while(A_in >> input)
	{
		PW.push_back(input);
	}
	return;
}// end fill Vector(_)
//*************************************
void checkPass(vector<string>& PW, ofstream& A_out, string ary[], int arySize)
{
	for(int xi = 0; xi < arySize; xi++) // Checks each possible word
	{
		int matches = 0; // Counts number of times word appears in passwords.txt
		for(int xj = 0; xj < PW.size(); xj++) // Checks each cracked word
		{
			if(ary[xi] == PW[xj]) // Determines match count
			{
				matches++;
			}
		}
		if(matches == 0) // Outputs word to file good_words.txt if 0 matches were found in passwords.txt
		{
			A_out << ary[xi] << endl;
		}
	}
	return;
 }
//*************************************