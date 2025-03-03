#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    // Проверка открытия файлов
    if (!in.is_open() || !out.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    int n;
    in >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        in >> a[i];
    }

    vector<int> lis;
    for (int x : a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        }
        else {
            *it = x;
        }
    }

    out << lis.size() << endl;

    // Файлы закроются автоматически при выходе из области видимости
    return 0;
}