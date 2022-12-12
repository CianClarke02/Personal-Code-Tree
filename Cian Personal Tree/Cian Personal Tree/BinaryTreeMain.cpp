#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "BinaryTreeP.h"
#include "Utilities.h"
#include "Utils.h"
using namespace std;

int main()
{
	BinaryTree<int> tree;
	tree.add(8);
	tree.add(3);
	tree.add(6);
	tree.add(7);
	tree.add(1);
	tree.add(9);
	tree.add(4);
	cout << tree.count() << endl;
	printBT(tree.root);

	return 0;
}