#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector <int> dp(n + 1, -INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i - a >= 0) dp[i] = max(dp[i], dp[i - a] + 1);
        if (i - b >= 0) dp[i] = max(dp[i], dp[i - b] + 1);
        if (i - c >= 0) dp[i] = max(dp[i], dp[i - c] + 1);
    }
    cout << dp[n];
    return 0;
}