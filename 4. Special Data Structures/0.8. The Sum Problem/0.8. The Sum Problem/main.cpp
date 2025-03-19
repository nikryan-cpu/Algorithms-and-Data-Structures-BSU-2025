#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

struct Node {
	int64_t data;
	Node* left;
	Node* right;
	int l;
	int r;
};
class SegmentTree {
private:
	Node* root;
public:
	SegmentTree(vector<int>& elements) {
		root = new Node;
		root->l = 0;
		root->r = elements.size();
		if (root->r > root->l + 1) {
			root->left = build(root->left, elements, root->l, root->r, true);
			root->right = build(root->right, elements, root->l, root->r, false);
			root->data = root->left->data + root->right->data;
		}
		else {
			root->data = elements[root->l];
			root->left = nullptr;
			root->right = nullptr;
		}
	}
	int64_t findSum(int l, int r) {		//[l,r)
		if (l >= r)
			return 0;
		return realFindSum(root, l, r);
	}
	void modify(int index, int difference) {
		realModify(this->root, index, difference);
	}
private:
	Node* build(Node* current, vector<int>& elements, int l, int r, bool isLeft) {
		current = new Node();
		switch (isLeft) {
			case true: {
				current->l = l;
				current->r = (l + r) / 2;
				break;
			}
			case false: {
				current->l = (l + r) / 2;
				current->r = r;
			}
		}
		if (current->r == current->l + 1) {
			current->data = elements[current->l];
			return current;
		}
		current->left = build(current->left, elements, current->l, current->r, true);
		current->right = build(current->right, elements, current->l, current->r, false);
		current->data = current->left->data + current->right->data;
		return current;
	}

	void realModify(Node* current, int index, int difference) {
		current->data += difference;
		if (current->r == current->l + 1)
			return;
		bool left = index < (current->l + current->r) / 2;
		switch (left) {
			case true: {
				realModify(current->left, index, difference);
				break;
			}
			case false: {
				realModify(current->right, index, difference);
				break;
			}
		}
	}

	int64_t realFindSum(Node* current, int left, int right) {
		if (current->l == left and current->r == right)
			return current->data;
		int medium = (current->l + current->r) / 2;
		if (left >= current->l and right <= medium)
			return realFindSum(current->left, left, right);
		else if(left >= medium and right <= current->r)
			return realFindSum(current->right, left, right);
		else {
			return realFindSum(current->left, left, medium) + realFindSum(current->right, medium, right);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string request;
	int n, q, index, difference, left, right;
	cin >> n;
	vector<int> elements(n);
	for (int i = 0; i < n; i++) {
		cin >> elements[i];
	}
	SegmentTree tree(elements);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> request;
		if(request == "Add"){
			cin >> index >> difference;
			tree.modify(index, difference);
		}
		else if(request == "FindSum"){
			cin >> left >> right;
			cout << tree.findSum(left, right) << '\n';
		}
	}
}