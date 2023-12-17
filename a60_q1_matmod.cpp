#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, K;
    vector <vector <vector <int>>> a(31, vector <vector <int>> (2, vector <int> (2, 0)));

    cin >> n >> K;
    cin >> a[0][0][0] >> a[0][0][1] >> a[0][1][0] >> a[0][1][1];

    for (int t = 1; t < 31; t++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    a[t][i][j] = (a[t][i][j] + a[t - 1][i][k] * a[t - 1][k][j]) % K;
                }
            }
        }
    }

    vector <vector <int>> res(2, vector <int> (2, 0)), tmp(2, vector <int> (2, 0));
    res[0][0] = res[1][1] = 1;
    for (int m = 0; m < 31; m++) {
        if (n & (1<<m)) {
            tmp[0][0] = tmp[0][1] = tmp[1][0] = tmp[1][1] = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        tmp[i][j] = (tmp[i][j] + res[i][k] * a[m][k][j]) % K;
                    }
                }
            }
            res = tmp;
        }
    }
    cout << res[0][0] << ' ' << res[0][1] << ' ' << res[1][0] << ' ' << res[1][1];
    return 0;
}