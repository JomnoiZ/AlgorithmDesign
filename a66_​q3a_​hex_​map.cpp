#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 305;
const int INF = 1e9 + 7;
const int d[2][6][2] = {{{-1, 0}, {1, 0}, {0, -1}, {1, -1}, {0, 1}, {1, 1}}, {{-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {-1, 1}, {0, 1}}};

int table[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    swap(a1, b1);
    swap(a2, b2);

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> table[i][j]; 
            dist[i][j] = INF;
        }
    }

    priority_queue <tuple <int, int, int>> pq;
    pq.emplace(-table[a1][b1], a1, b1);
    dist[a1][b1] = table[a1][b1];
    while (!pq.empty()) {
        auto [di, ux, uy] = pq.top();
        pq.pop();

        for (int i = 0; i < 6; i++) {
            int vx = ux + d[uy % 2][i][0], vy = uy + d[uy % 2][i][1];
            if (vx < 1 or vx > R or vy < 1 or vy > C) continue;

            if (dist[ux][uy] + table[vx][vy] < dist[vx][vy]) {
                dist[vx][vy] = dist[ux][uy] + table[vx][vy];
                pq.emplace(-dist[vx][vy], vx, vy);
            }
        }
    }
    cout << dist[a2][b2];
    return 0;
}