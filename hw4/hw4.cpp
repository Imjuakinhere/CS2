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

using namespace std;

template <class T>
class stackQueue
{
private:
	//declare your array variable and
	//any additional variables you need
	//to solve the problem
	T * items;
	unsigned front;
	unsigned back;
	unsigned capacity;
	unsigned numitems;

	//void Resize(unsigned Nsize)
	//{
	//	T * bigarray = new T[Nsize];
	//	for (int i = 0; i < capacity; ++i)
	//	{
	//		unsigned location = (front) % capacity;

	//		bigarray[i] = items[location];
	//		front++;
	//	}
	//	delete[] items;
	//	items = bigarray;
	//	capacity = Nsize;

	//	front = 0;
	//	back = numitems;
	//}
public:
	stackQueue()
	{
		items = new T[capacity];
		capacity = 999;
		front = 0;
		back = 0;

	}


	//Insert x to the "back" of the list of items.
	void addBack(T x)
	{
		if (empty())
		{
			front = 0;
			back = 0;
			items[back] = x;
		}
		else
		{
			back++;
			unsigned location = (back) % capacity;
			items[location] = x;
		}
		numitems++;
		/*if (numitems == capacity)
		{
			Resize(2 * capacity);
		}*/


	}

	//Add x to the "front" of the list of items.
	void addFront(T x)
	{
		if (empty())
		{
			front = 0;
			back = 0;
			items[front] = x;
		}
		else
		{
			if (front == 0)
			{
				front = capacity - 1;
				items[front] = x;
			}
			else
			{
				front--;
				items[front] = x;
			}
		}
		numitems++;
	/*	if (numitems == capacity)
		{
			Resize(2 * capacity);
		}*/
	}

	//Remove and return the item currently at the "back" of the list
	T removeBack()
	{
		T Ritems = items[back];
		if (back == 0)
		{
			back = capacity - 1;
		}
		else
		{
			back--;
		}
		numitems--;
		return  Ritems;

	}

	//Remove and return the item currently at the "front" of the list
	T removeFront()
	{
		T Ritems = items[front];
		if (front == capacity - 1)
		{
			front = 0;
		}
		else
		{
			front++;
		}
		numitems--;
		return Ritems;

	}

	//Is the stackQueue empty?
	bool empty()
	{
		if (numitems == 0)
		{
			return true;
		}
		else
			return false;
	}
};
int main()
{
	stackQueue<int> num;
	num.addFront(1);
	num.addFront(2);
	num.addBack(3);
	num.addFront(1);
	num.addBack(1);
	num.addFront(2);
	num.addBack(3);
	num.addFront(1);

	cout << num.removeFront() << endl;
	cout << num.removeBack() << endl;
	cout << num.removeFront() << endl;
	

}