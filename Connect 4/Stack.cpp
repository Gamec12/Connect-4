#include "Stack.h"
Stack::Stack() :myTop(0)
{
	Stack::size = 0;
}

Stack::Stack(const Stack& original)
{
	size = 0;
	myTop = new Node(original.myTop->data);
	NodePointer ptr = myTop;
	NodePointer ptr2 = original.myTop->next;
	while (ptr2 != nullptr)
	{
		ptr->next = new Node(ptr2->data);
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}

}

Stack::~Stack()
{
	NodePointer ptr = myTop;
	while (myTop != nullptr)
	{
		myTop = myTop->next;
		delete(ptr);
		ptr = myTop;
	}
	//delete(myTop);
}

const Stack& Stack::operator= (const Stack& rightHandSide)
{
	if (this != &rightHandSide)
	{
		this->~Stack();

		NodePointer ptr = new Node(rightHandSide.myTop->data), ptr2 = rightHandSide.myTop->next;
		myTop = ptr;
		while (ptr2 != nullptr)
		{
			ptr->next = new Node(ptr2->data);
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}
	}
	return *this;
}


bool Stack::empty() const
{
	return myTop == 0;
}

void Stack::push(const ElementType& value)
{
	Node* ptr = new Node(value);
	ptr->next = myTop;
	myTop = ptr;
	size++;
}



void Stack::pop()
{
	Node* ptr = myTop;
	myTop = myTop->next;
	delete(ptr);
}

void Stack::display(ostream& out) const
{
	NodePointer ptr = myTop;
	while (ptr != NULL)
	{
		out << ptr->data;
		ptr = ptr->next;
	}
}

ElementType Stack::top() const
{
	return myTop->data;
}

string Stack::toString() // to return
{
	string s1 = "";

	NodePointer ptr = myTop;
	while (ptr != NULL)
	{
		s1 += ptr->data;
		ptr = ptr->next;
	}
	reverse(s1.begin(), s1.end()); // reverses bec stack returns it from top to bottom
	return s1;
	
}
int Stack::getSize()
{
	return size;
}