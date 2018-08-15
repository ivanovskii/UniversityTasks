#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{  
    int a, c, K;
    string s;
    cin >> s;
    cin >> K;
    for (int i = 0; i <= s.length(); i++)
    {
        a = ((int)s[i] - K);
        if (a < 65) a = a + 26;
        s[i] = (char) a;
    }
    cout << s;
    system("pause");
    return 0;
}
