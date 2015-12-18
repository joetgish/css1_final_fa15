// Name Noe Lomeli	
// Date December 17 2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool isGoodPassWord(ofstream& A_out, vector<string>& PW, string arryA[], int n);
void fillVector(vector<string>& PW, ifstream& A_in);
// Precondition: Ifstream file and  string vector are to be input into the function
//Postcondition: Vector will be populated with strings
//********************************************************************************

int main()
{
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};

	vector<string> M;
	ifstream fin;
	ofstream fout;
	fout.open("good_words.txt");
	fin.open("passwords.txt");
	if(fin.fail())
	{
		cout << "Error opening file" << endl;
	}
	if(fout.fail())
	{
		cout << "Error opening file" << endl;
	}

	fillVector(M, fin);
	fout << "Noe Lomeli" << endl;
	isGoodPassWord(fout, M, possible, SIZE);


	fin.close();
	fout.close();
	return 0;
} // end main


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string word;
	while(A_in >> word)
	{
		PW.push_back(word);
		
	}
}// end fill Vector(_)
//************************************************
bool isGoodPassWord(ofstream& A_out, vector<string>& PW, string arryA[], int n)
{
	bool isNotHere = true;
	
	
	for(int i(0); i < n; i++)
	{
		for(int j(0); j < PW.size(); j++)
		{		
			if(arryA[i] == PW[j])
			{
				isNotHere = true;
				break;
				

			}
			else
			{
				isNotHere = false;
				
			}
			
		}
		if(isNotHere != true)
		{
			A_out << arryA[i] << endl;
		}
		
	}

}




 