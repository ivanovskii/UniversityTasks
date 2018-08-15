#include <iostream>

class BinaryTreeSearch {
private:

	struct Node
	{
		int key;
		Node *left, *right;
	};

	Node* root;

public:

	//Конструктор класса
	BinaryTreeSearch()
	{
		root = nullptr;
	}

	//Метод создает новый узел и возвращает указатель
	Node* CreateNode(int key)
	{
		Node *NewNode = new Node;
		NewNode->key = key;
		NewNode->left = nullptr;
		NewNode->right = nullptr;
		return NewNode;
	}

	//Обертка над методом добавления, посылает корень дерева в рекурсивную функцию
	void Add(int key)
	{
		Add(root, key);
	}

	//Метод добавления узла в дерево
	void Add(Node* &ptr, int key)
	{
		if (ptr == nullptr)
		{
			ptr = CreateNode(key);
			if (root == nullptr) root = ptr;
			return;
		}
		if (key < ptr->key) Add(ptr->left, key);
		else Add(ptr->right, key);
	}

	//Обертка над методом поиска. Возвращает true, если элемент найден. False - в противном случае
	bool Find(int key)
	{
		Node *time = nullptr;
		time = Find(root, key);
		if (time == nullptr) return false;
		else true;
	}

	//Метод поиска элемента. Возвращает указатель на найденный элемент
	Node *Find(Node *ptr, int key)
	{

		if (ptr == nullptr)
		{
			return nullptr;
			exit;
		}
		if (key == ptr->key) return ptr;
		else if (key < ptr->key) BinaryTreeSearch::Find(ptr->left, key);
		else Find(ptr->right, key);
	}

	//Обертка над методом обхода ЛКП и вывода элементов
	void Show()
	{
		Show(root);
		if (root == nullptr) std::cout << "Tree doesn't exist\n";
		else std::cout << "\n";
	}

	//Метод обхода ЛКП и вывода элементов
	void Show(Node *ptr)
	{
		if (ptr == nullptr) return;
		Show(ptr->left);
		std::cout << ptr->key << " ";
		Show(ptr->right);
	}

	//Метод нахождения максимального элемента. Необходим для метода удаления узла
	Node* FindMaxNode(Node *root)
	{
		if (root == nullptr) exit(4);
		if (root->right) return FindMaxNode(root->right);
		return root;
	}

	//Обертка над рекурсивным методом нахождения предыдущего узла
	Node *FindPrevNode(Node* ptr)
	{
		return FindPrevNode(root->left, ptr);
	}

	//Возвращает указатель на предыдущий узел
	Node* FindPrevNode(Node *prev, Node *ptr)
	{
		if (prev == nullptr) exit;
		if (prev->left == ptr || prev->right == ptr) return prev;
		else
		{
			FindPrevNode(prev->left, ptr);
			FindPrevNode(prev->right, ptr);
		}
	}

	//Обертка над методом удаления узла, посылает корень дерева
	void DeleteNode(int key)
	{
		DeleteNode(root, key);
	}

	//Метод удаления узла
	Node* DeleteNode(Node* ptr, int key)
	{
		if (root == nullptr) return nullptr;;
		//Если нужно удалить корень, то
		if (root->key == key)
		{
			//Если слева есть узлы, то
			if (root->left != nullptr)
			{
				//Находим максимальный узел и предыдущий максимального
				Node *NewRoot = FindMaxNode(root->left);
				Node *prev = FindPrevNode(NewRoot);
				if (NewRoot->key == root->left->key) prev = NewRoot; //Если максимальный узел равен узлу левого корня, prev = текущий. Не проходит по условию
				if (NewRoot->left == nullptr && NewRoot->right == nullptr && prev != NewRoot) //Если это лист
				{
					NewRoot->left = root->left;
					NewRoot->right = root->right; //Делаем из максимального узла - корень
					if (prev->right == NewRoot) prev->right = nullptr; //Обнуляем предыдущий указатель
					delete root;
					root = NewRoot;
				}
				else //Если это не лист, значит, максимальный находится слева от корня
				{
					root->left->right = root->right;
					delete root;
					root = NewRoot;
				}
			}
			else if (root->right != nullptr) root = root->right; //Если у нас слева нет узлов, справа от корня - новый корень
			else root = nullptr;
		}
		else
		{
			if (ptr == nullptr)
			{
				std::cout << "No such key\n";
				return nullptr;
			}
			if (ptr->key > key)
			{
				ptr->left = DeleteNode(ptr->left, key);
				return ptr;
			}
			else
				if (ptr->key < key)
				{
					ptr->right = DeleteNode(ptr->right, key);
					return ptr;
				}
				else
					if (ptr->left && ptr->right)
					{
						Node* locMax = FindMaxNode(ptr->left);
						ptr->key = locMax->key;
						ptr->left = DeleteNode(ptr->left, locMax->key);
						return ptr;
					}
					else
						if (ptr->left)
						{
							Node *tmp = ptr->left;
							delete ptr;
							return tmp;
						}
						else
							if (ptr->right)
							{
								Node *tmp = ptr->right;
								delete ptr;
								return tmp;
							}
							else
							{
								delete ptr;
								return nullptr;
							}
		}
	}

	//Обертка над методом уничтожения дерева, посылает корень дерева
	void Clear()
	{
		Clear(root);
	}

	//Метод уничтожения дерева
	void Clear(Node* ptr)
	{
		if (ptr == nullptr) return;
		Clear(ptr->left);
		Clear(ptr->right);
		delete (ptr);
		if (root != nullptr) root = nullptr;
	}

	~BinaryTreeSearch()
	{
		Clear();
	};
};