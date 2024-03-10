#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	int number;
	while (true)
	{
		cin >> number;
		if (number == 0)
		{
			break;
		}
		vec.push_back(number);
	}

	for (vector<int>::iterator p = vec.begin(); p != vec.end() - 1; p++)
	{
		if (*p == *(p + 1))
		{
			cout << *p << " ";
		}
	}
}