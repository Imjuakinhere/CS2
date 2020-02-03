#include "Connect-4.h"

int main()
{
	int player;
	int colums;
	char * person;
	bool per = true;
	
	
	while (per)
	{


		cout << "How many people are playing ";
		cin >> player;
		
		if (player > 0)
		{
			per = false;
		}
		else if((player >= 'a' && player <= 'z') || (player >= 'A' && player <= 'Z'))
		{
			per = true;
		}

	}
		
		if (player == 1)
		{
			bool ai = true;
			int i = 0;
			Connect4 AI;
			person = new char[2];
			person[0] = 'X';
			person[1] = 'O';
			while (ai)
			{
				do
				{
					AI.DrawBoard();
					cout << "It's is  " << person[i] << " s Turn: \n";
					if (i == 1)
					{
						colums = AI.GetAIMove();
					}
					else
					{
						cout << "Cose a number between 0 - 6\n";
						cout << "colum: ";
						cin >> colums;
					}
				} while (!AI.MakeMove(person[i], colums));
				if (AI.GameOver())
				{
					ai = false;
					break;
				}
				else if (person[i] == 'X')
				{
					++i;
				}
				else
				{
					--i;
				}
			}
			AI.DrawBoard();
			cout << "The winner is " << AI.Winner();

		}
		else if (player == 2)
		{
			bool stand = true;
			int i = 0;
			Connect4 standard;
			person = new char[player];
			person[0] = 'X';
			person[1] = 'O';

			while (stand)
			{

				do
				{
					standard.DrawBoard();
					cout << "It's is  " << person[i] << " s Turn: \n";
					cout << "Cose a number between 0 - 6\n";
					cout << "Column: ";
					cin >> colums;
				} while (!standard.MakeMove(person[i], colums));
				if (standard.GameOver())
				{
					stand = false;
					break;
				}
				else if (person[i] == 'X')
				{
					++i;
				}
				else
				{
					--i;
				}
			}
			standard.DrawBoard();
			cout << "The winner is " << standard.Winner();
		
		}
		if (player >= 3)
		{
			int x;
			int y;
			bool more = true;
			char letter;
			int i = 0;
			person = new char[player];
			cout << "please input x: the number of rows\n";
			cin >> x;
			cout << "please input y: the number of colums\n";
			cin >> y;
			Connect4 ultconnect4(x,y);
			for (int i = 0; i < player; ++i)
			{
				cout << i + 1 << " What charater you want to be\n";
				cin >> letter;
				person[i] = letter;
			}
			while (more)
			{
				do
				{
					ultconnect4.DrawBoard();
					cout << "It's is  " << person[i] << " s Turn: \n";
					cout << "Cose a number between 0 - " << y - 1 << endl;
					cout << "Column: ";
					cin >> colums;
				} while (!ultconnect4.MakeMove(person[i], colums));
				if (ultconnect4.GameOver())
				{
					more = false;
					break;
				}
				else
				{
					++i;
					i = i % player;
				}
			
			}
			ultconnect4.DrawBoard();
			cout << "The winner is " << ultconnect4.Winner();

			
		}
}

	
	
