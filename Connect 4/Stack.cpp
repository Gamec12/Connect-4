#include "Stack.h"

Stack::Stack()
{
	myTop = -1;
}

void Stack::push(ElementType item)
{
	myTop++;
	arr[myTop] = item;
}

ElementType Stack::top()
{
	return arr[myTop];
}

void Stack::pop()
{
	arr[myTop] = 0;
	myTop--;
}
