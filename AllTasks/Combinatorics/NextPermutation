#include <iostream>
#include <vector>
#include <algorithm>

void Swap(std::vector <int> &arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void NextPermut(std::vector <int> &arr)
{
	if (arr.size() == 1) return;
	int i = arr.size() - 2;
	while (arr[i] > arr[i + 1] && i > 0) i--; //Просматриваем массив от конца к началу, находим элемент, который меньше предыдущего

	int idx = -1;
	for (int j = i + 1; j < arr.size(); j++) 
		if ((idx == -1 || arr[idx] > arr[j]) && arr[j] > arr[i]) idx = j;

	Swap(arr, idx, i);

	std::sort(std::find(arr.begin(), arr.end(), arr[i+1]), arr.end());

}

int main()
{
	int size;
	std::cin >> size;
	std::vector <int> arr(size);
	for (int i = 0; i < size; i++) std::cin >> arr[i];
	NextPermut(arr);
	for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
 	system("pause");
}
