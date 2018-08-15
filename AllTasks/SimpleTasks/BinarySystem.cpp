#include <iostream>
 
using namespace std;
 
int main()
{
    int b = 0, counter = 0, a, c;
    int numb[100];
    cin >> a;
    while ((a != 0))
    {
        c = a; //c - делимое
        a = a / -2; //a - частное
        if (c == -1) a = 1; //исключение, когда -1/-2 = 0. Должно быть 1
        if ((c - (-2 * a)) == -1)
        {
            a++;
            b = c - (-2 * a);
        }
        else b = c - (-2 * a);
        numb[counter] = b;
        counter++;
    }
    for (int i = counter - 1; i != -1; i--) cout << numb[i];
    if (counter == 0) cout << 0;
    system("pause");
    return 0;
}
