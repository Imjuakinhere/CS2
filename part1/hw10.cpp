#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class wordchecker
{
private:

	class tree
	{
	public:
		tree* right;
		tree* left;
		string word;
		int count;
		tree(string x)
		{
			word = x;
			left = nullptr;
			right = nullptr;
			count = 1;
		}
	};

	tree* root;

	void recinsert(string x, tree* &p)
	{
		if (p == nullptr)
		{
			p = new tree(x);
		}
		else
		{
			if (p->word == x)
			{
				p->count++;
			}
			else if (p->word > x)
			{
				recinsert(x, p->left);
			}
			else
			{
				recinsert(x, p->right);				
			}
		}
	}
	void reccheked(ofstream &x, tree* &y)
	{
		if (y == nullptr)
		{
			return;
		}
		else
		{
			reccheked(x, y->left);
			x << y->word << " " << y->count << endl;
			reccheked(x, y->right);
		}
	}
public:
	wordchecker()
	{
		root = nullptr;
	}
	void insert(string word)
	{
		recinsert(word, root);
	}
	void storycheck(ofstream &x)
	{
		reccheked(x, root);
	}
};

int main()
{
	//part 1
	// Write a program to count the number of 
	// times each word appears in a file story.txt

	wordchecker story1;
	ifstream file;
	ofstream check;
	string x;

	file.open("story.txt");
	check.open("wordCounts.txt");

	if (!file)
	{
		cout << "file not open" << endl;
		return-1;
	}
	if (!check)
	{
		cout << "file not open" << endl;
		return -1;
	}
	while (!file.eof())
	{
		file >> x;
		story1.insert(x);
	}

	story1.storycheck(check);

	file.close();
	check.close();

	system("pause");
	return 0;
	
}
