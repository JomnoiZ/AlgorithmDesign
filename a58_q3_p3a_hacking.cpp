#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector <int> s(k), c(n);
    vector <vector <int>> graph(n);
    for (int i = 0; i < k; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector <int> dist(n, INF);
    vector <bool> visited(n, false);

    priority_queue <pair <int, int>> pq;
    for (int i = 0; i < k; i++) {
        dist[s[i]] = c[s[i]];
        pq.emplace(-c[s[i]], s[i]);
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u] == true) continue;
        visited[u] = true;

        for (auto v : graph[u]) {
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