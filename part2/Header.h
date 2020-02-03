#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<queue>

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
			count = 1;
			left = nullptr;
			right = nullptr;
		}
	};

	tree* root;
	vector<string> dic;

	void insert(string x, tree* &p)
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
				insert(x, p->left);
			}
			else
			{
				insert(x, p->right);
			}
		}
	}
	void cheked(ofstream &x, tree* &y)
	{
		if (y == nullptr)
		{
			return;
		}
		else
		{
			cheked(x, y->left);
			x << y->word << " " << y->count << endl;
			cheked(x, y->right);
		}
	}
	void dictinary()
	{
		ifstream Infile;
		Infile.open("largedictinary.txt");

		while (!Infile.eof())
		{
			string w;
			Infile >> w;
			dic.push_back(w);
		}
	}
	bool Rootsearch(string x)
	{
		return binarySearch(dic, 0, dic.size(), x);
	}
	bool binarySearch(vector<string>& dic, int start, int end, string caseWord)
	{
		if (end < start)
		{
			return false;
		}
		else
		{
			int mid = (start + end) / 2;

			if (dic[mid] == caseWord)
			{
				return true;
			}
			else if (caseWord < dic[mid])
			{
				return binarySearch(dic, start, mid - 1, caseWord);
			}
			else
			{
				return binarySearch(dic, mid + 1, end, caseWord);
			}
		}
	}

	void Display(tree * p, ofstream &outfile)
	{
		if (p == nullptr)
		{
			return;
		}
		else
		{
			Display(p->left, outfile);
			if (!(Rootsearch(p->word)))
			{
				outfile << "(fake Word) " << p->word << " "<< p->count << endl;
			}
			else
			{
				outfile << p->word << right << p->count << endl;
			}
			Display(p->right, outfile);
		}
	}


public:
	wordchecker()
	{
		root = nullptr;
	}
	void insert(string word)
	{
		insert(word, root);
	}
	void storycheck(ofstream &x)
	{
		cheked(x, root);
	}
	void search()
	{
		dictinary();
	}
	void display(ofstream &A)
	{
		Display(root, A);
	}
	void fake()

};