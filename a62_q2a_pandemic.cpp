#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 505;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int a[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int r, c, t;
    cin >> r >> c >> t;

    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> a[i][j];

    queue <pair <int, int>> q;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            dist[i][j] = -1;
            if (a[i][j] == 1) {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 1 or vx > r or vy < 1 or vy > c) continue;

            if (a[vx][vy] == 0 and dist[vx][vy] == -1 and dist[ux][uy] + 1 <= t) {
                a[vx][vy] = 1;
                dist[vx][vy] = dist[ux][uy] + 1;
                q.emplace(vx, vy);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) if (a[i][j] == 1) ans++;
    cout << ans << '\n';
    return 0;
}