#include"Student.h"
#include<iostream>
#include<fstream>

using namespace std;

void menu();
void getData(Student*&);
bool searchSame(string, int);
void Registration();
void AddDrop(LinkList<Student>);
void CalUnit(LinkList<Student>);
void CalCGPA(LinkList<Student>);

int main()
{
	char choice = -1;
	Student* student;
	getData(student);





	//egistration();

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
	string name, code, unit;
	int matric;
	cout << "Please Enter Your Name :";
	getline(cin, name);
	cout << "Please Enter Your Matric Number :";
	cin >> matric;
	if (!searchSame(name, matric))
	{
		LinkList<Course> list;
		Course add;
		int choice = 1, numC = 0;
		do
		{
			cin.get();
			cout << "Course Code: ";
			getline(cin, code);
			cout << "Course Unit: ";
			cin >> unit;
			add.setCourse(code, unit);
			list.appendNode(add);
			numC++;
			cout << "\n1. Add Course\n0. Quit" << endl;
			cout << "Choice: ";
			cin >> choice;
			system("cls");
		} while (choice != 0);
		list.WriteCourse(name, matric, numC);
	}
}

void AddDrop(LinkList<Student>)
{

}

void CalUnit(LinkList<Student>)
{

}

void CalCGPA(LinkList<Student>)
{

}

bool searchSame(string Tname = "", int Tmatric = 0)
{
	fstream file("Student.txt", ios::in);
	if (file.is_open())
	{
		string name, garbage;
		int  num;
		do
		{
			getline(file, name, '\t');
			if (file.eof()) break;
			file >> num;
			if (name == Tname || num == Tmatric)
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

void getData(Student*& student)
{
	fstream file("Student.txt", ios::in);
	if (file.is_open())
	{
		string name, code, unit, garbage = "";
		int num, numcourse, numStu;
		file >> numStu;
		student = new Student[numStu];
		for (int i = 0; i < numStu; i++)
		{
			getline(file, name, '\t');

			if (file.eof()) break;

			file >> num >> numcourse;
			getline(file, garbage, '\t');
			cout << name << num << endl;
			student[i].setName(name);
			student[i].setMatric(num);

			for (int j = 0; j < numcourse; i++)
			{
				getline(file, code, '/');
				getline(file, unit, '\t');
				student[i].setCourse(code, unit);
			}
			cout << endl;
		}
	}
	else
	{
		cout << "File Unable to open" << endl;
	}
}