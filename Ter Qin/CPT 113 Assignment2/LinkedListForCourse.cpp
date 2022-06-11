#include"LinkList.h"
#include<fstream>

void LinkList<Course>::DisplayStudentCourse()
{
	ListNode<Course>* nodeptr = head;
	while (nodeptr != nullptr)
	{
		nodeptr->value.displayCourse();
		nodeptr = nodeptr->next;
	}
}

void LinkList<Course>::WriteCourse(string name, int num, int numCourse)
{
	fstream file("Student.txt", ios::app|ios::out);
	ListNode<Course>* nodeptr = head;
	
	if (file.is_open())
	{
		file <<"\n" << name << "\t";
		file << num << "\t";
		file << numCourse << "\t";
		while (nodeptr != nullptr)
		{
			file << nodeptr->value.getCode() << "/" << nodeptr->value.getUnit() << "\t";
			nodeptr = nodeptr->next;
		}
	}
	else
	{
		cout << "Unable to open the file" << endl;
	}
	

	file.close();
}

////void LinkList<Course>::SetStudentCourse()
//{
//	string code = "",unit ="
//  int choice = 1;
//	Node* nodeptr = new Node;
//	while (choice != 0)
//	{
//		cout << "Please Enter Course Code (Example-CPT113) :";
//		cin >> code;
//		cout << "Please Enter Course Unit: ";
//		cin >> unit;
//		nodeptr->value.setCourse(code, unit);
//	}
//}