#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector <int> dist(n, INF), c(n), st(k);
    vector <bool> visited(n);
    vector <vector <int>> graph(n);
    for (auto &x : st) cin >> x;
    for (auto &x : c) cin >> x;
    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    priority_queue <pair <int, int>> pq;
    for (auto &x : st) {
        dist[x] = c[x];
        pq.emplace(-c[x], x);
    }

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u] == true) continue;
        visited[u] = true;

        for (auto &v : graph[u]) {
            if (visited[v] == false and dist[u] + c[v] < dist[v]) {
                dist[v] = dist[u] + c[v];
                pq.emplace(-dist[v], v);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dist[i]);
    cout << ans;
    return 0;
}