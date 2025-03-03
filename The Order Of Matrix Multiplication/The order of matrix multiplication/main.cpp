#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

int matrix_chain_multiplication(const vector<int>& dim) {
    int n = dim.size();
    vector<vector<int>> m(n, vector<int>(n, 0));

    for (int len = 2; len < n; ++len) {
        for (int i = 1; i < n - len + 1; ++i) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = m[i][k] + m[k + 1][j] + dim[i - 1] * dim[k] * dim[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int s;
    in >> s;
    vector<int> dim;
    int a, b;
    in >> a >> b;
    dim.push_back(a);
    dim.push_back(b);
    for (int i = 1; i < s; ++i) {
        in >> a >> b;
        dim.push_back(b);
    }
    out << matrix_chain_multiplication(dim);
    return 0;
}