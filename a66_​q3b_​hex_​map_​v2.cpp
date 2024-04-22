#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 305;
const int d[2][6][2] = {{{0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {1, -1}, {1, 0}}, 
                         {{0, -1}, {0, 1}, {-1, 0}, {-1, 1}, {1, 0}, {1, 1}}};
const int INF = 1e9 + 7;

int a[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) cin >> a[i][j];
    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) dist[i][j] = INF;

    priority_queue <tuple <int, int, int>> pq;
    pq.emplace(-a[a1][b1], a1, b1);
    dist[a1][b1] = a[a1][b1];
    while (!pq.empty()) {
        auto [di, x, y] = pq.top();
        pq.pop();

        if (visited[x][y] == true) continue;
        visited[x][y] = true;

        for (int i = 0; i < 6; i++) {
            int nx = x + d[x % 2][i][0], ny = y + d[x % 2][i][1];
            if (nx < 1 or nx > R or ny < 1 or ny > C) continue;
            if (visited[nx][ny] == false and dist[x][y] + a[nx][ny] < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + a[nx][ny];
                pq.emplace(-dist[nx][ny], nx, ny);
            }
        }
    }
    cout << dist[a2][b2];
    return 0;
}