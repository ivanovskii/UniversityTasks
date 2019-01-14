#include <iostream>
#include <string>
#include <vector>
#include <cmath>

const int q = 9973; // Некоторое простое число
const int x = rand() % q; // Любое другое число от 0 до q-1

size_t Hash(const std::string& str)
{
  uint64_t hash = 0;
  for (size_t i = 0; i < str.size(); ++i) 
    hash += (int)str[i] * pow(x, str.size() - i - 1);
  return hash % q;
}

std::vector<int> RK(const std::string& text, const std::string& pattern)
{
  std::vector<int> res;
  size_t p_len = pattern.size();
  size_t hashT = Hash(text.substr(0, p_len));
  size_t hashP = Hash(pattern.substr(0, p_len));
  for (int i = 0; i <= text.size() - p_len; ++i)
  {
    if (hashT == hashP)
      res.push_back(i);
    hashT = Hash(text.substr(i + 1, p_len));
  }
  return res;
}

int main()
{
  auto occur = RK("abracadabra", "ra");
  for (const auto& elem : occur)
    std::cout << elem << " ";
  system("pause");
}
