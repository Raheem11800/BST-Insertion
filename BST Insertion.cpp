#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* right;
	node* left;

	node(int d)
	{
		data = d;
		right = NULL;
		left = NULL;
	}

	node* insertBST(node*& root, int d)
	{
		if (root == NULL)
		{
			return new node(d);
		}
		if (d < root->data)
		{
			root->left = insertBST(root->left, d);
		}
		else
		{
			root->right = insertBST(root->right, d);
		}

		return root;
	}

	void preorder(node*& root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}

	void inorder(node*& root)
	{
		if (root == NULL)
		{
			return;
		}
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	void postorder(node*& root)
	{
		if (root == NULL)
		{
			return;
		}
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
};

void main()
{
	node* root = NULL;
	root = root->insertBST(root, 1);
	root->insertBST(root, 7);
	root->insertBST(root, 4);
	root->insertBST(root, 8);
	root->insertBST(root, 9);
	root->insertBST(root, 2);

	cout << "Inorder: ";
	root->inorder(root);
	cout << endl;

	cout << "Postorder: ";
	root->postorder(root);
	cout << endl;

	cout << "Preorder: ";
	root->preorder(root);
	cout << endl;

}