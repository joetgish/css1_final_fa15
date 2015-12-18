// Program comments here 
// 
// 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void checkSituation(ofstream& A_out, string S[][C]);

int main()
{
	ifstream fin;
	ofstream fout;
	string array[R][C];
	fin.open("northpole.txt");
	fout.open("status.txt");
	
	if(fin.fail() || fout.fail()){
		cout << "There's an error with a file you opened.\n";
		exit(1);
	}
	fout << "Nicole Hipolito\n\n";
	fillArray(fin, array);
	checkSituation(fout, array);
	fin.close();
	fout.close();
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			A_in >> S[i][j];
		}
	}
}//end fillArray

void checkSituation(ofstream& A_out, string S[][C])
{
	for(int i = 1; i < R-1; i++){
		for(int j = 1; j < C-1; j++){
			int count = 0;
			if(S[i][j] == "@")
			{
				if(S[i][j-1] == "!"){ //WEST
					count ++;
				}
				if(S[i][j+1] == "!"){ //EAST
					count ++;
				}
				if(S[i-1][j] == "!"){ //NORTH
					count ++;
				}
				if(S[i+1][j] == "!"){ //SOUTH
					count ++;
				}
				
				switch(count){
					case 3:
						A_out << "elf[" << i << "][" << j << "]: Run!\n";
						break;
					case 4:
						A_out << "elf[" << i << "][" << j << "]: Munch!\n";
						break;
				}
			}
			
		}
		
	}
}



 
