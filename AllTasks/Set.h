#include <algorithm>
#include <iostream>
#include <vector>

class Set {
 private:
  std::vector<int64_t> set_;

 public:
  Set() = default;

  explicit Set(const std::vector<int64_t>& set) { 
    for (const auto& it : set)
      Add(it);
  }

  void Add(int64_t num) {
    if (!Contains(num)) 
      set_.push_back(num);
  }

  void Remove(int64_t num) {
    set_.erase(std::find(set_.begin(), set_.end(), num));
  }

  bool Contains(int64_t num) const {
    return std::find(set_.begin(), set_.end(), num) != set_.end();
  }

  std::vector<int64_t> Data() {
    return set_;
  }

  Set Union(const Set& second_set) const {
    Set res_set(set_);
    for (size_t i = 0; i < second_set.set_.size(); ++i)
      if (!Contains(second_set.set_[i])) 
        res_set.Add(second_set.set_[i]);
    return res_set;
  }

  Set Intersection(const Set& second_set) const {
    Set new_set;
    for (size_t i = 0; i < second_set.set_.size(); ++i)
      if (Contains(second_set.set_[i])) 
        new_set.Add(second_set.set_[i]);
    return new_set;
  }

  Set Difference(const Set& second_set) const {
    Set new_set(set_);
    for (size_t i = 0; i < second_set.set_.size(); ++i)
      if (Contains(second_set.set_[i]))
        new_set.Remove(second_set.set_[i]);
    return new_set;
  }

  Set SymmetricDifference(const Set& second_set) const {
    return Difference(second_set).Union(second_set.Difference(*this));
  }

  std::vector<int64_t>::iterator begin() { 
    return set_.begin();
  }

  std::vector<int64_t>::iterator end() 
  { 
    return set_.end();
  }
};
