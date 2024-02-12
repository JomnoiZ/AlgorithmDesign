#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> dp(n + 1, -INF);
    cin >> dp[1];
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;

        if (i - 1 >= 1) dp[i] = max(dp[i], dp[i - 1] + a);
        if (i - 2 >= 1) dp[i] = max(dp[i], dp[i - 2] + a);
        if (i - 3 >= 1) dp[i] = max(dp[i], dp[i - 3] + a);
    }
    cout << dp[n];
    return 0;
}