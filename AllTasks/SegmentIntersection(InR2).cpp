#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

struct Point {
  float x, y;
  Point(float x_, float y_) : x(x_), y(y_){};
};

struct Segment {
  Point f_point, s_point;

  Segment(Point f, Point s) : f_point(f), s_point(s) {
    if (s_point.x < f_point.x)
      std::swap(f_point, s_point);
    if (s_point.x == f_point.x)
      if (s_point.y < f_point.y) 
        std::swap(f_point, s_point);
  };
};

// Ориентированная площадь треугольника
inline int area(const Point& a, const Point& b, const Point& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

//  Пересекаются ли проекции двух отрезков на оси X и Y
inline bool intersect_1(int a, int b, int c, int d) {
  if (a > b) std::swap(a, b);
  if (c > d) std::swap(c, d);
  return std::max(a, c) <= std::min(b, d);
}

bool intersect(const Point& a, const Point& b, const Point& c, const Point& d) {
  return intersect_1(a.x, b.x, c.x, d.x) && intersect_1(a.y, b.y, c.y, d.y) &&
         area(a, b, c) * area(a, b, d) <= 0 &&
         area(c, d, a) * area(c, d, b) <= 0;
}

// Обертка над intersect
bool intersect(const Segment& a, const Segment& b) {
  return intersect(a.f_point, a.s_point, b.f_point, b.s_point);
}

void SortSegments(std::vector<Segment>& v) {
  std::sort(v.begin(), v.end(),
            [](const Segment& seg1, const Segment& seg2) {
              return seg1.f_point.x < seg2.f_point.x;
            });
}

void Input(std::vector<Segment>& seg) {
  int n;
  std::cout << "Сколько отрезков вы хотите ввести?" << std::endl << ">>> ";
  std::cin >> n;
  system("cls");
  for (size_t i = 0; i < n; ++i)
  {
    int x1, y1, x2, y2;
    std::cout << "Точка A:\n>>> ";
    std::cin >> x1 >> y1;
    std::cout << "Точка B:\n>>> ";
    std::cin >> x2 >> y2;
    seg.push_back(Segment(Point(x1, y1), Point(x2,y2)));
    system("cls");
  }
}

int main() {
  setlocale(LC_ALL, "Rus");
  std::vector<Segment> segments;
  Input(segments);
  SortSegments(segments);
  for (size_t i = 0; i < segments.size(); ++i)
    for (size_t j = i + 1; j < segments.size(); ++j) 
    {
      if (intersect(segments[i], segments[j])) 
      {
        std::cout << "Segment ([" << segments[i].f_point.x << ", "
                  << segments[i].f_point.y << "], [" << segments[i].s_point.x
                  << ", " << segments[i].s_point.y << "]) intersects with ";
        std::cout << "a segment ([" << segments[j].f_point.x << ", "
                  << segments[j].f_point.y << "], [" << segments[j].s_point.x
                  << ", " << segments[j].s_point.y << "])\n";
      }
    }
  system("pause");
}
