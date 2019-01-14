class PrimeNumberGenerator {
 private:
  int start_;
  bool first_num_ = true;

  bool IsSimpleNumber(int num) {
    for (int d = 2; d * d <= num; d++)
      if (num % d == 0) return false;
    return true;
  }

 public:
  explicit PrimeNumberGenerator(int start) : start_(start) {}

  int GetNextPrime() {
    if (start_ == 1) {
      first_num_ = false;
      return start_ = 2;
    }
    if (!(first_num_ && IsSimpleNumber(start_)))
      for (start_++; !IsSimpleNumber(start_); start_++) {
      }
    first_num_ = false;
    return start_;
  };
};
