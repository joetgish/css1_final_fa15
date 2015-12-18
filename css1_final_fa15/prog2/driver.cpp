// Name: Nancy Gomez 
// Date: Dec 17, 2015
// Final Program 2
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& fin, ofstream& fout, string S[][C]);

int main(){
	ifstream A_in;
	ofstream A_out;
	A_in.open("northpole.txt");
	A_out.open("status.txt");
	
	//Checking to make sure the files open correctly
	if (A_in.fail() || A_out.fail()){
		cout << "Error opening files." << endl;
		exit(1);
	}
	
	// Creating the Two Dimensional Array and filling it
	string northpoleMap[R][C];
	fillArray(A_in, A_out, northpoleMap);
	
	return 0;
}

// **************************************************************************
//	Precondition: Takes in the both if and ofstream to input and output data
//  also takes in the empty array that was created in main
//	Postcondition: Fills in the empty array with the data provided from north-
//  pole.txt. Then the following for loop checks all of the non-outer rows and
//	columns for an elf. If it finds an elf it checks N, S, E, and W of that
// 	location for zombies. When a zombie is found, the zombieCount increments.
//	Depending on the number of zombies, "Run" or "Munch" is output to the file
// ***************************************************************************
void fillArray(ifstream& fin, ofstream& fout, string S[][C]){
	// filling the array with the data from the northpole file
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			fin >> S[i][j];
		}
	}
	
	// Now checking to see the elves' status
	// (Starting and ending early because we don't care about the outter rows/columns)
	for (int i = 1; i < R-1; i++){
		for (int j = 1; j < C-1; j++){
			int zombieCount = 0;
			// these ifs keep track of how many zombies are around the elf
			if (S[i][j] == "@"){
				if (S[i-1][j] == "!"){
					zombieCount++;
				}
				if (S[i+1][j] == "!"){
					zombieCount++;
				}
				if (S[i][j-1] == "!"){
					zombieCount++;
				}
				if (S[i][j+1] == "!"){
					zombieCount++;
				}
			}
			
			// This prints the elf's status depending on the number of zombies
			if (zombieCount == 4){
				fout << "elf[" << i << "] [" << j << "]: Munch!" << endl;
			}
			else if (zombieCount == 3){
				fout << "elf[" << i << "] [" << j << "]: Run!" << endl;
			}
			
			// Resetting the zombie count in order to check the next elf
			zombieCount = 0;
		}
	}
}




 
