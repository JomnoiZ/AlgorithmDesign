#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 505;
const int MOD = 1997;

int dp[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = (dp[i - 1][j] * j % MOD + dp[i - 1][j - 1]) % MOD;
        }
    }
    cout << dp[n][k];
    return 0;
}