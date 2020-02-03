
#include "binarySearchTree.h"



int main()
{
	binarySearchTree tree;

	tree.insert(15);
	tree.insert(24);
	tree.insert(53);
	tree.insert(-3);
	tree.insert(23);
	tree.insert(77);
	tree.insert(100);
	tree.insert(17);
	tree.insert(33);
	tree.insert(5);
	tree.insert(-10);
	tree.insert(2);

	tree.display();

	//part 1:  warmup with some basic methods
	cout << "number of items: " << tree.numItems() << endl;
	cout << "number of leaves: " << tree.numLeaves() << endl;
	cout << "height: " << tree.getHeight() << endl;

	//part 2: implement removal of smallest or largest items
	cout << "extractmin" << endl;
	cout << tree.extractMin() << endl; //displays -10
	cout << tree.extractMin() << endl; //displays -3
	cout << "extract max" << endl;
	cout << tree.extractMax() << endl; //displays 100
	cout << tree.extractMax() << endl; //displays 77

	cout << "befor remove" << endl;
	tree.display(); //verify above 4 values have been removed

	//part 3: implement a method that finds and removes a given value.
	tree.remove(33);
	tree.remove(15);
	tree.remove(5);

	tree.insert(43);

	cout << "display after removed" << endl;
	tree.display(); //verify above 3 have been removed and insert still works.

	system("pause");
	return 0;
}