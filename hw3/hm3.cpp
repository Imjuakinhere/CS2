#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

int random();
double divide(int * Rolled, int attemps, int j);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int min = 0;
	int max = 0;
	int dice = 0;
	int attemps = 0;

	cout << " how many dice do you want to use \n";
	cin >> dice;
	cout << "How many times do you want to throw a pair of six-sided dice? \n";
	cin >> attemps;

	min = dice;
	max = dice * 6 + 1;

	int * Rolled;
	Rolled = new int[max];

	for (int c = 0; c < max; ++c)
	{
		Rolled[c] = 0;
	}
	for (int i = 0; i < attemps; ++i)
	{
		int got = 0;
		for (int t = 0; t < min; ++t)
		{
			got = got + random();
		}
		Rolled[got]++;
	}
	for (int j = min; j < max; ++j)
	{
		double rate = divide(Rolled, attemps, j);
		cout << setprecision(2);
		cout << setw(1) << j << "." << setw(10)<< rate << endl;
	}
}

int random()
{
	return rand() % 6 + 1;
}
double divide(int * Rolled, int attemps, int j)
{
	double rate = static_cast<double>(Rolled[j]) / attemps;
	return rate;
}