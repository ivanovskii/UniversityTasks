#include <iostream>
#include <iterator>
#include <vector>
#include <list>

template <typename T, typename Iterator>
typename std::enable_if<std::is_same<typename Iterator::iterator_category,
                                     std::random_access_iterator_tag>::value,
                        Iterator>::type
Find(const T& value, Iterator start, Iterator end) {
  auto res = std::lower_bound(start, end, value);
  if ((res != end) && (*res == value))
    return res;
  else
    return end;
}
template <typename T, typename Iterator>
typename std::enable_if<!std::is_same<typename Iterator::iterator_category,
                                     std::random_access_iterator_tag>::value,
                        Iterator>::type
Find(const T& value, Iterator start, Iterator end) {
  auto res = std::find(start, end, value);
  if ((res != end) && (*res == value))
    return res;
  else
    return end;
}

int main() {

  std::list<int> v = {1,2,3};
  std::cout << *Find(2, v.begin(), v.end());
  system("pause");
}
