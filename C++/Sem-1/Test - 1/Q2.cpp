#include <iostream>
int main()
{
    int n;
    std::cout << "Enter the square size" << std::endl;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            std::cout << "X";
            if (i != 1 || i != n)
            {
                std::cout << " ";
                break;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
