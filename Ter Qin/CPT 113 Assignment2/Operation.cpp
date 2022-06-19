#include"Operation.h"
#include<fstream>

void getInput(Student& student)		//prompt user for name and matric in Registration
{
	int matric;
	cout << "Please Enter Your Matric Number :";
	cin >> matric;
	while (matric > 999999) 
	{
		cout << "Invalid input." << endl;
		cout << "Please Enter Your Matric Number :";
		cin >> matric;
	}
	student.setMatric(matric);
}


int getData(Student*& student)		//reading from txt file
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

bool Registration(Student*& student, int size)		//to register student and their courses
{
	Student temp;
	getInput(temp);
	bool same = false;
	for (int i = 0; i < size; i++)
	{
		if (temp == student[i])
		{
			temp.setName(student[i].getName());
			same = true;
		}
		
	}
	if (!same)
	{
		LinkList<Course> list;
		Course add, Delete;
		string code, name;
		int choice = 1, numC = 0, unit;
		cin.get();
		cout << "Please Enter Your Name :";
		getline(cin, name);
		temp.setName(name);
		cout << "Course Code (eg: ABC 123): ";
		getline(cin, code);
		cout << "Course Unit (eg: 3): ";
		cin >> unit;
		add.setCourse(code, unit);
		list.appendNode(add, numC);
		do
		{
			cout << "\n1. Add Course\n2. Delete Course\n0. Quit" << endl;
			cout << "Choice: ";
			cin >> choice;
			cin.get();
			system("cls");

			switch (choice)
			{
			case 1:
				cout << "Course Code (eg: ABC 123): ";
				getline(cin, code);
				cout << "Course Unit (eg: 3): ";
				cin >> unit;
				add.setCourse(code, unit);
				if (list.searchNode(add))
				{
					cout << "The Course is already Registered" << endl;
				}
				else
				{
					list.appendNode(add, numC);
				}
				break;
			case 2:
				list.displayListC();
				cout << "Course Code (eg: ABC 123): ";
				getline(cin, code);
				cout << "Course Unit (eg: 3): ";
				cin >> unit;
				Delete.setCourse(code, unit);
				list.deleteNode(Delete, numC);
				system("pause");
				break;
			default:
				cout << "Invalid Choice: please try again" << endl;
				break;
			}
		} while (choice != 0);
		list.WriteCourse(temp.getName(), temp.getMatric(), numC);
		cout << "Registration Successful!" << endl;
		return true;
	}
	else
	{
		cout << "Student (" << temp.getName() << ") with Matric Number " << temp.getMatric() << " Already Registered." << endl;
		return false;
	}
}

void displayStudent(Student*& student, int size)		//to display student according to matric number prompted
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


void StudentSameCourse(Student*& student, int size)		//to search for any other students taking the same course
{
	system("cls");
	LinkList<string> list;
	string search;
	int search2;
	cin.get();
	cout << "Please Enter Course Code (eg: ABC 123): ";
	getline(cin, search);
	cout << "Please Enter Course Unit (eg: 3): ";
	cin >> search2;
	for (int i = 0; i < size; i++)
	{
		if (student[i].searchCourse(search, search2))
			list.appendNode(student[i].getName());
	}
	if (!list.empty())
	{
		cout << "The student(s) which are taking the course " << search << "/" << search2 << " is: " << endl;
		list.displayList();
		cout << endl;
	}
	else
	{
		cout << "No one is taking the course " << search << "/" << search2 << endl;
	}

}

void CalUnit(Student*& student, int size)		//to calculate student's total unit taken for the semester
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

void CalCGPA(Student*& student, int size)		//to calculate student's CGPA at end of semester
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
		Temp.Grade();
	}
	else
	{
		cout << "Student Not Found." << endl;
	}
}

void menu() {		//To display Start menu 
	int option = 0;
	cout << "Welcome to Year 1 Semester 2!" << endl << endl;
	cout << ".88b  d88. d88888b d8b   db db    db " << endl;
	cout << "88'YbdP`88 88'     888o  88 88    88 " << endl;
	cout << "88  88  88 88ooooo 88V8o 88 88    88 " << endl;
	cout << "88  88  88 88~~~~~ 88 V8o88 88    88 " << endl;
	cout << "88  88  88 88.     88  V888 88b..d88 " << endl;
	cout << "YP  YP  YP Y88888P VP   V8P  Y8888P  " << endl;
	cout << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << " Registration System For Computer Science Student \n ";
	cout << "1. Course Registration \n "
		<< "2. Display Student Details \n "
		<< "3. Search Student with same Course Code \n "
		<< "4. Calculate total unit by semester \n "
		<< "5. Calculate CGPA \n "
		<< "6. Exit \n \n ";
	cout << "---------------------------------------------------------------" << endl;
	cout << endl << endl;;
}


void start()		//start function to prompt user to choose functions
{
	Student* student;
	int size = getData(student);
	int choice;
	do
	{
		menu();
		cout << "Please choose an option: ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			if (Registration(student, size))
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
			CalCGPA(student, size);
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
