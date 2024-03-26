#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, t[3];
    cin >> n >> t[0] >> t[1] >> t[2];

    vector <vector <int>> graph(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        while (k--) {
            int e;
            cin >> e;

            graph[i].push_back(e);
        }
    }
    
    vector <vector <int>> dist(3, vector <int> (n + 1, INF));
    for (int i = 0; i < 3; i++) {
        queue <int> q;
        q.push(t[i]);
        dist[i][t[i]] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &v : graph[u]) {
                if (dist[i][v] == INF) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) ans = min(ans, max({dist[0][i], dist[1][i], dist[2][i]}));
    cout << ans;
    return 0;
}