/*Вход: Knyaz Boris 3, number 77, room 51, fn.103567
Изход: Knyaz Boris , number *, room *, fn.
*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
    string text;
    size_t start, br = 0;
    getline(cin, text);
    string mask = "0123456789";
    while ((start = text.find_first_of(mask)) != string::npos)
    {
        br = text.find_first_not_of(mask, start + 1);
        text.replace(start, br - start, "*");
        start = text.find_first_of(mask, start + 1);

    }
    cout << text << endl;
}
