#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5005;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int a[MAX_N][MAX_N], dist[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) cin >> a[i][j];

    queue <pair <int, int>> q;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (a[i][j] == 1) {
                q.emplace(i, j);
                dist[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        if (a[ux][uy] == 2) {
            cout << dist[ux][uy];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 1 or vx > R or vy < 1 or vy > C or a[vx][vy] == 3) continue;
            if (dist[vx][vy] == 0) {
                dist[vx][vy] = dist[ux][uy] + 1;
                q.emplace(vx, vy);
            }
        }
    }
    return 0;
}