#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 505;

int A[MAX_N], dp[MAX_N][MAX_N];

int solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l >= r) return dp[l][r] = 0;
    
    dp[l][r] = max(0, solve(l + 1, r - 1) + A[l] * A[r]);
    for (int mid = l; mid < r; mid++) {
        dp[l][r] = max(dp[l][r], solve(l, mid) + solve(mid + 1, r));
    }
    return dp[l][r];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> A[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(1, n);
    return 0;
}