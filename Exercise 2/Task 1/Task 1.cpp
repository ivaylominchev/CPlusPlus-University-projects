/*
Вход: Knyaz Boris 3, number 77, room 51
Изход: number
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
    string text, word, neededWord;
    size_t maxLenght = 0, start, end = 0;
    string mask = " ,0123456789";
    getline(cin, text);
    while ((start = text.find_first_not_of(mask, end)) != string::npos)
    {
        end = text.find_first_of(mask, start);
        word = text.substr(start, end - start);
        if (word.length() >= maxLenght)
        {
            maxLenght = word.length();
            neededWord = word;
        }
    }
    cout << neededWord << endl;
}