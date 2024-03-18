#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int cnt;
vector <int> graph[MAX_N];
bool visited[MAX_N];

void dfs(int u) {
    if (visited[u] == true) return;
    visited[u] = true;

    if (graph[u].size() == 1) cnt++;
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
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            if (graph[i].size() == 0) ans++;
            else {
                cnt = 0;
                dfs(i);
                if (cnt == 2) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}