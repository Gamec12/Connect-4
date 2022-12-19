#pragma once
#include <iostream>

using namespace std;
typedef char ElementType;

class Stack
{
private:

	class Node {
	public:

		Node* next;
		ElementType data;
		Node() :next(0)
		{

		}

		Node(ElementType data) :data(data), next(0)
		{

		}
	};
public:

	Stack(); // default constructor

	Stack(const Stack& orig); // copy constructor to copy what is in one stack to another stack

	~Stack(); // destuctor to unassign the memory

	bool empty() const; // returns true if the list is empty
	void push(const ElementType& item); // to add an item to the top

	void pop(); // to remove item from the top

	ElementType top()const;// returns the top element in the list

	void display(ostream& out) const;

	const Stack& operator= (const Stack& rightSide);

	string toString(); // returns the entire stack as a string
	
	bool hasPosition(int position); // returns true if the stack has an element in position
	int getSize();

	typedef Node* NodePointer;
	NodePointer myTop;
	int size;
	const int capacity = 6;

	ElementType& operator[](int index);

};
