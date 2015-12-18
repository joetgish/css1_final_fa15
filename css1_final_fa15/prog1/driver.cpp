// Name
// Date
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);
void comparePW(vector<string>& PW, string ary[], int n, ofstream& A_out);

int main()
{
	ifstream fin;
	fin.open("passwords.txt");
	ofstream fout;
	fout.open("good_words.txt");
	
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!","ambystomidae"};
	vector<string> crackedPassWords;
	
	fillVector(crackedPassWords, fin);
	
	fout << "Emily Garcia" << endl; 
	comparePW(crackedPassWords, possible, SIZE, fout);
	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string crackedPW;

	while(A_in >> crackedPW )
	{
		PW.push_back(crackedPW);
	}
	return;
}// end fill Vector(_)
//*************************************
void comparePW(vector<string>& PW, string ary[], int n, ofstream& A_out)
{
	bool isNotSame = true;
	
	for(int i = 0; i < n; i++)//goes through every word in array
	{
		for(int j = 0; j < PW.size(); j++)//goes through every word in vector
		{
			if(ary[i] == PW[j])//if word at i matches word at j, then turns false
			{
				isNotSame = false;
			}

		}
		if(isNotSame == true)//if true after every word in j is compared to word i, then print to file
		{
			A_out << ary[i] << " ";
		}
		isNotSame = true;		
	}
	return;
}// end compare PW(_)
 
