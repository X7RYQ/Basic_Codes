#include <iostream>
using namespace std;
int main()
{
    double n, num;
    int c = 0, a = -1;
    cout << "Enter a decimal number: " << endl;
    cin >> n;
    while (a != 0)
    {
        n = n * 10;
        c++;
        num = n % 10;
        if (num != 0)
        {
            a = 0;
            cout << "Answer is " << c << endl;
            break;
        }
    }
    return 0;
}
