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
		tree(string x, int y)
		{
			word = x;
			count = y;
			left = nullptr;
			right = nullptr;
		}
	};
	tree* root;
	tree* fakeroot;
	int stopcount = 0;
	vector<string> dic;

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
	bool binarySearch(vector<string>& dic, int start, int end, string caseWord)
	{
		if (end < start)
		{
			return true;
		}
		else
		{
			int mid = (start + end) / 2;

			if (dic[mid] == caseWord)
			{
				return false;
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
	void fake(tree *& A)
	{
		if (A == nullptr)
		{
			return;
		}
		else
		{
			fake(A->left);
			if (Rootsearch(A->word))
			{
				fakelist(A->word, A->count, fakeroot);
			}
			fake(A->right);

		}
	}
	void wfake(string x ,int y, tree*& p)
	{
		if (p == nullptr)
		{
			p = new tree(x,y);
		}
		else
		{
			if (p->count == y)
			{
				wfake(x, y, p->left);
			}
			else if (p->count > y)

			{
				wfake(x, y, p->left);
			}
			else
			{
				wfake(x, y, p->right);
			}
		}
	}
	void fakedisplay(ofstream & file, tree*& A)
	{
		
			if (A == nullptr)
			{
			}
			else
			{
				fakedisplay(file, A->right);
				top100(A->word, A->count, file);
				fakedisplay(file, A->left);
			}
	}
	void print(string &x, int&y, ofstream & A)
	{
		if (stopcount < 100)
		{
			A << x << " " << y << endl;
			++stopcount;
		}
	}
public:
	wordchecker()
	{
		root = nullptr;
		fakeroot = nullptr;
	}
	void insert(string word)
	{
		insert(word, root);
	}
	bool Rootsearch(string x)
	{
		return binarySearch(dic, 0, dic.size(), x);
	}
	void search()
	{
		dictinary();
	}
	void fakelist(string &x, int &y, tree*& A)
	{
		wfake(x,y, A);
	}
	void fake()
	{
		fake(root);
	}
	void display(ofstream & Ofile)
	{
		fakedisplay(Ofile, fakeroot);
	}
	void top100(string &x,int &y, ofstream & a)
	{
		print(x, y, a);
	}
	
};
