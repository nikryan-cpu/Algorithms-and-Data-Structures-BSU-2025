#include <iostream>
#include <fstream>

using namespace std;


struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

class BinaryTree {
private:
	Node* root;
public:
	BinaryTree(Node* root) {
		this->root = root;
	}
	Node* getRoot() {
		return this->root;
	}

	void preorderPrint(Node* current, ofstream& out) {
		if (current == nullptr)
			return;
		else {
			out << current->data << '\n';
			preorderPrint(current->left, out);
			preorderPrint(current->right, out);
		}
	}
	Node* insert(Node* current, int data) {
		if (current == nullptr) {
			current = new Node(data);
		}
		else if (data < current->data) {
			current->left = insert(current->left, data);
		}
		else if (data > current->data) {
			current->right = insert(current->right, data);
		}
		return current;
	}

	void remove(int data) {
		this->root = privateRemove(data, this->root);
	}
	
private:
	Node* bothKidsRemoving(Node* removing, Node* current) {
		if (current->left != nullptr) {
			Node* previous = current;
			current = current->left;
			while (current->left != nullptr) {
				current = current->left;
				previous = previous->left;
			}
			previous->left = current->right;
		}
		else {
			removing->right = current->right;
		}
		removing->data = current->data;
		delete current;
		return removing;
	}
	Node* privateRemove(int data, Node* current) {
		if (current == nullptr)
			return nullptr;
		if (data < current->data) {
			current->left = privateRemove(data, current->left);
			return current;
		}
		else if (data > current->data) {
			current->right = privateRemove(data, current->right);
			return current;
		}
		else {
			if (current->left == nullptr) {
				return current->right;
			}
			else if (current->right == nullptr) {
				return current->left;
			}
			else {
				return bothKidsRemoving(current, current->right);
			}
		}
	}
};



int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int delElem, tmp;
	in >> delElem;
	if (!in.eof()) {
		in >> tmp;
		Node* root = new Node(tmp);
		BinaryTree* tree = new BinaryTree(root);
		while (in >> tmp) {
			tree->insert(tree->getRoot(), tmp);
		}
		tree->remove(delElem);
		tree->preorderPrint(tree->getRoot(), out);
	}
	else
		return 0;
}