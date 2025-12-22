#include <iostream>
#include <cstring>
using namespace std;
void trimLeadingDigits(char *str)
{
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    int j = 0;
    while (str[i])
    {
        str[j++] = str[i++];
    }
    str[j] = '\0';
}
int main()
{
    char a[100];
    cout << "Enter a string: ";
    cin >> a;
    trimLeadingDigits(a);
    cout << "String after trimming leading digits: " << a << endl;
    return 0;
}
