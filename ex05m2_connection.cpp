#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

vector <int> graph[MAX_N];
int dist[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        memset(dist, -1, sizeof(dist));

        int cnt = 1;
        queue <int> q;
        q.push(i);
        dist[i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] == k) break;
            for (auto v : graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    cnt++;
                    q.push(v);
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}