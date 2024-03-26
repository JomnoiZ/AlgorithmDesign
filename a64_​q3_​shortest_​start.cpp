#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k, V;
    cin >> n >> m >> k >> V;

    vector <int> st(k);
    for (auto &x : st) cin >> x;

    vector <vector <pair <int, int>>> graph(n);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[b].emplace_back(a, w);
    }

    vector <int> dist(n, INF);

    priority_queue <pair <int, int>> pq;
    pq.emplace(0, V);
    dist[V] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(-dist[v], v);
            }
        }
    }

    int ans = INF;
    for (auto &x : st) ans = min(ans, dist[x]);
    cout << ans;
    return 0;
}