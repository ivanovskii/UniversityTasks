#include <iostream>
#include <string>
#include <thread>
#include <vector>

void CaesarEncrypt(std::string* s) {
  std::vector<std::thread> threads;
  auto num_threads = std::thread::hardware_concurrency();
  size_t shift = (*s).size() / num_threads;
  auto it = (*s).begin();

  auto EncryptStr = [](std::string::iterator it,
                       const std::string::iterator& last) {
    while (it < last) {
      if (*it >= 'a' && *it <= 'z') {
        *it += (3 % 26);
        if (*it > 'z') *it -= 26;
      }
    it++;
    }
  };

  for (size_t i = 0; i < num_threads - 1; ++i) {
    const auto last = it + shift;
    threads.emplace_back(EncryptStr, it, last);
    it = last;
  }

  if (it != (*s).end()) EncryptStr(it, (*s).end());

  for (auto& thr : threads) {
    thr.join();
  }
}

int main() {
  std::string str = "abcdef";
  CaesarEncrypt(&str);
  std::cout << str;
  system("pause");
}
