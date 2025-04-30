#pragma comment(linker, "/STACK:524288000")  // 500 ла
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) : data(data), left(nullptr), right(nullptr) {}
};


class Tree {
	Node* root;
public:

	Tree(Node* root) : root(root) {}
	Tree(vector<int> preorder) {
		this->root = new Node(preorder[0]);
		constructBST(preorder, preorder.size(), 1, root, INT_MIN, INT_MAX);
	}

	void inorder(ofstream& out) {
		privateInorder(root, out);
	}

	void postorder(ofstream& out) {
		privatePostorder(root, out);
	}
private:
	int constructBST(vector<int>& preorder, int n, int pos, Node* curr, int left, int right) {
		if (pos == n or preorder[pos] < left or preorder[pos] > right)
			return pos;
		//Left
		if (preorder[pos] < curr->data) {
			curr->left = new Node(preorder[pos]);
			pos++;
			pos = constructBST(preorder, n, pos, curr->left, left, curr->data - 1);
		}

		if (pos == n or preorder[pos] < left or preorder[pos] > right)
			return pos;
		//Right
		if (preorder[pos] >= curr->data) {
			curr->right = new Node(preorder[pos]);
			pos++;
			pos = constructBST(preorder, n, pos, curr->right, curr->data, right);
		}
		return pos;
	}

	void privateInorder(Node* curr, ofstream& out) {
		if (curr == nullptr)
			return;
		privateInorder(curr->left, out);
		out << curr->data << ' ';
		privateInorder(curr->right, out);
	}

	void privatePostorder(Node* curr, ofstream& out) {
		if (curr == nullptr)
			return;
		privatePostorder(curr->left, out);
		privatePostorder(curr->right, out);
		out << curr->data << ' ';
	}
};

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	vector<int> preorder(n);
	for (int i = 0; i < n; i++) {
		in >> preorder[i];
	}

	Tree tree(preorder);
	tree.postorder(out);
	out << '\n';
	tree.inorder(out);
}