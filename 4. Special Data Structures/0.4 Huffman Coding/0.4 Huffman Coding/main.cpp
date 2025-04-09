#include <fstream>
#include <vector>
using namespace std;


int main() {
    ifstream in("huffman.in");
    ofstream out("huffman.out");
    ios::sync_with_stdio(false);
    in.tie(0);
    int n;
    in >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        in >> p[i];
    }
    vector<long long> new_nodes;
    long long total_length = 0;
    int i = 0, j = 0;
    for (int k = 0; k < n - 1; k++) {
        long long first, second;
        if (i < n && (j >= new_nodes.size() || p[i] <= new_nodes[j])) {
            first = p[i];
            i++;
        }
        else {
            first = new_nodes[j];
            j++;
        }
        if (i < n && (j >= new_nodes.size() || p[i] <= new_nodes[j])) {
            second = p[i];
            i++;
        }
        else {
            second = new_nodes[j];
            j++;
        }
        long long new_node = first + second;
        new_nodes.push_back(new_node);
        total_length += new_node;
    }
    out << total_length << endl;
    return 0;
}