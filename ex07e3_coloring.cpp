#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 55;
vector <int> graph[MAX_N];
int color[MAX_N];

void dfs(int u) {
    set <int> s;
    color[u] = 1;
    for (auto v : graph[u]) {
        if (color[v] != 0) s.insert(color[v]);
    }

    while (s.count(color[u])) color[u]++;

    for (auto v : graph[u]) {
        if (color[v] == 0) dfs(v);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) dfs(i);
    }

    int ma = 0;
    for (int i = 0; i < n; i++) ma = max(ma, color[i]);
    cout << ma;
    return 0;
}