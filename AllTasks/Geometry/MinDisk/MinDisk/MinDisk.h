#include <vector>
#include <iostream>

#define pointDist(i, j) (sqrt(pow((set[j].x-set[i].x), 2) + pow((set[j].y-set[i].y),2)))
#define Xcenter(x1, y1, x2, y2, x3, y3) -0.5*(((y1*(pow(x2, 2)+pow(y2, 2) - pow(x3, 2)-pow(y3, 2)))+y2*(pow(x3, 2)+pow(y3, 2)-pow(x1, 2)-pow(y1, 2))+y3*(pow(x1, 2) + pow(y1, 2) - pow(x2, 2)-pow(y2, 2)))/(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)))
#define Ycenter(x1, y1, x2, y2, x3, y3) 0.5*(x1*(pow(x2, 2)+pow(y2, 2)-pow(x3, 2)-pow(y3, 2))+x2*(pow(x3, 2)+pow(y3, 2) -pow(x1, 2) -pow(y1, 2))+x3*(pow(x1, 2)+pow(y1, 2)-pow(x2, 2)-pow(y2, 2)))/(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))

class MinDisk
{
private:

	struct point
	{
		float x, y;
	};

	float radius = 0;

	point* centre = new point; ///����� ����������
	std::vector <point> set, PCir; ///Set - ��� ����� | PCir (Points of circle) - �����, ������� �� ����������

public:

	MinDisk();

	void ShowCirclePoints()
	{
		std::cout << "\n\n";
		for (int i = 0; i < PCir.size(); i++)
		{
			std::cout << i+1 << ") x = " << PCir[i].x << " y = " << PCir[i].y << "\n";
		}
	}

	void SetPoint(float x, float y) 
	{
		set.push_back({ x, y });
	};

	void ShowSet()
	{
		for (int i = set.size() - 1; i >= 0; i--) std::cout << i + 1 << ") x: " << set[i].x << "  y: " << set[i].y << "\n";
	}

	//���������� True - ���� ����������� ����� ��������� �� ����������
	bool isPointOnCircle(int i)
	{
		for (int j = 0; j < PCir.size(); j++)
		{
			if (set[i].x == PCir[j].x && set[i].y == PCir[j].y) return true;
		}
		return false;
	}

	//���������� True - ���� ��� ����� ����� � ����������
	bool CheckAllPoints()
	{
		radius = (sqrt(pow((PCir[0].x - centre->x), 2) + pow((PCir[0].y - centre->y), 2)));
		for (int i = 0; i < set.size(); i++)
		{
			if (isPointOnCircle(i)) continue;
			if (((pow((set[i].x - centre->x), 2) + pow((set[i].y - centre->y), 2)) > pow(radius, 2))) return false;
		}
		return true;
	}

	//������� ����� ����� �� ���� �����������
	void FindCentreForTwoPoints()
	{
		centre->x = (PCir[0].x + PCir[1].x) / 2;
		centre->y = (PCir[0].y + PCir[1].y) / 2;
	}


	//������� ����� ����� �� ���� �����������
	void FindCentreForThreePoints()
	{
		centre->x = Xcenter(PCir[0].x, PCir[0].y, PCir[1].x, PCir[1].y, PCir[2].x, PCir[2].y);
		centre->y = Ycenter(PCir[0].x, PCir[0].y, PCir[1].x, PCir[1].y, PCir[2].x, PCir[2].y);
		radius = (sqrt(pow((PCir[0].x - centre->x), 2) + pow((PCir[0].y - centre->y), 2)));
	}

	//���������� ������ ���� �����, ������� ���������� ���������� �� ��������� �����
	void GetVectTwoPointMaxDist()
	{
		float max = 0;
		for (int i = 0; i < set.size() - 1; i++)
			for (int j = 1; j < set.size(); j++)
			{
				if (pointDist(i, j) > max)
				{
					max = pointDist(i, j);
					PCir.clear();
					PCir.push_back(set[i]);
					PCir.push_back(set[j]);
				}
			}
	}

	//���������� ������ ���� �����, � ������� ��� ��� ���������� � �������,
	//������ ��������� � ���������� ���������� ����������� ���������� ����� ������ ��������� �
	//������, ������� �� ������, ���������� �� �������
	void GetVectThreePointMaxDist()
	{
		float max = 0;
		PCir.push_back({ 0, 0 });
		for (int i = 0; i < set.size(); i++)
		{
			if ((sqrt(pow((set[i].x - centre->x), 2) + pow((set[i].y - centre->y), 2))) > max)
			{
				PCir.pop_back();
				PCir.push_back(set[i]);
			}
		}
	}

	void getCentreRadius()
	{
		GetVectTwoPointMaxDist();
		FindCentreForTwoPoints();
		if (CheckAllPoints()) std::cout << "\n1 case:\nCenter is (" << centre->x << ", " << centre->y << ")\nRadius is " << radius << std::endl;
		else
		{
			GetVectThreePointMaxDist();
			FindCentreForThreePoints();
			if (CheckAllPoints()) std::cout << "\n2 case:\nCenter is (" << centre->x << ", " << centre->y << ")\nRadius is " << radius << std::endl;
		}
	}

	~MinDisk();
};

/*

�������� ������:
1) ����� ��� �����, ������� ���������� ���������� ����� ����� ������� ����� ���������.
2) ����� ����� ���������� - �����, ������� ����� �� ������, ���������� �������, ����� ��������� �����.
3) ��������� ���������� � ���������, ��� �� ����� ����� � �������� ����������.
3) ���� ��, �� ��������� ������, ���������� ��������.
4) ���� ���, �� ����� ������ �����, ������� ����� ����� ���������� ���������� ����� ������ ����� ��������� �
   ������ ������ ����������.
5) �� ���� ������ ��������� ���������� � ����� � �����.

*/