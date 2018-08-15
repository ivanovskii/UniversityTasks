#include <Windows.h>

class Cars
{
private:
	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	int speed, startPosition, Position, numLine, roadLenght;
	char symbol;

	Cars() {};

	Cars(int rL, int sp, int sPos, int nLine, char sym)
	{
		roadLenght = rL;
		speed = sp; 
		startPosition = sPos;
		Position = sPos;
		numLine = nLine * 2 - 1;
		symbol = sym;
	}

	void move()
	{
		position.X = Position;
		position.Y = numLine;
		SetConsoleCursorPosition(hConsole, position);
		std::cout << symbol;
		Position += speed;
	}

	void remove()
	{
		position.X = Position - speed;
		position.Y = numLine;
		SetConsoleCursorPosition(hConsole, position);
		std::cout << " ";
		if (Position >= (roadLenght + speed - (speed - 1))) Position = startPosition;
	}
};