#include "Header.h"

int main()
{
	
	wordchecker words;
	ifstream part2;
	ofstream OFile2;

	part2.open("whale.txt");
	if (!part2)
	{
			cout << "file not open part 2" << endl;
			return-1;
	}
	while (!part2.eof())
	{
		string w;
		part2 >> w;
		words.insert(w);
	}
	
	words.search();

	OFile2.open("wordCount.txt");
	while (!OFile2)
	{
		cout << "part outfile" << endl;
		return -1;
	}

	words.display(OFile2);

	system("pause");
	return 0;

}