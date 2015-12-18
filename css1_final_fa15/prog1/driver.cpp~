// Name Mavey Ma
// Date Dec. 17, 2015 Thurs
// CSS-1 Fa15 Final Exam Prog 1
// IF THE POSSIBLE PASSWORD IS IN THE CRACKED PASSWORD FILE, DO NOT WANT TO USE IT. IN OTHER WORDS, IF THE POSSIBLE PASSWORD IS /NOT/ IN THE CRACKED PASSWORD FILE, OUTPUT THOSE GOOD PASSWORDS TO GOOD_WORDS.TXT. OKAY!
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);
void printVector(vector<string>& PW);
void comparePassword(string maybe[], int n, vector<string>& bad, ofstream& A_out);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("passwords.txt");
	fout.open("good_words.txt");
	//FAIL CHECK

	//POSSIBLE PASSWORDS ARRAY
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic", "aboral", "Santa",
				"password1","Password!", "ambystomidae"};
	//CRACKED PASSWORDS VECTOR
	vector<string> cracked;
	//FILL CRACKED VECTOR WITH CRACKED PASSWORD FILE.
	fillVector(cracked, fin);
	//printVector(cracked);

	fout << "Mavey Ma" << endl;
	comparePassword(possible, SIZE, cracked, fout);

	fin.close();
	fout.close();
	return 0;
}//END MAIN


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string temp;
	while (A_in >> temp)
	{
		PW.push_back(temp);
	}
	return;
}// end fill Vector(_)

void printVector(vector<string>& PW)
{
	for (int i=0; i<PW.size(); i++)
	{
		cout << PW[i] << endl;
	}
	return;
}//END PRINT VECTOR


void comparePassword(string maybe[], int n, vector<string>& bad, ofstream& A_out)
{
	for (int i=0; i<n; i++)
	{
		bool isGood = true;
		for (int j=0; j<bad.size(); j++)
		{
			if (maybe[i] == bad[j])
			{
				//A_out << "YIKES! " << maybe[i] << " " << bad[j] << endl;
				isGood = false;
			}
		}//END BAD CRACKED PASSWORDS
		if (isGood)
		{
			A_out << maybe[i] << endl;
		}
	}//END MAYBE POSSIBLE PASSWORDS
	return;
}//END COMPARE PASSWORD

 
