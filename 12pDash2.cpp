#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

void pressEnterToContinue();


int main() {


	string datafile;
	cout << "Enter filename: ";
	getline(cin, datafile);
	ifstream inFile(datafile);

	string word;
	int letters = 0;
	int words = 0;

	if (!inFile.is_open()) {
		cerr << "Error opening file." << endl;
		return 1;
	}

	while (inFile >> word) {
		words++;
		letters += word.size();
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