#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;

int dp[2][3];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        int now = i % 2, pre = now ^ 1;

        dp[now][0] = (dp[pre][0] + dp[pre][1] + dp[pre][2]) % MOD;
        dp[now][1] = (dp[pre][0] + dp[pre][2]) % MOD;
        dp[now][2] = (dp[pre][0] + dp[pre][1]) % MOD;
    }
    cout << (dp[n % 2][0] + dp[n % 2][1] + dp[n % 2][2]) % MOD;
    return 0;
}