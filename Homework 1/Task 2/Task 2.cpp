#include <iostream>
#include <string>
using namespace std;

int main()
{
    string url;
    cin >> url;

    string protocol = url.substr(0, url.find("://"));
    url.erase(0, url.find_first_of("/") + 2);
    string host = url.substr(0, url.find_first_of("/"));
    url.erase(0, url.find_first_of("/") + 1);
    string path = url.substr(0, url.find_last_of("/"));
    string file = url.substr(url.find_last_of("/") + 1);

    cout << "Protocol: " << protocol << endl;
    cout << "Host: " << host << endl;
    cout << "Path: " << path << endl;
    cout << "File: " << file << endl;

}