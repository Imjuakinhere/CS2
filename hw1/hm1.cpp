//////////////////////////////////////////
// joaquin Garcia
// date 1/23/2019
// class 2380
// homework 1:
// This is the guessing game with a top ten list 
//////////////////////////////////////////



#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;
const int SIZE = 10;
//created a struct thst contain both string that 
//allowed to inout fisrt and last name
struct Topten
{
	string first;
	string last;
};

int RGenerator();
// part one function 
// This creates the guessing game
void gamestart(int RN, int & score);
void Ratescore(int score);
void Ggame(string & Pfirst, string & Plast, int & score);
//part two functions
//This sorts the leaderboard when you finish playing the game 
void Toplist( string Pfirst, string Plast, Topten player[], int score, int Tscore[]);





int main()
{	
	// so Im using infile and out file to open the same file to 
	// get the information and save the new list when the game is over

	ifstream infile;
	ofstream outfile;
	infile.open("Topten.txt");
	if (!infile)
	{
		cout << "not working";

		system ("pause");
	}

	//This is all the variables im using which is 
	//the struct and the array for the score 
	//also using two strings for the full name and int for the score

	Topten player[SIZE];
	int Tscore[SIZE];
	string Pfirst;
	string Plast;
	int score = 0;

	// This part is to get the inforemation from the file 
	// and inputing them in a array 

	int count = 0;
	while (!infile.eof())
	{
		infile >> player[count].first;
		infile >> player[count].last;
		infile >> Tscore[count];
		++count;
	}

	// Ones i got the array know im displaying
	// it to the user can see the leader board
	cout << "Wellcom to the number huessing game.This are the top 10 leaderboard.\n";

	for (int i = 0; i < SIZE; ++i)
	{
		cout << player[i].first << " ";
		cout << player[i].last << " ";
		cout << Tscore[i] << "\n";
	}

	// Part one creating the game
	cout << "Think you've got what it takes to make the top ten? Lets find out\n";

	// inside this one function contains everything that involves 
	// the guessing game it self to keep main more clean 
	Ggame(Pfirst, Plast, score);
	
	// Toplist is the second part of the homework 
	// which it checks if you beat someone score 
	// and sorts the list with your score
	Toplist( Pfirst, Plast, player, score, Tscore);

	// knowi open the outfile to save the new leaderboard 
	outfile.open("Topten.txt");
	if (!outfile)
	{
		cout << "not working";

		system("pause");
	}
	for (int i = 0; i < SIZE; ++i)
	{
		outfile << player[i].first << " ";
		outfile << player[i].last << " ";
		outfile << Tscore[i] << "\n";
	}
	infile.close();
	outfile.close();


	system("Pause");
}
// This function creates a random number 
// that returns the number as and int
int RGenerator()
{
	srand(static_cast<unsigned int>(time(0)));
	return rand() % 100 + 1;
}
// This is were the game uses the random number 
// that we got and try to guess the number and 
// it keeps track of your score 
void gamestart(int RN, int & score)
{
	int num;
	bool GameOver = true;
	while (GameOver)
	{
		cout << "Please enter your guess number between 0-100\n";
		cin >> num;
		cout << endl;
		++score;
		if (!cin)
		{
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "Yout inputed something that is outside of 1 - 100\n";

		}
		else if (num < 1 || num > 100)
		{
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "Yout inputed something that is outside of 1 - 100\n\n";

		}
		else if (num < RN)
		{
			cout << "Sorry you guess is to low try again\n\n";
		}
		else if (num > RN)
		{
			cout << "Sorry you guess is to high try again\n\n";
		}

		else
		{
			cout << "you are victories\n\n";
			GameOver = false;
		}
	}
}
// This just tell the player how they did by  
// giving him comment depending on the score you got 
void Ratescore(int score)
{
	if (score >= 11)
	{
		cout << "Please stop playing the game\n";
	}
	else if (score >= 9)
	{
		cout << "Go home and get better\n";
	}
	else if (score >= 7)
	{
		cout << "Pretty good but still need more work to do\n";
	}
	else if (score >= 5)
	{
		cout << "I think you maid it on the LIST!!! \n";
	}
	else
	{
		cout << "YOU ARE A GOD \n";
	}
}

// This just contain 3 functions that do all the work 
void Ggame(string & Pfirst, string & Plast, int & score)
{
	cout << "Wellcom new player what is you name\n";
	cin >> Pfirst;
	cin >> Plast;

	int RN = RGenerator();

	gamestart(RN, score);

	cout << "It took you " << score << " guesses " << Pfirst << " " << Plast << endl;
	Ratescore(score);
}
// The toplist checks if you beat anyone in the list 
// and sorts the list with you in it 
// by swaping players and rearanging them in order
void Toplist( string Pfirst, string Plast, Topten player[], int score, int Tscore[])
{
	bool equal = false;
	if (score < Tscore[9])
	{
		cout << "congratualations you made it to the leaderboard\n";
	}
	for (int i = 0; i < SIZE; ++i)
	{
		string tempf;
		string templ;
		int temps;
		if (score < Tscore[i])
		{
			tempf = player[i].first;
			templ = player[i].last;
			temps = Tscore[i];
			player[i].first = Pfirst;
			player[i].last = Plast;
			Tscore[i] = score;
			Pfirst = tempf;
			Plast = templ;
			score = temps;
			equal = true;
		}
		while (equal)
		{
			if (score == Tscore[i])
			{
				tempf = player[i].first;
				templ = player[i].last;
				temps = Tscore[i];
				player[i].first = Pfirst;
				player[i].last = Plast;
				Tscore[i] = score;
				Pfirst = tempf;
				Plast = templ;
				score = temps;
			}
			else 
			{
				equal = false;
				break;
			}
		}
	}

	for (int x = 0; x < SIZE; ++x)
	{
		cout << player[x].first << " ";
		cout << player[x].last << " ";
		cout << Tscore[x] << "\n";

	}
}
