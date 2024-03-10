#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	fstream fp;
	fp.open("d:\\domashno\\homework.txt", ios::in);
	if (!fp.is_open())
	{
		cout << "Error to open file\n";

		return -1;
	}

	vector<string> dumi;
	string word;
	while (!fp.eof())
	{
		getline(fp, word);
		dumi.push_back(word);
	}
	fp.close();

	fstream fp2;
	fp2.open("d:\\domashno\\rezultati.txt", ios::out);

	sort(dumi.begin(), dumi.end());

	for (size_t i = 0; i < dumi.size(); i++)
	{
		fp2 << dumi[i] << endl;
	}
	fp2.close();
}