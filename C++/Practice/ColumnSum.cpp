#include <iostream>
using namespace std;
int main()
{
    int row, col, sum = 0, max = 0, count = 0;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    int a[row][col];
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < col; j++)
    {
        sum = 0;
        for (int i = 0; i < row; i++)
            sum += a[i][j];
        if (j == 0 || sum > max)
        {
            max = sum;
            count = j;
        }
    }
    cout << "Max sum is in column: " << count;
    return 0;
}
