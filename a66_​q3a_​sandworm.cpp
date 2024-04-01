#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 705;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int table[2][MAX_N][MAX_N];
int cnt[2][MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
bool warp[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C, K;
    cin >> R >> C >> K;

    for (int t = 0; t < 2 ; t++) {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                cin >> table[t][i][j];
            }
        }
    }
    while (K--) {
        int a, b;
        cin >> a >> b;

        warp[a][b] = true;
    }

    for (int t = 0; t < 2; t++) {
        for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) visited[i][j] = 0;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (visited[i][j] != 0 or table[t][i][j] == 1) continue;

                queue <pair <int, int>> q;
                q.emplace(i, j);
                visited[i][j] = 1;
                int sum = 0;
                while (!q.empty()) {
                    auto [ux, uy] = q.front();
                    q.pop();

                    sum++;
                    for (int z = 0; z < 4; z++) {
                        int vx = ux + d[z][0], vy = uy + d[z][1];
                        if (vx < 1 or vx > R or vy < 1 or vy > C) continue;

                        if (table[t][vx][vy] == 0 and visited[vx][vy] == 0) {
                            visited[vx][vy] = 1;
                            q.emplace(vx, vy);
                        }
                    }
                }

                q.emplace(i, j);
                visited[i][j] = 2;
                while (!q.empty()) {
                    auto [ux, uy] = q.front();
                    q.pop();

                    cnt[t][ux][uy] = sum;
                    for (int z = 0; z < 4; z++) {
                        int vx = ux + d[z][0], vy = uy + d[z][1];
                        if (vx < 1 or vx > R or vy < 1 or vy > C) continue;

                        if (table[t][vx][vy] == 0 and visited[vx][vy] == 1) {
                            visited[vx][vy] = 2;
                            q.emplace(vx, vy);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) visited[i][j] = 0;

    int ans = cnt[0][1][1];
    queue <pair <int, int>> q;
    q.emplace(1, 1);
    visited[1][1] = 1;
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        if (warp[ux][uy] == true) ans = max(ans, cnt[0][1][1] + cnt[1][ux][uy]);
        for (int z = 0; z < 4; z++) {
            int vx = ux + d[z][0], vy = uy + d[z][1];
            if (vx < 1 or vx > R or vy < 1 or vy > C) continue;

            if (table[0][vx][vy] == 0 and visited[vx][vy] == 0) {
                visited[vx][vy] = 1;
                q.emplace(vx, vy);
            }
        }
    }
    cout << ans;
    return 0;
}