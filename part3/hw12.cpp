#include "classfunction.h"

int main()
{
	wordchecker part3;
	ifstream infile;
	ofstream outfile;
	string w;
	infile.open("whale.txt");
	while (!infile)
	{
		cout << "whale file not open" << endl;
	return -1;
	}
	while (!infile.eof())
	{
		infile >> w;
		part3.insert(w);
	}

	part3.search();
	part3.fake();

	outfile.open("topMistakes.txt");
	while (!outfile)
	{ 
		cout << "outfile file not open" << endl;
		return -1;
	}
 	part3.display(outfile);

	infile.close();
	outfile.close();
	system("pause");
	return 0;
}