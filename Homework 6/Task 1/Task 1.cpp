#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<locale>
using namespace std;
class Magazinche
{
public:
	Magazinche(string i, double c)
	{
		ime = i;
		setCena(c);
	}
	~Magazinche();
	string ime;
	void setCena(double c)
	{
		cena = c;
	}
	double Cena()
	{
		return cena;
	}
	void View()
	{
		cout << ime << "\t" << cena << "ыт." << endl;
	}


private:
	double cena;
};

Magazinche::~Magazinche()
{
}
int main()
{
	setlocale(LC_ALL, "Bulgarian");
	vector<Magazinche*>stoki;
	while (true)
	{
		string ime;
		double cena;
		cout << "Name:";
		getline(cin, ime);
		if (ime == "")
		{
			break;
		}
		cout << "Cena:";
		cin >> cena;
		cin.ignore('\n', 10);
		stoki.push_back(new Magazinche(ime, cena));
	}
	for (vector<Magazinche*>::iterator p = stoki.begin(); p != stoki.end(); p++)
	{
		(*p)->View();
	}
	fstream file1;
	file1.open("d:\\HW\\STOKI.txt", ios::out);
	for (int i = 0; i < stoki.size(); i++)
	{
		file1 << stoki[i]->ime << "\t" << stoki[i]->Cena() << "ыт." << endl;
	}
	file1.close();
}