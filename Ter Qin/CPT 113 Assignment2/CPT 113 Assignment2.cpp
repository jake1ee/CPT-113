#include"Student.h"
#include<iostream>
#include<fstream>


void menu();
bool searchSame(const Student&);
void Registration();
void DisplayStudent(LinkList);
void CalUnit(LinkList);
void CalCGPA(LinkList);

int main()
{
	char choice=-1;


	Registration();

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
		LinkList list;
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
				list.displayList();
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

void AddDrop()
{

}

void DisplayStudent()
{

}

void CalCGPA()
{

}

bool searchSame(const Student& compare)
{
	fstream file("Student.txt", ios::in);
	if (file.is_open())
	{
		Student temp;
		string name, garbage;
		int  num;
		do
		{
			getline(file, name, '\t');
			if (file.eof()) break;
			file >> num;
			temp.setName(name);
			temp.setMatric(num);
			if (temp == compare)
			{
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