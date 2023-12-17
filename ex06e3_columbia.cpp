#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 7;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    vector <vector <int>> a(R + 5, vector <int> (C + 5));
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> a[i][j];
        }
    }

    vector <vector <int>> dist(R + 5, vector <int> (C + 5, INF));
    vector <vector <bool>> visited(R + 5, vector <bool> (C + 5, false));

    priority_queue <tuple <int, int, int>> pq;
    pq.emplace(0, 1, 1);
    dist[1][1] = 0;
    while (!pq.empty()) {
        auto [di, ux, uy] = pq.top();
        pq.pop();

        if (visited[ux][uy] == true) continue;
        visited[ux][uy] = true;

        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 1 or vx > R or vy < 1 or vy > C) continue;
            if (visited[vx][vy] == false and dist[ux][uy] + a[vx][vy] < dist[vx][vy]) {
                dist[vx][vy] = dist[ux][uy] + a[vx][vy];
                pq.emplace(-dist[vx][vy], vx, vy);
            }
        }
    }
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) cout << dist[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}