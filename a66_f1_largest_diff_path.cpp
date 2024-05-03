#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2005;
const int INF = 1e9 + 7;

int ans;
int c[MAX_N], dp[MAX_N];
vector <int> graph[MAX_N];

int dfs(const int &u) {
    if (dp[u] != -INF) return dp[u];

    int res = -INF;
    for (auto v : graph[u]) res = max(res, dfs(v));
    ans = max(ans, -c[u] + res);
    res = max(res, c[u]);
    return dp[u] = res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> c[i];
    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    for (int i = 0; i < n; i++) dp[i] = -INF;
    for (int i = 0; i < n; i++) dfs(i);

    cout << ans;
    return 0;
}