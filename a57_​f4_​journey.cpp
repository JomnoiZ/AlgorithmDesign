#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <vector <int>> w(N, vector <int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> w[i][j];
        }
    }

    vector <vector <int>> dp(N, vector <int> (1<<N, -INF));
    dp[0][1] = 0;
    for (int mask = 0; mask < (1<<N); mask++) {
        for (int i = 0; i < N; i++) {
            if (!(mask & (1<<i))) continue;
            for (int j = 0; j < N; j++) {
                if (mask & (1<<j)) continue;
                dp[j][mask | (1<<j)] = max(dp[j][mask | (1<<j)], dp[i][mask] + w[i][j]);
            }
        }
    }
    cout << dp[N - 1][(1<<N) - 1];
    return 0;
}