#include <iostream>
using namespace std;
int main()
{
    int n, a;
    cout << "Enter an integer: " << endl;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            a = j % i;
            if (a == 0)
            {
                cout << "(" << j << "," << i << ")" << endl;
                break;
            }
        }
    }
    return 0;
}
