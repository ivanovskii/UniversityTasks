#include <string>
#include <vector>
#include <map>
#include <algorithm>

using ObjectId = std::uint64_t;

struct GameObject {
  ObjectId id;
  std::string name;
  size_t x;
  size_t y;
};

bool comp(const GameObject& a, const GameObject& b) {
  return a.id > b.id;
}

class GameDatabase {
 private:
  std::map <ObjectId, GameObject> database_;

 public:
  GameDatabase() = default;

  /// вставляет в базу объект с именем [name] и позицией [x, y]
  /// если объект с таким id в базе уже есть, заменяет его новым
  void Insert(ObjectId id, std::string name, size_t x, size_t y) {
    database_.insert_or_assign(id, GameObject{ id, name, x, y });
  }

  /// удаляет элемент по id
  /// если такого элемента нет, ничего не делает
  void Remove(ObjectId id) {
    database_.erase(id);
  }

  /// возвращает вектор объектов c именем [name]
  /// сортировка по убыванию id
  std::vector<GameObject> DataByName(std::string name) const {
    std::vector <GameObject> res;
    for (const auto& it : database_)
      if (it.second.name == name)
        res.push_back(it.second);
    std::sort(res.begin(), res.end(), comp);
    return res;
  }

  /// возвращает вектор объектов, находящихся в позиции [x, y]
  /// сортировка по убыванию id
  std::vector<GameObject> DataByPosition(size_t x, size_t y) const {
    std::vector <GameObject> res;
    for (const auto& it : database_)
      if (it.second.x == x && it.second.y == y)
        res.push_back(it.second);
    std::sort(res.begin(), res.end(), comp);
    return res;
  }

  /// возвращает вектор всех объектов из базы
  /// сортировка по убыванию id
  std::vector<GameObject> Data() const {
    std::vector <GameObject> res;
    for (const auto& it : database_)
      res.push_back(it.second);
    std::sort(res.begin(), res.end(), comp);
    return res;
  }
};
