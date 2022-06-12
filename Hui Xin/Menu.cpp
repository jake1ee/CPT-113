
#include <iostream>
#include <string>
using namespace std;

int menu();
int optionValidation(int, int);
int integer_optionValidation();

int main()
{
	int menuoption = 0;
	do {
		system("cls");
		menuoption = menu();
		switch (menuoption) {
		case 1:
			cout << "Course Registration";
			break;
		case 2:
			cout << "Add course";
			break;
		case 3:
			cout << "Drop course";
			break;
		case 4:
			cout << "Calculate total unit by semester";
			break;
		case 5:
			cout << "Calculate CGPA";
			break;
		case 6:
			exit(0);
			break;
		}
	} while (menuoption != 6);
	return 0 ;
}

int menu() {
	int option = 0;
	cout << ".88b  d88. d88888b d8b   db db    db " << endl;
	cout << "88'YbdP`88 88'     888o  88 88    88 " << endl;
	cout << "88  88  88 88ooooo 88V8o 88 88    88 " << endl;
	cout << "88  88  88 88~~~~~ 88 V8o88 88    88 " << endl;
	cout << "88  88  88 88.     88  V888 88b..d88 " << endl;
	cout << "YP  YP  YP Y88888P VP   V8P  Y8888P  " << endl;
	cout << endl;
	cout << " Registration System For Computer Science Student \n ";
	cout << "1. Course Registration \n "
		 << "2. Add course \n "
		 << "3. Drop course \n "
		 << "4. Calculate total unit by semester \n "
		 << "5. Calculate CGPA \n "
		 << "6. Exit \n \n ";
	cout << endl << endl;
	option = optionValidation(1, 6);
	return option;
}


int integer_optionValidation() {
	int integer = 0;
	int converttoint = 0;
	bool temporaryholder = 0;
	string userInput = "";
	int a = 0;

	do {
		cout << "Please choose an option: ";
		getline(cin, userInput);
		if (userInput.empty()) {
			cin.clear();
			cout << "Please enter an input." << endl;
			continue;
		}
		for (a = 0; a < userInput.length(); a++) {
			if (isdigit(userInput[a])) {
				integer++;
			}
		}
		if (integer == userInput.length()) {
			converttoint = stoi(userInput);
			temporaryholder = 1;
		}
		else {
			cout << "Invalid input.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			temporaryholder = 0;
			integer = 0;
		}
	} while (temporaryholder = 0);
	return converttoint;
}

int optionValidation(int a, int b) {
	int optionEnter = 0;
	// Check whether the input entered is within the range 
	do {
		optionEnter = integer_optionValidation();
		if (optionEnter < a || optionEnter > b) {
			cout << "Out of range. Please enter between 1 to 6. \n";
		}
	} while (optionEnter < a || optionEnter > b);
	return optionEnter;
}