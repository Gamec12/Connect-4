

#include <iostream>
#include <string>
#include <algorithm>
#include "Stack.h";

using namespace std;
int pickAPlace();
void displayTheBoard(Stack s1[], const int NUMBEROFSTACKS);
int player1Turn(Stack s1[]);
int player2Turn(Stack s1[]);
bool CheckForWin(Stack s1[], int pos);
bool CheckForWin(Stack s1[], int pos);
int main()
{
	const int NUMBEROFSTACKS = 7;
	Stack s1[NUMBEROFSTACKS];
	int round = 0; // to keep track of how many rounds have passed
	/*for (int i = 0; i < NUMBEROFSTACKS; i++)
	{
		s1[i].push("A");
		s1[i].push("B");
	}*/
	//int check = true;
	int pos;
	displayTheBoard(s1, NUMBEROFSTACKS);
	while (true) 
	{
		/*
			the main game loop where it will allow each player to once place a token and  then it will check if that player won if not
			it will allow the next player to enter a token and then check if that player won
			the board will be displayed after every token is placed
			this will repat over and over until one player wins
		*/
		pos = player1Turn(s1);
		displayTheBoard(s1, NUMBEROFSTACKS);
		if (CheckForWin(s1, pos))
			break;
		pos = player2Turn(s1);
		if (CheckForWin(s1, pos))
			break;
		displayTheBoard(s1 , NUMBEROFSTACKS);
	}

}

int pickAPlace() // user enters the specific colom to place his token in
{
	int pos;
	cout << "choose a place to place your token ";
	cin >> pos;
	while (pos < 0 || pos >7) // for input validation
	{
		cout << "please enter a valid number between 1 and 7";
		cin >> pos;
	}
		
	return pos - 1;
}

void displayTheBoard(Stack s1[] , const int NUMBEROFSTACKS) // displays the whole board with the number of coloms
{
	for (int i = 0; i < NUMBEROFSTACKS; i++)
	{
		string s2 = s1[i].toString();
		reverse(s2.begin(), s2.end());
		cout << i+1 << " " << s2 << endl;
		
	}
}


bool CheckForWin( Stack s1[], int pos) // checks if one of the player won by checking if 4 matching tokens were added
{
	return false;
}

int player1Turn(Stack s1[])// to automatically put two diffrent tokens in each one?
{
	int pos = pickAPlace();
	cout << endl << s1[pos].getSize() << endl;
	while (s1[pos].getSize() >=7) // to make sure that the user can't choose a full colomn 
	{
		cout << "Colom " << pos+1 << " is full please choose another column\n";  // could remove the button in gui
		pos = pickAPlace();
		
	}
	s1[pos].push("A");
	return pos;
	
}

int player2Turn(Stack s1[])
{
	int pos = pickAPlace();
	cout << endl << s1[pos].getSize() << endl;
	while (s1[pos].getSize() >= 7) // to make sure that the user can't choose a full colomn 
	{
		cout << "Colom " << pos + 1 << " is full please choose another column\n";  // could remove the button in gui
		pos = pickAPlace();

	}
	s1[pos].push("B");
	return pos;
}


