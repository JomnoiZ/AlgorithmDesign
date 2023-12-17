#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

vector <int> graph[MAX_N];
bool visited[MAX_N];

bool dfs(int u, int p) {
    if (visited[u] == true) return true;
    visited[u] = true;

    for (auto v : graph[u]) {
        if (v == p) continue;

        if (dfs(v, u) == true) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            visited[i] = false;
            graph[i].clear();
        }

        while (m--) {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false and dfs(i, -1) == true) {
                ok = true;
                break;
            }
        }

        if (ok == true) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}