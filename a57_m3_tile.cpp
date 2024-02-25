#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector <vector <int>> dp(N + 1, vector <int> (M + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        for (int j = M; j >= 0; j--) {
            for (int k = 1; k <= 100; k++) {
                if (j - k * k >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - k * k] + (a - k) * (a - k));
                }
            }
        }
    }

    if (dp[N][M] == INF) dp[N][M] = -1;
    cout << dp[N][M];
    return 0;
}