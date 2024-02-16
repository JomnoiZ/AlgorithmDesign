#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <vector <int>> dp(n + 1, vector <int> (m + 1, -INF));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int a;
            cin >> a;

            if (i == 1 and j == 1) dp[i][j] = a;
            else {
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]}) + a;
                dp[i][j] = max({dp[i][j], dp[i - 1][j - 1] + 2 * a});
            }
        }
    }
    cout << dp[n][m];
    return 0;
}