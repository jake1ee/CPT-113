#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class LinkList
{
private:

	struct Node
	{
		T value;
		Node* next;
		Node* previous;
	};

	Node* head;
	Node* end;
public:
	LinkList();
	~LinkList();
	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void showList();
};

#include <iostream>

using namespace std;

template <class T>
LinkList<T>::LinkList()
{
	head = nullptr;
	end = nullptr;
}

template <class T>
LinkList<T>::~LinkList()
{
	Node* current = head;
	while (current != 0) {
		Node* next = current->next;
		free(current);
		current = next;
	}
	head = 0;
}

template <class T>
void LinkList<T>::appendNode(T data)
{
	Node* newNode = new Node;
	newNode->value = data;
	newNode->next = nullptr;
	if (head == nullptr)
	{
		newNode->previous = nullptr;
		head = newNode;
	}
	else
	{
		newNode->previous = end;
		end->next = newNode;
	}
	end = newNode;
}

template <class T>
void LinkList<T>::insertNode(T data)
{
	Node* newnNode = new Node;
	newnNode->value = data;

	Node* current = head;
	if (head == nullptr)
	{
		return;
	}
	else
	{
		while (current != nullptr)
		{
			if (current->value > data)
			{
				newnNode->next = current->next;
				current->next = newnNode;
				newnNode->previous = current;
				cout << "Done Inssert Node with data " << data << endl;
				return;
			}
			current = current->next;
		}
		cout << "Insert Failed" << endl;
	}
}

template <class T>
void LinkList<T>::deleteNode(T data)
{
	Node* current = head;
	Node* prev = new Node;

	if (head == nullptr)
	{
		return;
	}
	else
	{
		while (current != nullptr)
		{
			if (current->value == data)
			{
				prev->next = current->next;
				current->previous = prev;
				free(current);
				cout << "Done Delete The Data " << data << endl;
				return;
			}
			prev = current;
			current = current->next;
		}
		cout << "Cant Find The data" << endl;
	}
}

template <class T>
void LinkList<T>::showList()
{
	Node* nodeptr;
	for (nodeptr = head; nodeptr != nullptr; nodeptr = nodeptr->next)
	{
		cout << nodeptr->value << ' ';
	}
	cout << endl;
}


#endif // LINKEDLIST_H
