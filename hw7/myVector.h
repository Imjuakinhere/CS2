#pragma once
template <class vec>
class vector
{
private:
	int SIZE = 0;
	int cap = 0;
	vec * ray;

	void resize()
	{
		int tempcap = (cap + 11) * 2;
		vec * temp = new vec[tempcap];
		for (int i = 0; i < cap; ++i)
		{
			temp[i] = ray[i];
		}
		cap = tempcap;
		delete[]ray;
		ray = temp;
	}
public:
	//First I created the defult cases
	vector()
	{
		ray = new vec[cap]; 
	}
	vector(int x)
	{
		cap = x;
		ray = new vec[cap];
	}
	vector(int x, vec stuff)
	{
		cap = x;
		ray = new vec[cap];
		for (int i = 0; i < cap; ++i)
		{
			ray[i] = stuff;
			SIZE++;
		}
	}
	//well i need sizze and capacity to show
	//show how many thing are inside the array
	//also capacity shows you how many thing you
	//can put in the array
	int size()
	{
		return SIZE;
	}
	int capacity()
	{
		return cap;
	}
	//This is a overload that allwoes the user to change
	//the contant of the array from main by telling it
	// where in the array he is going to change 
	vec& operator[](int i)
	{
		return ray[i];
	}
	//push_back
	void push_back(vec i)
	{
		if (SIZE + 1 >= cap)
		{
			resize();
		}
		ray[SIZE] = i;
		SIZE++;
	}
	void pop_back()
	{
		SIZE--;
	}
	vec back()
	{
		return ray[SIZE - 1];
	}
	
};