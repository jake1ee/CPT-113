#include"LinkList.h"

//****************************************
// Destructor *
// This function deletes every node in the list. *
//**************************************************


LinkList::~LinkList()
{
	ListNode* nodePtr; // To traverse the list
	ListNode* nextNode; // To point to the next node
	// Position nodePtr at the head of the list.
	nodePtr = head;
	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;
		// Delete the current node.
		delete nodePtr;
		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

//**************************************************
// appendNode appends a node containing the value *
// pased into newValue, to the end of the list. *
//**************************************************

void LinkList::appendNode(Course newValue, int &numCourse)
{
	ListNode* newNode; // To point to a new node
	ListNode* nodePtr; // To move through the list
	// Allocate a new node and store newValue there.
	newNode = new ListNode(newValue);
	// If there are no nodes in the list,make newNode the first node.
	if (!head)
	{
		head = newNode;
	}	
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
	numCourse++;
}

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head. *
//**************************************************

void LinkList::displayList() const
{
	ListNode* nodePtr;
	// To move through the list
	// Position nodePtr at the head of the list.
	nodePtr = head;
	// While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{
		// Display the value in this node.
		nodePtr->value.displayCourse();
		cout << endl;
		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//*****************************************************
// The deleteNode function searches for a node *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory. *
//*****************************************************

void LinkList::deleteNode(Course searchValue, int& numCourse)
{
	ListNode* nodePtr = nullptr; // To traverse the list
	ListNode* previousNode = nullptr; // To point to the previous node
	// If the list is empty, do nothing.
	if (!head)
	{
		cout << "List is Empty\n";
		return;
	}

	// Determine if the first node is the one.
	if (head != nullptr && head->value == searchValue)
	{
		nodePtr = head;
		head = head->next;
		numCourse--;
		cout << "Deleting Node with Code( " << head->value.getCode() << '/' << head->value.getUnit() << ")" << endl;
		delete nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		// Skip all nodes whose value member is not equal to num.
		while (nodePtr != NULL && !(nodePtr->value == searchValue))
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// If nodePtr is not at the end of the list, link the previous node
		// to the node after nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			numCourse--;
			cout << "Deleting Node with Code( " << nodePtr->value.getCode() << '/' << nodePtr->value.getUnit() << " )" << endl;
			delete nodePtr;
		}
		else
		{
			cout << "Deletion Fail: Cant Found The Course" << endl;
		}
	}
}

void LinkList::searchNode(Course searchValue)
{
	ListNode* nodePtr; // To traverse
	ListNode* previousNode; // To point to
	// If the list is empty, do nothing.
	if (!head)
		cout << "List is Empty\n";
	// Determine if the first node is the one.
	if (head != nullptr && head->value == searchValue)
	{
		cout << "\n Found at first node \n";
		head->value; system("pause");
	}
	else
	{
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
			cout << "\n Found \n";
			nodePtr->value;
			system("pause");
		}
		else
		{
			cout << "\nNot found\n"; system("pause");
		}
	}
}

void LinkList::DisplayStudentCourse()
{
	ListNode* nodeptr = head;
	while (nodeptr != nullptr)
	{
		nodeptr->value.displayCourse();
		nodeptr = nodeptr->next;
	}
}

void LinkList::WriteCourse(string name, int num, int numCourse)
{
	fstream file("Student.txt", ios::app | ios::out);
	ListNode* nodeptr = head;

	if (file.is_open())
	{
		file << '\n' << name << '\t';
		file << num << '\t';
		file << numCourse << '\t';
		while (nodeptr != nullptr)
		{
			file << nodeptr->value.getCode() << '/' << nodeptr->value.getUnit() << '\t';
			nodeptr = nodeptr->next;
		}
	}
	else
	{
		cout << "Unable to open the file" << endl;
	}


	file.close();
}