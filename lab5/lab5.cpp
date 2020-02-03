#include <iostream>
#include <string>
using namespace std;

class binarySearchTree
{
private:
	class tree
	{
	public:
		tree* right;
		tree* left;
		double data;
		tree(double x)
		{

			data = x;
			left = nullptr;
			right = nullptr;
		}
	};
	tree* root;

	void recursive(double x, tree* &p)
	{
		if (p == nullptr)
		{
			p = new tree(x);
		}
		else
		{
			if (p->data > x)
			{
				recursive(x, p->left);
			}
			else
			{
				recursive(x , p->right);
			}
		}
	}
	void recdisplay(tree* i)
	{
		if (i == nullptr)
		{
			return;
		}
		else
		{
			
			recdisplay(i->left);
			cout << i->data << endl;
			recdisplay(i->right);
			
		}
	}
	int recnumItems(tree * p)
	{
		if (p == nullptr)
		{
			return 0;
		}
		else
		{
			return 1 + recnumItems(p->left) + recnumItems(p->right);
		}
	}
	int recnumleaves(tree * p)
	{

		if (p->left == nullptr && p->right == nullptr)
		{		if (p == nullptr)
		{
			return 0;
		}
			return 1;
		}
		else
		{
			 return recnumleaves(p->left) + recnumleaves(p->right);
			
		}
	}

public:
	binarySearchTree()
	{
		root = NULL;
	}
	void insert(double key)
	{
		recursive(key, root);
	}
	void display()
	{
		recdisplay(root);
	}
	int numItems()
	{
		return recnumItems(root);
	}
	int numLeaves()
	{
		return recnumleaves(root);
	}
	
	
};
int main()
{
	binarySearchTree bst;

	bst.insert(5);
	bst.insert(5.5);
	bst.insert(-20);
	bst.insert(30);
	bst.insert(12);
	bst.insert(100);
	bst.insert(7);
	bst.insert(5.2);
	bst.insert(1);
	bst.insert(0);
	bst.insert(3);
	bst.insert(17);
	bst.insert(16);


	//Print all items in the tree.
	bst.display();

	//Write a method to count and return the number of
	//items currently in the tree.
	cout << bst.numItems() << endl;

	////Write a method to count and return the number of
	////leaves in the tree.
	cout << bst.numLeaves() << endl;

	////Write a method to compute and return the height
	////of the tree.
	//cout << bst.height() << endl;


	////random number test
	//BinarySearchTree bst2;
	//int size = 1000;
	//for (int i = 0; i < size; i++)
	//{
	//	bst2.insert(rand());
	//}

	//cout << bst2.height() << endl;

	////sorted order!  Oh no, worst-case behavior!
	//BinarySearchTree bst3;
	//for (int i = 0; i < size; i++)
	//{
	//	bst3.insert(i);
	//}

	//cout << bst3.height() << endl;

	//system("pause");
	return 0;
}