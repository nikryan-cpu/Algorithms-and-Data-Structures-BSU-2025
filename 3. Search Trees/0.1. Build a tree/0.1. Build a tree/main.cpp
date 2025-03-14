#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class BinaryTree {
private:
	Node* root;
public:
	BinaryTree(Node* root) {
		this->root = root;
	}
	Node* add(Node* node, int data) {
		if (node == nullptr) {
			return new Node(data);
		}
		if (data < node->data)
			node->left = add(node->left, data);
		else if (data > node->data)
			node->right = add(node->right, data);
		return node;
	}

	void print(Node* node, ofstream& out) {
		if (node == nullptr)
			return;
		out << node->data << '\n';
		print(node->left, out);
		print(node->right, out);
	}
};



int main() {
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int tmp;
	in >> tmp;
	Node* root = new Node(tmp);
	BinaryTree* tree = new BinaryTree(root);
	while (in >> tmp) {
		tree->add(root, tmp);
	}
	in.close();
	tree->print(root, out);
}