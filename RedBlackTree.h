#include "Node.h"

class RBT
{
	Node *root;
	void INORDER(Node *p);
	void POSTORDER(Node *p);
	void PREORDER(Node *p);

public:
	RBT()
	{
		root = nullptr;
	}
	void insert(int value);
	void inorder();
	void postorder();
	void preorder();
};

void RBT::PREORDER(Node *p)
{
	if (p != nullptr)
	{
		cout << p->data << ":" << p->color << " ";
		PREORDER(p->left);
		PREORDER(p->right);
	}
}

void RBT::POSTORDER(Node *p)
{
	if (p != nullptr)
	{
		POSTORDER(p->left);
		POSTORDER(p->right);
		cout << p->data << ":" << p->color << " ";
	}
}

void RBT::INORDER(Node *p)
{
	if (p != nullptr)
	{
		INORDER(p->left);
		cout << p->data << ":2" << p->color << " ";
		INORDER(p->right);
	}
}

void RBT::preorder()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		PREORDER(root);
}

void RBT::postorder()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		POSTORDER(root);
}

void RBT::inorder()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		INORDER(root);
}

void RBT::insert(int value)
{
	Node *n = new Node;
	n->left = nullptr;
	n->right = nullptr;
	n->data = value;
	n->color = 'R';
	n->count = 0;

	if (root == nullptr)
	{
		n->color = 'B';
		root = n;
	}

	else
	{
		Node *g = root;
		Node *p = root;
		Node *c = root;

		while (1)
		{
			if (value < c->data) // left child case
			{
				if (c->left == nullptr) // insert the value
				{
					c->left = n;
					g = p;
					p = c;
					c = c->left;
					// cout<<"G:"<<g->data<<" ";
					// cout<<"P:"<<p->data<<" ";
					// cout<<"C:"<<c->data<<" ";
					// cout<<endl;
					break;
				}

				else
				{
					g = p;
					p = c;
					c = c->left;
				}
			}

			else // right child case
			{
				if (c->right == nullptr) // insert value
				{

					c->right = n;
					g = p;
					p = c;
					c = c->right;
					// cout<<"G:"<<g->data<<" ";
					// cout<<"P:"<<p->data<<" ";
					// cout<<"C:"<<c->data<<" ";
					// cout<<endl;
					break;
				}

				else
				{
					g = p;
					p = c;
					c = c->right;
				}
			}
		}
		if (p->color == 'R')//if parent is red
		{
			Node *u;
			if (g->data > p->data)
				u = g->right;
			else
				u = g->left;
			if (u == nullptr || u->color == 'B')//if uncle is black
			{
				if (c->data > p->data && p->data < g->data ) //N is added to right of left child of grandparent
				{
					g->left=c;
					c->left=p;
					p->right=nullptr;
					c=p;
					p=g->left;
				}
				else if(c->data < p->data && p->data > g->data) //N is added to left of right child of grandparent
				{
					g->right=c;				
					c->right=p;
					p->left=nullptr;
					c=p;
					p=g->right;
				}
				if(c->data<p->data && p->data<g->data){
					
				}

			}
			else //if uncle is red
			{
				u->color = 'B';
				p->color = 'B';
				g->color = 'R';
				if (root->color == 'R')
					root->color = 'B';
			}
		}
	}
}