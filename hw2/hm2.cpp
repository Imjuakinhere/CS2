#include <iostream>;


using namespace std;

int enigma(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else
	{
		int x = enigma(a, b / 2);
		if (b % 2 == 0)
		{
			return x * x;
		}
		else
		{
			return x * x*a;
		}
	}
}



int main()
{
	
		cout << enigma(5,3);

}