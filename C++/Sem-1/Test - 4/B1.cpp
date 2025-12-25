#include <iostream>
#include <string>
using namespace std;
bool trimming(string s, int j)
{
    int flag = false;
    if (s[j] >= '0' && s[j] <= '9')
    {
        flag = true;
    }
    return flag;
}
int main()
{
    string str;
    int count = 0;
    cout << "Enter a string: ";
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (trimming(str, i))
        {
            count++;
            str = str.erase(i, 1);
        }
        else if (count == 2)
        {
            break;
        }
    }
    cout << str << endl;
}
