#include <iostream>
#include <iterator>
#include <thread>
#include <vector>

class DenseMat {
 public:
  explicit DenseMat(int32_t rows = 0, int32_t cols = 0)
      : rows_(rows), cols_(cols) {
    matrix_.resize(rows);
    for (size_t i = 0; i < matrix_.size(); ++i) 
      matrix_[i].resize(cols);
  }

  DenseMat(int32_t rows, int32_t cols, const std::vector<int32_t>& data)
      : DenseMat(rows, cols) {
    auto it = begin(data);
    for (size_t i = 0; i < rows; ++i)
      for (size_t j = 0; j < cols; ++j) {
        matrix_[i][j] = *it;
        it++;
      }
  }

  int32_t Rows() const { return rows_; }

  int32_t Cols() const { return cols_; }

  const int32_t& operator()(int row, int col) const { return matrix_[row][col];}

  int32_t& operator()(int row, int col) { return matrix_[row][col]; }

  bool operator==(const DenseMat& other) const {
    if (Rows() != other.Rows() && Cols() != other.Cols()) 
      return false;
    for (size_t i = 0; i < Rows(); ++i)
      for (size_t j = 0; j < Cols(); ++j)
        if (matrix_[i][j] != other.matrix_[i][j]) 
          return false;
    return true;
  }

  bool operator!=(const DenseMat& other) const {
    if (*this == other) 
      return false;
    return true;
  }

  DenseMat MatMulParal(const DenseMat& a, const DenseMat& b, int thread_count) {
    DenseMat c(a.Rows(), b.Cols());
    if (thread_count > a.Rows())
      thread_count = a.Rows();
    
    int count = a.Rows() / thread_count;
    int additional = a.Rows() % thread_count;

    auto CalcThread = [&a, &b, &c](int startRow, int endRow) {
      for (int i = startRow; i <= endRow; i++)
        for (int j = 0; j < b.Cols(); j++)
          for (int k = 0; k < a.Cols(); k++)
            c(i, j) += a(i, k) * b(k, j);
    };

    std::vector <std::thread> threads;
    int start = 0;
    for (int i = 0; i < thread_count; i++) {
      int last = ((i == 0) ? count + additional : count);
      std::thread thr(CalcThread, start, start + last - 1);
      threads.emplace_back(std::move(thr));
      start += last;
    }

    for (auto& thr : threads)
      thr.join();

    return c;
  }

 private:
  int32_t rows_, cols_;
  std::vector<std::vector<int32_t>> matrix_;
};
