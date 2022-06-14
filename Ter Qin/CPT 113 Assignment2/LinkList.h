#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include <string>
#include"Course.h"

using namespace std;

//*********************************************
// The ListNode class creates a type used to *
// store a node of the linked list. *
//*********************************************
template<class T>
class ListNode
{
public:
	T value; // Node value T of class personInfo - composition
	ListNode<T>* next; // Pointer to the next node
	//Constructor
	ListNode()
	{
		value = NULL;
		next = nullptr;
	}
	ListNode(T nodeValue)
	{
		value = nodeValue;
		next = nullptr;
	}
};


template<class T>
class LinkList
{
private:
	ListNode<T>* head;
public:
	// Constructor 
	LinkList()
	{
		head = NULL;
	}

	// Destructor 
	~LinkList();

	// Linked list operations
	// For Template Type of data
	void appendNode(T); //to add node
	void insertNode(T); //to insert node
	void deleteNode(T); //to delete node
	bool searchNode(T); //to search node
	void displayList() const; //to display all nodes
	bool empty();       //to check the list is empty or not
	// For Course Type of data
	void appendNode(Course, int&); //to add node
	void deleteNode(Course, int&); //to delete node
	void displayListC(); //to display all nodes
	void displayListG(); //to display all nodes
	void WriteCourse(string, int, int); // to write the Student Info to txt file
	void setSame(const LinkList<Course>&);
	int getTotalUnit();
	double getGP();


	void displayListS();
};

//****************************************
// Destructor *
// This function deletes every node in the list. *
//**************************************************

template<class T>
LinkList<T>::~LinkList()
{
	ListNode<T>* nodePtr; // To traverse the list
	// Position nodePtr at the head of the list.
	nodePtr = head;
	// While nodePtr is not at the end of the list...
	while (nodePtr)
	{

		// Save a pointer to the next node.
		ListNode<T>* nextNode = nodePtr->next;
		// Delete the current node.
		delete nodePtr;
		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
	head = nullptr;

}


//**************************************************
// appendNode appends a node containing the value *
// pased into newValue, to the end of the list. *
//**************************************************

template <class T>
void LinkList<T>::appendNode(T newValue)
{
	ListNode<T>* newNode; // To point to a new node
	ListNode<T>* nodePtr; // To move through the list
	// Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);
	// If there are no nodes in the list,make newNode the first node.
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;
		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head. *
//**************************************************

template <class T>
void LinkList<T>::displayList()  const
{
	// To move through the list
	// Position nodePtr at the head of the list.
	ListNode<T>* nodePtr = head;
	// While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value;
		if (nodePtr->next != nullptr)
		{
			cout << ", ";
		}
		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with. *
// newValue copied to its value member. *
//**************************************************

template <class T>
void LinkList<T>::insertNode(T newValue)
{
	ListNode<T>* newNode;
	ListNode<T>* nodePtr;
	ListNode<T>* previousNode = NULL;
	// The previous
	// Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);
	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;
		// Initialize previousNode to nullptr.
		previousNode = NULL;
		// A new node
		// To traverse the list node
		// Skip all nodes whose value is less than newValue.
		while (nodePtr != NULL && nodePtr->value.getIC() < newValue.getIC()) // method in PersonInfo
		{
		}
		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

template<class T>
bool LinkList<T>::searchNode(T searchValue)
{
	ListNode<T>* nodePtr; // To traverse
	ListNode<T>* previousNode; // To point to
	// If the list is empty, do nothing.
	if (!head)
		cout << "List is Empty\n";
	// Determine if the first node is the one.

		// Initialize nodePtr to head of list
	nodePtr = head;
	// Skip all nodes whose value member is not equal to IC.
	while (nodePtr != NULL && !(nodePtr->value == searchValue))
	{
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
	}
	// If nodePtr is not at the end of the list,
	// link the previous node to the node after
	// nodePtr, then delete nodePtr.
	if (nodePtr)
	{
		return true;
	}
	return false;

}

//*****************************************************
// The deleteNode function searches for a node *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory. *
//*****************************************************

template <class T>
void LinkList<T>::deleteNode(T searchValue)
{
	ListNode<T>* nodePtr; // To traverse the list
	ListNode<T>* previousNode; // To point to the previous node
	// If the list is empty, do nothing.
	if (!head)
		cout << "List is Empty\n";
	// Determine if the first node is the one.
	if (head->value == searchValue)
	{
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		// Skip all nodes whose value member is not equal to num.
		while (nodePtr != NULL && nodePtr->value != searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// If nodePtr is not at the end of the list, link the previous node
		// to the node after nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//*****************************************************
// The empty function check  whether it is empty or no*
//*****************************************************
template <class T>
bool LinkList<T>::empty()
{
	if (head == NULL)
		return true;
	return false;
}

#endif // LINKEDLIST_H
