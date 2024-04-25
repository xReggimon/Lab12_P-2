#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

void pressEnterToContinue();
bool isLetter(char ch);

int main() {


	string datafile;
	cout << "Enter filename: ";
	getline(cin, datafile);
	ifstream inFile(datafile);

	string word;
	int letters = 0;
	int words = 0;

	char ch;
	bool inWord = false;

	if (!inFile.is_open()) {
		cerr << "Error opening file." << endl;
		return 1;
	}

	while (inFile.get(ch)) {
		if (isLetter(ch)) {
			letters++;
			if(!inWord){
				inWord = true;
				words++;
			}
		}
		else {
			inWord = false;
		}
	}

	inFile.close();

	cout << "Words: " << words << endl;
	cout << "Letters: " << letters << endl;

	pressEnterToContinue();
	return 0;
}


void pressEnterToContinue() {
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n')continue;
}

bool isLetter(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}