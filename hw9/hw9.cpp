#pragma once
#include <iostream>
#include <string>

using namespace std;

/*
Implement the "studentList" data structure with a doubly linked list implementation.

You must implement all methods and they must work as described in the comments. 
You must also achieve the stated run times, 
and know the big-Oh run times for each of your methods.
*/


class student
{
public:
	string name;
	unsigned int id;
	double gpa;

	student()
	{
		name = "ghost";
		id = 0;
		gpa = 0;
	}
	student(string _name, unsigned int _id, double _gpa)
	{
		id = _id;
		gpa = _gpa;
		name = _name;
	}
};

class studentList
{
private:
	//Implement a doubly linked list of students

	class node
	{
	public:
		student data;
		node * next;
		node * prev;

		node(student x)
		{
			data = x;
			next = NULL;
			prev = NULL;
		}
	};

	node * head;
	node * tail;

public:
	studentList()
	{
		head = nullptr;
		tail = nullptr;
	}

	//add a student to the list.
	//Must run in O(1) time.
	void insert(student s)
	{
		node * baby = new node(s);
		if (head == nullptr)
		{
			head = baby;
			tail = baby;
		}
		else
		{
			baby->prev = tail;
			tail->next = baby;
			tail = baby;
		}
	}

	//find the student with the given id number and return it
	//What is the worst case run time of this?O(n)
	//What is the average case run time of this?O(n)
	student retrieveStudent(unsigned int idnumber)
	{
		node * kid = head;
		while (kid->data.id != idnumber &&  kid->next != nullptr)
		{
			kid = kid->next;
		}
		if (kid->data.id == idnumber)
		{
			return kid->data;
		}
		else
		{ 
			return student();
		}
	}

	//Change the gpa of the student with given id number to newGPA
	//What is the run time?O(n)
	void updateGPA(unsigned int idnumber, double newGPA)
	{
		node * Bigbrain = head;
		while (Bigbrain->data.id != idnumber && Bigbrain->next != nullptr)
		{
			Bigbrain = Bigbrain->next;
		}
		if (Bigbrain->data.id == idnumber)
		{
			Bigbrain->data.gpa = newGPA;
		}
		else
		{
			cout << "you found a ghost his name is casper\n\n";
		}

	}

	//Add all students from otherlist to this list.
	//otherlist should be empty after this operation.
	//Must run in O(1) time.
	void mergeList(studentList &otherlist)
	{
		tail->next = otherlist.head;
		otherlist.head->prev = tail;
		tail = otherlist.tail;
		otherlist.head = nullptr;
		otherlist.tail = nullptr;
	}

	//create a list of students whose gpa is at least minGPA.
	//Return this list.  The original list should
	//not be modified (do not remove the students from the original list).
	//Run time?O(n)
	studentList honorRoll(double minGPA)
	{
		node * nerd = head;
		studentList nerdlist;
		while (nerd != nullptr)
		{
			if (nerd->data.gpa >= minGPA)
			{
				nerdlist.insert(nerd->data);
			}
			nerd = nerd->next;
		}
		return nerdlist;
	}

	//sort the list by the given field ("name", "id", or "gpa").
	//Run time?O(n^2)
	void sort(string field)
	{
		node * first = head;
		node * temp = new node(student());
		node * second;
		while (first->next)
		{
			bool fix = true;
			second = first->next;
			while (fix)
			{
				if (field == "name" || field == "Name")
				{
					if ((first->data.name > second->data.name) && (first != nullptr))
					{
						temp->data = first->data;
						first->data = second->data;
						second->data = temp->data;
					}
					else if (second->next == nullptr)
					{
						fix = false;
					}
					else
					{
						second = second->next;
					}
				}
				else if (field == "id" || field == "Id")
				{
					if ((first->data.id > second->data.id) && (first != nullptr))
					{
						temp->data = first->data;
						first->data = second->data;
						second->data = temp->data;
					}
					else if (second->next == nullptr)
					{
						fix = false;
					}
					else
					{
						second = second->next;
					}
				}
				else if (field == "gpa" || field == "Gpa")
				{
					if ((first->data.gpa > second->data.gpa) && (first != nullptr))
					{
						temp->data = first->data;
						first->data = second->data;
						second->data = temp->data;
					}
					else if (second->next == nullptr)
					{
						fix = false;
					}
					else
					{
						second = second->next;
					}
				}
				else
				{
					fix = false;
				}
			}
			first = first->next;
		}
	}

	//Print out each student in the list.  This is mainly for testing purposes.
	void printList()
	{
		node * list = head;
		while (list != nullptr)
		{
			cout << "name: " << list->data.name << " id: " << list->data.id << " gpa: " << list->data.gpa << endl;
			list = list->next;
		}
	}
};
