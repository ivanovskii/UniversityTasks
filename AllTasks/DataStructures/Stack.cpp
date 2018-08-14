#include <iostream>

using namespace std;

struct List
{
	int x; //информационный элемент
	List *Next, *Head; //Голова стека и указатель на следующий элемент
};

/*ФУНКЦИЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА В СТЕК (в список LIFO)*/
void Add(int x, List *&MyList) //Принимаем элемент стека и указатель на стек, при этом говорим, что принимаемый указатель будет сам по себе указателем
{
	List *temp = new List; //Выделяем память для нового элемента
	temp->x = x; //Записываем в поле x принимаемый в функцию элемент x
	temp->Next = MyList->Head; //Указываем, что следующий элемент это предыдущий
	MyList->Head = temp; //Сдвигаем голову на позицию вперед
}

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ СТЕКА*/
void Show(List *MyList) //Нужен только сам стек
{
	List *temp = MyList->Head; //Объявляем указатель и Указываем ему, что его позиция в голове стека
							   //с помощью цикла проходим по всему стеку
	while (temp != NULL) //выходим при встрече с пустым полем
	{
		cout << temp->x << " "; //Выводим на экран элемент стека
		temp = temp->Next; //Переходим к следующему элементу
	}
}

/*ФУНКЦИЯ УДАЛЕНИЯ СТЕКА ИЗ ПАМЯТИ*/
void ClearList(List *MyList)
{
	while (MyList->Head != NULL) //Пока по адресу не пусто
	{
		List *temp = MyList->Head->Next; //Временная переменная для хранения адреса следующего элемента
		delete MyList->Head; //Освобождаем адрес обозначающий начало
		MyList->Head = temp; //Меняем адрес на следующий
	}
}

int main()
{
	List *MyList = new List; //Выделяем память для стека
	MyList->Head = NULL; //Во избежание ошибок инициализируем первый элемент
	while (true)
	{
		int num;
		cin >> num;
		if (num == 1) break;
		Add(num, MyList); //Заносим данные в стек
	}
	Show(MyList); //Выводим стек на экран
	ClearList(MyList); //Очищаем память.
	delete MyList->Head;
	delete MyList;
	system("pause");
}
