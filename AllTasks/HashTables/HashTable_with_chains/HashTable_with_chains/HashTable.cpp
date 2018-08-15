#include <string>
#include <iostream>
#include <conio.h>

//����� ������������ ����� ���������� ���-������ � ���������
class HashTable {
private:

	struct List
	{
		std::string key;
		std::string value;
		List *next;
	};

	List* arr[256]; //������ ���������� �� ������

					//�������, ������������ ���������� ���������� ��������� � ����
					//��������� ����� 0, ����� � ���-������� ������ ��������� � ����� ������
	int getSameContacts(std::string key) {
		int counter = 0;
		List *time = arr[hashTable(key)];
		while (time != nullptr)
		{
			if (time->key == key) counter++;
			time = time->next;
		}
		return counter;
	}

public:
	//����������� ������.
	//�������������� ������ ������� ���������� ��� nullptr ��� ������ �������� �������, ���� ���������� �� ������
	HashTable()
	{
		//������������� nullptr ������ NULL ����������� � ���������� ���������
		//������������� ����� ��������� 0 ��� ������������� ��������� � ����������
		for (int i = 0; i < 256; i++) arr[i] = nullptr;
	}

	//���������� ������ ������� ��� ������������� �����
	int hashTable(std::string &key)
	{
		int position = 0;
		for (int i = 0; i < key.size(); i++) position += (int)key[i];
		position %= 256;
		return position;
	}

	//���������� �������� � ���-�������
	void add()
	{
		//���� ����� � ��������
		std::string key, value;
		std::cout << "Enter name: ";
		std::cin.ignore();
		std::getline(std::cin, key);
		std::cout << "Enter phone: ";
		std::getline(std::cin, value);

		//�������� ���������, ������������� � �����, ������������ ����� � ������������ ����������
		List *MyList = new List;
		(*MyList).key = key; // "->" ����� ��� ��������� �����
		MyList->value = value;
		MyList->next = nullptr;
		if (arr[hashTable(key)] == nullptr) arr[hashTable(key)] = MyList; //���� ������ ������� �� ���� ��� �������, �� ��������� � ��������� �����
		else //� ������ ������ ������� ��������� ���������, ������� � ��� ������� �������� ���� ���� � ��������� ����� � �����
		{
			List *time = arr[hashTable(key)];
			while (time->next != nullptr)
			{
				time = time->next;
			}
			time->next = MyList;
		}
		system("pause");
		system("cls");
	}

	//������� �� ����� ��� ���-�������. �������� ����� ���� �� ��������� ��������� ������ ��� �����������
	void show()
	{
		for (int i = 0; i < 256; i++)
		{
			if (arr[i] == nullptr) continue;
			else
			{
				List *time = arr[i];
				while (time != nullptr)
				{
					std::cout << "\n" << time->key << ": " << time->value;
					time = time->next;
				}
			}
			std::cout << "\n\n";
		}
		system("pause");
		system("cls");
	}

	//����� �� �����
	void find()
	{
		std::string key;
		std::cout << "Whose number you want to find?\n>>> ";
		std::cin >> key;
		List *time = arr[hashTable(key)];
		if (arr[hashTable(key)] == nullptr) std::cout << "Not Found!\n";
		else
		{
			std::cout << "\n";
			while (time != nullptr)
			{
				if (time->key == key)
				{
					std::cout << time->key << ": " << time->value << "\n";
				}
				time = time->next;
			}
			std::cout << "\n";
		}
		system("pause");
		system("cls");
	}

	//���������� ��� ��������� ������� � �������� ������ ����������
	//1 - ��� ������ ��������� �� ������� ��������
	//0 - ��� ������ ���������
	void clear(bool flag)
	{
		for (int i = 0; i < 256; ++i)
		{
			if (arr[i] == nullptr) continue;
			List *time = arr[i];
			while (time != nullptr)
			{
				delete time;
				time = time->next;
			}
		}
		for (int i = 0; i < 256; i++) arr[i] = nullptr;
		if (flag == true)
		{
			std::cout << "Well Done!\n";
			system("pause");
			system("cls");
		}
	}

	//����� �������� ���� �� ����
	void del()
	{
		std::string key;
		int order = 1, choice = 0;
		std::cout << "What contact you want to delete?\n>>> ";
		std::cin >> key;
		if (getSameContacts(key) == 0) std::cout << "There is no such contact\n";
		else
		{
			List *time = arr[hashTable(key)];
			List* timeArr[20]; //������ ���������� �� ��������� � ����������� ����������
			int i = 0;
			while (time != nullptr) //��������� ������ ���������� �� ���������� ��������
			{
				if (time->key == key) {
					timeArr[i] = time;
					i++;
				}
				time = time->next;
			}
			if (getSameContacts(key) > 1) //������, ����� ���������� ��������� > 1. ���������� ������� �������, ������� ����� �������
			{
				std::cout << "We detected same contacts. What contact you want to delete?\n";
				for (int i = 0; i < getSameContacts(key); i++) ///������� ��������, ������� ����� �������
				{
					time = timeArr[i];
					std::cout << order << ") " << time->key << ": " << time->value << "\n";
					order++;

				}
				std::cout << ">>> ";
				std::cin >> choice;
				choice--;
			}
			time = timeArr[choice]; //��������� �� ���������, ������� ���������� �������
			if (arr[hashTable(key)] == time) //������, ����� � ���� ������ ���� ������� - ����������� ���
			{
				arr[hashTable(key)] = time->next;
				delete time;
			}
			else //���� ���� ������� > 1 ���������, ���������� ����� ���������� ��������� ��� ���������, ������� ��������� �������
			{
				List *prev = arr[hashTable(key)];
				while (prev->next != time) prev = prev->next;
				prev->next = time->next;
				delete time;
			}
			std::cout << "Well Done!\n";
		}
		system("pause");
		system("cls");
	}

	//���������� ������.
	//���������� ��� ����������� ��������� ���� ���-�������
	~HashTable()
	{
		clear(0);
	};
};

int main()
{
	HashTable catalog;
	while (true)
	{
		int choice = 0;
		std::cout << "Press key:\n1) Add\n2) Del\n3) Search\n4) Show\n5) Clear HashTable\n6) Exit\n>>> ";
		std::cin >> choice;
		if (std::cin.fail()) //����� ���������� ���� cin
		{
			std::cout << "ERROR -- You did not enter an integer\n";
			std::cin.clear(); // �������� ��������� ������
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ��������� ����� ��������� ������ ���� 
		}
		if (choice == 6) break;
		switch (choice) {
		case 1:
		{
			catalog.add();
			continue;
		}
		case 2:
		{
			catalog.del();
			continue;
		}
		case 3:
		{
			catalog.find();
			continue;
		}
		case 4:
		{
			catalog.show();
			continue;
		}
		case 5:
		{
			catalog.clear(1);
			continue;
		}
		default:
		{
			system("pause");
			system("cls");
			continue;
		}
		}
	}
	system("pause");
	return 0;
}