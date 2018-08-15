#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1000000;

void input(std::vector <std::vector <int>> &matrix, int m)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++) matrix[i][j] = INF;
		matrix[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int first, second, weight;
		std::cin >> first >> second >> weight;
		first--; 
		second--;
		matrix[first][second] = weight;
		matrix[second][first] = weight;
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector <std::vector <int>> g(n, std::vector <int>(n));

	input(g, m);

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (g[i][j] != INF)
				result = std::max(result, g[i][j]);
	}

	if (result != INF) std::cout << result;
	else std::cout << 0;
}
