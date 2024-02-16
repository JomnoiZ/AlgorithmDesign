#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const long long INF = 1e18 + 7;

long long a[MAX_N];
long long dp[MAX_N][MAX_N];

long long solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 0;

    dp[l][r] = INF;
    for (int m = l; m < r; m++) {
        dp[l][r] = min(dp[l][r], solve(l, m) + solve(m + 1, r) + a[l] * a[m + 1] * a[r + 1]);
    }
    return dp[l][r];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n + 1; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    
    cout << solve(1, n);
    return 0;
}