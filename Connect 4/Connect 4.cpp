

#include <iostream>
#include "Stack.h";
int main()
{
	Stack s1;

	s1.push(10);
	s1.push(11);
	s1.push(12);
	s1.pop();
	cout << s1.top();
	s1.display(cout);

}
