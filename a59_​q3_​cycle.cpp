#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int ans, start;
vector <int> graph[MAX_N];
bool visited[MAX_N];

bool dfs(int u, int p) {
    if (visited[u] == true) {
        start = u;
        return true;
    }
    visited[u] = true;
    for (auto v : graph[u]) {
        if (v == p) continue;

        if (dfs(v, u) == true) {
            ans++;
            if (start == u) return false;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, -1);
    cout << ans;
    return 0;
}