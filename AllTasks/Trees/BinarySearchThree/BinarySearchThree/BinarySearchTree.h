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

	//����������� ������
	BinaryTreeSearch()
	{
		root = nullptr;
	}

	//����� ������� ����� ���� � ���������� ���������
	Node* CreateNode(int key)
	{
		Node *NewNode = new Node;
		NewNode->key = key;
		NewNode->left = nullptr;
		NewNode->right = nullptr;
		return NewNode;
	}

	//������� ��� ������� ����������, �������� ������ ������ � ����������� �������
	void Add(int key)
	{
		Add(root, key);
	}

	//����� ���������� ���� � ������
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

	//������� ��� ������� ������. ���������� true, ���� ������� ������. False - � ��������� ������
	bool Find(int key)
	{
		Node *time = nullptr;
		time = Find(root, key);
		if (time == nullptr) return false;
		else true;
	}

	//����� ������ ��������. ���������� ��������� �� ��������� �������
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

	//������� ��� ������� ������ ��� � ������ ���������
	void Show()
	{
		Show(root);
		if (root == nullptr) std::cout << "Tree doesn't exist\n";
		else std::cout << "\n";
	}

	//����� ������ ��� � ������ ���������
	void Show(Node *ptr)
	{
		if (ptr == nullptr) return;
		Show(ptr->left);
		std::cout << ptr->key << " ";
		Show(ptr->right);
	}

	//����� ���������� ������������� ��������. ��������� ��� ������ �������� ����
	Node* FindMaxNode(Node *root)
	{
		if (root == nullptr) exit(4);
		if (root->right) return FindMaxNode(root->right);
		return root;
	}

	//������� ��� ����������� ������� ���������� ����������� ����
	Node *FindPrevNode(Node* ptr)
	{
		return FindPrevNode(root->left, ptr);
	}

	//���������� ��������� �� ���������� ����
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

	//������� ��� ������� �������� ����, �������� ������ ������
	void DeleteNode(int key)
	{
		DeleteNode(root, key);
	}

	//����� �������� ����
	Node* DeleteNode(Node* ptr, int key)
	{
		if (root == nullptr) return nullptr;;
		//���� ����� ������� ������, ��
		if (root->key == key)
		{
			//���� ����� ���� ����, ��
			if (root->left != nullptr)
			{
				//������� ������������ ���� � ���������� �������������
				Node *NewRoot = FindMaxNode(root->left);
				Node *prev = FindPrevNode(NewRoot);
				if (NewRoot->key == root->left->key) prev = NewRoot; //���� ������������ ���� ����� ���� ������ �����, prev = �������. �� �������� �� �������
				if (NewRoot->left == nullptr && NewRoot->right == nullptr && prev != NewRoot) //���� ��� ����
				{
					NewRoot->left = root->left;
					NewRoot->right = root->right; //������ �� ������������� ���� - ������
					if (prev->right == NewRoot) prev->right = nullptr; //�������� ���������� ���������
					delete root;
					root = NewRoot;
				}
				else //���� ��� �� ����, ������, ������������ ��������� ����� �� �����
				{
					root->left->right = root->right;
					delete root;
					root = NewRoot;
				}
			}
			else if (root->right != nullptr) root = root->right; //���� � ��� ����� ��� �����, ������ �� ����� - ����� ������
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

	//������� ��� ������� ����������� ������, �������� ������ ������
	void Clear()
	{
		Clear(root);
	}

	//����� ����������� ������
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