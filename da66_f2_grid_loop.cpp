#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;

int R, C;
int a[MAX_N][MAX_N];
vector <int> graph[MAX_N * MAX_N];
bool visited[MAX_N * MAX_N];

int node(int i, int j) {
    if (i < 0 or i >= R or j < 0 or j >= C) return -1;
    return i * C + j;
}

bool is_horizontal_left(int i, int j) {
    return a[i][j] == 1 or a[i][j] == 3 or a[i][j] == 4;
}

bool is_horizontal_right(int i, int j) {
    return a[i][j] == 1 or a[i][j] == 5 or a[i][j] == 6;
}

bool is_vertical_top(int i, int j) {
    return a[i][j] == 2 or a[i][j] == 4 or a[i][j] == 5;
}

bool is_vertical_bottom(int i, int j) {
    return a[i][j] == 2 or a[i][j] == 3 or a[i][j] == 6;
}

void connect(int x1, int y1, int x2, int y2) {
    int u = node(x1, y1), v = node(x2, y2);
    graph[u].push_back(v);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> R >> C;

    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> a[i][j];
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        if (j - 1 >= 0 and is_horizontal_left(i, j - 1) == true and is_horizontal_right(i, j) == true) connect(i, j, i, j - 1);
        if (j + 1 < C and is_horizontal_left(i, j) == true and is_horizontal_right(i, j + 1) == true) connect(i, j, i, j + 1);
        if (i - 1 >= 0 and is_vertical_top(i - 1, j) == true and is_vertical_bottom(i, j) == true) connect(i, j, i - 1, j);
        if (i + 1 < R and is_vertical_top(i, j) == true and is_vertical_bottom(i + 1, j) == true) connect(i, j, i + 1, j);
    }

    int cnt_cycle = 0, max_len = 0;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (visited[node(i, j)] == false) {
        int s = node(i, j), cnt = 0;
        queue <pair <int, int>> q;
        q.emplace(s, -1);
        visited[s] = true;
        bool is_cycle = false;
        while (!q.empty()) {
            auto [u, p] = q.front();
            q.pop();

            cnt++;
            for (auto v : graph[u]) if (v != p) {
                if (visited[v] == false) {
                    visited[v] = true;
                    q.emplace(v, u);
                }
                else is_cycle = true;
            }
        }
        if (is_cycle == true) {
            cnt_cycle++;
            max_len = max(max_len, cnt);
        }
    }
    cout << cnt_cycle << ' ' << max_len;
    return 0;
}