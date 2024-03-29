#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10005;

vector <int> graph[MAX_N];
bool visited[MAX_N];

void dfs(int u) {
    if (visited[u] == true) return;
    visited[u] = true;
    
    for (auto v : graph[u]) dfs(v);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            ans++;
            dfs(i);
        }
    }
    cout << ans;
    return 0;
}