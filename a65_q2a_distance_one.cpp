#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int ans = 1;
    vector <int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = i - k; j >= 1; j--) dp[i] = (dp[i] + dp[j]) % MOD;
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans;
    return 0;
}