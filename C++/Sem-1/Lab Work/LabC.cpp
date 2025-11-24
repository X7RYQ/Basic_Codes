// C36, Given natural number n and sequence of natural numbers a(1), a(2), ... a(n) ( n<100) . Convert all numbers to reverse order of digits. Example: 234 convert to 432, 100 convert to 1, ...). Create and use function to convert one number. Splitting into digits should be carried out numerically.
// Program created on: 24/11/2025

#include <iostream>
using namespace std;

int reverseNumber(int x)
{
    int invNum = 0; // Reset inverted number for each element
    while (x != 0)
    {
        if ((x % 10) == 0)
        {
            invNum = invNum; // Skips Zeroes
        }
        else
        {
            invNum += x % 10; // Build the inverted number
        }
        x /= 10;      // Remove the last digit
        invNum *= 10; // Shift left for next digit
    }
    return invNum / 10; // Update the array with the inverted number
}
int main()
{
    int ok;
    do
    {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        if (n <= 0 || n >= 100)
        {
            cout << "Array size should be between 1 and 99." << endl;
            break;
        }
        else
        {
            int a[n];
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; i++)
            {
                cin >> a[i]; // Input array elements
            }
            for (int i = 0; i < n; i++)
            {
                a[i] = reverseNumber(a[i]); // Reverse each number in the array
            }
            for (int i = 0; i < n; i++)
            {
                cout << "a(" << i + 1 << ") = " << a[i]; // Print the modified array
                if (i == n - 1)
                {
                    cout << " "; // Adds space after the last element
                }
                else
                {
                    cout << ", "; // Adds comma and space between elements
                }
            }
        }
        cout << endl;
        cout << "If you would like to continue, enter 1 and to exit, enter any other number." << endl;
        cin >> ok; // Input to continue or exit the program
    } while (ok == 1);
    return 0;
}
