#include "Header.h"

int main()
{
	//ab: Recursion Fun - TEST YOUR MIGHT!
	//
	//No loops allowed for this lab:
	//-no for loops
	//-no while loops
	//-no do-while's
	//-no while-do's
	//-no for-while's
	//-no while-for-do's

	//#1: Write a method ‘void lineOfStars(int n)’ that prints a line of n stars.  You may not use a loop.

	lineOfStars(5);  //   should display: *****
	cout << endl;

	//#2: Write a method ‘void stars(int n)’ that prints the weird shape below.  You may not use a loop.  You may call ‘lineOfStars’ as a subroutine.

	stars(4);
	cout << endl;

	//should display:
	//****
	//***
	//**
	//*
	//*
	//**
	//***
	//****
	//#3: Write a recursive function ‘int numOnes(int n)’ that returns the number of 1's in the binary expansion of n.

	cout << numOnes(5325) << endl << endl;  //should display 7, because 5325 is 1010011001101 in binary.

	//	//#4: Write a recursive function ‘bool palindrome(string s)’ that returns true if s is a palindrome and false if not.
	
	cout << palindrome("racecar") << endl << endl;
			
	//	//#5: Write a recursive function 'void reverse(string &word)' that reverses the given input string.
	string name = "robbie";
	reverse(name);
	cout << name << endl << endl;  //should display "eibbor".

	//	#6: Write a recursive function 'int power(double x, int n) to compute x^n. 
	//  What is the run time of your function in terms of n? 
	//  Can you achieve O(log n)?

	cout << power(5, 5) << endl << endl;

	//	//#7: Write recursive "printForward(node *p)" and "printBackward(node * p)" methods for the linked list class provided below so that the following test code words as specified in the comments:
	
		linkedList list;
		list.push_front(8);
		list.push_front(7);
		list.push_front(6);	
		list.push_front(5);
		list.push_front(4);
		list.push_front(3);
		list.push_front(2);
		list.push_front(1);	
	
		list.printForwards(); //1,2,3,4,5,6,7,8,
		cout << endl;
		list.printBackwards(); //8,7,6,5,4,3,2,1, 
		cout << endl;
};
	
