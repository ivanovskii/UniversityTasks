    #include <iostream>
     
    using namespace std;
     
    int main ()
    {
        int a,b,counter=0;
        cin >> a >> b;
        while ((a!=0) && (b!=0))
        {
            counter++;
            if (a>b) a = a%b;
            else b = b%a;
        }
        if (a!=0) cout << a << " " << counter;
        else cout << b << " " << counter;
        system("pause");
        return 0;
    }
