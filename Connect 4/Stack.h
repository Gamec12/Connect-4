#pragma once
const int SIZE = 6;
typedef int ElementType;
class Stack
{
private:
	
	ElementType arr[SIZE];
	int myTop;
public:
	Stack();
	

	void push(ElementType item);
	

	ElementType top();
	

	void pop();
	

};

