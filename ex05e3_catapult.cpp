#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

vector <int> graph[MAX_N];
bool reach[MAX_N][MAX_N];
bool visited[MAX_N];
int parent[MAX_N], sz[MAX_N];

int find_parent(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_parent(parent[u]);
}

void dfs(int u, int x) {
    if (visited[u] == true) return;
    visited[u] = true;
    reach[x][u] = true;
    for (auto &v : graph[u]) dfs(v, x);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int m;
        cin >> m;

        while (m--) {
            int x;
            cin >> x;

            graph[i].push_back(x);
        }
    }

    for (int i = 0; i < N; i++) {
        fill(visited, visited + N, false);
        dfs(i, i);
    }

    iota(parent, parent + N, 0);
    fill(sz, sz + N, 1);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (reach[i][j] == true and reach[j][i] == true) {
                int u = find_parent(i), v = find_parent(j);
                if (u != v) {
                    parent[v] = u;
                    sz[u] += sz[v];
                }
            }
        }
    }

    vector <int> ans;
    for (int i = 0; i < N; i++) {
        if (parent[i] == i) ans.push_back(sz[i]);
    }

    sort(ans.begin(), ans.end());

    for (auto &v : ans) cout << v << ' ';
    return 0;
}