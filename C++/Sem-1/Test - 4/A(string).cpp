#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int flag = 0;
    cout << "Enter a string: ";
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
        {
            flag = 1;
            break;
        }
    }
    cout << flag << endl;
}
