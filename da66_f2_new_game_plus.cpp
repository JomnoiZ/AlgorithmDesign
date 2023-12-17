#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 505;
const int MOD = 1e8 + 7;

int table[MAX_N][MAX_N], dp[MAX_N][MAX_N][3];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) cin >> table[i][j];

    for (int i = 1; i <= R; i++) if (table[i][1] == 0) {
        if (i - 1 >= 0 and table[i - 1][2] == 0) dp[i - 1][2][0]++;
        if (table[i][2] == 0) dp[i][2][1]++;
        if (i + 1 <= R and table[i + 1][2] == 0) dp[i + 1][2][2]++;
    }
    for (int j = 2; j < C; j++) for (int i = 1; i <= R; i++) if (table[i][j] == 0) {
        if (i - 1 >= 0 and table[i - 1][j + 1] == 0) dp[i - 1][j + 1][0] = (dp[i - 1][j + 1][0] + dp[i][j][1] + dp[i][j][2]) % MOD;
        if (table[i][j + 1] == 0) dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i][j][0] + dp[i][j][2]) % MOD;
        if (i + 1 <= R and table[i + 1][j + 1] == 0) dp[i + 1][j + 1][2] = (dp[i + 1][j + 1][2] + dp[i][j][0] + dp[i][j][1]) % MOD;
    }
    
    int ans = 0;
    for (int i = 1; i <= R; i++) ans = (ans + dp[i][C][0] + dp[i][C][1] + dp[i][C][2]) % MOD;
    cout << ans;
    return 0;
}