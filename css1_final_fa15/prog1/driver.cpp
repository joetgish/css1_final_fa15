// Name: Nicole Hipolito
// Date: December 17, 2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

const int SIZE = 6;

void fillVector(vector<string>& PW, ifstream& A_in);
void goodWords(vector<string> PW, ofstream& A_out, string ary[SIZE]);

int main()
{
	ifstream fin;
	ofstream fout;
	vector<string> v;
	
	fin.open("passwords.txt");
	fout.open("good_words.txt");
	
	if(fout.fail() || fin.fail()){
		cout << "There's an error with a file called.\n";
		exit(1);
	}
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};
  	fout << "Nicole Hipolito";
  	fillVector(v, fin);
  	goodWords(v, fout, possible);
  	
  	fin.close();
  	fout.close();
	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string pword;
	while(A_in >> pword){
		PW.push_back(pword);
	}	
}// end fill Vector(_)
//*************************************
void goodWords(vector<string> PW, ofstream& A_out, string ary[SIZE])
{
	for(int j = 0; j < SIZE; j++){
		for(int i = 0; i < PW.size(); i++){
			if(PW[i] == ary[j])
			{
				ary[j] = "";
			}
		}
	}
	for(int j = 0; j < SIZE; j++){
		A_out << ary[j] << endl;
	}
}


 
 
 
 
 
 
 
 
 
 
 
 
 
