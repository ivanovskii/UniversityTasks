#include <iostream>
#include <vector>

class FixedAllocator {
 public:
  // Конструктор, принимающий размер страницы памяти и размер одного объекта
  FixedAllocator(size_t c, size_t p) : chunk_size(c), page_size(p) {}

  // Возвращает указатель на свободный участок памяти
  // для одного элемента размера chunk_size
  void* Allocate() {
    if (free == nullptr)
      new_pool();
    Chunk* result = free;
    free = free->next;
    return static_cast<void*>(result);
  }

  // Возвращает в пул память, занимаемую элементом
  void Deallocate(void* ptr) {
    if (free == nullptr)
      return;
    Chunk* node = static_cast<Chunk*>(ptr);
    node->next = free;
    free = node;
  }

 private:
  void new_pool() {
    for (int i = 1; i <= page_size; ++i) {
      Chunk* curr = new Chunk();
      curr->buff = static_cast<char>(chunk_size);
      curr->next = free;
      free = curr;
    }
  }

  struct Chunk {
    char buff;
    Chunk* next = nullptr;
  };

  size_t chunk_size, page_size;
  Chunk* free = nullptr;
};
