#include <iostream>
#include <vector>

std::vector<size_t> naiveStringMatcher(const std::string& haystack,
                                       const std::string& needle)
{
  std::vector<size_t> res;
  for (size_t i = 0; i <= haystack.size() - needle.size(); ++i)
  {
      bool success = true;
      for (size_t j = 0; j < needle.size(); ++j)
      {
          if (needle[j] != haystack[i + j])
          {
            success = false;
            break;
          }
          if (success) 
          {
            res.push_back(i);
            break;
          }
        }
    }
  return res;
}

int main() 
{
  auto matches = naiveStringMatcher("abracadabr", "r");
  for (const auto& elem : matches)
    std::cout << elem << " ";
  system("pause");
}
