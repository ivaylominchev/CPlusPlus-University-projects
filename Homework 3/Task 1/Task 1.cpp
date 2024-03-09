#include <iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    string task1 = "d:\\HW\\task1.txt";
    fstream f1;
    f1.open(task1, ios::in);
    if (!f1.is_open())
    {
        cout << "Error to open file\n";
        return -1;
    }
    string word, name, rezult;
    while (!f1.eof())
    {
        getline(f1, word);
        rezult += word + " ";
    }
    f1.close();
    if (!rezult.empty())
    {
        rezult.erase(rezult.size() - 1);
        rezult += ".";
    }
    cout << rezult << endl;
}
