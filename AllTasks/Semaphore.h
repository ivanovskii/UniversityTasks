#include <condition_variable>
#include <mutex>

class Semaphore {
 public:
  explicit Semaphore(int threads_cnt) : threads_cnt_(threads_cnt) {}

  void Wait() {
    std::unique_lock<std::mutex> lock(m_);
    threads_cnt_--;
    if (threads_cnt_ < 0) {
      do {
        cv_.wait(lock);
      } while (cnt_ < 1);
      cnt_--;
    }
  }

  void Notify() {
    std::unique_lock<std::mutex> lock(m_);
    threads_cnt_++;
    if (threads_cnt_ <= 0) {
      cnt_++;
      cv_.notify_one();
    }
  }

 private:
  std::mutex m_;
  std::condition_variable cv_;
  int threads_cnt_ = 0, cnt_ = 0;
};
