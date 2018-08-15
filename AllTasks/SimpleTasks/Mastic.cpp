#include <iostream>

using namespace std;

int a, b, c, s, e, j, N, counter = 0;

void second(int x)
{
	for (s = 0; s <= (N / a); s++)
		for (e = 0; e <= (N / b); e++)
			for (j = 0; j <= (N / c); j++)
			{
				if (((s*a) + (e*b) + (j*c)) == N)
				{
					if (x == 1) counter++;
					if (x==2) cout << s << " " << e << " " << j << endl;
				}
			}
}

int main()
{
	cin >> a >> b >> c >> N;
	second(1);
	cout << counter << endl;
	second(2);
	system("pause");
    return 0;
}
