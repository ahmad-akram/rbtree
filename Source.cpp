#include "RedBlackTree.h"
using namespace std;

int main()
{
	RBT bst1;
	
	bst1.insert(500);
	bst1.insert(1500);
	bst1.insert(800);
	// bst1.insert(11);
	// bst1.insert(12);


	
	bst1.inorder();
		
	
	return 0;
}