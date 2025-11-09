// Program created on:

#include <iostream>
using namespace std;

int main()
{
    int ok;
    do
    {

        cout << "If you would like to continue, enter 1 and to exit, enter any other number." << endl;
        cin >> ok; // Input to continue or exit the program
    } while (ok == 1);
    return 0;
}
