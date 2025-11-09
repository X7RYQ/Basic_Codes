// Exercise 1: Symmetric String
//  Project created on 04/11/2025

#include <iostream>
using namespace std;
int main()
{
    int size = 0, c, i;
    std::string str[size], rev[size];
    char a;
    cout << "Enter a string with no numbers and no more than 100 symbols: " << endl;
    cin >> a;
    while (a != '.')
    {
        if (a >= '1' && a <= '9')
        {
            cout << "String contains numbers" << endl;
            cin >> a;
        }
        else if (size > 100)
        {
            break;
        }
        else
        {
            str[size] += a;
            size++;
            cin >> a;
        }
    }
    c = size - i - 1;
    for (i = 0; i < size; i++)
    {
        rev[c] = str[i];
    }
    if (str == rev)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
