#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Bulgarian");

    string email;
    cin >> email;

    string username = email.substr(0, email.find("@"));
    string mailServer = email.substr(email.find("@") + 1);

    cout << "����������: " << username << endl;
    cout << "������: " << mailServer << endl;

    if (email.rfind(".bg") == email.length() - 3)
    {
        cout << "������������: ���������" << endl;
    }
    else
    {
        cout << "������������: ����" << endl;
    }
}