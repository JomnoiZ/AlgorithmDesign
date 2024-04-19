#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector <vector <int>> a(4, vector <int> (4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 0) continue;
            cnt += abs(i - (a[i][j] - 1) / 4) + abs(j - (a[i][j] - 1) % 4);
        }
    }
    if (cnt == 0) {
        cout << 0;
        return 0;
    }

    map <vector <vector <int>>, int> dp;
    priority_queue <pair <int, vector <vector <int>>>> pq;
    pq.emplace(-cnt, a);
    dp[a] = 0;
    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();

        int tmp = dp[u];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (u[i][j] != 0) continue;

                for (int k = 0; k < 4; k++) {
                    int ni = i + d[k][0], nj = j + d[k][1];
                    if (ni < 0 or ni >= 4 or nj < 0 or nj >= 4) continue;

                    swap(u[i][j], u[ni][nj]);
                    if (!dp.count(u)) {
                        dp[u] = tmp + 1;
                        int ncnt = 0;
                        for (int x = 0; x < 4; x++) {
                            for (int y = 0; y < 4; y++) {
                                if (u[x][y] == 0) continue;
                                ncnt += abs(x - (u[x][y] - 1) / 4) + abs(y - (u[x][y] - 1) % 4);
                            }
                        }
                        if (ncnt == 0) {
                            cout << dp[u];
                            return 0;
                        }
                        pq.emplace(-dp[u] - ncnt, u);
                    }
                    swap(u[i][j], u[ni][nj]);
                }
            }
        }
    }
    return 0;
}