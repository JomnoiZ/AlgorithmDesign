#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const long long INF = 1e18 + 7;

long long a[MAX_N];
long long dp[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n + 1; i++) cin >> a[i];

    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n; l++, r++) {
            dp[l][r] = INF;
            for (int m = l; m < r; m++) {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r] + a[l] * a[m + 1] * a[r + 1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}