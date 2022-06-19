#include "RedBlackTree.h"
#include <fstream>
using namespace std;

int main()
{
	int input;
	RBT bst1;
	cout << "Press 1 to insert values in the tree (one by one)"
		 << "\nPress 2 for searching a value from the tree"
		 << "\nPress 3 for pre-order traversal NLR"
		 << "\nPress 4 for in-order traversal LNR"
		 << "\nPress 5 for post-order traversal LRN"
		 << "\nPress 6 for pre-order traversal 2 NRL"
		 << "\nPress 7 for in-order traversal 2 RNL"
		 << "\nPress 8 for post-order traversal 2 RLN"
		 << "\nPress 9 for displaying parent of a node present in Tree"
		 << "\nPress 10 to read integer values from the file “input.txt” to create a red-black tree"
		 << "\nPress 11 to delete all duplicate values from the tree"
		 << "\nPress 12 to destroy the complete tree"
		 << "\nPress 13 to EXIT" << endl;

	
	if (input == 1)
	{
	}
	else if (input == 2)
	{
	}
	else if (input == 3)
	{
	}
	else if (input == 4)
	{
	}
	else if (input == 5)
	{
	}
	else if (input == 6)
	{
	}
	else if (input == 7)
	{
	}
	else if (input == 8)
	{
	}
	else if (input == 9)
	{
	}
	else if (input == 10)
	{
		int input;
		ifstream myfile("input.txt");
		while (myfile >> input)
		{
			bst1.insert(input);
		}
	}
	else if (input == 11)
	{
	}
	else if (input == 12)
	{
	}
	else if (input == 13)
	{
	}
	else
	{
	}

	bst1.insert(100);
	bst1.insert(105);
	bst1.insert(95);
	bst1.insert(98);
	bst1.insert(85);
	bst1.insert(80);
	bst1.insert(90);

	return 0;
}