#pragma once

template <typename K, typename E>
class TNode {
private:
	// A subset of the main data used to generate a unique number for the node
	K key;
	// The actual data that the node stores e.g. ID, Name, Email
	E data

	// Pointers of the two kids. Go left if new data key < key for this node, else go right
	TNode* pLeft, * pRight;

public:
	bool insert(K key, E data) {
		return false;
	}

	void setData(E data) { this->data = data; }
	E getData() const { return this->data; }
};