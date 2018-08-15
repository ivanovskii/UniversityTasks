#include <iostream>
#include <iterator>
#include <math.h>

const int eps = 0.00001;

double f(double x)
{
	return (x*x-2); //Любая монотонная непрерывная функция
}


void end()
{
	std::cout << std::endl;
	system("pause");
	system("cls");
}

double der_f(double x)
{
	return ((f(x + 0.01) - f(x - 0.01)) / (2 * 0.01));
}

double NewtonMethod(double x)
{
	while (f(x) > eps) x = x - f(x) / der_f(x);
	return x;
}

double Chord(double l, double r) // Где a — левая граница, а b — правая
{
	while (abs(l - r) > eps)
	{
		l = r - (r - l) * f(r) / (f(r) - f(l));
		r = l - (l - r) * f(l) / (f(l) - f(r));
	}
	return r;
}

double binSearch(double a, double b)
{
	double c;
	while (b - a > eps)
	{
		c = (a + b) / 2;
		if (f(b) * f(c) < 0)
			a = c;
		else
			b = c;
	}
	return (a + b) / 2;
}

int main()
{
	while (true)
	{
		std::cout << "Choose the action:\n1) Calculate by chords\n2) Calculate by the method of tangents\n3) Calculate by binary search\n>>> ";
		switch (*std::istream_iterator <int>(std::cin))
		{
		case 1:
			system("cls");
			std::cout << Chord(1, 5); //Значения подбираются самостоятельно
			end();
			break;
		case 2:
			system("cls");
			std::cout << NewtonMethod(-2); //Значения подбираются самостоятельно
			end();
			break;
		case 3:
			system("cls");
			std::cout << binSearch(1, 5); //Значения подбираются самостоятельно
			end();
			break;
		default:
			end();
			break;
		}
	}
	system("pause");
}
