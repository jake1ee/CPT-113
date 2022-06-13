#include"Student.h"
#include<iostream>
#include<fstream>
#include"Student.h"

void getInput(Student&);
int getData(Student* &);

void Registration(Student* &, int);
void displayStudent(Student*&, int);
void StudentSameCourse(Student*&, int);
void CalUnit(Student*&, int);



int main()
{
	Student* student;
	int size = getData(student);
	/*Registration(student, size);*/
	/*displayStudent(student, size);*/
	/*StudentSameCourse(student, size);*/
	CalUnit(student, size);



	

	

	return 0;
}

void getInput(Student& student)
{
	string name, code;
	int matric, unit;
	bool same = false;
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
		int  num, numC, numS=0, unit;
		while (getline(file,garbage))
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
	system("pause");
	system("cls");
}


void StudentSameCourse(Student*& student, int size)
{
	LinkList<string> list;
	string search;
	int search2;
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
	system("pause");
	system("cls");
}