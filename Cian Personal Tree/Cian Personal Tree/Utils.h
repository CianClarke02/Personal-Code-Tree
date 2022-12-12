#pragma once
#include <string>

template <class T>
void printBT(const std::string& prefix,/* BSTNode<T>* node,*/ bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "<--" : ">--");

		std::cout << node->getItem() << std::endl;

		printBT(prefix + (isLft ? "|  " : "   ", node->getLeft(), true))
		printBT(prefix + (isLft ? "|  " : "   ", node->getLeft(), false))
	}
}

template <class T>
void printBT(BSTNode<T>* node)
{
	printBT("", node, true);
}

void createBalancedTree(BinaryTree<int>& tree, int min, int max, int* arr)
{
	if (min < max)
	{
		int mid = (min + max) / 2;
		tree.add(arr[mid]);
		createBalancedTree(tree, min, mid, arr);
		createBalancedTree(tree, mid + 1, max, arr);
	}
}

void balance(BinaryTree<int>& tree)
{
	int* arr = tree.toArray();
	int max = tree.count();
	tree.clear();
	createBalancedTree(tree, 0, max, arr);
	delete[] arr;

};