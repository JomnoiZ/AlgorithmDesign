#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000003;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector <int> c(k);
    for (auto &x : c) cin >> x;

    vector <int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i - c[j] >= 0) dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}