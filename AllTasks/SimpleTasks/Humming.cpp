#include <iostream>
 
using namespace std;
 
int main()
{
    int xa, ya, xb, yb, xc, yc, s;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    s = (xb - xa) * (yc - ya) - (yb - ya) * (xc - xa);
    if (s < 0) cout << "RIGHT";
    else if (s > 0) cout << "LEFT";
    else cout << "BOTH";
    system("pause");
    return 0;
}
