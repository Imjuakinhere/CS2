
#include <iostream>
#include <string>
#include <ctime>
#include <queue> //This contains the priority_queue data structure (a "heap")
using namespace std;


void displayArray(double * items, int start, int end)
{
	for (int i = start; i <= end; i++)
		cout << items[i] << " ";
	cout << endl;
}

int filter(double * items, int begin, int last)
{
	double pivot = items[begin];
	int i = begin;
	for (int j = begin + 1; j <= last; j++)
	{
		if (items[j] <= pivot)
		{
			i++;
			swap(items[i], items[j]);
		}
	}
	swap(items[i], items[begin]);
	return i;
}

//The legendary "Blaze Sort" algorithm.
//Sorts the specified portion of the array between index start and end (inclusive)
//Hmmm... how fast is it?

void  blazeSort(double * items, int start, int end)
{
	//Base case:  when is sorting super easy?
	if (start < end)
	{
		//Recursive case:
		//step 1: call filter and get your pivot index.
		int index = filter(items, start, end);
		//step 2: recursively sort the items before the pivot
		blazeSort(items, index +1, end);
		//step 3: recursively sort the items after the pivot
		blazeSort(items, start, index - 1);
	}
}


//Another classic sorting routine is "heap sort" which uses
//a data structure called a "heap", which is an implementation of
//an abstract data type called a "priority queue".  A priority queue
//allows for two primary operations:  "insert" a new item into the data structure,
//and "remove/view" the item with the highest value in the data structure.
//The a heap of n items allows for O(log n) time to insert a new item,
//And O(log n) time to remove the highest value item (and O(1) time to view the value of the largest item in the heap).
//Use the STL heap  (called priority_queue) to implement heap sort.
//The relevent methods are called "push" to insert, "pop" to remove the largest item, and "top" to get the value of the largest item.
//Analyze and state the run-time of your algorithm.
void heapSort(double * items, int start, int end)
{
	priority_queue<double> heap;
	
	//step 1:  put all the items into the heap one by one
	for (int i = start; i <= end; ++i)
	{
		heap.push(items[i]);
	}
	//step 2: remove the largest item from the heap until it is empty,
	//putting the items into the array in the order you remove them.
	for (int i = start; i <= end; ++i)
	{
		items[i] = heap.top();
		heap.pop();
	}

}
int main()
{
	////////////////////////////////////////////////////
	//Part 1:  Implement a method called filter.
	////////////////////////////////////////////////////

	//Filter is a function that takes in an array and a range (start and end).
	//
	//Call the first item in the range the 'pivot'.
	//
	//Filter's job is to simply separate items within the range based on whether they are bigger or smaller than the pivot.
	//In the example array below, 13 is the pivot, so all items smaller than 13 are placed in indices 0-3.  The pivot is then placed at index 4, and all
	//Remaining items, which are larger than the pivot, are placed at positions 5-10.  Note that the array is NOT sorted, just "partitioned" around
	//the pivot value.  After doing this, the function must return the new index of the pivot value.

	double testNumsA[] = { 13, 34.1, 43, 189, 4, 4.5, 18.35, 85, 3, 37.2, 5 };

	//The filter will place all items <= 13 to the left of value 13, and all items large than 13 to the right of 13 in the array.
	int p = filter(testNumsA, 0, 10);
	cout << p << endl; //should be 4, the new index of 13.
	displayArray(testNumsA, 0, 10);  //should display something like this:  5 3 4.5 4 13 18.35 85 189 37.2 43 34.1

									 //One more example:
	double testNumsB[] = { 13, 34.1, 43, 189, 4, 4.5, 18.35, 85, 3, 37.2, 5 };
	p = filter(testNumsB, 2, 6);  //Here we are only interested in items from indices 2-6, ie, 43, 189, 4, 4.5, 18.35
	cout << p << endl; //should be 5
	displayArray(testNumsB, 0, 10); //Notice only indices 2-6 have been partioned:  13 34.1 18.35 4 4.5 43 189 85 3 37.2 5


	/////////////////////////////////////////////////////////////////////////////////
	//Part 2:  Implement "Blaze Sort".joprj
	//Blaze Sort uses/needs your filter method to work properly.
	/////////////////////////////////////////////////////////////////////////////////


	//Test if Blaze Sort correctly sorts the following array.
	double testNums[] = { 13, 34.1, 43, 189, 4, 4.5, 18.35, 85, 3, 37.2, 5 };

	blazeSort(testNums, 0, 10);

	displayArray(testNums, 0, 10);

	/////////////////////////////////////////////////////////////////////
	//Part 3:  Test how fast Blaze Sort is for large arrays.
	//What do you think the run-time (big-Oh) of blaze sort is?(N logn)
	/////////////////////////////////////////////////////////////////////

	//Stress test:
	int size = 1000000; //test with: 1000, 10000, 100000,1000000, 10000000
	double * numbers = new double[size];

	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand();
	}

	clock_t startTime, endTime;

	startTime = clock();
	blazeSort(numbers, 0, size - 1);
	endTime = clock();

	//displayArray(numbers, 0, size - 1);
	cout << "Blaze sort took: " << endTime - startTime << " milliseconds to sort " << size << " doubles." << endl;


	///////////////////////////////////////////////////////////
	//Part 4: Implement heap sort.  Don't forget to analyze it's run-time.
	///////////////////////////////////////////////////////////
	//Stress test:
	size = 100; //test with: 1000, 10000, 100000,1000000, 10000000
	double * numbers2 = new double[size];

	for (int i = 0; i < size; i++)
	{
		numbers2[i] = rand();
	}

	startTime = clock();
	heapSort(numbers2, 0, size - 1);
	endTime = clock();

	displayArray(numbers2, 0, size - 1);
	cout << "Heap sort took: " << endTime - startTime << " milliseconds to sort " << size << " doubles." << endl;


	system("pause");
	return 0;
}