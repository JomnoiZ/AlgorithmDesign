#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <vector <int>> dp(N + 1, vector <int> (N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            int a;
            cin >> a;

            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, dp[N][i]);
    
    cout << ans << '\n';
    return 0;
}