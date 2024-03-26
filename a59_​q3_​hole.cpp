#include <bits/stdc++.h>
using namespace std;

const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, a, b;
    cin >> N >> a >> b;

    vector <vector <bool>> hole(1001, vector <bool> (1001));
    while (N--) {
        int x, y;
        cin >> x >> y;

        hole[x][y] = true;
    }

    priority_queue <tuple <int, int, int>> pq;
    vector <vector <int>> dist(1001, vector <int> (1001, INF));
    vector <vector <bool>> visited(1001, vector <bool> (1001));

    int ans = INF;
    pq.emplace(0, a, b);
    dist[a][b] = 0;
    while (!pq.empty()) {
        auto [di, ux, uy] = pq.top();
        pq.pop();

        if (visited[ux][uy] == true) continue;
        visited[ux][uy] = true;

        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 1 or vx > 1000 or vy < 1 or vy > 1000) {
                ans = min(ans, dist[ux][uy]);
                continue;
            }

            if (visited[vx][vy] == false and dist[ux][uy] + hole[vx][vy] < dist[vx][vy]) {
                dist[vx][vy] = dist[ux][uy] + hole[vx][vy];
                pq.emplace(-dist[vx][vy], vx, vy);
            }
        }
    }
    cout << ans;
    return 0;
}