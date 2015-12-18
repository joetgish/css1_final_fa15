// Name: Carlos Huizar Valenzuela 
// Date: 17 Dec 2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);
void compare(vector<string>& v, ofstream& f_out, string a[], int n);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("passwords.txt");
	fout.open("good_words.txt");
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};
	vector<string> vec;

	fillVector(vec,fin);
	compare(vec, fout, possible, SIZE);
	

	fin.close();
	fout.close();
	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string data;

	while(A_in >> data)
	{
		PW.push_back(data);	
		
	}
	return;
}// end fill Vector(_)

void compare(vector<string>& v, ofstream& f_out, string a[], int n)
{
	
	for(int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(a[j] == v[i])
			{
				a[j] = "";
				
			}
		}
	}
	
	f_out << "Carlos Huizar Valenzuela";

	for (int j = 0; j < n; j++)
	{
		f_out << left << a[j] << endl;
	}
	return;
}

 
