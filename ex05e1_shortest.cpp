#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

char table[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++) cin >> table[i];

    memset(dist, -1, sizeof(dist));

    queue <pair <int, int>> q;
    if (table[0][0] == '.') {
        q.emplace(0, 0);
        dist[0][0] = 0;
    }
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 0 or vy < 0 or vx >= R or vy >= C) continue;

            if (dist[vx][vy] == -1 and table[vx][vy] != '#') {
                dist[vx][vy] = dist[ux][uy] + 1;
                q.emplace(vx, vy);
            }
        }
    }
    cout << dist[R - 1][C - 1];
    return 0;
}