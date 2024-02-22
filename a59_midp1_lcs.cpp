#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

char a[MAX_N], b[MAX_N];
int dp[MAX_N][MAX_N];
stack <char> ans;

void solve(int n, int m) {
    if (n == 0 or m == 0) return;
    if (dp[n - 1][m - 1] + 1 == dp[n][m]) {
        ans.push(a[n - 1]);
        solve(n - 1, m - 1);
    }
    else if (dp[n - 1][m] == dp[n][m]) solve(n - 1, m);
    else solve(n, m - 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    cin >> a >> b;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> dp[i][j];
        }
    }

    solve(n, m);

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    return 0;
}