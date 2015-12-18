// Name: Chanel Aquino
// Date: 17 December 2015
// CSS-1 Fa15 Final Exam Prog 1: Password Checker

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void fillArray(ifstream& fin, int size, string ary[]);
void checkMatch(int checkSize, string check[], int pwSize, string pw[], ofstream& A_out);

int main()
{
	// given information
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!","ambystomidae"};

	// create input and ouput file streams
	ifstream fin;
	ofstream fout;

	// open fies
	fin.open("passwords.txt");
	fout.open("good_words.txt");

	// check fail
	if(fin.fail() || fout.fail())
	{
		cout << "Error. Exiting now."<<endl;
		exit(1);
	}
	
	fout << "Name: Chanel Aquino" << endl << endl;
	

	//*** Get size of input file ***//
	int dataCount = 0;
	string password;
	
	while(fin >> password)
	{
		dataCount++;
	}


	//*** Create empty array with size PW_SIZE ***//
	const int PW_SIZE = dataCount;
	string passwordsArray[PW_SIZE];

	//*** Fill passwordsArray with input from fin ***//
	fillArray (fin, PW_SIZE, passwordsArray);

	//*** Check is possible[] is contained in passwordsArray ***//
	checkMatch(SIZE, possible, PW_SIZE, passwordsArray, fout);
	
	// close files
	fin.close();
	fout.close();
	
	return 0;
} // end main()


//*************************************
void fillArray(ifstream& A_in, int size, string ary[])
{	
	// reset pointer of A_in
	A_in.clear();
	A_in.seekg(0);
	
	int i = 0;
	string password;
	ary[size];
	
	// read input from A_in and store values in password
	while(A_in >> password)
	{	
		// assign password values to ary at index i
		ary[i] = password;
		i++;	
	}

	return;
} // end fillArray()

//*************************************
void checkMatch(int checkSize, string check[], int pwSize, string pw[], ofstream& A_out)
{
	int matchCount;

	// execute loop checkSize amount of times
	for(int i = 0; i < checkSize; i++)
	{
		// reset matchCount to 0
		matchCount = 0;
		
		// execute loop pwSize amount of times
		for(int j = 0; j < pwSize; j++)
		{
			// if check[i] matches pw[j], increment matchCount
			if(check[i] == pw[j])
			{
				matchCount++;
				
			}
		}
		
		// if no matches were found, print check[i] to output file
		if(matchCount == 0)
		{
			A_out << check[i] <<endl;
		}
	}

	return;
} // end checkMatch()