// Name Dario Molina	
// Date 12/17/15
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<string>
#include<cctype>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);
void removeSpecialChar( vector<string>& PW);
void checkIfSame( string array[], int n, vector<string> PW, ofstream& A_out);


int main()
{
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};

	vector<string> password;
	ifstream fin;
	ofstream fout;

	fin.open("passwords.txt");
	fout.open("good_words.txt");

	if( fin.fail() )
		{
			cout << "Password file could not be opened\n";
			exit(1);
		}

	else if ( fout.fail() )
		{
			cout << "Output file could not be opened\n";
			exit(1);
		}

	fillVector( password, fin);
	removeSpecialChar( password); 


  checkIfSame( possible, SIZE, password, fout);
  

	return 0;
}


//****************************************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
  string word = "";

  while( A_in >> word)
		{
			PW.push_back(word);

		}
	
}// end fill Vector(_)

//********************************************************************

void removeSpecialChar( vector<string>& PW)
{
		string str = "";
		string word = "";

	for( int i = 0; i < PW.size(); i++)
		{
			word = PW[i];

			for( int j = 0; j < word.length(); j++)
				{

					if( isalpha( word[j]))
						{
							str += word[j];
						}

				}
			PW[i] = str;
			str = "";
			word = "";

		}


}
//********************************************************************

void checkIfSame( string array[], int n, vector<string> PW, ofstream& A_out)
{

     string str = "";
		string word = "";

	for( int i = 0; i < n; i++)
		{
			word = array[i];

			for( int j = 0; j < PW.size(); j++)
				{
					str = PW[j];


					if( word == str )
					 {
							A_out << word << endl;

						}
				}
			
			str = "";
			word = "";

		}

}









 
