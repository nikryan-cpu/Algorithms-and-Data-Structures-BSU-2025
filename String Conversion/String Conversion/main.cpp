#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");

    int x, y, z;
    in >> x >> y >> z;
    string A, B;
    in >> A >> B;

    int n = A.size();
    int m = B.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Инициализация базовых случаев
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i * x; // Удаление всех символов из A
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j * y; // Вставка всех символов в B
    }

    // Заполнение таблицы DP
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                int del = dp[i - 1][j] + x;
                int ins = dp[i][j - 1] + y;
                int rep = dp[i - 1][j - 1] + z;
                dp[i][j] = min({ del, ins, rep });
            }
        }
    }

    out << dp[n][m] << endl;

    return 0;
}