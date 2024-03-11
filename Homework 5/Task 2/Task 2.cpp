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

	vector<pair<string, double>>helpVector;
	string name;
	int quantity;
	double price;

	while (f1 >> name >> quantity >> price)
	{
		double stoinost = quantity * price;
		size_t pos = 0;
		while (pos < helpVector.size() && name != helpVector[pos].first)
		{
			pos++;
		}
		if (pos == helpVector.size() || name != helpVector[pos].first)
		{
			helpVector.insert(helpVector.begin() + pos, make_pair(name, stoinost));
		}
		else
		{
			helpVector[pos].second += stoinost;
		}
	}

	for (size_t i = 0; i < helpVector.size() - 1; ++i)
	{
		for (size_t j = 0; j < helpVector.size() - i - 1; ++j)
		{
			if (helpVector[j].second < helpVector[j + 1].second)
			{
				swap(helpVector[j], helpVector[j + 1]);
			}
		}
	}

	f1.close();

	f2.open("d:\\HW\\rezult.txt", ios::out);
	for (int i = 0; i < helpVector.size(); i++)
	{
		f2 << helpVector[i].first << "\t" << helpVector[i].second << endl;
	}
	f2.close();
}