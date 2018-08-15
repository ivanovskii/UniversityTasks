#include "iostream"
 
int main()
{
    int num;
    std::cin >> num;
    for (int i = 7; i != -1; i--) std::cout << ((num >> i) & 1);
    system("pause");
    return 0;
}
