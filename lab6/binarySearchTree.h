#include <iostream>
using namespace std;

class binarySearchTree
{
private:
	class tree
	{
	public:
		tree* right;
		tree* left;
		int data;
		tree(int x)
		{

			data = x;
			left = nullptr;
			right = nullptr;
		}
	};
	tree* root;

	void insert(int x, tree* &p)
	{
		if (p == nullptr)
		{
			p = new tree(x);
		}
		else
		{
			if (p->data > x)
			{
				insert(x, p->left);
			}
			else
			{
				insert(x, p->right);
			}
		}
	}
	void display(tree* i)
	{
		if (i == nullptr)
		{
			return;
		}
		else
		{

			display(i->left);
			cout << i->data << endl;
			display(i->right);

		}
	}
	int numItems(tree * p)
	{
		if (p == nullptr)
		{
			return 0;
		}
		else
		{
			return 1 + numItems(p->left) + numItems(p->right);
		}
	}
	int numleaves(tree * p)
	{
		if (p == nullptr)
		{
			return 0;
		}
		if (p->left == nullptr && p->right == nullptr)
		{
			return 1;
		}
		else
		{
			return numleaves(p->left) + numleaves(p->right);

		}
	}
	int height(tree * root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		{
			int left = height(root->left);
			int right = height(root->right);

			if (left > right)
			{
				return left + 1;
			}
			else
			{
				return right + 1;
				
			}
		}
	}
	int extractMin(tree * &p)
	{
		if (p->left == nullptr)
		{
			int output = p->data;
			tree * doomed = p;
			p = p->right;
			delete doomed;
			return output;
		}
		else
		{
			return extractMin(p->left);
		}
	}
	int extractMax(tree * &p)
	{
		if (p->right == nullptr)
		{
			int output = p->data;
			tree * doomed = p;
			p = p->left;
			delete doomed;
			return output;
		}
		else
		{
			return extractMax(p->right);
		}
	}

	void remove(tree * &p, int x)
	{
		if (p == nullptr) 
		{
			return;
		}
		if (p->data == x) 
		{
			if (p->left == nullptr && p->right == nullptr)
			{
				tree * doomed = p;
				p = nullptr;
				delete doomed;
			}
			else if (p->left == nullptr) 
			{
				tree * doomed = p;
				p = p->right;
				delete doomed;
			}
			else if (p->right == nullptr)
			{
				tree * doomed = p;
				p = p->left;
				delete doomed;
			}
			else 
			{
				p->data = extractMin(p->right);
			}
		}
		else 
		{
			if (x < p->data)
			{
				remove(p->left, x);
			}
			else
			{
				remove(p->right, x);
			}
		}
	}

public:
	binarySearchTree()
	{
		root = NULL;
	}
	void insert(int key)
	{
		insert(key, root);
	}
	void display()
	{
		display(root);
	}
	int numItems()
	{
		return numItems(root);
	}
	int numLeaves()
	{
		return numleaves(root);
	}
	int getHeight()
	{
		return height(root);
	}
	int extractMin()
	{
		return extractMin(root);
	}
	int extractMax()
	{
		return extractMax(root);
	}
	void remove(int x)
	{
		remove(root, x);
	}
};