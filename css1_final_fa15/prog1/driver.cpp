// Name:Raquel Figueroa
// Date: 17 December 2015
// CSS-1 Fa15 Final Exam Prog 1

#include <iostream>//cin, cout
#include <fstream>//ifstream, ofstream
#include <cstdlib>//exit()
#include <vector>//vectors

using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);

int main()
{
	vector<string> p;//vector for passwords
	bool goodWord = true;
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic", "aboral", "Santa", 			"password1", "Password!", "ambystomidae"};

	ifstream fin;
	fin.open("passwords.txt");
	if(fin.fail())
	{
		cout << "Passwords.txt file failed to open.\n";
		exit(1);
	}

	ofstream fout;
	fout.open("good_words.txt");
	if(fout.fail())
	{
		cout << "Goods_words.txt failed to open.\n";
		exit(1);
	}

	fillVector(p, fin);//fills vector with pwords from txt file

	fout << "Name: Raquel Figueroa\n";

	for(int i = 0; i < SIZE; i++)//iterates through password array
	{
		goodWord = true;

		for(int j = 0; j < p.size(); j++)
		{
			if(possible[i] == p[j])
			{
				goodWord = false;
			}
		}
		if (goodWord == true)
		{
			fout << possible[i] << endl;
		}
	}



	cout << "good through here!\n";


	fin.close();
	fout.close();

	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string val;
	while (A_in >> val)
	{
		PW.push_back(val);
	}
	
}// end fill Vector(_)


 
