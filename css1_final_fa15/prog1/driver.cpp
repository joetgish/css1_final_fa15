// Kristine Laranjo
// 16 December 2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream> //input output stream
#include <fstream> //files
#include <vector> //vector
#include <string> //string library
#include <cstdlib> //exit
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);
void checkPw(vector<string> PW, string ary[], ofstream& A_out);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("passwords.txt"); //opens file for input
	fout.open("good_words.txt"); //opens file for output
	if (fin.fail() || fout.fail()) //checks if files opened correctly
	{
		cout << "Error opening file.";
		exit(1);
	}
	const int SIZE = 6;
	vector<string> v;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};
	fillVector(v,fin);
	fout << "Kristine Laranjo" << endl << endl;
	checkPw(v,possible,fout);


	fin.close(); //closes input file
	fout.close(); //closes output file
	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string word;
	while (A_in >> word) //loops through file
	{
		PW.push_back(word); //pushes word into vector
	}
}// end fill Vector(_)

void checkPw(vector<string> PW, string ary[], ofstream& A_out)
{
	for(int i = 0; i < PW.size(); i++)
	{
		if (ary[0] == PW[i] || ary[1] == PW[i] || ary[2] == PW[i] ||
			ary[3] == PW[i] || ary[4] == PW[i] || ary[5] == PW[i] ||
			ary[6] == PW[i]) //checks if word is in the array
		{
			A_out << PW[i] << endl; //prints to output file
		}
		else
		{
			continue;
		}
	}
	return;
}