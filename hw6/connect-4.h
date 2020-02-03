#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

class Connect4
{
	private:

		int rows;
		int colums;
		char ** Board;
		char player;
	public:
		//first thing first i want to set up the 
		// the standard constructur and the custom constructur
		Connect4()
		{
			rows = 6;
			colums = 7;
			Board = new char *[rows];
			for (int i = 0; i < rows; ++i)
			{
				Board[i] = new char[colums];
			}
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < colums; ++j)
				{
					Board[i][j] = ' ';
				}
			}
		}
		Connect4(int numrows, int numColumns)
		{
			rows = numrows;
			colums = numColumns;
			Board = new char *[rows];
			for (int i = 0; i < rows; ++i)
			{
				Board[i] = new char[colums];
			}
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < colums; ++j)
				{
					Board[i][j] = ' ';
				}
			}
		}
		//Once we created the boards we want to display
		//the board to the players so they can play the game
		void DrawBoard()
		{
			cout << "  ";
			for (int i = 0; i < colums; ++i)
			{
				cout << "_"  << " ";
			}
			cout << endl;
			for (int i = 0; i < rows; ++i)
			{
				cout  << i <<  "|";
				for (int j = 0; j < colums; ++j)
				{
					cout <<  Board[i][j] << " ";
				}
				cout <<"|"<< endl;
			}
			cout << "  ";
			for (int i = 0; i < colums; ++i)
			{
				cout  << "_" << " ";
			}
			cout << endl;
		}
		// This ai just gets a number between 0- colums-1
		// and gives it to main to make a move
		int GetAIMove()
		{
			srand(static_cast<unsigned>(time(NULL)));
			int random = rand() % colums;
			return random;
		}
		//Know we need to allow the player to make a move 
		//but at the same time checking if they put something within
		// the range of the columns and also checking if the columns 
		//are full.
		
		bool MakeMove(char pieces, int Colums)
		{
			player = pieces;

			int x = rows - 1;
			int y = Colums;

			while (y > 0 || y < colums)
			{
				if (Board[x][y] == ' ')
				{
					Board[x][y] = player;
					return true;
				}
				else if (Board[x][y] != ' ')
				{
					--x;
					 if (x == -1)
					{
						cout << "pick another place\n";
						return false;
					}
				}
		
			}
			return false;
		}
		// so were checking for every winning condition 
		// we have verticle / horizantal / diagonal left / diagonal right
		// also have the last condition wich is tie
		bool GameOver()
		{
			  // First we going to creater some counters 
			int verticle;
			int horizontal;
			int diagonalleft;
			int diagonalright;
			// First we going to check for the verticle lines
			for (int i = 0; i < colums; ++i)
			{
				verticle = 0;
				for (int j = rows - 1; j >= 0; --j)
				{
					if (Board[j][i] == player)
					{
						verticle++;
						if (verticle == 4)
						{
							return true;
						}
					}
					else if (Board[j][i] != player)
					{
						verticle = 0;
					}
					else
					{
						continue;
					}
				}
			}
			// know we need to check the horizontal
			// by fliping the position of the for loops 
			//of the verticle 
			for (int i = rows - 1; i > 0; --i)
			{
				horizontal = 0;
				for (int j = 0; j < colums; ++j)
				{
					if (Board[i][j] == player)
					{
						horizontal++;
						if (horizontal == 4)
						{
							return true;
						}
					}
					else if (Board[i][j] != player)
					{
						horizontal = 0;
					}
				}
			}
			// know that we finish checking the verticle and horizontal 
			//know we need to check for the left diagnol and right diagnol
			for (int i = 0; i < colums; ++i)
			{
				for (int j = rows - 1; j > 0; --j)
				{
					diagonalright = 0;
					int y = i;
					for (int x = j; x > 0; --x)
					{
						if (Board[x][y] == player)
						{
							diagonalright++;
							++y;
							if (diagonalright == 4)
							{
								return true;
							}
						}
						else if (Board[x][y] != player)
						{
							diagonalright = 0;
							++y;
						}
					}

				}
			}
			//know im going to check for the left side witch is just the oppsite 
			//of the right just that the for loops have changed
			for (int i = colums -1; i > 0; --i)
			{
				for (int j = rows - 1; j > 0; --j)
				{
					diagonalleft = 0;
					int y = i;
					for (int x = j; x > 0; --x)
					{
						if (Board[x][y] == player)
						{
							diagonalleft++;
							--y;
							if (diagonalleft == 4)
							{
								return true;
							}
						}
						else if (Board[x][y] != player)
						{
							diagonalleft= 0;
							--y;
						}
					}

				}
			}
			return false;

		}
		char Winner()
		{
			return player;
		}

};
 