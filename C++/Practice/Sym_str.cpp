// Project created on 04/11/2025

#include <iostream>
int main()
{
    int c = 0, n;
    std::cout << "Enter the length of the string: ";
    std::cin >> n;
    std::string str[n], rev[n];
    std::cout << "Enter a string: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> str[i];
    }
    for (int i = 0; i < n; i++)
    {
        rev[i] = str[n - i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == rev[i])
        {
            c++;
        }
        else
        {
            break;
        }
    }
    if (c == n)
    {
        std::cout << "The string is symmetric." << std::endl;
    }
    else
    {
        std::cout << "The string is not symmetric." << std::endl;
    }
    return 0;
}
