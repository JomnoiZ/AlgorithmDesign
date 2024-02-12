#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector <vector <long long>> dp(N + 1, vector <long long> (N + 1));
    for (int n = 0; n <= N; n++) {
        for (int k = 0; k <= n; k++) {
            if (k == 0 or k == n) dp[n][k] = 1;
            else dp[n][k] = dp[n - 1][k - 1] + dp[n - 1][k];
        }
    }
    cout << dp[N][K];
    return 0;
}