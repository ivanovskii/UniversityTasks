#include <iostream>
 
using namespace std;
 
int counter = 0, frst = 0, scnd = 0, mas[999], amount, les = 0;
 
int find() {
    int time = 0, identical = 0;
    for (int i = 0; i < amount; i++) {
        if (time != mas[i] && identical < 3) //Нахождение первого элемента в цепи
        {
            identical = 0;
            time = mas[i];
            frst = i;
        }
        else if (time != mas[i] && identical >= 3) //Нахождение второго элемента в цепи
        {
            scnd = i;
            break;
        }
        if (time == mas[i]) identical++;
        else identical = 1;
        if (identical == 3) counter += 3;
        else if (identical > 3) counter++;
    }
    les = identical;
    return counter, frst, scnd;
}
 
void del() {
    for (int k = frst; scnd < amount; k++) {
        mas[k] = mas[scnd];
        scnd++;
    }
    amount -= les;
}
 
int main () {
    int k = 0;
    cin >> amount;
    for (int i = 0; i < amount; i++) cin >> mas[i];
    while (true)
    {
        k = counter;
        find();
        del();
        if (k == counter) break;
    }
    cout << counter;
    system("pause");
    return 0;
}
