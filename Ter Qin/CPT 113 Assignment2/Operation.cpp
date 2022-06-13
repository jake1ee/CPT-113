#include"Operation.h"
#include<fstream>

void getInput(Student& student)
{
	system("cls");
	string name, code;
	int matric, unit = 0;
	bool same = false;
	cin.get();
	cout << "Please Enter Your Name :";
	getline(cin, name);
	cout << "Please Enter Your Matric Number :";
	cin >> matric;
	student.setName(name);
	student.setMatric(matric);
}

int getData(Student*& student)
{
	fstream file("Student.txt", ios::in);
	if (file.is_open())
	{
		Student temp;
		Course temp2;
		string name, code, garbage;
		int  num, numC, numS = 0, unit;
		while (getline(file, garbage))
		{
			numS++;
		}
		file.clear();
		file.seekg(0, ios::beg);
		student = new Student[numS];
		for (int i = 0; i < numS; i++)
		{
			getline(file, name, '\t');
			if (file.eof()) break;
			file >> num;
			temp.setName(name);
			temp.setMatric(num);
			file >> numC;
			getline(file, garbage, '\t');
			for (int i = 0; i < numC; i++)
			{
				getline(file, code, '/');
				file >> unit;
				getline(file, garbage, '\t');
				temp2.setCourse(code, unit);
				temp.setStudentCourse(temp2);
			}
			getline(file, garbage);
			student[i] = temp;
			temp.reset();
		}
		return numS;
	}
	else
	{
		cout << "File Unable to open" << endl;
	}
	return -1;
}

void Registration(Student*& student, int size)
{
	Student temp;
	getInput(temp);
	bool same = false;
	for (int i = 0; i < size; i++)
	{
		if (student[i] == temp)
			same = true;
	}

	if (!same)
	{
		LinkList<Course> list;
		Course add, Delete;
		string code;
		int choice = 1, numC = 0, unit;
		do
		{
			switch (choice)
			{
			case 1:
				cin.get();
				cout << "Course Code: ";
				getline(cin, code);
				cout << "Course Unit: ";
				cin >> unit;
				add.setCourse(code, unit);
				list.appendNode(add, numC);
				break;
			case 2:
				list.displayListC();
				cin.get();
				cout << "Course Code: ";
				getline(cin, code);
				cout << "Course Unit: ";
				cin >> unit;
				Delete.setCourse(code, unit);
				list.deleteNode(Delete, numC);

				system("pause");
				break;
			default:
				cout << "Invalid Choice: please try again" << endl;
				break;
			}
			cout << "\n1. Add Course\n2. Delete Course\n0. Quit" << endl;
			cout << "Choice: ";
			cin >> choice;
			system("cls");
		} while (choice != 0);
		list.WriteCourse(temp.getName(), temp.getMatric(), numC);
		cout << "Registration Success" << endl;
	}
}

void displayStudent(Student*& student, int size)
{
	Student temp;
	getInput(temp);
	bool same = false;
	for (int i = 0; i < size; i++)
	{
		if (student[i] == temp)
		{
			same = true;
			temp = student[i];
		}

	}
	if (same)
	{
		temp.displayDetails();
	}
	else
	{
		cout << "Student Not Found." << endl;
	}
}


void StudentSameCourse(Student*& student, int size)
{
	system("cls");
	LinkList<string> list;
	string search;
	int search2;
	cin.get();
	cout << "Please Enter Course Code: ";
	getline(cin, search);
	cout << "Please Enter Course Unit: ";
	cin >> search2;
	for (int i = 0; i < size; i++)
	{
		if (student[i].searchCourse(search, search2))
			list.appendNode(student[i].getName());
	}
	if (!list.empty())
	{
		cout << "The Student which take the course " << search << "/" << search2 << " is: " << endl;
		list.displayList();
		cout << endl;
	}
	else
	{
		cout << "No one take the course " << search << "/" << search2 << endl;
	}

}

void CalUnit(Student*& student, int size)
{
	Student Temp;
	bool same = false;
	getInput(Temp);
	for (int i = 0; i < size; i++)
	{
		if (student[i] == Temp)
		{
			Temp = student[i];
			same = true;
		}
	}
	if (same)
	{
		Temp.displayUnits();
	}
	else
	{
		cout << "Student Not Found." << endl;
	}
}


void menu() {
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
		<< "2. Display Student Details \n "
		<< "3. Search Student with same Course Code \n "
		<< "4. Calculate total unit by semester \n "
		<< "5. Calculate CGPA \n "
		<< "6. Exit \n \n ";
	cout << endl << endl;;
}


//int integer_optionValidation() {
//	int integer = 0;
//	int converttoint = 0;
//	bool temporaryholder = 0;
//	int userInput = 0;
//	int a = 0;
//
//	do {
//		cout << "Please choose an option: ";
//		cin >>userInput;
//		if (userInput==NULL) {
//			cout << "Please enter an input." << endl;
//			continue;
//		}
//		for (a = 0; a < userInput.length(); a++) {
//			if (isdigit(userInput[a])) {
//				integer++;
//			}
//		}
//		if (integer == userInput.length()) {
//			converttoint = stoi(userInput);
//			temporaryholder = 1;
//		}
//		else {
//			cout << "Invalid input.\n";
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			temporaryholder = 0;
//			integer = 0;
//		}
//	} while (temporaryholder = 0);
//	return converttoint;
//}

//int optionValidation(int a, int b) {
//	int optionEnter = 0;
//	// Check whether the input entered is within the range 
//	do {
//		cout << "Please choose an option: ";
//		cin >> optionEnter;
//		if (optionEnter < a || optionEnter > b) {
//			cout << "Out of range. Please enter between 1 to 6. \n";
//		}
//	} while (optionEnter < a || optionEnter > b);
//	return optionEnter;
//}

void start()
{
	Student* student;
	int size = getData(student);
	int choice;
	do
	{
		
		menu();
		cout << "Please choose an option: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Registration(student, size);
			exit(EXIT_SUCCESS);
			break;
		case 2:
			displayStudent(student, size);
			break;
		case 3:
			StudentSameCourse(student, size);
			break;
		case 4:
			CalUnit(student, size);
			break;
		case 5:
			break;
		case 6:
			cout << "Thank You For Using The Program." << endl;
			break;
		default:
			cout << "Out of range. Please enter between 1 to 6. \n";
			break;
		}
		system("pause");
		system("cls");
	} while (choice != 6);
}