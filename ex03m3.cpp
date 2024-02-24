#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector <int> p(N + 1);
    for (int i = 1; i <= N; i++) cin >> p[i];

    vector <int> dp(N + 1);
    for (int i = 1; i <= min(N, K + 1); i++) dp[i] = p[i];
    for (int i = K + 2; i <= N; i++) {
        dp[i] = INF;
        for (int j = i; j >= max(1, i - 2 * K - 1); j--) {
            dp[i] = min(dp[i], dp[j] + p[i]);
        }
    }

    int ans = INF;
    for (int i = max(1, N - K); i <= N; i++) ans = min(ans, dp[i]);
    cout << ans;
    return 0;
}