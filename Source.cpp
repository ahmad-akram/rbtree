#include "RedBlackTree.h"
using namespace std;

int main()
{
	RBT bst1;
	
	bst1.insert(20);
	bst1.insert(10);
	bst1.insert(30);
	bst1.insert(5);
	bst1.insert(15);
	bst1.insert(3);
	bst1.insert(7);
	bst1.insert(6);
	bst1.insert(1);
	bst1.insert(25);
	bst1.insert(100);
	bst1.insert(155);
	bst1.insert(9);
	bst1.insert(8);
	bst1.insert(23);
	bst1.insert(24);
	
	bst1.postorder();
		
	
	return 0;
}