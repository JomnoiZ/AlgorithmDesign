#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8 + 7;

vector <vector <int>> multiply(vector <vector <int>> a, vector <vector <int>> b) {
    vector <vector <int>> c(4, vector <int> (4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                c[i][j] = (c[i][j] + 1ll * a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

vector <vector <int>> power(vector <vector <int>> &a, long long n) {
    if (n == 1) return a;

    vector <vector <int>> c = power(a, n / 2);
    c = multiply(c, c);
    if (n % 2 == 1) c = multiply(c, a);
    return c;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long n;
    cin >> n;

    if (n == 1) cout << 1;
    else if (n == 2) cout << 4;
    else {
        vector <vector <int>> dp(4, vector <int> (4));
        dp[0][0] = 1;
        dp[2][0] = 1;
        dp[0][1] = 1;
        dp[1][2] = 1;
        dp[3][2] = 1;
        dp[1][3] = 1;
        dp[3][3] = 1;
        vector <vector <int>> res = power(dp, n - 2);

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                ans = (ans + res[i][j]) % MOD;
            }
        }
        cout << ans;
    }
    return 0;
}