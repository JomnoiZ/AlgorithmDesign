#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 705;
const int INF = 1e9 + 7;

vector <int> graph[MAX_N];
int c[MAX_N][MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n >> c[1][2];
    c[2][1] = c[1][2];

    graph[1].push_back(2);
    graph[2].push_back(1);
    for (int i = 3; i <= n; i++) {
        int k;
        cin >> k;

        while (k--) {
            int a;
            cin >> a >> c[i][a];
            c[a][i] = c[i][a];

            graph[i].push_back(a);
            graph[a].push_back(i);
        }

        for (int j = 1; j <= i; j++) dist[j] = INF, visited[j] = false;

        priority_queue <pair <int, int>> pq;
        pq.emplace(0, 1);
        dist[1] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u] == true) continue;
            visited[u] = true;

            if (u == 2) break;

            for (auto &v : graph[u]) {
                if (visited[v] == false and dist[u] + c[u][v] < dist[v]) {
                    dist[v] = dist[u] + c[u][v];
                    pq.emplace(-dist[v], v);
                }
            }
        }
        cout << dist[2] << ' ';
    }
    return 0;
}