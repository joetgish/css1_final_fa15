// Name Jesus Perez
// Date 12/17/2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);// fills in a vector by pass by reference, using a ifstream object from the function call.
void compare(string ara[], const int size, vector<string> PW, ofstream& A_out);

int main()
{
	ifstream fin;
	ofstream fout;
	vector<string> passwords;

	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};
	fillVector(passwords, fin);
	compare(possible, SIZE, passwords, fout);
	
	

	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	A_in.open("passwords.txt");
	string read;
	while(A_in >> read)
	{
		PW.push_back(read);
	}
	for(int i =0; i<PW.size(); i++)
	{
		//cout <<PW[i] << endl;
	}
	
	return;
}// end fill Vector(_)
//*************************************
void compare(string ara[], const int size, vector<string> PW, ofstream& A_out)
{
	string goodword, badword;
	int index;
	string word;
	
	A_out.open("good_words.txt");
	A_out << "Jesus Perez" << endl;
	for(int i = 0; i<size; i++)

	{
		for(int j =0; j<PW.size();j++)
		{
			if( PW[j]==ara[i])
			{
				A_out <<"Words that are bad" << ara[i] << endl;
				
				
				
				
				 
			}
			
			
			
			
		
			
			
		}
		//cout << word << endl;
		
		
		
		
			
	
	}
	


			
	
	return;
}


 
