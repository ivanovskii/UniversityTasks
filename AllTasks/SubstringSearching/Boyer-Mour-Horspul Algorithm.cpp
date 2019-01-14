#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <array>

std::vector <size_t> BMH(const std::string& text, const std::string& pattern) 
{
	std::array <unsigned int, 256> table;
	std::vector <size_t> occur;

	for (size_t i = 0; i < 256; ++i)
		table[i] = pattern.size();
	for (size_t i = 0; i < pattern.size() - 1; ++i)
		table[(int) pattern[i]] = pattern.size() - i - 1;

	int i = pattern.size() - 1;
	int j = i;
	int k = i;
	while (i < text.size())
	{
		j = pattern.size() - 1;
		k = i;
		while (j >= 0 && text[k] == pattern[j]) 
		{
			k--;
			j--;
		}
		i += table[(int) text[i]];
		if (j < 0)
			occur.push_back(k + 1);
	}
	return occur;
}

int main() 
{
	auto occur = BMH("abracadabra","ra");
	for (const auto& elem : occur)
		std::cout << elem << " ";
	system("pause");
}
