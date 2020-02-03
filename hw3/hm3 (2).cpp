////////////////////////////////////////////////////////////////
// Joaquin Garcia
// date 1/30/2019
// hm3
// This function allowes you to roll as many dive you want with 
// how ever many attemps you want and give you a possibility
// of reciving a random roll
///////////////////////////////////////////////////////////////



#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

// this two prototipes that are used to get random number 
// and it also gives me the possibilitie rate of getting a roll
int random();
double divide(int * Rolled, int attemps, int j);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	// This are all the variables i use to keep clean and set things
	int min = 0;
	int max = 0;
	int dice = 0;
	int attemps = 0;
	
	// Im telling the user to input how many dice and attemps they want to do 
	cout << " how many dice do you want to use \n";
	cin >> dice;
	cout << "How many times do you want to throw a pair of six-sided dice? \n";
	cin >> attemps;

	// know im setting the information to min 
	// and max to have something set for later
	min = dice;
	max = dice * 6 + 1;

	// I created a new array using dinamic array 
	int * Rolled;
	Rolled = new int[max];

	// This for loop set every index to 0 
	// for it dosen't give me trash later;
	for (int c = 0; c < max; ++c)
	{
		Rolled[c] = 0;
	}
	// This for loop uses function called random to get random number
	// then strat andding it to a new barible that sets a counter on 
	// the index that you from adding all number together
	for (int i = 0; i < attemps; ++i)
	{
		int got = 0;
		for (int t = 0; t < min; ++t)
		{
			got = got + random();
		}
		Rolled[got]++;
	}
	// This is deisplaying the result of the probobility of getting the number
	// it does that by calling function divid to get me the persantage as a double 
	// and use it to display every single possible roll
	for (int j = min; j < max; ++j)
	{
		double rate = divide(Rolled, attemps, j);
		cout << setprecision(2);
		cout << setw(1) << j << "." << setw(10)<< rate << endl;
	}
}

// random is just getting a number between 1 - 6 and return it 
int random()
{
	return rand() % 6 + 1;
}
// THis function turn rolled to a double then devides it by attemps
// and gives you a persentage an returns it back to main.
double divide(int * Rolled, int attemps, int j)
{
	double rate = static_cast<double>(Rolled[j]) / attemps;
	return rate;
}