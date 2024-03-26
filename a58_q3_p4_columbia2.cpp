#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 7;
const int d[5][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {0, 0}};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    vector <vector <int>> a(R + 1, vector <int> (C + 1));
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> a[i][j];
        }
    }

    vector <vector <vector <int>>> dist(R + 5, vector <vector <int>> (C + 5, vector <int> (3, INF)));
    vector <vector <vector <bool>>> visited(R + 5, vector <vector <bool>> (C + 5, vector <bool> (3)));

    priority_queue <tuple <int, int, int, int>> pq;
    pq.emplace(0, 1, 1, 0);
    dist[1][1][0] = 0;
    while (!pq.empty()) {
        auto [di, ux, uy, k] = pq.top();
        pq.pop();

        if (visited[ux][uy][k] == true) continue;
        visited[ux][uy][k] = true;

        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 1 or vx > R or vy < 1 or vy > C) continue;
            if (visited[vx][vy][k] == false and dist[ux][uy][k] + a[vx][vy] < dist[vx][vy][k]) {
                dist[vx][vy][k] = dist[ux][uy][k] + a[vx][vy];
                pq.emplace(-dist[vx][vy][k], vx, vy, k);
            }
            if (k + 1 < 3) {
                for (int j = 0; j < 5; j++) {
                    int vx2 = vx + d[j][0], vy2 = vy + d[j][1];
                    if (vx2 < 1 or vx2 > R or vy2 < 1 or vy2 > C) continue;
                    if (visited[vx2][vy2][k + 1] == false and dist[ux][uy][k] < dist[vx2][vy2][k + 1]) {
                        dist[vx2][vy2][k + 1] = dist[ux][uy][k];
                        pq.emplace(-dist[vx2][vy2][k + 1], vx2, vy2, k + 1);
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) cout << min({dist[i][j][0], dist[i][j][1], dist[i][j][2]}) << ' ';
        cout << '\n';
    }
    return 0;
}