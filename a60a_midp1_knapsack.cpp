#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 505;

int v[MAX_N], w[MAX_N];
int V[MAX_N][MAX_N];
vector <int> ans;

void solve(int n, int m) {
    if (n == 0) return;
    if (V[n - 1][m] == V[n][m]) solve(n - 1, m);
    else {
        ans.push_back(n);
        solve(n - 1, m - w[n]);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> V[i][j];
        }
    }

    solve(n, m);

    cout << ans.size() << '\n';
    for (auto v : ans) cout << v << ' ';
    return 0;
}