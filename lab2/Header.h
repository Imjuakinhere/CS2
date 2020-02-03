#pragma once
#include<iostream>
#include <string>

using namespace std;
class linkedList
{
private:
	class node
	{
	public:
		double data;
		node * next;

		node(double x)
		{
			data = x;
			next = NULL;
		}
	};

	node * head;

	//print the contents of the list from p to the end (no loops!)
	void printForwards(node * p)
	{
		if (p == NULL)
		{
			return;
		}
		else
		{
			cout << p->data << endl;
			p = p->next;
			printForwards(p);
		}
	}

	//print the contents of the list from p to the end but in reverse order!
	void printBackwards(node * p)
	{
		if (p == NULL)
		{
			return;
		}
		else
		{
			node * back = p;
			p = p->next;
			printBackwards(p);
			cout << back->data << endl;
		}
	}


public:
	linkedList()
	{
		head = NULL;
	}

	void push_front(double x)
	{
		node * babyNode = new node(x);
		babyNode->next = head;
		head = babyNode;
	}

	void printForwards()
	{
		printForwards(head);
	}

	void printBackwards()
	{
		printBackwards(head);
	}
};


void lineOfStars(int n)
{
	if (n == 0)
	{
		cout << endl;

	}
	else
	{
		cout << "*";
		lineOfStars(n - 1);
	}
}
void stars(int n)
{
	if (n == 0)
	{
		return;
	}
	else
	{
		lineOfStars(n);
		stars(n - 1);
		lineOfStars(n);

	}
}
int numOnes(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		if (n % 2 == 1)
		{
			return 1 + numOnes(n / 2);
		}
		else
		{
			return numOnes(n / 2);
		}
	}
}
bool palindrome(string  s)
{
	if (s.length() < 2)
	{
		return true;
	}
	else
	{
		if (s[0] == s[s.length() - 1])
		{
			return palindrome(s.substr(1, s.length() - 2));
		}
		else
		{
			return false;
		}
	}
}
void reverse(string &name)
{
	if (name.length() <= 0)
	{
		return;
	}
	string back = name.substr(1, name.size() - 2);
	reverse(back);
	name = name.substr(name.size() - 1) + back + name[0];
}
int power(double x, int n)
{
	int i;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		i = x * power(x, --n);
		return i;
	}

}
