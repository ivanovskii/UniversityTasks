#include <vector>
#include <iostream>
#include <string>
#include <fstream>

std::ifstream fin("input.txt", std::ios_base::in);
std::ofstream fout("output.txt", std::ios_base::out);

void input(std::vector <std::vector<int>> &matrix)
{
	std::string *s = new std::string;
	std::getline(fin, *s);
	delete s;
	for (int i = 0; i < matrix.size(); i++)
	{
		std::string str;
		std::getline(fin, str);
		while (str.find(' ') != -1) str.erase(str.find(' '), 1); //Очищаем строку от пробелов
		for (int j = 0; j < str.size(); j++) if (str[j] != '0') matrix[i][j] = 1;
	}
}

void showMatrix(std::vector <std::vector<int>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++) fout << matrix[i][j] << " ";
		fout << std::endl;
	}
}

int main()
{

	int size;
	fin >> size;
	std::vector <std::vector<int>> matrix(size, std::vector <int> (size));
	input(matrix);

	for (int k = 0; k < matrix.size(); k++)
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix.size(); j++)
			{
				matrix[i][j] = matrix[i][j] | (matrix[i][k] & matrix[k][j]);
			}
	showMatrix(matrix);
	fin.close();
	fout.close();
}
