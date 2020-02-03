// Joaquin Garcia
// class 2380

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class node
{
public:
	string data;
	node * next;
};

//Create a linkedList class here
class linkedList
{
	private:
		node * head;
	public:
		linkedList()
		{
			head = nullptr;
		}
		void addFront(string name)
		{
			node * babynode = new node;
			babynode->next = head;
			babynode->data = name;
			head = babynode;
		}
		void display()
		{
			node* current = head;
			while (current != nullptr)
			{
				cout << current->data << endl;
				current = current->next;
			}
		}
		void removeFront()
		{
			node * doomednode = head;
			head = head->next;
			delete doomednode;
		}
		void addBack(string name)
		{
			node * back = new node;
			back->data = name;
			back->next = nullptr;
			
			if (head == nullptr)
			{
				head = back;
			}
			else
			{
				node * tail = head;
				while (tail->next != nullptr)
				{
					tail = tail->next;
				}
				tail->next = back;
			}
		}
		// To remove something in the list i created 2 temps
		// because i want one of them tom be in the name and 
		//the other one to be infornt to give the location from 
		// the name to keep the linklist working then remove the name
		void remove(string name)
		{
			bool find = true;
			node * temp1 = head;
			node * temp2 = head;
			if (head->data == name)
			{
				node *temp1 = head;
				head = head->next;
				delete temp1;
				find = false;
			}
			while (find)
			{
				temp1 = temp1->next;
				if (temp1->data != name)
				{
					temp2 = temp1->next;
					if (temp2->data == name)
					{
						temp1->next = temp2->next;
						delete temp2;
						find = false;
					}

				}
			}
		}

		// I decided to sort the link list by 
		//comparing the data inside them and
		// swaping. i used a selection sort
		void sort()
		{
			node * first = head;
			node * temp1 = new node;
			node * temp;
			while (first->next)
			{
				bool fix = true;
				temp = first->next;
				while (fix)
				{
					if (first->data > temp->data)
					{
						
						temp1->data = first->data;
						first->data = temp->data;
						temp->data = temp1->data;
						
					}
					else if(temp->next == nullptr)
					{
						fix = false;
					}
					else
					{
						temp = temp->next;
					}
				}
				first = first->next;
			}
		}
};
int main()
{
	//part 0:  Implement adding items to the front and displaying the list
	linkedList list1;

	list1.addFront("pichacu");
	list1.addFront("elmo");
	list1.addFront("charmander");
	list1.addFront("ekans");

	list1.display(); //ekans charmander elmo pichacu

	cout << endl;

	//part 0.1:  Implement removal from front
	list1.removeFront();
	list1.removeFront();

	list1.addFront("snorlax");

	list1.display(); //snorlax elmo pichacu

	cout << endl;

	//part 1:  implement "addBack"
	linkedList list2;
	list2.addBack("rattata");
	list2.addBack("raticate");
	list2.addBack("arcanine");
	list2.addFront("arbok");
	list2.addFront("eevee");

	list2.display(); //eevee arbok rattata raticate arcanine

	cout << endl;

	//part 2: implement "remove"
	list2.remove("arcanine");
	list2.remove("rattata");
	list2.remove("eevee");

	list2.addFront("dugtrio");
	list2.addBack("charizard");

	list2.display(); //dugtrio arbok raticate charizard

	cout << endl;
	//part 3: implement "sort"
	list1.sort();
	list2.sort();

	list1.display(); //elmo pichacu snorlax
	cout << endl;
	list2.display(); //arbok charizard dugtrio raticate


	return 0;
}