#include <iostream>
#include <vector>
#include <algorithm>

void Swap(std::vector <int> &arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

bool NextSet(std::vector <int> &arr)
{
	if (arr.size() == 1) return false;

	int i = arr.size() - 2;
	while (i != -1 && arr[i] > arr[i + 1]) i--; //просматриваем массив от конца к началу, находим элемент, который меньше предыдущего
	if (i == -1) return false;

	int idx = -1;
	for (int j = i + 1; j < arr.size(); j++)
		if ((idx == -1 || arr[idx] > arr[j]) && arr[j] > arr[i]) idx = j;
	Swap(arr, idx, i);
	std::sort(std::find(arr.begin(), arr.end(), arr[i + 1]), arr.end());
	return true;
}

void Print(std::vector <int> &arr)
{
	for (int i = 0; i < arr.size(); i++) std::cout << arr[i];
	std::cout << std::endl;
}

int main()
{
	int size;
	std::cin >> size;
	std::vector <int> arr;
	for (int i = 1; i <= size; i++) arr.push_back(i);
	Print(arr);
	while (NextSet(arr)) Print(arr);
	system("pause");
}

/*
Алгоритм:
1) Просмотреть текущую перестановку справа налево и следить за тем, чтобы
   каждый следующий элемент перестановки был не более чем предыдущий.
   Как только данное соотношение будет нарушено необходимо остановиться
   и отметить текущее число (позиция 1).
2) Снова просмотреть пройденный путь справа налево пока не дойдем до первого числа,
   которое больше чем отмеченное на предыдущем шаге.
3) Поменять местами два полученных элемента.
4) Теперь в части массива, которая размещена справа от позиции 1 надо отсортировать все
   числа в порядке возрастания. Поскольку до этого они все были уже записаны в порядке
   убывания необходимо эту часть подпоследовательность просто перевернуть.

Таким образом мы получим новую последовательность, которая будет рассматриваться в качестве исходной на следующем шаге.
*/
