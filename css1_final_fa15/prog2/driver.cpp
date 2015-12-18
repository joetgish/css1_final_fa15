// Sarah Villegas   
// Dec. 17, 2015
// Santa Needs Help 
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);

void makeMove(string S[][C], int& posX, int& posY, char& choice, ofstream& B_out); 

void updateFile(ofstream& B_out,int& posX, int& posY, char& choice); 

int main()
{
    ifstream fin; 
    ofstream fout;
    string placement[R][C] = {""};
    int spotX,spotY;
    char eatOrNot;   
    
    fin.open("northpole.txt");
    fout.open("status.txt");
    
    if(fin.fail() && fout.fail()){
    
        cout << "File failed to open" << endl; 
        exit(1);
    }    
    fillArray(fin,placement);
    makeMove(placement, spotX, spotY, eatOrNot, fout);    
      
    
    fin.close();
    fout.close();
	
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
    string move; 
    while(A_in >> move){
    
        for(int i = 0; i < R; i++){
        
            for(int j = 0; j < C; j++){
            
                S[i][j] = move; 
            } 
        }
    }
	
}//end fillArray

//****************************************************
void makeMove(string S[][C], int& posX, int& posY , char& choice, ofstream& B_out){
    
     B_out << "Sarah Villegas" << endl; 
    
    for(int i = 1; i < R-1; i++){
        
        for(int j = 1; j < C-1; j++){
            // 4 same up ---------------------------down----------------------left-------------------right 
            if( (S[i-1][j] == "!") && (S[i+1][j] == "!") && (S[i][j-1] == "!") && (S[i][j+1] == "!")){
            
                posX = i;
                posY = j; 
                choice ='E';
                B_out << "elf[" << posX << "]" << posY << "]: Munch!" << endl;  
            }
            // 3 same up ---------------------------down----------------------left 
            else if( (S[i-1][j] == "!") && (S[i+1][j] == "!") && (S[i][j-1] == "!") ){
                posX = i;
                posY = j;
                choice = 'R';
                B_out << "elf[" << posX << "]" << posY << "]: Run!" <<endl;
            }
            // 3 same up ---------------------------down-------------------right 
            else if( (S[i-1][j] == "!") && (S[i+1][j] == "!")  && (S[i][j+1] == "!")){
                posX = i;
                posY = j;
                choice = 'R';
                B_out << "elf[" << posX << "]" << posY << "]: Run!" <<endl;
            
            }
             // 3 same up ---------------------left-------------------right 
            else if( (S[i-1][j] == "!")  && (S[i][j-1] == "!") && (S[i][j+1] == "!")){
                posX = i;
                posY = j;
                choice = 'R';
                B_out << "elf[" << posX << "]" << posY << "]: Run!" <<endl;
            
            }
             // 3 same down----------------------left-------------------right 
            else if( (S[i+1][j] == "!") && (S[i][j-1] == "!") && (S[i][j+1] == "!")){
                posX = i;
                posY = j;
                choice = 'R';
                B_out << "elf[" << posX << "]" << posY << "]: Run!" <<endl;
            
            }
        }
    } 

    
    B_out.close();
    return;
}





//************************************************
void updateFile(ofstream& B_out,int& posX, int& posY, char& choice ){

    B_out << "Sarah Villegas" << endl; 
    
    switch(choice){
    
        case'E':
            B_out << "elf[" << posX << "]" << posY << "]: Munch!" << endl;   
            break;
        case'R':
            B_out << "elf[" << posX << "]" << posY << "]: Run!" <<endl;
            break;
        // for error                                               
        default:
            cout << "Error" << endl; 
            break;
            

    }//end of switch 
    
    B_out.close(); 
}

 
