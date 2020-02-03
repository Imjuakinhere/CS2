#pragma once
#include <string>
#include <vector>
#include <queue>
using namespace std;

class gameGraph
{
private:
	class vertex
	{
	public:
		string data;
		bool mark;
		vertex * bread;

		//List of all edges leaving this vertex
		vector<vertex*> neighbors;

		vertex(string x)
		{
			data = x;
		}
	};

	//For faster vertex lookups,
	//Replace this with a binary search tree (or hash table)
	vector<vertex*> vertexList;

	//Return the vertex with x as it's data field.
	//Return null if it doesn't exist.
	//O( n )  -- oooh slow, use a bst to make this faster 
	vertex * findVertex(string x)
	{
		for (unsigned i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->data == x)
				return vertexList[i];
		}
		return nullptr;
	}

	///////////Game specific stuff////////////////
	vertex * playerLocation;
	

public:

	void addVertex(string x)
	{
		vertex * babyVertex = new vertex(x);
		vertexList.push_back(babyVertex);
	}

	void addDirectedEdge(string x, string y)
	{
		vertex * xVert = findVertex(x);
		vertex * yVert = findVertex(y);

		if (xVert == nullptr || yVert == nullptr)
		{
			cout << "Oh no!  You've hosed up!" << endl;
		}
		else
		{
			xVert->neighbors.push_back(yVert);
		}
	}

	void addEdge(string x, string y)
	{
		addDirectedEdge(x, y);
		addDirectedEdge(y, x);
	}

	/////////////Game specific methods///////////////

	void setPlayerLocation(string x)
	{
		playerLocation = findVertex(x);
	}

	string getPlayerLocation()
	{
		return playerLocation->data;
	}

	//Return list of locations player can get to from current location.
	string getExits()
	{
		string exits = "";
		for (unsigned i = 0; i < playerLocation->neighbors.size(); i++)
		{
			exits = exits + ", " + playerLocation->neighbors[i]->data;
		}
		return exits;
	}

	//Attempt to move player to x.
	//If x is not directly reaching from player location,
	//return false.  Otherwise, move player and return true.
	bool travelTo(string x)
	{
		for (unsigned i = 0; i < playerLocation->neighbors.size(); i++)
		{
			if (x == playerLocation->neighbors[i]->data)
			{
				playerLocation = playerLocation->neighbors[i];
				return true;
			}
		}
		return false;
	}
	void breadthFirstsearch(vertex * s)
	{
		queue<vertex*> Q;
		s->mark = true;
		Q.push(s);

		while (!Q.empty())	
		{

			vertex * x = Q.front();
			Q.pop();
			for (unsigned y = 0; y < x->neighbors.size(); y++)
			{
				vertex * temp = x->neighbors[y];
				if (temp->mark == false)
				{
					Q.push(temp);
					temp->mark = true;
					temp->bread = x;
				}
			}
		}
	}

	string traceback( vertex * s)
	{
		if (s->bread == nullptr)
		{
			return s->data;

		}
		else
		{
			return traceback(s->bread) + ", " + s->data;
		}

	}
	void shortestPathTo(string d)
	{
		for (unsigned i = 0; i < vertexList.size(); i++)
		{
			vertexList[i]->mark = false;
			vertexList[i]->bread = nullptr;
		}

		breadthFirstsearch(playerLocation);

		vertex * dvert = findVertex(d);
		
		cout << traceback(dvert) << endl;
	}
};