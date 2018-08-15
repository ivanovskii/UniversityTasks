#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector <std::vector <int>> g(n, std::vector <int>(n)), res(n, std::vector <int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cin >> g[i][j];
			res[i][j] = g[i][j];
		}

	for (int m = 0; m < n; m++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					res[i][j] |= res[i][k] & g[k][j];

	for (int i = 0; i < n; i++)
	{
		if (res[i][i] != 0)
		{
			std::cout << 1;
			return 0;
		}
	}
	std::cout << 0;
}
