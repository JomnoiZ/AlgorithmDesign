#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5005;

int ans;
int b[MAX_N], q[MAX_N];
vector <int> graph[MAX_N];
bool visited[MAX_N];

void dfs(int u, int x) {
    if (visited[u] == true) return;
    visited[u] = true;

    ans += b[u];
    for (auto v : graph[u]) dfs(v, x);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
    }
    for (int i = 1; i <= k; i++) cin >> q[i];
    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    for (int i = 1; i <= k; i++) {
        dfs(q[i], q[i]);
        cout << sum - ans << ' ';
    }
    return 0;
}