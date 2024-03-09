#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


int main()
{
    string words;
    getline(cin, words);
    string filename = "d:\\HW\\task22.txt";
    fstream f1;
    f1.open(filename, ios::out);

    if (!f1.is_open())
    {
        cout << "Error to open file!" << endl;
        return -1;
    }

    istringstream iss(words);
    string word, line;
    size_t br = 0;

    while (iss >> word)
    {
        line += word + " ";
        br++;

        if (br == 3)
        {
            f1 << line << endl;
            line = "";
            br = 0;
        }
    }

    if (br > 0)
    {
        f1 << line << endl;
    }

    f1.close();
    return 0;
}