#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <functional>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>
#include "FixedAllocator.h"

struct Sample {
  int a, b;
};

int main() {
  {
    FixedAllocator f(sizeof(Sample), 4);
    for (int i = 0; i < 20; ++i) {
      auto ptr = static_cast<Sample*>(f.Allocate());
      Sample& s = *ptr;
      s.a = 1;
      s.b = 2;
    }
  }

  {
    FixedAllocator f(sizeof(int), 4);
    for (int i = 0; i < 5; ++i) {
      auto ptr = static_cast<int*>(f.Allocate());
      *ptr = 13;
    }
  }

  {
    FixedAllocator f(10, 4);
    for (int i = 0; i < 500; ++i) {
      auto ptr = static_cast<char*>(f.Allocate());
      memcpy(ptr, "aaaaaaaaaa", 10);
    }
  }

  {
    size_t page_size = 4;
    FixedAllocator f(sizeof(int), page_size);
    int* ptr;
    for (int i = 0; i < page_size; ++i) {
      ptr = static_cast<int*>(f.Allocate());
      f.Deallocate(ptr);
      ptr = static_cast<int*>(f.Allocate());
    }
  }

  {
    size_t page_size = 4;
    FixedAllocator f(sizeof(int), page_size);
    std::vector<int*> ptrs(7);
    for (int i = 0; i < 7; ++i) {
      ptrs[i] = static_cast<int*>(f.Allocate());
      f.Deallocate(ptrs[i]);
      ptrs[i] = static_cast<int*>(f.Allocate());
      *ptrs[i] = i;
    }
    for (int i = 0; i < 7; ++i) {
      assert(*ptrs[i] == i);
    }
  }
  std::cout << 1;
  system("pause");
}
