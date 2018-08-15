#include <iostream>
 
using namespace std;
 
int main()
{
    int number, mas[35], r, l, time;
    cin >> number;
    for (int i = 0; i < number; i++) cin >> mas[i];
    r = number-1;
    l = 0;
    while (r >= l) {
        time = mas[r];
        mas[r] = mas[l];
        mas[l] = time;
        l++;
        r--;
    }
    for (int i = 0; i != number; i++) cout << mas[i] << " ";
    system("pause");
    return 0;
}
