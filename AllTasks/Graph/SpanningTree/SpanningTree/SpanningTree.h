#include <vector>
#include <iostream>

class SpanningTree
{
private:
	struct vertex //����� �����
	{
		int i, j;
	};

	int vertAmount; //���������� ����� � �����
	std::vector <int> knotColor; //���� ������ ������� �����
	std::vector <vertex> route; //������ ��������� ����� �����
	std::vector <std::vector <int>> graphMatrix; //������� �����

	//���������� ��� ������� �����
	void paintKnots()
	{
		for (int i = 0; i < graphMatrix.size(); i++) knotColor.push_back(i);
	}

	//������� ������ � ���������� ������� �����
	std::vector <vertex> getVertexs()
	{
		int min, jMin, iMin, col_j;
		std::vector <vertex> choosed;
		for (int k = 0; k < vertAmount - 1; k++)
		{
			min = 300;
			for (int i = 0; i < graphMatrix.size() - 1; i++)
				for (int j = i + 1; j < graphMatrix.size(); j++)
					if (knotColor[i] != knotColor[j] && graphMatrix[i][j] < min && graphMatrix[i][j] > 0) // ���� ����� �������� �����, �� ���������� �����
					{
						min = graphMatrix[i][j];
						iMin = i;
						jMin = j;
					}
			if (k!=0 && choosed[k-1].i == iMin && choosed[k-1].j) break;
			choosed.push_back({ iMin, jMin });
			col_j = knotColor[jMin];
			for (int i = 0; i < graphMatrix.size(); i++) // ����������� ��� �������, ���� ������� ������ � ������ ������� jMin
				if (knotColor[i] == col_j) knotColor[i] = knotColor[iMin];
		}
		return choosed;
	}

public:
	SpanningTree(std::vector <std::vector <int>> matrix)
	{
		graphMatrix = matrix;
		for (int i = 0; i < graphMatrix.size() - 1; i++)
			for (int j = i + 1; j < graphMatrix.size(); j++)
				if (graphMatrix[i][j]>0) vertAmount++;
	}

	int GetWeight()
	{
		paintKnots();
		route = getVertexs();
		int result = 0;
		for (int i = 0; i < route.size(); i++)
		{
			result += graphMatrix[route[i].i][route[i].j];
		}
		return result;
	}
};