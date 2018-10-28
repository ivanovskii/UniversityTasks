class AVL
{
private:

	struct node
	{
		int key;
		unsigned char height;
		node* left;
		node* right;
		node() {};
		node(int k) { key = k; left = right = 0; height = 1; };
	};

	node* root = new node;

public:

	AVL()
	{
		root = nullptr;
	}

	unsigned char height(node* p)
	{
		return (p ? p->height : 0);
	}

	int bfactor(node* p)
	{
		return height(p->right) - height(p->left);
	}

	void fixheight(node* p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->height = (hl>hr ? hl : hr) + 1;
	}
	
	node* rotateright(node* p)
	{
		node* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}
	
	node* rotateleft(node* q)
	{
		node* p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}
	
	node* balance(node* p)
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p;
	}

	void insert(int k)
	{
		root = insert(root, k);
	}

	node* insert(node* p, int k)
	{
		if (root == nullptr) return root = new node(k);
		if (!p) return new node(k);
		if (k < p->key)
			p->left = insert(p->left, k);
		else
			p->right = insert(p->right, k);
		return balance(p);
	}

	node* findmin(node* p)
	{
		return (p->left ? findmin(p->left) : p);
	}

	node* removemin(node* p)
	{
		if (p->left == 0)
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}

	void remove(int k)
	{
		root = remove(root, k);
	}

	node* remove(node* p, int k)
	{
		if (!p) return 0;
		if (k < p->key)
			p->left = remove(p->left, k);
		else if (k > p->key)
			p->right = remove(p->right, k);
		else //  k == p->key 
		{
			node* q = p->left;
			node* r = p->right;
			delete p;
			if (!r) return q;
			node* min = findmin(r);
			min->right = removemin(r);
			min->left = q;
			return balance(min);
		}
		return balance(p);
	}

	void show()
	{
		if (root != nullptr) show(root);
		else std::cout << "Empty";
	}

	void show(node* p)
	{
		if (p == nullptr) return;
		show(p->left);
		std::cout << p->key << " ";
		show(p->right);
	}
};
