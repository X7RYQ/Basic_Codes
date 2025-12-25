#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[100];
    int flag = 0;
    cout << "Enter a string: ";
    cin.getline(str, 100);
    for (int i = 0; i != '\n'; i++)
    {
        if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
        {
            flag = 1;
            break;
        }
    }
    cout << flag << endl;
}
