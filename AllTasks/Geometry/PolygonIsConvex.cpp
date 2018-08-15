#include <iostream>
#include <vector>

#define equationOfTheLine(i, j, k) ((p[i].y-p[j].y)*p[k].x+(p[j].x-p[i].x)*p[k].y+(p[i].x*p[j].y-p[j].x*p[i].y))

struct Point
{
	float x, y;
};

void input(std::vector <Point> &points)
{
	float x = 0, y = 0;
	unsigned short int amount = 0;
	std::cout << "How many points you want to enter?\n>>> ";
	std::cin >> amount;
	system("cls");
	for (int i = 0; i < amount; ++i)
	{
		std::cout << "Fill the vector.\n";
		std::cin >> x >> y;
		points.push_back({ x, y });
		system("cls");
	}
}

bool isConvex(std::vector <Point> p)
{
	for (int i = 0; i < p.size(); i++)
	{
		int j = (i + 1) % p.size();	
		for (int k = 0; k < p.size(); k++) if ((k != i || k != j) && (equationOfTheLine(i, j, k) < 0)) return false;
	}
	return (p.size() > 2 ? true : false);
}

float square(std::vector <Point> points)
{
	int s = 0;
	for (int i = 0; i < points.size(); ++i)
	{
		if (i != points.size() - 1)
			s += (points[i].x * points[i + 1].y - points[i].y * points[i + 1].x);
		else
			s += (points[i].x * points[0].y - points[i].y * points[0].x);
	}
	return (abs(s)*0.5);
}

int main() 
{
	std::vector <Point> points;
	input(points);
	std::cout << "Entered points:\n";
	for (int i = 1; i <= points.size(); ++i) std::cout << i << ") " << points[i - 1].x << "  " << points[i - 1].y << std::endl;
	std::cout << "\n";
	if (isConvex(points)) std::cout << "It is a convexity polygon!\nSquare is " << square(points) << std::endl;
	else std::cout << "It isn't a convexity polygon!\n";
	system("pause");
	return 0;
}
