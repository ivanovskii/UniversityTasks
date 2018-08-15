#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string str;
    int counter = 0;
    getline(cin, str);
    for (int i = 0; i != str.length(); i++) {
        if (str[i] == ',' || str[i] == '!' || str[i] == ';' || str[i] == ':' || str[i] == '?' || str[i] == '.') counter++;
    }
    cout << counter;
    system("pause");
    return 0;
}
