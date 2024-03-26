#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <vector <pair <int, int>>> graph(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int w;
            cin >> w;

            if (w > 0) graph[i].emplace_back(j, w);
        }
    }

    vector <int> dist(N + 1, INF);

    priority_queue <pair <int, int>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;
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

    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, dist[i]);

    if (ans == INF) ans = -1;
    cout << ans;
    return 0;
}