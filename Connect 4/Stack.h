#pragma once
const int SIZE = 6;
class Stack
{
private:
	typedef int ElementType;
	ElementType arr[SIZE];
	int myTop;
public:
	Stack()
	{
		myTop = -1;
	}

	void push(ElementType item)
	{
		myTop++;
		arr[myTop] = item;
	}

	ElementType top()
	{
		return arr[myTop];
	}

	void pop()
	{
		arr[myTop] = 0;
		myTop--;
	}

};

