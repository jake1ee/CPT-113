#include"LinkList.h"

double getPoint(string grade)	//get grade point 
{
	if (grade == "A")
		return 4.00;
	else if (grade == "A-")
		return 3.75;
	else if (grade == "B+")
		return 3.33;
	else if (grade == "B")
		return 3.00;
	else if (grade == "B-")
		return 2.67;
	else if (grade == "C+")
		return 2.33;
	else if (grade == "C")
		return 2.00;
	else if (grade == "C-")
		return 1.67;
	else if (grade == "D+")
		return 1.33;
	else if (grade == "D")
		return 1;
	else if (grade == "D-")
		return 0.67;
	else if (grade == "F")
		return 0;
	else
		return -1;
}


//**************************************************
// appendNode appends a node containing the value *
// pased into newValue, to the end of the list. *
//**************************************************
void LinkList<Course>::appendNode(Course newValue, int& numCourse)
{
	ListNode<Course>* newNode; // To point to a new node
	ListNode<Course>* nodePtr; // To move through the list
	// Allocate a new node and store newValue there.
	newNode = new ListNode<Course>(newValue);
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

void LinkList<Course>::displayListC()
{
	ListNode<Course>* nodePtr;
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

void LinkList<Course>::keyInGrade(double &totalpoint)
{
	ListNode<Course>* nodePtr;
	// To move through the list
	// Position nodePtr at the head of the list.
	nodePtr = head;
	double gradepoint;
	string grade;
	// While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{
		nodePtr->value.displayCourse();
		do
		{
			cout << "Grade: ";
			cin >> grade;
			gradepoint = getPoint(grade);
			if (gradepoint == -1)
				cout << "Invalid Input Please Enter Again" << endl;
		} while (gradepoint == -1);
		cout << endl;
		totalpoint += gradepoint*nodePtr->value.getUnit();
		nodePtr = nodePtr->next;
	}
}

int LinkList<Course>::getTotalUnit()
{
	ListNode<Course>* nodePtr;
	// To move through the list
	// Position nodePtr at the head of the list.
	nodePtr = head;
	int totalUnit = 0;
	// While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{
		totalUnit += nodePtr->value.getUnit();
		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	return totalUnit;
}

//*****************************************************
// The deleteNode function searches for a node *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory. *
//*****************************************************

void LinkList<Course>::deleteNode(Course searchValue, int& numCourse)
{
	ListNode<Course>* nodePtr = nullptr; // To traverse the list
	ListNode<Course>* previousNode = nullptr; // To point to the previous node
	// If the list is empty, do nothing.
	if (!head)
	{
		cout << "List is Empty\n";
		return;
	}
	// Initialize nodePtr to head of list
	nodePtr = head;

	// Determine if the first node is the one.
	if (head != nullptr && head->value == searchValue)
	{
		head = head->next;
		numCourse--;
		cout << "Deleting Node with Code( " << nodePtr->value.getCode() << '/' << nodePtr->value.getUnit() << ")" << endl;
		delete nodePtr;
	}
	else
	{
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

//write course into txt file
void LinkList<Course>::WriteCourse(string name, int num, int numCourse)
{
	fstream file("Student.txt", ios::app | ios::out);
	ListNode<Course>* nodeptr = head;

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

void LinkList<Course>::setSame(const LinkList<Course>& obj)
{

	ListNode<Course>* current = obj.head;
	ListNode<Course>* newNode; // To point to a new node
	ListNode<Course>* nodePtr; // To move through the list

	while (current)
	{
		// Allocate a new node and store newValue there.
		newNode = new ListNode<Course>(current->value);
		// If there are no nodes in the list,make newNode the first node.
		if (!head)
		{
			this->head = newNode;
		}
		else // Otherwise, insert newNode at end.
		{
			// Initialize nodePtr to head of list.
			nodePtr = this->head;
			// Find the last node in the list.
			while (nodePtr->next)
				nodePtr = nodePtr->next;
			// Insert newNode as the last node.
			nodePtr->next = newNode;
		}
		current = current->next;
	}

}