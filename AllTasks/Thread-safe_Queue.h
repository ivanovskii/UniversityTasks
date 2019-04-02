#include <queue>
#include <mutex>
#include <string>
#include <utility>
#include <condition_variable>

template<typename T>
class Queue {
 public:
  T Pop() {
    std::unique_lock<std::mutex> lock(mut_);
    while (q.empty())
      cv_.wait(lock);
    lock.unlock();
    T val = std::move(q.front());
    q.pop();
    return std::move(val);
  }

  size_t Size() {
    std::unique_lock<std::mutex> lock(mut_);
    size_t size = q.size();
    lock.unlock();
    return size;
  }

  template <typename U>
  void Push(U&& elem) {
    std::lock_guard<std::mutex> lock(mut_);
    q.push(std::move(elem));
    cv_.notify_one();
  }

  template <class ... U>
  void Emplace(U ... arg) {
    std::unique_lock<std::mutex> lock(mut_);
    q.emplace(arg...);
    lock.unlock();
  }

 private:
  std::queue<T> q;
  std::mutex mut_;
  std::condition_variable cv_;
};
