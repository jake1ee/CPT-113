#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include"Course.h"

using namespace std;

//*********************************************
// The ListNode class creates a type used to *
// store a node of the linked list. *
//*********************************************
 class ListNode
{
public:
	Course value; // Node value T of class personInfo - composition
	ListNode* next; // Pointer to the next node
	//Constructor
	ListNode(Course nodeValue)
	{
		value = nodeValue;
		next = nullptr;
	}
};


class LinkList
{
private:
	ListNode* head;
public:
	// Constructor 
	LinkList()
	{
		head = NULL;
	}

	// Destructor 
	~LinkList();

	// List head pointer
	// Linked list operations
	void appendNode(Course, int&); //to add node
	void deleteNode(Course, int&); //to delete node
	void searchNode(Course); //to delete node
	void displayList() const; //to display all nodes
	void DisplayStudent();
	void DisplayStudentCourse();
	void WriteCourse(string, int, int);
};
#endif // LINKEDLIST_H
