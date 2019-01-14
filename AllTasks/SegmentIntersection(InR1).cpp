#include <iostream>
#include <vector>
#include <algorithm>

struct Segment {
	float x1, x2;
  Segment(float x1_, float x2_) : x1(x1_), x2(x2_) {
          if (x1 > x2) std::swap(x1, x2);
  };
};

bool IsIntersection(const Segment& segment1, const Segment& segment2) {
	return segment1.x2 >= segment2.x1;
}

// Сортировка вектора отрезков по первой координате
void SortSegments(std::vector <Segment>& s) {
	std::sort(s.begin(), s.end(), [](const Segment& seg1, const Segment& seg2) -> bool {
		return seg1.x1 < seg2.x1;
	}
	);
}

int main() {
  std::vector<Segment> segments{Segment(0, 0), Segment(1, 1), Segment(1, 0)};
	SortSegments(segments);
	// Для вектора с индексами 01234 нужно перебрать: 01, 02, 03, 04, 12, 13, 14, 23
	for (size_t i = 0; i < segments.size() - 1; i++)
		for (size_t j = i + 1; j < segments.size(); j++) {
			if (IsIntersection(segments[i], segments[j])) {
				std::cout << "Segment [" << segments[i].x1 << ", " << segments[i].x2 << "]";
				std::cout << " intersects with a segment [" << segments[j].x1 << ", " << segments[j].x2 << "]\n";
			}
		}
	system("pause");
}
