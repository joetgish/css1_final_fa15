// Name: Nancy Gomez
// Date: Dec 17, 2015
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

void varifyPassword(ofstream& fout, ifstream& fin, string password[], int size); 

int main(){
	ifstream A_in;
	ofstream A_out;
	A_in.open("passwords.txt");
	A_out.open("good_words.txt");
	
	//Checking to make sure the files open correctly
	if (A_in.fail() || A_out.fail()){
		cout << "Error opening files." << endl;
		exit(1);
	}
	
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic", "aboral", "Santa", "password1", "Password!", "ambystomidae"};
	
	varifyPassword(A_out, A_in, possible, SIZE);
	
	return 0;
}

void varifyPassword(ofstream& fout, ifstream& fin, string password[], int size){
	fout << "Nancy Gomez" << endl << endl;

	// Creating a vector to store all of the passwords
	string element;
	vector<string> filePasswords;
	while (fin >> element){
		filePasswords.push_back(element);
	}
	
	// Checking whether each array element is in the file
	for (int i = 0; i < size; i++){
		for (int j = 0; j < filePasswords.size(); j++){
			if (filePasswords[j] == password[i]){
				fout << password[i] << endl;
			}
		}
	}
}
