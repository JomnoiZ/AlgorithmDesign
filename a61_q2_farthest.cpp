#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
const int INF = 1e9 + 7; 

vector <pair <int, int>> graph[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int w;
            cin >> w;

            if (w != -1) graph[i].emplace_back(j, w);
        }
    }

    for (int i = 1; i <= N; i++) dist[i] = INF;

    priority_queue <pair <int, int>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u] == true) continue;
        visited[u] = true;

        for (auto [v, w] : graph[u]) {
            if (visited[v] == false and dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(-dist[v], v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) {
            ans = -1;
            break;
        }
        else ans = max(ans, dist[i]);
    }
    cout << ans;
    return 0;
}