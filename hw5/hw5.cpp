#include <iostream>

using namespace std;

class Calculator
{
	private:
		double num;
		double numitems[90];
		int i = 0;

	public:
		Calculator operator+(const Calculator & x)
		{
			Calculator newcal;
			return newcal.num = num + x.num;
			 
		}
		Calculator()
		{
			num = 0;
		}
		Calculator(double x)
		{
			num = x;
		}
		void clear()
		{
			num = 0;
			numitems[i] = num;
			++i;

		}
		void add(double x)
		{
			num = num + x;
			numitems[i] = num;
			++i;
		}
		void subtract(double x)
		{
			num = num - x;
			numitems[i] = num;
			++i;
		}
		void multiply(double x)
		{
			num = num * x;
			numitems[i] = num;
			++i;
		}
		void divide(double x)
		{
			num = num / x;
			numitems[i] = num;
			++i;
		}
		double display()
		{
			
			return numitems[i - 1];
		}
		void undo()
		{
			--i;
		}
		void redo()
		{
			++i;
		}
};
int main()
{
	Calculator mycalc;
	mycalc.clear();
	mycalc.add(4.52);
	mycalc.add(3.789);
	mycalc.divide(2.6);
	mycalc.multiply(3.12);
	mycalc.subtract(2.678);
	cout << mycalc.display() << endl;       // prints out "7.2928"
	mycalc.clear();
	mycalc.add(5.0);
	cout << mycalc.display() << endl;       // prints out "5"

	//advanced stuff #1: add a constructor
	Calculator calc1;
	cout << calc1.display() << endl;  //prints out 0

	//advanced stuff #2: add a parameterized constructor
	Calculator calc2(5);
	cout << calc2.display() << endl; //prints out 5

	//advanced stuff #3: Define calculator addition (overload the '+' operator) 
	Calculator calc3(7);
	calc1 = calc2 + calc3;
	cout << calc1.display() << endl;  //prints out 12

	//advanced stuff #4 (10 points extra credit): Create an 'undo' method for the calculator
	mycalc.undo();
	mycalc.undo();
	cout << mycalc.display() << endl;  //prints out 7.2928

	//advanced stuff #5 (10 points extra credit): Create a 'redo' method for the calculator
	mycalc.redo();
	mycalc.redo();
	cout << mycalc.display() << endl;  //prints out 5

	system ("pause");

}