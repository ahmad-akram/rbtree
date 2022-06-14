#include "Node.h"

class RBT
{
	Node* root;
	void INORDER(Node* p);
	void POSTORDER(Node* p);
	void PREORDER(Node* p);
public:
	RBT(){
		root=nullptr;
	}
	void insert(int value);
	void inorder();
	void postorder();
	void preorder();
	
};

void RBT::PREORDER(Node* p)
{
	if (p!=nullptr)
	{
		cout << p->data << " ";
		PREORDER(p->left);
		PREORDER(p->right);
		
	}
}

void RBT::POSTORDER(Node* p)
{
	if (p!=nullptr)
	{
		POSTORDER(p->left);
		POSTORDER(p->right);
		cout << p->data << " ";
	}
}

void RBT::INORDER(Node* p)
{
	if (p!=nullptr)
	{
		INORDER(p->left);
		cout << p->data << " ";
		INORDER(p->right);
	}
}

void RBT::preorder()
{
	if (root == nullptr)
		cout << "Tree is empty"  << endl;
		
	else
		PREORDER(root);
}


void RBT::postorder()
{
	if (root == nullptr)
		cout << "Tree is empty"  << endl;
		
	else
		POSTORDER(root);
}


void RBT::inorder()
{
	if (root == nullptr)
		cout << "Tree is empty"  << endl;
		
	else
		INORDER(root);
}

void RBT::insert(int value)
{
	Node *n = new Node;
	n->left = nullptr;
	n->right = nullptr;
	n->data = value;
	n->color='R';
	n->count=0;

	
	if (root == nullptr)
	{
		n->color='B';
		root = n;
	}
	
	else
	{
		Node*p=root;
		Node*t = root;
		
		while(1)
		{
			if (value<t->data)	//left child case
			{
				if (t->left==nullptr)	//insert the value 
				{
					t->left = n;
					break;
				}
				
				else
				{
					t = t->left;
				}
			}
			
			else				//right child case
			{
				if (t->right == nullptr)	//insert value
				{
					t->right = n;
					break;
				}
				
				else
				{
					t=t->right;
				}
				
			}
				
		}
	}
	
}