#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5005;

int a[MAX_N];
int dp[MAX_N][MAX_N];

int solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l > r) return 0;
    if (l == r) return dp[l][r] = a[l];

    return dp[l][r] = max({solve(l + 2, r) + max(a[l], a[l + 1]), 
                           solve(l, r - 2) + max(a[r - 1], a[r]), 
                           solve(l + 1, r - 1) + max(a[l], a[r])});
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, sizeof(dp), -1);
    cout << solve(1, n);
    return 0;
}