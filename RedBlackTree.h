#include "Node.h"

class RBT
{
	Node *root;
	void NLR(Node *p);
	void LNR(Node *p);
	void LRN(Node *p);
	void NRL(Node *p);
	void RNL(Node *p);
	void RLN(Node *p);

public:
	RBT()
	{
		root = nullptr;
	}
	void insert(int value);
	void nlr();
	void lnr();
	void lrn();
	void nrl();
	void rnl();
	void rln();
};
void RBT::NLR(Node *p)
{
	if (p != nullptr)
	{
		cout << p->data << ":" << p->color << " ";
		NLR(p->left);
		NLR(p->right);
	}
}

void RBT::LNR(Node *p)
{
	if (p != nullptr)
	{
		NLR(p->left);
		cout << p->data << ":" << p->color << " ";
		NLR(p->right);
	}
}

void RBT::LRN(Node *p)
{
	if (p != nullptr)
	{
		LRN(p->left);
		LRN(p->right);
		cout << p->data << ":2" << p->color << " ";
	}
}
void RBT::NRL(Node *p)
{
	if (p != nullptr)
	{
		cout << p->data << ":" << p->color << " ";
		NRL(p->right);
		NRL(p->left);
	}
}

void RBT::RNL(Node *p)
{
	if (p != nullptr)
	{
		RNL(p->right);
		cout << p->data << ":" << p->color << " ";
		RNL(p->left);
	}
}

void RBT::RLN(Node *p)
{
	if (p != nullptr)
	{
		RLN(p->right);
		RLN(p->left);
		cout << p->data << ":2" << p->color << " ";
	}
}

void RBT::nlr()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		NLR(root);
}

void RBT::lnr()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		LNR(root);
}

void RBT::lrn()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		LRN(root);
}
void RBT::nrl()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		NRL(root);
}

void RBT::rnl()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		RNL(root);
}

void RBT::rln()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		RLN(root);
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
		Node *gg = root;
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
					gg = g;
					g = p;
					p = c;
					c = c->left;
					//cout<<"GG:"<<gg->data<<" ";
					//cout<<"G:"<<g->data<<" ";
					//cout<<"P:"<<p->data<<" ";
					//cout<<"C:"<<c->data<<" ";
					//cout<<endl;
					break;
				}

				else
				{
					gg = g;
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
					gg=g;
					g = p;
					p = c;
					c = c->right;
					// cout<<"GG:"<<gg->data<<" ";
					// cout<<"G:"<<g->data<<" ";
					// cout<<"P:"<<p->data<<" ";
					// cout<<"C:"<<c->data<<" ";
					// cout<<endl;
					break;
				}

				else
				{
					gg=g;
					g = p;
					p = c;
					c = c->right;
				}
			}
		}
		if (p->color == 'R') // if parent is red
		{
			Node *u;
			if (g->data > p->data)
				u = g->right;
			else
				u = g->left;
			if (u == nullptr || u->color == 'B') // if uncle is black
			{
				if (c->data > p->data && p->data < g->data) // N is added to right of left child of grandparent
				{
					g->left = c;
					c->left = p;
					p->right = nullptr;
					c = p;
					p = g->left;
				}
				if (c->data < p->data && p->data > g->data) // N is added to left of right child of grandparent
				{
					g->right = c;
					c->right = p;
					p->left = nullptr;
					c = p;
					p = g->right;
				}
				if (c->data < p->data && p->data < g->data)
				{
					if(gg==root){
						Node* t=p->right;
						root=p;
						p->right=g;
						g->left=t;
					}
					else{
						if(gg->data>g->data){

						}
						else{

						}
					}
				}
				if (c->data > p->data && p->data > g->data)
				{
					if(gg==root){
						Node* t=p->left;
						root=p;
						p->left=g;
						g->right=t;
					}
					else{
						if(gg->data>g->data){

						}
						else{

						}
					}
				}
			}
			else // if uncle is red
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