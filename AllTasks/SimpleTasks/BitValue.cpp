#include <iostream>
 
int main()
{
    int num1;
    unsigned int num2;
    std::cin >> num1 >> num2;
    num1 = num1 >> num2;
    std::cout << (num1 & 1);
    system("pause");
    return 0;
}
