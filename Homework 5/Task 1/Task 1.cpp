#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<algorithm>
using  namespace std;
int main()
{
	setlocale(LC_ALL, "Bulgarian");
	fstream f1, f2;
	f1.open("d:\\HW\\products.txt", ios::in);
	if (!f1.is_open())
	{
		cout << "Error to open file\n";
		return -1;
	}
	vector<pair<string, double>>rezult;
	vector<pair<string, double>>helpVector;


	string name;
	int quantity;
	double price;

	while (!f1.eof())
	{
		f1 >> name >> quantity >> price;
		helpVector.push_back(make_pair(name, quantity * price));


	}

	/*for (vector<pair<string, double>>::iterator it = helpVector.begin(); it != helpVector.end(); it++)
	{
		  cout << it->first << "\t" << it->second << endl;
	}*/

	vector<pair<string, double>> sorted;
	for (int x = 0; x < helpVector.size(); x++)
	{
		int pos = 0;
		while (pos < sorted.size() && helpVector[x].second < sorted[pos].second)
		{
			pos++;
		}
		if (pos == sorted.size())
		{
			sorted.push_back(helpVector[x]);
		}
		else
		{
			sorted.insert(sorted.begin() + pos, helpVector[x]);
		}
	}
	cout << "Sorted:\n";

	for (int a = 0; a < sorted.size(); a++)
	{
		cout << sorted[a].first << "\t" << sorted[a].second << endl;
	}

	f1.close();
}