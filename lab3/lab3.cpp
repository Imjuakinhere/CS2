#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void binarySearch(string dictionary[], int start, int end, string key)
{
	if (end < start) //oh, no search space, BASE CASE!
	{
		cout << "WHOA! " <<  key  << " isn’t a word!  Bad human! Learn to spell!";
	}
	else //Recursive case
	{
		int mid = (start + end) / 2;

		if (dictionary[mid] == key) //middle item equals the key)
		{
			cout << "The word " << dictionary[mid] << "is spelled correctly!";
		}
		else if (key < dictionary[mid]) //key is less than middle item)
		{
			return binarySearch(dictionary, start, mid - 1, key);
		}
		else 			//key is greater than middle item
		{
			return binarySearch(dictionary, mid + 1, end, key);
		}
	}
};
int main()
{
	const int SIZE = 202412;
	string look;
	string word[SIZE];
	ifstream file;
	file.open("largedictionary.txt");

	for(int i = 0;i < SIZE; ++i)
	{
		file >> word[i];
	}
	while (true)
	{
		cout << "Enter another word:\n";
		cin >> look;
		binarySearch(word, 0, SIZE -1, look);
	}
	system("pause");
}