#include "RedBlackTree.h"
using namespace std;

int main()
{
	RBT bst1;
	
	bst1.insert(20);
	bst1.insert(30);
	bst1.insert(10);
	bst1.insert(11);
	bst1.insert(12);


	
	bst1.inorder();
		
	
	return 0;
}