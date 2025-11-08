#include <iostream>
int main()
{
    int n, n1, c;
    std::cout << "Enter a series of integers and end it with 0" << std::endl;
    std::cin >> n;
    n1 = n;
    while (n != 0)
    {
        if (n >= n1)
        {
            c = 1;
            n1 = n;
            std::cin >> n;
        }
        else
        {
            c = 0;
            std::cin >> n;
        }
    }
    if (c == 1)
    {
        std::cout << "answer is YES";
    }
    else
    {
        std::cout << "answer is NO";
    }
    return 0;
}
