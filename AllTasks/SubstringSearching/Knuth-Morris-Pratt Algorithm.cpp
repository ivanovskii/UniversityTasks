#include <iostream>
#include <string>
#include <vector>

// Префикс функция от строки - длина наибольшего префикса строки,
// который одновременно является её суффиксом
std::vector<size_t> prefixFunction(const std::string& s)
{
	std::vector<size_t> pi(s.size()); // значения префикс-функции
	pi[0] = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		int k = pi[i - 1];  // k - длина текущего рассматриваемого образца
		while ((k > 0) && (s[k] != s[i])) // Символы не равны
			k = pi[k - 1]; // берем ранее рассчитанное значение (начиная с максимально возможных)
		if (s[k] == s[i])
			++k;
		pi[i] = k;
	}
	return pi;
}

std::vector<size_t> kmp(const std::string& text, const std::string& pattern)
{
	std::vector<size_t> result, pi = prefixFunction(pattern + '\0' + text);
	for (size_t i = 0; i < text.size(); ++i)
		if (pi[pattern.size() + i + 1] == pattern.size())
			result.push_back(i + 1 - pattern.size());
	return result;
}

int main() {
	auto pi = kmp("abracadabra", "r");
	for (const auto& elem : pi)
		std::cout << elem << " ";
	std::cout << "\n";
	system("pause");
}
