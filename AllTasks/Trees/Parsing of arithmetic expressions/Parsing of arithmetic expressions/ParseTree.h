#include <string>
#include <iostream>
#include <vector>

class ParseTree
{
private:

	struct Node 
	{
		char data;
		Node *left, *right;
	};

	Node* root;

	std::string expression;

public:
	
	ParseTree() { };

	void SetExpression(std::string s) 
	{
		expression = s;
	};

	int Priority(char c)
	{
		switch (c)
		{
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		}
		return 100; // ��� �� �������������� ��������
	}

	//������� ���������
	int CalcTree()
	{
		return CalcTree(root);
	}

	int CalcTree(Node* Tree)
	{
		int num1, num2;
		if (!Tree->left) return Tree->data - '0';  // ���� ��� ��������, ������� �����
		num1 = CalcTree(Tree->left); // ��������� ����������
		num2 = CalcTree(Tree->right);
		switch (Tree->data) // ��������� ��������
		{ 
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '*': return num1 * num2;
		case '/': return num1 / num2;
		}
		return 32767; // ����������� ��������, ������!
	}

	//������� ������
	void MakeTree()
	{
		root = MakeTree(expression, 0, expression.size() - 1);
	}

	Node* MakeTree(std::string expr, int first, int last)
	{
		int MinPrt, k, prt;
		int nest = 0; // ������� �������� ������
		Node* Tree = new Node;
		if (first == last) // �������� �������: ����� ��� ����������
		{ 
			Tree->data = expr[first];
			Tree->left = nullptr;
			Tree->right = nullptr;
			return Tree;
		}
		MinPrt = 100;
		//������� �������� � ���������� �����������, ��������� ���������� ������
		for (int i = first; i <= last; i++)
		{
			if (expr[i] == '(')
			{
				nest++; 
				continue;
			}
			if (expr[i] == ')')
			{
				nest--; 
				continue;
			}
			if (nest > 0) continue; // ���������� ���, ��� � �������
			prt = Priority(expr[i]);
			if (prt <= MinPrt)
			{
				MinPrt = prt;
				k = i;
			}
		}
		if (MinPrt == 100 && expr[first] == '(' && expr[last] == ')') // ��� ��������� ����� � ������
		{
			delete Tree;
			return MakeTree(expr, first + 1, last - 1);
		}
		Tree->data = expr[k]; // ���������� ������� (��������)
		Tree->left = MakeTree(expr, first, k - 1); // ���������� ������
		Tree->right = MakeTree(expr, k + 1, last); // ����������
		return Tree;
	}

	//����� ��� 
	void Show()
	{
		Show(root);
	}

	void Show(Node *ptr)
	{
		if (ptr == nullptr) return;
		Show(ptr->left);
		std::cout << ptr->data << " ";
		Show(ptr->right);
	}
};