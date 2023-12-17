#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6 + 3;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector <int> s(k);
    for (auto &x : s) cin >> x;

    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i - s[j] >= 0) dp[i] = (dp[i] + dp[i - s[j]]) % MOD;
        }
    }
    cout << dp[n];
    return 0;   
}