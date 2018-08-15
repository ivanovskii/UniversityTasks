#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int first, second, numb, firstnumeral, time, counter;
	counter = 0;
	cin >> first >> second;
	for (int i = first; i <= second; i++)
	{
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0) break;
			else if (j + 1 > sqrt(i))
			{
				numb = i % 10;
				time = i;
				while (time > 9) {
					time = time / 10;
					firstnumeral = time;
				}
				if ((firstnumeral == numb) && ((i % 10) == numb))
				{
					counter++;
					cout << i << " ";
				}
				if (counter == 0) cout << 0;
			}
		}
	}
	system("pause");
	return 0;
}