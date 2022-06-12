#include"Student.h"
#include<iostream>
#include<fstream>

void menu();
bool searchSame(Student&);
void Registration();
void StudentSameCourse();
void DisplayStudent();
void CalUnit();
void CalCGPA();

int main()
{
	char choice=-1;


	//Registration();
	//DisplayStudent();
	StudentSameCourse();
	/*do
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case '1':
			Registration(student);
			break;
		case '2':
			AddDrop(student);
			break;
		case '3':
			CalUnit(student);
			break;
		case '4':
			CalCGPA(student);
			break;
		case '0':

			break;
		default:
			cout << "Invalid Choice: Please Enter Again.";
			break;
		}
	} while (choice!= 0);*/
	

	return 0;
}

void menu()
{
	cout << " ---------- Welcome to Group 26 Course Registration ---------- " << endl;
	cout << "1. Course Registration \n2. Add/Drop Course \n3. Total Unit of the semester\n4. Calculate CGPA of the Semester\n0. Exit" << endl;
	cout << "Choice: ";
}

void Registration()
{
	Student Temp;
	string name, code, unit;
	int matric;
	cout << "Please Enter Your Name :";
	getline(cin, name);
	cout << "Please Enter Your Matric Number :";
	cin >> matric;
	Temp.setMatric(matric);
	Temp.setName(name);
	if (!searchSame(Temp))
	{
		LinkList<Course> list;
		Course add, Delete;
		int choice = 1, numC = 0;
		numC++;
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
				list.appendNode(add,numC);
				break;
			case 2:
				list.displayListC();
				cin.get();
				cout << "Course Code: ";
				getline(cin, code);
				cout << "Course Unit: ";
				cin >> unit;
				Delete.setCourse(code, unit);
				list.deleteNode(Delete,numC);

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
		list.WriteCourse(name, matric, numC);
	}
}

void DisplayStudent()
{
	Student Temp;
	string name, code, unit;
	int matric;
	cout << "Please Enter Your Name :";
	getline(cin, name);
	cout << "Please Enter Your Matric Number :";
	cin >> matric;
	Temp.setMatric(matric);
	Temp.setName(name);
	if (searchSame(Temp))
	{
		Temp.displayDetails();
	}
	else
	{
		cout << "Student Not Found." << endl;
	}
	system("pause");
	system("cls");
}

void StudentSameCourse()
{
	LinkList<string> list;
	Student temp;
	Course temp2;
	fstream file("Student.txt", ios::in);
	string name, search, search2, code,garbage;
	int numC;
	cout << "Please Enter Course Code: ";
	getline(cin, search);
	cout << "Please Enter Course Unit: ";
	cin >> search2;
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, name, '\t');
			if (file.eof()) break;
			getline(file, garbage, '\t');
			file >> numC;
			getline(file, garbage, '\t');
			for (int i = 0; i < numC; i++)
			{
				getline(file, code, '/');
				getline(file, garbage, '\t');				
				temp2.setCourse(code, garbage);
				temp.setStudentCourse(temp2);
			}
			getline(file, garbage);
			if (temp.searchCourse(search,search2))
			{
				list.appendNode(name);
			}
			temp.reset();
		}
		if (!list.empty())
		{
			cout << "The Student which take the course " << search << "/" << search2 << " is: " << endl;
			list.displayList();
		}
		else
		{
			cout << "No one take the course " << search << "/" << search2 << endl;
		}
	}
	else
	{
		cout << "Error: Invalid Open File." << endl;
	}

}

void CalUnit()
{

}

void CalCGPA()
{

}

bool searchSame( Student& compare)
{
	fstream file("Student.txt", ios::in);
	if (file.is_open())
	{
		Student temp;
		Course temp2;
		string name, garbage, code, unit;
		int  num, numC;
		do
		{
			getline(file, name, '\t');
			if (file.eof()) break;
			file >> num;
			temp.setName(name);
			temp.setMatric(num);
			if (temp == compare)
			{
				file >> numC;
				getline(file, garbage, '\t');
				for (int i = 0; i < numC; i++)
				{
					getline(file, code,'/');
					file >> unit;
					temp2.setCourse(code, unit);
					compare.setStudentCourse(temp2);
				}
				return true;
			}
			getline(file, garbage);

		} while (!file.eof());
	}
	else
	{
		cout << "File Unable to open" << endl;
	}
	return false;
}