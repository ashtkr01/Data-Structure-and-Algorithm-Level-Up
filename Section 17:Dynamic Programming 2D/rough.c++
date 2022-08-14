#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string str = "Shivaji";
    str.erase(2, 1);
    cout << str << endl;
    char d = 'i';
    str.insert(2, 1, d);
    cout << str << endl;
    str[2] = 'e';
    cout << str << endl;
    str[2] = 'i';
    cout << str << endl;
    return 0;
}
