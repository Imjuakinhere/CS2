//////////////////////////////////////////////////////
// Topics: circular arrays, templated classes, dynamic arrays
//
// Implement a stackQueue using a
// circular array implementation as discussed in class.
// Your data structure must increase its array size dynamically
// if the array runs out of room.
//
// Abstractly, your stackQueue represents a list of items
// with a front and back from which items may be added
// or removed.  If you choose to add and remove from just
// one end, you effectively have a stack.  If you choose
// to add to the back and remove from the front, (or vice versa)
// you effectively have a queue, thus the name "stackQueue".
//
//
///////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;



template <class T>
class stackQueue
{
private:
	//declare your array variable and
	//any additional variables you need
	//to solve the problem
	T * items;
	unsigned capacity;
	unsigned front;
	unsigned back;
	unsigned numitems;

public:
	stackQueue()
	{
		items = new T[capacity];
		capacity = 5;
		front = -1;
		back = 0;
		numitems = 0;
	}

	//Insert x to the "back" of the list of items.
	void addBack(T x)
	{
		if (front == -1)
		{
			front = 0;
			back = 0;
		}
		else if (back == capacity - 1)
		{
			back = 0;
		}
		else
		{
			back = back + 1;
		}
		items[back] = x;
		numitems++;
	}

	//Add x to the "front" of the list of items.
	void addFront(T x)
	{
		if (front == -1)
		{
			front = 0;
			back = 0;
		}
		else if (front == 0)
		{
			front = capacity - 1;
		}
		else
		{
			front = front - 1;
		}
		items[front] = x;
		numitems++;
	}

	//Remove and return the item currently at the "back" of the list
	T removeBack()
	{
		numitems--;
		T stuff = items[back];
		if (back == 0)
		{
			back = capacity - 1;
		}
		else
		{
			back = back - 1;
		}
		return stuff;
		
	}

	//Remove and return the item currently at the "front" of the list
	T removeFront()
	{
		numitems--;
		T stuff = items[front];
		
		if (front == capacity - 1)
		{
			front = 0;
		}
		else
		{
			front = front + 1;
		}
		return stuff;

	
	}

	//Is the stackQueue empty?
	bool empty()
	{
		return (numitems == 0);
	}
};


int main()
{
	stackQueue<int> numbers;

	numbers.empty();
	numbers.addFront(1);
	numbers.addFront(2);
	numbers.empty();
	numbers.addBack(3);
	cout << numbers.removeBack();
	cout << numbers.removeFront();

	

	system ("pause");
	return 0;
}