#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    int ans = 0;
    vector <vector <int>> dp(R + 1, vector <int> (C + 1));
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            char a;
            cin >> a;

            if (a == '1') dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}