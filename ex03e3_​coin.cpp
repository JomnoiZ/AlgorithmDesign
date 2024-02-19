#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector <int> a(N);
    for (auto &x : a) cin >> x;

    vector <int> dp(M + 1);
    for (int i = 1; i <= M; i++) {
        dp[i] = INF;
        for (int j = 0; j < N; j++) {
            if (i - a[j] >= 0) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    cout << dp[M];
    return 0;
}