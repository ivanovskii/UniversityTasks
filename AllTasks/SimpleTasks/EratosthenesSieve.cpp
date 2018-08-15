    #include <iostream>
    #include <math.h>
     
    using namespace std;
     
    int main()
    {
        int n;
        cin >> n;
        cout << 2 << " " << 3 << " ";;
        for (int i = 2; i<=n; i++)
            for (int j = 2; j*j <= i; j++)
            {
                if (i % j == 0)
                {
                    break;
                }
                else if (j + 1 > sqrt(i))
                {
                    cout << i << " ";
                }
            }
        system("pause");
        return 0;
    }
