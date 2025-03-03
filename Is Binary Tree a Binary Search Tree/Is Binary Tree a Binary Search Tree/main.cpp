#include <fstream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

struct Node {
    int value;
    int left, right;
    Node(int v) : value(v), left(-1), right(-1) {}
};

struct StackElem {
    int idx;
    long long lo, hi;
    StackElem(int idx, long long lo, long long hi) : idx(idx), lo(lo), hi(hi) {}
};

int main() {
    ifstream fin("bst.in");
    ofstream fout("bst.out");
    int n;
    fin >> n;

    // Создаём массив узлов.
    vector<Node> tree;
    tree.reserve(n);

    // Чтение корня.
    int rootVal;
    fin >> rootVal;
    tree.push_back(Node(rootVal));

    // Читаем оставшиеся n-1 узлов.
    // Каждая строка описывает: значение узла, номер строки (p) с описанием родителя и букву 'L'/'R'.
    // Родитель определяется как узел, описанный в строке с номером p (с нумерацией с нуля),
    // поэтому индекс родителя в массиве равен (p - 1).
    for (int i = 0; i < n - 1; i++) {
        int value, p;
        char c;
        fin >> value >> p >> c;
        tree.push_back(Node(value));
        int parentIdx = p - 1;
        if (c == 'L') {
            tree[parentIdx].left = tree.size() - 1;
        }
        else { // c == 'R'
            tree[parentIdx].right = tree.size() - 1;
        }
    }

    // Проверяем, является ли дерево BST.
    // Для левого поддерева допустим диапазон значений: [lo, cur_value - 1],
    // для правого: [cur_value, hi].
    bool isBST = true;
    stack<StackElem> st;
    st.push(StackElem(0, numeric_limits<long long>::min(), numeric_limits<long long>::max()));

    while (!st.empty() && isBST) {
        StackElem cur = st.top();
        st.pop();

        int idx = cur.idx;
        long long curVal = tree[idx].value;
        if (curVal < cur.lo || curVal > cur.hi) {
            isBST = false;
            break;
        }

        if (tree[idx].left != -1) {
            long long newHi = curVal - 1;
            st.push(StackElem(tree[idx].left, cur.lo, newHi));
        }
        if (tree[idx].right != -1) {
            long long newLo = curVal;
            st.push(StackElem(tree[idx].right, newLo, cur.hi));
        }
    }

    fout << (isBST ? "YES" : "NO");

    fin.close();
    fout.close();
    return 0;
}