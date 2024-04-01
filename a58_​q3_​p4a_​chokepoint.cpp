#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int n;
vector <int> graph[MAX_N];
int sz[MAX_N];
long long dp[MAX_N];

void dfs(int u, int p) {
    int sum = 0;
    sz[u] = 1;
    dp[u] = n - 1;
    for (auto v : graph[u]) if (v != p) {
        dfs(v, u);
        sz[u] += sz[v];
        dp[u] += 1ll * sum * sz[v];
        sum += sz[v];
    }
    dp[u] += 1ll * (sz[u] - 1) * (n - sz[u]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++) cout << dp[i] << '\n';
    return 0;
}