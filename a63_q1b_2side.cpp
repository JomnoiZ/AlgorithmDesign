#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, w, k;
    cin >> n >> w >> k;

    vector <int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> r[i];

    if (k == n) {
        vector <vector <int>> dp(n + 1, vector <int> (2));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[max(0, i - w - 1)][1] + l[i]);
            dp[i][1] = max(dp[i - 1][1], dp[max(0, i - w - 1)][0] + r[i]);
        }
        cout << max(dp[n][0], dp[n][1]);
    }
    else {
        vector <vector <vector <int>>> dp(n + 1, vector <vector <int>> (2, vector <int> (2)));
        for (int j = 1; j <= k; j++) {
            int now = j % 2, pre = now ^ 1;
            for (int i = 1; i <= n; i++) {
                dp[i][now][0] = max(dp[i - 1][now][0], dp[max(0, i - w - 1)][pre][1] + l[i]);
                dp[i][now][1] = max(dp[i - 1][now][1], dp[max(0, i - w - 1)][pre][0] + r[i]);
            }
        }
        cout << max(dp[n][k % 2][0], dp[n][k % 2][1]);
    }
    return 0;
}